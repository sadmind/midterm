#include "s1031506_string.h"
#include <string.h>
#include <iostream>
using namespace std;

ostream &operator<<(ostream& output, const String& str)
{
	output << str.sPtr;
	return output;
}
String::String()
{
	size = 0;
	capacity = 0;
	sPtr = "";
}

String::String(const String &str)
{
	size = str.size;
	capacity = str.capacity;
	sPtr = str.sPtr;
}

String::String(const String& str, size_t pos, size_t len = npos)
{

}
// (substring constructor)
// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
// (or until the end of str, if either str is too short or if len is string::npos).

String::String(const char *s)
{

}
// Copies the array of character (C-string) pointed by s.
// The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
// The sequence is copied as the new value for the string.

String::~String()
{

}// Destroys the string object.

char* begin(); // Returns an pointer referring to the first character in the string.

char* end();
// Returns an pointer referring to the past-the-end character of the string.
// The past-the-end character is a theoretical character that would follow the last character in the string.
// It shall not be dereferenced.

size_t String::getSize() const
{

}// Returns the number of characters in the string.

void String::resize(size_t n)
{

}
// Resizes the string to a length of n characters.
// If n is smaller than the current string length,
// the current value is shortened to its first n character,
// removing the characters beyond the nth.
// If n is greater than the current string length,
// the current content is extended by inserting at the end
// as many characters as needed to reach a size of n.
// The new elements are initialized as copies of null characters ('\0').

void resize(size_t n, char c)
{

}
// Similar to above one. The new elements are initialized as copies of c.

size_t String::getCapacity() const
{

}
// NOTE: default capacity = 10
// Returns the size of the storage space currently allocated for the string,
// expressed in terms of elements.
// *This capacity is not necessarily equal to the string length. It can be equal or greater, 
// with the extra space allowing the object to optimize its operations when new characters are added to the string.

void String::reserve(size_t n = 0)
{

}// Requests that the string capacity be enough to contain n characters.
// If n is greater than the current string capacity,
// the function causes the container to reallocate its storage increasing its capacity to n.
// In all other cases, the function call does NOT cause a reallocation and
// (the string capacity is not affected)

void String::shrink_to_fit()
{

}// Requests the container to reduce its capacity to fit its size.

void String::clear()
{
	size = 0;
	capacity = 0;
	sPtr = "";
}
// Erases the contents of the string, which becomes an empty string 
// (with a length of 0 characters, the Capacity is not affected).

bool String::empty() const
{

}// Returns whether the string is empty (i.e. whether its size is 0).

char &String::front()
{

}
// *Returns a reference to the first character of the string.
// This function shall not be called on empty strings.

char&Stingback();
// *Returns a reference to the last character of the string.
// This function shall not be called on empty strings.

void String::push_back(char c)
{

}
// Appends character c to the end of the string, increasing its length by one.
// *Return the reference of itself

void String::pop_back()
{

}
// Erases the last character of the string, effectively reducing its size by one. 
// (the string capacity is not affected)
// *Return the reference of itself

String& append(const String &str)
{

}
// Appends a str on the tail of current String. 
// *Return the reference of itself

String& String::substr(size_t pos = 0, size_t len = npos) const
{

}
// The substring is the portion of the object that starts at character position pos and spans len characters 
// (or until the end of the string, whichever comes first).
// *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.

String& insert(size_t pos, const String &str)
{

}
// Inserts a copy of a str at "pos".
// example: str = "to be question", str2 = "the "
// str.insert(6,str2); // = to be (the )question
// *Return the reference of itself

String& insert(size_t pos, const String &str, size_t subpos, size_t sublen)
{ 

}
// Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
// begins at the character position subpos and spans sublen characters (or until the end of str).
// example: str = "to be the question", str3 = "or not to be"
// str.insert(6,str3,3,4); // to be (not )the question
// *Return the reference of itself

String& erase(size_t subpos, size_t sublen)
{

}
// Erases the portion of the string value that begins at the character position pos and spans len characters 
// (or until the end of the string, if either the content is too short or if len is string::npos.)
// *Return the reference of itself

size_t String::find(const String &str, size_t pos = 0) const
{

}
// Searches the portion of the string value that begins at the character position pos until the end of the string
// for the first occurrence of the string str.
// Return Value: The position of the first character of the first match. If no matches were found, the function returns String::npos.

size_t String::find_first_of(const String str, size_t pos = 0) const
{

}
// Searches the portion of the string value that begins at the character position "pos" until the end of the string
// for the first character that matches *any* of the characters of the string str.
// Return Value: The position of the first character that matches. If no matches are found, the function returns String::npos.

char& String::operator[] (size_t pos)
{

}//Get character of string
const char& String::operator[] (size_t pos) const
{

}
// Value with the position of a character within the string.
// Note: The first character in a string is denoted by a value of 0 (not 1).
// size_t is an unsigned integral type (the same as member type string::size_type).

String operator+ (const String& lhs, const String& rhs);
String operator+ (const String& lhs, const char*   rhs);

// Returns a newly constructed string object with its value 
// being the *concatenation* of the characters in lhs followed by those of rhs.
// Note: If of type char*, it shall point to a null-terminated character sequence.

String& String::operator= (const String& str)
{
	string assign;
	assign.size = str.size;
	assign.capacity = str.capacity;
	assign = str.sPtr;
	return assign;
}
String& String::operator= (const char* s)
{

}
//Assigns a new value to the string, replacing its current contents.

bool String::operator==(const String &str)
{
	if (size == str.size && capacity == str.capacity && sPtr == str.sPtr)
		return true;
	else
		return false;
}//< (equal to) true: two identical String
bool String::operator!=(const String &str)
{
	return !(*this == str);
}//< (not equal to)
//Compares the value of the string object to the sequence of characters specified by its arguments.