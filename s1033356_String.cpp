#include<iostream>
#include<cstring>
#include"s1033356_String.h"


using namespace std;

ostream &operator<<(ostream& output, const String& str)
{
	for (int i = 0; i < strlen(str.sPtr); i++)
	{
        output << str.sPtr[i];
	}
	
	
	return output;
}


String::String()
{
	sPtr = new char[1];
	sPtr[0] = '\0';
	size++;
}

String::String(const char *s)
{
	length = strlen(s);
	sPtr = new char[length + 1];
	size++;
	for (int i =0; i <= length; i++)
	{
		sPtr[i]=s[i];
	}	
}

String::String(const String &str)
{
	size++;
	length = strlen(str.sPtr);
	sPtr = new char[length + 1];
	for (int i = 0; i <= length; i++)
	{
		 sPtr[i]=str.sPtr[i] ;
	}
}

String::~String()
{
	--size;
	delete[] sPtr;

}

void String::push_back(char c)
{
	String temp;
	length = strlen(sPtr);
	for (int i = 0; i <length-1; i++)
	{
		temp.sPtr[i + 1] = sPtr[i + 1];
	}
	delete[] sPtr;
	sPtr = new char[length + 1];
	for (int i = 0; i <length-1; i++)
	{
		sPtr[i + 1] = temp.sPtr[i + 1];
	}
	sPtr[length] = c;

}

void String::clear()
{
	delete[]sPtr;
}



void String::pop_back()
{
	length = strlen(sPtr);
	sPtr[length-1]='\0';
}





char & String::operator[] (size_t pos)
{
	return sPtr[pos];
}

const char & String::operator[] (size_t pos) const
{
	return sPtr[pos];
}


String String::operator+ (const String& rhs)
{

	String newValue;
	length = strlen(rhs.sPtr) + strlen(sPtr);
	newValue.sPtr = new char[length + 1];
	for (int i = 0; i <= strlen(sPtr); i++)
	{
		newValue.sPtr[i] = sPtr[i];
	}
	for (int i = strlen(sPtr) ; i <= length; i++)
	{
		newValue.sPtr[i] = rhs.sPtr[i - strlen(sPtr)];
		
	}
	return newValue.sPtr;
}
String String::operator+ (const char*   rhs)
{
	String newValue;
	length = strlen(rhs) + strlen(sPtr);
	newValue.sPtr = new char[length + 1];
	for (int i =0; i <= strlen(sPtr); i++)
	{
		newValue.sPtr[i] = sPtr[i-1];
	}
	for (int i = strlen(sPtr); i < length; i++)
	{
		newValue.sPtr[i] = rhs[i - strlen(sPtr)-1];
	
	}
	return newValue.sPtr;
}



String & String::operator= (const String& str)
{
	if (this == &str)
		return *this;
	delete[] sPtr;
	length = strlen(str.sPtr);
	sPtr = new char[length + 1];
	for (int i = 0; i <length; i++)
	{
		str.sPtr[i+1] = sPtr[i+1];
	}
	return *this;
}






String & String::operator= (const char* s)
{
	delete[] sPtr;
	length = strlen(s);
	sPtr = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		sPtr[i]=s[i];
	}
	return *this;
}

bool String::operator==(const String &str)
{
	if (strcmp(sPtr, str.sPtr))
		return true;
	else
		return false;

}
bool String::operator!=(const String &str)
{
	if (strcmp(sPtr, str.sPtr))
		return false;
	else
		return true;
}