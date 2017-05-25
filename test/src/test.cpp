#include <cstring>
#include<iostream>

using namespace std;

template <class Type> Type maxof(Type a, Type b)
{
	return a > b ? a : b;
}

template <> const char* maxof<const char*>(const char* a, const char* b)
{
	return strcmp(a, b) > 0 ? a : b;
}
