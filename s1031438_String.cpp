
#include<string>
#include <iostream>
#include "s103148_String.h"
using namespace std;
ostream &operator<<(ostream& output, const String& str){

	for (size_t i = 0; i < str.size; i++){
		output << str.sPtr[i];
	}
	return output;
}


String::String(){
	size = 0;
	capacity = 10;
	sPtr = new char[size];
	sPtr = 0;
}
String::String(const String &str){
	size = str.size;
	sPtr = new char[size];
	capacity = str.capacity;
	for (size_t i = 0; i < capacity; i++){
		sPtr[i] = str.sPtr[i];
	}
}
String::String(const String& str, size_t pos, size_t len){
	size = len;
	sPtr = new char[size];
	capacity = size;
	for (size_t i = pos,j=0; i < pos + len; i++,j++){
		sPtr[j] = str.sPtr[i];
	}
}
String::String(const char *s){
	size = strlen(s);
	string a;
	sPtr = new char[size];
	capacity = size;
	for (size_t i = 0; i < size; i++){
		sPtr[i] = s[i];
	}
}
String::~String(){
	delete[] sPtr;
}

char* String::begin(){
	char begin1[1];
	begin1[0] = sPtr[0];
	return begin1;
}
char* String::end(){
	char end1[1];
	end1[0] = sPtr[size - 1];
	return end1;
}
size_t String::getSize() const{
	return size;
}
void String::resize(size_t n){
	if (n > size){
		for (size_t i = size; i < n; i++){
			sPtr[i] = '\0';
		}
		size = n;
		sPtr = new char[size];
	}
	else if (size <= n){
		size = n;
		sPtr = new char[size];
	}
}
void String::resize(size_t n, char c){
	if (n > size){
		for (size_t i = size; i < n; i++){
			sPtr[i] = c;
		}
		size = n;
		sPtr = new char[size];
	}
	else if (size <= n){
		size = n;
		sPtr = new char[size];
	}
}


size_t String::getCapacity() const{
		return size;
}
void String::reserve(size_t n){
	capacity = n;
}
void String::shrink_to_fit(){
	if (size > capacity)
		capacity = size;
	else if (capacity > size)
		capacity = size;
}

void String::clear(){
	size = 0;
	sPtr = new char[size];
	sPtr[0] = NULL;
}

bool String::empty() const{
	if (size == 0)
		return true;
	else
		return false;
}

char& String::front(){
	return sPtr[0];
}

char& String::back(){
	return sPtr[size - 1];
}
void String::push_back(char c){  //little bug

	for (size_t i = size; i < size+1; i++){
		sPtr[i] = c;
	}
}
void String::pop_back(){
	size--;
	sPtr = new char[size];
}

String& String::append(const String &str){
	size_t _1size = size;
	size_t _size = strlen(str.sPtr);
	size += _size;
	sPtr = new char[size];
	for (size_t i = _1size, j=0; i < _1size + _size; i++,j++){
		sPtr[i] = str.sPtr[j];
	}
	return *this;
}
String& String::substr(size_t pos, size_t len) const{
	String sub;
	sub.size = len;
	sub.sPtr = new char[sub.size];
	for (size_t i = pos, j = 0; i < pos + len; i++, j++){
		sub.sPtr[j] = sPtr[i];
	}
	cout << sub.size << endl;
	return sub;
}
String& String::insert(size_t pos, const String &str){
	size_t _size = strlen(str.sPtr);
	String temp;
	temp.sPtr = new char[size];
	for (size_t i = pos,j=0; i < size+_size; i++,j++)
		temp.sPtr[j] = sPtr[i];
	for (size_t i = pos, j = 0; i < pos + _size; i++, j++)
		sPtr[i] = str.sPtr[j];
	for (size_t i = pos+size, j = 0; i<size+_size; i++, j++)
		sPtr[i] = temp.sPtr[j];
	size = size + _size;
	sPtr = new char[size];
	return *this;
}
String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen){
	size_t _size = sublen;
	String temp;
	temp.sPtr = new char[size];
	for (size_t i = pos, j = 0; i < size; i++, j++)
		temp.sPtr[j] = sPtr[i];
	for (size_t i = pos, j = subpos; i < pos + _size; i++, j++)
		sPtr[i] = str.sPtr[j];
	for (size_t i = pos + size, j = 0; i<size + _size; i++, j++)
		sPtr[i] = temp.sPtr[j];
	size = size + _size;
	sPtr = new char[size];
	return *this;
}
String& String::erase(size_t subpos, size_t sublen){
	String temp;
	temp.sPtr = new char[size];
	for (size_t i = subpos+sublen, j = 0; i < size; i++, j++)
		temp.sPtr[j] = sPtr[i];
	size = size - sublen;
	sPtr = new char[size];
	for (size_t i = subpos, j = 0; i < size; i++, j++)
		sPtr[i] = temp.sPtr[j];
	return *this;
}

size_t String::find(const String &str, size_t pos) const{
	size_t yes = 1;
	size_t ans = 0;
	for (size_t i = 0; i < size; i++){
		if (sPtr[i] == str.sPtr[0]){
			for (size_t j = 0, k = i; j < strlen(str.sPtr); j++){
				if (sPtr[i] != str.sPtr[j]){
					yes = 0;
					break;
				}
			}
			if (yes == 1)
				ans = i;
		}
	}
	return ans;
}

size_t String::find_first_of(const String str, size_t pos) const{
	size_t yes=1;
	for (size_t i = 0; i < size; i++){
		if (sPtr[i] == str.sPtr[0]){
			for (size_t j = 0, k = i; j < strlen(str.sPtr); j++){
				if (sPtr[i] != str.sPtr[j]){
					yes = 0;
					break;
				}
			}
			if (yes == 1)
				return i;
		}
	}

}
char& String::operator[] (size_t pos){
	return sPtr[pos];
}
const char& String::operator[] (size_t pos) const{
	return sPtr[pos];
}
String String::operator+ (const String& rhs){
	String temp;
	temp.size = size + rhs.size;
	temp.sPtr = new char[temp.size];
	for (size_t i = 0, j = 0; i < size; i++, j++)
		temp.sPtr[i] = sPtr[j];

	for (size_t i = size,j=0; i <= temp.size; i++,j++){
		temp.sPtr[i] = rhs.sPtr[j];
	}
	return temp;
}
String String::operator+ (const char* rhs){
	String temp;
	size_t _size = strlen(rhs);
	temp = *this;
	for (size_t i = temp.size, j = 0; i < temp.size + _size; i++, j++){
		temp.sPtr[i] = rhs[j];
	}
	temp.size += _size;
	temp.sPtr = new char[temp.size];
	temp.shrink_to_fit();
	if (capacity < 10)
		capacity = 10;
	return temp;
}
String& String::operator= (const String& str){
	size = str.size;
	sPtr = new char[size];
	capacity = str.capacity;
	for (size_t i = 0; i < size; i++)
		sPtr[i] = str.sPtr[i];
	return *this;
}
String& String::operator= (const char* s){
	size = strlen(s);
	sPtr = new char[size];
	capacity = 10;
	for (size_t i = 0; i < size; i++)
		sPtr[i] = s[i];
	return *this;
}
bool String::operator==(const String &str){
	if (size != str.size)
		return false;
	for (size_t i = 0; i < size; i++){
		if (sPtr[i] != str.sPtr[i])
			return false;
	}
	return true;
}
bool String::operator!=(const String &str){
	if (size != str.size)
		return true;
	for (size_t i = 0; i < size; i++){
		if (sPtr[i] != str.sPtr[i])
			return true;
	}
	return false;
}