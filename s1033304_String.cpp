#include"s1033304_String.h"
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

ostream &operator<<(ostream& output, const String& str)
{
	for (int i = 0; i < str.size; i++)
		output << str.sPtr[i];
	return output;
}

istream &operator>>(istream& input, String& str)
{
	char *inputS = new char[100];
	input >>setw(100)>> inputS;
	str = inputS;
	return input;
}
String::String()
:size(0), capacity(10), sPtr(NULL)
{
}

String::String(const String &str)
: size(str.size), capacity(str.capacity)
{
	setString(str.sPtr);
}

String::String(const String& str, size_t pos, size_t len)
// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
// (or until the end of str, if either str is too short or if len is string::npos).
{
	int newsize = len - pos + 1;
	size = newsize;
	capacity = size;
	sPtr = new char[newsize + 1];
	if (strlen(str.sPtr) == NULL)
		sPtr[0] = '\0';
	else
	{
		for (int i = 0; i < newsize; i++)
		{
			sPtr[i] = str.sPtr[pos];
			pos++;
		}
		sPtr[newsize] = '\0';
	}

}

String::String(const char *s)
// Copies the array of character (C-string) pointed by s.
// The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
// The sequence is copied as the new value for the string.
{
	size = strlen(s);
	capacity = size;
	sPtr = new char[strlen(s) + 1];
	if (s != NULL)
	{
		for (int i = 0; i < size + 1; i++)
		{
			sPtr[i] = s[i];
		}
	}
	else
		sPtr[0] = '\0';
}

String::~String()
{
	delete[]sPtr;
}

void String::setString(char *inputS)
{
	sPtr = new char[size + 1];
	if (inputS != NULL)
	{
		for (int i = 0; i < size + 1; i++)
		{
			sPtr[i] = inputS[i];
		}
	}
	else
		sPtr[0] = '\0';
}

String &String:: operator= (const String& str)
{
	if (*this != str)
	{
		delete[]sPtr;
		size = str.size;
		capacity = str.capacity;
		setString(str.sPtr);
		return *this;
	}
}
String &String:: operator= (const char* s)
//Assigns a new value to the string, replacing its current contents.
{
	if (*this != s)
	{
		delete[]sPtr;
		size = strlen(s);
		capacity = size;
		for (int i = 0; i < size + 1; i++)
		{
			sPtr[i] = s[i];
		}
		return *this;
	}
}

bool String:: operator==(const String &str) //< (equal to) true: two identical String
{
	return strcmp(sPtr, str.sPtr) == 0;
}

bool String:: operator!=(const String &str) //< (not equal to)
{
	bool equal = strcmp(sPtr, str.sPtr);
	return equal;
}


size_t String::getSize() const // Returns the number of characters in the string.
{
	return size;
}

size_t String::getCapacity() const
// NOTE: default capacity = 10
// Returns the size of the storage space currently allocated for the string,
// expressed in terms of elements.
// *This capacity is not necessarily equal to the string length. It can be equal or greater,
// with the extra space allowing the object to optimize its operations when new characters are added to the string.
{
	return capacity;
}

void String:: clear()
// Erases the contents of the string, which becomes an empty string
// (with a length of 0 characters, the Capacity is not affected).
{
	size = 0;
}

bool String:: empty() const // Returns whether the string is empty (i.e. whether its size is 0).
{
	if (size == 0)
		return true;
	else
		return false;
}

char& String::front()
// *Returns a reference to the first character of the string.
// This function shall not be called on empty strings.
{
	if (sPtr == NULL)
		cout << "Error" << endl;
	return sPtr[0];
}

char& String::back()
// *Returns a reference to the last character of the string.
// This function shall not be called on empty strings.
{
	if (sPtr == NULL)
		cout << "Error" << endl;
	return sPtr[size - 1];
}


char& String:: operator[] (size_t pos) //Get character of string
{
	if (pos < 0 || pos >= size)
		cout << "Error" << endl;
	else
		return sPtr[pos];
}
const char& String:: operator[] (size_t pos) const
// Value with the position of a character within the string.
// Note: The first character in a string is denoted by a value of 0 (not 1).
// size_t is an unsigned integral type (the same as member type string::size_type).
{
	if (pos < 0 || pos >= size)
		cout << "Error" << endl;
	else
		return sPtr[pos];
}

String String:: operator+ (const String& rhs)
{
	int newsize = size + rhs.size;
	capacity = newsize;
	char *tempS = new char[newsize + 1];
	for (int i = 0; i < size; i++)
		tempS[i] = sPtr[i];
	for (int i = size; i < newsize; i++)
		tempS[i] = rhs.sPtr[i - size];
	tempS[newsize] = '\0';
	String returnS(tempS);
	delete tempS;
	return returnS;
}
String String:: operator+ (const char*   rhs)
// Returns a newly constructed string object with its value
// being the *concatenation* of the characters in lhs followed by those of rhs.
// Note: If of type char*, it shall point to a null-terminated character sequence.
{
	int newsize = size + strlen(rhs);
	capacity = newsize;
	char *tempS = new char[newsize + 1];
	for (int i = 0; i < size; i++)
		tempS[i] = sPtr[i];
	for (int i = size; i < newsize; i++)
		tempS[i] = rhs[i - size];
	tempS[newsize] = '\0';
	String returnS(tempS);
	delete tempS;
	return returnS;
}

