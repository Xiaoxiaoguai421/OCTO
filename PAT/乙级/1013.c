#include<stdio.h>
#include<math.h>
int isPrime(int n);
int main()
{
		int M,N;
		printf("请输入M N: ");
		scanf("%d %d",&M,&N);
		int count=0,num=1,i=0;
		int k;
		k = N-M+1;
		int p[k];
		while(count<=N)
		{
				if(isPrime(num)==1)
				{
						count++;
				}
				if(count >= M && count <=N)
				{
						p[i]=num;
						i++;
				}
				num++;
		}
		i=0;
		while(i<k)
		{
				printf("%d ",p[i]);
				i++;
				if(i%10==0 )
						printf("%d\n",p[i]);
		}
		return 0;
}
int isPrime(int n)
{
		int i,k;
		k=(int)sqrt(n);
		for(i=0;i<=k;i++)
				if(n%k==0)
						break;
		if(i>k)
				return 1;
		else
				return 0;
}
