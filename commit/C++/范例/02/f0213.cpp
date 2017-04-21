//File  name : f0213.cpp
//Description: copy constructor
#include<iostream>
using namespace std;
class CPoint
{
		private:
				int nPosX,nPosY;
		public:
				CPoint(int x = 0,int y = 0)  // constructor
				{
						nPosX = x;
						nPosY = y;
				}
				CPoint(const CPoint& pt):nPosX(pt.nPosX),nPosY(pt.nPosY)   //copy constructor
		{}
				~CPoint()       //destructor
				{}
				void print()
				{
						cout << "X=" << nPosX << ",Y=" << nPosY << endl;
				}
};
int main(void)
{
		CPoint pt1(1,2);  //constructing pt1
		pt1.print();
		CPoint pt2(pt1);  //copy constructing pt2
		pt2.print();
		CPoint pt3=pt2,
			   pt4(pt3);
		pt3.print();
		pt4.print();
		return 0;
}
