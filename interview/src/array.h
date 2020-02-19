#ifndef __ARRAY_TEST__
#define __ARRAY_TEST__
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))  //�궨�壬ע�������
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
/*��С��k�����������ڴ棬���ŷ�*/
void getLeastNumber(int *input, int *output, int length,int k);
/*��С��k�������������ڴ棬����*/
void getLeastNumbers(int *input, int *output, int length,int k);
/*��Ϊ��ֵ��������*/
bool findNumberWithSum(int *array,int *num1,int *num2,int length,int sum);
/*��Ϊ��ֵ�Ķ����*/
void printContinueSequence(int start,int end);
void findContunieSequence(int num);
/*쳲������������еĵݹ�ʵ�֣���̨������*/
int faBonacci(int num);
/*쳲������������еķǵݹ�ʵ�֣���̨������*/
int faBonacci1(int num);
/*������ż��ǰ������ָ��˼��*/
void reOderOddEven(int *array,int length);
/*����������⣬����ָ��˼��*/
void sortRedWhiteBlue(int *array,int length);
/*��ά���������еĲ���*/
bool findNumberInArray(int *array,int width,int high,int num);
/*���������������*/
double findMaxProduct(double *array,int length);
/*���������������*/
double findMaxSum(double *array,int length);
/*������K�ĸ���*/
int getNumberOfK(int *array,int length,int k);
/*����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�*/
int removeDuplicates(int* nums, int numsSize);
/*������Ʊ�����ʱ�� II*/
int maxProfit(int* prices, int pricesSize);
/*������Ʊ�����ʱ�� ��̬�滮ֻ������һ��*/
int maxProfit2(int* prices, int pricesSize);
/*����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ���������������ǵ������±ꡣ
����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ��������������ͬ����Ԫ�ء�*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
/*����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����*/
void rotate(int* nums, int numsSize, int k);
/*����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ��*/
int singleNumber(int* nums, int numsSize);
/*����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��

���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�

����Լ���������� 0 ֮�⣬��������������㿪ͷ��*/
int* plusOne(int* digits, int digitsSize, int* returnSize);
int * plusOne1(int *digits,int length) ;
/*����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��*/
void moveZeroes(int* nums, int numsSize);

/*�ҳ������г��ȳ������鳤��һ������֣����벻�ԣ����޸�
*/
int moreThanHalfNumber(int *array,int length);
/*�ж��Ƿ�Ϊ����*/
bool isAugly(int num);
/*�򵥴ֱ�����Ѱ�ҵ�index������*/
int getAuglyNum(int index);
/*�����������*/
int getAuglyNum1(int index);
/*�ϲ�������������
�������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);
/*�����е������*/
int InversePairsCore(int *data,int *copy,int start,int end);
int inversePairs(int *data,int length);
/*��ҽ��ᣬ��̬�滮*/
int rob(int* nums, int numsSize);
#endif