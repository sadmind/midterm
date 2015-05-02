#include <iostream>
#include <cstdlib>
#include "s1031517_String.h" // include definition of class String
using namespace std;

static const size_t npos = -1;
//size_t is an unsigned integral type.
//This constant is defined with a value of -1, which because size_t is an unsigned integral type, 
//it is the largest possible representable value for this type.

ostream &operator<<(ostream& output, const String& str)
{
	output << str.sPtr;
	return output;
}

String::String()
{
	size = 0;
	capacity = 10;
	for (int i = 0; i <= size; i++)
		sPtr[i] = '\0';

}// Constructs an empty string, with a length of zero characters. ***default capacity = 10

String::String(const String &str) // Constructs a copy of "str". (copy constructor)
{
	size = str.size;
	strcpy(sPtr, str.sPtr);
}

String::String(const String& str, size_t pos, size_t len = npos) // (substring constructor)
{
	String cop;
	for (int i = pos; i <= npos; i++)
		cop.sPtr[i - pos] = sPtr[i];
	strcpy(sPtr, cop.sPtr);
	size = npos - pos + 1;
}
// Copies the portion of str that begins at the character position "pos" and spans "len" characters 
// (or until the end of str, if either str is too short or if len is string::npos).

String::String(const char *s)
{ 
	strcpy(sPtr , s);
	size = strlen(s);
}
// Copies the array of character (C-string) pointed by s.
// The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
// The sequence is copied as the new value for the string.

String:: ~String() // Destroys the string object.
{
	size = 0;
	

}

char* String:: begin() // Returns an pointer referring to the first character in the string.
{


}

char* String::end()
{


}
// Returns an pointer referring to the past-the-end character of the string.
// The past-the-end character is a theoretical character that would follow the last character in the string.
// It shall not be dereferenced.

size_t String::getSize() const // Returns the number of characters in the string.
{
	return size;
}

void String::resize(size_t n)
{
	size = n;

}
// Resizes the string to a length of n characters.
// If n is smaller than the current string length,
// the current value is shortened to its first n character,
// removing the characters beyond the nth.
// If n is greater than the current string length,
// the current content is extended by inserting at the end
// as many characters as needed to reach a size of n.
// The new elements are initialized as copies of null characters ('\0').

void String::resize(size_t n, char c)
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
