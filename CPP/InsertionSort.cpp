#include "InsertionSort.h"

template <class T>
void InsertionSort<T>::binaryInsertionSort(T *arr,const int size)
{
	T temp;

	for(int i = 1 ; i < size; ++i)
	{
		temp = arr[i];
		int left = 0;
		int right = i;

		while(left < right)
		{
			int const mid = (left+right)/2;

			if(temp >= arr[mid])
				left = mid +1;
			else
				right = mid;
		}
		for(int j = i ; j > left ; --j)
			swap(arr[j-1],arr[j]);
	}
}


template <class T>
void InsertionSort<T>::linkedInsertionSort(T* arr, int size)
{
	T input;
	int cnt = 0;
	Node *head =NULL;
	Node *data =NULL;
	Node *temp =NULL;

	for(int i=0 ; i<size ; i++)
	{
		input = arr[i];
		data = new Node(input);
		Add_Sorting(head, data);
	}

	for(temp = head; temp; temp = temp ->link)
	{
		arr[cnt++] = temp->Key;
	}
}

template <class T>
void InsertionSort<T>::Add_Sorting(Node*& head, Node* data)
{
	Node* index;
	Node* pre;

	if(head == NULL)
		head = data;
	else
	{
		index = head;
		pre = NULL;
		while(index != NULL)
		{
			if(index->Key > data->Key)
			{
				if(pre != NULL)
					pre->link = data;
				else
					head = data;
				data ->link = index;
				break;
			}
			pre = index;
			index = index->link;
		}
		if(index == NULL)
			pre->link = data;
	}
}