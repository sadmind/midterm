#include <iostream>
#include "s1031408_String.h"
using namespace std;

ostream &operator<<(ostream& output, const String& str)
{
	output << str.sPtr;
	return output;
}
String::String()
{
	size = 0;
	capacity = 10;
	sPtr = "";
}
String::String(const String &str)
{
	size = str.size;
	capacity = str.capacity;
	sPtr = str.sPtr;
}
//String::String(const String& str, size_t pos, size_t len = npos)
//{
//
//}
//String::String(const char *s)
//{
//	*sPtr = *s;
//}
String::~String()
{
	size = 0;
	capacity = 10;
	sPtr = "";
}