#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "s1011458_String.h"


using namespace std;

String::String()
{
	capacity = 10;
	size = 0;
}

String::String(const String &copy)
:size(copy.size)
{

	setString(copy.sPtr);

}
String::String(char *s)
{
	setString(s);
}
void String::setString(char *str)
{
	sPtr = new char[size+1];

	if (str != 0)
	{
		for (int i = 0; i<= size; i++)
		{
			sPtr = str;
		}
	}
	else
		sPtr[0] = '\0';
}
String::~String()
{

}
String String::operator+ (String& rhs)
{
	int newSize = size + rhs.size;

	char *tempPtr = new char[30];
	
	for (int i = 0; i <= 4; i++)
	{
		tempPtr[i] = sPtr[i];
	}
	tempPtr[5] = ' ';
	for (int i = 6; i <= 30; i++)
	{
		tempPtr[i] = rhs.sPtr[i-6];
	}

	sPtr =tempPtr;

	return *this;
}
//char &String::operator[] (size_t pos)
//{
//	return ;
//}//Get character of string
const char &String::operator[] (size_t pos) const
{
	return pos;
}

String String::operator+ (char*   rhs)
{
	int newSize = size + 20;
	char *tempPtr = new char[newSize + 1];

	for (int i = 0; i <= newSize; i++)
	{
		tempPtr = sPtr;
	}
	for (int i = 0; i <= newSize; i++)
	{
		tempPtr = rhs;
	}

	tempPtr = sPtr;

	return *this;
}
size_t String::getSize() const
{
	return size;
}
size_t String::getCapacity() const
{
	return capacity;
}
String &String::operator= (const String &str)
{
	if (&str != this)
	{
		size = str.size;
		setString(str.sPtr);
	}

	return *this;
}
String &String::operator= (char* s)
{
	size = size + 20;
	for (int i = 0; i <= size; i++)
	{
		sPtr = s;
	}

	return *this;
}
bool String::operator==(const String &str) //< (equal to) true: two identical String
{
	if (sPtr == str.sPtr)
		return true;
}
bool String::operator!=(const String &str) //< (not equal to)
{
	return !(*this == str);
}
bool String::empty() const
{
	return size == 0;
}
void String::push_back(char c)
{

	char *tempPtr = new char[100];
	tempPtr = sPtr;
	tempPtr[18] = c;

//	sPtr = tempPtr;
}
void String::pop_back()
{
	char *tempPtr = new char[100];
	tempPtr = sPtr;
	tempPtr[18] = ' ';

}

String &String::append(const String &str)
{
	int newSize = size + str.size;

	char *tempPtr = new char[50];

	for (int i = 0; i <= 17; i++)
	{
		tempPtr[i] = sPtr[i];
	}
	tempPtr[18] = ' ';
	for (int i = 19; i <= 50; i++)
	{
		tempPtr[i] = str.sPtr[i - 19];
	}

	sPtr = tempPtr;

	return *this;
}

void String::clear()
{
	size = 0;

}
ostream &operator << (ostream &output, const String& s)
{
	output << s.sPtr;
	return output;
}

istream &operator >>(istream &input, String &s)
{
	char temp[100];
	input >> setw(100) >> temp;
	s = temp;
	return input;
}

