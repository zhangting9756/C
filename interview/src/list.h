
typedef struct ListNode{
	int data;
	struct ListNode *next;
}Node,*pList;

void reserveList(pList headList);
pList creatList();

/*����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣*/
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);

/*��ת����*/
struct ListNode* reverseList(struct ListNode* head);

/*�ϲ��������������*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

/*�жϻ�������*/
bool isPalindrome(struct ListNode* head);