
#include <iostream>
#include "s1033310_string.h"
using namespace std;

ostream &operator<<(ostream& output, const String& str)
{
	int i = str.size;
	int j = 0;
	while (i--)
		output << str.sPtr[j++];
	return output;
}

static const size_t npos = -1;

String::String()
{
	sPtr = new char[10];
	size = 0;
	capacity = 10;
}
String::String(const String &str)
{
	int tmp;
	if (str.size > 10)
		tmp = str.size;
	else
		tmp = 10;
	sPtr = new char[tmp];
	size = str.size;
	capacity = str.getCapacity();
	for (int i = 0; i < size; i++)
		sPtr[i] = str.sPtr[i];
}
String::String(const String& str, size_t pos, size_t len)
{
	size = len;
	sPtr = new char[len];
	len >= 10 ? capacity = len : capacity = 10;
	for (int i = 0; i < len; i++)
		sPtr[i] = str.sPtr[pos + i];
}
String::String(const char *s)
{
	size = 0;
	int j = 0;
	while (s)
	{
		if (s[j] == '\0')
			break;
		size++;
		j++;
	}
	sPtr = new char[size];
	for (int i = 0; i < size; i++)
		sPtr[i] = s[i];
	size >= 10 ? capacity = size : capacity = 10;
}

String::~String()
{
	delete[] sPtr;
}
char* String::begin()
{
	return sPtr;
}

char* String::end()
{
	return sPtr+size;
}

size_t String::getSize() const
{
	return size;
}

void String::resize(size_t n)
{
	if (n <= 0)
		return;
	int s = size;
	int k = n;
	if (size > n)
		k = size;
	if (s < 10)
		s = 10;
	char* tmp = new char[s];
	for (int i = 0; i < size; i++)
		tmp[i] = sPtr[i];
	delete[] sPtr;
	int tttt;
	if (n < 10)
		tttt = 10;
	else
		tttt = n;
	sPtr = new char[tttt];
	for (int i = 0; i < size; i++)
		sPtr[i] = tmp[i];
	capacity < n ? capacity = size : capacity = capacity;
}
void String::resize(size_t n, char c)
{
	if (n <= 0)
		return;
	int k = n;
	if (size > n)
		k = size;
	char* tmp = new char[n];
	for (int i = 0; i < k; i++)
		tmp[i] = sPtr[i];
	delete[] sPtr;
	sPtr = new char[n];
	for (int i = 0; i < size; i++)
		sPtr[i] = tmp[i];
	for (int i = size; i < n; i++)
		sPtr[i] = c;
	size = n;
	capacity = n;
}

size_t String::getCapacity() const
{
	return capacity;
}

void String::reserve(size_t n)
{
	if (n <= size)
		return;
	else
		resize(n);
}

void String::shrink_to_fit()
{
	if (size < capacity)
		resize(size);
}

void String::clear()
{
	delete[] sPtr;
	sPtr = new char[10];
	size = 0;
	capacity = 10;
}

bool String::empty() const
{
	if (size == 0)
		return true;
	else
		return false;
}

char& String::front()
{
	return sPtr[0];
}

char& String::back()
{
	return sPtr[size-1];
}

void String::push_back(char c)
{
	resize(size + 1);
	sPtr[size] = c;
	size++;
}
void String::pop_back()
{
	
	resize(size - 1);
	size--;
}

String& String::append(const String &str)
{
	resize(size + str.size);
	for (int i = 0; i < str.size; i++)
		sPtr[size + i] = str.sPtr[i];
	size = size + str.size;
	return *this;
}

String& String::substr(size_t pos, size_t len) const
{
	String tmp;
	tmp.resize(len);
	for (int i = 0; i < len; i++)
		tmp.sPtr[i] = sPtr[pos + i];
	tmp.size = len;
	return tmp;
}

String& String::insert(size_t pos, const String &str)
{
	if (pos > size)
		return *this;
	String tmp(*this);
	resize(size + str.size);
	int i = 0;
	size += str.size;
	for (; i < str.size; i++)
		sPtr[pos+i] = str[i];
	for (int j = pos; j < size-str.size; j++)
		sPtr[i + j] = tmp[j];
	return *this;
}

String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen)
{
	String tmp(str.substr(subpos, sublen));
	insert(pos , tmp);
	return *this;
}

String& String::erase(size_t subpos, size_t sublen)
{
	int p = subpos, l = sublen, s = size;
	if (l + p > s  || sublen == npos)
	{
		int k = size;
		while (k != l)
		{
			pop_back();
			k--;
		}
		return *this;
	}

	String tmp(*this);
	resize(s - l);
	for (int i = subpos; i < size; i++)
		sPtr[i] = tmp.sPtr[i + sublen];
	size -= sublen;
	return *this;
}

size_t String::find(const String &str, size_t pos) const
{
	for (int i = pos; i < (size - str.size); i++)
	{
		if (sPtr[i] == sPtr[0])
		{
			bool flag = 0;
			for (int j = 0; j < str.size; j++){
				if (sPtr[i + j] != sPtr[j])
				{
					break;
					flag = 1;
				}
			}
			if (flag)
				return i;

		}
	}
	return npos;
}

size_t String::find_first_of(const String str, size_t pos) const
{
	for (int i = pos; i < (size - str.size); i++)
	{
		for (int j = 0; j < str.size;j++)
		if (sPtr[i] == str.sPtr[j])
			return i;
	}
	return npos;
}

char& String::operator[](size_t pos)
{
	if (pos > size)
		return sPtr[0];
	else
		return sPtr[pos];
}
const char& String::operator[] (size_t pos) const
{
	if (pos > size)
		return 0;
	else
		return sPtr[pos];
}

String& String::operator=(const String& str)
{
	resize(str.size);
	for (int i = 0; i < size; i++)
		sPtr[i] = str.sPtr[i];
	//size = str.size;
	return *this;
}
String& String::operator=(const char* s)
{
	String tmp(s);
	cout << tmp << endl;
	*this = tmp;
	return *this;
}

bool String::operator==(const String &Str)
{
	if (find(Str) != npos)
		return true;
	else
		return false;
}

bool String:: operator!=(const String &Str)
{
	return (*this == Str);
}

String String::operator+(const String& rhs)
{
	String tmp(*this);
	return tmp.append(rhs);
}
String String::operator+(const char*   rhs)
{
	String tmp(*this);
	String ttmp(rhs);
	return tmp.append(ttmp);
}