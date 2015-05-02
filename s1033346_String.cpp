#include"s1033346_String.h"
#include<iostream>
using namespace std;
//string has not '\0', after resize may content \0 
String::String()
{
	size = 0;
	capacity = 10;
	sPtr = new char[10];
}
String::String(const String &str)
{
	size = str.size;
	capacity = str.capacity;
	sPtr = new char[capacity];
	for (int i = 0; i < capacity; i++)
		sPtr[i] = str.sPtr[i];
}
String::String(const String& str, size_t pos, size_t len )
{
	if (len == npos)
	{
		size = str.size - pos + 1;
		capacity = size;
		sPtr = new char[capacity];
		for (int i = 0; i < size; i++)
			sPtr[i] = str.sPtr[pos + i];
	}
	else
	{
		size = len - pos + 1;
		capacity = size;
		sPtr = new char[capacity];
		for (int i = 0; i < size; i++)
			sPtr[i] = str.sPtr[pos + i];
	}
}
String::String(const char *s)
{
	int ssize = 0;
	while (s[ssize] != '\0')
		ssize++;
	size = ssize;
	capacity = size;
	sPtr = new char[capacity];
	for (int i = 0; i < size; i++)
		sPtr[i] = s[i];
}
String::~String()
{
	delete sPtr;
	sPtr = 0;
}
char* String::begin()
{
	return sPtr;
}
char* String::end()
{
	return sPtr + size - 1;
}
size_t String::getSize() const
{
	return size;
}
void String::resize(size_t n)
{
	if (n <= size)
	{
		String temp(*this);
		size = n;
		capacity = size;
		delete [] sPtr;
		sPtr = new char[capacity];
		for (int i = 0; i < size; i++)
			sPtr[i] = temp.sPtr[i];
	}
	else//n>size
	{
		String temp(*this);
		size = n;
		capacity = size;
		delete [] sPtr;
		sPtr = new char[capacity];
		for (int i = 0; i < temp.size; i++)
			sPtr[i] = temp.sPtr[i];
		for (int i = temp.size; i < capacity; i++)
			sPtr[i] = '\0';
	}
}
void String::resize(size_t n, char c)
{
	if (n <= size)
	{
		String temp(*this);
		size = n;
		capacity = size;
		delete [] sPtr;
		sPtr = new char[capacity];
		for (int i = 0; i < size; i++)
			sPtr[i] = temp.sPtr[i];
	}
	else//n>size
	{
		String temp(*this);
		size = n;
		capacity = size;
		delete [] sPtr;
		sPtr = new char[capacity];
		for (int i = 0; i < temp.size; i++)
			sPtr[i] = temp.sPtr[i];
		for (int i = temp.size; i < capacity; i++)
			sPtr[i] = c;
	}
}
size_t String::getCapacity() const
{
	return capacity;
}
void String::reserve(size_t n )
{
	if (n>capacity)
	{
		String temp(*this);
		capacity = n;
		delete[] sPtr;
		sPtr = new char[capacity];
		for (int i = 0; i < size; i++)
			sPtr[i] = temp.sPtr[i];
	}
}
void String::shrink_to_fit()
{
	if (size != capacity)
	{
		char* temp = sPtr;
		capacity = size;
		sPtr = new char[capacity];
		for (int i = 0; i < size; i++)
			sPtr[i] = temp[i];
		delete [] temp;
	}
}
void String::clear()
{
	size = 0;
	capacity = 0;
	delete[] sPtr;
	sPtr = 0;
}
bool String::empty() const
{
	if (!size)
		return true;
	else
		return false;
}
char& String::front()
{
	char& temp = sPtr[0];
	return temp;
}
char& String::back()
{
	char& temp = sPtr[size-1];
	return temp;
}
void String::push_back(char c)
{
	if (size == capacity)
	{
		char*temp = sPtr;
		capacity += 10;
		sPtr = new char[capacity];
		for (int i = 0; i < size; i++)
			sPtr[i] = temp[i];
		sPtr[size + 1] = c;
		size++;
		delete[] temp;
	}
	else
	{
		size++;
		sPtr[size - 1] = c;
	}
}
void String::pop_back()
{
	size--;
}
String& String::append(const String &str)
{
	String temp(*this);
	capacity = size + str.size;
	sPtr = new char[capacity];
	for (int i = 0; i < size; i++)
		sPtr[i] = temp.sPtr[i];
	for (int i = 0; i < str.size; i++)
		sPtr[size + i] = str.sPtr[i];
	size += str.size;
	return *this;
}
/*String& String::substr(size_t pos , size_t len) const
{
	return *this;
}
String& String::insert(size_t pos, const String &str)
{
	return *this;
}
String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen)
{
	return *this;
}	
String& String::erase(size_t subpos, size_t sublen)
{
	return *this;
}
*/
size_t String::find(const String &str, size_t pos ) const
{
	int findnum = 0;
	for (int i = 0; i < size; i++)
	{
		findnum = 0;
		for (int j = pos; j < str.size; j++)
		{
			if (sPtr[i] != str.sPtr[j])
				break;
			else
				findnum++;
		}
		if (findnum = str.size)
			return i;
	}
	return npos;
}

size_t String::find_first_of(const String str, size_t pos ) const
{

	for (int i = 0; i < size; i++)
	{
		if (sPtr[i] == str.sPtr[pos])
			return i;
	}
	return npos;
}

char& String::operator[] (size_t pos)
{
	if (pos > size)
		cerr << "The position is more than the string'size\n";
	char& temp = sPtr[pos];
	return temp;
}
const char& String::operator[] (size_t pos) const
{
	if (pos > size)
		cerr << "The position is more than the string'size\n";
	char& temp = sPtr[pos];
	return temp;
}

String String::operator+ (const String& rhs)
{
	String temp;
	temp.size = size + rhs.size;
	temp.capacity = size;
	temp.sPtr = new char[temp.capacity];
	for (int i = 0; i < size; i++)
		temp.sPtr[i] = sPtr[i];
	for (int i = 0; i < rhs.size; i++)
		temp.sPtr[size + i] = rhs.sPtr[i];
	return temp;
}
String String::operator+ (const char*rhs)
{
	int rhslen = 0;
	while (rhs[rhslen] != '\0')
		rhslen++;
	String temp;
	temp.size = size + rhslen;
	temp.capacity = size;
	temp.sPtr = new char[temp.capacity];
	for (int i = 0; i < size; i++)
		temp.sPtr[i] = sPtr[i];
	for (int i = 0; i < rhslen; i++)
		temp.sPtr[size + i] = rhs[i];
	return temp;
}

String& String::operator= (const String& str)
{
	size = str.size;
	capacity = str.capacity;
	sPtr = new char[capacity];
	for (int i = 0; i < capacity; i++)
		sPtr[i] = str.sPtr[i];
	return *this;
}
String& String::operator= (const char* s)
{
	int ssize = 0;
	while (s[ssize] != '\0')
		ssize++;
	size = ssize;
	capacity = size;
	sPtr = new char[capacity];
	for (int i = 0; i < size; i++)
		sPtr[i] = s[i];
	return *this;
}
//Assigns a new value to the string, replacing its current contents.

bool String::operator==(const String &str)
{
	if (size != str.size)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (sPtr[i] != str.sPtr[i])
				return false;
		}
		return true;
	}
}//< (equal to) true: two identical String
bool String::operator!=(const String &str)
{
	return !((*this) == str);
}//< (not equal to)