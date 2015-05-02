#include "s1031452_String.h"
#include<string>
#include<iostream>
using namespace std;

ostream &operator<<(ostream& output, const String& str)
{
	for (size_t i = 0; i < str.size; i++)
	{
		output << str.sPtr[i];
	}
	return output;
}

String::String()
{
	size = 0;
	capacity = 10;
	sPtr = new char[capacity];
	sPtr = '\0';
}
String::String(const String &str)
{
	size = str.size;
	capacity = str.capacity;
	sPtr = new char[capacity];
	for (size_t i = 0; i < capacity; i++)
	{
		sPtr[i] = str.sPtr[i];
	}
}
String::String(const char *s)
{
	size_t length = strlen(s);
	if (capacity < length)
	{
		capacity = length;
		sPtr = new char[capacity];
	}
	size = length;
	for (size_t i = 0; i < size; i++)
	{
		sPtr[i] = s[i];
	}
}
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
	return size;
}
void String::resize(size_t n)
{
	if (n < size)
	{
		for (size_t i = n; i < size; i++)
		{
			sPtr[i] = '\0';
		}
	}
	if (n>size)
	{
		char* tmp = new char[n];
		for (size_t i = 0; i < size; i++)
		{
			tmp[i] = sPtr[i];
		}
		for (size_t i = size; i < n; i++)
		{
			tmp[i] = '\0';
		}
		for (size_t i = 0; i < size; i++)
		{
			sPtr[i] = tmp[i];
		}
	}
	size = n;
}
void String::resize(size_t n,char c)
{
	if (n < size)
	{
		for (size_t i = n; i < size; i++)
		{
			sPtr[i] = '\0';
		}
	}
	if (n>size)
	{
		if (n>capacity)
		{
			capacity = n;
		}
		char* tmp = new char[n];
		for (size_t i = 0; i < size; i++)
		{
			tmp[i] = sPtr[i];
		}
		for (size_t i = size; i < n; i++)
		{
			tmp[i] = c;
		}
		for (size_t i = 0; i < size; i++)
		{
			sPtr[i] = tmp[i];
		}
	
	}
	size = n;
	
}
size_t String::getCapacity() const
{
	return capacity;
}
void String::reserve(size_t n)
{
	if (n>capacity)
	{
		capacity = n;
		resize(n);
	}
}
void String::shrink_to_fit()
{
	capacity = size;
}
void String::clear()
{
	size = 0;
	sPtr = '\0';
}
bool String::empty() const
{
	if (size==0)
	{
		return true;
	}
	return false;
}
char& String::front()
{
	return sPtr[0];
}
char& String::back()
{
	return sPtr[size - 1];
}
void String::push_back(char c)
{
	char* tmp = new char[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = sPtr[i];
	}
	tmp[size] = c;
	size++;
	for (size_t i = 0; i < size; i++)
	{
		sPtr[i] = tmp[i];
	}
	if (capacity<size)
	{
		capacity = size;
	}
}
void String::pop_back()
{
	sPtr[size - 1] = '\0';
	size--;
}
char& String::operator[] (size_t pos)
{
	return sPtr[pos];
}
const char& String::operator[] (size_t pos) const
{
	return sPtr[pos];
}
