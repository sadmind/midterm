#include <iostream>
#include <string>
#include "s1033354_String.h"
using namespace std;




String::String()
{
	
	sPtr=  new char [size];
	unsigned int size = 0;
	
}

String::String(const String &str)
{
	for (int i = 0; i <= size; i++)
		sPtr[i] = str[i];

}

/*
String::String(const String& str, size_t pos, size_t len = npos)
{
	for (int i = 0; i <= size; i++)
		sPtr[i] = str[i];
	size =len;
	capacity = size + 1;
	
}*/
String::String(const char *s)
{
	for (int i = 0; i <= size;i++)
	if (sPtr[i] == 's')
	{
		int x;
		x =size-i;
		size = x;

	}
	else;
	size = NULL;
	sPtr = { 0 };
	
}

char * String::begin()
{
	return &sPtr[0];
}

char * String::end()
{
	return &sPtr[size - 1];
}

size_t String::getSize() const
{
	return size;
}

/*
void String::resize(size_t n)
{
	if (size<n)



}

void String::resize(size_t n, char c)
{

}
*/

size_t String::getCapacity() const
{
	return capacity;
}
/*
void String::reserve(size_t n = 0)
{
	if (n>capacity)
		capacity = n;
}
*/
void String::shrink_to_fit()
{
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
	if (size != 0)
		return sPtr[0];
}

char& String::back()
{
	if (size != 0)
		return sPtr[size];
}


void String::push_back(char c)
{
	size++;
	sPtr[size - 1] = c;

}


void String::pop_back()
{
	size--;
	sPtr[size] = 0;

}


String& String::append(const String &str)
{

	size=size+str.size ;
	for (int i = 0; i <=str.size; i++)
	{
		sPtr[size + i] = str[i];

	}
	return *this;
}
/*
String& String::substr(size_t pos = 0, size_t len = npos) const
{
	int x;
	int y;
	y= size - len ;
	
	for (int i = len; i <= size;i++)
		sPtr[i] = {0};
	for (int i = 0; i <=len; i++)
	{
		x = sPtr[pos+i];
		sPtr[i] = x;
		
			
	}

	}
	*/

String& String::insert(size_t pos, const String &str)
{
	int x;
	x = size + str.size;
	size = x;

	for (int i = pos+1; i <= str.size; i++)
	{
		sPtr[i + str.size] = sPtr[i] = {0};
	}

	for (int i = 0; i <= str.size; i++)
	{
		sPtr[pos + i] = str[i];

	}

	return *this;

}


String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen)
{
	int x;
	x = size + sublen;
	size = x;

	for (int i = pos + 1; i <= str.size; i++)
	{
		sPtr[i + sublen] = sPtr[i] = { 0 };
	}


	for (int i = 0; i <= sublen; i++)
	{
		sPtr[pos + i] = str[subpos+i];

	}


	return *this;



}


String& String::erase(size_t subpos, size_t sublen)
{
	int x;
	x = size - sublen;
	size = x;

	for (int i = subpos+1; i <= sublen; i++)
	{
		sPtr[i] = { 0 };
	}

	for (int i = subpos+1; i <= sublen; i++)
	{
		sPtr[i + sublen + 1] = sPtr[i];

	}

	return *this;


}

/*

size_t String::find(const String &str, size_t pos = 0) const
{
	for (int i = 0; i <= size; i++)
	{
		if (sPtr[pos]==str[0])
		for (int j = 0; j <= str.size; j++)
			sPtr[j] = str[j];
		
	}

}


size_t String::find_first_of(const String str, size_t pos = 0) const
{
	for (int i = 0; i <= size; i++)
	{
		if (sPtr[pos] == str[0])
		for (int j = 0; j <= str.size; j++)
			sPtr[j] = str[j];

	}

}
*/

char& String::operator[] (size_t pos)
{
	if (pos < 0 || pos >= size)
	{
		cerr << "error";
	}

	return sPtr[pos];


}


const char& String::operator[] (size_t pos) const
{
	if (pos<0||pos>=size)
	{
		cerr << "error";
	}

	return sPtr[pos];

}
// Value with the position of a character within the string.
// Note: The first character in a string is denoted by a value of 0 (not 1).
// size_t is an unsigned integral type (the same as member type string::size_type).

String String::operator+ (const String& rhs)
{
	size = size + rhs.size;
	for (int i = 0; i <= rhs.size; i++)
	{
		sPtr[size + i] = rhs[i];

	}
	return *this;
}


String String::operator+ (const char*   rhs)
{
	size = size + rhs[size];
	for (int i = 0; i <= rhs[size]; i++)
	{
		sPtr[size + i] = rhs[i];

	}
	return *this;
}
// Returns a newly constructed string object with its value 
// being the *concatenation* of the characters in lhs followed by those of rhs.
// Note: If of type char*, it shall point to a null-terminated character sequence.

String& String::operator= (const String& str)
{
	if (&str != this)
	{
		if (size != str.size)
		{
			delete[]sPtr;
			size = str.size;
			sPtr = new char[size];

		}
		for (int i = 0; i < size; i++)
		{
			sPtr[i] = str.sPtr[i];
		}
		return *this;
	}
}

/*
String& String::operator= (const char* s)
{



}
//Assigns a new value to the string, replacing its current contents.
*/
bool String::operator==(const String &str)
{
	if (size != str.size)
		return false;
	
	for (int i = 0; i < size; i++)
	if (sPtr[i] != str.sPtr[i])
		return false;
		
	return true;

}

bool String::operator!=(const String &str)
{
	if (size == str.size)
		return false;

	for (int i = 0; i < size; i++)
	if (sPtr[i] == str.sPtr[i])
		return false;

	return true;


}




