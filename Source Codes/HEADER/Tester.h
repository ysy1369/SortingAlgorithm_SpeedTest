#include "ioHandler.h"

#ifndef __TESTER_H__
#define __TESTER_H__

template <class T>
class Tester
{
private:
	T* arr;
	int size;
public:
	//CONSTRUCTOR & DESTRUCTOR
	//Tester(){}
	Tester():arr(NULL), size(0) {}
	~Tester()
	{
		if(arr != NULL) 
		{
			delete[] arr; 
			arr=NULL; 
		}	
	}
	
	//SETTER METHOD
	void setArr(T* testArr){ this->arr = testArr; }
	void setSize(int size){ this->size = size; }

	//GETTER METHOD
	T*& getArr(){ return arr; }
	int getSize(){ return size;}

	//QUICK SORT TEST METHOD
	void reQuickSortTest(double TimeTable[], int& timeCount);
	void iterQuickSortTest(double TimeTable[], int& timeCount);
	void median3_reQuickSortTest(double TimeTable[], int& timeCount);
	void median3_iterQuickSortTest(double TimeTable[], int& timeCount);
	void STLQuickSortTest(double TimeTable[], int& timeCount);

	//MERGE SORT TEST METHOD
	void recursiveMergeTest(double TimeTable[], int& timeCount);
	void nonRecursiveMergeTest(double TimeTable[], int& timeCount);
	void naturalMergeTest(double TimeTable[], int& timeCount);

	//INSERTION SORT TEST METHOD
	void binaryInsertionSortTest(double TimeTable[], int& timeCount);
	void linkedInsertionSortTest(double TimeTable[], int& timeCount);

	//OTHER SORTS TEST METHOD
	void selectionSortTest(double TimeTable[], int& timeCount);
	void bubbleSortTest(double TimeTable[], int& timeCount);
	void heapSortTest(double TimeTable[], int& timeCount);
};
#endif