void String:: push_back(char c)
// Appends character c to the end of the string, increasing its length by one.
// *Return the reference of itself
{
	int newsize = size + 1;
	char *tempS = new char[newsize + 1];
	for (int i = 0; i < size; i++)
		tempS[i] = sPtr[i];
	tempS[size] = c;
	tempS[newsize] = '\0';
	size = newsize;
	sPtr = tempS;
}

void String:: pop_back()
// Erases the last character of the string, effectively reducing its size by one.
// (the string capacity is not affected)
// *Return the reference of itself
{
	size--;
}

String &String:: append(const String &str)
// Appends a str on the tail of current String.
// *Return the reference of itself
{
	int newsize = size + str.size;
	char *tempS = new char[newsize + 1];
	for (int i = 0; i < size; i++)
		tempS[i] = sPtr[i];
	for (int i = size; i < newsize; i++)
		tempS[i] = str[i - size];
	tempS[newsize] = '\0';
	size = newsize;
	sPtr = tempS;
	return *this;
}

String &String:: erase(size_t subpos, size_t sublen)
// Erases the portion of the string value that begins at the character position pos and spans len characters
// (or until the end of the string, if either the content is too short or if len is string::npos.)
// *Return the reference of itself
{
	int newsize = 0;
	int j = subpos + sublen;
	if (sublen == 0)
		return *this;
	else
		newsize = size - sublen;
	char *tempS = new char[newsize + 1];
	for (int i = 0; i < subpos; i++)
		tempS[i] = sPtr[i];
	for (int i = subpos; i < newsize; i++)
	{
		tempS[i] = sPtr[j];
		j++;
	}
	tempS[newsize] = '\0';
	size = newsize;
	sPtr = tempS;
	return *this;
}

String &String:: insert(size_t pos, const String &str)
// Inserts a copy of a str at "pos".
// example: str = "to be question", str2 = "the "
// str.insert(6,str2); // = to be (the )question
// *Return the reference of itself
{
	int newsize = size + str.size;
	int j = pos;
	int k = 0;
	char *tempS = new char[newsize + 1];
	for (int i = 0; i < pos; i++)
		tempS[i] = sPtr[i];
	for (int i = pos; i < pos + str.size; i++)
	{
		tempS[i] = str[k];
		k++;
	}

	for (int i = pos + str.size; i < newsize; i++)
	{
		tempS[i] = sPtr[j];
		j++;
	}
	tempS[newsize] = '\0';
	size = newsize;
	sPtr = tempS;
	return *this;
}

String &String:: insert(size_t pos, const String &str, size_t subpos, size_t sublen)
// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
// begins at the character position subpos and spans sublen characters (or until the end of str).
// example: str = "to be the question", str3 = "or not to be"
// str.insert(6,str3,3,4); // to be (not )the question
// *Return the reference of itself*/
{
	int newsize = size + sublen;
	int j = pos;
	char *tempS = new char[newsize + 1];
	for (int i = 0; i < pos; i++)
		tempS[i] = sPtr[i];
	for (int i = pos; i < pos + sublen; i++)
	{
		tempS[i] = str[subpos];
		subpos++;
	}
	for (int i = pos + sublen; i < newsize; i++)
	{
		tempS[i] = sPtr[j];
		j++;
	}
	tempS[newsize] = '\0';
	size = newsize;
	sPtr = tempS;
	return *this;
}

String &String:: substr(size_t pos , size_t len ) const
// The substring is the portion of the object that starts at character position pos and spans len characters
// (or until the end of the string, whichever comes first).
// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
{
	int newsize = len;
	int j = pos;
	char *tempS = new char[newsize + 1];
	for (int i = 0; i < newsize; i++)
	{
		tempS[i] = sPtr[j];
		j++;
	}	
	tempS[newsize] = '\0';
	String returnS;
	returnS.size = newsize;
	returnS = tempS;
	return returnS;
}

size_t String:: find(const String &str, size_t pos) const
// Searches the portion of the string value that begins at the character position pos until the end of the string
// for the first occurrence of the string str.
// Return Value: The position of the first character of the first match. If no matches were found, the function returns String::npos.
{
	int j = 0;
	int first = 0;
	for (int i = 0; i < size; i++)
	{
		if (sPtr[i] == str[j])
		{
			j++;
			first = i;
		}
		if (j == str.size)
			return first;
	}
	return String::npos;
}