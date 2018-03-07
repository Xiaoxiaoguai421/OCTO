/*************************************************************************
    > File Name: main.cpp
    > Author:
    > Mail:
    > Created Time: 2018年01月17日 星期三 11时57分59秒
 ************************************************************************/

#include"Huffman.h"
#include<cstring>
#include<map>
int main(void)
{
	/*
	    //输入vector<HuffmanNode> leafs
	    map<char,int> hash;
	    cout<<"请输入一行文本数据:\n$:";   //由此文本确定各字符编码，键盘/file
	    string str;
	    cin>>str;
	    char *p=new char[str.length()];
	    char *q=p;
	    strcpy(p,str.c_str());
	    int count=0;
	    while(*p!='\0')
	    {
	        if(hash.find(*p)!=hash.end())
	            hash[*p]+=1;
	        else
	            hash[*p]=1;
	        p++;
	    }
	    delete q;
	    q=p=NULL;
	    map<char,int>::iterator iter;
	    vector<HuffmanNode> leafs;
	    HuffmanNode leaf;
	    for(iter=hash.begin();iter!=hash.end();iter++)
	    {
	        leaf.data=iter->first;
	        leaf.weight=iter->second;
	        leafs.push_back(leaf);
	    }
	*/
	int num;
	cout << "请输入hafuuman编码的字符个数：\n$:";
	cin >> num;
	vector<HuffmanNode> leafs(num);
	for (int i = 0; i < num; i++)
	{
		cout << "请输入第" << i + 1 << "个字符：";
		cin >> leafs[i].data;
		cout << "权重:";
		cin >> leafs[i].weight;
	}
	//huffman树
	HuffmanTree A(leafs);
//	A.Print();
	cout << "编码表" << endl;
	for (int i = 0; i < leafs.size(); i++)
	{
		string temp_code = A.GetCode(i);
		cout << leafs[i].data << ": " << temp_code;
		cout << endl;
	}

	map<char, string> hash_code;
	for (int i = 0; i < leafs.size(); i++)
		hash_code[leafs[i].data] = A.GetCode(i);

	cout << "请输入待编码的信息\n$;";
	string temp_str;
	cin >> temp_str;

	string code = "";
	char *p = new char[temp_str.length()];
	strcpy(p, temp_str.c_str());
	char *q = p;
	while (*p != '\0')
		code += hash_code[*p++];
	cout << "编码：" << code << endl;
	delete q;
	q = p = NULL;



	//输入vector<int> source
	cout << "请输入编码文件：\n$:";
	vector<int> source;
	string str_code;
	cin >> str_code;
	p = new char[str_code.size()];
	q = p;
	strcpy(p, str_code.c_str());
	while (*p != '\0')
	{
		source.push_back(*p - '0');
		p++;
	}
	delete q;
	q = p = NULL;
	string decode = A.Decode(source);
	cout << "译码：" << decode << endl;

	return 0;
}
