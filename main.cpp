#include <iostream>

bool srcAddr[32] = {1,1,0,0,0,0,0,0 , 1,0,1,0,1,0,0,0 , 0,0,0,0,0,0,0,1 , 0,0,0,0,0,0,0,1};
bool destAddr[32] = {1,1,1,0,0,0,0,0 , 1,0,1,0,1,0,0,0 , 0,0,0,0,0,0,0,1 , 0,0,0,0,0,0,1,0};
bool data[64] = {0,0,0,1,0,1,1,1 , 0,1,1,1,1,1,0,1 , 
				 1,0,1,0,1,1,1,0 , 1,1,0,1,0,1,1,1 , 
				 1,0,1,1,0,1,1,0 , 0,1,1,0,0,1,1,1 ,
				 1,1,1,0,0,1,0,1 , 1,0,0,1,0,0,0,1};

int main() {

	bool output[512] = {};
	
	for(int i=0; i<32; i++) {
		output[i] = srcAddr[i];
	}
	
	for(int i=32; i<64; i++) {
		output[i] = destAddr[i-32];
	}
	
	for(int i=64; i<128; i++) {
		output[i] = data[i-64];	
	}
	
	for(int i=0; i<256; i++) {
		if(i == 32 || i == 64 || i == 128) {
			std::cout << " ";	
		}
		std::cout << output[i];
	}
	std::cout << std::endl;
	
	return 0;
}