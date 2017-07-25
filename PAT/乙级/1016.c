#include<iostream>
using namespace std;
class AB
{
	private:
	int D;
	long n,P;
	public:
	AB()
	{
		n=0;
		D=0;
		P=0;
	}
	void cin_info()
	{
		cin >> n >> D;
	}
	int get_P()
	{
		int temp = n%10;
		while(n>0)
		{
			if(temp == D)
				P = P*10 + D;
			n = n/10;
			temp = n%10;
		}
		return P;
	}
};
int main(void)
{
	AB A,B;
	A.cin_info();
	B.cin_info();
	cout << A.get_P() + B.get_P() << endl;
	return 0;
}
