/***˳��ջ��ʵ��***/
#include<iostream>
#include<stdlib.h>
using namespace std;

//˳��ջ����
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE  100//˳��ջ�洢�ռ�ĳ�ʼ������
typedef int Status;
typedef int SElemType;

typedef struct {
	SElemType *base;//ջ��ָ��
	SElemType *top;//ջ��ָ��
	int stacksize;//ջ���õ��������
} SqStack;

//�㷨3.1��˳��ջ�ĳ�ʼ��
Status InitStack(SqStack &S) {
	//����һ����ջS
	S.base = new SElemType[MAXSIZE];//Ϊ˳��ջ��̬����һ���������ΪMAXSIZE������ռ�
	if (!S.base)
		exit(OVERFLOW); //�洢����ʧ��
	S.top = S.base; //top��ʼΪbase����ջ
	S.stacksize = MAXSIZE; //stacksize��Ϊջ���������MAXSIZE
	return OK;
}
//�㷨3.2��˳��ջ����ջ
Status Push(SqStack &S, SElemType e) {
	// ����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S.top - S.base == S.stacksize)
		return ERROR; //ջ��
	*(S.top++) = e; //Ԫ��eѹ��ջ����ջ��ָ���1
	return OK;
}
//�㷨3.3��˳��ջ�ĳ�ջ
Status Pop(SqStack &S, SElemType &e) {
	//ɾ��S��ջ��Ԫ�أ���e������ֵ	
	if (S.base == S.top)
		return ERROR;//ջ��
	e = *(--S.top); //ջ��ָ���1����ջ��Ԫ�ظ���e
	return OK;
}
//�㷨3.4��ȡ˳��ջ��ջ��Ԫ��
SElemType GetTop(SqStack S) {//����S��ջ��Ԫ�أ����޸�ջ��ָ��
	if (S.top != S.base) //ջ�ǿ�
		return *(S.top - 1); //����ջ��Ԫ�ص�ֵ��ջ��ָ�벻��
}

int StackEmpty(SqStack S)
{//�ж�ջ�Ƿ�ǿգ��շ���1���ǿշ���0
     	if (S.top == S.base) //ջ��
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
			  { //����ջ�쳣ʱ�����"POP ERROR",��������
			     cout<<"POP ERROR"<<endl;
			     break;			    				
			  } 
			else
			  cout<<temp<<endl;
		}			 
	}
	if(StackEmpty(s))
	   cout<<"ջ�գ�"<<endl;	  
	else
	   cout<<"ջ��Ԫ��Ϊ�� "<<GetTop(s)<<endl;
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
