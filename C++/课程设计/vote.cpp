/*************************************************************************
	> File Name: vote.cpp
	> Author: Guangze Zhu 
	> Mail: xiaoxiaoguai421@gmail.com 
	> Created Time: 2017年09月05日 星期二 13时58分57秒
 ************************************************************************/

#include"vote.h"
candidate::candidate()
{
	num = "NULL";
	name = "NULL";
	class_in = "NULL";
	pvote = 0;
}
void candidate::setinfo()
{
	cout << "请输入候选人信息：编号	名字	所在班级" << endl;
	cin >> num >> name >> class_in;
}
void candidate::getinfo()
{
	cout << "编号：" << num << " 名字：" << name << " 所在班级：" << class_in << " 当前得票数：" << pvote << endl;
}

string candidate::getnum()
{
	return num;
}
string candidate::getname()
{
	return name;
}
string candidate::getclass_in()
{
	return class_in;
}
int candidate::getpvote()
{
	return pvote;
}

void candidate::getvoted()
{
	pvote++;
	cout << "投票成功" << endl;
}

void candidate::setnum(string number)
{
	num = number;
}
void candidate::setname(string nm)
{
	name = nm;
}
void candidate::setclass_in(string cl)
{
	class_in = cl;
}
void candidate::setpvote(int voted)
{
	pvote = voted;
}

void vote(candidate* pt)
{
	string number;
	cout << "请输入候选人编号：";
	cin >> number;
	for (int i = 0; i < 5; i++)
	{
		if (pt[i].getnum() == number)
		{
			pt[i].getvoted();
			break;
		}
		if (i = 4 && pt[i].getnum() != number)
		{
			cout << "查无此人" << endl;
			break;
		}
	}
}
int check()
{
	string password = "8888";   //初始密码 
    string mypassword = NULL;
	cout << "请输入登录密码：" << endl;
	cin >> mypassword;
	if (mypassword == password)
		return 1;
	else {
		cout << "密码错误" << endl;
		return -1;
	}
}
void select(candidate* pt)
{
	string number;
	int i = 0;
	cout << "请输入候选人编号：";
	cin >> number;
	while (i < 5)
	{
		if (pt[i].getnum() == number)
		{
			pt[i].getinfo();
			break;
		}
		if (i = 4 && pt[i].getnum() != number)
			cout << "查无此人" << endl;
		i++;
	}
}
void swap(candidate& pr,candidate& px)
{
	candidate temp(pr);
	pr = px;
	px = temp;
}
void sort(candidate* pt)
{
	for (int i = 0; i < 4; i++)
		for(int j=i+1;j<5;j++)
			if (pt[i].getpvote() > pt[j].getpvote())
				swap(pt[i], pt[j]);
}
/*冒泡排序有待优化*/
void display(candidate* pt,int& count)
{
	cout << "候选人信息如下" << endl;
	for (int i = 0; i < 5; i++)
		pt[i].getinfo();
	cout << "#当前投票人数 " << count << endl;
}
void read(candidate* pt,int& count)
{
	ifstream in("date");
	streambuf* old_buffer = cin.rdbuf(in.rdbuf());
	if (!in)
	{
		cout << "同步数据出错" << endl;
	}
	in >> count;
	string temp;
	int tmp;
	for (int i = 0; i < 5; i++)
	{
		cin >> temp;
		pt[i].setnum(temp);
		cin >> temp;
		pt[i].setname(temp);
		cin >> temp;
		pt[i].setclass_in(temp);
		cin >> tmp;
		pt[i].setpvote(tmp);
	}
	for (int i = 0; i < 5; i++)
		pt[i].getinfo();
	cout << "成功加载投票数据" << endl;
	if ((count + 1) < 10)
		cout << "提示：当前投票人少于10人" << endl;
	cin.rdbuf(old_buffer);//修复buffer
	in.close();
}
void save(candidate* pt, int& count)
{
	ofstream out("date");
	if (!out)
	{
		cout << "保存数据出错" << endl;
	}
	else {
		out << count;
		for (int i = 0; i < 5; i++)
		{
			out << pt[i].getnum();
			out << pt[i].getname();
			out << pt[i].getclass_in();
			out << pt[i].getpvote();
			out << "\n";
		}
	}
	cout << "成功保存投票数据" << endl;
	out.close();
}
