#include "Queue.h"

#ifndef __MIN_HEAP_H__
#define __MIN_HEAP_H__

template <class T>
class MinHeap
{//�ּ� ���� ����
private:
	T* heap;		//�� �迭������
	int heapSize;	//�� �迭�� ���� ũ��
	int end;		//�� �迭�� ���� �������� ������ �ε���

	int getLChildIdx(int parent_idx);	//���� �ڽ� �ε��� ��ȯ
	int getRChildIdx(int parent_idx);	//������ �ڽ� �ε��� ��ȯ
	int getParentIdx(int child_idx);	//�θ� �ε��� ��ȯ
	int getSmallerChildIdx(int parent_idx);	//�ڽİ� ��� ��
public:
	//CONSTRUCTOR & DESTRUCTOR
	MinHeap():end(0), heap(NULL), heapSize(0) {}
	MinHeap(int size);
	~MinHeap(){ delete[] heap; }
	
	//OTHER METHODS
	bool isEmpty();
	bool insertHeap(T data);
	T front();
	bool deleteHeap();
};
#endif