#include "pch.h"
#include "searchTree.h"

//TOOLS
void searchTree::free(Node * p)
{
	if (p == nullptr)
		return;
	else
	{
		for (size_t i = 0; i < p->children.size(); i++)
			free(p->children[i]);
		delete p;
		p = nullptr;
	}
}
void searchTree::print_path(Node * p,int& step)
{
	if (p == nullptr)
		return;
	else
	{
		print_path(p->parent, step);
		if (p->parent == nullptr)
			cout << "��ʼ״̬:" << endl;
		else
			cout << "step: " << step << "\taction: " << p->action << endl;
		print(*p);
		cout << endl;
	}
	step++;
}
void searchTree::setCord(char* cord1, string cord2)
{
	const char *temp = cord2.c_str();
	for (size_t i = 0; i < 9; i++)
		cord1[i] = temp[i];
}
void searchTree::setCord(char * cord1, const char * cord2)
{
	for (size_t i = 0; i < 9; i++)
		cord1[i] = cord2[i];
}
void searchTree::swap(char* a, size_t index_1, size_t index_2)
{
	if (index_1 >= 9 || index_2 >= 9)
		cout << "indexԽ��" << endl;
	char temp = a[index_1];
	a[index_1] = a[index_2];
	a[index_2] = temp;
}
void searchTree::print(Node node)
{
	for (size_t i = 0; i < 9; i++)
	{
		cout << node.cord[i] << "\t";
		if ((i + 1) % 3 == 0)
			cout << endl;
	}
}
void searchTree::show(bool bo)
{
	if (bo == true)
	{
		cout << "Open��" << Open.size() << endl;
		deque<Node*>::iterator iter;
		cout << "Closed��" << Closed.size() << endl;
	}
	else
	{
		int cnt = 0;
		Node* p = Open_heuristic.next;
		while (p != nullptr)
		{
			cnt++;
			p = p->next;
		}
		cout << "Open��" << cnt << endl;
		cnt = 0;
		p = Closed_heuristic.next;
		while (p != nullptr)
		{
			cnt++;
			p = p->next;
		}
		cout << "Closed��" << cnt << endl;
	}
}
int searchTree::missCord(Node* p)
{
	int cnt = 0;
	for (size_t i = 0; i < 9; i++)
	{
		if (p->cord[i] != target->cord[i])
			cnt++;
	}
	return cnt;
}
bool searchTree::isEqual(Node v1, Node v2)
{
	for (size_t i = 0; i < 9; i++)
		if (v1.cord[i] != v2.cord[i])
			return false;
	return true;
}
bool searchTree::isExist(Node node)
{
	deque<Node*>::iterator iter;
	iter = Open.begin();
	while (iter != Open.end())
	{
		if (isEqual(**iter, node) == true)
			return true;
		iter++;
	}
	iter = Closed.begin();
	while (iter != Closed.end())
	{
		if (isEqual(**iter, node) == true)
			return true;
		iter++;
	}
	return false;
}
Node * searchTree::move(Node * node, ACTION act)
{
	//���ɽ��
	Node *temp = new Node;
	temp->parent = node;
	temp->index = node->index;
	setCord(temp->cord, node->cord);
	temp->depth = node->depth + 1;
	switch (act)
	{
	case 0:
		// index ��index-1����
		temp->action = Left;
		swap(temp->cord, temp->index, temp->index - 1);
		temp->index = temp->index - 1;
		break;
	case 1:
		// index ��index-3����
		temp->action = Up;
		swap(temp->cord, temp->index, temp->index - 3);
		temp->index = temp->index - 3;
		break;
	case 2:
		// index ��index+3����
		temp->action = Down;
		swap(temp->cord, temp->index, temp->index + 3);
		temp->index = temp->index + 3;
		break;
	case 3:
		// index ��index+1����
		temp->action = Right;
		swap(temp->cord, temp->index, temp->index + 1);
		temp->index = temp->index + 1;
	default:
		break;
	}
	temp->f = temp->depth + missCord(temp);
	temp->next = nullptr;
	return temp;
}

