#include <iostream>
#include<cstring>
#include "PG2String.h" 
using namespace std;

String::String()
{
	size = 0;
    capacity=10;
	sPtr = new char[1];
	sPtr = " ";
	size++;
}
String::String(const String &str)
{
	size++;
	size = str.size;
	sPtr = new char[size+1];
	strcpy(sPtr,str.sPtr);


}

String::~String()
{
	--size;
	delete[]sPtr;
}
String::String(const char *s)
{
	size = strlen(s);
	sPtr = new char[size + 1];
	strcpy(sPtr, s);
	size++;


}
String& String::operator= (const String& str)
{
	if (this == &str)
		return *this;
	delete[]sPtr;
	size = str.size;
	sPtr = new char[size + 1];
	strcpy(sPtr, str.sPtr);
	return *this;
	

}
String& String::operator= (const char* s)
{
	delete[]sPtr;
	size = strlen(s);
	sPtr = new char[size + 1];
	strcpy(sPtr, s);
	return *this;
}

char&String:: operator[] (size_t pos)
{
	return sPtr[pos];
}
const char&String:: operator[] (size_t pos) const
{
	return sPtr[pos];
}

ostream &operator<<(ostream& output, const String& str)
{
	output << str.sPtr;
	return output;
}
istream &operator >> (istream & input, String &str)
{
	char temp[String::CINLIM];
	input.get(temp, String::CINLIM);
	if (input)
		str = temp;
	while (input &&input.get() != '\n')
		continue;
	return input;



}