#include "InsertionSort.cpp"

#ifndef __OTHER_SORTS_H__
#define __OTHER_SORTS_H__

template <class T>
class OtherSorts
{
private:
	
public:
	//CONSTRUCTOR & DESTRUCTOR
	OtherSorts(){}
	~OtherSorts(){}

	//KINDS OF OTHER SORTS
	void selectionSort(T* a, const int size);
	void bubbleSort(T* arr,int size);
	void heapSort(T* arr, int size);

};
#endif