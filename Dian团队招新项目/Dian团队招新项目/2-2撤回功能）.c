#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>




struct Channel {
	int number;     //ͨ����
	int count;		//��Ʒ��
	char name[10];		//��Ʒ��
	int price;      //ͨ����Ʒ�ĵ���
};


struct Channel channel[5];    //�����ͨ���Ľṹ������


struct Channel init_channel1(struct Channel channel1[]) {            //��ʼ��ͨ��

	for (int i = 1; i < 6; i++) {
		printf("����%d��ͨ�������������ڷ���Ʒ�����ƣ����ڴ�ͨ���ڷ�������END������Ҫ�����ϲ��ڷŲ�����ֱ������back����\n", i);
		scanf_s("%s", &channel[i - 1].name, 10);
		fflush(stdin);

		if (strcmp(channel[i - 1].name, "END") == 0) {                //�û�����ENDʱ������ͨ����Ʒ������Ϊ0
			channel[i - 1].count = 0;
			continue;
		}
		else if (strcmp(channel[i - 1].name, "back") == 0) {       //�û�ѡ������back��ʱ��i-2��i������������
			i -= 2;
		}
		else {
			printf("������ڷ���Ʒ�������ͼ۸������ÿո��������\n");
			scanf_s("%d %d", &channel[i - 1].count, &channel[i - 1].price);

		}
	}
	return *channel1;
}







void show_channel(struct Channel channels[]) {       //���ڲ鿴ͨ��״̬�ĺ���

	for (int i = 1; i < 6; i++) {

		printf("%d: ", i);

		if (channels[i - 1].count <= 0) {
			printf("��ͨ��û����Ʒ����\n");	    	//����ȱ�ٻ���Ĵ���
		}
		else {
			for (int j = 0; j < channels[i - 1].count; j++) {
				printf("%s", channels[i - 1].name);
			}
			printf("   %dԪ/��\n", channels[i - 1].price);
		}
	}

}







void Trade(struct Channel channel[]) {                   //���������������㣩


	char goods_name[10];                   //�����Ʒ����END����
	int goods_count;						//��Ҫ�������Ʒ����
	int goods_channel;						//��Ʒ����ͨ��
	int count[5] = { 0,0,0,0,0 };								//���ڴ���������Ʒ����������
	int price[5] = { 0,0,0,0,0 };							//��Ӧͨ������ļ۸�
	bool enough;                            //�ж�����������Ƿ��㹻�Ĳ�������

	int i = 0;
	while (1) {
		printf("��������Ҫ�������Ʒ��������ͨ�������������ÿո����������ѡ����ֱ������END ,���볷���ϲ�������ֱ������back����\n");
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
			enough = (goods_count <= (channel[goods_channel - 1]).count) ? 1 : 0;     //�����Ƿ����
			switch (enough) {
			case 0:
				printf("���ﲻ����������ͨ�����������һ��ɣ�\n");
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

	register int sum = 0;		            //�û�Ͷ���Ӳ���ܶ�
	int coin;					//�û�Ͷ���Ӳ��
	int change;                 //����
	int total = 0;					//��Ʒ�ܼ�


	for (i = 0; i < 5; i++) {
		total += count[i] * price[i];
	}                                         //�����ܼ�




	while (1) {                                    //��ʼͶ�Һ��������
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









int main() {
	*channel = init_channel1(channel);

	printf("������Ҫִ�еĲ����� 1: ������Ʒ �� 2���鿴ͨ��״̬ �� 0����������\n");

	int x;
	scanf_s("%d", &x);
	switch (x) {                                      //����x��ֵ����ת��Ӧ����
	case 1:
		Trade(channel);
		break;
	case 2:
		show_channel(channel);
		break;
	case 0:
		printf("ʹ����ϣ���ӭ�´�������");
		exit(0);
		break;
	}

	while (1) {                                     //����ѭ����ֱ���û�����0���˳�����
		printf("������Ҫִ�еĲ����� 1: ����������Ʒ �� 2���鿴ͨ��״̬ �� 0����������\n");
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
			printf("ʹ����ϣ���ӭ�´�������");
			exit(0);
			break;

		}




	}
}