
#include<stdio.h>
#include<string.h>
#include "stdafx.h"
#include <stdlib.h>
#include  <malloc.h>


#include "charString.h"

/*���������ַ�*/
void swapChar(char *s,int low,int high)
{
	char temp = s[low];
	s[low]=s[high];
	s[high]=temp;
}

bool checkChar(char c)
{
	if(('a'<=c)&&(c<='z'))
		return 1;
	else if(('A'<=c)&&(c<='Z'))
		return 1;
	else
		return 0;
}

/*�����Ƿ�Ϊ�����ַ���*/
int reserveCheck(char *s,int length)
{
	int high = length-1;
	int low = 0;
	if (NULL == s || 1>length)
	{
		printf("the string is NULL!\n");
		return 0;
	}
	while (low <= high)
	{
		if (s[low++] != s[high--])
			return 0;
	}
	return 1;

}
/*��ת�ַ���*/
void reserve(char *s, int from,int end)
{
	if (NULL == s || 0 >(end - from))
	{
		printf("the string is NULL!\n");
		return ;
	}
	while (from <= end)
	{
		char c =  s[from];
		s[from] = s[end];
		s [end] = c;
		from++;
		end--;
	}
	return;
}

/*��ת����˳�� ��ָoffer42
����һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣Ϊ������������ź���ͨ��ĸһ������
eg����I am a student.�������student. a am I��
����Ҳ����ʹ��,
����һ���ַ�����Ҫ����ַ���ǰ������ɸ��ַ��ƶ����ַ�����β����
����ַ�����abcdef��ǰ���2���ַ�'a'��'b'�ƶ����ַ�����β����ʹ��ԭ�ַ�������ַ�����cdefab����
��дһ��������ɴ˹��ܣ�Ҫ��Գ���Ϊn���ַ���������ʱ�临�Ӷ�Ϊ O(n)���ռ临�Ӷ�Ϊ O(1)��
*/
void reserveString(char *s)
{
	int i = 0;
	int start = 0;
	int end = 0;
	int length = strlen(s);
	reserve(s,0,length-1);
	char *pBegin = s;
	char *pEnd = s;
	while(*pBegin != '\0')
	{
		if(*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
			start++;
			end++;
		}
		else if((*pEnd == ' ')||(*pEnd == '\0'))
		{
			reserve(s,start,--end);
			pBegin = pEnd;
			start = ++end;
		}
		else
		{
			*pEnd++;
			end++;
		}
	}
}

/*�ҳ��������ַ���*/
int maxHuiWen(char *s,int length)
{
	int i,j;
	int max = 0;
	int templeMax = 0;
	for(i=0;i<length;i++)
	{
		for(j=0;(((i-j)>=0) && ((i+j)<length));++j)     //�������
		{
			if(s[i-j] != s[i+j])
				break;
		}
		templeMax = (j-1)*2 +1;
		if(templeMax > max)
			max = templeMax;
		for(j=0;(((i-j)>=0) && ((i+j)<length));++j)     //ż�����
		{
			if(s[i-j] != s[i+j+1])
				break;
		}
		templeMax = (j-1)*2 +2;
		if(templeMax > max)
			max = templeMax;
	}
	return max;
}

void calcAllPermutation(char *s,int from,int to)
{
	if(from == to)
	{
		for(int m = 0;m<=to;m++)
			printf("%c",s[m]);
		printf("\n");
	}
	else
	{
		for(int i=from;i<=to;i++)
		{
			swapChar(s,from,i);
			calcAllPermutation(s,from+1,to);
			swapChar(s,from,i);
		}
	}
}

/*
���������ֱ�����ĸ��ɵ��ַ���A���ַ���B���ַ���B�ĳ��ȱ��ַ���A�̡�
���ʣ���������ж��ַ���B��������ĸ�Ƿ����ַ���A�
*/

bool stringContain(char *a, char *b)
{
	int alength = strlen(a);
	int blength = strlen(b);
	int hash = 0;
	int i = 0;
	for(i = 0;i<alength;++i)
	{
		hash |= (1<<(a[i]-'A'));
	}
	for(i = 0;i<blength;++i)
	{
		if((hash & (1<<(b[i]-'A'))) == 0)
			return false;
	}
	return true;
}

/*���ַ����е����е��ʽ��е��š�

˵����

1��ÿ����������26����д��СдӢ����ĸ���ɣ�

2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������

3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������

4��ÿ�������20����ĸ��*/

void reserveString1(char *s)
{
	if(NULL == s )
		return;
	int from=0;
	int end = 0;
	int i =0;
	int j = 0;
	int length = strlen(s);
	reserve(s,0,length-1);
	char dest[1000];
	for(i=0;i<length;i++)
	{
		if(checkChar(s[i]))
		{
			dest[j++]=s[i];
			if(i == length-1)
				reserve(dest,from,i);
		}
		else
		{
			if(i==0)
			{
				dest[0]=' ';
				j++;
			}
			if(dest[j-1]==' ')
			{
				continue;
			}
			end = j-1;
			reserve(dest,from,end);
			dest[j]=' ';
			j++;
			from = j;
			end = j;
		}
	}
	dest[j]='\0';
}
