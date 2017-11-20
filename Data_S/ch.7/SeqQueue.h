/*************************************************************************
 *
    > File Name: SeqQueue.h
    > Author:
    > Mail:
    > Created Time: 2017年11月05日 星期日 23时31分55秒
 ************************************************************************/

#ifndef _SEQQUEUE_H
#define _SEQQUEUE_H
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
template<class T, int MaxSize>
class SeqQueue
{
public:
	SeqQueue();
	void EnQueue(T x);
	T DeQueue();
	T GetQueue();
//	int GetLength(){return rear - front;}
	bool isFull();
	bool isEmpty();
	void Read(fstream &file);
	void Save(fstream &file);
private:
	T data[MaxSize];
	int front, rear;
};
#endif
