#include <stdio.h>


#include "sort.h"
#include "array.h"

/*��С��K���������ÿ��ŵ�˼��*/
void getLeastNumber(int *input, int *output, int length,int k)
{
	int i =0;
	int index =0;
	int start = 0;
	int end = length -1;
	while(index !=k-1)
	{
		index = partition(input,start,end);
		if(index < k-1)
			start = index +1;
		else
			end = index -1;
	}
	for(i = 0;i<k;i++)
	{
		output[i]=input[i];
	}

}
/*��С��K���������ö��ŵ�˼��*/
void getLeastNumbers(int *input, int *output, int length,int k)
{
	int i = 0;
	for(i=0;i<k;i++)
	{
		output[i]=input[i];
	}

	heapSort(output, k);
	for(i=k;i<length;i++)
	{
		if(input[i]<output[k-1])
		{
			output[k-1]=input[i];
			heapSort(output,k);
		}
	}
}

/*Ѱ�Һ�Ϊ��ֵ��������
����һ�������һ�����֣��������в�����������ʹ�����ǵĺ�������������Ǹ����֡�
*/
bool findNumberWithSum(int *array,int *num1,int *num2,int length,int sum)
{
	int start = 0;
	int end = length -1;
	if (NULL == array || length <=0)
	{
		return false;
	}
	else
	{
		while(start <= end)
		{
			if(array[start]+array[end]==sum)
			{
				*num1 = array[start];
				*num2 = array[end];
				return true;
			}
			else if(array[start]+array[end]<sum)
				start++;
			else
				end--;
		}
	}
	return false;
}
/*Ѱ�Һ�Ϊ��ֵ�Ķ����*/
void printContinueSequence(int start,int end)
{
	int i;
	for(i=start;i<=end;++i)
	{
		printf("%3d",i);
	}
	printf("\n");
}
void findContunieSequence(int num)
{
	int start=1;
	int end =2;
	int middle = (num+1)/2;
	int countSum = start+end;
	while(start<middle)
	{
		if(countSum == num)
		{
			printContinueSequence(start,end);
		}
		while(countSum>num && start<middle)
		{

			countSum -= start;
			start++;
			if(countSum == num)
			{
				printContinueSequence(start,end);
			}
		}
		end++;
		countSum +=end;
		
	}

}
/*������̨��*/
int faBonacci(int num)
{
	if(num <= 0)
		return 0;
	if(num == 1)
		return 1;
	if(num == 2)
		return 2;
	else
	{
		return faBonacci(num-1)+faBonacci(num-2);
	}
}

int faBonacci1(int num)
{
	int minNum=1;   //һ��̨��ʱ�ķ�����
	int maxNum=2;   //����̨�׵ķ�����
	int fibN=0;
	int i=2;
	if(num ==0)
		return 0;
	if(num ==1)
		return 1;
	else
	{
		for(i=2;i<=num;i++)
		{
			fibN = minNum+maxNum;
			minNum = maxNum;
			maxNum=fibN;
		}
	}
	return fibN;
}
/*��������˳��ʹ����λ��ż��ǰ�棬��ָoffer ������14*/
bool oddEven(int num)
{
	if(num%2 == 1)
		return true;
	else
		return false;
}
void reOderOddEven(int *array,int length)
{
	int start=0;
	int end = length-1;
	while(start<=end)
	{
		while(start<=end && oddEven(array[start]))
			start++;
		swap(array,start,end);
		while(start<=end && !(oddEven(array[end])))
			end--;
		swap(array,start,end);
	}
}
/*�����������n����������ֲ�ͬ��ɫ��С������������һ����ͨ��������������������ʹ�ô������ң�������һЩ����һЩ����һЩ����
*/
void sortRedWhiteBlue(int *array,int length)
{
	int start = 0;
	int current = 0;
	int end = length-1;
	while(current <= end)
	{
		if(array[current]==0)
		{
			swap(array,start,current);
			start++;
			current++;
		}
		else if(array[current]==1)
		{
			current++;
		}
		else
		{
			swap(array,current,end);
			end--;
		}
	}
}


/*��ά�����в��ң���������*/
bool findNumberInArray(int *array,int width,int high,int num)
{
	if(NULL == array)
		return false;
	int i = width-1;
	int j =0;
	while(i>=0 && j<high)
	{
		if(array[j*width+i]==num)
			return true;
		else if(array[j*width+i]<num)
			j++;
		else
			i--;
	}
	return false;
}
/*�������������ģ������и���*/
double findMaxProduct(double *array,int length)//�Զ�̬�滮����Ҫ�ҵ�״̬ת�Ʒ���
{
	if (NULL == array)
		return 0;
	double max = array[0];
	double min = max;
	double maxproduct = min;
	int i=1;
	for(i=1;i<length;++i)
	{
		max = MAX(MAX(max*array[i],min*array[i]),array[i]);
		min = MIN(MIN(max*array[i],min*array[i]),array[i]);
		maxproduct = MAX(max,maxproduct);
	}
	return maxproduct;
}
/*��������������*/
double findMaxSum(double *array,int length)//�Զ�̬�滮����Ҫ�ҵ�״̬ת�Ʒ���
{
	if (NULL == array)
		return 0;
	double max = array[0];
	double maxSum = array[0];
	int i =1;
	for(i=1;i<length;++i)
	{
		max = MAX(max+array[i],array[i]);
		maxSum=MAX(max,maxSum);
	}
	return maxSum;
}
/*���������������г��ֵĴ��� ������38*/
int getFirstKIndex(int *array,int from,int to,int k)
{
	if(from>to)
		return -1;
	while(from<=to)
	{
		int half = (from+to)/2;
		if(array[half]==k)
		{
			if((half == 0)|| array[half -1]!=k)
				return half;
			else
				to = half -1;
		}
		else if(k<array[half])
		{
			to = half-1;
			
		}
		else
			from = half +1;
	}
	return getFirstKIndex(array,from,to,k);
}

