#include "Header.h"

#ifndef __Rectangle_H__
#define __Rectangle_H__

class Rectangle 
{//가로(width)와 세로(height)를 가지는 RECTANGLE CLASS (==, <=, >=, > , < 연산자 오버로딩)
private :
	double width;		// 가로길이	
	double height;		// 세로길이
public :
	Rectangle():width(0),height(0) {}
	Rectangle(double width, double height):width(width), height(height) {}
	~Rectangle(){}

	double getWidth(){ return width;}
	double getHeight(){ return height;}
	
	bool operator == (Rectangle& b) 
	{// == 연산자 오버로딩
		double thisArea = this -> width * this -> height;
		double bArea = b.width * b.height;

		if(thisArea == bArea) 
			return true;
		else
			return false;
	}
	bool operator >= (Rectangle& b) 
	{//>= 연산자 오버로딩
		double thisArea = this -> width * this -> height;
		double bArea = b.width * b.height;

		if(thisArea >= bArea) 
			return true;
		else
			return false;
	}

	bool operator <= (Rectangle& b) {//<= 연산자 오버로딩
		double thisArea = this -> width * this -> height;
		double bArea = b.width * b.height;

		if(thisArea <= bArea) 
			return true;
		else
			return false;
	}
	
	bool operator > (Rectangle& b) 
	{// > 연산자 오버로딩
		double thisArea = this -> width * this -> height;
		double bArea = b.width * b.height;

		if(thisArea > bArea) 
			return true;
		else
			return false;
	}

	bool operator < (Rectangle& b)
	{// < 연산자 오버로딩
		double thisArea = this -> width * this -> height;
		double bArea = b.width * b.height;

		if(thisArea < bArea) 
			return true;
		else
			return false;
	}
	friend extern ostream& operator << (ostream& os, const Rectangle& a); 	
};
//GLOBAL OPERATOR OVERLOADING.cpp 파일에 정의 되어있음.
ostream& operator << (ostream& os, const Rectangle& a);
bool operator< (string a, string b);
bool operator > (string a, string b);
bool operator <= (string a, string b);
bool operator >= (string a, string b);

#endif