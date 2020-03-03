
#include<stdio.h>
#include<string.h>
#include "stdafx.h"
#include <stdlib.h>
#include  <malloc.h>


#include "charString.h"
#include "strToInt.h"

/*���������ַ�*/;
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
bool checkNum(char c)
{
	return (c>='0'&&c<='9');
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
/*�ַ�����ȫ����
*/
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
hash�൱���Ǹ�λͼ�����ֵ��ַ�����Ϊ1�������ֵľ���0
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

/*��֤�����ַ���,����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��leetcode �ַ���*/
bool isPalindrome(char *s)
{
	char *pBegin=s;
	char *pEnd = s;
	while(*pEnd!='\0')
		pEnd++;
	pEnd--;
	while(pBegin<pEnd)
	{
		if(!(checkChar(*pBegin)||checkNum(*pBegin)))
		{
			pBegin++;
			continue;
		}
		if(!(checkChar(*pEnd)||checkNum(*pEnd)))
		{
			pEnd--;
			continue;
		}
		if(('A'<=*pBegin)&&(*pBegin<='Z'))
		{
			*pBegin = *pBegin + 32;
		}
		if(('A'<=*pEnd)&&(*pEnd<='Z'))
		{
			*pEnd = *pEnd + 32;
		}
		if(*pBegin == *pEnd)
		{
			pBegin++;
			pEnd--;
			continue;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

/*����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��
ע���־λ��ʹ��*/

int firstUniqChar(char *s)
{
	
	if (s==NULL)
		return -1;
	int length = strlen(s);
	if(length == 1)
		return 0;
	int i = 0;
	int j = 0;
	int flag = 0;
	for(i=0;i<length;i++)
	{
		flag = 0;
		for(j=0;j<length;j++)
		{
			if(s[i]==s[j]&&j!=i)
			{	
				flag = 1;
				break;
			}
			
		}
		if(flag==0)
			return i;
	}
	return -1;
}

/*������ת
����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת*/
bool checkNumMax(int num, int c)
{
	if ((num <= MAX_NUM / 10) && ((MAX_NUM - num * 10) >= c))
		return TRUE;
	else
		return FALSE;
}

bool checkNumMin(int num, int c)
{
	if ((num >= int(MIN_NUM) / 10) && (int(MIN_NUM - num * 10) <= c))
		return TRUE;
	else
		return FALSE;
}
int reverse(int x)
{
	int s = x;
	int flag = 0;
	int num = 0;
	if (x < 0)
	{
		flag = 1;
	}
	if (flag)
	{
		while (s)
		{
			if (checkNumMin(num, s % 10))
			{
				num = num * 10 + s % 10;
				s = s / 10;
			}
			else
			{
				return 0;
			}
			
		}
		
	}
	else
	{
		while (s)
		{
			if (checkNumMax(num, s % 10))
			{
				num = num * 10 + s % 10;
				s = s / 10;
			}
			else
				return 0;
			
		}
	}
	return num;
}

/*��Ч����ĸ��λ��,���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�leetcode*/
bool isAnagram(char * s, char * t)
{
	int i,num1[123]={0};
	int num2[123]={0};
	int s_len,t_len;
	s_len=strlen(s);
	t_len=strlen(t);
	if(s_len!=t_len) return false;

	for(i=0;i<s_len;i++)
	{    
		num1[(int)s[i]]++;
		num2[(int)t[i]]++;        
	}
	for(i=97;i<123;i++)
	{
		if(num1[i]!=num2[i]) return false;
	}

	return true;

}
/*�ַ���ת������ (atoi)leetcode*/
bool checkFirstChar(char c)
{
	if(c == '-')
		return true;
	if(c == '+')
		return true;
	if('0'<=c && c<='9')
		return true;
	return false;
}
int myAtoi(char * str)
{
	if(str == NULL)
		return 0;
	int flag = 1;
	int num = 0;
	while(*str != '\0')
	{
		/*�ҵ���һ���ǿ��ַ�*/
		if(*str!=' ')
		{
			if(checkFirstChar(*str))
			{
				if(*str == '-')
					flag = -1;
				else if(*str == '-')
					flag = 1;
				else
					num = *str -'0';
				break;
			}
			else
				return 0;
		}
		else
		{
			str++;
		}
		
	}
	while(*str++ != '\0'&&(checkStrInt(*str)))
	{
		if(checkMax(num,*str))
		{
			return (flag == 1) ?MAX_NUM : MIN_NUM;
		}
		num = 10 * num + (*str - '0');
	}
	return num*flag;
}
/*ʵ�� strStr()
����һ�� haystack �ַ�����һ�� needle �ַ������� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����������ڣ��򷵻�  -1��*/
int strStr(char * haystack, char * needle)
{
	if(haystack==NULL || needle == NULL)
		return -1;
	int length1=strlen(haystack);
	int length2=strlen(needle);
	if (length1 == 0 && length2 > 0)
		return -1;
	if(length2 == 0 )
		return 0;
	if(length2>length1)
		return -1;
	int i=0;
	int j=0;
	int m = 0;
	int flag = 0;
	for(i=0;i<length1;i++)
	{
		j = 0;
		if(haystack[i]!=needle[j])
		{
			continue;
		}
		else
		{
			m=i;
			if((length1-m+1)<length2)
				return -1;
			for(j=0;j<length2 && m<length1;j++,m++)
			{
				if(haystack[m]!=needle[j])
					break;
			}
			if(j==length2 && m==i+length2)
				return i;
		}
	}
	return -1;
}

/*�����ǰ׺*/
char *longestCommonPrefix(char ** strs, int strsSize)
{
	int length = strlen(strs[0]);

	//char *str = strs[0];//���õ�һ�����ж�

	//char *str = (char *)malloc(sizeof(char)*length);//���õ�һ�����ж�   ����strһ��Ҫ�Լ����䣬����ı䲻��str���ֵ����Ϊ���ھ�̬�������
	char str[5000];
	int m =0;
	for(m =0;m<length;m++)
		str[m]=strs[0][m];
	str[m]='\0';
	int i,j;
	if(strsSize == 0) return "";
	for(i = 1; i<strsSize;i++){
		j = 0;
		while(str[j]&&strs[i][j]&&str[j]==strs[i][j])j++;//��������������ж���һ��Ԫ���Ƿ���ͬ
		str[j] ='\0';//�ַ���������ֻ���ǰ���Ӧ��ͬ��
	}
	return str;
}

/*��Ч������
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ע����ַ����ɱ���Ϊ����Ч�ַ�����*/
bool isValid(char * s){
	if( s == NULL )
		return false;
	char *stack = (char *) malloc( sizeof(char) * ( strlen(s)+1 ) );
	int top = 0;
	for( int i=0; s[i]!='\0'; i++)
	{
		if(s[i]=='(' || s[i]=='[' || s[i]=='{') //��������ջ
			stack[++top] = s[i];
		else if( (s[i]==')'&&stack[top]=='(') || (s[i]==']'&&stack[top]=='[') || (s[i]=='}'&&stack[top]=='{') ) //�����űȶ�
			top--;
		else    //�ȶ�ʧ��
			return false;
	}
	if( stack!= NULL)
	{
		free(stack);
		stack = NULL;
	}
	if( top == 0 )  //�ַ���������ջ��
		return true;
	return false;


}