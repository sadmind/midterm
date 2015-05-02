#include<iostream>
#include"s1031416_String.h"

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
}
String::String(const String &str)
{

	size = str.getSize();
	for (int i = 0; i < 10; i++)
	{
		sPtr[i] = str.sPtr[i];
	}

}
String::String(const String& str, size_t pos, size_t len )
{}
String::String(const char *s)
{}
String::~String()
{}
char* String::begin()
{
	char *first;
	*first = sPtr[0];
	return first;

}
char* String::end()
{
	char *end;
	*end = sPtr[size];
	return end;
}
size_t String::getSize() const
{
	int size_;
	return size_;
}
void String::resize(size_t n)
{}
void String::resize(size_t n, char c)
{}
void String::reserve(size_t n )
{}
void String::shrink_to_fit()
{}
void String::clear()
{}

/*bool String::empty() const
{}

char& String::front()
{}

char& String::back()
{}

void String::push_back(char c)
{}

void String::pop_back()
{}


String& String::append(const String &str)
{}

String& String::substr(size_t pos, size_t len ) const
{}
String& String::insert(size_t pos, const String &str)
{}


String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen)
{}
String& String::erase(size_t subpos, size_t sublen)
{}

size_t String::find(const String &str, size_t pos ) const
{}
size_t String::find_first_of(const String str, size_t pos) const
{}

char& String::operator[] (size_t pos)
{

}
const char& String::operator[] (size_t pos) const
{

}*/
String String::operator+ (const String& rhs)
{
	int plussize;
	plussize = size + rhs.size+1;
	for (int i = 0; i < plussize; i++)
	{
		if (i>size + 1)
		{
			sPtr[i] = rhs.sPtr[i-size-1];
		}
	}

	return sPtr;
}
String String::operator+ (const char*   rhs)
{
	int plussize;


	plussize = size + getSize() + 1;
	for (int i = 0; i < plussize; i++)
	{
		if (i>size + 1)
		{
			sPtr[i] = rhs[i - size - 1];
		}
	}

	return sPtr;
}

String& String::operator= (const String& str)
{
	String  equal;
	for (int i = 0; i < str.size; i++)
		sPtr[i] = str.sPtr[i];

	equal = sPtr;
	return equal;

}
String& String::operator= (const char* s)
{
	String equal;

	for (int i = 0; i < size; i++)
		sPtr[i] = s[i];

	equal = sPtr;

	return equal;
}
/*bool String::operator==(const String &str)
{

}
bool String::operator!=(const String &str)
{

}*/