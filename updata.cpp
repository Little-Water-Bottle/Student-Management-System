#include "updata.h"
#include <stdio.h>
#include <windows.h>
#include "student.h"


/******************************************************************************************
*��������updata()
*���ܣ��޸�ѧ����Ϣ
*������i ��¼�ڼ�ѧ��  num ����atoi()�����ķ���ֵ   n��t ��¼ѧ������  ch[5] ��¼Ҫ��ѯ��ѧ�Ż�����
*******************************************************************************************/
void updata() {
	int i = 0, num = 0, n = 0, t = 0;
	char ch[5];
	FILE *fp;
	//Student Stu;
	Student stu[45];
	do {
		system("cls");
		printf("������Ҫ�޸ĵڼ�ѧ�ڵ���Ϣ��1-4����");
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
	printf("������Ҫ�޸ĵ�ѧ��������ѧ�ţ�");
	scanf("%s", ch);
	num = atoi(ch);		//�ַ���ת����,ʧ���򷵻�0 �ɹ�������Ӧ����

	while (fread(&stu[n], sizeof(Student), 1, fp) == 1) {		//ͳ��ѧ������
		++n;
	}
	t = n;

	if (num == 0) {
		while (n--) {
			if (strcmp(stu[n].xm, ch) == 0) {	//����0 ��ƥ��ɹ�
				printf("��Ҫ�޸ĵ�ѧ����ϢΪ��\n");
				printf("ѧ��\t\t�༶\t\t����\t\t����\t\t��ѧ\t\tӢ��\t\t�����\n");
				printf("%s\t\t%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", stu[n].xh, stu[n].bj, stu[n].xm, stu[n].yw, stu[n].sx, stu[n].yy, stu[n].jsj);
				printf("������ѧ����ѧ��:");
				scanf("%s", stu[n].xh);
				printf("������ѧ���İ༶:");
				scanf("%s", stu[n].bj);
				printf("������ѧ�������ĳɼ�:");
				scanf("%f", &stu[n].yw);
				printf("������ѧ������ѧ�ɼ�:");
				scanf("%f", &stu[n].sx);
				printf("������ѧ����Ӣ��ɼ�:");
				scanf("%f", &stu[n].yy);
				printf("������ѧ���ļ�����ɼ�:");
				scanf("%f", &stu[n].jsj);
				break;
			}
		}

		if (n == t) {
			printf("û�д�ѧ������Ϣ\n");
			system("pause");
		}

		switch (i) {
		case 1: fp = fopen("��һѧ��ѧ����Ϣ.txt", "w"); break;
		case 2: fp = fopen("�ڶ�ѧ��ѧ����Ϣ.txt", "w"); break;
		case 3: fp = fopen("����ѧ��ѧ����Ϣ.txt", "w"); break;
		case 4: fp = fopen("����ѧ��ѧ����Ϣ.txt", "w"); break;
		}

		n = 0;
		while (n < t) {
			fwrite(&stu[n], sizeof(Student), 1, fp);
			n++;
		}
		fclose(fp);
		fflush(stdin);
	}
	else {
		for (n = 0; n < t; n++) {
			if (strcmp(stu[n].xh, ch) == 0) {	//����0 ��ƥ��ɹ�
				printf("��Ҫ�޸ĵ�ѧ����ϢΪ��\n");
				printf("ѧ��\t\t�༶\t\t����\t\t����\t\t��ѧ\t\tӢ��\t\t�����\n");
				printf("%s\t\t%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", stu[n].xh, stu[n].bj, stu[n].xm, stu[n].yw, stu[n].sx, stu[n].yy, stu[n].jsj);
				printf("������ѧ��������:");
				scanf("%s", stu[n].xm);
				printf("������ѧ���İ༶:");
				scanf("%s", stu[n].bj);
				printf("������ѧ�������ĳɼ�:");
				scanf("%f", &stu[n].yw);
				printf("������ѧ������ѧ�ɼ�:");
				scanf("%f", &stu[n].sx);
				printf("������ѧ����Ӣ��ɼ�:");
				scanf("%f", &stu[n].yy);
				printf("������ѧ���ļ�����ɼ�:");
				scanf("%f", &stu[n].jsj);
				break;
			}

		}

		if (n == t) {
			printf("û�д�ѧ������Ϣ\n");
			system("pause");
		}

		switch (i) {
		case 1: fp = fopen("��һѧ��ѧ����Ϣ.txt", "w"); break;
		case 2: fp = fopen("�ڶ�ѧ��ѧ����Ϣ.txt", "w"); break;
		case 3: fp = fopen("����ѧ��ѧ����Ϣ.txt", "w"); break;
		case 4: fp = fopen("����ѧ��ѧ����Ϣ.txt", "w"); break;
		}

		for (n = 0; n < t; n++) {
			fwrite(&stu[n], sizeof(Student), 1, fp);
		}

		fclose(fp);
		fflush(stdin);
	}

}