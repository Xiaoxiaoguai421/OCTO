#include<stdio.h>
struct Rank{
	char name[10];
	char number[10];
	int score;
};
int main(void)
{
	int n;
	scanf("%d",&n);
	struct Rank stu[n];
	for(int i=0;i<n;i++){
		scanf("%s",stu[i].name);
		scanf("%s",stu[i].number);
		scanf("%d",&stu[i].score);
	}
	struct Rank max=stu[0],min=stu[0];
	for(int j=0;j<n;j++){
		if(stu[j].score > max.score)
			max = stu[j];
		if(stu[j].score < min.score)
			min = stu[j];
	}
	printf("%s %s\n",max.name,max.number);
	printf("%s %s\n",min.name,min.number);
	return 0;
}
