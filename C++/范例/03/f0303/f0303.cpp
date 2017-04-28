//File  name :f0303.cpp
//Description:建立数组类
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Student
{
		private:
				string id;
				char* pName;
				char gender;
		public:
				Student(string id="191601",char* pN="noName",char gender='m'):id(id),gender(gender)  //构造函数
		{
				cout <<"in Student constructor\n";
				pName = new char[strlen(pN)+1];  //new返回申请到的空间的地址，申请char类型 strlen(pN)+1大小的空间，可是pN不是地址吗？？
				if(pName)
						strcpy(pName,pN);
		}
				Student(const Student& s)     //拷贝构造函数
				{
						cout <<"in Student copy constructor\n";
						id = s.id;
						pName = new char[strlen(s.pName)+1];
						if(pName)
								strcpy(pName.s.pName);
						gender = s.gender;
				}
				void setDate(const Student& s)
				{
						if(this == &s)
								return;
						id = s.id;
						pName = new char[strlen(s.pName)+1];
						if(pName)
								strcpy(pName,s.pName);
						gender = s.gender;
				}
				void setDate(string id,char* p,char gen)
				{
						this->id = id;
						pName = new char[strlrn(p)+1];
						if(pName)
								strcpy(pName,p);
						gender = gen;
				}
				~Student()
				{
						cout <<"in Stuent destructor" << endl;
						delete [] pName;
				}
				void print()
				{
						cout << id <<"-"<< pName <<"-"<< gender << endl;
				}
};
class CD  //CD == CDyArray
{
		private:
				int Max_size;
				int Cur_size;  //what is it?
				Student *ptrArray;
		public:
				CD(int n=100)   //构造数组类
				{
						cout <<"in CD constructor"<< endl;
						ptrArray = new Student[n];
						Max_size = n;
						Cur_size = 0;
				}
				CD(CD& arr)    //复制构造数组类
				{
						cout <<"in CD copy constructor" << endl;
						ptrArray = new Student[arr.Max_size];
						Max_size = arr.Max_size;
						Cur_size = arr.Cur_size;
						for(int i=0;i<Cur_size;i++)
						{
								ptrArray[i].setDate(arr.ptrArray[i]);
						}
				}
				void copyit(CD& arr)  //复制数组类
				{
						Cur_size = arr.Cur_size;
						for(int i=0;i<Cur_size;i++)
						{
								ptrArray[i].setDate(arr.ptrArray[i]);
						}
				}
				void appendit(CD& arr)  //添加
				{
						for(int i=0;i<arr.Cur_size;i++)
						{
								ptrArray[Cur_size+i].setDate(arr.ptrArray[i]);
						}
						Cur_size = Cur_size+arr.Cur_size;
				}
				void setDate(Student& arr,int num)
				{
						for(int i=0;i<num;i++)
						{
								ptrArray[i].setDate(arr[i]);
						}
						Cur_size = num;
				}
				void setDate(Stuent arr,int i)
				{
						ptrArray[i].setDate(arr);
						Cur_size++;
				}
				void print()
				{
						for(int i=0;i<Cur_size;i++)
								ptrArray[i].print();
				}
				~CD()
				{
						cout <<"in CD destructor" << endl;
						delete []ptrArray;
				}
};

int main(void)
{
		ifstream in("date");
		if(!in)
		{
				cout << "Can't oprn file" << endl;
				exit(0);
		}
		int num;
		in >> num;
		CD stu(num);
		string id;
		char name[20];
		char gen;
		for(int i=0;i<num;i++)
		{
				in>>id>>name>>gen;
				stu.setDate(Student(id,name,gen),i);
		}
		stu.print();
		return 0;
}