//expand
bool searchTree::bfs_expand(Node* node)
{
	/*��չ���,
		˳��Left Up Down Right
		����ҵ���չʱ�ҵ�Ŀ���㣬����true
	*/
	if ((node->index + 1) % 3 != 1)
	{
		Node *temp = move(node, Left);
		if (isExist(*temp) == false)
		{
			node->children.push_back(temp);	//����������
			Open.push_back(temp);
			if ((isEqual(*temp, *target)) == true)
				return true;
		}
		else
			delete temp;
	}
	if (node->index > 2)
	{
		Node *temp = move(node, Up);
		if (isExist(*temp) == false)
		{
			node->children.push_back(temp);	//����������
			Open.push_back(temp);
			if ((isEqual(*temp, *target)) == true)
				return true;
		}
		else
			delete temp;
	}
	if (node->index < 6)
	{
		Node *temp = move(node, Down);
		if (isExist(*temp) == false)
		{
			node->children.push_back(temp);	//����������
			Open.push_back(temp);
			if ((isEqual(*temp, *target)) == true)
				return true;
		}
		else
			delete temp;
	}
	if ((node->index + 1) % 3 != 0)
	{
		Node *temp = move(node, Right);
		if (isExist(*temp) == false)
		{
			node->children.push_back(temp);	//����������
			Open.push_back(temp);
			if ((isEqual(*temp, *target)) == true)
				return true;
		}
		else
			delete temp;
	}
	return false;
}
bool searchTree::dfs_expand(Node* node,bool& expand_able)
{
	/*��չ���,
		˳��Left Up Down Right
		����ҵ���չʱ�ҵ�Ŀ���㣬����true
		���������չ��expand_able = false
	*/
	if ((node->index + 1) % 3 != 1)
	{
		Node *temp = move(node, Left);
		if (isExist(*temp) == false)
		{
			expand_able = true;
			node->children.push_back(temp);	//����������
			Open.push_front(temp);
			if ((isEqual(*temp, *target)) == true)
				return true;
		}
		else
			delete temp;
	}
	if (node->index > 2)
	{
		Node *temp = move(node, Up);
		if (isExist(*temp) == false)
		{
			expand_able = true;
			node->children.push_back(temp);	//����������
			Open.push_front(temp);
			if ((isEqual(*temp, *target)) == true)
				return true;
		}
		else
			delete temp;
	}
	if (node->index < 6)
	{
		Node *temp = move(node, Down);
		if (isExist(*temp) == false)
		{
			expand_able = true;
			node->children.push_back(temp);	//����������
			Open.push_front(temp);
			if ((isEqual(*temp, *target)) == true)
				return true;
		}
		else
			delete temp;
	}
	if ((node->index + 1) % 3 != 0)
	{
		Node *temp = move(node, Right);
		if (isExist(*temp) == false)
		{
			expand_able = true;
			node->children.push_back(temp);	//����������
			Open.push_front(temp);
			if ((isEqual(*temp, *target)) == true)
				return true;
		}
		else
			delete temp;
	}
	return false;
}
void searchTree::insert_open(Node * p)
{
	Node* q = Open_heuristic.next;
	if (q == nullptr)
	{
		Open_heuristic.next = p;
		return;
	}
	if ((q->f) > (p->f))	//�嵽��ǰ��
	{
		p->next = q;
		Open_heuristic.next = p;
		return;
	}
	Node* k = Open_heuristic.next->next;
	while (k != nullptr)
	{
		if ((k->f) > (p->f))
		{
			q->next = p;
			p->next = k;
			return;
		}
		k = k->next;
		q = q->next;
	}
	q->next = p;	//�嵽���
	p->next = k;
}
void searchTree::heu_expand(Node * node)
{
	if ((node->index + 1) % 3 != 1)
	{
		Node* temp = move(node,Left);
		//��������ֻ��һ�������ڵ�,�����ɵĽڵ㶼���½ڵ�
		insert_open(temp);
	}
	if (node->index > 2)
	{
		Node* temp = move(node, Up);
		insert_open(temp);
	}
	if (node->index < 6)
	{
		Node* temp = move(node, Down);
		insert_open(temp);
	}
	if ((node->index + 1) % 3 != 0)
	{
		Node* temp = move(node, Right);
		insert_open(temp);
	}
}

