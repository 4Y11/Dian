#include <stdio.h>
#include <stdlib.h>

struct Channel {
	int number;     //通道号
	int count;		//商品数
	char name;		//商品名
	int price;      //通道商品的单价
};

struct Channel init_channel(struct Channel channel) {             //初始化通道的函数【摆放商品（按通道摆放）】

	printf("这是%d号通道\n", channel.number);

	printf("请输入您要摆放的商品名和数量(用空格隔开 , 不摆放请在数量处输入0）：\n");
	scanf_s(" %c %d", &channel.name, 1, &channel.count);
	fflush(stdin);


	if (channel.count != 0) {
		printf("该商品的定价为：\n");
		scanf_s("%d", &channel.price);
	}
	else {
		return channel;
	}

	return channel;											//待完善的函数

}




void show_channel(struct Channel channels) {       //用于查看通道状态的函数
	printf("%d: ", channels.number);

	if (channels.count <= 0) {
		printf("该通道没有商品啦！\n");	    	//对于缺少货物的处理
	}
	else {
		for (int i = 0; i < channels.count; i++) {
			printf("%c", channels.name);
		}
		printf("   %d元/件\n", channels.price);
	}


}





void buy_goods1(struct Channel* ptr) {                              //购买函数
	int coin;                  //用户单次投入的硬币价值 
	int sum = 0;                   //用户投入的硬币总额
	int change;               //找零
	int i;                    //用户购买商品数量
	int total;               //商品总价



	while (1) {

		if ((ptr->count) <= 0) {
			printf("这个通道没货啦，换一个吧！\n");
			return 0;
		}
		else {
			printf("请输入您要购买的数量：\n");
			scanf_s("%d", &i);
			if (i > (ptr->count)) {
				printf("商品数量不够了哦，这一次可以少买一点\n");
			}
			else {
				break;
			}
		}
	}


	total = i * (ptr->price);


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


	ptr->count -= i;

}                        //购买函数buy_goods完毕





void Trade(struct Channel* channel_1, struct Channel* channel_2, struct Channel* channel_3, struct Channel* channel_4, struct Channel* channel_5) {
	printf("请问您要购买几号通道的商品：\n");                             //判断用户所购买的通道
	int number;
	scanf_s("%d", &number);
	while (1) {
		if (number < 1 || number > 5) {
			printf("只有1~5号通道哟，请重新输入：\n");
			scanf_s("%d", &number);
		}
		else {
			break;
		}
	}

	switch (number) {         //检测输入的通道序号，转向对应的通道购买
	case 1:
		buy_goods1(channel_1);
		break;
	case 2:
		buy_goods1(channel_2);
		break;
	case 3:
		buy_goods1(channel_3);
		break;
	case 4:
		buy_goods1(channel_4);
		break;
	case 5:
		buy_goods1(channel_5);
		break;
	}



}







int main() {
	struct Channel channel_1;
	struct Channel channel_2;
	struct Channel channel_3;
	struct Channel channel_4;
	struct Channel channel_5;

	channel_1.number = 1;
	channel_1 = init_channel(channel_1);

	channel_2.number = 2;
	channel_2 = init_channel(channel_2);

	channel_3.number = 3;
	channel_3 = init_channel(channel_3);

	channel_4.number = 4;
	channel_4 = init_channel(channel_4);

	channel_5.number = 5;
	channel_5 = init_channel(channel_5);

	printf("请输入要执行的操作： 1: 购买商品 ， 2：查看通道状态 ， 0：结束购物\n");
	int x;
	scanf_s("%d", &x);
	switch (x) {
	case 1:
		Trade(&channel_1, &channel_2, &channel_3, &channel_4, &channel_5);
		break;
	case 2:
		show_channel(channel_1);
		show_channel(channel_2);
		show_channel(channel_3);
		show_channel(channel_4);
		show_channel(channel_5);
		break;
	case 0:
		printf("使用完毕，欢迎下次再来！");
		exit(0);
		break;
	}

	while (1) {
		printf("请输入要执行的操作： 1: 继续购买商品 ， 2：查看通道状态 ， 0：结束购物\n");
		int x;
		scanf_s("%d", &x);
		switch (x) {
		case 1:
			Trade(&channel_1, &channel_2, &channel_3, &channel_4, &channel_5);
			break;
		case 2:
			show_channel(channel_1);
			show_channel(channel_2);
			show_channel(channel_3);
			show_channel(channel_4);
			show_channel(channel_5);
			break;
		case 0:
			printf("使用完毕，欢迎下次再来！");
			exit(0);
			break;

		}


	}



}















