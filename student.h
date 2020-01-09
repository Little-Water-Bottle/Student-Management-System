#ifndef _STUDENT_
#define _STUDENT_

typedef struct student
{
	int xq;			//学期
	char xh[11];	//学号
	char bj[10];	//班级
	char xm[10];	//姓名

	float yw;		//语文
	float sx;		//数学
	float yy;		//英语
	float jsj;		//计算机

	float zcj;		//总成绩
	float pjcj;		//平均成绩
}Student;

//Student stu1[45];	//一个班最多45人
//Student stu2[45];
//Student stu3[45];
//Student stu4[45];

#endif