/*************************************************************************
	> File Name: vote.h
	> Author: Guangze Zhu 
	> Mail: xiaoxiaoguai421@gmail.com 
	> Created Time: 2017年09月05日 星期二 13时56分29秒
 ************************************************************************/

#ifndef _VOTE_H
#define _VOTE_H
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class candidate{
public:
	candidate();
	void setinfo();
	void getinfo();
	string getnum();
	string getname();
	string getclass_in();
	int getpvote();

	void getvoted(); //投票功能

	void setnum(string number);
	void setname(string nm);
	void setclass_in(string cl);
	void setpvote(int voted);
	~candidate() {};
private:
	string num;
	string name;
	string class_in;
	int pvote; //得票数
};
void vote(candidate* pt);
/*管理者*/
int check();
void select(candidate* pt);
void swap(candidate& pr,candidate& px);
void sort(candidate* pt);
void display(candidate* pt,int& count);
void read(candidate* pt,int& count);
void save(candidate* pt,int& count);
#endif
