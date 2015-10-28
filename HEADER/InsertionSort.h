#include "Merge.cpp"

#ifndef __INSERTION_SORT_H__
#define __INSERTION_SORT_H__

template <class T>
class InsertionSort
{
private:
	class Node
	{
	public:
		T Key;
		Node* link;
	
		Node():link(NULL) {}
		Node(T data):Key(data), link(NULL) {}
	};
	void Add_Sorting(Node*& head, Node *data);
public:
	//CONSTRUCTOR & DESTRUCTOR
	InsertionSort(){}
	~InsertionSort(){}

	//KINDS OF INSERTION SORT
	void binaryInsertionSort(T* arr,const int size);
	void linkedInsertionSort(T* arr, int size);
};
#endif
