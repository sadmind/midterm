#include <iostream>
#include <string>
#include "s1031444_String.h"
using namespace std;

String::String()
{
	sPtr = new char[size];

	for (int i = 0; i < size; i++)
		sPtr[i] = 0;
		capacity = 10;
}

String::String(const String &str)
	 :size(str.size)
{
	sPtr = new char[size];
	for (int i = 0; i < size; i++)
		sPtr[i] = str.sPtr[i];
}

String::String(const String& str, size_t pos, size_t len)
{

}

String::String(const char *s)
{

}

String::~String()
{
	delete[] sPtr;
}

char* String::begin()
{

}

char* String::end()
{

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

void String::reserve(size_t n )
{

}

void String::shrink_to_fit()
{

}

void String::clear()
{

}

bool String::empty() const
{
	

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

String& String::append(const String &str)
{

}

String& String::substr(size_t pos , size_t len ) const
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
	cout << "to be or not to be, that is question" << endl;
}

size_t String::find(const String &str, size_t pos ) const
{

}

size_t String::find_first_of(const String str, size_t pos ) const
{

}

char& String::operator[] (size_t pos)
{
	if (pos < 0 || pos >= size)
	{
		cerr << "\nError: pos" << pos << "out of range" << endl;
		exit(1);
	}
	return sPtr[pos];
}

const char& String::operator[] (size_t pos) const
{
	if (pos < 0 || pos >= size)
	{
		cerr << "\nError: pos" << pos << "out of range" << endl;
		exit(1);
	}
	return sPtr[pos];
}

String String::operator+ (const String& rhs)
{

}

String String::operator+ (const char*   rhs)
{

}

String& String::operator= (const String& str)
{
	if (&str != this)
	{
		if (size != str.size)
		{
			delete[] sPtr;
			size = str.size;
			sPtr = new char[size];
		}
		for (int i = 0; i < size; i++)
			sPtr[i] = str.sPtr[i];
	}
	return *this;
}

String& String::operator= (const char* s)
{
	
}

bool String::operator==(const String &str)
{
	if (size != str.size)
		return false;

	for (int i = 0; i < size; i++)
		if (sPtr[i] != str.sPtr[i])
			return false;
}

bool String::operator!=(const String &str)
{
	return !(*this == str);
}

ostream &operator<<(ostream& output, const String& str)
{
	int i;
	for (int i = 0; i < str.size; i++)
	{
		output << str.sPtr[i];
	}
	return output;
}