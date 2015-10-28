#include "TaskManager.h"

template <class T>
int TaskManager<T>::startTask()
{
	Tester<T> tester;
	ioHandler io;
	ArraySetter as;

	int testCaseSize[5] ={5,10, 5000, 10000, 20000};	//TEST CASE SIZE 입력 배열

	double timeTable[5] = {NOT_SORTED, NOT_SORTED, NOT_SORTED, NOT_SORTED, NOT_SORTED};	
	int timeCount=0;

	int select = io.getMenu();	//Testing 할 정렬의 종류 선택
	if(select < STANDARD_RECURSIVE_QUICKSORT || EXIT <=select ) return EXIT;

	int testCase = io.selectTestCase();	//TestCase의 종류 선택(랜덤, 오름차순, 내림차순)
				
	for(int i=0 ; i<5 ;i++)	//TestCase 의 사이즈 입력
	{
		int n = testCaseSize[i]; 
		tester.setSize(n);

		switch(testCase)
		{
		case RANDOM:
			as.setRandomTestCase(tester.getArr(),n);	//TestCase 의 사이즈 만큼 랜덤 값 입력
			break;
		case INCREASE:
			as.setIncreaseOrderTestCase(tester.getArr(),n);//TestCase 의 사이즈 만큼 오름차순 값 입력
			break;
		case DECREASE:
			as.setDecreaseOrderTestCase(tester.getArr(),n);//TestCase 의 사이즈 만큼 내림차순 값 입력
			break;
		default:
			break;
		}

		cout <<" Sorting ..." <<endl <<endl;	

		switch(select)
		{
	/*QUICK SORT*/
		case STANDARD_RECURSIVE_QUICKSORT:
			tester.reQuickSortTest(timeTable, timeCount);
			break;
		case STANDARD_NON_RECURSIVE_QUICSORT:  
			tester.iterQuickSortTest(timeTable, timeCount);
			break;
		case MEDIAN_3_RECURSIVE_QUICKSORT:
			tester.median3_reQuickSortTest(timeTable, timeCount);
			break;
		case MEDIAN_3_NON_RECURSIVE_QUICKSORT:
			tester.median3_iterQuickSortTest(timeTable, timeCount);
			break;
		case STL_QUICKSORT:
			tester.STLQuickSortTest(timeTable, timeCount);
			break;
	/*MERGE SORT*/
		case RECURSIVE_MERGE:
			tester.recursiveMergeTest(timeTable, timeCount);
			break;
		case NON_RECURSIVE_MERGE:
			tester.nonRecursiveMergeTest(timeTable, timeCount);
			break;
		case NATURAL_MERGE:
			tester.naturalMergeTest(timeTable, timeCount);
			break;
	/*INSERTION SORT*/
		case BINARY_INSERTION:
			tester.binaryInsertionSortTest(timeTable, timeCount);
			break;
		case LINKED_INSERTION:
			tester.linkedInsertionSortTest(timeTable, timeCount);
			break;
	/*OTHER SORTS*/
		case HEAP_SORT:
			tester.heapSortTest(timeTable, timeCount);
			break;
		case BUBBLE_SORT:
			tester.bubbleSortTest(timeTable, timeCount);
			break;
		case SELECTION_SORT:
			tester.selectionSortTest(timeTable, timeCount);
			break;
	/*예외*/
		default:
			break;
		}
		system("cls");
		io.outputName(select);
		io.outputTimeTable(testCaseSize, timeTable);
		
	}//End of for loop
	
	cout <<"Sorting Complete!!"<<endl;
	system("pause");
	system("cls");

	return CONTINUE;
}