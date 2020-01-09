#include "staticstic.h"
#include <stdio.h>
#include <windows.h>
#include "student.h"

/*************************************************************************
*函数名：staticstic()
*功能：按班级统计学生的成绩，求学生的总分及平均分
*变量：i 选择学期信息  stu[45] 容纳同班级的人   bj 记录班级  st_bj 学生班级接收 // m 记录要查询的班级的人数
**************************************************************************/
void staticstic() {
	int i = 0, n = 0, t = 0, bj = 0, st_bj;
	Student stu[45];
	FILE *fp;
	do {
		system("cls");
		printf("请输入查询的是第几学期的学生总成绩和平均成绩（1-4）：");
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
	default: fp = fopen("第一学期学生信息.txt", "r"); break;
	}
	printf("请输入要统计第几班的学生成绩与平均成绩：");
	scanf("%d", &bj);

	while (fread(&stu[n], sizeof(Student), 1, fp) == 1) {		//统计学生个数
		++n;
	}
	t = n;

	printf("%d班的总成绩和平均成绩为：\n", bj);
	printf("姓名\t\t总成绩\t\t平均成绩\n");

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