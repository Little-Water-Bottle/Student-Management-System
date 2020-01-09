#include "search.h"
#include <stdio.h>
#include <windows.h>
#include "student.h"

/*****************************************************************
*�������ƣ�search()
*���ܣ���ѯѧ���ɼ��Ͳ������Ŀ��ѧ������
*������i ѡ��ѧ����Ϣ  n ͳ��ѧ������  num ����atoi()�����ķ���ֵ xz ��¼ѡ��
	   xks ѧ����Ŀ ch[5] ��¼Ҫ��ѯ��ѧ�Ż�����
	   q1, q2, q3, q4	�������Ŀѧ���ɼ�������Ϣ������ȡ����������ȡ��
******************************************************************/
void search() {
	int i, n = 0, num, xz, xks;
	int q1, q2, q3, q4;
	q1 = q2 = q3 = q4 = 0;
	char ch[5];
	FILE *fp;
	Student stu[45];
	system("cls");

	printf("1����ѯѧ���ɼ�\n");
	printf("2����ѯ�������Ŀ��ѧ������\n");
	printf("��ѡ��");
	scanf("%d", &xz);
	if (xz == 1) {
		do {
			system("cls");
			printf("�������ѯ���ǵڼ�ѧ�ڵ�ѧ���ɼ���1-4����");
			scanf("%d", &i);
			if (i != 1 && i != 2 && i != 3 && i != 4)
			{
				printf("�������������� ");
				system("pause");
			}
		} while (i != 1 && i != 2 && i != 3 && i != 4);

		switch (i) {
		case 1: fp = fopen("��һѧ��ѧ����Ϣ.txt", "r"); break;
		case 2: fp = fopen("�ڶ�ѧ��ѧ����Ϣ.txt", "r"); break;
		case 3: fp = fopen("����ѧ��ѧ����Ϣ.txt", "r"); break;
		case 4: fp = fopen("����ѧ��ѧ����Ϣ.txt", "r"); break;
		}
		printf("������Ҫ��ѯ��ѧ����ѧ�Ż�������");
		scanf("%s", ch);

		num = atoi(ch);		//�ַ���ת����,ʧ���򷵻�0 �ɹ�������Ӧ����

		while (fread(&stu[n], sizeof(Student), 1, fp) == 1) {		//ͳ��ѧ������
			++n;
		}
		if (num == 0) {
			while (n--) {
				if (strcmp(stu[n].xm, ch) == 0) {
					printf("��ѯ�ɹ�,��ѧ����ϢΪ��\n");
					printf("ѧ��\t\t����\t\t��ѧ\t\tӢ��\t\t�����\n");
					printf("%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", stu[n].xh, stu[n].yw, stu[n].sx, stu[n].yy, stu[n].jsj);
				}
			}
			system("pause");
		}
		else {
			while (n--) {
				if (strcmp(stu[n].xh, ch) == 0) {
					printf("��ѯ�ɹ�,��ѧ����ϢΪ��\n");
					printf("����\t\t����\t\t��ѧ\t\tӢ��\t\t�����\n");
					printf("%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", stu[n].xm, stu[n].yw, stu[n].sx, stu[n].yy, stu[n].jsj);
				}
			}
			system("pause");
		}
		fclose(fp);
		fflush(stdin);
	}
	else if (xz == 2) {
		system("cls");
		do {
			printf("�������ѯ���ǵڼ�ѧ�ڵĲ�����ѧ���ɼ�������1-4����");
			scanf("%d", &i);
			if (i != 1 && i != 2 && i != 3 && i != 4)
			{
				printf("�������������� ");
				system("pause");
			}
		} while (i != 1 && i != 2 && i != 3 && i != 4);

		switch (i) {
		case 1: fp = fopen("��һѧ��ѧ����Ϣ.txt", "r"); break;
		case 2: fp = fopen("�ڶ�ѧ��ѧ����Ϣ.txt", "r"); break;
		case 3: fp = fopen("����ѧ��ѧ����Ϣ.txt", "r"); break;
		case 4: fp = fopen("����ѧ��ѧ����Ϣ.txt", "r"); break;
		}

		while (fread(&stu[n], sizeof(Student), 1, fp) == 1) {		//ͳ��ѧ������
			++n;
		}
		printf("������ѧ������\n����\t\t����\t\t��ѧ\t\tӢ��\t\t�����\n");
		while (n--) {
			if (stu[n].yw < 60) q1 = -1;
			if (stu[n].sx < 60) q2 = -1;
			if (stu[n].yy < 60) q3 = -1;
			if (stu[n].jsj < 60) q4 = -1;

			if ((q1 + q2 + q3 + q4) < 0) {
				printf("%s\t\t", stu[n].xm);
				for (xks = 1; xks < 5; xks++) {		//����ֱ��if else if else ����ȥ
					switch (xks) {
					case 1: if (q1 < 0) {
						printf("%.2f\t\t", stu[n].yw);
					}
							else { printf("\t\t"); } break;
					case 2: if (q2 < 0) {
						printf("%.2f\t\t", stu[n].sx);
					}
							else { printf("\t\t"); } break;
					case 3: if (q3 < 0) {
						printf("%.2f\t\t", stu[n].yy);
					}
							else { printf("\t\t"); } break;
					case 4: if (q4 < 0) {
						printf("%.2f\t\t", stu[n].jsj);
					}
							else { printf("\t\t"); } break;
					}

				}
			}
			printf("\n");
			q1 = q2 = q3 = q4 = 0;
		}
		system("pause");
		fclose(fp);
	}
}