#include <iostream>
#include "s1031552_String.h" // include definition of class String
using namespace std;

ostream &operator<<(ostream& output, const String& str)
{
	output << str.sPtr;
	return output;
}

String::String()
{
	sPtr = "";
	size = 0;
	capacity = 10;
}

String::String(const String &str)
{
		sPtr = str.sPtr;
		size = str.size;
}

//String::String(const String& str, size_t pos, size_t len = npos)
//{
//	for (int i = pos; i < len; i++) {
//		sPtr[i] = str.sPtr[i];
//	}
//}

String::String(/*const*/ char *s)
{
	sPtr = s;
	size = strlen(s);
}

//String::~String

char* String::begin()
{
	return &sPtr[0];
}

char* String::end()
{
	return &sPtr[size - 1];
}

size_t String::getSize() const
{
	int count = 0;
	for (int i = 0; i != '\0' && i < size; i++) {
		count++;
	}

	return count;
}

String String::operator + (const String& rhs)
{
	for (int i = 0; i < rhs.size; i++) {
		sPtr[size + i] = rhs.sPtr[i];
	}
	return *this;
}

String String::operator+ (const char*   rhs)
{
	for (int i = 0; rhs[i] != '\0'; i++) {
		sPtr[size + i] = rhs[i];
	}
	return *this;
}

