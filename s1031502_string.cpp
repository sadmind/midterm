#include "s1031502_string.h"
#include <iostream>
using namespace std;

ostream &operator << (ostream& output, const String& str)
{
	for (size_t i = 0; i < str.getSize(); i++)
	{
		output << str.sPtr[i];
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
	for (size_t i = 0; i < size; i++)
	{
		sPtr[i] = str.sPtr[i];
	}
}

String::String(const String& str, size_t pos, size_t len)
{
	if (pos+len<=size && str.size!=0)
	{
		for (size_t i = 0; i < len; i++)
		{
			str.sPtr[i] = sPtr[pos + i];
		}
		size = len;
	}
}

String::String(const char *s)
{
	size = strlen(s);
	sPtr = new char[size];
	for (size_t i = 0; i < size; i++)
		sPtr[i] = s[i];
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

void String::resize(size_t n)
{
	if (n <= size)
	{
		char* temp = new char[size];//暫存
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = sPtr[i];
		}
		delete[] sPtr;
		
		sPtr = new char[n];
		for (size_t i = 0; i < n; i++)
		{
			sPtr[i] = temp[i];
		}
		size = n;
	}
	else
	{
		char* temp = new char[size];//暫存
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = sPtr[i];
		}
		delete[] sPtr;

		sPtr = new char[n];
		for (size_t i = 0; i < size; i++)
		{
			sPtr[i] = temp[i];
		}
		for (size_t i = size; i < n; i++)
		{
			sPtr[i] = '\0';
		}
		size = n;
	}
	if (capacity < n)
		capacity = n;
}

void String::resize(size_t n, char c)
{
	if (n <= size)
	{
		char* temp = new char[size];//暫存
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = sPtr[i];
		}
		delete[] sPtr;

		sPtr = new char[n];
		for (size_t i = 0; i < n; i++)
		{
			sPtr[i] = temp[i];
		}
		size = n;
	}
	else
	{
		char* temp = new char[size];//暫存
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = sPtr[i];
		}
		delete[] sPtr;

		sPtr = new char[n];
		for (size_t i = 0; i < size; i++)
		{
			sPtr[i] = temp[i];
		}
		for (size_t i = size; i < n; i++)
		{
			sPtr[i] = c;
		}
		size = n;
	}
	if (capacity < n)
		capacity = n;
}

size_t String::getCapacity() const
{
	return capacity;
}

void String::reserve(size_t n)
{
	if (n > capacity)
		capacity = n;
}

void String::shrink_to_fit()
{
	if (capacity != size)
		capacity = size;
}

void String::clear()
{
	size = 0;

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
	return sPtr[size - 1];
}

void String::push_back(char c)
{
	char* temp = new char[size];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = sPtr[i];
	}
	delete[] sPtr;
	size += 1;
	sPtr = new char[size];
	for (size_t i = 0; i < size - 1; i++)
	{
		sPtr[i] = temp[i];
	}
	sPtr[size - 1] = c;
}

void String::pop_back()
{
	char* temp = new char[size];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = sPtr[i];
	}
	delete[] sPtr;
	size -= 1;
	sPtr = new char[size];
	for (size_t i = 0; i < size; i++)
	{
		sPtr[i] = temp[i];
	}
}

String& String::append(const String &str)
{
	char* temp = new char[size];//暫存
	size_t A = size;
	for (size_t i = 0; i < size;i++)
	{
		temp[i] = sPtr[i];
	}

	size += str.size;
	delete [] sPtr;

	sPtr = new char[size];
	for (size_t i = 0; i < A; i++)
	{
		sPtr[i] = temp[i];
	}
	int a = 0;
	for (size_t i = A; i < size; i++)
	{
		sPtr[i] = str.sPtr[a];
		a++;
	}
	return *this;
}


String& String::substr(size_t pos, size_t len) const
{
	String sub;
	sub.size = len;
	sub.sPtr = new char[len];
	for (size_t i = 0; i < len; i++)
	{
		sub.sPtr[i] = sPtr[pos + i];
	}
	return sub;

}

