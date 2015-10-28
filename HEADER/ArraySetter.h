#include "Tester.cpp"

#ifndef __ARRAY_SETTER_H__
#define __ARRAY_SETTER_H__
class ArraySetter
{
private:
	string dectoA(int n);
public:
	//CONSTRUCTOR & DESTRUCTOR
	ArraySetter(){}
	~ArraySetter(){}

	/* INT SET ARRAY METHOD */
	void setRandomTestCase(int*& arr, int arrSize);
	void setIncreaseOrderTestCase(int*& arr, int arrSize);
	void setDecreaseOrderTestCase(int*& arr, int arrSize);

	/* DOUBLE SET ARRAY METHOD */
	void setRandomTestCase(double*& arr, int arrSize);
	void setIncreaseOrderTestCase(double*& arr, int arrSize);
	void setDecreaseOrderTestCase(double*& arr, int arrSize);

	/* RECTANGLE SET ARRAY METHOD */
	void setRandomTestCase(Rectangle*& arr, int n);
	void setIncreaseOrderTestCase(Rectangle*& arr, int n);
	void setDecreaseOrderTestCase(Rectangle*& arr, int n);

	/* STRING SET ARRAY METHOD */
	void setRandomTestCase(string*& arr, int arrSize);
	void setIncreaseOrderTestCase(string*& arr, int arrSize);
	void setDecreaseOrderTestCase(string*& arr, int n);
};
#endif