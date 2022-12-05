#include <iostream>
#include "SafeArr.h"

// test test test 

using namespace std;

void inform_insert(Safe_Array& sa, int val, int ndx)
{
	if (sa.insert(val, ndx))
		cout << "Insert data " << val << " in ndx " << ndx << endl;
	else
		cout << "Insert failed: Invalid ndx " << ndx << endl;
}

void inform_get(Safe_Array& sa, int ndx, int& val)
{
	if (sa.get(ndx, val))
		cout << "Got value " << val << " in ndx " << ndx << endl;
	else
		cout << "Get failed: Invalid ndx " << ndx << endl;
}

void inform_search(const Safe_Array& sa, int val, unsigned& ndx)
{
	if (sa.search(val, ndx))
		cout << val << " found in ndx " << ndx << endl;
	else
		cout << val << " not found" << endl;
}

void test1()
{
	Safe_Array a1(5);
	Safe_Array a19(6);

	cout << sizeof(a1) << endl;
	cout << sizeof(a19) << endl;

	if (a1 == a1) // test for operator ==
		cout << true << endl;
	if (a1 == a19)
		cout << true << endl;
	else cout << false << endl;// end test

	
	inform_insert(a1, 1, 3);
	inform_insert(a1, 2, 0);
	inform_insert(a1, 8, 1);
	inform_insert(a1, 4, 2);
	inform_insert(a1, 9, 4);
	inform_insert(a1, 9, 5);
	inform_insert(a1, 9, 5);
	inform_insert(a1, 9, 5);
	inform_insert(a1, 9, 5);
	inform_insert(a1, 9, 5);
	inform_insert(a1, 9, 5);

	cout << "a1: ";
	a1.show();


	Safe_Array a2(a1);		// CC
	cout << "a2: ";
	a2.show();

	Safe_Array a3;			// DC

	Safe_Array& a4 = a3 = a1;
	cout << "a3 after assign with a1: ";
	a3.show();
	cout << endl << "a4 after assign a3 with a1: ";
	a4.show();

	a1.insert(7, 1);
	cout << "change a1 after assign to a3:" << endl << "a1: ";
	a1.show();
	cout << endl << "a3: ";
	a3.show();
	cout << endl << endl;

	int val;
	inform_get(a1, 6, val);
	inform_get(a1, 2, val);

	unsigned ndx;
	inform_search(a1, 4, ndx);
	inform_search(a1, 5, ndx);

	cout << "array of arrays: " << endl;
	Safe_Array s_arr[3] = { a1, a2, a3 };		// 3 new arrys are constructed!
	for (int i = 0; i < 3; i++)
	{
		s_arr[i].show();
		cout << endl;
	}


	cout << "array of pointers to array: " << endl;
	Safe_Array* s_arr1[3] = { &a1, &a2, &a3 };	// pointers to existing arrays. No additional Safe_Array objects
	for (int i = 0; i < 3; i++)
	{
		s_arr1[i]->show();
		cout << endl;
	}


	Safe_Array a5;
	a5.resize(3);
}

void print_arr(const Safe_Array& a, char* name)
{
	cout << name << ": " << a;
}


//void test2()
//{
//	Safe_Array a1(5);
//
//	a1[3] = 1;
//	a1[0] = 0;
//	a1[1] = 1;
//	a1[2] = 2;
//	a1[4] = 4;
//	a1[5] = 5;
//	a1[6] = 6;
//	a1[5] = 5;
//
//	print_arr(a1, "a1");
//	a1[2] = 9;
//	print_arr(a1, "a1");
//
//	a1.resize(4);
//	print_arr(a1, "a1");
//
//	a1.resize(8);
//	print_arr(a1, "a1");
//
//	Safe_Array a2(3);
//	a2[0] = -4;
//	a2[1] = 2;
//	a2[2] = 8;
//	a2[4] = 8;
//	a2[5] = 8;
//	a2[6] = 8;
//
//	print_arr(a2, "a2");
//
//	a2 = a1;
//	print_arr(a2, "a2");
//
//	Safe_Array a3(0);
//	a2 = a3;
//	print_arr(a2, "a2");
//
//	//	a2[6] = 8;
//
//	a3.resize(0);
//	print_arr(a3, "a3");
//
//	a2.resize(a1.get_capacity());
//	a2[-1] = 4;
//	a2[-4] = 2;
//	a2[-3] = 8;
//	a2[-2] = 4;
//
//
//
//}

