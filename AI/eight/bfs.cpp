#include "bfs.h"

bool bfs::getREACH() const
{
    return _REACH;
}

void bfs::free(Node *p)
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

size_t bfs::setCord(char *code1, string code2)
{
    size_t index_zero = INFINITY;
    const char *temp = code2.c_str();
    for (size_t i = 0; i < 9; i++)
    {
        code1[i] = temp[i];
        if('0'==code1[i])
            index_zero=i;
    }
    return index_zero;
}

void bfs::setCord(char *code1, const char *code2)
{
    for (size_t i = 0; i < 9; i++)
        code1[i] = code2[i];
}

void bfs::swap(char *a, size_t index_1, size_t index_2)
{
    char temp = a[index_1];
    a[index_1] = a[index_2];
    a[index_2] = temp;
}

bool bfs::isEqual(Node* v1,Node* v2)
{
    for (size_t i = 0; i < 9; i++)
        if (v1->code[i] != v2->code[i])
            return false;
    return true;
}

bool bfs::isExist(Node* node)
{
    deque<Node*>::iterator iter;
    iter = Open.begin();
    while (iter != Open.end())
    {
        if (isEqual(*iter, node) == true)
            return true;
        iter++;
    }
    iter = Closed.begin();
    while (iter != Closed.end())
    {
        if (isEqual(*iter, node) == true)
            return true;
        iter++;
    }
    return false;
}

Node *bfs::move(Node *node, ACTION act)
{
    //生成结点
    Node *temp = new Node;
    temp->parent = node;
    temp->index = node->index;
    setCord(temp->code, node->code);
    switch (act)
    {
    case 0:
        // index 和index-1交换
        temp->action = Left;
        swap(temp->code, temp->index, temp->index - 1);
        temp->index = temp->index - 1;
        break;
    case 1:
        // index 和index-3交换
        temp->action = Up;
        swap(temp->code, temp->index, temp->index - 3);
        temp->index = temp->index - 3;
        break;
    case 2:
        // index 和index+3交换
        temp->action = Down;
        swap(temp->code, temp->index, temp->index + 3);
        temp->index = temp->index + 3;
        break;
    case 3:
        // index 和index+1交换
        temp->action = Right;
        swap(temp->code, temp->index, temp->index + 1);
        temp->index = temp->index + 1;
        break;
    default:
        break;
    }
    return temp;
}

bool bfs::bfs_expand(Node *node)
{
    /*拓展结点,
            顺序：Left Up Down Right
            如果找到拓展时找到目标结点，返回true
        */
    if ((node->index + 1) % 3 != 1)
    {
        Node *temp = move(node, Left);
        if (isExist(temp) == false)
        {
            node->children.push_back(temp);	//加入搜索树
            Open.push_back(temp);
            if ((isEqual(temp, target)) == true)
                return true;
        }
        else
            delete temp;
    }
    if (node->index > 2)
    {
        Node *temp = move(node, Up);
        if (isExist(temp) == false)
        {
            node->children.push_back(temp);	//加入搜索树
            Open.push_back(temp);
            if ((isEqual(temp, target)) == true)
                return true;
        }
        else
            delete temp;
    }
    if (node->index < 6)
    {
        Node *temp = move(node, Down);
        if (isExist(temp) == false)
        {
            node->children.push_back(temp);	//加入搜索树
            Open.push_back(temp);
            if ((isEqual(temp, target)) == true)
                return true;
        }
        else
            delete temp;
    }
    if ((node->index + 1) % 3 != 0)
    {
        Node *temp = move(node, Right);
        if (isExist(temp) == false)
        {
            node->children.push_back(temp);	//加入搜索树
            Open.push_back(temp);
            if ((isEqual(temp, target)) == true)
                return true;
        }
        else
            delete temp;
    }
    return false;
}

bfs::bfs(string m_start,string m_target)
{
    _REACH = false;

    start = new Node;
    start->index=setCord(start->code,m_start);
    start->parent = nullptr;
    start->action = Nothing;

    target = new Node;
    target->index=setCord(target->code,m_target);
    target->parent = nullptr;
    target->action = Nothing;
}

bfs::~bfs()
{
    free(start);
    delete target;
    target = nullptr;
    Open.clear();
    Closed.clear();
}

unsigned long bfs::getOPEN() const
{
    return Open.size();
}

unsigned long bfs::getCLOSED() const
{
    return Closed.size();
}

void bfs::BfsSearch()
{
    _REACH=false;
    Node* node;
    //初始状态进队列
    Open.push_back(start);
    while ( !Open.empty() && _REACH!=true )	//找到目标结点即停止，不要求Open表为空
    {
        node = Open.front();
        if (bfs_expand(node) == true)
            _REACH = true;
        Open.pop_front();
        Closed.push_back(node);
    }
}
