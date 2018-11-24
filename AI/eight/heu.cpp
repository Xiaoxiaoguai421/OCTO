#include "heu.h"

bool heu::getREACH() const
{
    return _REACH;
}

void heu::free(Node *p)
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

void heu::free_tab(Node *p)
{
    if(nullptr == p)
        return;
    free_tab(p->next);
    delete p;
    p=nullptr;
}

size_t heu::setCord(char *code1, string code2)
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

void heu::setCord(char *code1, const char *code2)
{
    for (size_t i = 0; i < 9; i++)
        code1[i] = code2[i];
}

void heu::swap(char *a, size_t index_1, size_t index_2)
{
    char temp = a[index_1];
    a[index_1] = a[index_2];
    a[index_2] = temp;
}

bool heu::isEqual(Node *v1, Node *v2)
{
    for (size_t i = 0; i < 9; i++)
        if (v1->code[i] != v2->code[i])
            return false;
    return true;
}

Node *heu::move(Node *node, ACTION act)
{
    //生成结点
    Node *temp = new Node;
    temp->parent = node;
    temp->index = node->index;
    setCord(temp->code, node->code);
    temp->depth = node->depth + 1;
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
    temp->f = temp->depth + missCord(temp);
    temp->next = nullptr;
    return temp;
}

int heu::missCord(Node *p)
{
    int cnt = 0;
    for (size_t i = 0; i < 9; i++)
    {
        if (p->code[i] != target->code[i])
            cnt++;
    }
    return cnt;
}

void heu::insert_open(Node *p)
{
    Node* q = Open_heuristic.next;
    if (q == nullptr)
    {
        Open_heuristic.next = p;
        return;
    }
    if ((q->f) > (p->f))	//插到最前面
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
    q->next = p;	//插到最后
    p->next = k;
}

void heu::heu_expand(Node *node)
{
    if ((node->index + 1) % 3 != 1)
    {
        Node* temp = move(node,Left);
        //搜索树中只有一个父辈节点,新生成的节点都是新节点
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

heu::heu(string m_start,string m_target)
{
    _REACH = false;

    target = new Node;
    target->index=setCord(target->code,m_target);
    target->parent = nullptr;
    target->action = Nothing;
    target->depth=0;
    target->f=0;
    target->next=nullptr;

    start = new Node;
    start->index=setCord(start->code,m_start);
    start->parent = nullptr;
    start->action = Nothing;
    start->depth=0;
    start->f=missCord(target);
    start->next=nullptr;
}

heu::~heu()
{
    //释放搜索树
    free(start);
    delete target;
    target = nullptr;
    free_tab(Open_heuristic.next);
    free_tab(Closed_heuristic.next);
}

void heu::HeuSearch()
{
    _REACH = false;
    Open_heuristic.next= start;
    Closed_heuristic.next = nullptr;
    while(Open_heuristic.next != nullptr)
    {
        Node* p = Open_heuristic.next;
        Open_heuristic.next = p->next;	//移出open
        p->next = Closed_heuristic.next;	//移入closed
        Closed_heuristic.next = p;
        //找到目标节点
        if (isEqual(p, target))
        {
            _REACH = true;
            break;
        }
        heu_expand(p);	//拓展节点
    }
}

unsigned long heu::getOPEN() const
{
    unsigned long cnt=0;
    Node* p = Open_heuristic.next;
    while(nullptr!=p)
    {
        cnt++;
        p=p->next;
    }
    return cnt;
}

unsigned long heu::getCLOSED() const
{
    unsigned long cnt=0;
    Node* p = Closed_heuristic.next;
    while(nullptr!=p)
    {
        cnt++;
        p=p->next;
    }
    return cnt;
}






