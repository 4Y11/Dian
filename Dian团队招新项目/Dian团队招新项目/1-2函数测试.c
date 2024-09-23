#include <stdio.h>

void buy_goods(int price) {               //购买函数（涵括找零功能）
	int coin;         //用户单次投入的硬币价值
	int sum;             //用户投入的硬币总额
	int change;          //找零
	int i;               //用户购买商品数量
	int total;           //商品总价
	
	printf("请问您要买多少：\n");
	scanf_s("%d", &i);
	total = i * price;
	
	while (1) {
		printf("请投币（只能投1，2，5元）：\n");
		scanf_s("%d", &coin);
		if (!(coin == 1 || coin == 2 || coin == 5)) {
			printf("只能输入1，2，5元哟");
			continue;
		}                                 //判断用户输入的金额是否满足要求
		
		sum += coin;
		
		if (sum < total) {                 //判断总额能否成功购买
			printf("钱不够呢，请继续投币\n");
			continue;                     //钱不够，跳过本次循环
		}
		
		else {
			printf("购买成功，请记得取走您的零钱\n");
			change = sum - total;
			printf("您的找零为%d元 ，欢迎下次再来\n", change);
			break;                       //购买成功，跳出循环
		}
	
	}

}





void Trade() {                          //判断用户需要交易的商品的函数
	printf("请输入您要购买的商品名：\n");     
	char name;
	scanf_s("%c", &name,1);
	
	switch (name) {           
	case 'A': 
		buy_goods(goods_A.price);
		break;
	case'B':
		buy_goods(goods_B.price);
		break;
	case'C':
		buy_goods(goods_C.price);

	}

}