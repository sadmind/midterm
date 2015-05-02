#include <iostream>
#include<fstream>
#include<string>
#include "s1033336_String.h" // include definition of class String
using namespace std;

String::String()
{
	size = 0;
	capacity = (size / 16) * 16 + 10;
}

String::String(const String &str)
{
	size =str.size;
	capacity = (size/16)*16+10;
}

//String::String(const String& str, size_t pos, size_t len = npos)


String::String(const char *s)
{
	sPtr = new char[size];
	*sPtr = *s;
}

String::~String()
{
	size = 0;
	capacity = 10;
	delete sPtr;
}

char *String::begin()
{
	*sPtr = 0;
	return sPtr;
}

char *String::end()
{
	*sPtr = size-1;
	return sPtr;
}

size_t String::getSize() const
{
	return size;
}

void String::resize(size_t n)
{
	if (size>n)
		size = n;
	else if (size < n)
	{
		size = n;
		for (int i = size; i <= n; i++)
		{
			sPtr[i] = '/0';
		}
	}
	else
		size = n;
}

void String::resize(size_t n, char c)
{
	for (int i = 0; i < size; i++)
		sPtr[i+1] = sPtr[i + 2];
	sPtr[0] = c;
}

size_t String::getCapacity() const
{
	return capacity;
}

//void String::reserve(size_t n = 0)


void String::shrink_to_fit()
{
	if (capacity < size)
		capacity = size;
}

void String::clear()
{
	size = 0;
	capacity = 10;
}

bool String::empty() const
{
	if (size == 0)
		return true;
	else
		return false;
}

char & String::front()
{
	return *begin();
}

char & String::back()
{
	return *end();
}

void String::push_back(char c)
{
	size = size + 1;
	sPtr[size - 1] = c;
}

void String::pop_back()
{
	size = size - 1;
}

//String & String::append(const String &str)


//String & String::substr(size_t pos = 0, size_t len = npos) const


//String& String::insert(size_t pos, const String &str)


//String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen)

String& String::erase(size_t subpos, size_t sublen)
{
	if (subpos + sublen <= size)
	{
		for (int i = 0; i + subpos + sublen < size; i++)
			sPtr[i] = sPtr[subpos];
		return *this;
	}
	else
	{
		size= npos;
		return *this;
	}
}

//size_t String::find(const String &str, size_t pos = 0) const


//size_t String::find_first_of(const String str, size_t pos = 0) const


//char& String::operator[] (size_t pos)


//const char& String::operator[] (size_t pos) const


//String operator+ (const String& rhs)

//String operator+ (const char*   rhs)

String& String::operator= (const String& str)
{
	size = str.size;
	capacity = str.capacity;
	sPtr = str.sPtr;
	return *this;
}
//String& String::operator= (const char* s)
bool String::operator==(const String &str)
{
	if (size == str.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (sPtr != str.sPtr)
				return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}
bool String::operator!=(const String &str)
{
	if (size == str.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (sPtr != str.sPtr)
				return true;
		}
		return false;
	}
	else
	{
		return true;
	}
}

ostream &operator<<(ostream& output, const String& str)
{
	for (int i = 0; i < str.size; i++)
		output << str.sPtr[i];
	return output;
}