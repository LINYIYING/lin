// trade_commodity.cpp : 定义控制台应用程序的入口点。
#include <string.h>
#include <list>
#include "stdafx.h"
#include "trade.h"
#include <iostream>

void drawBuyRecord()
{
	system("cls");
	printf("\t ════════════════════════════ \n");
	printf("\t               ***** 采购记录 *****                         \n");
	printf("\t ════════════════════════════ \n");
}

void drawSellRecord()
{
	system("cls");
	printf("\t ════════════════════════════ \n");
	printf("\t               ***** 销售记录 *****                         \n");
	printf("\t ════════════════════════════ \n");
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
		printf("请输入您的选项:");
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
				printf("操作成功,");
			}
			else
			{
				system("cls");
				printf("您的输入有误,");
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
				printf("操作成功,");
			}
			else
			{
				system("cls");
				printf("您的输入有误,");
			}
			operate();
			break;

		case 3:
			char name[30];
			float value;
			float cost;
			system("cls");
			cout << "请输入新品的名称" << endl;
			cin >> name;
			getchar();
			cout << "请输入购入价格" << endl;
			cin >> cost;
			getchar();
			cout << "请输入出售价格" << endl;
			cin >> value;
			getchar();
			myTrade.AddNew(name, cost, value);
			system("cls");
			printf("操作成功,");
			operate();
			break;

		case 4:
			drawIndex();
			myTrade.GetIndex();
			drawLine();
			cout << "请输入商品编号:";
			int index;
			cin >> index;
			getchar();
			system("cls");
			if (!myTrade.GetInformathion(index))
			{
				cout << "无效的商品编号，";
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
			printf("无效的选项，");
			operate();
		}
	}

	myTrade.save();
	return 0;
}

