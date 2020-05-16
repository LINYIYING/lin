/***顺序栈的实现***/
#include<iostream>
#include<stdlib.h>
using namespace std;

//顺序栈定义
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE  100//顺序栈存储空间的初始分配量
typedef int Status;
typedef int SElemType;

typedef struct {
	SElemType *base;//栈底指针
	SElemType *top;//栈顶指针
	int stacksize;//栈可用的最大容量
} SqStack;

//算法3.1　顺序栈的初始化
Status InitStack(SqStack &S) {
	//构造一个空栈S
	S.base = new SElemType[MAXSIZE];//为顺序栈动态分配一个最大容量为MAXSIZE的数组空间
	if (!S.base)
		exit(OVERFLOW); //存储分配失败
	S.top = S.base; //top初始为base，空栈
	S.stacksize = MAXSIZE; //stacksize置为栈的最大容量MAXSIZE
	return OK;
}
//算法3.2　顺序栈的入栈
Status Push(SqStack &S, SElemType e) {
	// 插入元素e为新的栈顶元素
	if (S.top - S.base == S.stacksize)
		return ERROR; //栈满
	*(S.top++) = e; //元素e压入栈顶，栈顶指针加1
	return OK;
}
//算法3.3　顺序栈的出栈
Status Pop(SqStack &S, SElemType &e) {
	//删除S的栈顶元素，用e返回其值	
	if (S.base == S.top)
		return ERROR;//栈空
	e = *(--S.top); //栈顶指针减1，将栈顶元素赋给e
	return OK;
}
//算法3.4　取顺序栈的栈顶元素
SElemType GetTop(SqStack S) {//返回S的栈顶元素，不修改栈顶指针
	if (S.top != S.base) //栈非空
		return *(S.top - 1); //返回栈顶元素的值，栈顶指针不变
}

int StackEmpty(SqStack S)
{//判定栈是否非空，空返回1，非空返回0
     	if (S.top == S.base) //栈空
     	  return 1;
     	else
     	  return 0;
}

int main()
{	
	SqStack s;
	int n,t;
	SElemType e,temp;
	InitStack(s);
	cin>>n;
	while(n--)
	{			
		cin>>e; 
		if(e!=-1)
		   Push(s,e);
		else
		{
			t=Pop(s,temp);
			if(t==0)
			  { //当出栈异常时，输出"POP ERROR",并结束。
			     cout<<"POP ERROR"<<endl;
			     break;			    				
			  } 
			else
			  cout<<temp<<endl;
		}			 
	}
	if(StackEmpty(s))
	   cout<<"栈空！"<<endl;	  
	else
	   cout<<"栈顶元素为： "<<GetTop(s)<<endl;
	return 0;
}



void conversion(int N)
{
InitStack(S);
while(N)
{
	Push(S,N%8);
	N=N/8;
 } 
 while(!StackEmpty(S))
 {
 	Pop(S,e);
 	cout<<e;
 }
}



Status Matching()
{
	InitStack(S);
	flag=1;
	cin>>ch;
	while(ch!='#'&&flag)
	{
		switch(ch)
		{
			case'['||'(':
				Push(S,ch);
				break;
				case')':
					if(!StackEmoty(S)&&GetTop(S)=='(')
					Pop(S,x);
					else flag=0;
					break;
					ease']':
						if(!StackEmpty(s)&&GetTop(S)=='[')
						Pop(S,x);
						else flag=0;
						break;
		}
		cin>>ch;
	}
	if(StackEmpty(S)&&flag) return ture;
	else return false;
}
