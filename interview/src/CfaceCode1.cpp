// CfaceCode1.cpp : �������̨Ӧ�ó������ڵ㡣
//
/***************************
*ͷ�ļ�
****************************/
#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include  <malloc.h>


#include "array.h"
#include "charString.h"
#include "sort.h"
#include "strToInt.h"
#include "list.h"

/***************************
*ȫ�ֱ���
****************************/
int b_g[5]={3, 8, 2, 4,5};


int _tmain(int argc, _TCHAR* argv[])
{
	int length = -1;
	char *p[] = {"test1","test2"};
	int nums1[2]= {2,1};
	int m=-1;
	//int b[6] = {0};
	char c[] = {"ABCD"};
	char b[]= {"BAD"};
	pList a = creatList();
	length=isPalindrome(a);
	system("pause");
	return 0;
}

