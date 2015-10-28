#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include "MinHeap.cpp"
template <class T>
class QuickSort
{
private:
	/* Median Of Three �� �̿��� ����Ʈ �Լ��� ���� �μ����� �޼ҵ� */
	T getMedianOf3(T* arr, int left, int right) ;	//�߰����� ��ȯ�ϴ� �޼ҵ�
	int partitionIt(T* arr,int left, int right, T pivot);
	void manualSort(T* arr, int left, int right);

public:
	//CONSTRUCTOR & DESTRUCTOR
	QuickSort(){}
	~QuickSort(){}
	
	//KINDS OF QUICKSORT
	void reQuickSort(T* a, const int left, const int right);					//ǥ���� ��� ����Ʈ
	void iterQuickSort(T* arr, int begin, int end);						//ǥ���� �ݺ� ����Ʈ
	void median3_reQuickSort(T* a, const int left, const int right);			//�߰���(�޵��) ��� ����Ʈ 
	void median3_iterQuickSort(T* a, const int begin, const int end);		//�߰���(�޵��) �ݺ� ����Ʈ
	void STLQuickSort(T* a, const int size);	//std::sort()�� �̿��� STL ����Ʈ
};
#endif