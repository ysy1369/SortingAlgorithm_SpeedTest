#include "OtherSorts.h"
template <class T>
void OtherSorts<T>::selectionSort(T* arr, const int size)
{//선택 정렬
	int i, j;
	T tmp;
 
	for (i = 0; i < size-1; i++)
	{
		for (j = i + 1; j < size; j++)
		{//SWAP
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
template <class T>
void OtherSorts<T>::bubbleSort(T* arr,int size)//Bubble sort function 
{
    int i,j;
	T temp;
    for(i=0;i<size;i++)
    {
        for(j=0; j<i; j++)
        {
            if(arr[i]<arr[j])
            {//SWAP
                temp=arr[i];  
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
template <class T>
void OtherSorts<T>::heapSort(T* arr, int size)
{
	MinHeap<T> heap(size);
	
	for(int i=0; i<size ;i++)
	{
		heap.insertHeap(arr[i]);
	}
	for(int i=0; i<size; i++)
	{
		arr[i] = heap.front();
		heap.deleteHeap();
	}
}
