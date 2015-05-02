#include <iostream>
#include <cstring>
#include <vector>
#include "s1031542_String.h"

using namespace std;

ostream &operator<<(ostream& output, const String& str){
	for (int i = 0; i < str.size; i++)
	{
		output << str.sPtr[i];
	}
	return output;
}


String::String(){
	sPtr=0;
	capacity = 10;
	size = 0;
}

String::String(const String &str){
	String cpy;
	for (int i = 0; i < size; i++)
		cpy.sPtr[i] = str.sPtr[i];
}

String::String(const String& str, size_t pos, size_t len = npos){
	String cpy;
	for (int i = 0; i < size; i++){
		cpy.sPtr[i] = str.sPtr[pos];
		pos++;
	}

}

String::String(const char *s){
	String cpy;
	
}