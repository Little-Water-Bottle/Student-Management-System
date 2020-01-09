#include "add.h"
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

//嫌add过长，用add2分担一点长度
void add2(int t) {
	//FILE *fp1, *fp2, *fp3, *fp4;
	FILE *fp;
	Student stu;

	printf("请输入学生的学号:");
	scanf("%s", stu.xh);
	printf("请输入学生的班级:");
	scanf("%s", stu.bj);
	printf("请输入学生的姓名:");
	scanf("%s", stu.xm);
	printf("请输入学生的语文成绩:");
	scanf("%f", &stu.yw);
	printf("请输入学生的数学成绩:");
	scanf("%f", &stu.sx);
	printf("请输入学生的英语成绩:");
	scanf("%f", &stu.yy);
	printf("请输入学生的计算机成绩:");
	scanf("%f", &stu.jsj);

	switch (t) {
	case 1: fp = fopen("第一学期学生信息.txt", "a");
		fwrite(&stu, sizeof(Student), 1, fp);
		fclose(fp);
		fflush(stdin);
		break;
	case 2: fp = fopen("第二学期学生信息.txt", "a");
		fwrite(&stu, sizeof(Student), 1, fp);
		fflush(stdin);
		fclose(fp);
		break;
	case 3: fp = fopen("第三学期学生信息.txt", "a");
		fwrite(&stu, sizeof(Student), 1, fp);
		fflush(stdin);
		fclose(fp);
		break;
	case 4: fp = fopen("第四学期学生信息.txt", "a");
		fwrite(&stu, sizeof(Student), 1, fp);
		fflush(stdin);
		fclose(fp);
		break;
	}


}


/******************************************************************
*函数名：add
*功能：按学期、班级完成对学生成绩的录入
*变量：xq 记录学期
*******************************************************************/
void add() {
	int xq;		//学期
	do {
		system("cls");
		printf("请输入要录入的是第几学期(1-4):");
		scanf("%d", &xq);
		if (xq != 1 && xq != 2 && xq != 3 && xq != 4)
		{
			printf("输入错误 "); system("pause");
		}
	} while (xq != 1 && xq != 2 && xq != 3 && xq != 4);


	add2(xq);



}