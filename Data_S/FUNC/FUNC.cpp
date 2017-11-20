/*************************************************************************
    > File Name: FUNC.cpp
    > Author:
    > Mail:
    > Created Time: 2017年11月16日 星期四 20时59分02秒
 ************************************************************************/

#include"FUNC.h"
void Read(char *target, fstream &file)
{
	int i = 0;
	if (!file)
	{
		cerr << "打开文件失败" << endl;
		exit(1);
	}
	else
		while (!file.eof())
		{
			if (file.peek() == EOF)
				break;
			file >> target[i++];
		}
}

void Save(char *target, fstream &file)
{
	if (!file)
	{
		cerr << "打开文件失败" << endl;
		exit(1);
	}
	else
		file << target << '\t';
}
