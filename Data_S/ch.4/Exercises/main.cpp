/*************************************************************************
    > File Name: main.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月16日 星期四 21时20分56秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include"match.cpp"
#include<time.h>
using namespace std;
const int MaxSize = 100;
int nextval[MaxSize];
int KMP(char *source, char *pattern);

int Count(char *source, char *pattern);
void Delete(char *source, char *pattern);
char* Max_same(char *source, char *pattern);
void Rev_all(char *s);
void Rev_sentence(char *s);
void RemoveChars_1(char *str, char *remove);
void RemoveChars_2(char *str, char *remove);

int main(void)
{
	char source[MaxSize];
	char pattern[MaxSize];
	cout << "请输入主串\n$:";
	cin >> source;
	cout << "请输入模式串\n$:";
	cin >> pattern;
	cout << "主串中有" << Count(source, pattern) << "个模式串" << endl;
	cout << "从主串中删除所有模式串后,主串为" << endl;
	Delete(source, pattern);
	cout << source << endl;

	cout << "*********************************************************" << endl;
	cout << "找最大公共子串" << endl;
	cout << "请输入串s:";
	cin >> source;
	cout << "请输入串t:";
	cin >> pattern;
	char *same = Max_same(source, pattern);
	if (same != NULL)
		cout << "主串、模式串的最大公共子串为\n$:" << same << endl;
	else
		cout << "无公共子串" << endl;

	cout << "*********************************************************" << endl;
	char sentence[MaxSize];
	cout << "请输入一个句子:";
	cin.get();
	cin.get(sentence, MaxSize);
	Rev_sentence(sentence);
	cout << "颠倒后:" << sentence << endl;

	cout << "*********************************************************" << endl;
	char str_1[MaxSize];
	char str_2[MaxSize];
	char re[MaxSize];
	cout << "请输入str:";
	cin.get();
	cin.get(str_1, MaxSize);
	int str_i=0;
	for (str_i = 0; str_i < strlen(str_1); str_i++)
		str_2[str_i] = str_1[str_i];
	str_2[str_i]='\0';

	cout << "请输入remove:";
	cin.get();
	cin.get(re, MaxSize);

	clock_t start;
	clock_t end;
	start = clock();
	RemoveChars_1(str_1, re);
	end = clock();
	cout << "RemoveChars_1删除后:" << str_1 << endl;
	cout << "用时:" << (end - start) / CLOCKS_PER_SEC << "s" << endl;

	start = clock();
	RemoveChars_2(str_2, re);
	end = clock();
	cout << "RemoveChars_2删除后:" << str_2 << endl;
	cout << "用时:" << (end - start) / CLOCKS_PER_SEC << "s" << endl;

	return 0;
}

//输入两个字符串source和pattern，统计source中包含串pattern个数
int Count(char *source, char *pattern)
{
	int cnt = 0;
	int find = 0;
	int length = strlen(pattern);
	char *new_start = source;
	while (1)
	{
		find = KMP(new_start, pattern);
		if (find == -1)
			break;
		cnt++;
		new_start = new_start + find + 1;
	}
	return cnt;
}

//从串source中删除所有与串pattern相同的子串
void Delete(char *source, char *pattern)
{
	int i = 0;
	int Del[MaxSize];
	int length = strlen(pattern);
	char *new_start = source;
	while (1)
	{
		Del[i] = KMP(new_start, pattern);
		if (Del[i] == -1)
			break;
		new_start = new_start + Del[i] + 1;
		Del[i] = new_start - source - 1; //主串中的下标位置
		i++;
	}
	/*
	    for(int m=0;m<i;m++)
	        cout<<Del[m]<<'\t';
	    cout<<endl;
	*/
	int j = 0;
	int k = 0;
	int g = 0;
	while (g < strlen(source) && j < i)
	{
		while (g == Del[j])
		{
			if ((Del[j] + 1) != Del[j + 1])
				g = Del[j] + length;
			else
				g++;
			j++;
		}
		source[k++] = source[g++];
	}
	source[k] = '\0';
}

//求串s和串t的最大公共子串
char* Max_same(char *source, char *pattern)
{
	char *p = NULL;
	char *s = NULL;
	char *t = NULL;
	if (strlen(source) > strlen(pattern))
	{
		s = source;
		t = pattern;
	}
	else
	{
		s = pattern;
		t = source;
	}
	for (int i = strlen(t); i > 0; i--) //用短串t的子串KMP匹配长串s
	{
		p = t;
		while (*(p + i) != '\0')
		{
			char temp = *(p + i);
			*(p + i) = '\0'; //截取子串
			if (KMP(s, p) != -1)
				return p;
			*(p + i) = temp; //找错了，复原
			p++;
		}
		if (KMP(s, p) != -1)
			return p;
	}
	return NULL;
}

//颠倒单词在字符串中的位置
void Rev_sentence(char *s)
{
	if (s == NULL)
	{
		cerr << "无内容" << endl;
		exit(1);
	}
	Rev_all(s);
	char *high = s;
	char *low = s;
	while (*high != '\0')
	{
		while (*high == ' ' && *high != '\0')
			high++;
		low = high;
		while (*high != ' ' && *high != '\0')
			high++;
		char temp = *high;
		*high = '\0';   //断句
		Rev_all(low);
		*high = temp;   //重连
	}
}
void Rev_all(char *s)
{
	int length = strlen(s);
	int start = 0;
	int end = length - 1;
	while (start < (length / 2))
	{
		char temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
}

//删除字符串中的指定字符
void RemoveChars_1(char *str, char *remove)
{
	bool flag = false;
	int len_str = strlen(str);
	int len_re = strlen(remove);
	int k = 0;
	for (int i = 0; i < len_str; i++)
	{
		flag = false;
		for (int j = 0; j < len_re; j++)
			if (str[i] == remove[j])
			{
				flag = true;
				break;
			}
		if (flag == true)
			continue;
		str[k++] = str[i];
	}
	str[k] = '\0';
}

void RemoveChars_2(char *str, char *remove)
{
	char *temp = remove;
	int tab[256];
	for (int i = 0; i < 256; i++)
		tab[i] = 0;
	int k = 0;
	while (remove[k])
		tab[remove[k++]] = 1;
	k = 0;
	int j = 0;
	while (str[j] != '\0')
	{
		if (tab[str[j]] != 1)
			str[k++] = str[j];
		j++;
	}
	str[k] = '\0';
}

int KMP(char *source, char *pattern)
{
	Getnextval(pattern, nextval);
	return KMPmatching(source, pattern, nextval);
}
