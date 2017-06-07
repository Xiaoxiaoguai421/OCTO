#include<stdio.h>
int main()
{
		int N,M;
		printf("请输入学生人数Ｎ题目数Ｍ:");
		scanf("%d %d",&N,&M);
		int a[N+2][M+1];
		int i,j;
		printf("请输入分值及正确答案\n");
		for(i=0;i<2;i++)
				for(j=0;j<M;j++)
						scanf("%d",&a[i][j]);
		printf("请输入学生答案:\n");
		for(i=2;i<=N+1;i++)   //输入答案并计算应得分数
		{
				a[i][M]=0;
				for(j=0;j<M;j++)
				{
						scanf("%d",&a[i][j]);
						if(a[i][j]==a[1][j])  //比对答案
								a[i][M]+=a[0][j];
						else
								a[i][j]+=0;
				}
		}
		printf("得分如下:\n");
		for(i=2;i<=N+1;i++)  //打印
				printf("%d\n",a[i][M]);
		return 0;
}
