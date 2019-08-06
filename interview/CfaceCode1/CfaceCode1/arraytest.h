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
#endif