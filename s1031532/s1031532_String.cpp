#include <iostream>
#include "s1031532_String.h" 
using namespace std;

 ostream &operator<<(ostream& output, const String& str)
{
	 for (size_t i = 0; i < str.size; i++)
		 cout << str.sPtr[i]; return output;

}
String::String()
{
	size = 0;
	capacity = 0;
}
String::String(const String &str)
{
	size = str.size;
	capacity = str.capacity;

}

String::String(const String& str, size_t pos, size_t len )
{
	size = pos - len;
	sPtr = new char[size];

	

}

String::String(const char *s)
{
	size = strlen(s);
	capacity = size;
	sPtr = new char[size];
	for (size_t i = 0; i < size; i++)
		sPtr[i] = s[i];
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
	return sPtr + size;
}

size_t String::getSize()const
{
	return size;
}

void String::resize(size_t n)
{
	char*buffer;
	if (n > size)
	{
			buffer = new char[size];
			for (size_t i = 0; i < size; i++)
				buffer[i] = sPtr[i];
			delete sPtr;
			sPtr = new char[n];
			for (size_t i = 0; i, size; i++)
				sPtr[i] = buffer[i];
			delete buffer;
			capacity = n;
			size = n;
	}
	else if (n < size)
	{
		for (size_t i = size; i < n; i++)
			sPtr[size] = '\0';
		size = n;
	}
	else
		return;
	
	
}

void String::resize(size_t n, char c)
{
	
	if (n > size)
	{
		delete sPtr;
		sPtr = new char[n];
		for (size_t i = 0; i < n; i++)
			sPtr[i] = c;
		size = n;
		capacity = n;
	}
	else if (n < size)
	{
		for (size_t i = size; i < n; i++)
			sPtr[size] = '\0';
		size = n;
	}
	else
		return;



}

size_t String::getCapacity()const
{
	return capacity;
}

void String::reserve(size_t n )
{
	char *buffer;
	if (n > capacity)
	{
		buffer = new char[size];
		for (size_t i = 0; i < n; i++)
			buffer[i] = sPtr[i];
		delete sPtr;
		sPtr = new char[n];
		for (size_t i = 0; i < size; i++)
			sPtr[i] = buffer[i];
		delete buffer;
		for (size_t i = size; i < n; i++)
			sPtr[i] = '\0';
		capacity = n;
	
	}

	else if (n < capacity)
	{
		size = n;
		capacity = n;



	}
	else
		return;


}

void String::shrink_to_fit()
{

}

void String::clear()
{
	size = 0;
}

bool String::empty()const
{
	if (size == 0)
		return 1;

}

char& String::front()
{
	return sPtr[0];

}

char& String::back()
{
	return sPtr[size];

}

void String::push_back(char c)
{
	size += 1;
	capacity += 1;
	sPtr[size] = c;
}

void String::pop_back()
{
	size -= 1;
	

}

