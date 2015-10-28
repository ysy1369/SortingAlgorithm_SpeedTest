#include "QuickSort.cpp"

#ifndef __MERGE_H__
#define __MERGE_H__
template <class T>
class Merge
{
private:
	void arrCopy(T i[],T c[],const int s);
	void nMerge(T* initList, T* mergedList, const int l, const int m, const int n);
	void Merges(T i[],T l[],T r[],const int sm,const int me);
public:
	//CONSTRUCTOR & DESTRUCTOR
	Merge(void){}
	~Merge(void){}

	//KINDS OF MERGE SORT
	void recursiveMerge(T i[],const int s);
	void nonrecursiveMerge(T i[],const int s);
	void naturalMerge(T i[],const int s);
};
#endif