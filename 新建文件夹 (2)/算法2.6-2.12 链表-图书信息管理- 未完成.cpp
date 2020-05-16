#include<string.h>
#include<stdlib.h>
#include<iostream>  
#include<iomanip> //��I/O������ͷ�ļ�����Ҫ�Ƕ�cin,cout֮���һЩ���������� 
#include<math.h> //�����õ��˾���ֵ����fabs() 
using namespace std;
#define OK 1
#define ERROR 0
//#define OVERFLOW -2
typedef int Status; //Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣


typedef struct  {
	char id[15];//ISBN     
	char name[50];//����   
	double price;//����
}ElemType;
typedef struct LNode {
	ElemType data; //������
	struct LNode *next; //ָ���� 
} LNode,*LinkList;

Status InitList(LinkList &L) { //�㷨2.6 ������ĳ�ʼ��
	//����һ���յĵ�����L
	L = new LNode; //�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
	if(!L)
	  exit(OVERFLOW); 
	L->next = NULL; //ͷ����ָ�����ÿ�
	return OK;
}

Status GetElem(LinkList L, int i, ElemType &e) { //�㷨2.7 �������ȡֵ
	//�ڴ�ͷ���ĵ�����L�в��ҵ�i��Ԫ��
	//��e����L;�е�i������Ԫ�ص�ֵ
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

LNode *LocateElem(LinkList L, double e) { //�㷨2.8 ��ֵ����
	//�ڴ�ͷ���ĵ�����L�в���ֵΪe��Ԫ��
LinkList p;
p=L->next;
while(fabs(p && p->data.price-e<1e-6))
p=p->next;
return p;




} //LocateElem

Status ListInsert(LinkList &L, int i, ElemType &e) { //�㷨2.9 ������Ĳ���
	//�ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½��
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

Status ListDelete(LinkList &L, int i) { //�㷨2.9 �������ɾ��
	//�ڴ�ͷ���ĵ�����L�У�ɾ����i��λ��	
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
{ //�㷨2.12 ��巨����������
	//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L 
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
 { //�㷨2.11 ǰ�巨����������
	//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L 
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
	cout << "1. ����\n";
	cout << "2. ȡֵ\n";
	cout << "3. ����\n";
	cout << "4. ����\n";
	cout << "5. ɾ��\n";
	cout << "6. ���\n";
	cout << "7. ����-��巨����������\n";
	cout << "8. ����-ǰ�巨����������\n";
	cout << "0. �˳�\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "��ѡ��:";
		cin >> choose;
		switch (choose) {
		case 1://��������
			if (InitList(L))
				cout << "�ɹ���������\n\n";
			else
				cout << "������ʧ��\n\n";
			break;
	
		case 2://�����ȡֵ
			cout << "������һ��λ������ȡֵ��\n";
			cin >> i;
			temp = GetElem(L, i, e);
			if (temp != 0) {
				cout << "���ҳɹ�\n";
				cout << "��" << i << "��ͼ�����Ϣ�ǣ�\n";
				cout << left << setw(15) << e.id  << left << setw(50)
						<< e.name  << left << setw(5) << e.price << endl
						<< endl;
			} else
				cout << "����ʧ�ܣ�λ�ó�����Χ\n\n";
			break;
		case 3: //����Ĳ���
			cout << "��������Ҫ���Ҽ۸�:";
			cin >> price;
			r = LocateElem(L, price);
			if (r) {
				cout << "���ҳɹ�\n";
				cout << "�ü۸��Ӧ������Ϊ��" << r->data.name << endl << endl;
			} else
				cout << "����ʧ�ܣ�û������۸��Ӧ���鼮\n\n";
			break;
		case 4: //����Ĳ���
			cout << "����������λ�ú��鱾��Ϣ����������� ���� �۸��ÿո������:";
			cin >> a;
			cin >> e.id >> e.name >> e.price; 
			if (ListInsert(L, a, e))
				cout << "����ɹ�.\n\n";
			else
				cout << "����ʧ��.\n\n";
			break;
		case 5: //�����ɾ��
			cout << "��������Ҫɾ�����鼮��λ��:";
			cin >> c;
			if (ListDelete(L, c))
				cout << "ɾ���ɹ�.\n\n";
			else
				cout << "ɾ��ʧ��.\n\n";
			break;
		case 6: //��������
			cout << "��ǰͼ��ϵͳ��Ϣ��˳�������:\n";
	     	TraverseList(L);
			break;
		
		case 7: //������Ϣ����-��巨����������
		    cout << "������¼����Ϣ�ĸ��� ��\n";
			cin >> n;
			cout << "�밴�գ���� ���� �۸� ����������Ŀ��Ϣ\n\n"; 
			CreateList_R(L,n);
		    cout << "������Ϣ���\n\n";
		
			break;
		case 8: //������Ϣ����-ǰ�巨����������
		    cout << "������¼����Ϣ�ĸ��� ��\n";
			cin >> n;
			cout << "�밴�գ���� ���� �۸� ����������Ŀ��Ϣ\n\n"; 
			CreateList_H(L,n);
		    cout << "������Ϣ���\n\n";
		
			break;
		
		 
	
		}
	}
	return 0;
}
