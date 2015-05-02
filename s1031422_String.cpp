#include<iostream>
#include"s1031422_String.h"

using namespace std;

ostream &operator<<(ostream& output, const String& str)
{
	for (int i = 0; i < str.size; i++)
		output << str.sPtr[i];
	return output;
}
istream& operator>> (istream& input, string& str)
{
	char in;
	input >> in;
	str=in;
	return input;
}
String::String()
{
	size = 0;
	capacity = 10;
	sPtr = new char [10];
	for (int i = 0; i < 10; i++)
		sPtr[i] = '\0';
}
String::String(const String &str)
{

	size = str.size;
	capacity = size;
	sPtr = new char[capacity];
	for (int i = 0; i<str.size; i++)
		sPtr[i] = str.sPtr[i];
	
}
/*String::String(const String& str, size_t pos, size_t len = npos)
{


}*/
String::String(const char *s)
{
	size = 0;
	capacity = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		size++;
		capacity++;
	}
	size++;
	capacity++;
	sPtr = new char[size];
	for (int i = 0; i < size;i++)
	sPtr[i] = s[i];


}
String::~String()
{
	delete[]sPtr;
}
char* String::begin()
{
	char * temp = sPtr;
	return temp;
}
char* String::end()
{
	char *temp = sPtr+size - 2;
	return temp;
}
size_t String::getSize() const
{
	return size;
}
void String::resize(size_t n)
{
	if (n < size)
	{
		char *temp = new char[n];
		for (int i = 0; i < n; i++)
			temp[i] = sPtr[i];
		temp[n - 1] = '\0';
		delete[]sPtr;
		sPtr = temp;
		size = n;
		capacity = n;
	}
	else if (n>size)
	{
		char *temp = new char[n];
		for (int i = 0; i < size; i++)
			temp[i] = sPtr[i];
		for (int i = size; i < n; i++)
			temp[i] = '\0';
		delete[]sPtr;
		sPtr = temp;
		capacity = n;
	}
}

void String::resize(size_t n, char c)
{
	if (n < size)
	{
		char *temp = new char[n];
		for (int i = 0; i < n; i++)
			temp[i] = sPtr[i];
		temp[n - 1] = '\0';
		delete[]sPtr;
		sPtr = temp;
		size = n;
		capacity = n;
	}
	else if (n>size)
	{
		char *temp = new char[n];
		for (int i = 0; i < size; i++)
			temp[i] = sPtr[i];
		for (int i = size; i < n; i++)
			temp[i] = c;
		temp[n - 1] = '\0';
		delete[]sPtr;
		sPtr = temp;
		size = n;
		capacity = n;
	}
}

size_t String::getCapacity() const
{
	return capacity;
}

void String::reserve(size_t n){}

void String::shrink_to_fit()
{
	if (size != capacity)
	{
		char *temp = new char[size];
		for (int i = 0; i < size; i++)
			temp[i] = sPtr[i];
		delete[] sPtr;
		sPtr = temp;
		capacity = size;
	}
}

void String::clear()
{
	delete[] sPtr;
	char *temp = '\0';
	sPtr = temp;
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
	if (sPtr)
		return sPtr[0];

}
char& String::back()
{
	if (sPtr)
	return sPtr[size];
}

void String::push_back(char c)
{
	char *temp = new char[size + 1];
	for (int i = 0; i < size; i++)
		temp[i] = sPtr[i];
	temp[size - 1] = c;
	temp[size] = '\0';
	delete[] sPtr;
	sPtr = temp;
	size++;
	capacity = size;
}

void String::pop_back()
{
	char *temp = new char[capacity];
	for (int i = 0; i < size-1; i++)
		temp[i] = sPtr[i];
	temp[size - 2] = '\0';
	delete[] sPtr;
	sPtr = temp;
	size--;
}

String& String::append(const String &str)
{
	
	*this=*this + str;
	return *this;
}

String& String::substr(size_t pos , size_t len ) const
{
	String temp;
	char *s1 = new char[size - len];
	temp.size = size - len;
	temp.capacity = size;
	for (int i = 0; i < pos; i++)
		s1[i] = sPtr[i];
	for (int i = pos, j = pos + len; i < size; i++, j++)
		s1[i] = sPtr[j];
	delete[] temp.sPtr;
	temp.sPtr = s1;
	return temp;
}

String& String::insert(size_t pos, const String &str)
{
	int count;
	for (count = 0; str[count] != '\0'; count++){}
	char *temp = new char[size + count];
	for (int i = 0; i < pos; i++)
		temp[i] = sPtr[i];
	for (int i = pos; i < pos + count; i++)
		temp[i] = str[i];
	for (int i = pos + count; i < size + count; i++)
		temp[i] = sPtr[i];
	delete[] sPtr;
	sPtr = temp;
	return *this;
}

//String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen){}

String& String::erase(size_t subpos, size_t sublen)
{
	char *temp = new char[size - sublen];
	size = size - sublen;
	capacity = size;
	for (int i = 0; i < subpos; i++)
		temp[i] = sPtr[i];
	for (int i = subpos, j = subpos+sublen; i < size; i++, j++)
		temp[i] = sPtr[j];
	delete[] sPtr;
	sPtr = temp;
	return *this;
}

/*size_t String::find(const String &str, size_t pos )const 
{

}

size_t String::find_first_of(const String str, size_t pos )const {}
*/
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
	String temp;
	temp.size = size + rhs.size-1;
	temp.capacity = temp.size;
	temp.sPtr = new char[temp.size];
	for (int i = 0; i < size-1; i++)
		temp.sPtr[i] = sPtr[i];
	for (int i = size-1,j=0 ; i < temp.size;i++,j++)
		temp.sPtr[i] = rhs.sPtr[j];
	return temp;
}
String String::operator+ (const char*   rhs)
{
	String temp;
	int count = 0;
	for (count = 0; rhs[count] != '\0'; count++){}
	count++;
	temp.size = count + size-1;
	temp.capacity = temp.size;
	temp.sPtr = new char[temp.size];
	for (int i = 0; i < size-1; i++)
		temp.sPtr[i] = sPtr[i];
	for (int i = size - 1,j=0; i < temp.size; i++,j++)
		temp.sPtr[i] = rhs[j];
	return temp;
}

String& String::operator= (const String& str)
{
	size = str.size;
	capacity = str.capacity;
	sPtr = new char[capacity];
	for (int i = 0; i < capacity; i++)
		sPtr[i] = str.sPtr[i];
	return *this;
}
String& String::operator= (const char* s)
{

	size = 0;
	capacity = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		size++;
		capacity++;
	}
	size++;
	capacity++;
	sPtr = new char[size];
	for (int i = 0; i < size; i++)
		sPtr[i] = s[i];
	return *this;
}

bool String::operator==(const String &str)
{
	return !(operator!=(str));
}

bool String::operator!=(const String &str)
{
	if (size != str.size)
		return true;
	for (int i = 0; str.sPtr[i] == '\0' || sPtr[i] == '\0'; i++)
	{
		if (str.sPtr[i] != sPtr[i])
			return true;
	}
	return false;
}
