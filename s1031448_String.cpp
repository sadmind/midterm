#include <iostream>
#include "s1031448_String.h" 
using namespace std;

String::String()
{
	size_t size = 0;
	size_t capacity = 10;
}
String::String(const String &str)
{
	for (int i = 0; i < size; i++)
		sPtr[i] = str.sPtr[i];
}
String::String(const String& str, size_t pos, size_t len = npos)
{
	for (int i = 0; i < size; i++){
		sPtr[i] = str.sPtr[i];
		sPtr[i]= pos;
	}
}
String::String(const char *s)
{

}
String::~String()
{
	delete[] sPtr;
}

char* begin(); 

char* end();


size_t getSize()
{
	size_t size =size;
	return size;
}
void resize(size_t n)
{
}
void resize(size_t n, char c)
{
}
size_t getCapacity() 
{
	size_t capacity = capacity;
	return capacity;
}

void reserve(size_t n = 0);

void shrink_to_fit(); 

void clear()
{
	
}

bool empty()
{
	if (size_t size= 0)
		true;
	else
		false;
}
char& front()
{
	string *sPtr = &sPtr[0];
}
char& back()
{
	string *sPtr = &sPtr[SIZE_MAX];
}

void push_back(char c)
{
	string *sPtr = &sPtr[c+1];
}

void pop_back()
{
	string *sPtr = &sPtr[c + 1];
}

/*
String& append(const String &str)
{
	.append(str);
}


String& substr(size_t pos = 0, size_t len = npos) const;

String& insert(size_t pos, const String &str);


String& insert(size_t pos, const String &str, size_t subpos, size_t sublen);


String& erase(size_t subpos, size_t sublen);


size_t find(const String &str, size_t pos = 0) const
{
	str.find(str);
}

size_t find_first_of(const String str, size_t pos = 0) const
{
	str.find_first_of(str.substr(10, 4));
}

char& operator[] (size_t pos)

const char& operator[] (size_t pos) const;

String operator+ (const String& rhs)
{
	
}
String operator+ (const char* rhs)
{
}
*/