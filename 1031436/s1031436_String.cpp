#include <iostream>
#include <string>
#include "PG2String.h"

using namespace std;

ostream &operator<<(ostream& output, const String& str){
	output << str;
	return output;
}

String::String(){
	sPtr = new char[size];
}

String::String(const String &str){
	size = str.size;
	sPtr = new char[size];
	for (int i = 0; i<size; i++)
		sPtr[i] = str.sPtr[i];
}

String::String(const String& str, size_t pos, size_t len = npos){
	for (int i = pos; i<len; i++)
		sPtr[i] = str.sPtr[i];
}

String::String(const char *s){
	s = sPtr;
}

String::~String(){

	delete[]sPtr;
}

char*String::begin(){
	string a;
	for (int i = 0; i < size; i++)
		a[i] = sPtr[i];
	char*c = a.capacity[0];
	return c;
}

char* String::end(){
	string a;
	for (int i = 0; i < size; i++)
		a[i] = sPtr[i];
	char *c = a.capacity[size - 1];
	return c;
}

size_t getSize(){
	string str;
	return str.size;
}

void String::resize(size_t n){
	string a;
	a.resize(capacity);
	for (int i = 0; i <capacity; i++)
		a[i] = sPtr[i];

	if (n < capacity){
		a.resize(n);
		size = size + a.size() - 1;
		for (int i = capacity, j = 0; i < n, j < n; i++, j++)
			sPtr[i] = a[j];
	}
	if (n > capacity){
		size = n;
		for (int i = capacity - 1; i < n; i++)
			sPtr[i] = '\0';
	}
}

void String::resize(size_t n, char c){
	string a;
	a.resize(capacity);
	for (int i = 0; i <capacity; i++)
		a[i] = sPtr[i];

	if (n < capacity){
		a.resize(n);
		size = size + a.size() - 1;
		for (int i = capacity, j = 0; i < n, j < n; i++, j++)
			sPtr[i] = a[j];
	}
	if (n > capacity){
		size = n;
		for (int i = capacity - 1; i < n; i++)
			sPtr[i] = c;
	}
}

size_t getCapacity(){

}
// NOTE: default capacity = 10
// Returns the size of the storage space currently allocated for the string,
// expressed in terms of elements.
// *This capacity is not necessarily equal to the string length. It can be equal or greater, 
// with the extra space allowing the object to optimize its operations when new characters are added to the string.

void String::reserve(size_t n = 0){
	if (n > capacity)
		capacity = n;
}

void String::shrink_to_fit(){
	while (sPtr[capacity - 1] == '\0')
		capacity--;
}

void String::clear(){
	while (sPtr[capacity - 1] != 0 && capacity != 0){
		sPtr[capacity - 1] = 0;
		capacity--;
	}
}

bool empty(){
	string str;

	if (str.capacity == 0)
		return true;
	else
		return false;

}

char& String::front(){
	if (empty)
		return;
	char ref = sPtr[0];
	return ref;
}

char& String::back(){
	if (empty)
		return;
	char ref = sPtr[size - 1];
	return ref;
}
/*
void String::push_back(char c){}
// Appends character c to the end of the string, increasing its length by one.
// *Return the reference of itself

void String::pop_back(){}
// Erases the last character of the string, effectively reducing its size by one.
// (the string capacity is not affected)
// *Return the reference of itself

String& String::append(const String &str){
}
// Appends a str on the tail of current String.
// *Return the reference of itself

String& substr(size_t pos = 0, size_t len = npos){}
// The substring is the portion of the object that starts at character position pos and spans len characters
// (or until the end of the string, whichever comes first).
// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.

String& String::insert(size_t pos, const String &str){

}
// Inserts a copy of a str at "pos".
// example: str = "to be question", str2 = "the "
// str.insert(6,str2); // = to be (the )question
// *Return the reference of itself

String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen){}
// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
// begins at the character position subpos and spans sublen characters (or until the end of str).
// example: str = "to be the question", str3 = "or not to be"
// str.insert(6,str3,3,4); // to be (not )the question
// *Return the reference of itself

String& String::erase(size_t subpos, size_t sublen){}
// Erases the portion of the string value that begins at the character position pos and spans len characters
// (or until the end of the string, if either the content is too short or if len is string::npos.)
// *Return the reference of itself

size_t find(const String &str, size_t pos = 0){}
// Searches the portion of the string value that begins at the character position pos until the end of the string
// for the first occurrence of the string str.
// Return Value: The position of the first character of the first match. If no matches were found, the function returns String::npos.

size_t find_first_of(const String str, size_t pos = 0){}
// Searches the portion of the string value that begins at the character position "pos" until the end of the string
// for the first character that matches *any* of the characters of the string str.
// Return Value: The position of the first character that matches. If no matches are found, the function returns String::npos.

char& String::operator[] (size_t pos){} //Get character of string
char& String::operator[] (size_t pos){}
// Value with the position of a character within the string.
// Note: The first character in a string is denoted by a value of 0 (not 1).
// size_t is an unsigned integral type (the same as member type string::size_type).

String String::operator+ (const String& rhs){}
String String::operator+ (const char*   rhs){}
String String::operator+ (const String& rhs){}
// Returns a newly constructed string object with its value
// being the *concatenation* of the characters in lhs followed by those of rhs.
// Note: If of type char*, it shall point to a null-terminated character sequence.
*/
String& String::operator= (const String& str){
	for (int i = 0; i < capacity; i++)
		sPtr[i] = str.sPtr[i];
	return *this;
}
String& String::operator= (const char* s){
	for (int i = 0; i < capacity; i++)
		sPtr[i] = s[i];
	return *this;
}
//Assigns a new value to the string, replacing its current contents.

bool String::operator==(const String &str){
	if (size < str.size)
		return false;
	if (size>str.size)
		return false;
	if (size == str.size){
		for (int i = 0; i < size; i++){
			if (sPtr[i] != str.sPtr[i])
				return false;
		}
		return true;
	}
}
bool String::operator!=(const String &str){
	if (*this == str)
		return false;
	else
		return true;
}