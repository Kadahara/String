#include<iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;			//Размер строки в байтах
	char* str;			//Адрес строки в динамической памяти

public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//
	explicit String(int size = 256)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Default1AtgConstruct:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		cout << std::left << "Constructor:" << this << endl;
	}
	~String()
	{
		delete[] this->str;
	}

	//Methods;
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str " << str << endl;
	}
};
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	String sum(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		sum.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		sum.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return sum;
}
//#define CONSTRUCTORS_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1;			//Default constructor
	str1.print();
	//Single-argimen constructor;
/*	String str2 = 16;*/		//explicit constructor  невозможно вызвать оператором присвоить.
	String str2(16);		//Его можно вызвать только так.
	str2.print();

	//Узнать что такое литерал
	String str3 = "Hello";
	str3.print();
#endif // 
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str1 << "+" << str2 << " = " << str3 << endl;

}