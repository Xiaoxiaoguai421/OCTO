//File  name : f0402.h
//Description: 复数类头文件
#ifndef _COMPLEX_H
#define _COMPLEX_H
class CCOmplex
{
		private:
				double m_im,m_re;
		public:
				CComplex(double = 0,double = 0); //in construction
				void set_re(double);
				void set_in(double);
				void display()const; //常成员函数，什么鬼？？
				friend CComplex& operator++(CComplex);
				friend CComplex& operator++(CComplex&,int);
};
#endif
