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
String::String(const String& str, size_t pos, size_t len)
{
	size = pos - len;
	sPtr = new char[size];
	for (int i = 0; i < size; i++)
	{
		sPtr[i] = str.sPtr[i];
	}
}
String::String(const char *s)
:size(strlen(s))
{
	sPtr = new char[size];
	if (size > 0)
	{
		for (int i = 0; i < size ; i++)
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
void String::reserve(size_t n )
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
		for (int i = capacity; i < size; i++)
		{
			 sPtr[i] = c;
		}
	}
}
void String::pop_back()
{
	sPtr[size - 1] = '\0';
	size = size - 1;
}
String& String::append(const String &str)
{
	String point;
	point = new char[1];
	point[0] = str.sPtr[0];
	return point;
}
String& String::substr(size_t pos , size_t len ) const
{
	String point;
	point = new char[capacity];
	for (int i = pos; i < len; i++)
	{
		point[i] = sPtr[i];
	}
	return point;
}
String& String::insert(size_t pos, const String &str)
{
	String temp;
	size = size + str.size;
	temp = new char[size];
	for (int i = pos+str.size; i < size; i++)
	{
		sPtr[i + str.size] = sPtr[i];
	}
	for (int i = pos; i < pos + str.size; i++)
	{
		sPtr[i + str.size] = sPtr[i];
	}
	for (int i = pos; i < size; i++)
	{
		for (int j = 0; j < str.size; j++)
		{
			sPtr[i] = str.sPtr[j];
		}
	}
	for (int i = 0; i < size; i++)
	{
		temp[i] = sPtr[i];
	}
	return temp;
}
String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen)
{
	String temp;
	size = size + str.size;
	temp = new char[size];
	for (int i = pos; i < size; i++)
	{
		sPtr[i + str.size] = sPtr[i];
	}
	for (int i = pos; i < size; i++)
	{
		for (int j = 0; j < str.size; j++)
		{
			sPtr[i] = str.sPtr[j];
		}
	}
	for (int i = 0; i < size; i++)
	{
		temp[i] = sPtr[i];
	}
	return temp;
}
String& String::erase(size_t subpos, size_t sublen)
{
	String temp;
	temp = new char[size - (sublen - subpos)];
	for (int i = 0; i < size-subpos-1; i++)
	{
		sPtr[i + subpos] = sPtr[sublen + i + 1];
	}
	for (int i = 0; i < temp.size; i++)
	{
		temp[i] = sPtr[i];
	}
	return temp;
}
size_t String::find(const String &str, size_t pos ) const
{
	int i;
	for (i = pos; i < size; i++)
	{
		if (sPtr[i] == str.sPtr[0])
			break;
	}
	return i;
}
size_t String::find_first_of(const String str, size_t pos) const
{
	return 0;
}
char& String::operator[] (size_t pos)
{
	return sPtr[pos];
}
const char& String::operator[] (size_t pos) const
{
	return sPtr[pos];
}
String String::operator+ (const String& rhs)
{
	int temp = size;
	size = size + rhs.size;
	for (int i = 0; i < rhs.size; i++)
	{
		sPtr[temp + i] = rhs.sPtr[i];
	}
	return sPtr;
}
String String::operator+ (const char*   rhs)
{
	return 0;
}
String& String::operator= (const String& str)
{
	return *this = str.sPtr;
}
String& String::operator= (const char* s)
{
	return *this = s;
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