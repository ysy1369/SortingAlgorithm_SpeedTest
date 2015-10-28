#include "ArraySetter.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
//INPUT INT TYPE TEST CASE METHOD
//////////////////////////////////////////////////////////////////////////////////////////////////////

/* int �� RANDOM TEST CASE */
void ArraySetter::setRandomTestCase(int*& arr, int arrSize)
{
	if(arr != NULL) { delete arr; arr=NULL; }	//�����Ҷ� �޸� ������ ����

	arr = new int[arrSize];

	srand((unsigned)time(NULL));	//RANDOM ������ �Է�
	for(int i=0 ; i<arrSize ;i++)		
	{
		arr[i] = rand()%arrSize;
	}
	//typeid(T) == typeid(int)
}

/* int �� �������� TEST CASE */
void ArraySetter::setIncreaseOrderTestCase(int*& arr, int arrSize)
{
	if(arr != NULL) { delete arr; arr=NULL; }	//�����Ҷ� �޸� ������ ����

	arr = new int[arrSize];

	for(int i=0 ; i<arrSize ;i++)	//�������� ������ �Է�
	{
		arr[i] = i;
	}
}

/* int �� �������� TEST CASE */
void ArraySetter::setDecreaseOrderTestCase(int*& arr, int arrSize)
{
	if(arr != NULL) { delete arr; arr=NULL; }	//�����Ҷ� �޸� ������ ����

	arr = new int[arrSize];

	for(int i=arrSize-1 ; i>=0 ;i--)	//�������� ������ �Է�
	{
		arr[i] = arrSize-i;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//INPUT DOUBLE TYPE TEST CASE METHOD
//////////////////////////////////////////////////////////////////////////////////////////////////////

/* double �� RANDOM TEST CASE */
void ArraySetter::setRandomTestCase(double*& arr, int arrSize)
{
	if(arr != NULL) { delete arr; arr=NULL; }	//�����Ҷ� �޸� ������ ����

	arr = new double[arrSize];

	srand((unsigned)time(NULL));	//RANDOM ������ �Է�
	for(int i=0 ; i<arrSize ;i++)		
	{
		arr[i] = rand()/arrSize;
	}
	//typeid(T) == typeid(int)
}

/* double �� �������� TEST CASE */
void ArraySetter::setIncreaseOrderTestCase(double*& arr, int arrSize)
{
	if(arr != NULL) { delete arr; arr=NULL; }	//�����Ҷ� �޸� ������ ����

	arr = new double[arrSize];

	for(int i=0 ; i<arrSize ;i++)	//�������� ������ �Է�
	{
		arr[i] = i;
	}
}

/* double �� �������� TEST CASE */
void ArraySetter::setDecreaseOrderTestCase(double*& arr, int arrSize)
{
	if(arr != NULL) { delete arr; arr=NULL; }	//�����Ҷ� �޸� ������ ����

	arr = new double[arrSize];

	for(int i=arrSize-1 ; i>=0 ;i--)	//�������� ������ �Է�
	{
		arr[i] = arrSize-i;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//INPUT RECTANGLE TYPE TEST CASE METHOD
//////////////////////////////////////////////////////////////////////////////////////////////////////

/* Rectangle �� RANDOM TEST CASE */
void ArraySetter::setRandomTestCase(Rectangle*& arr, int arrSize)
{
	if(arr != NULL) { delete[] arr; arr=NULL; }	//�����Ҷ� �޸� ������ ����

	arr = new Rectangle[arrSize];

	srand((unsigned)time(NULL));	//RANDOM ������ �Է�
	for(int i=0 ; i<arrSize ;i++)		
	{
		double width = rand()/arrSize;
		double height = rand()/arrSize;
		arr[i] = Rectangle(width, height);
	}
}

/* Rectangle �� �������� TEST CASE */
void ArraySetter::setIncreaseOrderTestCase(Rectangle*& arr, int arrSize)
{
	if(arr != NULL) { delete[] arr; arr=NULL; }	//�����Ҷ� �޸� ������ ����

	arr = new Rectangle[arrSize];

	for(int i=0 ; i<arrSize ;i++)	//�������� ������ �Է�
	{
		arr[i] = Rectangle(1,i);
	}
}

/* Rectangle �� �������� TEST CASE */
void ArraySetter::setDecreaseOrderTestCase(Rectangle*& arr, int arrSize)
{
	if(arr != NULL) { delete[] arr; arr=NULL; }	//�����Ҷ� �޸� ������ ����

	arr = new Rectangle[arrSize];

	for(int i=arrSize-1 ; i>=0 ;i--)	//�������� ������ �Է�
	{
		arr[i] = Rectangle(1,arrSize-i);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
								//INPUT STRING TYPE TEST CASE METHOD
//////////////////////////////////////////////////////////////////////////////////////////////////////

/* string �� RANDOM TEST CASE */
void ArraySetter::setRandomTestCase(string*& arr, int arrSize)
{
	if(arr != NULL) { delete[] arr; arr=NULL; }	//�����Ҷ� �޸� ������ ����

	arr = new string[arrSize];

	int strLength = 0;

	for(int i = 0; i < arrSize; i++)
	{
		strLength = 0;

		while(strLength == 0)
			strLength = rand() % 10; // string ���̴� 10������ ����

		arr[i] = "";

		for(int k = 0; k < strLength; k++) 
		{
			// A~Z������ ����
			arr[i] += (char)(rand()%25 + 65);
		}
	}
}
/* string �� �������� TEST CASE */
void ArraySetter::setIncreaseOrderTestCase(string*& arr, int arrSize)
{
	//if(arr != NULL) { delete[] arr; arr=NULL; }	//�����Ҷ� �޸� ������ ����

	//arr = new string[arrSize];

	//for(int i=0; i< arrSize ;i++)
	//{
	//	arr[i] = dectoA(i);
	//}
	if(arr != NULL) { delete[] arr; arr=NULL; }	//�����Ҷ� �޸� ������ ����
	arr = new string[arrSize];

	ifstream fin;
	fin.open("IncreaseTestCase.txt" ,ios_base::in);
	
	for(int i=0; i< arrSize ;i++)
	{
		fin >> arr[i];
	}
	fin.close();
}

/* string �� �������� TEST CASE */
void ArraySetter::setDecreaseOrderTestCase(string*& arr, int arrSize)
{
	if(arr != NULL) { delete[] arr; arr=NULL; }	//�����Ҷ� �޸� ������ ����
	arr = new string[arrSize];

	ifstream fin;
	fin.open("IncreaseTestCase.txt" ,ios_base::in);
	
	for(int i=arrSize-1 ; i>=0 ;i--)	
	{
		fin >> arr[i];
	}
	fin.close();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
						// "PRIVATE METHOD" FOR INPUT STRING TYPE TEST CASE METHOD
//////////////////////////////////////////////////////////////////////////////////////////////////////

/* 10���� -> 26������ ��ȯ�Ѵٰ� �����ϰ� ����*/
string ArraySetter::dectoA(int n)
{
	string str="";
    char result[20];
    int index=0;
    int q,r;
    int i;
 
    do{
        q=n/26;
        r=n%26;
        result[index] = r+'A';
        index++;
        n=q;
    }while(q>=26);
 
	result[index]=q+'A';
 
	for(i=index; i>=0; i--)
	{
        str += result[i];
    }
	return str;
}