#include "search.h"
#include <stdio.h>
#include <windows.h>
#include "student.h"

/*****************************************************************
*函数名称：search()
*功能：查询学生成绩和不及格科目及学生名单
*变量：i 选择学期信息  n 统计学生个数  num 接收atoi()函数的返回值 xz 记录选择
	   xks 学科数目 ch[5] 记录要查询的学号或姓名
	   q1, q2, q3, q4	定义各科目学生成绩及格信息，及格取正，不及格取负
******************************************************************/
void search() {
	int i, n = 0, num, xz, xks;
	int q1, q2, q3, q4;
	q1 = q2 = q3 = q4 = 0;
	char ch[5];
	FILE *fp;
	Student stu[45];
	system("cls");

	printf("1、查询学生成绩\n");
	printf("2、查询不及格科目及学生名单\n");
	printf("请选择：");
	scanf("%d", &xz);
	if (xz == 1) {
		do {
			system("cls");
			printf("请输入查询的是第几学期的学生成绩（1-4）：");
			scanf("%d", &i);
			if (i != 1 && i != 2 && i != 3 && i != 4)
			{
				printf("输入有误，请重输 ");
				system("pause");
			}
		} while (i != 1 && i != 2 && i != 3 && i != 4);

		switch (i) {
		case 1: fp = fopen("第一学期学生信息.txt", "r"); break;
		case 2: fp = fopen("第二学期学生信息.txt", "r"); break;
		case 3: fp = fopen("第三学期学生信息.txt", "r"); break;
		case 4: fp = fopen("第四学期学生信息.txt", "r"); break;
		}
		printf("请输入要查询的学生的学号或姓名：");
		scanf("%s", ch);

		num = atoi(ch);		//字符串转数字,失败则返回0 成功返回相应数字

		while (fread(&stu[n], sizeof(Student), 1, fp) == 1) {		//统计学生个数
			++n;
		}
		if (num == 0) {
			while (n--) {
				if (strcmp(stu[n].xm, ch) == 0) {
					printf("查询成功,该学生信息为：\n");
					printf("学号\t\t语文\t\t数学\t\t英语\t\t计算机\n");
					printf("%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", stu[n].xh, stu[n].yw, stu[n].sx, stu[n].yy, stu[n].jsj);
				}
			}
			system("pause");
		}
		else {
			while (n--) {
				if (strcmp(stu[n].xh, ch) == 0) {
					printf("查询成功,该学生信息为：\n");
					printf("姓名\t\t语文\t\t数学\t\t英语\t\t计算机\n");
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
			printf("请输入查询的是第几学期的不及格学生成绩名单（1-4）：");
			scanf("%d", &i);
			if (i != 1 && i != 2 && i != 3 && i != 4)
			{
				printf("输入有误，请重输 ");
				system("pause");
			}
		} while (i != 1 && i != 2 && i != 3 && i != 4);

		switch (i) {
		case 1: fp = fopen("第一学期学生信息.txt", "r"); break;
		case 2: fp = fopen("第二学期学生信息.txt", "r"); break;
		case 3: fp = fopen("第三学期学生信息.txt", "r"); break;
		case 4: fp = fopen("第四学期学生信息.txt", "r"); break;
		}

		while (fread(&stu[n], sizeof(Student), 1, fp) == 1) {		//统计学生个数
			++n;
		}
		printf("不及格学生名单\n姓名\t\t语文\t\t数学\t\t英语\t\t计算机\n");
		while (n--) {
			if (stu[n].yw < 60) q1 = -1;
			if (stu[n].sx < 60) q2 = -1;
			if (stu[n].yy < 60) q3 = -1;
			if (stu[n].jsj < 60) q4 = -1;

			if ((q1 + q2 + q3 + q4) < 0) {
				printf("%s\t\t", stu[n].xm);
				for (xks = 1; xks < 5; xks++) {		//可以直接if else if else 接下去
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