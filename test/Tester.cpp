#include "Tester.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////
								//QUICK SORT TEST METHOD
//////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Tester<T>::reQuickSortTest(double TimeTable[], int& timeCount) // [1]
{// 표준 재귀 퀵소트 TEST
	QuickSort<T> quick;
	ioHandler io;
	clock_t begin, end;

	begin = clock();
	quick.reQuickSort(arr,0,size-1);
	end =  clock();

	io.setTime(TimeTable,timeCount, ((double)(end - begin))/CLOCKS_PER_SEC);
}

template <class T>
void Tester<T>::iterQuickSortTest(double TimeTable[], int& timeCount) // [2]
{// 표준 반복 퀵소트 TEST
	QuickSort<T> quick;
	ioHandler io;
	clock_t begin, end;

	begin = clock();
	quick.iterQuickSort(arr, 0, size-1);
	end =  clock();

	io.setTime(TimeTable,timeCount, ((double)(end - begin))/CLOCKS_PER_SEC);
}

template <class T>
void Tester<T>::median3_reQuickSortTest(double TimeTable[], int& timeCount) // [3]
{//중간값(메디안) 재귀 퀵소트 TEST
	QuickSort<T> quick;
	ioHandler io;
	clock_t begin, end;

	begin = clock();
	quick.median3_reQuickSort(arr,0,size-1);
	end =  clock();

	io.setTime(TimeTable,timeCount, ((double)(end - begin))/CLOCKS_PER_SEC);
}

template <class T>
void Tester<T>::median3_iterQuickSortTest(double TimeTable[], int& timeCount) // [4]
{//중간값(메디안) 반복 퀵소트 TEST
	QuickSort<T> quick;
	ioHandler io;
	clock_t begin, end;

	begin = clock();
	quick.median3_iterQuickSort(arr, 0, size-1);
	end =  clock();

	io.setTime(TimeTable,timeCount, ((double)(end - begin))/CLOCKS_PER_SEC);
}	

template <class T>
void Tester<T>::STLQuickSortTest(double TimeTable[], int& timeCount) // [5]
{//STL 퀵소트 TEST
	QuickSort<T> quick;
	ioHandler io;
	clock_t begin, end;

	begin = clock();
	quick.STLQuickSort(arr, size);
	end =  clock();

	io.setTime(TimeTable,timeCount, ((double)(end - begin))/CLOCKS_PER_SEC);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
								//MERGE SORT TEST METHOD
//////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Tester<T>::recursiveMergeTest(double TimeTable[], int& timeCount) // [6]
{//재귀 합병 정렬 TEST
	Merge<T> mg;
	ioHandler io;
	clock_t begin, end;

	begin = clock();
	mg.recursiveMerge(arr,size);
	end =  clock();

	io.setTime(TimeTable,timeCount, ((double)(end - begin))/CLOCKS_PER_SEC);
}

template <class T>
void Tester<T>::nonRecursiveMergeTest(double TimeTable[], int& timeCount) // [7]
{//반복 합병 정렬 TEST
	Merge<T> mg;
	ioHandler io;
	clock_t begin, end;

	begin = clock();
	mg.nonrecursiveMerge(arr,size);
	end =  clock();

	io.setTime(TimeTable,timeCount, ((double)(end - begin))/CLOCKS_PER_SEC);
}

template <class T>
void Tester<T>::naturalMergeTest(double TimeTable[], int& timeCount) // [7]
{//반복 합병 정렬 TEST
	Merge<T> mg;
	ioHandler io;
	clock_t begin, end;

	begin = clock();
	mg.naturalMerge(arr,size-1);
	end =  clock();

	io.setTime(TimeTable,timeCount, ((double)(end - begin))/CLOCKS_PER_SEC);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
								//INSERTION SORT TEST METHOD
//////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Tester<T>::binaryInsertionSortTest(double TimeTable[], int& timeCount) // [9]
{//이원 삽입 정렬 TEST
	InsertionSort<T> insertion;
	ioHandler io;
	clock_t begin, end;

	begin = clock();
	insertion.binaryInsertionSort(arr,size);
	end =  clock();

	io.setTime(TimeTable,timeCount, ((double)(end - begin))/CLOCKS_PER_SEC);
}
template <class T>
void Tester<T>::linkedInsertionSortTest(double TimeTable[], int& timeCount)
{//연결 삽입 정렬 TEST
	InsertionSort<T> insertion;
	ioHandler io;
	clock_t begin, end;

	begin = clock();
	insertion.linkedInsertionSort(arr,size);
	end =  clock();

	io.setTime(TimeTable,timeCount, ((double)(end - begin))/CLOCKS_PER_SEC);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
								//OTHER SORTS TEST METHOD
//////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Tester<T>::selectionSortTest(double TimeTable[], int& timeCount)
{//선택 정렬 TEST
	OtherSorts<T> os;
	ioHandler io;
	clock_t begin, end;

	begin = clock();
	os.selectionSort(arr,size);
	end =  clock();

	io.setTime(TimeTable,timeCount, ((double)(end - begin))/CLOCKS_PER_SEC);
}

template <class T>
void Tester<T>::bubbleSortTest(double TimeTable[], int& timeCount)
{
	OtherSorts<T> os;
	ioHandler io;
	clock_t begin, end;

	begin = clock();
	os.bubbleSort(arr,size);
	end =  clock();

	io.setTime(TimeTable,timeCount, ((double)(end - begin))/CLOCKS_PER_SEC);
}

template <class T>
void Tester<T>::heapSortTest(double TimeTable[], int& timeCount)
{
	OtherSorts<T> os;
	ioHandler io;
	clock_t begin, end;

	begin = clock();
	os.heapSort(arr,size);
	end =  clock();

	io.setTime(TimeTable,timeCount, ((double)(end - begin))/CLOCKS_PER_SEC);
}