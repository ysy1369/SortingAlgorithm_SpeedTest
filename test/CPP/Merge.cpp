#include "Merge.h"

template <class T>
void Merge<T>::recursiveMerge(T i[],const int s)
{
	const int sm = s/2;
	const int me = s - sm;

	T *arrLeft,*arrRight;

	if(s>1)
	{
		arrLeft = new T[sm];
		arrRight = new T[me];

		arrCopy(i,arrLeft,sm);
		arrCopy(i+sm,arrRight,me);

		recursiveMerge(arrLeft,sm);
		recursiveMerge(arrRight,me);

		Merges(i,arrLeft,arrRight,sm,me);

		delete[] arrLeft;
		delete[] arrRight;
	}
}
template <class T>
void Merge<T>::arrCopy(T i[],T c[],const int s)
{
	for(int k = 0 ; k < s ; k++)
	{
		c[k] = i[k];
	}
}
template <class T>
void Merge<T>::Merges(T i[],T l[],T r[],const int sm,const int me)
{
	int tempA,tempB,tempC;
	tempA = tempB = tempC = 0;

	while (tempA < sm && tempB < me) {
		if (l[tempA] < r[tempB]) {
			i[tempC] = l[tempA++]; 
		} else {
			i[tempC] = r[tempB++];
		}
		tempC++;
	}

	if (tempA == sm) 
		arrCopy(r + tempB, i + tempC, me - tempB);
	else
		arrCopy(l + tempA, i + tempC, sm - tempA);
}

template <class T>
void Merge<T>::nonrecursiveMerge(T i[],const int s)
{
	int rght, rend;
	int z,j,m;

	T* tempArr;
	int size = s;
	tempArr = new T[size];

	arrCopy(i,tempArr,size);


	for (int k=1; k < s; k *= 2 ) 
	{       
		for (int left=0; left+k < s; left += k*2 ) 
		{
			rght = left + k;        
			rend = rght + k;
			if (rend > s) rend = s; 
			m = left; z = left; j = rght; 
			while (z < rght && j < rend) 
			{ 
				if (i[z] <= i[j]) 
				{         
					tempArr[m] = i[z]; z++;
				} else {
					tempArr[m] = i[j]; j++;
				}
				m++;
			}
			while (z < rght) 
			{ 
				tempArr[m] = i[z]; 
				z++; m++;
			}
			while (j < rend) 
			{ 
				tempArr[m] =i[j]; 
				j++; m++;
			}
			for (m=left; m < rend; m++) 
			{ 
				i[m] = tempArr[m]; 
			}
		}
	}
}
template <class T>
void Merge<T>::naturalMerge(T a[],const int n)
{
	Queue<int> list_Length(n);

	int length=1;

	for(int i=0; i < n; i++)
	{
		if(a[i] > a[i+1])
		{
			list_Length.Push(length);
			length=0;
		}
		else
		{
			list_Length.Push(length);
			length=0;
		}
		length++;
	}
	T* tempList = new T[n+1];

	int index = 0;

	while(list_Length.getSize() !=1)
	{
		int j = list_Length.Front(); list_Length.Pop();

		if(index +j > n -1)
		{
			list_Length.Push(j);

			index = 0;

			for(int i =0; i<n; i++)
				a[i] = tempList[i];

			continue;
		}

		int k = list_Length.Front(); 
		list_Length.Pop();

		nMerge(a,tempList,index, index +j -1, index +j + k -1);

		index = index + j + k;
		
		list_Length.Push(j+k);

		if(index > n-1)
		{
			index = 0; 
			for(int i =0; i<n; i++)
				a[i] = tempList[i];
		}
	}
	delete[] tempList;
}
template<class T>
void Merge<T>::nMerge(T* initList, T* mergedList, const int l, const int m, const int n)
{
	// initList[l:m]�� initList[m+1:n]�� ���ĵ� ����Ʈ. �̵��� ���ĵ� ����Ʈ
	// mergedList[1:n]���� �պ��ȴ�.
	int i1 = l, iResult = l, i2 = m+1; // i1, i2�� iResult�� ����Ʈ ��ġ

	for(; i1<=m && i2 <=n; iResult++) // � �Է¸���Ʈ�� �������� ����
	{
		if(initList[i1] <= initList[i2])
		{
			mergedList[iResult] = initList[i1];
			i1++;
		}
		else
		{
			mergedList[iResult] = initList[i2];
			i2++;
		}
	}

	// ù ��° ����Ʈ�� ������ ���ڵ带 ����
	copy(initList + i1, initList + m +1, mergedList + iResult);

	// �� ��° ����Ʈ�� ������ ���ڵ带 ����
	copy(initList + i2, initList + n + 1, mergedList + iResult);
}

