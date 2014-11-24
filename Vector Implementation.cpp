#include<iostream>
using namespace std;

/* const at the end of a function: 
		tells that the method is a "const member function"
		which does not modify any member variables of the class
*/

// use shallow copy in copy constructor & assignment operator would fail the assertions.

template <typename Object>
class Vector{

private:
	int size;
	int capacity;
	Object *objects;

public:
	/********** ctr & dtr **********/
	// constructor
	explicit Vector(): size(0), capacity(4){ // avoid implicit type conversion
		objects = new Object[capacity];
	}
	// copy constructor
	Vector(const Vector &rhs): objects(NULL){
		operator=(rhs);
	}
	// destructor
	~Vector(){
		delete []objects;
	}
	// assignment operator
	const Vector& operator= (const Vector &rhs){
		if(this != &rhs){
			delete []objects;
			this->size = rhs.size;
			this->capacity = rhs.capacity;
			this->objects = new Object[capacity];
			for(int i = 0; i < size; i++)
				this->objects[i] = rhs.objects[i];
		}
		return *this;
	}

	/********** pop_back() & push_back() **********/
	void pop_back(){
		size--;
	}
	void push_back(const Object &x){
		if(size == capacity)
			reserve(2 * capacity + 1); 
		objects[size++] = x;
	}
	void reserve(int newCapacity){
		Object *oldObjects = objects;
		objects = new Object[newCapacity];
		for(int i = 0; i < size; i++){
			objects[i] = oldObjects[i];
		}	
		capacity = newCapacity;
		delete []oldObjects;
	}

	/********** address operator **********/
	Object& operator[] (int index){
		return objects[index];
	}

	Object& back(){
		return objects[size-1]; // bug happened
	}
	
	/********** iterator **********/
	typedef Object* iterator;
	iterator begin(){
		return &objects[0];
	}
	iterator end(){
		return &objects[size];
	}

	/********** others **********/
	int getSize(){
		return size;
	}
	bool empty(){
		return size == 0;
	}

};

int main(){
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	cout << v.getSize() << endl;
	v.pop_back();
	cout << v.getSize() << endl;
	v.push_back(8);
	cout << v.getSize() << endl;
	cout << v.back() << endl; 
	cout << "***" << endl;
	cout << v[2] << endl; 

	Vector<int> vv(v);
	cout << vv[2] << endl; 

	cout << v.getSize() << endl;

	for(Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
	return 0;
}