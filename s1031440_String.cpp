// PG2String test program.
#include <iostream>
#include "s1031440_String.h" // include definition of class String
using namespace std;

ostream &operator<<(ostream& output, const String& str)
{

	for (int i = 0; i <str.size ; i++)
	{
		cout << str.sPtr[i];
	}
	return output;
}
String::String()
{
	size = 0;
	capacity = 10;
}
String::String(const String &str)
{
	size = str.size;
	capacity = str.capacity;
	sPtr = new char[size];
	for (int i = 0; i < size; i++)
	{
		sPtr[i] = str.sPtr[i];
	}
}
String::String(const String& str, size_t pos, size_t len )
{
	size = len - pos + 1;
	sPtr = new char[size];
	for (int i = 0; i < size; i++)
	{
		sPtr[i] = str.sPtr[i + pos];
	}
}
String::String(const char *s)
{
	int count=0;
	sPtr = new char[20];
	for (int i = 0; i < 20; i++)
	{
		sPtr[i] = *s;
		s++;
		count++;
		if (sPtr[i]=='\0')
			break;
	}
	size = count -1;
}
String::~String()
{
	size = 0;
	delete []sPtr;
}
char* String::begin()
{
	char* string1=0;
	*string1 = sPtr[0];
	return string1;
}
char* String::end()
{
	char* string2=0;
	*string2 = sPtr[size];
	return string2;
}

size_t String::getSize() const
{
	size_t count=0;
	for (int i = 0; i >= 0; i++)
	{
		if (sPtr[i] != '\0')
		{
			count++;
		}
		else
			break;
	}
	return count;
}
void String::resize(size_t n)
{
	if (size > n)
	{
		size = n;	
	}
	else
	{
		size = n;
		for (int i = size - 1; i < n; i++)
		{
			sPtr[i] = '\0';
		}
	}
}
void String::resize(size_t n, char c)
{
	if (size > n)
	{
		size = n;
	}
	else
	{
		size = n;
		for (int i = size - 1; i < n; i++)
		{
			sPtr[i] = 'c';
		}
	}
}
/*size_t String::getCapacity() const
{}
void String::reserve(size_t n = 0)
{}
void String::shrink_to_fit()
{}
void String::clear()
{}
bool String::empty() const
{}
char& String::front()
{}
char& String::back()
{}*/
/*void String::push_back(char c)
{
	char space[30];
	for (int i = 0; i < size; i++)
	{
		space[i] = sPtr[i];
	}
	size = size + 1;
	sPtr = new char[size];
	for (int i = 0; i < size-1; i++)
	{
		 sPtr[i]= space[i];
	}
	sPtr[size] = c;
}
void String::pop_back()
{}*/
/*String& String::append(const String &str)
{}
String& String::substr(size_t pos = 0, size_t len = npos) const
{}
String& String::insert(size_t pos, const String &str)
{}
String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen)
{}
String& String::erase(size_t subpos, size_t sublen)
{}
size_t String::find(const String &str, size_t pos = 0) const
{}
size_t String::find_first_of(const String str, size_t pos = 0) const
{}*/
char& String::operator[] (size_t pos)
{
	char number = sPtr[pos];
	return number;
}
const char& String::operator[] (size_t pos) const
{
	char number = sPtr[pos];
	return number;
}
String String::operator+ (const String& rhs)
{
	String string1;
	string1.size = size+rhs.size;
	string1.sPtr = new char[string1.size];
	for (int i = 0; i < size; i++)
	{
		string1.sPtr[i] = sPtr[i];
	}
	for (int i = 0; i < rhs.size; i++)
	{
		string1.sPtr[size+i] = rhs.sPtr[i];
	}
	return string1;
}
String String::operator+ (const char*   rhs)
{
	String string1;
	string1.size = 30;
	string1.sPtr = new char[30];
	for (int i = 0; i < size; i++)
	{
		string1.sPtr[i] = sPtr[i];
	}
	for (int i = size; i < 30; i++)
	{
		string1.sPtr[i] = *rhs;
	}
/*	int count = 0;
	sPtr = new char[20];
	for (int i = 0; i < 20; i++)
	{
		sPtr[i] = *rhs;
		rhs++;
		count++;
		if (sPtr[i] == '\0')
			break;
	}
	size = count - 1;*/
	return string1;

	
}
String& String::operator= (const String& str)
{
	String string1;
	string1.size = str.size;
	string1.capacity = str.capacity;
	string1.sPtr = new char[string1.size];
	for (int i = 0; i < string1.size; i++)
	{
		string1.sPtr[i] = str.sPtr[i];
	}
	return string1;
}
String& String::operator= (const char* s)
{
	String string2;
	string2.sPtr = new char[20];
	for (int i = 0; i < 20; i++)
	{
		*string2.sPtr = *s;
		string2.sPtr[i] = *string2.sPtr;
		s++;
		if (sPtr[i] == '\0')
			break;
	}
	return string2;
}
bool String::operator==(const String &str)
{
	if (size != str.size)
		return false;
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (sPtr[i] != str.sPtr[i])
			{
				return false;
				break;
			}
			else
				return true;
		}
	}
}
bool String::operator!=(const String &str)
{
	if (size != str.size)
		return true;
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (sPtr[i] != str.sPtr[i])
			{
				return true;
			}
			else
			{
				return false;
				break;
			}
		}
	}
}