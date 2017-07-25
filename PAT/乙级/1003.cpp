#include<iostream>
#include<string.h>
using namespace std;
class pass{
	private:
	char str[100];
	int flag;
	public:
	pass(){ flag = 0; }
	void get_date(){ cin >> str; }
	void judge();
	void out();
};
void pass::judge()
{
	int count_p=0,count_a=0,count_t=0,si_p=0,si_t=0;
	int i=0;
	while(str[i] != '\0'){
		if(str[i]=='P'){
			count_p++;
			si_p=i;
		}
		if(str[i]=='A')
			count_a++;
		if(str[i]=='T'){
			count_t++;
			si_t=i;
		}
		i++;
	}
	//判断是否正确的条件控制出错
	if(count_p ==1 && count_a!=0 && count_t==1 && si_t>si_p){
    	if(count_p+count_a+count_t != strlen(str))
		  flag = 0;
	    else if(si_p*(si_t-si_p) == (strlen(str) - si_t -1)) 
		  flag = 1;
	}
}
void pass::out()
{
	if(flag == 0)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}
int main(void)
{
	int n;
	cin >> n;
	pass p[n];
	for(int i=0;i<n;i++){
		p[i].get_date();
		p[i].judge();
	}
	for(int i=0;i<n;i++)
		p[i].out();
	return 0;
}
