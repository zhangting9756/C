#include<stdio.h>
#include<string.h>
#include<malloc.h>


#include "list.h"
#include "sort.h"

/*
�����������
*/
void reserveList(pList headList)
{
	if(NULL == headList)
	{
		printf("the list is NULL!\n");
	}
	else
	{
		if(headList->next != NULL)
		{
			reserveList(headList->next);
			printf("%d\n",headList->data);
		}
		else
		{
			printf("%d\n",headList->data);
		}
	}
}

pList creatList()
{
	int i = 0;
	pList pNode;
	pList p;
	pList headList = NULL;
	pNode = (pList)malloc(sizeof(Node));
	pNode->data = 8;
	pNode->next=NULL;
	headList = pNode;
	p = pNode;
	for(i=0;i<5;++i)
	{
		pNode = (pList)malloc(sizeof(Node));
		pNode->data = i;
		pNode->next = NULL;
		p->next = pNode;
		p = pNode;
	}
	return headList;
}
/*����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	pList p =head;
	int size = 0;
	while(p!=NULL)
	{
		size++;
		p = p->next;
	}
	if( size == 1)//ֻ��һ���������ֱ�ӷ���null
	{   
		return NULL;
	}

	size = size - n;//������,Ҳ������Ҫɾ���Ľڵ�ǰ���м����ڵ�

	if(size == 0)//����ڵ���>1,��Ϊɾ������ĵ�һ���ڵ�������
	{
		return head->next;
	}
	p = head;
	for(int i = 0;i<size-1;i++)//ע��i�Ǵ�0��size-2�ģ���Ϊ��0��size-1Ϊsize��λ���������������Ǵӵ�һ����ʼƫ�ƣ�ֻ��Ҫƫ��size-1��λ���������Ա߽�ֵΪsize -1
	{
		p = p->next;
	}
	p->next = p->next->next;
	return head;

}
/*��ת����*/
struct ListNode* reverseList(struct ListNode* head){
	pList pReversedHead = NULL;
	pList pNode = head;
	pList pPrev = NULL;
	while(pNode!=NULL)
	{
		pList pNext = pNode->next;
		if(pNext==NULL)
			pReversedHead = pNode;
		pNode->next = pPrev;
		pPrev=pNode;
		pNode=pNext;
	}
	return pReversedHead;
}
/*�ϲ��������������*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if(l1==NULL)
		return l2;
	if(l2==NULL)
		return l1;
	pList pHead = (pList)malloc(sizeof(Node));
	pList p = pHead;


	while(l1&&l2)
	{
		if(l1->data <l2->data){
			p->next=l1;
			l1=l1->next;
		}
			
		else{
			p->next =l2;
			l2=l2->next;
		}
		p=p->next;	
	}
	if(l1==NULL)
		p->next=l2;
	if(l2==NULL)
		p->next=l1;
	return pHead->next;
}
/*�жϻ�������*/
bool isPalindrome(struct ListNode* head){
	int size = 0;
	struct ListNode* p =head;
	while(p)
	{
		size++;
		p=p->next;
	}
		
	int *a = (int *)malloc(sizeof(int)*size);
	p=head;
	int i = 0;
	for(i=0;i<size;i++)
	{
		a[i]=p->data;
		p=p->next;
	}
	for(i=0;i<size/2;i++)
	{
		if(a[i]!=a[size-i-1])
			return false;
	}
	return true;
}

bool isPalindrome1(struct ListNode* head){
	if(head==NULL) return true;
	struct ListNode *fast,*slow,*p,*q,*temp=NULL;
	fast=slow=head;
	while(fast->next && fast->next->next){     //����ָ��Ѱ���е�
		fast=fast->next->next;
		slow=slow->next;
	}
	slow=slow->next;
	while(slow!=NULL){                      //��ָ�뷭ת���������
		p=slow;
		slow=slow->next;
		p->next=temp;
		temp=p;
	}
	while(temp!=NULL){
		if(temp->data!=head->data){
			return false;
		}
		temp=temp->next;
		head=head->next;
	}
	return true;

}
/*�ж��Ƿ�Ϊ��������*/
bool hasCycle(struct ListNode *head) {
	if(head == NULL || head->next == NULL)
		return false;
	struct ListNode *slow = head;
	struct ListNode *fast = head;
	fast = fast->next->next;
	slow = slow->next;
	while(1)
	{
		if(fast == NULL || fast->next == NULL)
			return false;
		else if(fast == slow || fast->next == slow)
			return true;
		else
		{
			fast = fast->next->next;
			slow = slow->next;
		}
	}
}


/*��������������,������39�������������*/
int maxDepth(struct TreeNode* root){
	int deepRigt = 0;
	int deepLeft = 0;

	if(root == NULL)
		return 0;
	else
	{
		deepRigt=maxDepth(root->right)+1;
		deepLeft=maxDepth(root->left)+1;
	}
	int depth = (deepLeft > deepRigt) ? deepLeft : deepRigt;
	return depth;

}
/*�ж��Ƿ�Ϊƽ���������������39*/
bool isBalanced(struct TreeNode* root)
{
	if(root == NULL)
		return true;
	int deepRigt = isBalanced(root->left);
	int deepLeft = isBalanced(root->right);
	int diff = deepLeft - deepRigt;
	if(diff>1 || diff<-1)
		return false;
	return isBalanced(root->left)&&isBalanced(root->right);
}

/*�ж��Ƿ�Ϊ�Գƶ�����*/
bool MyisSymmetric(struct TreeNode *Left,struct TreeNode *Right)
{
	if(!Left && !Right)
		return true;
	if(!Left || !Right)
		return false;
	if(Right->val!=Left->val)
		return false;
	return MyisSymmetric(Left->left,Right->right) && MyisSymmetric(Left->right,Right->left);
}

bool isSymmetric(struct TreeNode *Root)
{
	if(!Root)
		return true;
	return MyisSymmetric(Root->left,Root->right);
}