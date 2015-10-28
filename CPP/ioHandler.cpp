#include "ioHandler.h"

bool ioHandler::cinFailCheck()
{
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(1);
		cout << "�߸��Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ�."<<endl;
		
		return true;
	}
	return false;
}
int ioHandler::selectType()
{
	int type =0;
	cout << "========================================="<< endl;
	cout << " <<  SORT�� ���� �ڷ���(type) ����  >> "<< endl;
	cout << "========================================="<< endl;
	cout << "[1]  int(����)�� "                        << endl;
	cout << "[2]  double(�Ǽ�)�� "                     << endl;
	cout << "[3]  �簢�� ����(Rectangle)"              << endl;
	cout << "[4]  string(���ڿ�)�� "                   << endl;
	cout << "[5]  ������(EXIT) "                       << endl;
	cout << "========================================="<< endl;
	cout << "���� >> ";
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
	cout << "[1]  ǥ�� ��� Quick Sort "               << endl;
	cout << "[2]  ǥ�� Non_��� Quick Sort "           << endl;
	cout << "[3]  Median of Three ��� Quick Sort"     << endl;
	cout << "[4]  Median of Three Non_��� Quick Sort "<< endl;
	cout << "[5]  STL Quick Sort "                     << endl;
	cout << "[6]  ��� Merge Sort "                    << endl;
	cout << "[7]  Non_��� Merge Sort "                << endl;
	cout << "[8]  Natural Merge Sort "                 << endl;
	cout << "[9]  �̿���������(Binary Insertion Sort) "<< endl;
	cout << "[10]  �����������(Linked Insertion Sort)"<< endl;
	cout << "[11] �� ���� (Heap Sort) "                << endl;
	cout << "[12] ���� ���� (Bubble Sort) "            << endl;
	cout << "[13] ���� ���� (Selection Sort) "         << endl;
	cout << "[14] ������(EXIT) "                       << endl;
	cout << "========================================="<< endl;
	cout << "���� >> ";
	cin >> select;

	if(cinFailCheck())
		select = ERROR;

	return select;
}

//int ioHandler::setTestSize()
//{
//	int size;
//	cout << "�� ���� Test Case�� �����ðڽ��ϱ�?"<< endl;
//	cout << "�Է� >> ";
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
	cout <<"�Է� >> ";
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
		cout << " << ǥ�� ��� Quick Sort >> " << endl; 
		break;
	case STANDARD_NON_RECURSIVE_QUICSORT:  
		cout << " << ǥ�� Non_��� Quick Sort >> "<< endl;
		break;
	case MEDIAN_3_RECURSIVE_QUICKSORT:
		cout << " << Median of Three ��� Quick Sort >> " << endl;
		break;
	case MEDIAN_3_NON_RECURSIVE_QUICKSORT:
		cout << " << Median of Three Non_��� Quick Sort >> "<< endl;
		break;
	case STL_QUICKSORT:
		cout << " << STL Quick Sort >> "<<endl;
		break;
/*MERGE SORT*/
	case RECURSIVE_MERGE:
		cout << " << ��� Merge Sort >> " << endl;
		break;
	case NON_RECURSIVE_MERGE:
		cout << " << Non_��� Merge Sort >> " << endl;
		break;
	case NATURAL_MERGE:
		cout << " << Natural Merge Sort >> " << endl;
		break;
/*INSERTION SORT*/
	case BINARY_INSERTION:
		cout << " << �̿���������(Binary Insertion Sort) >> "<<endl;
		break;
	case LINKED_INSERTION:
		cout << " << �����������(Linked Insertion Sort) >> "<<endl;
		break;
/*OTHER SORTS*/
	case HEAP_SORT:
		cout << " << �� ���� (Heap Sort) >> " <<endl;
		break;
	case BUBBLE_SORT:
		cout << " << ���� ���� (Bubble Sort) >> " <<endl;
		break;
	case SELECTION_SORT:
		cout << " << ���� ���� (Selection Sort) >> " <<endl;
		break;
/*����*/
	default:
		cout << "<< �ٽ� �Է��� �ֽʽÿ�!! >> " << endl;
		break;
	}
}
void ioHandler::outputTimeTable(int testCaseSize[], double timeTable[])
{
	cout <<"======================================="<<endl;
	cout <<" �Է� ������ ���� "<<" ����ð�" << endl;
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