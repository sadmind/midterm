#include<iostream>
#include "s1031520_String.h"
using namespace std;

String::String()
{
	capacity = 10;
	sPtr = new char[capacity];
}
String::String(const String &str)
{
	sPtr = new char[capacity];
	for (int i = 0; i < str.size; i++)
	{
		sPtr[i] = str.sPtr[i];
	}
}
String::String(const String& str, size_t pos, size_t len = npos)
{
	size = pos - len;
	for (int i = 0; i < size; i++)
	{
		sPtr[i] = str.sPtr[i];
	}
}
String::String(const char *s)
:size(strlen(s))
{
	sPtr = new char[capacity];
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			sPtr[i] = s[i];
		}
	}
}
String::~String()
{
	delete[] sPtr;
}
char* String::begin()
{
	char* begin;
	begin = new char[1];
	begin[0] = sPtr[0];
	return begin;
}
char* String::end()
{
	char* end;
	end = new char[1];
	end[0] = sPtr[size - 1];
	return end;
}
size_t String::getSize() const
{
	return size;
}
void String::resize(size_t n)
{
	if (size > n)
	{
		size = n;
	}
	else if (size < n)
	{
		for (int i = size + 1; i < n; i++)
		{
			sPtr[i] = '\0';
		}
		size = n;
	}
}
void String::resize(size_t n, char c)
{
	if (size>n)
	{
		size = n;
		for (int i = 0; i < n; i++)
		{
			sPtr[i] = c;
		}
	}
}
size_t String::getCapacity() const
{
	return capacity;
}
void String::reserve(size_t n = 0)
{

}
void String::shrink_to_fit()
{
	capacity = size;
}
void String::clear()
{
	size = 0;
	sPtr[0] = '\0';
}
bool String::empty() const
{
	if (size == 0)
		return true;
	else
		return false;
}
char& String::front()
{
	if (size != 0)
	{
		return sPtr[0];
	}
}
char& String::back()
{
	if (size != 0)
	{
		return sPtr[size - 1];
	}
}
void String::push_back(char c)
{
	if (size > c)
	{
		size = size + c;
		for (int i = capacity + 1; i < size; i++)
		{
			 sPtr[i] = c;
		}
	}
}
void String::pop_back()
{

}
String& String::append(const String &str)
{
	String point;
	point = new char[1];
	point[0] = str.sPtr[0];
	return point;
}
String& String::substr(size_t pos = 0, size_t len = npos) const
{

}
String& String::insert(size_t pos, const String &str)
{

}
String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen)
{

}
String& String::erase(size_t subpos, size_t sublen)
{

}
size_t String::find(const String &str, size_t pos = 0) const
{
	int i;
	for (i = pos; i < size; i++)
	{
		if (sPtr[i] == str.sPtr[0])
			break;
	}
	return i;
}
size_t String::find_first_of(const String str, size_t pos = 0) const
{

}
char& String::operator[] (size_t pos)
{
	cout << sPtr[pos];
}
const char& String::operator[] (size_t pos) const
{

}
String String::operator+ (const String& rhs)
{

}
String String::operator+ (const char*   rhs)
{

}
String& String::operator= (const String& str)
{
	return *this = str.sPtr;
}
String& String::operator= (const char* s)
{
	//return 
}
bool String::operator==(const String &str)
{
	return *this == str;
}
bool String::operator!=(const String &str)
{
	return *this != str;
}
ostream &operator<<(ostream& output, const String& str)
{
	for (int i = 0; i < str.size; i++)
	{
		output << str.sPtr[i];
	}

	return output;
}