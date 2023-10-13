#include "StringReverse.h"

std::string StringReverse::reverseString(const std::string& str){
	// base case, returns empty string
        if(str.length() == 0){
            return "";
        } else {
            // Recrusive case: return the last character of the string, concatenated with the reversed substring of the rest of the string
            return str.at(str.length() - 1) + reverseString(str.substr(0,str.length() - 1));
        }
}