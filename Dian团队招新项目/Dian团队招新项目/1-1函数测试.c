#include <stdio.h>

struct Goods {
	int price;            //���ﵥ��
	int channel;          //��������ͨ��
	char name[100];       //��������
	int count;            //��������
};

struct Goods init_goods() {         //���ڳ�ʼ������ṹ��ĺ��� init_goods
	struct Goods goods;
	printf("���������ĵ��ۣ�\n");
	scanf_s("%d", &goods.price);
	
	printf("������������ڵ�ͨ����\n");
	scanf_s("%d", &goods.channel);
	
	printf("����������������\n");
	scanf_s("%d", &goods.count);
	
	printf("��������������(��������ո񣩣�\n");
	scanf_s("%s", &goods.name,100);

	return goods;
}
int main() {
	struct Goods goods_A = init_goods();
	printf("%d: ", goods_A.channel);   
	
	for (int i = 0; i < goods_A.count; i++) {
	printf("%s", goods_A.name);
	}
	
	printf(" %d", goods_A.price);         // ���ڻ���A��˵��


	



}