String& String::insert(size_t pos, const String &str)
{
	char* temp = new char[pos];
	char *temp2 = new char[size - pos];
	for (size_t i = 0; i < pos; i++)
		temp[i] = sPtr[i];
	for (size_t i = 0; i < size - pos; i++)
		temp2[i] = sPtr[pos + i];
	int temp2size = size - pos;
	delete[] sPtr;

	size += str.size;
	sPtr = new char[size];
	for (size_t i = 0; i < pos; i++)
		sPtr[i] = temp[i];

	for (size_t i = 0; i < str.size; i++)
		sPtr[pos + i] = str.sPtr[i];

	for (size_t i = 0; i < temp2size; i++)
		sPtr[pos + str.size + i] = temp2[i];

	return *this;
}

String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen)
{
	char* temp = new char[pos];
	char *temp2 = new char[size - pos];
	for (size_t i = 0; i < pos; i++)
		temp[i] = sPtr[i];
	for (size_t i = 0; i < size - pos; i++)
		temp2[i] = sPtr[pos + i];
	int temp2size = size - pos;
	delete[] sPtr;

	size += sublen;
	sPtr = new char[size];
	for (size_t i = 0; i < pos; i++)
		sPtr[i] = temp[i];
	for (size_t i = 0; i < sublen; i++)
		sPtr[pos + i] = str.sPtr[subpos+i];
	for (size_t i = 0; i < temp2size; i++)
		sPtr[pos + sublen+ i] = temp2[i];

	return *this;
}

String& String::erase(size_t subpos, size_t sublen)
{
	if (size > 0 && subpos + sublen <= size)
	{
		int i = 0;
		for (size_t a = subpos; a < size; a++)
		{
			sPtr[subpos+i] = sPtr[i+sublen + subpos];
			i++;
		}
		size -= sublen;
		return *this;
	}
	else
	{
		size = 0;
		return *this;
	}

}

size_t String::find(const String &str, size_t pos) const
{
	bool check=true;
	if (pos <= str.size)
	{
		for (size_t i = pos; i < size - str.size; i++)
		{
			for (size_t j = 0; j < str.size; j++)
			{
				if (sPtr[i + j] != str.sPtr[i + j])
					check = false;
			}
			if (check == false)
				return String::npos;
			else
				return i;
		}
	}
	else
		return String::npos;
}

size_t String::find_first_of(const String str, size_t pos) const
{
	if (pos <= str.size)
	{
		for (size_t i = pos; i < size; i++)
		{
			for (size_t j = 0; j < str.size; j++)
			{
				if (sPtr[i] == str.sPtr[j])
					return i;
			}
		}
		return String::npos;

	}
	else
		return String::npos;
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
	size_t length = size + rhs.size;
	String temp;
	temp.sPtr = new char[length];//暫存
	temp.size = length;
	size_t A = size;
	for (size_t i = 0; i < size; i++)
	{
		temp.sPtr[i] = sPtr[i];
	}

	int a = 0;
	for (size_t i = A; i < length; i++)
	{
		temp.sPtr[i] = rhs.sPtr[a];
		a++;
	}
	return temp;
}

String String::operator+ (const char* rhs)
{
	size_t length = size + strlen(rhs);
	String temp;
	temp.sPtr = new char[length];//暫存
	temp.size = length;
	size_t A = size;
	for (size_t i = 0; i < size; i++)
	{
		temp.sPtr[i] = sPtr[i];
	}

	int a = 0;
	for (size_t i = A; i < length; i++)
	{
		temp.sPtr[i] = rhs[a];
		a++;
	}
	return temp;
}

String& String::operator= (const String& str)
{
	if (size > str.size || size<str.size)
	{
		delete[] sPtr;
		sPtr = new char[str.size];
	}
	size = str.size;
	capacity = str.capacity;
	for (size_t i = 0; i < size; i++)
		sPtr[i] = str.sPtr[i];

	return *this;
}

String& String::operator= (const char* s)
{
	if (size>strlen(s) || size < strlen(s))
	{
		delete[] sPtr;
		sPtr = new char[strlen(s)];
	}
	size = strlen(s);
	for (size_t i = 0; i < size; i++)
		sPtr[i] = s[i];
	return *this;
}

bool String::operator==(const String &str)
{
	if (size == str.size)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (sPtr[i] != str.sPtr[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

bool String::operator!=(const String &str)
{
	return !(*this == str);
}