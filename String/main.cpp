#include<iostream>
#include"String.h"
using namespace std;


//#define CONSTRUCTORS_CHECK
#define METHODS_CHECK
#define MOVE_METHODS
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1;			//Default constructor
	str1.print();
	//Single-argimen constructor;
/*	String str2 = 16;*/		//explicit constructor  ���������� ������� ���������� ���������.
	String str2(16);		//��� ����� ������� ������ ���.
	str2.print();

	//������ ��� ����� �������
	String str3 = "Hello";
	str3.print();
	String str4;
	str4 = str3;
	str4.print();

#endif // 
#ifdef METHODS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	//String str3 = str1 + str2;
	/*String str3;
	str3 = str1 + str2;
	cout << str1 << "+" << str2 << " = " << str3 << endl;*/
	str1 += str2;
	cout << str1 << endl;
	String str3;
	String str4;
	cout << "������� ������: ";
	cin >> str3 >> str4;
	cout << "\t" << str3 << str4 << endl;
#endif // METHODS_CHECK
//			Move-methods:
		//  Move constructor
		//  Move assignment
		//  R-value reference (Class&& obj)
#ifdef MOVE_METHODS

#endif // MOVE_METHODS


}