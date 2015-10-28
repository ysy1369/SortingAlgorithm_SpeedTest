#include "Header.h"

#ifndef __Rectangle_H__
#define __Rectangle_H__

class Rectangle 
{//����(width)�� ����(height)�� ������ RECTANGLE CLASS (==, <=, >=, > , < ������ �����ε�)
private :
	double width;		// ���α���	
	double height;		// ���α���
public :
	Rectangle():width(0),height(0) {}
	Rectangle(double width, double height):width(width), height(height) {}
	~Rectangle(){}

	double getWidth(){ return width;}
	double getHeight(){ return height;}
	
	bool operator == (Rectangle& b) 
	{// == ������ �����ε�
		double thisArea = this -> width * this -> height;
		double bArea = b.width * b.height;

		if(thisArea == bArea) 
			return true;
		else
			return false;
	}
	bool operator >= (Rectangle& b) 
	{//>= ������ �����ε�
		double thisArea = this -> width * this -> height;
		double bArea = b.width * b.height;

		if(thisArea >= bArea) 
			return true;
		else
			return false;
	}

	bool operator <= (Rectangle& b) {//<= ������ �����ε�
		double thisArea = this -> width * this -> height;
		double bArea = b.width * b.height;

		if(thisArea <= bArea) 
			return true;
		else
			return false;
	}
	
	bool operator > (Rectangle& b) 
	{// > ������ �����ε�
		double thisArea = this -> width * this -> height;
		double bArea = b.width * b.height;

		if(thisArea > bArea) 
			return true;
		else
			return false;
	}

	bool operator < (Rectangle& b)
	{// < ������ �����ε�
		double thisArea = this -> width * this -> height;
		double bArea = b.width * b.height;

		if(thisArea < bArea) 
			return true;
		else
			return false;
	}
	friend extern ostream& operator << (ostream& os, const Rectangle& a); 	
};
//GLOBAL OPERATOR OVERLOADING.cpp ���Ͽ� ���� �Ǿ�����.
ostream& operator << (ostream& os, const Rectangle& a);
bool operator< (string a, string b);
bool operator > (string a, string b);
bool operator <= (string a, string b);
bool operator >= (string a, string b);

#endif