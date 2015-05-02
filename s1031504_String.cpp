#include<iostream>
using namespace std;
#include "s1031504_String.h"

ostream &operator<<(ostream& output, const String& str)
{
	for (unsigned int i = 0; i < str.size; i++)
	{
		output << str.sPtr[i];
	}
	return output;
}

String::String()
{
	size = 0;
	capacity = 10;
	sPtr = NULL;
}
String::String(const String &str)
{
	size = str.size;
	capacity = str.capacity;

	sPtr = new char[size];
	for (unsigned int i = 0; i < size; i++)
	{
		sPtr[i] = str.sPtr[i];
	}
}
String::String(const String& str, size_t pos, size_t len )
{
	size = str.size;
	size = str.size;
	capacity = str.capacity;

	sPtr = new char[size];
	for (unsigned int i = 0; i < size; i++)
	{
		sPtr[i] = str.sPtr[i];
	}
}
String::String(const char *s)
{
	size = strlen(s);
	capacity = 10;
	sPtr = new char[size];
	for (unsigned int i = 0; i < size; i++)
	{
		sPtr[i] = s[i];
	}

}
String::~String()
{
	delete sPtr;
}
char* String::begin()
{
	return sPtr;
}
char* String::end()
{
	return (sPtr + size-1);
}
size_t String::getSize() const
{
	return size;
}

void String::resize(size_t n)
{
	String temp;
	temp = *this;
	delete sPtr;
	sPtr = new char[n];
	size = n;
	capacity = n;
	
}
void String::resize(size_t n, char c)
{
	String temp;
	temp = *this;
	delete sPtr;
	sPtr = new char[n];
	size = n;
	capacity = n;
	for (unsigned int i = 0; i < temp.size; i++)
	{
		sPtr[i] = temp.sPtr[i];
	}
	for (unsigned int i = temp.size; i < size; i++)
	{
		sPtr[i] = c;
	}
}
size_t String::getCapacity() const
{
	return capacity;

}
void String::reserve(size_t n )
{
	capacity = n;

}
void String::shrink_to_fit()
{
	capacity = size;
}
void String::clear()
{
	size = 0;
	capacity = 10;
}
bool String::empty() const
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

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
	String temp;
	temp = *this;
	delete sPtr;
	size += 1;
	sPtr = new char[size];
	
	for (unsigned int i = 0; i < size - 1; i++)
	{
		sPtr[i] = temp.sPtr[i];
	}
	sPtr[size - 1] = c;

}
void String::pop_back()
{
	String temp;
	temp = *this;
	delete sPtr;
	size -= 1;
	sPtr = new char[size];

	for (unsigned int i = 0; i < size; i++)
	{
		sPtr[i] = temp.sPtr[i];
	}
}

String& String::append(const String &str)
{
	unsigned int sumsize = size + str.size;
	String temp;
	temp = *this;
	delete sPtr;
	sPtr = new char[sumsize];
	if (sumsize > 10)
	{
		capacity = sumsize;
	}
	size = sumsize;
	
	for (unsigned int i = 0; i < temp.size; i++)
	{
		sPtr[i] = temp.sPtr[i];
	}
	for (unsigned int i = temp.size, j = 0; i < sumsize, j < str.size; i++, j++)
	{
		sPtr[i] = str.sPtr[j];
	}
	return *this;
}

String& String::substr(size_t pos, size_t len) const
{
	String temp;
	temp.size = len;
	if (temp.size > 10)
	{
		temp.capacity = temp.size;
	}
	else
	{
		temp.capacity = 10;
	}
	temp.sPtr = new char[temp.size];

	for (unsigned int i = 0, j = pos; i < temp.size, j < pos + len; i++, j++)
	{
		temp.sPtr[i] = sPtr[j];
	}
	return temp;
}
String& String::insert(size_t pos, const String &str)
{
	String temp;
	temp = *this;
	size += str.size;
	if (size > 10)
	{
		capacity = size;
	}
	delete sPtr;
	sPtr = new char[size];

	for (unsigned int i = 0; i < pos; i++)
	{
		sPtr[i] = temp.sPtr[i];
	}
	for (unsigned int i = pos, j = 0; i < pos + str.size, j < str.size; i++, j++)
	{
		sPtr[i] = str.sPtr[j];
	}
	for (unsigned int i = pos + str.size, j = pos; i < size, j < temp.size; i++, j++)
	{
		sPtr[i] = temp.sPtr[j];
	}
	return *this;

}

