#include "s991533_String.h"

using namespace std;

#if defined(__GNUC__) || defined(__GNUG__)
size_t strlen(const char *arr)
{
    size_t i = 0;
    while (arr[i] != '\0') {
        i++;
    }
    return i;
}
#endif


ostream &operator << (ostream& output, const String& str)
{
    for (size_t i = 0; i < str.size; i ++) {
        cout << str.sPtr[i];
    }
    return output;
}

String::String()
{
    size = 0;
    capacity = 10;
    sPtr = new char[capacity];
}

String::String(const String &str)
{
    size = str.size;
    capacity = str.capacity;
    sPtr = new char[capacity];
    for (size_t i = 0; i < size; i ++) {
        sPtr[i] = str.sPtr[i];
    }
}

String::String(const String& str, size_t pos, size_t len)
{
    size = (len == -1) ? str.size - pos : len;
    capacity = (size > 10) ? size : 10;
    sPtr = new char[capacity];
    for (size_t i = 0; i < size; i ++) {
        sPtr[i] = str.sPtr[pos + i];
    }
}

String::String(const char *s)
{
	size = strlen(s);
    capacity = (size > 10) ? size : 10;
    sPtr = new char[capacity];
    for (size_t i = 0; i < size; i ++) {
         sPtr[i] = s[i];
    }
}

String::~String()
{
	delete[] sPtr;
}

String& String::operator = (const String& str)
{
	size = str.size;
    capacity = str.capacity;
    delete[] sPtr;
	sPtr = new char[capacity];
    for (size_t i = 0; i < size; i ++) {
        sPtr[i] = str.sPtr[i];
    }
    return *this;
}

String& String::operator = (const char* s)
{
	String temp(s);
	*this = temp;
    return *this;
}

char* String::begin()
{
    return &sPtr[0];
}

char* String::end()
{
    return &sPtr[size-1];
}

void String::resize(size_t n)
{
	this->resize(n, '\0');
}

void String::resize( size_t n, char c )
{
    if (n == size) {
        return;
    }
    String temp(*this);
    delete[] sPtr;
	capacity = n;
	sPtr = new char[capacity];
    if (n < size) {
        for (size_t i = 0; i < n; i ++) {
			sPtr[i] = temp.sPtr[i];
        }
    } else {
        for (size_t i = 0; i < size; i ++) {
            sPtr[i] = temp.sPtr[i];
        }
        for (size_t i = size; i < n; i ++) {
            sPtr[i] = c;
        }
    }
    size = n;
}

bool String::operator == (const String &str)
{
    if (size != str.size) {
        return false;
    }
    for (size_t i = 0; i < size; i ++) {
        if (sPtr[i] != str.sPtr[i]) {
            return false;
        }
    }
    return true;
}

bool String::operator != (const String &str)
{
    return !(*this == str);
}

size_t String::getSize() const
{
    return size;
}

size_t String::getCapacity() const
{
    return capacity;
}

void String::reserve(size_t n)
{
    if (n > capacity) {
        String temp(*this);
        delete [] sPtr;
        sPtr = new char[n];
        for (size_t i = 0; i < size; i++) {
            sPtr[i] = temp.sPtr[i];
        }
		capacity = n;
    }
}

void String::shrink_to_fit()
{
    if (capacity > size) {
        String temp(*this);
        delete [] sPtr;
		capacity = size;
		sPtr = new char[capacity];
        for (size_t i = 0; i < size; i++) {
            sPtr[i] = temp.sPtr[i];
        }
    }
}

void String::clear()
{
    size = 0;
}

bool String::empty() const
{
    return (size == 0);
}

char& String::back()
{
    return sPtr[size - 1];
}

char& String::front()
{
    return sPtr[0];
}

void String::push_back(char c)
{
    if (capacity - size < 1) {
		this->reserve(size + 1);
    }
    sPtr[size++] = c;
}

void String::pop_back()
{
    size--;
}

String& String::append(const String &str)
{
    size_t oldSize = size;
	this->reserve(size + str.size);
	size += str.size;
    for (size_t i = oldSize; i < size; i ++) {
		sPtr[i] = str.sPtr[i - oldSize];
    }
    return *this;
}

String& String::substr(size_t pos , size_t len) const
{
	String * temp = new String(*this, pos, len);
    return *temp;
}

String& String::insert(size_t pos, const String &str)
{
    String front(*this, 0, pos);
	String back(*this, pos);
	this->reserve(size + str.size);
	this->clear();
	this->append(front);
	this->append(str);
    this->append(back);
    return *this;
}

String& String::insert(size_t pos, const String &str, size_t subpos, size_t sublen)
{
	String temp(str, subpos, sublen);
	this->insert(pos, temp);
	return *this;
}

String& String::erase(size_t subpos, size_t sublen)
{
    String front(*this, 0, subpos);
    String back(*this, subpos+sublen);
	this->clear();
	this->append(front);
	this->append(back);
    return *this;
}

size_t String::find(const String &str, size_t pos) const
{
    for (size_t i = pos; i < size - str.size; i ++) {
        for (size_t j = i; j <= i + str.size; j ++) {
			if (j == i + str.size) {
                return i;
            }
            if (sPtr[j] != str.sPtr[j - i]) {
                break;
            }
        }
    }
    return -1;
}

size_t String::find_first_of(const String str, size_t pos) const
{
    for (size_t i = pos; i < size; i ++) {
        if (sPtr[i] == str.sPtr[0]) {
            return i;
        }
    }
    return -1;
}

char& String::operator [] (size_t pos)
{
    return pos < size ? sPtr[pos] : sPtr[0];
}

const char& String::operator [] (size_t pos) const
{
    return pos < size ? sPtr[pos] : sPtr[0];
}

String String::operator + (const String& rhs)
{
    String temp(*this);
    temp.append(rhs);
    return temp;
}

String String::operator + (const char* rhs)
{
	String temp(*this);
	String temp2(rhs);
	temp.append(temp2);
    return temp;
}
