#ifndef _ANIMAL_H
#define _ANIMAL_H
#include<iostream>
using namespace std;
class Animal
{
		private:
				string name;
				string food;
		public:
				string getName()
				{
						return name;
				}
				void setName(string nam)
				{
						name = nam;
				}
				string getFood()
				{
						return food;
				}
				void setFood(string f)
				{
						food = f;
				}
				void eat()
				{
						cout <<"我在吃饭\t";
				}
				void sleeping()
				{
						cout << "我在睡觉\t";
				}
				Animal(string nam,string f)
				{
						name = nam;
						food = f;
				}
};
class Mouse :public Animal
{
		public:
				Mouse(string nam,string f):Animal(nam,f){}
				void dig()
				{
						cout <<"我在打洞\t";
				}
};
class Panda :public Animal
{
		public:
				Panda(string nam,string f):Animal(nam,f){}
};
#endif
