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

	//			Constructor
	explicit String(int size = 256) 
	{
		//this->size = size;
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
		cout << std::left << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructors:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << std::left << "Destructor:\t\t" << this << endl;
	}
	//			Operators:
	String& operator=(const String& other)
	{
		//0) Проверяем, не является ли принятый параметр нашим обьектом
		if (this == &other)return *this;
		//1) Удаляем старую строку
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignemtn:\t\t" << this << endl;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	//			Methods;
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str " << str << endl;
	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}

};
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)
{
	const int SIZE = 102400;
	char buffer[SIZE]{};
	is >> buffer;
	obj = buffer;
	return is;
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
#define METHODS_CHECK
#define MOVE_METHODS
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
	cout << "Введите строку: ";
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