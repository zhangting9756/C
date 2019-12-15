#include <stdio.h>
#include <string.h>

/*��������1�ĸ���������10 ��ָoffer*/
int countOneInNumber(int num)
{
	int count = 0;
	while(num!=0)
	{
		if((num&1)==1)
			count++;
		num=num>>1;
	}
	return count;
}
/*��һ��ֻ����һ�ε��ַ�  ������35 ��ָoffer ��hash��*/
char findFirstOneChar(char *s)
{
	if(NULL == s)
	{
		return '\0';
	}
	char *pString =s;
	const int length = 256;
	unsigned int hashTable[length];
	for(unsigned int i=0;i<length;i++)
	{
		hashTable[i]=0;
	}
	while(*pString!='\0')
	{
		hashTable[*(pString)]++;
		pString++;
	}
	pString = s;
	while(*pString!='\0')
	{

		if(hashTable[*pString]==1)
			return *pString;
		pString++;
	}
	return '\0';
}
/*�滻�ո�  ������4 ��ָoffer*/
void replaceBlank(char *string,int length)
{
	int i = 0;
	int newLength = 0;
	int stringLength = 0;
	int blankNumber = 0;
	while(string[i]!='\0')
	{
		stringLength++;
		if(string[i]==' ')
			blankNumber++;
		++i;
	}
	newLength = stringLength + blankNumber*2;
	if(newLength > length)
		return;
	int newIndex = newLength;
	int indexOfOrignal = stringLength;
	while(indexOfOrignal<=newIndex && indexOfOrignal >= 0)
	{
		if(string[indexOfOrignal]!=' ')
		{
			string[newIndex--] = string[indexOfOrignal];
		}
		else
		{
			string[newIndex--]='0';
			string[newIndex--]='2';
			string[newIndex--]='%';
		}
		indexOfOrignal--;
	}
}

/*������ֻ����һ�ε�����
һ�����������������������֮�⣬�������ֶ����������Ρ���д�������ҳ�����������һ�ε����֣�
Ҫ��ʱ�临�Ӷ���O��n�����ռ临�Ӷ���O��1��*/
/*����������϶���Ϊ0���ҳ���һ��Ϊ1��λ�����������λ����������������*/
int findFirst1inbit(int num)
{
	int firstBitIndex = 0;
	for(int i=0;i<=32;++i)
	{
		if((num&1) == 1)
			return firstBitIndex;
		else
		{
			num = num>>1;
			firstBitIndex++;
		}
	}
}
void findOnlyOnceNumber(int data[],int length,int *num1,int *num2)
{
	int i=0;
	int allXOR = 0;
	int firstOneIndexInBit = 0;
	for(i=0;i<length;i++)
	{
		allXOR = allXOR^data[i];
	}
	firstOneIndexInBit = findFirst1inbit(allXOR);
	for(i=0;i<length;++i)
	{
		if ((data[i]>>firstOneIndexInBit)&1==1)
			*num1 =(*num1 ^ data[i]);
		else
			*num2 =(*num2 ^ data[i]);
	}
}