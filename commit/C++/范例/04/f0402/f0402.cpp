//File  name : f0402.cpp
//Description: 复数类源文件
#include<iostream>
#include "f0402.h"
using namespace std;
//member function
CComplex::CComplex(double re,double im)
{
		m_re = re;
		m_im = im;
}
inline void CComplex::set_im(double im)  // what is "inline"??
{
		m_im = im;
}
inline void CComplex::set_re(double re)
{
		m_re = re;
}
void CComplex::display()const 
{
		cout << m_re << "+" << m_im << "i";
}
//friend function
CComplex& operator++(CComplex& cobj)
{
		++cobj.m_re;
		return cobj;
}
CComplex operator++(CComplex& cobj,int)
{
		CComplex temp(cobj);
		++cobj.m_re;
		return temp;
}
