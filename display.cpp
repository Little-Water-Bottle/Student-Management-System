#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

/*******************************************************************
*函数名：display
*功能：对某一学期学生信息进行输出
*变量：i 记录学生个数  n 记录学期信息
********************************************************************/
void display() {
	int i, n;
	Student stu[45];
	FILE *fp;

	do {
		system("cls");
		printf("显示哪一学期的学生信息（1-4）");
		scanf("%d", &n);
		if (n != 1 && n != 2 && n != 3 && n != 4)
		{
			printf("输入错误 "); system("pause");
		}
	} while (n != 1 && n != 2 && n != 3 && n != 4);

	switch (n) {
	case 1: if ((fp = fopen("第一学期学生信息.txt", "r")) == NULL)
	{
		printf("打开文件失败！");
	}
			else printf("第一学期学生信息\n");
			break;
	case 2: if ((fp = fopen("第二学期学生信息.txt", "r")) == NULL)
	{
		printf("打开文件失败！");
	}
			else printf("第二学期学生信息\n");
			break;
	case 3: if ((fp = fopen("第三学期学生信息.txt", "r")) == NULL)
	{
		printf("打开文件失败！");
	}
			else printf("第三学期学生信息\n");
			break;
	case 4: if ((fp = fopen("第四学期学生信息.txt", "r")) == NULL)
	{
		printf("打开文件失败！");
	}
			else printf("第四学期学生信息\n");
			break;
	default: fp = fopen("第一学期学生信息.txt", "r");	//总报错说fp可能在关闭文件时未初始化
	}

	//计算学生个数，并取出
	i = 0;
	while (fread(&stu[i], sizeof(Student), 1, fp))
	{
		++i;
	}

	printf("学号\t\t班级\t\t姓名\t\t语文\t\t数学\t\t英语\t\t计算机\n");
	while (i--) {
		printf("%s\t\t%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", stu[i].xh, stu[i].bj, stu[i].xm, stu[i].yw, stu[i].sx, stu[i].yy, stu[i].jsj);
	}

	fclose(fp);
	system("pause");

}