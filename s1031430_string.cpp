#include<iostream>
#include<cstring>
#include<string>
#include"s1031430_string.h"

using namespace std;

String::String()
{
	size = 0;
	capacity = 10;
}

String::String(const String &str)
{
	this->size = str.size;
	this->capacity = str.capacity;
}

String::String(const String& str, size_t pos, size_t len = npos)
{
	if (pos==str.size)
		pos = str.size;
		len = str.capacity;
}

String::String(const char *s)
{
	s = sPtr[size];
	s = sPtr[capacity];
}

String::~String()
{
	delete [] sPtr;
}

char *String::begin()
{
	return sPtr[0];
}

char *String::end()
{
	return sPtr[capacity];
}

size_t String::getSize() const
{
	return size;
}

void String::resize(size_t n)
{

}

void String::resize(size_t n, char c)
{

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
	String x;
	if (x.capacity > x.size)
	{
		capacity = x.size;
	}
}

void String::clear()
{
	delete [] sPtr;
}

bool String::empty() const
{
	if (size != 0)
		return false;
	else
		return true;
}

char& String::front()
{

}

char& String::back()
{

}

void String::push_back(char c)
{

}

void String::pop_back()
{

}

String &String::append(const String &str)
{

}

String &String::substr(size_t pos = 0, size_t len = npos) const
{

}

String &String::insert(size_t pos, const String &str)
{

}

String &String::insert(size_t pos, const String &str, size_t subpos, size_t sublen)
{

}

String &String::erase(size_t subpos, size_t sublen)
{

}

size_t String::find(const String &str, size_t pos = 0) const
{

}

char& String::operator[] (size_t pos)
{

}

const char& String::operator[] (size_t pos) const
{

}

String String::operator+(const String& rhs)
{
	this->size + rhs.size;
	this->capacity + rhs.capacity;
}

String String::operator+(const char*rhs)
{

}

String &String::operator=(const String& str)
{
	this->size = str.size;
	this->capacity = str.capacity;
}

String &String::operator=(const char* s)
{
	
}

bool String::operator==(const String &str)
{
	if (this->size != str.size)
		return false;
	else
		return true;
	if (this->capacity != str.capacity)
		return false;
	else
		return true;
}

bool String::operator!=(const String &str)
{
	if (this->size == str.size)
		return false;
	else
		return true;
	if (this->capacity == str.capacity)
		return false;
	else
		return true;
}

ostream &operator<<(ostream &output, const String &str)
{
	output << str.size;
	output << str.capacity;
}