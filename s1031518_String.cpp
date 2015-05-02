#include "s1031518_String.h"
#include <iostream>
using namespace std;

ostream& operator<<( ostream& output, const String& str ){

	for (int i = 0; i < str.size; i++)
		output << str.sPtr[i];
		
	return output;

}

String::String(){

	size = 0;
	capacity = 0;

}

String::String( const String &str ){

	size = str.size;
	capacity = str.capacity;
	
	sPtr = new char[capacity];
	for (int i = 0; i < capacity; i++)
		sPtr[i] = str.sPtr[i];

}

String::String(const String& str, size_t pos, size_t len ) : size(len){

	
	capacity = size;
	sPtr = new char[capacity];

	for (int i = pos; i < str.size ; i++)
		sPtr[i - pos] = str.sPtr[i];

}

String::String(const char* s) : size(strlen(s)) {

	capacity = size;

	sPtr = new char[capacity];

	for (int i = 0; i < capacity; i++)
		sPtr[i] = s[i];

}

String::~String(){

	delete[] sPtr;

}

String& String::operator=( const String& str ){

	resize(str.size);
	for (int i = 0; i < size; i++)
		sPtr[i] = str.sPtr[i];

	return *this;
}

String& String::operator=(const char* str){

	resize( strlen( str ) );
	for (int i = 0; i < size; i++)
		sPtr[i] = str[i];

	return *this;

}

bool String::operator==(const String& str){

	if (size != str.size)
		return false;

	for (int i = 0; i < size; i++){
		if (sPtr[i] != str.sPtr[i])
			return false;
	}

	return true;
}

bool String::operator!=(const String& str){

	return !(*this == str);

}

String String::operator+( const String& str ){

	String place;

	place.resize(size + str.size);
	for (int i = 0; i < size; i++)
		place.sPtr[i] = sPtr[i];
	for (int i = size; i < place.size; i++)
		place.sPtr[i] = str.sPtr[i-size];

	return place;

}

String String::operator+(const char* str){

	String place;

	place.resize( size + strlen(str) );
	
	for (int i = 0; i < size; i++)
		place.sPtr[i] = sPtr[i];
	for (int i = size; i < place.size; i++)
		place.sPtr[i] = str[i-size];

	return place;
}

char& String::operator[]( size_t pos ){

	return sPtr[pos];

}

const char& String::operator[](size_t pos) const{

	return sPtr[pos];

}

char* String::begin(){

	return sPtr;

}

char* String::end(){

	return ( sPtr + size - 1 );

}

size_t String::getSize() const{

	return size;

}

void String::resize(size_t n ){

	reserve(n);
	size = n;

}

void String::resize( size_t n, char c ){

	reserve(n);
	for (int i = size; i < n; i++)
		sPtr[i] = c;
	size = n;

}

void String::reserve(size_t n){

	if (n > capacity){
		capacity = n;
		char* place = new char[capacity];
		for (int i = 0; i < size; i++)
			place[i] = sPtr[i];
		delete[] sPtr;
		sPtr = new char[n];
		for (int i = 0; i < size; i++)
			sPtr[i] = place[i];
		delete[] place;

	}
	capacity = n;
}

size_t String::getCapacity() const{

	return capacity;

}

void String::shrink_to_fit(){

	if (size < capacity){
		char* place = new char[size];
		for (int i = 0; i < size; i++)
			place[i] = sPtr[i];
		delete[] sPtr;
		sPtr = new char[size];
		for (int i = 0; i < size; i++)
			sPtr[i] = place[i];
		capacity = size;
	}
}

void String::clear(){

	size = 0;

}

bool String::empty() const{

	if (size != 0)
		return false;

	else
		return true;
	
}

void String::push_back( char c ){

	char* place = new char[size + 1];
	for (int i = 0; i < size; i++)
		place[i] = sPtr[i];
	place[size] = c;
	delete[] sPtr;
	sPtr = new char[size+1];
	for (int i = 0; i < size + 1; i++)
		sPtr[i] = place[i];
	size++;
}

void String::pop_back(){

	char* place = new char[size - 1];
	for (int i = 0; i < size - 1; i++)
		place[i] = sPtr[i];
	delete[]sPtr;
	sPtr = new char[size-1];
	for (int i = 0; i < size - 1; i++)
		sPtr[i] = place[i];
	delete[] place;
	size--;

}

String& String::append( const String& str ){

	size_t buffer = size;
	resize( size + str.size );
	for (int i = buffer; i < size; i++)
		sPtr[i] = str.sPtr[i-buffer];

	return *this;

}

String& String::erase(size_t subpos, size_t sublen){

	String place;
	place.resize(size - sublen);

	for (int i = 0; i < subpos; i++)
		place.sPtr[i] = sPtr[i];

	for (int i = subpos + sublen; i < size; i++)
		place.sPtr[i - sublen] = sPtr[i];

	delete[] sPtr;
	sPtr = new char[place.size];
	size = place.size;
	for (int i = 0; i < size; i++)
		sPtr[i] = place.sPtr[i];

	return *this;
}

String& String::insert( size_t pos, const String &str){

	String place;
	place.resize(size + str.size);

	for (int i = 0; i < pos; i++)
		place.sPtr[i] = sPtr[i];

	for (int i = pos; i < pos + str.size; i++)
		place.sPtr[i] = str.sPtr[i-pos];

	for (int i = pos + str.size; i < place.size; i++)
		place.sPtr[i] = sPtr[i - str.size];

	delete[] sPtr;
	sPtr = new char[place.size];
	size = place.size;
	for (int i = 0; i < size; i++)
		sPtr[i] = place.sPtr[i];

	return *this;
}

String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen){

	String place;
	place.resize(size + sublen);

	for (int i = 0; i < pos; i++)
		place.sPtr[i] = sPtr[i];

	char* subplace = new char[sublen];
	for (int i = subpos; i < subpos + sublen; i++)
		subplace[i - subpos] = str.sPtr[i];

	for (int i = pos; i < pos + sublen; i++)
		place.sPtr[i] = subplace[i - pos];

	for (int i = pos + sublen; i < place.size; i++)
		place.sPtr[i] = sPtr[i - sublen];

	delete[] sPtr;
	sPtr = new char[place.size];
	size = place.size;
	for (int i = 0; i < size; i++)
		sPtr[i] = place.sPtr[i];

	return *this;

}
/*
String& String::substr( size_t pos, size_t len ) const{

	String place;
	place.resize(len);

	for (int i = pos; i < size; i++)
		place.sPtr[i - pos] = sPtr[i];

	return place;

}*/

