#include"s1031508_String.h"
#include<iostream>

using namespace std;

ostream &operator<<(ostream& output, const String& str)
{
	for (size_t i = 0; i < str.getSize(); i++)
	{
		output << str[i];
	}
	return output;
}
String::String()
{
	size = 0;
	capacity = 10;
	sPtr = new char[capacity];
}
String::String(const String &str)
{
	size = str.size;
	capacity = str.capacity;
	sPtr = new char[capacity];
	for (size_t i = 0; i < size; i++)
	{
		sPtr[i] = str.sPtr[i];
	}
}
String::String(const String& str, size_t pos, size_t len)
{
	int k = 0;
	size = str.size;
	capacity = str.capacity;
	sPtr = new char[capacity];
	for (size_t i = pos; i < pos + len; i++)
	{
			sPtr[k] = str.sPtr[i];
			k++;
	}
}
String::String(const char *s)
{
	size = strlen(s);
	capacity = size;
	sPtr = new char[capacity];
	for (size_t i = 0; i < capacity; i++)
	{
		sPtr[i] = s[i];
	}
}
String::~String()
{
	delete []sPtr;
}
char* String::begin()
{
	char* p = NULL;
	*p= sPtr[0];
	return p;
}
char* String::end()
{
	char* p = NULL;
	*p = sPtr[size-1];
	return p;
}
size_t String::getSize() const
{
	return size;
}
void String::resize(size_t n)
{
	if (n <= capacity)
	{
		if (n > size)
		{
			for (int i = size; i < n; i++)
			{
				sPtr[i] = NULL;
			}
		}
		else if (n < size)
		{
			erase(size, n - size);
		}
	}
	else
	{
		reserve(n);
		resize(n);
	}
}
void String::resize(size_t n, char c)
{
	if (n <= capacity)
	{
		if (n > size)
		{
			for (int i = size; i < n; i++)
			{
				sPtr[i] = c;
			}
		}
		else if (n < size)
		{
			erase(size, n - size);
		}
	}
	else
	{
		reserve(n);
		resize(n, c);
	}
}
size_t String::getCapacity() const
{
	return capacity;
}
void String::reserve(size_t n)
{
	char *buffer = new char[size];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = sPtr[i];
	}
	delete []sPtr;
	capacity = n;
	char* sPtr = new char[capacity];
	for (int i = 0; i < size; i++)
	{
		sPtr[i] = buffer[i];
	}
	size = n;
	delete[]buffer;
}
void String::shrink_to_fit()
{
	char *buffer = new char[size];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = sPtr[i];
	}
	delete []sPtr;
	capacity = size;
	char* sPtr = new char[capacity];
	for (int i = 0; i < size; i++)
	{
		sPtr[i] = buffer[i];
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
	return false;
}
char& String::front()
{
	if (empty() == false)
	{
		char& p = sPtr[0];
		return p;
	}
}
char& String::back()
{
	if (empty() == false)
	{
		char& p = sPtr[size - 1];
		return p;
	}
}
void String::push_back(char c)
{
	if (capacity >= size + 1)
	{
		sPtr[size] = c;
		size += 1;
	}
	else
	{
		reserve(size + 1);
		sPtr[size - 1] = c;
	}
}
void String::pop_back()
{
	sPtr[size - 1] = NULL;
	size -= 1;
}
String& String::append(const String &str)
{
	char *buffer = new char[size];
	for (int i = 0; i < size; i++)
	{
		buffer[i] = sPtr[i];
	}
	delete []sPtr;
	capacity = size + str.size;
	char *sPtr = new char[capacity];
	for (int i = 0; i < size; i++)
	{
		sPtr[i] = buffer[i];
	}
	delete []buffer;
	int k = 0;
	for (int i = size; i < capacity; i++)
	{
		sPtr[i] = str.sPtr[k];
		k++;
	}
	size = capacity;
	return *this;
}
String& String::substr(size_t pos, size_t len) const
{
	String sub(sPtr, pos, len);
	return sub;
}
String& String::insert(size_t pos, const String &str)
{
	size_t osize = size;
	if (size + str.size > capacity)
	{
		reserve(size + str.size);
	}
	char *buffer = new char[osize - pos];
	int k = 0;
	for (int i = pos + 1; i < osize; i++)
	{
		buffer[k] = sPtr[i];
		k++;
	}
	int j = 0;
	for (int i = pos + 1; i < str.size; i++)
	{
		sPtr[i] = str.sPtr[j];
		j++;
	}
	int m = 0;
	for (int i = pos + str.size + 1; i < size; i++)
	{
		sPtr[i] = buffer[m];
		m++;
	}
	return *this;
}
String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen)
{
	insert(pos, str.substr(subpos, sublen));
	return *this;
}
String& String::erase(size_t subpos, size_t sublen)
{
	if (size >= subpos + sublen)
	{
		for (int i = subpos; i < subpos + sublen; i++)
		{
			sPtr[i] = NULL;
		}
		int k = subpos;
		for (int i = subpos + sublen; i < size; i++)
		{
			sPtr[k] = sPtr[i];
		}
		for (int i = size - sublen; i < size; i++)
		{
			sPtr[i] = NULL;
		}
	}
	else
	{
		for (int i = subpos; i < size; i++)
		{
			sPtr = NULL;
		}
	}
	return *this;
}
size_t String::find(const String &str, size_t pos ) const
{
	size_t i;
	for (i = pos; i < size; i++)
	{
		if (substr(i, str.size) == str)
		{
			return i;
		}
	}
	return npos;
}
size_t String::find_first_of(const String str, size_t pos ) const
{
	char p = str.sPtr[0];
	size_t i;
	for (i = pos; i < size; i++)
	{
		if (sPtr[i] == p)
		{
			return i;
		}
	}
	return npos;
}
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
	String sum( append(rhs) );
	return sum;
}
/*String String::operator+ (const char*   rhs)
{
	String rnew(rhs);
	String sum( append(rnew) );
	return sum;
}*/
String& String::operator= (const String& str)
{
	delete []sPtr;
	size = str.size;
	capacity = str.capacity;
	sPtr = new char[capacity];
	for (size_t i = 0; i < size; i++)
	{
		sPtr[i] = str.sPtr[i];
	}
	return *this;
}
/*String& String::operator= (const char* s)
{
	String rs(s);
	delete []sPtr;
	size = rs.size;
	capacity = rs.capacity;
	sPtr = new char[capacity];
	for (size_t i = 0; i < size; i++)
	{
		sPtr[i] = rs.sPtr[i];
	}
	return *this;
}*/
bool String::operator==(const String &str)
{
	if (size == str.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (sPtr[i] != str.sPtr[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
bool String::operator!=(const String &str)
{
	return !(*this == str);
}