String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen)
{
	String temp;
	temp = *this;
	size += sublen;
	if (size > 10)
	{
		capacity = size;
	}
	delete sPtr;
	sPtr = new char[size];

	for (unsigned int i = 0; i < pos; i++)
	{
		sPtr[i] = temp.sPtr[i];
	}
	for (unsigned int i = pos, j = subpos; i < pos + sublen, j < subpos + sublen; i++, j++)
	{
		sPtr[i] = str.sPtr[j];
	}
	for (unsigned int i = pos + sublen, j = pos; i < size, j < temp.size; i++, j++)
	{
		sPtr[i] = temp.sPtr[j];
	}
	return *this;

}

String& String::erase(size_t subpos, size_t sublen)
{
	String temp;
	temp = *this;
	size -= sublen;
	if (size > 10)
	{
		capacity = size;
	}
	delete sPtr;
	sPtr = new char[size];

	for (unsigned int i = 0; i < subpos; i++)
	{
		sPtr[i] = temp.sPtr[i];
	}
	for (unsigned int i = subpos, j = subpos + sublen; i < size, j < temp.size; i++, j++)
	{
		sPtr[i] = temp.sPtr[j];
	}
	return *this;
}

size_t String::find(const String &str, size_t pos ) const
{
	int count = 0;
	size_t i;
	for (i = pos; i < size; i++)
	{
		if (sPtr[i] == str.sPtr[i])
			count++;
		else
			count = 0;
		if (count == str.size)
			return i;
	}

}
size_t String::find_first_of(const String str, size_t pos) const
{
	size_t i;
	for (i = pos; i < size; i++)
	{
		if (sPtr[i] == str.sPtr[0])
			return i;
	}
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
/*	int sumsize = size + rhs.size;
	String temp;
	temp = *this;
	delete sPtr;
	sPtr = new char[sumsize];
	size = sumsize;
	capacity = capacity + rhs.capacity;
	for (unsigned int i = 0; i < temp.size; i++)
	{
		sPtr[i] = temp.sPtr[i];
	}
	for (int i = temp.size; i < sumsize; i++)
	{
		sPtr[i] = rhs.sPtr[i];
	}
	return *this;*/

	String store;
	store.size = size + rhs.size;
	store.capacity = capacity + rhs.capacity;
	store.sPtr = new char[store.size];
	for (unsigned int i = 0; i < size; i++)
	{
		store.sPtr[i] = sPtr[i];
	}
	for (unsigned int i = size, j = 0; i < store.size, j < rhs.size; i++, j++)
	{
		store.sPtr[i] = rhs.sPtr[j];
	}

	return store;

}
String String::operator+ (const char*   rhs)
{
	/*int sumsize = size + strlen(rhs);
	
	String temp;
	temp = *this;
	delete sPtr;
	size = sumsize;
	capacity += 10;

	sPtr = new char[sumsize];
	for (unsigned int i = 0; i < temp.size; i++)
	{
		sPtr[i] = temp.sPtr[i];
	}
	for (int i = temp.size; i < sumsize; i++)
	{
		sPtr[i] = rhs[i];
	}

	return *this;*/
	String store;
	store.size = size + strlen(rhs);
	store.capacity = capacity + 10;
	store.sPtr = new char[store.size];
	for (unsigned int i = 0; i < size; i++)
	{
		store.sPtr[i] = sPtr[i];
	}
	for (unsigned int i = size, j = 0; i < store.size, j < strlen(rhs); i++, j++)
	{
		store.sPtr[i] = rhs[j];
	}
	return store;
}

String& String::operator= (const String& str)
{
	size = str.size;
	capacity = str.capacity;
	sPtr = new char[size];
	for (unsigned int i = 0; i < size; i++)
	{
		sPtr[i] = str.sPtr[i];
	}
	return *this;
}
String& String::operator= (const char* s)
{
	size = strlen(s);
	capacity = 10;
	sPtr = new char[size];
	for (unsigned int i = 0; i < size; i++)
	{
		sPtr[i] = s[i];
	}
	return *this;
}

bool String::operator==(const String &str)
{
	if (size != str.size)
		return false;
	int check = 0;
	for (unsigned int i = 0; i < size; i++)
	{
		if (sPtr[i] == str.sPtr[i])
			check++;
	}
	if (check == str.size)
		return true;
	else
		return false;
}

bool String::operator!=(const String &str)
{
	return !(*this == str);
}