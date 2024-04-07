#pragma once
#ifndef __COMPLEX__
#define __COMPLEX__

#include<cmath>

class complex
{
public:
	complex(double r = 0, double i = 0)
		:re(r), im(i)
	{}
private:
	double re, im;
};



#endif // !__COMPLEX__
