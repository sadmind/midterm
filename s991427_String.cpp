#include<iostream>
#include<string>
#include"s991427_String.h"

using namespace std;

 ostream &operator<<(ostream& output, const String& str1)
{
	 
	 for (int i=0; i <= str1.size; i++)
		 output << str1.sPtr[i];
	 return output;

}

String::String()
{
	 capacity = 10;
	 size = 0;
	 sPtr=NULL;
}
String::String(const String &str)
{
	capacity = str.capacity;
	size = str.size;
	for (int i = 0; i <= size;i++)
	sPtr[i] = str.sPtr[i];
}
String::String(const String& str, size_t pos, size_t len )
{
	capacity = npos - pos+1;
	size = npos - pos;
	for (int i = pos; i <= npos;i++)
	sPtr[i] = str.sPtr[i];
}

String::String(const char *s)
{
	*this = s;
}

String::~String()
{

}

char* String::begin()
{
	*sPtr = sPtr[0];
	return (sPtr) ;
}

char* String::end()
{
	*sPtr = sPtr[size];
	return (sPtr);
}

size_t String::getSize()const
{
	return size;
}
void String::resize(size_t n)
{
	if (this->size>n)
	for (int i = 0; i <= n; i++)
		sPtr[i] = sPtr[i];
	else
	{
		for (int j = 0; j <= this->size; j++)
			sPtr[j] = sPtr[j];
		for (int k = this->size + 1; k <= n; k++)
			sPtr[k] = 0;
	}
}
void String::resize(size_t n, char c)
{
	if (this->size>n)
	for (int i = 0; i <= n; i++)
		sPtr[i] = sPtr[i];
	else
	{
		for (int j = 0; j <= this->size; j++)
			sPtr[j] = sPtr[j];
		for (int k = this->size + 1; k <= n; k++)
			sPtr[k] = 'c';
	}
}

size_t String::getCapacity()const
{
	return capacity;
}
void String::reserve(size_t n)
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
	sPtr = NULL;
}

bool String::empty()const
{
	if (this->size == 0)
		return true;
	else
		return false;
}
char&String::front()
{
	if (sPtr != NULL)
		*sPtr = sPtr[0];
	return(*sPtr);
}
char&String::back()
{
	if (sPtr != NULL)
		*sPtr = sPtr[size-1];
	return(*sPtr);
}
void String::push_back(char c)
{
	size=size + 1;
	sPtr[size-1] = 'c';
}

void String::pop_back()
{
	size = size - 1;

}
String &String::append(const String &str)
{
	String append;
	append.size= size + str.size;
	for (int i = 0; i < size; i++)
		append.sPtr[i] = sPtr[i];
	for (int j = size; j < append.size; j++)
		append.sPtr[j] = str.sPtr[j - size];
	return append;
}
String &String::substr(size_t pos , size_t len)const
{
	String substr;
	for (int i = pos; i < len; i++)
		substr.sPtr[i - pos] = sPtr[i];
	return substr;
}

String& String::insert(size_t pos, const String &str)
{
	String insert;
	for (int i = 0; i < pos; i++)
	{
		insert.sPtr[i] = sPtr[i];
	}
	insert.sPtr[pos] = '(';
	for (int j = pos+1; j <= pos + str.size; j++)
	{
		insert.sPtr[j] = str.sPtr[j - pos];
	}
	insert.sPtr[pos + str.size + 1] = ')';
	for (int k = pos + str.size + 2; k < pos + str.size + size; k++)
	{
		insert.sPtr[k] = sPtr[k - str.size - 2];
	}

	return insert;
}

String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen)
{
	String ins;
	ins = NULL;
	return ins;
}
String& String::erase(size_t subpos, size_t sublen)
{
	String erase;
	if (size<sublen)
	for (int i = 0; i < subpos; i++)
		erase.sPtr[i] = sPtr[i];
	else{
		for (int i = 0; i < subpos; i++)
			erase.sPtr[i] = sPtr[i];
		for (int i = subpos; i < size - sublen; i++)
			erase.sPtr[i] = sPtr[i + sublen - subpos];
	}
	return erase;
}
size_t String::find(const String &str, size_t pos )const
{
	
	for (int i = pos; i < size; i++)
	{
		if (sPtr[i] == str.sPtr[i])
			return i;
		else
			return 'npo';
	}
}


size_t String::find_first_of(const String str, size_t pos )const
{

	for (int i = pos; i < size; i++)
	
	{
		for (int i = 0; i < str.size;i++)
		if (sPtr[i] == str.sPtr[i])
			return i;
		else
			return 'npo';
	}
}

char& String::operator[] (size_t pos)
{
	if (pos < 0 || pos >= size){
		cerr << "Error:pos" << pos << "out of range" << endl;
		exit(1);}
	return sPtr[pos];
}
const char& String::operator[] (size_t pos)const
{
	if (pos < 0 || pos >= size){
		cerr << "Error:pos" << pos << "out of range" << endl;
		exit(1);
	}
	for (int i = 0; i <= pos; i++)
		return sPtr[pos];
}

String operator+(const String& rhs)
{
	String add;
	add = rhs;
	return add;
	
}
/*String operator+(const char *rhs)
{

}*/

String &String::operator=(const String& str)
{
	String nstr;
	nstr.capacity = str.capacity;
	nstr.size = str.size;
	for (int i = 0; i < nstr.size; i++)
		nstr.sPtr[i] = str.sPtr[i];
	return nstr;
}
String &String::operator=(const char* s)
{
	String S1;
	S1 = s;
	return S1;
}
bool String::operator==(const String &str)
{
	if (this->size != str.size)
		return false;
	else
	for (int i = 0; i <= size; i++)
	{
		if (sPtr[i] != str[i])
		{
			return false;
			break;
		}
		else
		{
			return true;
		}
	}
}
bool String::operator!=(const String &str)
{
	if (this->size != str.size)
		return true;
	else
	for (int i = 0; i <= size; i++)
	{
		if (sPtr[i] != str[i])
		{
			return true;
			break;
		}
		else
		{
			return false;
		}
	}
}