searchTree::searchTree()
{
	_REACH = false;

	start = new Node;
	start->index = 7;
	setCord(start->cord, "283164705");
   
	//start->index = 8;
	//setCord(start->cord, "253184760");	//14�� 

	start->parent = nullptr;
	start->action = Nothing;
	start->depth = 0;
	start->f = 0;
	start->next = nullptr;

	target = new Node;
	/*target->index = 4;
	setCord(target->cord, "123804765");*/
	target->index = 5;
	setCord(target->cord, "123850746");	//��Ŀ��״̬10��

	target->parent = nullptr;
	target->action = Nothing;
	target->depth = 0;
	target->f = 0;
	target->next = nullptr;
}
searchTree::~searchTree()
{
	free(start);
	delete target;
	target = nullptr;
	Open.clear();
	Closed.clear();
}

void searchTree::BFS()
{
	cout << "��ʼ״̬�� " << endl;
	print(*start);
	cout << "Ŀ��״̬�� " << endl;
	print(*target);
	bool getTarget = false;
	Node* node;
	//��ʼ״̬������
	Open.push_back(start);
	while ( !Open.empty() && getTarget!=true )	//�ҵ�Ŀ���㼴ֹͣ����Ҫ��Open��Ϊ��
	{
		node = Open.front();
		if (bfs_expand(node) == true)
			getTarget = true;
		Open.pop_front();
		Closed.push_back(node);
	}
	if (getTarget == true)
	{
		_REACH = true;
		cout << "�ܹ�����Ŀ��״̬" << endl;
		show(true);
		cout << endl;
	}
	else
		cout << "���ܵ���Ŀ��״̬" << endl;
}
void searchTree::DFS()
{
	cout << "��ʼ״̬�� " << endl;
	print(*start);
	cout << "Ŀ��״̬�� " << endl;
	print(*target);
	bool getTarget = false;
	bool expand_able = false;
	Node* node;
	//��ʼ״̬��ջ��˫�����ģ�⣩
	Open.push_front(start);
	while (!Open.empty() && getTarget==false)
	{
		node = Open.front();
		if ((node->depth) > 4)
		{
			Open.pop_front();
			Closed.push_back(node);
			continue;
		}
		getTarget = dfs_expand(node,expand_able);
		if (expand_able == false)
		{
			Open.pop_front();
			Closed.push_back(node);
		}
		else
			expand_able = false;
	}
	if (getTarget == true)
	{
		_REACH = true;
		cout << "�ܹ�����Ŀ��״̬" << endl;
		show(true);
	}
	else
		cout << "���ܵ���Ŀ��״̬" << endl;
}
void searchTree::HEU()
{
	cout << "��ʼ״̬�� " << endl;
	print(*start);
	cout << "Ŀ��״̬�� " << endl;
	print(*target);
	bool getTarget = false;
	Open_heuristic.next= start;
	Closed_heuristic.next = nullptr;
	while(Open_heuristic.next != nullptr)
	{
		Node* p = Open_heuristic.next;
		Open_heuristic.next = p->next;	//�Ƴ�open
		p->next = Closed_heuristic.next;	//����closed
		Closed_heuristic.next = p;
		//�ҵ�Ŀ��ڵ�
		if (isEqual(*p, *target))
		{
			getTarget = true;
			break;
		}
		heu_expand(p);	//��չ�ڵ�
	}
	if (getTarget == true)
	{
		_REACH = true;
		cout << "�ܹ�����Ŀ��״̬" << endl;
		show(false);
	}
	else
		cout << "���ܵ���Ŀ��״̬" << endl;
}

void searchTree::print_path()
{
	int step = 0;
	//DFS
//	Node* p = Open.front();
	//BFS
//	Node* p = Open.back();	
	//��������
	Node* p = Closed_heuristic.next;
	print_path(p, step);
}