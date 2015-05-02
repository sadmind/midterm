#include "s1031404_string.h"
#include<iostream>
using namespace std;

ostream &operator<<(ostream& output, const String& str)
{
	output<<str.sPtr;
	return output;
}
String::String()
{
	size_t size = 0;
	size_t capacity = 10;
	char *sPtr = "0";
}

String::String(const String &str)
{
	this->size = str.size;
	this->capacity = str.capacity;
	this->sPtr = str.sPtr;
}

String::String(const String& str, size_t pos, size_t len)
{
	if (pos != len)
	{
		this->size = str.size - (pos - 1);
		for (int i = pos; i < str.size; i++)
			this->sPtr += str.sPtr[i];
	}
}
String::String(const char *s)
{
	*sPtr = *s;
}


String::~String()
{
	String();
}

char* String::begin()
{
	char *first = &sPtr[0];
	return first;
}

char* String::end()
{
	char*last = &sPtr[size - 1];
	return last;
}

size_t String::getSize() const
{
	return size;
}

void String::resize(size_t n)
{
	if (size > n)
	for (int i = size; i > n; i--)
		sPtr[i - 1] = 0;
	size = n;
}

void String::resize(size_t n, char c)
{
	if (size > n)
	for (int i = size; i > n; i--)
		sPtr[i - 1] = 0;
	else
		sPtr += c;
	size = n;
}

size_t String::getCapacity() const
{
	return capacity;
}


void String::reserve(size_t n)
{
	capacity = size * 10;
	if (n > capacity)
		capacity = n;
}
void String::shrink_to_fit()
{
	capacity = size * 10;
}

void String::clear()
{
	size = 0;
	sPtr = 0;
}

bool String::empty() const
{
	if (size == 0)
		return true;
	else
		return false;
}
char&  String::front()
{
	char f = { 0 };
	if (!empty())
		return sPtr[0];
	else
		return f;
}

char&  String::back()
{
	char f = { 0 };
	if (!empty())
		return sPtr[size-1];
	else
		return f;
}

void  String::push_back(char c)
{
	sPtr += c;
	size++;
}

void  String::pop_back()
{
	sPtr[size - 1] = 0;
	size--;
}
String&  String::append(const String &str)
{
	this->size += str.size;
	this->capacity += str.capacity;
	for (int i = 0; i < str.size;i++)
	    this->sPtr += str.sPtr[i];
	return *this;
}

String&  String::substr(size_t pos, size_t len) const
{
	String sub = (0);
	if (pos != len)	
	for (int i = pos; i < size; i++)
		sPtr[i - 1] = 0;
	sub = sPtr;
	return sub;
}

String&  String::insert(size_t pos, const String &str)
{
	int j = 0;
	char temp[100] = { 0 };
	for (int i = pos; i < this->size; i++)
	{
		temp[j] = this->sPtr[i-1];
		j++;
	}
	j = 0;
	this->size += str.size;
	for (int i = pos; i < (str.size+pos+1); i++)
	{
		this->sPtr[i - 1] = str.sPtr[j];
		j++;
	}
	j = 0;
	for (int i = (str.size + pos); i <= this->size; i++)
	{
		this->sPtr[i - 1] = temp[j];
		j++;
	}
	return *this;
}

String&  String::insert(size_t pos, const String &str, size_t subpos, size_t sublen)
{
	int j = 0;
	char temp[100] = { 0 };
	for (int i = pos; i < this->size; i++)
	{
		temp[j] = this->sPtr[i - 1];
		j++;
	}
	j = subpos;
	this->size += sublen;
	for (int i = pos; i <= (sublen+pos); i++)
	{
		this->sPtr[i - 1] = str.sPtr[j-1];
		j++;
	}
	j = 0;
	for (int i = (sublen + pos); i <= this->size; i++)
	{
		this->sPtr[i - 1] = temp[j];
		j++;
	}
	return *this;
}
String&  String::erase(size_t subpos, size_t sublen)
{
	for (int i = subpos; i <= (sublen + subpos); i++)
		sPtr[i] = 0;
	return *this;
}

size_t  String::find(const String &str, size_t pos) const
{
	for (int i = 0; i < this->size; i++)
	if (this->sPtr[i - 1] == str.sPtr[0])
		return i - 1;
	else
		return npos;

}
size_t  String::find_first_of(const String str, size_t pos) const
{
	for (int i = 0; i < this->size; i++)
	if (this->sPtr[i - 1] == str.sPtr[0])
		return i - 1;
	else
		return npos;

}
char&  String::operator[] (size_t pos)
{
	char o = *sPtr;
	this->size = pos;
	return o;
}
const char&  String::operator[] (size_t pos) const
{
	 pos;
	 return pos;
}

String  String::operator+ (const String& rhs)
{
	int j = 0;
	for (int i = this->size; i < (this->size + rhs.size + 1); i++)
	{
		this->sPtr[i] = rhs.sPtr[j];
		j++;
	}
	return *this;
}
String  String::operator+ (const char*   rhs)
{
	int j = 0;
	int i = this->size;
	while (rhs[j]==0)
	{
		this->sPtr[i] = rhs[j];
		j++;
		i++;
	}
	return *this;
}

String&  String::operator= (const String& str)
{
	this->size = str.size;
	this->sPtr = str.sPtr;
	return *this;
}
String&  String::operator= (const char* s)
{
	int j = 0;
	while (s[j] == 0)
	{
		this->sPtr[j] = s[j];
		j++;
	}
	return *this;
}

bool  String::operator==(const String &str)
{
	if (this->sPtr == str.sPtr)
		return true;
	else
		return false;
}
bool  String::operator!=(const String &str)
{

	if (this->sPtr != str.sPtr)
		return true;
	else
		return false;
}