#include <iostream>
using namespace std;
#include "s1033344_String.h"

const size_t npos = -1;
ostream &operator<<(ostream& output, const String& str)
{
	for (int i = 0; i < str.size; i++)
	{
		output << str.sPtr[i];
	}
	return output;
}

String::String()
{
	capacity = 10;
	size = 0;	
	sPtr = new char[capacity];
	for (int i = 0; i < capacity; i++)
	{
		sPtr[i] = '0';
	}
}
String::String(const String &str)
{
	capacity = str.getSize();
	size = str.getSize();
	sPtr = new char[capacity];
	for (int i = 0; i < size; i++)
	{
		sPtr[i] = str.sPtr[i];
	}
}
String::String(const String& str, size_t pos, size_t len)
{
	capacity = len;
	size = len;
	sPtr = new char[capacity];
	for (int i = pos - 1; i <= len; i++)
	{
		sPtr[i] = str.sPtr[i];
	}
}
String::String(const char *s)
{
	int tmpSize = 1;
	while (s[tmpSize] != NULL)
	{
		tmpSize++;
	}
	capacity = tmpSize;
	size = tmpSize;
	sPtr = new char[capacity];
	for (int i = 0; i < size; i++)
	{
		sPtr[i] = s[i];
	}
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
	return &sPtr[size-1];
}
size_t String::getSize() const
{
	return size;
}
void String::resize(size_t n)
{
	int tmpSize = 1;
	while (sPtr[tmpSize] != NULL)
	{
		tmpSize++;
	}	
}
void String::resize(size_t n, char c)
{
	int tmpSize = 1;
	while (sPtr[tmpSize] != NULL)
	{
		tmpSize++;
	}
}
size_t String::getCapacity() const
{
	return capacity;
}
void String::reserve(size_t n)
{
	int tmpSize = 1;
	while (sPtr[tmpSize] != NULL)
	{
		tmpSize++;
	}
}
/*void String::shrink_to_fit()
{

}
void String::clear()
{

}
bool String::empty() const
{

}
char& String::front()
{

}
char& String::back()
{

}
*/void String::push_back(char c)
{
	char *tmpArray = new char[size];
	for (int i = 0; i < size; i++)
	{
		tmpArray[i] = sPtr[i];
	}
	delete[]sPtr;
	capacity += 1;
	size += 1;
	sPtr = new char[capacity];
	for (int i = 0; i < size - 1; i++)
	{
		sPtr[i] = tmpArray[i];
	}
	sPtr[size - 1] = c;
}
void String::pop_back()
{
	char *tmpArray = new char[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		tmpArray[i] = sPtr[i];
	}
	delete[]sPtr;
	capacity -= 1;
	size -= 1;
	sPtr = new char[capacity];
	for (int i = 0; i < size; i++)
	{
		sPtr[i] = tmpArray[i];
	}
}
String& String::append(const String &str)
{
	char *tmpArray = new char[size];
	for (int i = 0; i < size; i++)
	{
		tmpArray[i] = sPtr[i];
	}
	size_t preSize = size;
	delete[]sPtr;
	capacity += str.capacity;
	size += str.size;
	sPtr = new char[capacity];
	for (int i = 0; i < preSize; i++)
	{
		sPtr[i] = tmpArray[i];
	}
	for (int i = preSize, j = 0; j < str.size; i++, j++)
	{
		sPtr[i] = str.sPtr[j];
	}
	return *this;
}
/*String& String::substr(size_t pos, size_t len) const
{
	char *tmpArray1 = new char[pos];
	for (int i = 0; i < pos; i++)
	{
		sPtr[i] = tmpArray1[i];
	}
	char *tmpArray2 = new char[size - pos + len - 1];
	for (int i = pos + len - 2; i <= len; i++)
	{
		sPtr[i] = tmpArray2[i];
	}
	delete[] sPtr;
	
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

}
char& String::operator[] (size_t pos)
{

}*/
String String::operator+ (const String& rhs)
{
	String tmpArray;
	tmpArray.capacity = capacity + rhs.size;
	tmpArray.size = size + rhs.size;
	tmpArray.sPtr = new char[tmpArray.size];
	for (int i = 0; i < size; i++)
	{
		tmpArray.sPtr[i] = sPtr[i];
	}
	for (int i = size, j = 0; j < rhs.size; i++, j++)
	{
		tmpArray.sPtr[i] = rhs.sPtr[j];
	}
	return tmpArray;
}
String String::operator+ (const char*   rhs)
{
	int tmpSize = 1;
	while (rhs[tmpSize] != NULL)
	{
		tmpSize++;
	}
	
	String tmpArray;
	tmpArray.capacity = capacity + tmpSize;
	tmpArray.size = size + tmpSize;	
	tmpArray.sPtr = new char[tmpArray.size];
	for (int i = 0; i < size; i++)
	{
		tmpArray.sPtr[i] = sPtr[i];
	}
	for (int i = size, j = 0; j < tmpSize; i++, j++)
	{
		tmpArray.sPtr[i] = rhs[j];
	}
	return tmpArray;
}
String& String::operator= (const String& str)
{
	capacity = str.getSize();
	size = str.getSize();
	for (int i = 0; i < size; i++)
	{
		sPtr[i] = str.sPtr[i];
	}
	return *this;
}
String& String::operator= (const char* s)
{
	int tmpSize = 1;
	while (s[tmpSize] != NULL)
	{
		tmpSize++;
	}
	capacity = tmpSize;
	size = tmpSize;
	for (int i = 0; i < size; i++)
	{
		sPtr[i] = s[i];
	}
	return *this;
}
/*bool String::operator==(const String &str)
{

}
bool String::operator!=(const String &str)
{

}*/
