#include "QuickSort.h"

/* 표준 재귀 Quick Sort*/
template <class T>
void QuickSort<T>::reQuickSort(T* arr, const int left, const int right)
{//arr[left:right]를 비감소 순으로 정렬한다.
	//arr[left]는 피벗으로 임의로 선정한다. 변수 i와 j는 
	//서브리스트를 분할하는데 사용되어 항상 arr[m]<= pivot,m <i 와
	//arr[m] >= pivot, m>j을 만족시킨다. arr[left]<=arr[right+1] 이라고 가정한다.
	if(left<right)
	{
		int i= left,
			j= right+1;
		T pivot=arr[left];
		do{
			do{
				i++; 
				if(i>right){ break; }
			}while(arr[i]<pivot);
			do
			{
				j--;
				if(j<left){ break; }
			}while(arr[j]>pivot);
			if(i<j) swap(arr[i], arr[j]);
		}while(i<j);
		swap(arr[left], arr[j]);

		reQuickSort(arr, left, j-1);
		reQuickSort(arr, j+1, right);
	}
}
/* 표준 비재귀 퀵소트*/
template <class T>
void QuickSort<T>::iterQuickSort(T* arr, int begin, int end)
{
	Queue<int> queue(50);
	int left = begin;
	int right = end;

	do
	{
		if(!queue.IsEmpty())
		{
			left = queue.Front();
			queue.Pop();
			right = queue.Front();
			queue.Pop();
		}
		if(left<right)
		{
			int i= left,
				j= right+1;
			T pivot=arr[left];
			do{
				do{
					i++; 
					if(i>end){ i--; break; }
				}while(arr[i]<pivot);
				do{
					j--; 
					if(j<begin){ j++; break; }
				}while(arr[j]>pivot);
				if(i<j) swap(arr[i], arr[j]);
			}while(i<j);
			swap(arr[left], arr[j]);

			queue.Push(left);
			queue.Push(j-1);
			queue.Push(j+1);
			queue.Push(right);
		}
	}while(!queue.IsEmpty());
}
/* 중간값(메디안) 재귀 퀵소트 */
template <class T>
void QuickSort<T>::median3_reQuickSort(T* arr, const int left, const int right)
{
	int size = right - left + 1;

	if (size <= 3) // manual sort if small
		manualSort(arr, left, right);
	else // quicksort if large
	{
		T median = getMedianOf3(arr, left, right);
		int partition = partitionIt(arr, left, right, median);

		median3_reQuickSort(arr,left, partition - 1);
		median3_reQuickSort(arr, partition + 1, right);
	}
}
/* 중간값(메디안) 비재귀 퀵소트 */
template <class T>
void QuickSort<T>::median3_iterQuickSort(T* arr, int begin, int end)
{
	Queue<int> queue(50);
	int left = begin;
	int right = end;

	do
	{
		if(!queue.IsEmpty())
		{
			left = queue.Front();
			queue.Pop();
			right = queue.Front();
			queue.Pop();
		}

		int size = right - left + 1;

		if (size <= 3) // manual sort if small
			manualSort(arr, left, right);
		else // quicksort if large
		{
			T median = getMedianOf3(arr, left, right);
			int partition = partitionIt(arr, left, right, median);

			queue.Push(left);
			queue.Push(partition - 1);
			queue.Push(partition + 1);
			queue.Push(right);
		}
	}while(!queue.IsEmpty());
}

/* STL의 qsort() 함수를 이용한 Quick Sort */
template <class T>
void QuickSort<T>::STLQuickSort(T* arr, const int size)
{
	sort(arr, arr+size);
	//qsort(arr, size, sizeof(int), dataCompare);
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////         <<Private 영역>>        median3_reQuickSort() 함수를 위한 부수적인 메소드
//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T QuickSort<T>::getMedianOf3(T* arr, int left, int right) 
{
	int center = (left + right) / 2;

	// order left & center
	if (arr[left] > arr[center])
		swap(arr[left], arr[center]);

	// order left & right
	if (arr[left] > arr[right])
		swap(arr[left], arr[right]);

	// order center & right
	if (arr[center] > arr[right])
		swap(arr[center], arr[right]);

	swap(arr[center], arr[right-1]); // put pivot on right

	return arr[right-1]; // return median value
}

template <class T>
int QuickSort<T>::partitionIt(T* arr, int left, int right, T pivot) 
{
	int leftPtr = left; // right of first elem
	int rightPtr = right - 1; // left of pivot

	while (true) 
	{

		while (arr[++leftPtr] < pivot);	//	find bigger
		while (arr[--rightPtr] > pivot);//	find smaller

		if (leftPtr >= rightPtr) // if pointers cross, partition done
			break;    
		else	// not crossed, so
			swap(arr[leftPtr], arr[rightPtr]); // swap elements
	}
	swap(arr[leftPtr], arr[right-1]); // restore pivot

	return leftPtr; // return pivot location
}

template <class T>
void QuickSort<T>::manualSort(T* arr, int left, int right) 
{
	int size = right - left + 1;

	if (size <= 1)
		return; // no sort necessary

	if (size == 2) 
	{ // 2-sort left and right
		if (arr[left] > arr[right])
			swap(left, right);
		return;
	}
	else // size is 3
	{ // 3-sort left, center, & right
		if (arr[left] > arr[right - 1])
			swap(arr[left], arr[right-1]);	// left, center
		if (arr[left] > arr[right])
			swap(arr[left], arr[right]);	// left, right
		if (arr[right - 1] > arr[right])
			swap(arr[right-1], arr[right]);	// center, right
	}
}
