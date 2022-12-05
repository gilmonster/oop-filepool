#include "SafeArr.h"
#include <iostream>
#include <stdbool.h>
#include <string>

using namespace std;
unsigned Safe_Array::score(0);

//Safe_Array::Safe_Array(unsigned capacity)
//{
//	if (capacity == 0) // for capacity zero
//	{
//		m_data = nullptr;
//		m_capacity = 0;
//		return;
//	}
//
//	m_data = new int[capacity];
//
//	for (unsigned i = 0; i < capacity; i++) m_data[i] = 0; // initialize the arry to zeros
//
//	m_capacity = capacity;
//	score = score+(sizeof(m_data) + sizeof(Safe_Array)); 
//}

Safe_Array::Safe_Array(unsigned size, unsigned max_tries) : m_max_tries(max_tries), curr_max_try(0)
{
	unsigned capacity = size;
	if (capacity == 0) // for capacity zero
	{
		m_data = nullptr;
		m_capacity = 0;
		return;
	}

	m_data = new int[capacity];

	for (unsigned i = 0; i < capacity; i++) m_data[i] = 0; // initialize the arry to zeros

	m_capacity = capacity;
	score = score + (sizeof(m_data) + sizeof(Safe_Array));
}

Safe_Array::Safe_Array(const Safe_Array& a) : m_max_tries(0), curr_max_try(0)
{
	*this = a;
	score = score + (sizeof(m_data) + sizeof(Safe_Array));

	/*m_capacity =a.m_capacity;                //implamentation at assign func to avoid code copying;
	m_data = new int[m_capacity];

	for (unsigned i = 0; i < m_capacity; i++)
	{
		m_data[i] = a.m_data[i];
	}*/
}

Safe_Array::~Safe_Array()
{
	score = score - (sizeof(m_data) - sizeof(Safe_Array));
	delete[] m_data;

}

void Safe_Array::show(void) const
{
	for (unsigned i = 0; i < m_capacity; i++)
	{
		printf("%d", m_data[i]);
	}
}

unsigned Safe_Array::get_capacity() const
{
	return m_capacity;
}

bool Safe_Array::insert(int value, unsigned index)
{
	int flag = 0;
	if (leagal_idx(m_capacity, index))
	{
		m_data[index] = value;
		flag = 1;
	}
	return flag;
}

bool leagal_idx(int capacity, int idx)
{
	if (idx < 0 || idx >= capacity) return false;
	return true;
}

bool Safe_Array::get(unsigned index, int& value) const
//int Safe_Array::operator[](int index) const
{
	int flag = 0;
	if (leagal_idx(m_capacity, index))
	{
		value = m_data[index];
		return true;
		flag = 1;
	}
	return flag;
}

bool Safe_Array::search(int value, unsigned& index) const
{
	for (unsigned i = 0; i < m_capacity; i++)
	{
		if (m_data[i] == value)
		{
			index = i;
			return true;
		}
	}
	return false;
}

Safe_Array& Safe_Array::operator=(const Safe_Array& a)
{
	m_capacity = a.m_capacity;
	m_data = new int[m_capacity];

	for (unsigned i = 0; i < m_capacity; i++)
	{
		m_data[i] = a.m_data[i];
	}
	return *this;
}

void Safe_Array::resize(unsigned size)
{
	unsigned new_size = m_capacity;
	int* tmp_data;

	if (size > m_capacity)  // set the correct size
		new_size = size;

	tmp_data = new int[size];

	unsigned i;
	for (i = 0; i < m_capacity; i++) // copy the alredy stored data
		tmp_data[i] = m_data[i];

	if (size > m_capacity) // fill zeros if needed
	{
		for (i; i < size; i++)
			tmp_data[i] = 0;
	}

	delete[] m_data;   // no data leaks
	m_data = tmp_data;
}

ostream& operator<<(ostream& os, const Safe_Array& a)
{
	for (unsigned i = 0; i < a.m_capacity; i++)
	{
		os << a.m_data[i];
	}
	return os;
}

int& Safe_Array::operator[](int index)  //insert
{
	//if (curr_max_try >= m_max_tries)
	//	cout << 'You tried to access illegal memory % d time', m_max_tries << endl;
	if (((unsigned)index >= m_capacity) && ((unsigned)index >= 0))
	return m_data[0];     // false

	return m_data[index];  // true
}

int Safe_Array:: operator[](int index) const  //get
{
	if (((unsigned)index >= m_capacity) && ((unsigned)index >= 0))
		return -1;   // false

	return m_data[index];  // true
}

bool operator==(const Safe_Array& a, const Safe_Array& b)
{
	if ((a.m_capacity < b.m_capacity) || (a.m_capacity > b.m_capacity))
		return false;
	for (unsigned i = 0; i < a.m_capacity; i++)
	{
		if (a.m_data[i] == b.m_data[i])
			continue;
		return false;
	}
	return true;
}