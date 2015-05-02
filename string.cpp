#include<iostream>
#include"s1031546_String.h"

using namespace std;

ostream &operator<<(ostream& output, const String& str)
{
	for (int i = 0; i < str.size - '0'; i++)
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
	String t = str;
}

/*String::String(const String& str, size_t pos, size_t len = npos)
{
	for (int i = 0; str[i] != NULL; i++)
		size = i;
	size = size + 1;
	if (size > capacity)
		capacity = size;
	sPtr = new char[size];
	for (int i = 0; i < size - '0'; i++)
		sPtr[i] = str[i];
}*/

String::String(const char *s)
{
	for (int i = 0; s[i] != NULL; i++)
		size = i;
	size = size + 1;
	if (size > capacity)
		capacity = size;
	sPtr = new char[size];
	for (int i = 0; i < size - '0'; i++)
		sPtr[i] = s[i];

}

/*String::~String()
{

}

char* String::begin()
{

}

char* String::end()
{

}

size_t String::getSize() const
{

}

void String::resize(size_t n, char c)
{

}

size_t String::getCapacity() const
{

}

/*void String::reserve(size_t n = 0)
{

}*/

void String::shrink_to_fit()
{

}

void String::clear()
{
	size = 0;
	capacity = 10;
}

bool String::empty() const
{
	if (size != 0)
		return false;
	else
		return true;
}

/*char& String::front()
{
	
}

char& String::back()
{

}*/

void String::push_back(char c)
{	
	String t;
	t.size = size + 1;
	t.sPtr = new char[t.size];
	for (int i = 0; i < size - '0'; i++)
	{
		t.sPtr[i] = sPtr[i];
	}
	size = size + 1;
	sPtr = new char[size];
	for (int i = 0; i < t.size; i++)
	{
		sPtr[i] = t.sPtr[i];
	}
	sPtr[size - 1] = c;

}

void String::pop_back()
{
	String t;
	t.size = size - 1;
	t.sPtr = new char[t.size];
	for (int i = 0; i < t.size - '0'; i++)
	{
		t.sPtr[i] = sPtr[i];
	}
	size = size - 1;
	sPtr = new char[size];
	for (int i = 0; i < t.size; i++)
	{
		sPtr[i] = t.sPtr[i];
	}
}

/*String& String::append(const String &str)
{

}*/

//String& String::substr(size_t pos = 0, size_t len = npos) const
//{

//}

/*String& String::insert(size_t pos, const String &str)
{

}

String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen)
{

}

String& String::erase(size_t subpos, size_t sublen)
{

}*/

/*size_t String::find(const String &str, size_t pos = 0) const
{

}*/

/*size_t String::find_first_of(const String str, size_t pos = 0) const
{

}*/

/*char& String::operator[] (size_t pos)
{

}*/

/*const char& String::operator[] (size_t pos) const
{

}*/

String String::operator+ (const String& rhs)
{
	String t;
	t.size = size + rhs.size;
	t.sPtr = new char[t.size];
	t.capacity = t.size;
	for (int i = 0; i < size - '0'; i++)
	{
		t.sPtr[i] = sPtr[i];
	}
	for (int i = size; i < t.size - '0'; i++)
	{
		t.sPtr[i] = rhs.sPtr[i - size];
	}
	return t;
}

String String::operator+ (const char*   rhs)
{
	String t;
	for (int i = 0; rhs[i] != NULL; i++)
		size = size+i;
	size = size + 1;
	t.size = size;
	t.sPtr = new char[t.size];
	for (int i = 0; i < size; i++)
	{
		t.sPtr[i] = sPtr[i];
	}
	for (int i = size; i < t.size; i++)
	{
		t.sPtr[i] = rhs[i - size];
	}
	return t;
}

String& String::operator= (const String& str)
{
	String t;
	t.size = str.size;
	t.capacity = str.capacity;
	t.sPtr = new char[t.size];
	for (int i = 0; i < t.size - '0'; i++)
		t.sPtr[i] = str.sPtr[i];
	return t;
}

String& String::operator= (const char* s)
{
	String t;
	for (int i = 0; s[i] != NULL; i++)
		size = size+i;
	size = size + 1;
	t.size = size;
	t.sPtr = new char[t.size];
	if (size > capacity)
		t.capacity = size;
	for (int i = 0; i < size - '0'; i++)
		t.sPtr[i] = s[i];
	return t;
}

bool String::operator==(const String &str)
{
	if (size != str.size)
		return false;
	else
	{
		for (int i = 0; i < size - '0'; i++)
		{
			if (sPtr[i] != str.sPtr[i])
				return false;
		}
		return true;
	}
}

bool String::operator!=(const String &str)
{
	if (size == str.size)
	{
		for (int i = 0; i < size - '0'; i++)
		{
			if (sPtr[i] != str.sPtr[i])
				return true;
		}
		return false;
	}
	else
		return true;
}