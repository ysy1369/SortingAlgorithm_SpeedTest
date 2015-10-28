#include "ArraySetter.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
//INPUT INT TYPE TEST CASE METHOD
//////////////////////////////////////////////////////////////////////////////////////////////////////

/* int 형 RANDOM TEST CASE */
void ArraySetter::setRandomTestCase(int*& arr, int arrSize)
{
	if(arr != NULL) { delete arr; arr=NULL; }	//재사용할때 메모리 관리를 위해

	arr = new int[arrSize];

	srand((unsigned)time(NULL));	//RANDOM 정수값 입력
	for(int i=0 ; i<arrSize ;i++)		
	{
		arr[i] = rand()%arrSize;
	}
	//typeid(T) == typeid(int)
}

/* int 형 오름차순 TEST CASE */
void ArraySetter::setIncreaseOrderTestCase(int*& arr, int arrSize)
{
	if(arr != NULL) { delete arr; arr=NULL; }	//재사용할때 메모리 관리를 위해

	arr = new int[arrSize];

	for(int i=0 ; i<arrSize ;i++)	//오름차순 정수값 입력
	{
		arr[i] = i;
	}
}

/* int 형 내림차순 TEST CASE */
void ArraySetter::setDecreaseOrderTestCase(int*& arr, int arrSize)
{
	if(arr != NULL) { delete arr; arr=NULL; }	//재사용할때 메모리 관리를 위해

	arr = new int[arrSize];

	for(int i=arrSize-1 ; i>=0 ;i--)	//내림차순 정수값 입력
	{
		arr[i] = arrSize-i;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//INPUT DOUBLE TYPE TEST CASE METHOD
//////////////////////////////////////////////////////////////////////////////////////////////////////

/* double 형 RANDOM TEST CASE */
void ArraySetter::setRandomTestCase(double*& arr, int arrSize)
{
	if(arr != NULL) { delete arr; arr=NULL; }	//재사용할때 메모리 관리를 위해

	arr = new double[arrSize];

	srand((unsigned)time(NULL));	//RANDOM 정수값 입력
	for(int i=0 ; i<arrSize ;i++)		
	{
		arr[i] = rand()/arrSize;
	}
	//typeid(T) == typeid(int)
}

/* double 형 오름차순 TEST CASE */
void ArraySetter::setIncreaseOrderTestCase(double*& arr, int arrSize)
{
	if(arr != NULL) { delete arr; arr=NULL; }	//재사용할때 메모리 관리를 위해

	arr = new double[arrSize];

	for(int i=0 ; i<arrSize ;i++)	//오름차순 정수값 입력
	{
		arr[i] = i;
	}
}

/* double 형 내림차순 TEST CASE */
void ArraySetter::setDecreaseOrderTestCase(double*& arr, int arrSize)
{
	if(arr != NULL) { delete arr; arr=NULL; }	//재사용할때 메모리 관리를 위해

	arr = new double[arrSize];

	for(int i=arrSize-1 ; i>=0 ;i--)	//내림차순 정수값 입력
	{
		arr[i] = arrSize-i;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//INPUT RECTANGLE TYPE TEST CASE METHOD
//////////////////////////////////////////////////////////////////////////////////////////////////////

/* Rectangle 형 RANDOM TEST CASE */
void ArraySetter::setRandomTestCase(Rectangle*& arr, int arrSize)
{
	if(arr != NULL) { delete[] arr; arr=NULL; }	//재사용할때 메모리 관리를 위해

	arr = new Rectangle[arrSize];

	srand((unsigned)time(NULL));	//RANDOM 정수값 입력
	for(int i=0 ; i<arrSize ;i++)		
	{
		double width = rand()/arrSize;
		double height = rand()/arrSize;
		arr[i] = Rectangle(width, height);
	}
}

/* Rectangle 형 오름차순 TEST CASE */
void ArraySetter::setIncreaseOrderTestCase(Rectangle*& arr, int arrSize)
{
	if(arr != NULL) { delete[] arr; arr=NULL; }	//재사용할때 메모리 관리를 위해

	arr = new Rectangle[arrSize];

	for(int i=0 ; i<arrSize ;i++)	//오름차순 정수값 입력
	{
		arr[i] = Rectangle(1,i);
	}
}

/* Rectangle 형 내림차순 TEST CASE */
void ArraySetter::setDecreaseOrderTestCase(Rectangle*& arr, int arrSize)
{
	if(arr != NULL) { delete[] arr; arr=NULL; }	//재사용할때 메모리 관리를 위해

	arr = new Rectangle[arrSize];

	for(int i=arrSize-1 ; i>=0 ;i--)	//내림차순 정수값 입력
	{
		arr[i] = Rectangle(1,arrSize-i);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
								//INPUT STRING TYPE TEST CASE METHOD
//////////////////////////////////////////////////////////////////////////////////////////////////////

/* string 형 RANDOM TEST CASE */
void ArraySetter::setRandomTestCase(string*& arr, int arrSize)
{
	if(arr != NULL) { delete[] arr; arr=NULL; }	//재사용할때 메모리 관리를 위해

	arr = new string[arrSize];

	int strLength = 0;

	for(int i = 0; i < arrSize; i++)
	{
		strLength = 0;

		while(strLength == 0)
			strLength = rand() % 10; // string 길이는 10이하의 랜덤

		arr[i] = "";

		for(int k = 0; k < strLength; k++) 
		{
			// A~Z까지만 설정
			arr[i] += (char)(rand()%25 + 65);
		}
	}
}
/* string 형 오름차순 TEST CASE */
void ArraySetter::setIncreaseOrderTestCase(string*& arr, int arrSize)
{
	//if(arr != NULL) { delete[] arr; arr=NULL; }	//재사용할때 메모리 관리를 위해

	//arr = new string[arrSize];

	//for(int i=0; i< arrSize ;i++)
	//{
	//	arr[i] = dectoA(i);
	//}
	if(arr != NULL) { delete[] arr; arr=NULL; }	//재사용할때 메모리 관리를 위해
	arr = new string[arrSize];

	ifstream fin;
	fin.open("IncreaseTestCase.txt" ,ios_base::in);
	
	for(int i=0; i< arrSize ;i++)
	{
		fin >> arr[i];
	}
	fin.close();
}

/* string 형 내림차순 TEST CASE */
void ArraySetter::setDecreaseOrderTestCase(string*& arr, int arrSize)
{
	if(arr != NULL) { delete[] arr; arr=NULL; }	//재사용할때 메모리 관리를 위해
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

/* 10진수 -> 26진수로 변환한다고 생각하고 구현*/
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