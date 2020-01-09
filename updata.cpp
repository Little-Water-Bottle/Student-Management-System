#include "updata.h"
#include <stdio.h>
#include <windows.h>
#include "student.h"


/******************************************************************************************
*函数名：updata()
*功能：修改学生信息
*变量：i 记录第几学期  num 接收atoi()函数的返回值   n、t 记录学生个数  ch[5] 记录要查询的学号或姓名
*******************************************************************************************/
void updata() {
	int i = 0, num = 0, n = 0, t = 0;
	char ch[5];
	FILE *fp;
	//Student Stu;
	Student stu[45];
	do {
		system("cls");
		printf("请输入要修改第几学期的信息（1-4）：");
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
	printf("请输入要修改的学生姓名或学号：");
	scanf("%s", ch);
	num = atoi(ch);		//字符串转数字,失败则返回0 成功返回相应数字

	while (fread(&stu[n], sizeof(Student), 1, fp) == 1) {		//统计学生个数
		++n;
	}
	t = n;

	if (num == 0) {
		while (n--) {
			if (strcmp(stu[n].xm, ch) == 0) {	//等于0 则匹配成功
				printf("你要修改的学生信息为：\n");
				printf("学号\t\t班级\t\t姓名\t\t语文\t\t数学\t\t英语\t\t计算机\n");
				printf("%s\t\t%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", stu[n].xh, stu[n].bj, stu[n].xm, stu[n].yw, stu[n].sx, stu[n].yy, stu[n].jsj);
				printf("请输入学生的学号:");
				scanf("%s", stu[n].xh);
				printf("请输入学生的班级:");
				scanf("%s", stu[n].bj);
				printf("请输入学生的语文成绩:");
				scanf("%f", &stu[n].yw);
				printf("请输入学生的数学成绩:");
				scanf("%f", &stu[n].sx);
				printf("请输入学生的英语成绩:");
				scanf("%f", &stu[n].yy);
				printf("请输入学生的计算机成绩:");
				scanf("%f", &stu[n].jsj);
				break;
			}
		}

		if (n == t) {
			printf("没有此学生的信息\n");
			system("pause");
		}

		switch (i) {
		case 1: fp = fopen("第一学期学生信息.txt", "w"); break;
		case 2: fp = fopen("第二学期学生信息.txt", "w"); break;
		case 3: fp = fopen("第三学期学生信息.txt", "w"); break;
		case 4: fp = fopen("第四学期学生信息.txt", "w"); break;
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
			if (strcmp(stu[n].xh, ch) == 0) {	//等于0 则匹配成功
				printf("你要修改的学生信息为：\n");
				printf("学号\t\t班级\t\t姓名\t\t语文\t\t数学\t\t英语\t\t计算机\n");
				printf("%s\t\t%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", stu[n].xh, stu[n].bj, stu[n].xm, stu[n].yw, stu[n].sx, stu[n].yy, stu[n].jsj);
				printf("请输入学生的姓名:");
				scanf("%s", stu[n].xm);
				printf("请输入学生的班级:");
				scanf("%s", stu[n].bj);
				printf("请输入学生的语文成绩:");
				scanf("%f", &stu[n].yw);
				printf("请输入学生的数学成绩:");
				scanf("%f", &stu[n].sx);
				printf("请输入学生的英语成绩:");
				scanf("%f", &stu[n].yy);
				printf("请输入学生的计算机成绩:");
				scanf("%f", &stu[n].jsj);
				break;
			}

		}

		if (n == t) {
			printf("没有此学生的信息\n");
			system("pause");
		}

		switch (i) {
		case 1: fp = fopen("第一学期学生信息.txt", "w"); break;
		case 2: fp = fopen("第二学期学生信息.txt", "w"); break;
		case 3: fp = fopen("第三学期学生信息.txt", "w"); break;
		case 4: fp = fopen("第四学期学生信息.txt", "w"); break;
		}

		for (n = 0; n < t; n++) {
			fwrite(&stu[n], sizeof(Student), 1, fp);
		}

		fclose(fp);
		fflush(stdin);
	}

}