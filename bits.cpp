// File bits.cpp 
// Contains bit manipulation hacks.

#include <iostream>
#include <bitset>

using std::bitset;
using std::cout;
using std::endl;


// check if bit in given position is set
// just need a mask with 1 at the position
// and with data to find if the bit is set
bool isBitSet(int data , int pos){
	if(pos>32 || pos <0){
		//can't access posiiton provided
		return data;
	}
	return (data & (1<<pos));
}


// update bit in position pos to zero
int clearBit(int data , int pos){
	if(pos>32 || pos <0){
		//can't access posiiton provided
		return data;
	}
	return (data & (~(1<<pos)));
}


//update bit in position pos to 1
int setBit(int data , int pos){
	if(pos>32 || pos <0){
		//can't access posiiton provided
		return data;
	}
	return (data | (1<<pos));
}


//clear bits from position m to n 
int clearBits(int data , int m, int n){
	if(m >32 || n <0){
		return data;
	}
	
	// make a mask with 1's in the bit range provided
	// We will need to and with os in those places to clear bits
	// Hence take the ~ of MASK generated with 1's
	int MASK = ((1<<(m-n)+1)-1) << (n);
	std::cout << "MASK  "<<std::bitset<16>(MASK);
	return data & (~MASK);
}

//set bits from position m to n 
int setBits(int data , int m, int n){
	if(m >32 || n <0 || m<n){
		return data;
	}
	
	// make a mask with 1's in the bit range provided
	// We will need to OR with 1s in those places to set bits
	int MASK = ((1<<(m-n)+1)-1) << (n);
	std::cout << "MASK  "<<std::bitset<16>(MASK);
	return data | MASK;
}

// to copy bit in given position range from one to another
int copyBits(int data1, int data2, int m, int n){
	
	if(m >32 || n <0 || m<n){
		return data1;
	}

	int MASK = ((1<<((m-n)+1))-1) << (n);
	// use OR operation to copy over the bits
	data1 |= data2 & MASK;

	return data1;

}

// for flipping we need to xor with mask of 1s.
// 1^(1) = 0 , 0^(1) = 1;
int flipBits(int data, int m , int n){
	if(m<n || m>32 || n <0){
		return data;
	}

	int MASK = ((1<<(m-n)+1)-1)<<n;
	return data^MASK;
}

int countBitFlipsToConvertAtoB(int a , int b){
	int temp = a^b;
	int counter =0;
	int n=0;
	while(n<32){
		if(temp & 1<<n){
			counter++;
		}
		n++;
	}

	return counter;
}


bool isPowerOfTwo(int data){
	return (!(data & (data-1)));
}



bool copyBitsInRange(int data1, int data2, int m , int n){

}

int main(){

	std::cout<<"\n"<<std::bitset<16>(clearBits(0xFFFF, 4,2))<<endl;
	std::cout<<"isPowerOfTwo(4) "<<isPowerOfTwo(4)<<endl;
	std::cout<<"isPowerOfTwo(5) "<<isPowerOfTwo(5)<<endl;

	int data1 = 0x0000;
	int data2 = 0xFFFF;
	std::cout<<"data1 "<<std::bitset<16>(data1)<<std::endl;
	std::cout<<"data2 "<<std::bitset<16>(data2)<<std::endl;
	std::cout<<"copyBits() "<<std::bitset<16>(copyBits(data1,data2,5,3))<<endl;

	std::cout<<"Flipbits() "<<std::bitset<16>(flipBits(data1,8,5))<<endl;
	std::cout<<"Flipbits() "<<std::bitset<16>(flipBits(data2,8,5))<<endl;

	std::cout<<"numbitstoflip "<<(countBitFlipsToConvertAtoB(data1,data2))<<endl;
}