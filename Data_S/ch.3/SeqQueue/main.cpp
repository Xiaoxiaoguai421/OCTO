/*************************************************************************
    > File Name: main.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月05日 星期日 23时43分00秒
 ************************************************************************/

#include<iostream>
#include"SeqQueue.cpp"
using namespace std;
int main(void)
{
	SeqQueue<int, 50> A;
	fstream file_in("data", ios::in);
	A.Read(file_in);
	file_in.close();

	cout << "取队头元素: " << A.GetQueue() << endl;

	cout << "队列元素如下" << endl;
	while (!A.isEmpty())
		cout << A.DeQueue() << endl;
	int x = 0;
	cout << "请输入入队元素(x)\n$:";
	cin >> x;
	A.EnQueue(x);

	fstream file_out("data", ios::out);
	A.Save(file_out);
	file_out.close();
	return 0;
}
