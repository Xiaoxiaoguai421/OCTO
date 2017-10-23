/*************************************************************************
	> File Name: SeqStack.h
	> Author:
	> Mail: 
	> Created Time: 2017年10月22日 星期日 15时27分03秒
 ************************************************************************/

#ifndef _SEQSTACK_H
#define _SEQSTACK_H
template<class T,int MaxSize>
class SeqStack{
    T data[MaxSize];
    int top;
public:
    SeqStack();
    void push(T x);  
    T Pop();
    T Top();
    bool Empty();
    bool Full();
}
#endif
