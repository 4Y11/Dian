#include <stdio.h>

struct Goods {
	int price;            //货物单价
	int channel;          //货物所在通道
	char name[100];       //货物名称
	int count;            //货物数量
};

struct Goods init_goods() {         //用于初始化货物结构体的函数 init_goods
	struct Goods goods;
	printf("请输入货物的单价：\n");
	scanf_s("%d", &goods.price);
	
	printf("请输入货物所在的通道：\n");
	scanf_s("%d", &goods.channel);
	
	printf("请输入货物的数量：\n");
	scanf_s("%d", &goods.count);
	
	printf("请输入货物的名称(请勿输入空格）：\n");
	scanf_s("%s", &goods.name,100);

	return goods;
}
int main() {
	struct Goods goods_A = init_goods();
	printf("%d: ", goods_A.channel);   
	
	for (int i = 0; i < goods_A.count; i++) {
	printf("%s", goods_A.name);
	}
	
	printf(" %d", goods_A.price);         // 对于货物A的说明


	



}