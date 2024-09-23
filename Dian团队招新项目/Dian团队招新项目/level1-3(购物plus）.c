#include <stdio.h>
#include <stdlib.h>

struct Channel {
	int number;     //ͨ����
	int count;		//��Ʒ��
	char name;		//��Ʒ��
	int price;      //ͨ����Ʒ�ĵ���
};

struct Channel init_channel(struct Channel channel) {             //��ʼ��ͨ���ĺ������ڷ���Ʒ����ͨ���ڷţ���

	printf("����%d��ͨ��\n", channel.number);

	printf("��������Ҫ�ڷŵ���Ʒ��������(�ÿո���� , ���ڷ���������������0����\n");
	scanf_s(" %c %d", &channel.name, 1, &channel.count);
	fflush(stdin);


	if (channel.count != 0) {
		printf("����Ʒ�Ķ���Ϊ��\n");
		scanf_s("%d", &channel.price);
	}
	else {
		return channel;
	}

	return channel;											//�����Ƶĺ���

}




void show_channel(struct Channel channels) {       //���ڲ鿴ͨ��״̬�ĺ���
	printf("%d: ", channels.number);

	if (channels.count <= 0) {
		printf("��ͨ��û����Ʒ����\n");	    	//����ȱ�ٻ���Ĵ���
	}
	else {
		for (int i = 0; i < channels.count; i++) {
			printf("%c", channels.name);
		}
		printf("   %dԪ/��\n", channels.price);
	}


}





void buy_goods1(struct Channel* ptr) {                              //������
	int coin;                  //�û�����Ͷ���Ӳ�Ҽ�ֵ 
	int sum = 0;                   //�û�Ͷ���Ӳ���ܶ�
	int change;               //����
	int i;                    //�û�������Ʒ����
	int total;               //��Ʒ�ܼ�



	while (1) {

		if ((ptr->count) <= 0) {
			printf("���ͨ��û��������һ���ɣ�\n");
			return 0;
		}
		else {
			printf("��������Ҫ�����������\n");
			scanf_s("%d", &i);
			if (i > (ptr->count)) {
				printf("��Ʒ����������Ŷ����һ�ο�������һ��\n");
			}
			else {
				break;
			}
		}
	}


	total = i * (ptr->price);


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


	ptr->count -= i;

}                        //������buy_goods���





void Trade(struct Channel* channel_1, struct Channel* channel_2, struct Channel* channel_3, struct Channel* channel_4, struct Channel* channel_5) {
	printf("������Ҫ���򼸺�ͨ������Ʒ��\n");                             //�ж��û��������ͨ��
	int number;
	scanf_s("%d", &number);
	while (1) {
		if (number < 1 || number > 5) {
			printf("ֻ��1~5��ͨ��Ӵ�����������룺\n");
			scanf_s("%d", &number);
		}
		else {
			break;
		}
	}

	switch (number) {         //��������ͨ����ţ�ת���Ӧ��ͨ������
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

	printf("������Ҫִ�еĲ����� 1: ������Ʒ �� 2���鿴ͨ��״̬ �� 0����������\n");
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
		printf("ʹ����ϣ���ӭ�´�������");
		exit(0);
		break;
	}

	while (1) {
		printf("������Ҫִ�еĲ����� 1: ����������Ʒ �� 2���鿴ͨ��״̬ �� 0����������\n");
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
			printf("ʹ����ϣ���ӭ�´�������");
			exit(0);
			break;

		}


	}



}















