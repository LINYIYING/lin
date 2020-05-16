#include<string.h>
#include<stdlib.h>
#include<iostream>  
#include<iomanip> //是I/O流控制头文件，主要是对cin,cout之类的一些操纵运算子 
#include<math.h> //后面用到了绝对值函数fabs() 
using namespace std;
#define OK 1
#define ERROR 0
//#define OVERFLOW -2
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。


typedef struct  {
	char id[15];//ISBN     
	char name[50];//书名   
	double price;//定价
}ElemType;
typedef struct LNode {
	ElemType data; //数据域
	struct LNode *next; //指针域 
} LNode,*LinkList;

Status InitList(LinkList &L) { //算法2.6 单链表的初始化
	//构造一个空的单链表L
	L = new LNode; //生成新结点作为头结点，用头指针L指向头结点
	if(!L)
	  exit(OVERFLOW); 
	L->next = NULL; //头结点的指针域置空
	return OK;
}

Status GetElem(LinkList L, int i, ElemType &e) { //算法2.7 单链表的取值
	//在带头结点的单链表L中查找第i个元素
	//用e返回L;中第i个数据元素的值
	LinkList p;
	p=L->next;int j;j=1;
	while(p&&j<i)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i)return ERROR;
	e=p->data;
	return OK;
	
	
	
	
} //GetElem

LNode *LocateElem(LinkList L, double e) { //算法2.8 按值查找
	//在带头结点的单链表L中查找值为e的元素
LinkList p;
p=L->next;
while(fabs(p && p->data.price-e<1e-6))
p=p->next;
return p;




} //LocateElem

Status ListInsert(LinkList &L, int i, ElemType &e) { //算法2.9 单链表的插入
	//在带头结点的单链表L中第i个位置插入值为e的新结点
LinkList p;int j;LinkList s;
p=L;j=0;
while(p && (j<i-1))
{p=p->next;++j;
}
if(!p||j>i-1)return ERROR;
s=new LNode;
s->data=e;
s->next=p->next;
p->next=s;
return OK;






} //ListInsert

Status ListDelete(LinkList &L, int i) { //算法2.9 单链表的删除
	//在带头结点的单链表L中，删除第i个位置	
	LinkList p;int j;LinkList q;
	p=L;j=0;
	while((p->next) && (j<i-1))
	{p=p->next;++j;
	}
	if(!(p->next)||(j>i-1))return ERROR;
	q=p->next;
	p->next=q->next;
	delete q;
	return OK;
	
	
	
	
} //ListDelete



void CreateList_R(LinkList &L, int n) 
{ //算法2.12 后插法创建单链表
	//正位序输入n个元素的值，建立带表头结点的单链表L 
	int i;LinkList p;LinkList r;
	L=new LNode;
	r=L;
	for(i=0;i<n;++i)
	{
		p=new LNode;
		cin>>p->data.price;
		p->next=NULL;r->next=p;
		r=p;
	}
	
	
	
	
} 
 
void CreateList_H(LinkList &L, int n)
 { //算法2.11 前插法创建单链表
	//逆位序输入n个元素的值，建立带表头结点的单链表L 
		int i;LinkList p;
	L=new LNode;
	L->next=NULL;
	for(i=0;i<n;++i)
	{
		p=new LNode;
		cin>>p->data.price;
		p->next=L->next;L->next=p;
	}
	
	
	
	
}

void TraverseList(LinkList L)
{
	 LNode *p;
	 p=L->next;
	 while(p)
	 {
	 	cout << left << setw(15) << p->data.id  
		     << left<< setw(50) << p->data.name  
		     << left<< setw(5) << p->data.price << endl;
		p=p->next;
	 }	
	 cout << endl;
}


int main() {
	LinkList L;
	LNode *p,*q,*r;
	int i = 0, temp, a, c, choose,n;
	double price;
	ElemType e;
	cout << "1. 建立\n";
	cout << "2. 取值\n";
	cout << "3. 查找\n";
	cout << "4. 插入\n";
	cout << "5. 删除\n";
	cout << "6. 输出\n";
	cout << "7. 输入-后插法创建单链表\n";
	cout << "8. 输入-前插法创建单链表\n";
	cout << "0. 退出\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "请选择:";
		cin >> choose;
		switch (choose) {
		case 1://创建链表
			if (InitList(L))
				cout << "成功建立链表\n\n";
			else
				cout << "链表建立失败\n\n";
			break;
	
		case 2://链表的取值
			cout << "请输入一个位置用来取值：\n";
			cin >> i;
			temp = GetElem(L, i, e);
			if (temp != 0) {
				cout << "查找成功\n";
				cout << "第" << i << "本图书的信息是：\n";
				cout << left << setw(15) << e.id  << left << setw(50)
						<< e.name  << left << setw(5) << e.price << endl
						<< endl;
			} else
				cout << "查找失败！位置超出范围\n\n";
			break;
		case 3: //链表的查找
			cout << "请输入所要查找价格:";
			cin >> price;
			r = LocateElem(L, price);
			if (r) {
				cout << "查找成功\n";
				cout << "该价格对应的书名为：" << r->data.name << endl << endl;
			} else
				cout << "查找失败！没有这个价格对应的书籍\n\n";
			break;
		case 4: //链表的插入
			cout << "请输入插入的位置和书本信息，包括：编号 书名 价格（用空格隔开）:";
			cin >> a;
			cin >> e.id >> e.name >> e.price; 
			if (ListInsert(L, a, e))
				cout << "插入成功.\n\n";
			else
				cout << "插入失败.\n\n";
			break;
		case 5: //链表的删除
			cout << "请输入所要删除的书籍的位置:";
			cin >> c;
			if (ListDelete(L, c))
				cout << "删除成功.\n\n";
			else
				cout << "删除失败.\n\n";
			break;
		case 6: //链表的输出
			cout << "当前图书系统信息（顺序表）读出:\n";
	     	TraverseList(L);
			break;
		
		case 7: //链表信息输入-后插法创建单链表
		    cout << "请输入录入信息的个数 ：\n";
			cin >> n;
			cout << "请按照：书号 书名 价格 依次输入书目信息\n\n"; 
			CreateList_R(L,n);
		    cout << "输入信息完毕\n\n";
		
			break;
		case 8: //链表信息输入-前插法创建单链表
		    cout << "请输入录入信息的个数 ：\n";
			cin >> n;
			cout << "请按照：书号 书名 价格 依次输入书目信息\n\n"; 
			CreateList_H(L,n);
		    cout << "输入信息完毕\n\n";
		
			break;
		
		 
	
		}
	}
	return 0;
}
