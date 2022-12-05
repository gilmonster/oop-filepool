#ifndef _SAFE_ARRY_
#define _SAFE_ARRY_

#include <iostream>
#include <stdbool.h>
using namespace std;

class Safe_Array
{
private:
	int* m_data;
	unsigned m_capacity;
public:
	static unsigned score;
	const int m_max_tries;
	int curr_max_try;

	//Safe_Array(unsigned capacity = 0);
	Safe_Array(unsigned size = 0, unsigned max_tries = 0);
	Safe_Array(const Safe_Array&);// cc
	~Safe_Array();
	void show(void) const;
	unsigned get_capacity() const;
	bool insert(int value, unsigned index);
	int& operator[](int index);
	
	bool get(unsigned index, int& value) const;
	int operator[](int index) const;
	
	bool search(int value, unsigned& index) const;
	Safe_Array& operator=(const Safe_Array& a);
	void resize(unsigned size);



	friend ostream& operator<<(ostream& os, const Safe_Array& a);
	friend bool operator==(const Safe_Array& a, const Safe_Array& b);
};



bool leagal_idx(int capacity, int idx);

#endif // _SAFE_ARRY_
