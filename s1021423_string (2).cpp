// PG2String test program.
#include <iostream>
#include "s1021423_string.h" // include definition of class String
using namespace std;

String::String()
{
	size = 0;
	capacity = 10;
	sPtr[capacity];
}
String::String(const String& str, size_t pos, size_t len = npos)
{
	String(str, pos, npos);
}
String::String(const String &copy)
{
	*sPtr*(copy, 0);
}
String::String(const char *s)
{

}
String::~String()
{
	sPtr = "\n";
	cout << "String destructor runs" << endl;
}
char* String::begin() // Returns an pointer referring to the first character in the string.
{
	sPtr = sPtr+0;
}
char* String::end()
{
	sPtr = sPtr+size;
}

size_t String::getSize() const
{
	return size;
}
void String::resize(size_t n )
{
	size = n;
	if (n > size)
	{
		for (int i = size; i < n; i++)
		{
			sPtr[i] = 0;
		}
	}
}
void String::resize(size_t n, char c)
{	
	size = n;
}

void String::reserve(size_t n = 0)
{

}
void String::shrink_to_fit() // Requests the container to reduce its capacity to fit its size.
{
	if (capacity > size)
	{
		capacity = size;
	}

}
void String::clear()
{
	size = 0;
}
bool String::empty() const
{
	if (size == 0)
	{
		return true;
	}
	else
		return false;
}
char& String::front()
{
	return sPtr[0];
}
char& String::back()
{
	if (!empty)
		return sPtr[size];
	else
		cout << "false";

}
void String::push_back(char c)
{
	capacity+= c.size();

}
String &String::append(const String &str)
{
	capacity += str.size;
	for (int i = 0; i < str.size; i++)
	{
		sPtr[size + i] = str[i];
	}
	return *this;
}
String &String::substr(size_t pos = 0, size_t len = npos) const
{

}

String &String::insert(size_t pos, const String &str)
{
	capacity += str.size;
	for (int i = pos; i < str.size + pos; i++)
	{
		sPtr[i + pos] = sPtr[i];
	}
	for (int i = 0; i < str.size; i++)
	{
		sPtr[pos + i] = str[i];
	}
	return *this;
}
String &String::erase(size_t subpos, size_t sublen)
{
	for (int i = subpos; i >= sublen; i--)
		sPtr[i] = 0;
	return *this;
}
size_t String::find(const String &str, size_t pos = 0) const
{
	bool bCorrect = false;

}
ostream&operator<<(ostream& output, const String& str)
{
	if (str.size == 0)
		output << '0' << endl;
	else
	for (int i = 0; i < str.size; i++)
	{
		output << str[i];
	}
	output << endl;
}