/*
	Facebook Interview Question
	1.
		If you have only one room, what is the maximum number of meetings you can scheduled into that room.

	2.
		You are given a set of meetings with start time and end time, 
		what is the minimum number of meeting rooms you need to have to hold all the meetings. 
 */

// greedy 
//	1. a room with max activities: sort by finish time
//	2. min number of rooms: sort by start time, and use min_heap to save ending time

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct meeting{
	int startTime;
	int endTime;
	meeting(int s, int e): startTime(s), endTime(e){}
};

struct cmp_arr{
	bool operator() (const meeting *a, const meeting *b){
		return a->startTime < b->startTime;
	}
};

struct cmp_pq{
	bool operator() (const int a, const int b){
		return b < a;
	}
};

class roomScheduling{
public:
	int findMinNumberOfRooms(vector<meeting*> &arr){
		sort(arr.begin(), arr.end(), cmp_arr()); // must have "()"
		priority_queue<int, vector<int>, cmp_pq> pq; // save all end time, can't have "()"
		for(meeting *m : arr){
			if(pq.empty() || m->startTime < pq.top()) // schedule a new room
				pq.push(m->endTime);
			else{
				pq.pop();
				pq.push(m->endTime);
			}
		}

		return pq.size();
	}
};

int main(){
	roomScheduling *obj = new roomScheduling();
	meeting *m1 = new meeting(1, 4);
	meeting *m2 = new meeting(2, 4);
	meeting *m3 = new meeting(3, 10);
	meeting *m4 = new meeting(5, 6);
	vector<meeting*> mm;
	mm.push_back(m1);
	mm.push_back(m2);
	mm.push_back(m3);
	mm.push_back(m4);
	cout << obj->findMinNumberOfRooms(mm) << endl;
	return 0;
}

