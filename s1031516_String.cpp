#include "s1031516_String.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;


String::String()
{
	char *a;
	cin >> *a;
	a[10] = { };
}

String::String(const String &str)
{
	int n = sizeof(str);
	string f[100];
	for (int i = 0; i <= sizeof(&str); i++)
		f[i] = str[i];
}



String::String(const char *s)
{

}



String::~String()
{
	*this = {};
}

char* String::begin()
{
	String f[1] = {};

}

char* String::end()
{

}

size_t String::getSize() const
{
	int count;
	count = sizeof(*this) - 1;
	return count;
}

void String::resize(size_t n)
{
	
}

void String::resize(size_t n, char c)
{

}

size_t String::getCapacity() const
{
	int a;
	a = sizeof(*this);
	return a;
}



void String::shrink_to_fit()
{

}

void String::clear()
{
}

bool String::empty() const
{
	return false;
}

char &String::front()
{
	String a[100] = { *this };

	if (empty() != true)
	{
		char s;
		return s;
	}

}


char &String::back()
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



char &String::operator[] (size_t pos)
{
	String a[100] = { *this };
}

const char &String::operator[] (size_t pos) const
{

}

String String::operator+ (const String& rhs)
{
	String a = *this;
	int b = sizeof(rhs);
	string c[100];
	for (int i = 0; i <= 100; i++)
		c[i] = a[i] + rhs[i];
}

String String:: operator+ (const char*   rhs)
{

}

String &String::operator= (const String& str)
{

}

String &String::operator= (const char* s)
{

}

bool String::operator==(const String &str)
{

}

bool String::operator!=(const String &str)
{

}

ostream &operator<<(ostream& output, const String& str)
{
	for (int i = 0; i <= sizeof(str); i++)
	{
		output << str[i];
	}
	return output;
}