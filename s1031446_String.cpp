#include <iostream>efini
#include "s1031446_String.h" 

using namespace std;

String::String()
{

}

String::String(const String &str)
{

}

String::String(const String& str, size_t pos, size_t len = npos)
{

}

String::String(const char *s)
{

}

String::~String()
{

}

char String::* begin()
{

}

char String::* end()
{

}

size_t String::getSize() const
{

}

void resize(size_t n)
{

}

void resize(size_t n, char c)
{

}

size_t String::getCapacity() const
{

}

void reserve(size_t n = 0)
{

}

void clear()
{

}

bool String::empty() const
{

}

char &String:: front()
{

}

char& String::back()
{

}

void push_back(char c)
{

}

void pop_back()
{

}

void shrink_to_fit()
{

}

String& String::append(const String &str)
{

}

String& String::substr(size_t pos = 0, size_t len = npos) const
{

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

}

const char& String::operator[] (size_t pos) const
{

}

String String::operator+ (const String& rhs)
{

}

String String::operator+ (const char*   rhs)
{

}

String& String::operator= (const String& str)
{

}

String& String::operator= (const char* s)
{

}

bool String::operator==(const String &str)
{

}

bool String::operator!=(const String &str)
{

}
