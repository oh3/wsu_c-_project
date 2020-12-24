//start.cpp

#include <iostream>
using namespace std;
#include "accmanager.h"

class CompareByIntP
{
	int number;
public:
	CompareByIntP(int _number) : number(_number) {}
	
	bool operator()(int* value)
	{
		return (*value == number);
	}
};

class Data
{
	int number;
	char name[20];
	char juso[200];
public:
	Data(int n, const char* _name, const char* _juso) : number(n)
	{
		strcpy_s(name, sizeof(name), _name);
		strcpy_s(juso, sizeof(juso), _juso);
	}

	int GetNumber() const		{ return number;	}
	const char* GetName() const { return name;		}
	const char* GetJuso() const { return juso; }

	void print() const
	{
		cout << name << "," << number << "," << juso << endl;
	}
};


class CompareByNumber	//���� ��� number
{
	int number;
public:
	//���� ���� �����ڸ� ���� ���޹޾� �ɹ������� ����
	CompareByNumber(int _number) : number(_number) {}

	//find_if���� �ݺ������� ȣ��Ǵ� �κ�
	//vector<Data*> �� ������� �ֱ� ������ �̶� ���޵Ǵ� Ÿ����
	//Data*
	bool operator()(Data* value)
	{
		return (value->GetNumber() == number);
	}
};

class CompareByName	//���� ��� name
{
	char name[20];
public:
	//���� ���� �����ڸ� ���� ���޹޾� �ɹ������� ����
	CompareByName(const char* _name)
	{
		strcpy_s(name, sizeof(name), _name);
	}

	//find_if���� �ݺ������� ȣ��Ǵ� �κ�
	//vector<Data*> �� ������� �ֱ� ������ �̶� ���޵Ǵ� Ÿ����
	//Data*
	bool operator()(Data* value)
	{
		return ( strcmp(value->GetName(), name) == 0);
	}
};

int main()
{

	accManager* sm = new accManager();
	sm->Run();
	delete sm;	

	return 0;
}