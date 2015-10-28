#include "MinHeap.h"

template <class T>
MinHeap<T>::MinHeap(int size):end(0),heapSize(size)
{
	heap = new T[size+1];
/*	for(int i=0 ; i< size+1 ;i++)
	{
		heap[i] = -1;
	}*/
}
template <class T>
int MinHeap<T>::getLChildIdx(int parent_idx)
{
	int child_idx = parent_idx*2;

	if(child_idx <= end)
		return child_idx;
	else
		return NOT_FOUND;
}
template <class T>
int MinHeap<T>::getRChildIdx(int parent_idx)
{
	int child_idx = parent_idx*2+1;

	if(child_idx <= end)
		return child_idx;
	else
		return NOT_FOUND;
}
template <class T>
int MinHeap<T>::getParentIdx(int child_idx)
{
	int parent_idx = child_idx/2;

	if(parent_idx >=1)
		return parent_idx;
	else
		return NOT_FOUND;
}
template <class T>
bool MinHeap<T>::isEmpty()
{
	if(end==0)
		return true;
	else 
		return false;
}
template <class T>
int MinHeap<T>::getSmallerChildIdx(int parent_idx)
{
	if(getLChildIdx(parent_idx) > end)
		return NOT_FOUND;
	else if(getLChildIdx(parent_idx) == end)
		return getLChildIdx(parent_idx);
	else
	{
		if(heap[getLChildIdx(parent_idx)] > heap[getRChildIdx(parent_idx)])
			return getRChildIdx(parent_idx);
		else
			return getLChildIdx(parent_idx);
	}

}
template <class T>
bool MinHeap<T>::insertHeap(T data)
{
	if(heapSize ==end)
		return false;

	int idx = end+1;
	T insertData = data;

	while(idx !=1)
	{
		if(data < heap[getParentIdx(idx)])
		{
			heap[idx] = heap[getParentIdx(idx)];
			idx = getParentIdx(idx);
		}
		else
			break;
	}
	heap[idx] = insertData;
	end++;

	return true;
}
template <class T>
T MinHeap<T>::front()
{
	if(!isEmpty())
		return heap[1];
}
template <class T>
bool MinHeap<T>::deleteHeap()
{
	if(isEmpty())
		return false;

	T deleteData = heap[1];
	T endData =heap[end];

	int parent_idx =1;
	int child_idx;

	while(child_idx = getSmallerChildIdx(parent_idx))
	{
		if(endData <= heap[child_idx])
			break;
		heap[parent_idx] = heap[child_idx];
		parent_idx = child_idx;
	}

	heap[parent_idx] = endData;
	end--;

	return true;
}