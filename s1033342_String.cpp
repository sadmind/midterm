#include <iostream>
#include <iomanip>
#include <cstring>
#include "s1033342_String.h"
using namespace std;

ostream &operator<<(ostream& output, const String& str)
{
	output << str.sPtr;
	return output;
}

//default constructor
String::String(const char *cons)
:size((cons != 0) ? strlen(cons) : 0) 
{
	capacity = 10;
	setString(cons);
}

void String::setString(const char *string)
{
	size = strlen(string);
	sPtr = new char[size + 1];
	if (size != 0)
		strcpy(sPtr, string);
	else
		sPtr = '\0';
}

//copt constuctor
String::String(const String &str)
{
	setString(str.sPtr);
}

//destructor
String::~String()
{
	delete[] sPtr;
}



size_t String::getSize() const
{
	return size;
}

size_t String::getCapacity() const
{
	return capacity;
}

void String::clear()
{
	sPtr = '\0';
}

bool String::empty() const
{
	return size == 0;
}

void String::push_back(char c)
{
	size++;
	String temp;
	temp.size = size + 1;
	temp.sPtr = new char[temp.size];
	
	strcpy(temp.sPtr, sPtr);
	temp.sPtr[temp.size - 1] = '\0';
	temp.sPtr[temp.size - 2] = c;
	delete[] sPtr;

	sPtr = new char[size + 1];
	strcpy(sPtr, temp.sPtr);
}

void String::pop_back()
{
	String temp;
	temp.size = size;
	temp.sPtr = new char[temp.size + 1];
	strcpy(temp.sPtr, sPtr);
	temp.sPtr[size - 1] = '\0';
	size -= 1;

	delete[] sPtr;
	sPtr = new char[size + 1];
	strcpy(sPtr, temp.sPtr);
}



String String::operator+ (const String& rhs)
{
	size_t newLength = size + rhs.getSize();

	char* tempPtr = new char[newLength];
	strcpy(tempPtr, sPtr);
	strcpy(tempPtr + size, rhs.sPtr);

	return tempPtr;
}

String String::operator+(const char* rhs)
{
	size_t newLength = size + strlen(rhs);

	char* tempPtr = new char[newLength];
	strcpy(tempPtr, sPtr);
	strcpy(tempPtr + size, rhs);

	return tempPtr;
}

String &String::operator=(const String& str)
{
	String temp;
	temp.size = str.size;
	temp.capacity = (capacity < str.size) ? size + 1 : 10;
	temp.sPtr = new char[size + 1];
	strcpy(temp.sPtr, str.sPtr);

	return temp;
}

String &String::operator=(const char* s)
{
	delete[] sPtr;
	size = strlen(s);
	setString(s);

	return *this;
}

char& String::operator[] (size_t pos)
{
	return sPtr[pos];
}

bool String::operator==(const String &str)
{
	return strcmp(sPtr, str.sPtr) == 0;
}

bool String::operator!=(const String &str)
{
	return !(strcmp(sPtr, str.sPtr) == 0);
}

