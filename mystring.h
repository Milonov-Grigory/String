#ifndef MYSTRING_H
#define MYSTRING_H

#define STRBUFSIZE sizeof(char*)

class String
{
	union Container
	{
		char* _str;
		char  _buf[STRBUFSIZE];
	} _container;

	int   _len;

	char* get_container()
	{
		return ( _len < STRBUFSIZE ) 
			? _container._buf 
			: _container._str;
	}

	String(int size);
	public:
	String();
	String(const String&);
	~String();
	String(const char*);

	char& operator[](int idx); // index: s[10] = 'a'
	char  operator[](int idx) const; // a = s[10]

	bool operator==(const String&) const;
	bool operator!=(const String&) const;
	bool operator< (const String&) const;
	bool operator> (const String&) const;
	bool operator<=(const String&) const;
	bool operator>=(const String&) const;

	String operator+(const String&) const;
	String& operator=(const String&);

	operator const char*() const;
};

#endif
