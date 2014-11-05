/*
	Facebook / Google interview question.

	Given API: 
	int Read4096(char* buf); 
	It reads data from a file and records the position so that the next time when it is called it read the next 4k chars 
	(or the rest of the file, whichever is smaller) from the file. 
	The return is the number of chars read. 

	Todo: Use above API to implement API 
	"int Read(char* buf, int n)" which reads any number of chars from the file.
*/
#include<cstring>

// some internal staff will record its position
int Read4K(char *buf){
	return 4096;
}

class Reader{
public:
	int Read(char *buf, int n){
		char buffer[4096];
		int count = 0;
		int remain = n;
		int bytesRead = 4096;

		while(remain > 0 && bytesRead == 4096){

			// bytesRead could be less than 4096
			int bytesRead = Read4K(buffer);

			// finished reading
			if(bytesRead >= remain){
				// memcpy(dest, src, num);
				memcpy(buf+count, buffer, remain);
				return n;
			}
			else{
				memcpy(buf+count, buffer, bytesRead);
				count += bytesRead;
				remain -= bytesRead;
			}
		}
		return count;
	}
};