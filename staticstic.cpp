#include "staticstic.h"
#include <stdio.h>
#include <windows.h>
#include "student.h"

/*************************************************************************
*��������staticstic()
*���ܣ����༶ͳ��ѧ���ĳɼ�����ѧ�����ּܷ�ƽ����
*������i ѡ��ѧ����Ϣ  stu[45] ����ͬ�༶����   bj ��¼�༶  st_bj ѧ���༶���� // m ��¼Ҫ��ѯ�İ༶������
**************************************************************************/
void staticstic() {
	int i = 0, n = 0, t = 0, bj = 0, st_bj;
	Student stu[45];
	FILE *fp;
	do {
		system("cls");
		printf("�������ѯ���ǵڼ�ѧ�ڵ�ѧ���ܳɼ���ƽ���ɼ���1-4����");
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
	default: fp = fopen("��һѧ��ѧ����Ϣ.txt", "r"); break;
	}
	printf("������Ҫͳ�Ƶڼ����ѧ���ɼ���ƽ���ɼ���");
	scanf("%d", &bj);

	while (fread(&stu[n], sizeof(Student), 1, fp) == 1) {		//ͳ��ѧ������
		++n;
	}
	t = n;

	printf("%d����ܳɼ���ƽ���ɼ�Ϊ��\n", bj);
	printf("����\t\t�ܳɼ�\t\tƽ���ɼ�\n");

	for (n = 0; n < t; n++) {
		st_bj = atoi(stu[n].bj);
		if (bj == st_bj) {
			//m = m + 1;
			stu[n].zcj = stu[n].yw + stu[n].sx + stu[n].yy + stu[n].jsj;
			stu[n].pjcj = stu[n].zcj / 4;
			printf("%s\t\t%.2f\t\t%.2f\n", stu[n].xm, stu[n].zcj, stu[n].pjcj);
		}
	}
	system("pause");
}