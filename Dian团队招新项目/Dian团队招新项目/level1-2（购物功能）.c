#include <stdio.h>
#include <stdlib.h>
struct Goods {                         //货物结构体
	int price;            //货物单价
	int channel;          //货物所在通道
	char name[100];       //货物名称
	int count;            //货物数量
};




struct Goods init_goods() {         //用于初始化货物结构体的函数 init_goods
	struct Goods goods;
	printf("请输入货物所在的通道：\n");
	scanf_s("%d", &goods.channel);
	
	printf("请输入货物的名称(请勿输入空格）：\n");
	scanf_s("%s", &goods.name, 100);
	
	printf("请输入货物的单价：\n");
	scanf_s("%d", &goods.price);

	printf("请输入货物的数量：\n");
	scanf_s("%d", &goods.count);

	
	return goods;                            //初始化函数结束
}







void buy_goods(int price) {               //购买函数（涵括找零功能）
	int coin;                //用户单次投入的硬币价值
	int sum = 0;             //用户投入的硬币总额
	int change;              //找零
	int i;                  //用户购买商品数量
	int total;             //商品总价

	printf("请输入您要购买的数量：\n");
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

}                        //购买函数buy_goods完毕


                  
	void Trade(char name , struct Goods goods_A ) {                          //判断用户需要交易的商品的函数
		                           //判断用户需要交易的商品的函数
	switch (name) {
	case 'A':
		buy_goods(goods_A.price);
		break;
	

	}

}                           //Trade函数完毕

int main() {
	
	struct Goods goods_A = init_goods();        //初始化货物A
	
	char name1;
	printf("请输入您要购买的商品名：\n");
	scanf_s(" %c", &name1 , 100);
	Trade(name1 , goods_A );
}