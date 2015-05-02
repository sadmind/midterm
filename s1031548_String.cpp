#include <iostream>
#include "s1031548_String.h"
using namespace std;

String::String()
{
	sPtr = new char[size];

	for (int i = 0; i < size; i++)
	{
		sPtr[i] = 0;
	}
}
String::String(const String &str)
:size(str.size)
{
	setString(str.sPtr);
}
/*String::String(const String& str, size_t pos, size_t len = npos)
{

}*/
String::String(const char *s)
:size((s != 0) ? strlen(s) : 0)
{
	setString(s);
}
String::~String()
{
	delete[] sPtr;
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
/*void String::resize(size_t n)
{
	if (n < size)
	{
		
	}
	else if (n>size)
	{

	}
}
// Similar to above one. The new elements are initialized as copies of c.
void String::resize(size_t n, char c)
{

}*/

size_t String::getCapacity() const
{
	size_t len;
	len = (capacity > 0 ? capacity : 10);
	return len;
}

/*void String::reserve(size_t n = 0)
{
	if (n > capacity)
	{
		
	}
}*/
void String::shrink_to_fit()
{

}
void String::clear()
{

}
bool String::empty() const
{
	if (size != 0)
	{
		return false;
	}

	return true;
}
/*char& String::front()
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

}
size_t String::find_first_of(const String str, size_t pos = 0) const
{

}*/
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
	size_t newsize = size + rhs.size;
	char *tempPtr = new char[newsize + 1];

	strcpy(tempPtr, sPtr);
	//strcpy(tempPtr + size, rhs.sPtr);
	strcat(tempPtr, rhs.sPtr);

	delete[] sPtr;
	sPtr = tempPtr;
	size = newsize;

	return *this;
}
/*String String::operator+ (const char*  rhs)
{
	size_t newsize = size + rhs.size;
	char *tempPtr = new char[newsize + 1];

}*/
String& String::operator= (const String& str)
{
	if (&str != this)
	{
		delete[] sPtr;
		size = str.size;
		setString(str.sPtr);
	}
	return *this;
}
/*String& String::operator= (const char* s)
{
	if (*s != this)
	{
		if (size != s.size)
		{
			delete[] sPtr;
			size = s.size;
			sPtr = new char[size];
		}
		for (int i = 0; i < size; i++)
		{
			sPtr[i] = s.sPtr[i];
		}
	}
	return *this;
}*/


bool String::operator==(const String &str)
{
	return strcmp(sPtr, str.sPtr) == 0;
}
bool String::operator!=(const String &str)
{
	return !(*this == str);
}
void String::setString(const char* string2)
{
	sPtr = new char[size + 1];
	if (string2 != 0)
	{
		strcpy(sPtr, string2);
	}
	else
	{
		sPtr[0] = '\0';
	}
}
ostream &operator<<(ostream& output, const String& str)
{
	output << str.sPtr;
	return output;
}
istream& operator>>(istream& input, string& str)
{
	char temp[100];
	input >> temp;
	str = temp;
	return input;
}