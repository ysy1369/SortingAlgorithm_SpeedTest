#include "Rectangle.h"

///////////////////////////////////////////////////////////////////////////////
					//전역 함수 형태의 연산자 오버로딩//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator<< (ostream& out, Rectangle& a)
{//<< 연산자 오버로딩
	cout << "W : " << a.getWidth() << " H : " << a.getHeight();
	return out;
}

bool operator< (string a, string b)
{// < 연산자 오버로딩
	if(strcmp(a.c_str(), b.c_str()) <0)
		return true;
	else 
		return false;
}

bool operator > (string a, string b)
{// > 연산자 오버로딩
	if(strcmp(a.c_str(), b.c_str()) >0)
		return true;
	else 
		return false;
}
bool operator <= (string a, string b)
{// < 연산자 오버로딩
	if(strcmp(a.c_str(), b.c_str()) <=0)
		return true;
	else 
		return false;
}

bool operator >= (string a, string b)
{// > 연산자 오버로딩
	if(strcmp(a.c_str(), b.c_str()) >=0)
		return true;
	else 
		return false;
}