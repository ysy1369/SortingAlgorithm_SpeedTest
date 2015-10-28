#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include "MinHeap.cpp"
template <class T>
class QuickSort
{
private:
	/* Median Of Three 를 이용한 퀵소트 함수를 위한 부수적인 메소드 */
	T getMedianOf3(T* arr, int left, int right) ;	//중간값을 반환하는 메소드
	int partitionIt(T* arr,int left, int right, T pivot);
	void manualSort(T* arr, int left, int right);

public:
	//CONSTRUCTOR & DESTRUCTOR
	QuickSort(){}
	~QuickSort(){}
	
	//KINDS OF QUICKSORT
	void reQuickSort(T* a, const int left, const int right);					//표준형 재귀 퀵소트
	void iterQuickSort(T* arr, int begin, int end);						//표준형 반복 퀵소트
	void median3_reQuickSort(T* a, const int left, const int right);			//중간값(메디안) 재귀 퀵소트 
	void median3_iterQuickSort(T* a, const int begin, const int end);		//중간값(메디안) 반복 퀵소트
	void STLQuickSort(T* a, const int size);	//std::sort()를 이용한 STL 퀵소트
};
#endif