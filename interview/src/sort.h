#ifndef __QUICK_SORT_TEST__
#define __QUICK_SORT_TEST__
/*ð��*/;
void bubleAsceningSort(int *array,int length);
//��ѡ�񣬸�ð�ݲ�࣬���ǽ���������
void simpleSelectSort(int *array,int length);
//ֱ�Ӳ���
void directInsertSort(int *array,int length);
//ϣ������
void shellSort(int *array,int length);
//����
void quickSort(int *a ,int low,int high);
void swap(int *a,int low,int high);
int partition(int *a, int low, int high);
//�鲢
void merge(int *a,int low, int half, int high);
void mergeSort(int *a, int low, int high);

//����
void heapSort(int *a, int length);
void headAdjust(int *a, int from, int end);
#endif