int getLastKIndex(int *array,int from,int to,int k)
{
	if(from>to)
		return -1;
	while(from <= to)
	{
		int half = (from+to)/2;
		if(array[half]==k)
		{
			if((half == to)|| array[half+1]!=k)
				return half;
			else
				from = half+1;
		}
		else if(k<array[half])
		{
			to = half-1;
		}
		else
			from = half +1;
	}
	return getLastKIndex(array,from,to,k);
}

int getNumberOfK(int *array,int length,int k)
{
	if(NULL == array || length<=0)
		return -1;
	int from = 0;
	int end = length -1;
	int kNumber = -1;
	int firstKIndex = getFirstKIndex(array,from,end,k);
	int lastKIndex = getLastKIndex(array,from,end,k);
	if(firstKIndex>-1 && lastKIndex >-1)
	{
		kNumber = lastKIndex - firstKIndex +1;
	}
	return kNumber;
}

/*�ҳ������г��ȳ������鳤��һ������֣����벻�ԣ����޸�
*/
int moreThanHalfNumber(int *array,int length)
{
	int count = 1;
	int number = array[0];
	int i = 0;
	for(i=1;i<length;i++)
	{
		if(count ==0)
		{
			number=array[i];
			count = 1;
		}
		else if(array[i]==number)
		{
			count++;
		}
		else
			count--;
	}
	if(count>0)
		return number;
	else
		return 0;
}
/*����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�*/

int removeDuplicates(int* nums, int numsSize)
{
	if((nums==NULL)|| (numsSize<=0))
	{
		return 0;
	}
	int temp = nums[0];
	int i = 0;
	int count = 1;
	for (i=1;i<numsSize;i++)
	{
		if(temp!=nums[i])
		{
			nums[count]=nums[i];
			temp = nums[i];
			count++;
		}
	}
	return count;
}
/*������Ʊ�����ʱ�� II*/
int maxProfit(int* prices, int pricesSize)
{
	if(prices == NULL || pricesSize <=0)
		return 0;
	int i =0;
	int maxProfit = 0;
	for(i = 1;i<pricesSize;i++)
	{
		if(prices[i]>prices[i-1])
			maxProfit += prices[i]-prices[i-1];
	}
	return maxProfit;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	if(nums == NULL || numsSize <=0)
		return NULL;
	int front = 0;
	int end   = numsSize - 1;
	while(front<end)
	{
		if(nums[front]+nums[end] == target)
		{	
			returnSize[0]=front;
			returnSize[1]=end;
			break;
		}
		if(nums[front]+nums[end]>target)
			end--;
		else
			front++;
	}
	return returnSize;
}

/*����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����*/
void reserveArray(int*nums,int begin,int end)
{
	int temp =0;
	int temp_end = end;
	for(int i=begin;i<=(begin+end)/2;i++)
	{
		temp = nums[i];
		nums[i]=nums[temp_end];
		nums[temp_end] = temp;
		temp_end--;
	}
}
void rotate(int* nums, int numsSize, int k)
{
	if(nums == NULL || numsSize==0 || k == 0)
		return;
	reserveArray(nums,0,numsSize-k-1);
	reserveArray(nums,numsSize-k,numsSize-1);
	reserveArray(nums,0,numsSize-1);

}
/*����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ��*/
int singleNumber(int* nums, int numsSize)
{
	if(nums==NULL || numsSize<=0)
		return 0;
	int num = nums[0];
	for(int i=1;i<numsSize;i++)
	{
		num =num^nums[i];
	}
	return num;
}

/*����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��

���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�

����Լ���������� 0 ֮�⣬��������������㿪ͷ��*/
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	if(digits == NULL || digitsSize == 0)
		return NULL;
	int carry=1;
	int i = digitsSize-1;
	while(i>=0)
	{
		digits[i]=digits[i]+1;
		if(digits[i]>9)
		{
			digits[i]=digits[i]-10;
			carry = 1;
		}
		else
		{
			carry = 0;
			break;
		}
		i--;
	}
	if(carry==1)
	{
		returnSize[0]=1;
		for(i=0;i<digitsSize;i++)
		{
			returnSize[i+1]=digits[i];
		}
	}
	else
	{
		for(i=0;i<digitsSize;i++)
		{
			returnSize[i]=digits[i];
		}
	}
	return returnSize;
}

int * plusOne1(int *digits,int length) 
{
	int len = length - 1; 
	for(;len>0 && digits[len]==9  ;--len)
	{
		digits[len]=0;
	}
	if (len == 0 && digits[0] == 9) 
	{
		digits[0] = 0;
	}
	else 
	{
		++digits[len];
	}
	return digits;
}
/*����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��*/
void moveZeroes(int* nums, int numsSize)
{
	int begin=0;
	int net = begin+1;
	while(begin<numsSize)
	{
		if(nums[begin]==0)
		{
			while((nums[net]==0)&&(net<numsSize))
			{
				net++;
			}
			if((net==numsSize-1)&&(nums[net]==0))
			{
				break;
			}
			else
			{
				swap(nums,begin,net);
				begin++;
				net++;
			}
		}
		else
			begin++;
	}
}

