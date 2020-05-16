// trade_commodity.cpp : �������̨Ӧ�ó������ڵ㡣
#include <string.h>
#include <list>
#include "stdafx.h"
#include "trade.h"
#include <iostream>

void drawBuyRecord()
{
	system("cls");
	printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
	printf("\t               ***** �ɹ���¼ *****                         \n");
	printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
}

void drawSellRecord()
{
	system("cls");
	printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
	printf("\t               ***** ���ۼ�¼ *****                         \n");
	printf("\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
}

int main(int argc, _TCHAR* argv[])
{
	trade myTrade;

	if (!myTrade.init())
	{
		myTrade = trade();
	}

	bool quitFlag = false;
	while (!quitFlag)
	{
		DrawMainMenu();
		printf("����������ѡ��:");
		int selection;
		cin >> selection;
		getchar();
		int ID;
		int count;

		switch (selection)
		{
		case 1:
			drawIndex();
			myTrade.GetIndex();
			drawLine();
			ToBuy(ID, count);
			if (myTrade.Buy(ID, count))
			{
				system("cls");
				printf("�����ɹ�,");
			}
			else
			{
				system("cls");
				printf("������������,");
			}
			operate();
			break;

		case 2:
			drawIndex();
			myTrade.GetIndex();
			drawLine();
			ToSell(ID, count);
			if (myTrade.Sell(ID, count))
			{
				system("cls");
				printf("�����ɹ�,");
			}
			else
			{
				system("cls");
				printf("������������,");
			}
			operate();
			break;

		case 3:
			char name[30];
			float value;
			float cost;
			system("cls");
			cout << "��������Ʒ������" << endl;
			cin >> name;
			getchar();
			cout << "�����빺��۸�" << endl;
			cin >> cost;
			getchar();
			cout << "��������ۼ۸�" << endl;
			cin >> value;
			getchar();
			myTrade.AddNew(name, cost, value);
			system("cls");
			printf("�����ɹ�,");
			operate();
			break;

		case 4:
			drawIndex();
			myTrade.GetIndex();
			drawLine();
			cout << "��������Ʒ���:";
			int index;
			cin >> index;
			getchar();
			system("cls");
			if (!myTrade.GetInformathion(index))
			{
				cout << "��Ч����Ʒ��ţ�";
				operate();
			}
			else{
				operate();
			}
			break;

		case 5:
			drawBuyRecord();
			myTrade.getBuyRecord();
			operate();
			break;

		case 6:
			drawSellRecord();
			myTrade.getSellRecord();
			operate();
			break;

		case 7:
			quitFlag = true;
			break;

		default:
			system("cls");
			printf("��Ч��ѡ�");
			operate();
		}
	}

	myTrade.save();
	return 0;
}

