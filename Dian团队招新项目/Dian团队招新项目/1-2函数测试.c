#include <stdio.h>

void buy_goods(int price) {               //���������������㹦�ܣ�
	int coin;         //�û�����Ͷ���Ӳ�Ҽ�ֵ
	int sum;             //�û�Ͷ���Ӳ���ܶ�
	int change;          //����
	int i;               //�û�������Ʒ����
	int total;           //��Ʒ�ܼ�
	
	printf("������Ҫ����٣�\n");
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

}





void Trade() {                          //�ж��û���Ҫ���׵���Ʒ�ĺ���
	printf("��������Ҫ�������Ʒ����\n");     
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