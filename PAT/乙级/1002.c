#include<stdio.h>
#include<string.h>
void pinyin(int n);
int main(void)
{
	char str[100];
	scanf("%s",str);
	int i=0,sum=0;
	while(str[i] != '\0') 
		sum += str[i++] -'0';
	int n[3];
	int j=0;
	while(sum){
		n[j++] = sum%10;
		sum = sum/10;
	}
	for(j=j-1;j>0;j--){
		pinyin(n[j]);
		printf(" ");
	}
	pinyin(n[0]);
	return 0;
}
void pinyin(int n)
{
	switch(n){
		case 0:printf("ling");break;
		case 1:printf("yi");break;
		case 2:printf("er");break;
		case 3:printf("san");break;
		case 4:printf("si");break;
		case 5:printf("wu");break;
		case 6:printf("liu");break;
		case 7:printf("qi");break;
		case 8:printf("ba");break;
		case 9:printf("jiu");break;
	}
}
