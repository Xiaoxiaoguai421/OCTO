/*************************************************************************
    > File Name: SeqQueue.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月05日 星期日 23时35分14秒
 ************************************************************************/

#include"SeqQueue.h"
template<class T, int MaxSize>
SeqQueue<T, MaxSize>::SeqQueue()
{
	front = rear = 0;
}

template<class T, int MaxSize>
void SeqQueue<T, MaxSize>::EnQueue(T x)
{
	if (isFull())
	{
		cerr << "上溢" << endl;
		exit(1);
	}
	rear = (rear + 1) % MaxSize;
	data[rear] = x;
}

template<class T, int MaxSize>
T SeqQueue<T, MaxSize>::DeQueue()
{
	if (isEmpty())
	{
		cerr << "下溢" << endl;
		exit(1);
	}
	front = (front + 1) % MaxSize;
	return data[front];
}

template<class T, int MaxSize>
T SeqQueue<T, MaxSize>::GetQueue()
{
	if (isEmpty())
	{
		cerr << "下溢" << endl;
		exit(1);
	}
	else
		return data[front];
}

template<class T, int MaxSize>
bool SeqQueue<T, MaxSize>::isFull()
{
	return ((rear + 1) % MaxSize == front);
}

template<class T, int MaxSize>
bool SeqQueue<T, MaxSize>::isEmpty()
{
	return rear == front;
}

template<class T, int MaxSize>
void SeqQueue<T, MaxSize>::Read(fstream &file)
{
	T item;
	if (!file)
	{
		cerr << "读取文件失败" << endl;
		exit(1);
	}
	else
		while (!file.eof())
		{
			file >> item;
			if (file.peek() == EOF)
				break;
			else
				EnQueue(item);
		}
}

template<class T, int MaxSize>
void SeqQueue<T, MaxSize>::Save(fstream &file)
{
	if (!file)
	{
		cerr << "无法打开文件，保存数据失败" << endl;
		exit(1);
	}
	else
		while (!isEmpty())
			file << DeQueue() << '\t';
}
