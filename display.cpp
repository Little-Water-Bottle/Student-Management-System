#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

/*******************************************************************
*��������display
*���ܣ���ĳһѧ��ѧ����Ϣ�������
*������i ��¼ѧ������  n ��¼ѧ����Ϣ
********************************************************************/
void display() {
	int i, n;
	Student stu[45];
	FILE *fp;

	do {
		system("cls");
		printf("��ʾ��һѧ�ڵ�ѧ����Ϣ��1-4��");
		scanf("%d", &n);
		if (n != 1 && n != 2 && n != 3 && n != 4)
		{
			printf("������� "); system("pause");
		}
	} while (n != 1 && n != 2 && n != 3 && n != 4);

	switch (n) {
	case 1: if ((fp = fopen("��һѧ��ѧ����Ϣ.txt", "r")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�");
	}
			else printf("��һѧ��ѧ����Ϣ\n");
			break;
	case 2: if ((fp = fopen("�ڶ�ѧ��ѧ����Ϣ.txt", "r")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�");
	}
			else printf("�ڶ�ѧ��ѧ����Ϣ\n");
			break;
	case 3: if ((fp = fopen("����ѧ��ѧ����Ϣ.txt", "r")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�");
	}
			else printf("����ѧ��ѧ����Ϣ\n");
			break;
	case 4: if ((fp = fopen("����ѧ��ѧ����Ϣ.txt", "r")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�");
	}
			else printf("����ѧ��ѧ����Ϣ\n");
			break;
	default: fp = fopen("��һѧ��ѧ����Ϣ.txt", "r");	//�ܱ���˵fp�����ڹر��ļ�ʱδ��ʼ��
	}

	//����ѧ����������ȡ��
	i = 0;
	while (fread(&stu[i], sizeof(Student), 1, fp))
	{
		++i;
	}

	printf("ѧ��\t\t�༶\t\t����\t\t����\t\t��ѧ\t\tӢ��\t\t�����\n");
	while (i--) {
		printf("%s\t\t%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", stu[i].xh, stu[i].bj, stu[i].xm, stu[i].yw, stu[i].sx, stu[i].yy, stu[i].jsj);
	}

	fclose(fp);
	system("pause");

}