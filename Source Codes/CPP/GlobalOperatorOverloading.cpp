#include "Rectangle.h"

///////////////////////////////////////////////////////////////////////////////
					//���� �Լ� ������ ������ �����ε�//
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator<< (ostream& out, Rectangle& a)
{//<< ������ �����ε�
	cout << "W : " << a.getWidth() << " H : " << a.getHeight();
	return out;
}

bool operator< (string a, string b)
{// < ������ �����ε�
	if(strcmp(a.c_str(), b.c_str()) <0)
		return true;
	else 
		return false;
}

bool operator > (string a, string b)
{// > ������ �����ε�
	if(strcmp(a.c_str(), b.c_str()) >0)
		return true;
	else 
		return false;
}
bool operator <= (string a, string b)
{// < ������ �����ε�
	if(strcmp(a.c_str(), b.c_str()) <=0)
		return true;
	else 
		return false;
}

bool operator >= (string a, string b)
{// > ������ �����ε�
	if(strcmp(a.c_str(), b.c_str()) >=0)
		return true;
	else 
		return false;
}