/*�ַ�������*/
void reserve(char *s, int from, int end);
/*����Ƿ��ǻ���*/
int reserveCheck(char *s, int length);
/*�����пո���ַ�������*/
void reserveString(char *s);
/*�����ĳ���*/
int maxHuiWen(char *s,int length);
/*�����ַ���*/
void swapChar(char *s,int low,int high);
/*�ַ���ȫ����*/
void calcAllPermutation(char *s,int from,int to);
/*�ַ�������*/
bool stringContain(char *a, char *b);
/*���ַ����е����е��ʽ��е��š�

˵����

1��ÿ����������26����д��СдӢ����ĸ���ɣ�

2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������

3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������

4��ÿ�������20����ĸ��*/
void reserveString1(char *s);
/*��֤�����ַ���,����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��leetcode �ַ���*/
bool isPalindrome(char *s);
/*����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��*/
int firstUniqChar(char * s);
/*������ת
����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת*/
int reverse(int x);
/*��Ч����ĸ��λ��,���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�leetcode*/
bool isAnagram(char * s, char * t);
/*�ַ���ת������ (atoi)leetcode*/
int myAtoi(char * str);