// 超市采购系统.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Commodity.h"
#include<iostream>
using namespace std;
int main(){
	int opt; //输入的操作指令
	Commodity com; //商品对象
	com.Create_File();
	//com.Login();
	fstream File;
	
	Node temp; //用于存放临时变量的商品结点
	Node *s = com.head; //链表的头结点
	
	// 将文件中的商品信息写入链表
	for (int i = 0; !File.eof(); i++) {
		File.open("stock.txt", ios::in | ios::binary);
		Node *q = new Node;
		File.seekg(i * sizeof(Node), ios::beg);
		File.read((char *)&temp, sizeof(Node));
		q->ID = temp.ID;
		q->Name = temp.Name;
		q->Num = temp.Num;
		q->BuyIn = temp.BuyIn;
		q->SellOut = temp.SellOut;
		q->Next = NULL;
		s->Next = q;
		s = s->Next;
		File.close();
	}
	do{
		cout  <<"\t╔═══════════════════════════╗\n";
		cout  <<"\t║               欢迎使用超市采购系统                   ║\n";
		cout  <<"\t╠═══════════════════════════╣\n";
		cout << "\t║                 1 -   添加新品                       ║\n";
		cout << "\t║                 2 -   下架商品                       ║\n";
		cout << "\t║                 3 -   买入商品                       ║\n";
		cout << "\t║                 4 -   卖出商品                       ║\n";
		cout << "\t║                 5 -   修改商品                       ║\n";
		cout << "\t║                 6 -   统计商品                       ║\n";
		cout << "\t║                 7 -   查询商品                       ║\n";
		cout << "\t║                 8 -   查看商品                       ║\n";
		cout << "\t║                 9 -   注册账号	                   ║\n";
		cout << "\t║                 10 -   查询日志记录                  ║\n";
		cout << "\t║                 11 -   退出                          ║\n";
		cout << "\t╚═══════════════════════════╝\n";
		cin >> opt;
		if (cin.fail()){
			// 解决因输入错误类型而导致的回调问题
			cin.clear();
			system("cls");
			cout << "无效编号！请重新输入" << endl;
			cin.get();
			continue;
		}else{
			switch (opt) {
			case 1:com.AddNew();	break;
			case 2:com.del_info();  break;
			case 3:com.Buy();		break;
			case 4:com.Sell();		break;
			case 5:com.Modify();	break;
			case 6:com.Add_up();	break;
			case 7:com.GetInformathion();	break;
			case 8:com.Sort();		break;
			case 9:com.Register();	break;
			case 10:com.ShowJournal();		break;
			case 11:
				com.Save();
				exit(0);
			default:
				system("cls");
				cout << "无效编号！请重新输入" << endl;
				break;
			}
		}
	} while (true);
	return 0;
}

