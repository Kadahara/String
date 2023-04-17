#include<iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;	//������ ������ � ������
	char* str;	//����� ������ � ������������ ������
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

	//			Constructors:
	explicit String(int size = 256) :size(size), str(new char[size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "Default1ArgConstruct:\t" << this << endl;
	}
	String(const char* str) :String(strlen(str) + 1)//���������� ��������� ������ ������������ �� ���������
	{
		//this->size = strlen(str) + 1;
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other) :String(other.str)
	{
		//Deep copy (��������� �����������):
		//this->size = other.size;
		//this->str = new char[size] {};
		//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other) :size(other.size), str(other.str)
	{
		//Shallow copy (������������� �����������):
		//this->size = other.size;
		//this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destrutor:\t\t" << this << endl;
	}
	//			Operators:
	String& operator=(const String& other)
	{
		//Deep copy (��������� �����������):
		int a = 2;
		int b = 3;
		a = b;

		//0) ���������, �� �������� �� �������� ������ ����� ��������:
		if (this == &other)return *this;

		//1) ������� ������ ������:
		delete[] this->str;

		//2) ��������� ��������� �����������:
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		//Shallow copy (������������� �����������):
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignemtn:\t\t" << this << endl;
	}

	//				Operators:
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}


	//			Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	//os - Output Stream
	//obj - Object
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)
{
	//is - Input Stream
	const int SIZE = 102400;
	char buffer[SIZE]{};
	is >> buffer;
	obj = buffer;
	return is;// >> obj.get_str();
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