int main()
{
	test1();
	//	test2();
	cout << "Leaks: " << _CrtDumpMemoryLeaks() << endl;
	return 0;
}

//#include <iostream>
//#include "SafeArr.h"
//
//using namespace std;
//
//void inform_insert(Safe_Array& sa, int val, int ndx)
//{
//	if (sa.insert(val, ndx))
//		cout << "Insert data " << val << " in ndx " << ndx << endl;
//	else
//		cout << "Insert failed: Invalid ndx " << ndx << endl;
//}
//
//void inform_get(const Safe_Array& sa, int ndx, int& val)
//{
//	if (sa.get(ndx, val))
//		cout << "Got value " << val << " in ndx " << ndx << endl;
//	else
//		cout << "Get failed: Invalid ndx " << ndx << endl;
//}
//
//void inform_search(const Safe_Array& sa, int val, unsigned& ndx)
//{
//	if (sa.search(val, ndx))
//		cout << val << " found in ndx " << ndx << endl;
//	else
//		cout << val << " not found" << endl;
//}
//
//void test()
//{
//	Safe_Array a1(5);
//	inform_insert(a1, 1, 3);	
//	inform_insert(a1, 2, 0);
//	inform_insert(a1, 8, 1);
//	inform_insert(a1, 4, 2);
//	inform_insert(a1, 9, 4);
//	inform_insert(a1, 9, 5);
//
//	cout<<"a1: ";
//	a1.show();
//	cout << endl << "score=" << Safe_Array::score << endl;	
//
//	Safe_Array a2(a1);		// CC
//	cout << "a2: ";
//	a2.show();
//	cout << endl << "score=" << Safe_Array::score << endl;
//
//	Safe_Array a3;			// DC
//	cout << "a3 with DC; score=" << Safe_Array::score << endl;
//
//	Safe_Array& a4 = a3.assign(a1);
//	cout << "a3 after assign with a1: ";
//	a3.show();
//	cout << endl << "score=" << Safe_Array::score << endl;
//	cout << endl << "a4 after assign a3 with a1: ";
//	a4.show();
//	cout << endl << "score=" << Safe_Array::score << endl;
//	
//	a1.insert(7,1);
//	cout<<"change a1 after assign to a3:"<<endl<<"a1: ";
//	a1.show();
//	cout<<endl<<"a3: ";
//	a3.show();
//	cout<<endl<<endl;
//
//	int val;
//	inform_get(a1, 6, val);
//	inform_get(a1, 2, val);
//
//	unsigned ndx;
//	inform_search(a1, 4, ndx);
//	inform_search(a1, 5, ndx);
//
//	cout << "array of arrays: "<<endl;
//	Safe_Array s_arr[3] = {a1, a2, a3};		// 3 new arrys are constructed!
//	for (int i=0; i<3; i++)
//	{
//		s_arr[i].show();
//		cout<<endl;
//	}
//
//	cout <<"total num of bytes including array of arrays = "<<Safe_Array::score<<endl<<endl;
//
//	cout << "array of pointers to array: "<<endl;
//	Safe_Array* s_arr1[3] = {&a1, &a2, &a3};	// pointers to existing arrays. No additional Safe_Array objects
//	for (int i=0; i<3; i++)
//	{
//		s_arr1[i]->show();
//		cout<<endl;
//	}
//
//	cout <<"total num of bytes including array of pointers = "<<Safe_Array::score<<endl<<endl;
//
//	a1.resize(a1.get_capacity() - 2);
//	cout << "a1 after decrement size by 2: ";
//	a1.show();
//	cout << endl << "score=" << Safe_Array::score << endl;
//
//	a2.resize(a2.get_capacity() + 3);
//	cout << "a2 after increment size by 3: ";
//	a2.show();
//	cout << endl << "score=" << Safe_Array::score << endl;
//
//	Safe_Array a5;
//	a5.resize(3);
//}
//
//int main()
//{
//	test();
//	_CrtDumpMemoryLeaks();
//	cout << "Leaks: " << _CrtDumpMemoryLeaks() << endl;
//	return 0;
//}