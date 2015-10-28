#include "ioHandler.h"

bool ioHandler::cinFailCheck()
{
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(1);
		cout << "잘못입력하셨습니다. 다시 입력하십시오."<<endl;
		
		return true;
	}
	return false;
}
int ioHandler::selectType()
{
	int type =0;
	cout << "========================================="<< endl;
	cout << " <<  SORT에 사용될 자료형(type) 선택  >> "<< endl;
	cout << "========================================="<< endl;
	cout << "[1]  int(정수)형 "                        << endl;
	cout << "[2]  double(실수)형 "                     << endl;
	cout << "[3]  사각형 면적(Rectangle)"              << endl;
	cout << "[4]  string(문자열)형 "                   << endl;
	cout << "[5]  나가기(EXIT) "                       << endl;
	cout << "========================================="<< endl;
	cout << "선택 >> ";
	cin>> type;
	
	if(cinFailCheck())
		type = ERROR;
	return type;
}
int ioHandler::getMenu()
{
	int select =0;
	cout << "========================================="<< endl;
	cout << "             <<  SORT TEST  >>           "<< endl;
	cout << "========================================="<< endl;
	cout << "[1]  표준 재귀 Quick Sort "               << endl;
	cout << "[2]  표준 Non_재귀 Quick Sort "           << endl;
	cout << "[3]  Median of Three 재귀 Quick Sort"     << endl;
	cout << "[4]  Median of Three Non_재귀 Quick Sort "<< endl;
	cout << "[5]  STL Quick Sort "                     << endl;
	cout << "[6]  재귀 Merge Sort "                    << endl;
	cout << "[7]  Non_재귀 Merge Sort "                << endl;
	cout << "[8]  Natural Merge Sort "                 << endl;
	cout << "[9]  이원삽입정렬(Binary Insertion Sort) "<< endl;
	cout << "[10]  연결삽입정렬(Linked Insertion Sort)"<< endl;
	cout << "[11] 힙 정렬 (Heap Sort) "                << endl;
	cout << "[12] 버블 정렬 (Bubble Sort) "            << endl;
	cout << "[13] 선택 정렬 (Selection Sort) "         << endl;
	cout << "[14] 나가기(EXIT) "                       << endl;
	cout << "========================================="<< endl;
	cout << "선택 >> ";
	cin >> select;

	if(cinFailCheck())
		select = ERROR;

	return select;
}

//int ioHandler::setTestSize()
//{
//	int size;
//	cout << "몇 개의 Test Case를 넣으시겠습니까?"<< endl;
//	cout << "입력 >> ";
//	cin >> size;
//
//	if(cinFailCheck())
//		size = ERROR;
//
//	return size;
//}

void ioHandler::setTime(double timeTable[], int& timeCount, double time)
{
	timeTable[timeCount++] = time;
}

int ioHandler::selectTestCase()
{
	int testCase;
	cout <<"=================================" << endl;
	cout <<"[1] Random Value Input "           << endl;
	cout <<"[2] Increase Order Value Input "   << endl;
	cout <<"[3] Decrease Order Value Input "   << endl;
	cout <<"=================================" << endl;
	cout <<"입력 >> ";
	cin >> testCase;

	if(cinFailCheck())
		testCase = ERROR;

	return testCase;
}
void ioHandler::outputName(int sort)
{
	switch(sort)
	{
/*QUICK SORT*/
	case STANDARD_RECURSIVE_QUICKSORT:
		cout << " << 표준 재귀 Quick Sort >> " << endl; 
		break;
	case STANDARD_NON_RECURSIVE_QUICSORT:  
		cout << " << 표준 Non_재귀 Quick Sort >> "<< endl;
		break;
	case MEDIAN_3_RECURSIVE_QUICKSORT:
		cout << " << Median of Three 재귀 Quick Sort >> " << endl;
		break;
	case MEDIAN_3_NON_RECURSIVE_QUICKSORT:
		cout << " << Median of Three Non_재귀 Quick Sort >> "<< endl;
		break;
	case STL_QUICKSORT:
		cout << " << STL Quick Sort >> "<<endl;
		break;
/*MERGE SORT*/
	case RECURSIVE_MERGE:
		cout << " << 재귀 Merge Sort >> " << endl;
		break;
	case NON_RECURSIVE_MERGE:
		cout << " << Non_재귀 Merge Sort >> " << endl;
		break;
	case NATURAL_MERGE:
		cout << " << Natural Merge Sort >> " << endl;
		break;
/*INSERTION SORT*/
	case BINARY_INSERTION:
		cout << " << 이원삽입정렬(Binary Insertion Sort) >> "<<endl;
		break;
	case LINKED_INSERTION:
		cout << " << 연결삽입정렬(Linked Insertion Sort) >> "<<endl;
		break;
/*OTHER SORTS*/
	case HEAP_SORT:
		cout << " << 힙 정렬 (Heap Sort) >> " <<endl;
		break;
	case BUBBLE_SORT:
		cout << " << 버블 정렬 (Bubble Sort) >> " <<endl;
		break;
	case SELECTION_SORT:
		cout << " << 선택 정렬 (Selection Sort) >> " <<endl;
		break;
/*예외*/
	default:
		cout << "<< 다시 입력해 주십시오!! >> " << endl;
		break;
	}
}
void ioHandler::outputTimeTable(int testCaseSize[], double timeTable[])
{
	cout <<"======================================="<<endl;
	cout <<" 입력 데이터 갯수 "<<" 수행시간" << endl;
	cout <<"---------------------------------------"<<endl;
	for(int i=0, n=100 ; i<5 ; i++, n*=10)
	{
		cout <<"\t"<< testCaseSize[i] <<"\t\t";
		if(timeTable[i] != NOT_SORTED)
			cout<< timeTable[i] <<"\t"<<endl;
		else
			cout<< "[ Not Yet ]" << endl;
	}
	cout <<"======================================="<<endl;
}