#include "add.h"
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

//��add��������add2�ֵ�һ�㳤��
void add2(int t) {
	//FILE *fp1, *fp2, *fp3, *fp4;
	FILE *fp;
	Student stu;

	printf("������ѧ����ѧ��:");
	scanf("%s", stu.xh);
	printf("������ѧ���İ༶:");
	scanf("%s", stu.bj);
	printf("������ѧ��������:");
	scanf("%s", stu.xm);
	printf("������ѧ�������ĳɼ�:");
	scanf("%f", &stu.yw);
	printf("������ѧ������ѧ�ɼ�:");
	scanf("%f", &stu.sx);
	printf("������ѧ����Ӣ��ɼ�:");
	scanf("%f", &stu.yy);
	printf("������ѧ���ļ�����ɼ�:");
	scanf("%f", &stu.jsj);

	switch (t) {
	case 1: fp = fopen("��һѧ��ѧ����Ϣ.txt", "a");
		fwrite(&stu, sizeof(Student), 1, fp);
		fclose(fp);
		fflush(stdin);
		break;
	case 2: fp = fopen("�ڶ�ѧ��ѧ����Ϣ.txt", "a");
		fwrite(&stu, sizeof(Student), 1, fp);
		fflush(stdin);
		fclose(fp);
		break;
	case 3: fp = fopen("����ѧ��ѧ����Ϣ.txt", "a");
		fwrite(&stu, sizeof(Student), 1, fp);
		fflush(stdin);
		fclose(fp);
		break;
	case 4: fp = fopen("����ѧ��ѧ����Ϣ.txt", "a");
		fwrite(&stu, sizeof(Student), 1, fp);
		fflush(stdin);
		fclose(fp);
		break;
	}


}


/******************************************************************
*��������add
*���ܣ���ѧ�ڡ��༶��ɶ�ѧ���ɼ���¼��
*������xq ��¼ѧ��
*******************************************************************/
void add() {
	int xq;		//ѧ��
	do {
		system("cls");
		printf("������Ҫ¼����ǵڼ�ѧ��(1-4):");
		scanf("%d", &xq);
		if (xq != 1 && xq != 2 && xq != 3 && xq != 4)
		{
			printf("������� "); system("pause");
		}
	} while (xq != 1 && xq != 2 && xq != 3 && xq != 4);


	add2(xq);



}