#include"s1033328_String.h"
#include<iostream>
using namespace std;
ostream &operator<<(ostream& output, const String& str){
	for (int i = str.size-1; i >= 0; i--)
		output << str.sPtr[i];
	return output;
}
String::String(){
	capacity = 10;
	size = 0;
}
String::String(const String &str){
	capacity = str.capacity;
	size = str.size;
	int s = size;
	for (int i = 0; i < s; i++)
		sPtr[i] = str.sPtr[i];
}
/*String::String(const String& str, size_t pos, size_t len = npos){
	int p = pos,l=len;
	for (int i = p; i < p + l; i++)
		sPtr[i] = str.sPtr[i];
}*/

String::String(const char *s){
	for (int i = 0; ; i++){
		if (s[i] == '\0')
			break;
		a[i] = s[i];
		size = i;
		if (capacity < size)
			capacity = size;
	}
}
String::~String(){
	capacity = 10;
	size = 0;
	sPtr = 0;
}
char* String::begin(){
	return &sPtr[0];
}
char* String::end(){
	return &sPtr[size - 1];
}
size_t String::getSize()const{
	return size;
}
void String::resize(size_t n){
	size = n;
}
void String::resize(size_t n, char c){
	size = n;
	*sPtr = c;
}
size_t String::getCapacity()const{
	return capacity;
}
/*void String::reserve(size_t n = 0){
	if (n > capacity)
		capacity = n;
}*/
void String::shrink_to_fit(){
	capacity = size;
}
void String::clear(){
	*sPtr = 0;
	size = 0;
	capacity = 10;
}
bool String::empty()const{
	if (size == 0)
		return true;
	else
		return false;
}
char& String::front(){
	return *&sPtr[0];
}
char& String::back(){
	return *&sPtr[size - 1];
}
//String& String::append(const String &str){}
