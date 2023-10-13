#include"StringReverse.h"
#include<iostream>

int main(){
	std::string test = "Taylor Swift";
	
	StringReverse str_rev;
	
	std::cout << str_rev.reverseString(test) << std::endl;
	
	return 0;
}