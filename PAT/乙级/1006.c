#include<stdio.h>
int main()
{
		int a[3]={0,0,0};
		int n,i;
		printf("请输入一个数(n<1000): ");
		scanf("%d",&n);
		for(i=2;n!=0;i--)
		{
				a[i]=n%10;
				n/=10;
		}
		for(i=0;i<a[0];i++)
				printf("B");
		for(i=0;i<a[1];i++)
				printf("S");
		for(i=1;i<=a[2];i++)
				printf("%d",i);
		printf("\n");
		return 0;
}
