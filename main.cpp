#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "display.h"
#include "search.h"
#include "staticstic.h"
#include "updata.h"
#include "add.h"
/******************************************************************************
*��������main
*���ܣ��������
*������num ��¼ѡ��
*******************************************************************************/
int main() {
	system("color F9");
	system("cls");
	system("mode con cols=110 lines=30");  //����ϵͳConsole����̨��ʾ�Ŀ�Ⱥ͸߶ȣ��߶�Ϊ30���ַ������Ϊ100���ַ�
	system("title ѧ����Ϣ���߹���ϵͳ");	   //�����
	fflush(stdin);						   //������뻺����

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