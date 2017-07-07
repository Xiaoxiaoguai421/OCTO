#include<stdio.h>
#include<math.h>
int isPrime(int n)    //判断素数
{
	for(int i=2;i<=sqrt(n);i++)
		if((n%i)==0)
			return 0;
	return 1;
}
int main(void)
{
	int num=1,count=0,i=0,M,N;
	scanf("%d %d",&M,&N);
	int k=N-M+1;
	int p[k];
	while(++num){
		if(isPrime(num)==1){
			count++; 
			if(count>=M && count <=N)  //存符合条件的素数
				p[i++]=num;
		}
		if(count >N)
			break;
	}
	for(i=0;i<(k-1);i++){
		if((i+1)%10 == 0)
			printf("%d\n",p[i]);
		else
			printf("%d ",p[i]);
	}
	printf("%d",p[i++]);    //最后一个数的格式
	return 0;
}
