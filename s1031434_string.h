#ifndef s1031434_string_H
#define s1031434_string_H

#include<iostream>
#include<vector>
using namespace std;

class String
{
	friend ostream &operator<<(ostream& output, const String& str);
public:
	static const size_t npos = -1;
	String();
	String(const String &str);
	String(const String& str, size_t pos, size_t len = npos);
	String(const char *s);
	~String();
	char& begin();
	char& end();
	size_t getSize() const; 
	void resize(size_t n);
	void resize(size_t n, char c);
	size_t getCapacity() const;
	void reserve(size_t n = 0); 
	void shrink_to_fit(); 
	void clear();
	bool empty() const;
	char& front();
	char& back();
	void push_back(char c);
	void pop_back();
	String& append(const String &str);
	String& substr(size_t pos = 0, size_t len = npos) const;
	String& insert(size_t pos, const String &str);
	String& insert(size_t pos, const String &str, size_t subpos, size_t sublen);
	String& erase(size_t subpos, size_t sublen);
	size_t find(const String &str, size_t pos = 0) const;
	size_t find_first_of(const String str, size_t pos = 0) const;
	char& operator[] (size_t pos);
	const char& operator[] (size_t pos) const;
	String operator+ (const String& rhs);
	String operator+ (const char*   rhs);
	String& operator= (const String& str);
	String& operator= (const char* s);
	bool operator==(const String &str);
	bool operator!=(const String &str); 
private:
	vector<char> str;
	size_t size; 
	size_t capacity;
	char *sPtr;
};

#endif