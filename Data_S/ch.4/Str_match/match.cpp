/*************************************************************************
    > File Name: match.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月06日 星期一 21时16分24秒
 ************************************************************************/
#ifndef _MATCH_CPP
#define _MATCH_CPP

#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
void Read(char *source, fstream &file);
int BFmatching(char *source, char *pattern);
void Getnext(char *pattern,int *next);
void Getnextval(char *pattern,int *next);
int KMPmatching(char *source,char *pattern,int *next);

int BFmatching(char *source, char *pattern)
{
	int i = 0;
	int j = 0;
	int len_s = strlen(source);
	int len_p = strlen(pattern);
	while (i < len_s && j < len_p)
	{
		if (source[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;  //j相当于在上次错误匹配过程中主串i的偏移量，先主串回到原位置i-j,再移动主串+1，准备下次BF匹配
			j = 0;
		}
	}
	if (j >= len_p)
		return i - j;
	else
		return -1;
}

void Getnext(char *pattern, int *next)
{
	int j = 0;
	int k = -1;
	int length = strlen(pattern);
	next[0] = -1;
	while (j < length - 1)
	{
		if (k == -1 || pattern[j] == pattern[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}
}
void Getnextval(char *pattern, int *next)
{
	int j = 0;  //前缀
	int k = 0;  //后缀
	int length = strlen(pattern);
	next[0] = -1;
	while (j < length - 1)
	{
		if (k == -1 || pattern[j]==pattern[k])
		{
			j++;
			k++;
			if (pattern[j] != pattern[k])
				next[j] = k;
			else
				next[j] = next[k];
		}
		else
			k = next[k];
	}
}
int KMPmatching(char *source, char *pattern, int *next)
{
	int i = 0;
	int j = 0;
	int len_s = strlen(source);
	int len_p = strlen(pattern);
	while (i < len_s && j < len_p)
	{
		if (j == -1 || source[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j >= len_p)
		return i - len_p;
	else
		return -1;
}

#endif
