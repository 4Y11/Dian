#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>




struct Channel {
	int number;     //通道号
	int count;		//商品数
	char name[10];		//商品名
	int price;      //通道商品的单价
};


struct Channel channel[5];    //含五个通道的结构体数组


struct Channel init_channel1(struct Channel channel1[]) {            //初始化通道

	for (int i = 1; i < 6; i++) {
		printf("这是%d号通道，请输入所摆放商品的名称（不在此通道摆放请输入END，如想要撤销上步摆放操作请直接输入back）：\n", i);
		scanf_s("%s", &channel[i - 1].name, 10);
		fflush(stdin);

		if (strcmp(channel[i - 1].name, "END") == 0) {                //用户输入END时，将该通道商品数量定为0
			channel[i - 1].count = 0;
			continue;
		}
		else if (strcmp(channel[i - 1].name, "back") == 0) {       //用户选择撤销（back）时，i-2对i进行重新输入
			i -= 2;
		}
		else {
			printf("请输入摆放商品的数量和价格（请用用空格隔开）：\n");
			scanf_s("%d %d", &channel[i - 1].count, &channel[i - 1].price);

		}
	}
	return *channel1;
}







void show_channel(struct Channel channels[]) {       //用于查看通道状态的函数

	for (int i = 1; i < 6; i++) {

		printf("%d: ", i);

		if (channels[i - 1].count <= 0) {
			printf("该通道没有商品啦！\n");	    	//对于缺少货物的处理
		}
		else {
			for (int j = 0; j < channels[i - 1].count; j++) {
				printf("%s", channels[i - 1].name);
			}
			printf("   %d元/件\n", channels[i - 1].price);
		}
	}

}







void Trade(struct Channel channel[]) {                   //购买函数（包括找零）


	char goods_name[10];                   //检查商品名及END符号
	int goods_count;						//需要购买的商品数量
	int goods_channel;						//商品所在通道
	int count[5] = { 0,0,0,0,0 };								//用于储存所买商品数量的数组
	int price[5] = { 0,0,0,0,0 };							//对应通道货物的价格
	bool enough;                            //判断所需货物量是否足够的布尔变量

	int i = 0;
	while (1) {
		printf("请输入你要购买的商品名，所在通道和数量（请用空格隔开，结束选择请直接输入END ,如想撤销上步购买请直接输入back）：\n");
		scanf_s("%s", goods_name, 10);
		fflush(stdin);

		if (strcmp(goods_name, "END") == 0) {
			break;
		}
		else if (strcmp(goods_name, "back") == 0) {
			count[i - 1] = 0;
			price[i - 1] = 0;
			i -= 2;
		}	
		else {
			scanf_s(" %d %d", &goods_channel, &goods_count);
			enough = (goods_count <= (channel[goods_channel - 1]).count) ? 1 : 0;     //货物是否充足
			switch (enough) {
			case 0:
				printf("货物不够啦，换个通道买或者少买一点吧！\n");
				break;
			case 1:
				count[i] = goods_count;
				price[i] = (channel[goods_channel - 1]).price;
				fflush(stdin);
				(channel[goods_channel - 1]).count -= goods_count;
				break;

			}


		}

		i++;
	}

	register int sum = 0;		            //用户投入的硬币总额
	int coin;					//用户投入的硬币
	int change;                 //找零
	int total = 0;					//商品总价


	for (i = 0; i < 5; i++) {
		total += count[i] * price[i];
	}                                         //计算总价




	while (1) {                                    //开始投币和找零操作
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









int main() {
	*channel = init_channel1(channel);

	printf("请输入要执行的操作： 1: 购买商品 ， 2：查看通道状态 ， 0：结束购物\n");

	int x;
	scanf_s("%d", &x);
	switch (x) {                                      //检验x的值，跳转对应操作
	case 1:
		Trade(channel);
		break;
	case 2:
		show_channel(channel);
		break;
	case 0:
		printf("使用完毕，欢迎下次再来！");
		exit(0);
		break;
	}

	while (1) {                                     //反复循环，直到用户输入0以退出程序
		printf("请输入要执行的操作： 1: 继续购买商品 ， 2：查看通道状态 ， 0：结束购物\n");
		int x;
		scanf_s("%d", &x);
		switch (x) {
		case 1:
			Trade(channel);
			break;
		case 2:
			show_channel(channel);
			break;
		case 0:
			printf("使用完毕，欢迎下次再来！");
			exit(0);
			break;

		}




	}
}