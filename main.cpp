#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "display.h"
#include "search.h"
#include "staticstic.h"
#include "updata.h"
#include "add.h"
/******************************************************************************
*函数名：main
*功能：程序入口
*变量：num 记录选项
*******************************************************************************/
int main() {
	system("color F9");
	system("cls");
	system("mode con cols=110 lines=30");  //调整系统Console控制台显示的宽度和高度，高度为30个字符，宽度为100个字符
	system("title 学生信息在线管理系统");	   //起标题
	fflush(stdin);						   //清空输入缓冲区

	unsigned int  num;
	while (1) {
		num = menu();
		num = int(num);
		switch (num) {
		case 1:	add(); break;
		case 2: display(); break;
		case 3: search(); break;
		case 4: updata(); break;
		case 5:	staticstic(); break;
		case 0: exit(0);
		default:break;
		}
	}

	return 0;
}