#include <stdio.h>
#include <stdlib.h>
struct Goods {                         //����ṹ��
	int price;            //���ﵥ��
	int channel;          //��������ͨ��
	char name[100];       //��������
	int count;            //��������
};




struct Goods init_goods() {         //���ڳ�ʼ������ṹ��ĺ��� init_goods
	struct Goods goods;
	printf("������������ڵ�ͨ����\n");
	scanf_s("%d", &goods.channel);
	
	printf("��������������(��������ո񣩣�\n");
	scanf_s("%s", &goods.name, 100);
	
	printf("���������ĵ��ۣ�\n");
	scanf_s("%d", &goods.price);

	printf("����������������\n");
	scanf_s("%d", &goods.count);

	
	return goods;                            //��ʼ����������
}







void buy_goods(int price) {               //���������������㹦�ܣ�
	int coin;                //�û�����Ͷ���Ӳ�Ҽ�ֵ
	int sum = 0;             //�û�Ͷ���Ӳ���ܶ�
	int change;              //����
	int i;                  //�û�������Ʒ����
	int total;             //��Ʒ�ܼ�

	printf("��������Ҫ�����������\n");
	scanf_s("%d", &i);
	total = i * price;

	while (1) {
		printf("��Ͷ�ң�ֻ��Ͷ1��2��5Ԫ����\n");
		scanf_s("%d", &coin);
		if (!(coin == 1 || coin == 2 || coin == 5)) {
			printf("ֻ������1��2��5ԪӴ");
			continue;
		}                                 //�ж��û�����Ľ���Ƿ�����Ҫ��

		sum += coin;

		if (sum < total) {                 //�ж��ܶ��ܷ�ɹ�����
			printf("Ǯ�����أ������Ͷ��\n");
			continue;                     //Ǯ��������������ѭ��
		}

		else {
			printf("����ɹ�����ǵ�ȡ��������Ǯ\n");
			change = sum - total;
			printf("��������Ϊ%dԪ ����ӭ�´�����\n", change);
			break;                       //����ɹ�������ѭ��
		}

	}

}                        //������buy_goods���


                  
	void Trade(char name , struct Goods goods_A ) {                          //�ж��û���Ҫ���׵���Ʒ�ĺ���
		                           //�ж��û���Ҫ���׵���Ʒ�ĺ���
	switch (name) {
	case 'A':
		buy_goods(goods_A.price);
		break;
	

	}

}                           //Trade�������

int main() {
	
	struct Goods goods_A = init_goods();        //��ʼ������A
	
	char name1;
	printf("��������Ҫ�������Ʒ����\n");
	scanf_s(" %c", &name1 , 100);
	Trade(name1 , goods_A );
}