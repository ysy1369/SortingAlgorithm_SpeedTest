#include "Queue.h"

#ifndef __MIN_HEAP_H__
#define __MIN_HEAP_H__

template <class T>
class MinHeap
{//최소 히프 구현
private:
	T* heap;		//힙 배열포인터
	int heapSize;	//힙 배열의 실제 크기
	int end;		//힙 배열의 실질 데이터의 마지막 인덱스

	int getLChildIdx(int parent_idx);	//왼쪽 자식 인덱스 반환
	int getRChildIdx(int parent_idx);	//오른쪽 자식 인덱스 반환
	int getParentIdx(int child_idx);	//부모 인덱스 반환
	int getSmallerChildIdx(int parent_idx);	//자식간 대소 비교
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