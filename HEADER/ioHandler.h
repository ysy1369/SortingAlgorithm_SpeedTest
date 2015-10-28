#include "OtherSorts.cpp"

#ifndef __IO_HANDLER_H__
#define __IO_HANDLER_H__
class ioHandler
{
public:
	//CONSTRUCTOR & DESTRUCTOR
	ioHandler() {}
	~ioHandler(){}
	
	//SETTER METHOD
	void setTime(double timeTable[], int& timeCount, double time);

	//OTHER METHODS
	bool cinFailCheck();
	int selectType();
	int getMenu();
	int selectTestCase();
	void outputName(int sort);
	//int setTestSize();
	void outputTimeTable(int testCaseSize[], double timeTable[]);
	
};
#endif