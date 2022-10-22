#include<stdio.h>
#define FREE 0                   // �ڴ����״̬ 
#define FULL 1                   // �ڴ�ռ��״̬ 
#define MAX_ALLOC_SIZE 65536     // ����ϵͳ����������ռ�Ĵ�С 
#define MIN_MEMORY_DIFFER 2      // ��ֹ��Ƭ��̫�����أ�������С��ֵ��������-����Ƭ��С�� 

struct Node{                     // ���з�������� and ��ʹ�÷��������
	int p_id;                    // ��ǰ���з�������id��Ψһ 
	long address, size;
	int status;	 
	struct Node *pre, *next;

};

struct Node *usedLink, *freeLink, *initMemory;
long start_add, end_add, memory_size; // ��ʼ��ַ����ֹ��ַ���ڴ��С 
int initLink();
char *getStatus(int status);
struct Node *deepCopyNode(struct Node *p1, struct Node *p2);
void insertNode(struct Node *link, struct Node *p);
void sortLink(struct Node *temp);
void memoryRecovery(int p_id);
void bestFitAlloc(long prgSize);
void callAllocAlgorithm();
void callRecoveryAlgorithm();
void userInterface();
void displayLink(struct Node *head);

int initLink(){
	// ���з����� & ��ʹ�÷����� �� ˵��������ͷ��㣬����������� 
	usedLink = (struct Node *)malloc(sizeof(struct Node));
	freeLink = (struct Node *)malloc(sizeof(struct Node));
	initMemory = (struct Node *)malloc(sizeof(struct Node));
	
	if(!freeLink || !usedLink || !initMemory){
		printf("�ռ�����ʧ�ܣ�");
		return 0;
	}
	
	// ��ʼ����ʹ�÷������� 
	usedLink->p_id = -1;
	usedLink->size = 0;
	usedLink->address = 0;
	usedLink->pre = usedLink->next = NULL;
	usedLink->status = FULL;
	
	// ��ʼ�����з������� 
	freeLink->p_id = -1;
	freeLink->size = 0;
	freeLink->address = 0;
	freeLink->pre = freeLink->next = NULL;
	freeLink->status = FULL;

	// ��ʼ���ڴ�ռ� 
	initMemory->p_id = -1;
	initMemory->size = 0;
	initMemory->address = 0;
	initMemory->pre = initMemory->next = NULL;
	initMemory->status = FULL;
	
	return 1;
	
}
char *getStatus(int status){
	return status ? "ռ��" : "����";
}
struct Node *deepCopyNode(struct Node *p1, struct Node *p2){  // �Խڵ������� 
	p1->next = p1->pre = NULL;
	p1->address = p2->address;
	p1->p_id = p2->p_id;
	p1->size = p2->size;
	p1->status = p2->status;
	return p1;
}
void insertNode(struct Node *link, struct Node *p){
	link->next = p;
	p->pre = link;
}
void sortLink(struct Node *temp){   // ����������������Ӧ�Ŀ��з����� 
	// ��ͷ��㣬��˴˴� freeLink һ���ǿ� 
	struct Node *p = freeLink->next;
	struct Node *preNode = freeLink;

	// ������״���ӽ�㣬�������� 
	if(!p){
		freeLink->next = temp;
		temp->pre = freeLink;
		return;
	}
	
	// ���տ��з���������С������в������򣬻�ȡ��һ����Ҫ�����λ�� 
	while(p && temp->size > p->size){
		p = p->next;
		preNode = preNode->next;
	}
	temp->next = p;
	if(p)
		p->pre = temp;
	preNode->next = temp;
	temp->pre = preNode;
//	printf("111\n");
}
void memoryRecovery(int p_id){  // �����ڴ� 
	// ʹ��initMemory �Լ� freeLink
	// ����initMemory ���յ��ڴ����� ʹ��sortLink() �������뵽���з����� freeLink ��
	
	// ��������initMemory���ҵ�p_id ���ڵ��ڴ棬�ж���֮�ڽӵ����������ڴ��״̬
	int find = 0;
	struct Node *p = initMemory->next;
	struct Node *copyNode = (struct Node*)malloc(sizeof(struct Node));
	while(p){
		if(p->p_id == p_id){
			// do something
			find = 1;
			break;
		}
		p = p->next;
	}
	if(!find){
		printf("δ�ҵ�ָ�� id ���ڴ棡");
		return;
	}
	// �ҵ���Ӧid���ڴ��㣬�ڴ�ָ��Ϊ p����ȡ�ڽӵ������ڴ��״̬ 
	struct Node *freeHead = freeLink->next;
	struct Node *preNode = p->pre, *nextNode = p->next;
	int preNodeStatus = preNode->status, nextNodeStatus = nextNode->status;
	
//	printf("%d\n%\d\n", nextNodeStatus, preNodeStatus);
	
	
	if(preNodeStatus < nextNodeStatus){  // ǰ���к��� 
		printf("\nǰ���к���\n");
		// ֻ�޸�ǰһ�������Ĵ�С��ɾ����λ����������� 
		preNode->size += p->size;
		preNode->next = nextNode;
		if(nextNode)
			nextNode->pre = preNode;
		free(p);
	}
	else if(preNodeStatus > nextNodeStatus){  // �����ǰ�� 
		// ֻ�޸ĺ�һ�������Ĵ�С��ɾ����λ����������� 
		printf("\n�����ǰ��\n");
		preNode->next = nextNode;
		if(nextNode){
			nextNode->size += p->size;
			nextNode->address = p->address;		
			nextNode->pre = preNode;
		}
		if(nextNode==freeLink->next)
			return;
		free(p);
	}
	else if(!nextNodeStatus){  // ǰ�������    
		// �����ڵ����������ϲ� 
		printf("\nǰ�������\n");
		preNode->size += p->size;
		if(nextNode)
			preNode->size += nextNode->size;
		preNode->next = NULL;
		free(p);
		free(nextNode);	
	}
	else{  // ǰ����� 
		// Ϊ�������������������д��������ַ����С�������ݻ�������С���뵽���з��������ʵ�λ��
		printf("\nǰ�����\n");
		struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
		temp->pre = temp->next = NULL;
		temp->address = p->address;
		temp->size = p->size;
		temp->p_id = p->p_id; 
		temp->status = FREE;
		p->status = FREE; 
	}
} 
void bestFitAlloc(long prgSize){  // �����Ӧ�㷨 

	struct Node *p = freeLink->next, *preNode = freeLink; 
	
	// ���ҵ�Ӧ��������ڴ�� 
	while(p && prgSize > p->size){
		p = p->next;
		preNode = preNode->next;
	}
	if(!p){
		printf("�����������ڴ�Ƭ���ȣ��޷�װ�룡");
		return;
	}
	
	p->size = p->size - prgSize;
	if(!p->size || p->size < MIN_MEMORY_DIFFER) // װ�� 
	{
		p->status = FULL;
		preNode->next = p->next;
		if(p->next)
			p->next->pre = preNode;
		struct Node *q = usedLink;
		
		p->status = FULL;
		p->next = q->next;
		if(q->next)
			q->next->pre = p;
		q->next = p;
		p->pre = q;
		
	}
	else{
		
		preNode->next = p->next;
		if(p->next)
			p->next->pre = preNode;
		// ��ÿ�ζ����������з���������Ч���Ʊغܵ�
		// �����ֻ����λ�����ڴ�Ƭ��ȥ����Ƭ��С��"ժ��"��Ȼ�����¶�������������в�������
		sortLink(p);
	} 
	printf("freeLink:\n");
	displayLink(freeLink);
	printf("usedLink:\n");
	displayLink(usedLink);	
}
void callAllocAlgorithm(){ // ���÷����㷨���˴���Ҫ�����û�������Ϣ 

	int prgNum = 0, i = 0;
	long prgSize = 0, p_id = -1;
	printf("��������ӵĳ���������"); 
	scanf("%d", &prgNum);
	for(;i < prgNum;i++){
		printf("\n������� %d ������� id ����С��", i + 1);
		scanf("%ld%d", &p_id, &prgSize);
		if(prgSize <= 0 || prgSize >= MAX_ALLOC_SIZE){
			printf("�ڴ�����ʧ�ܣ�");
			return;
		}
		bestFitAlloc(prgSize);
	} 	

}
void callRecoveryAlgorithm(){
	struct Node *mHead = initMemory, *fHead = freeLink;
	int prgNum = 0, i = 0;
	int p_id = -1;
	printf("��������յ��ڴ�������"); 
	scanf("%d", &prgNum);
	for(;i < prgNum;i++){
		printf("\n������� %d ���ڴ�� id:", i + 1);
		scanf("%ld", &p_id);
		if(p_id == -1){
			printf("�޴��ڴ���Ի��գ�");
			return;
		}
		memoryRecovery(p_id);
		printf("\ninitMemory after recovery:\n");	
		displayLink(initMemory);
		

	} 	
	while(mHead){
		if(mHead->status == FREE){
			fHead->next = mHead;
			fHead = mHead;
		}
		mHead = mHead->next;
	}
	printf("freeLink:\n");
	displayLink(freeLink);
}
void userInterface(){  // �û����� 
	
	int i = 0;
	long curAdd = 0;
	int init_success = 0;
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	struct Node *lastNode, *preNode;
		
	// ��ʼ����ʼ��ַ����ֹ��ַ
	start_add = end_add = -1; 
	
	printf("���ʼ���ڴ����׵�ַ���ڴ��С��");
	scanf("%ld%ld", &start_add, &memory_size);
	if(memory_size > MAX_ALLOC_SIZE){
		printf("�����ڴ泬���ڴ��С��ֵ��");
		return;
	}
	
	init_success = initLink();
	if(!init_success){
		printf("�ڴ�����ʧ�ܣ�");
		return;
	}
	// �ڴ�����ɹ���ִ��������룬������������ڴ�ռ� 
	
	temp->p_id = -1;
	temp->address = start_add;
	temp->size = memory_size;
	temp->pre = temp->next = NULL;
	temp->status = FREE;
	
	insertNode(initMemory, temp);
	lastNode = temp;   // lastNode ָ���ʼ�ڴ����һ����� 
	preNode = temp->pre;
	
	int p_id = -1, p_num = 0;
	long p_size = -1;
	printf("������������Դ�Ľ��̸�����");
	scanf("%d", &p_num);
	for(i = 0;i < p_num;i++){
		printf("������� %d �����̵���ķ����ż����С��", i + 1);
		scanf("%d%ld", &p_id, &p_size);
		// ��ʼ������������ 
		struct Node *p = (struct Node*)malloc(sizeof(struct Node));
		p->address = curAdd;
		p->p_id = p_id;
		p->size = p_size;
		p->status = FULL;
		p->pre = p->next = NULL; 

		curAdd += p_size;
		if(curAdd > start_add + memory_size){
			printf("�ڴ���䳬��ϵͳ���ƣ�");
			return;
		}
		
		lastNode->address = curAdd;
		lastNode->size -= p_size;
		p->next = lastNode;
		lastNode->pre = p;
		
		p->pre = preNode;
		preNode->next = p;
		preNode = p;
	}
	// ��������������initMemory�ڴ汻����ʹ�� 
	printf("initMemory:\n");
	displayLink(initMemory);
	callRecoveryAlgorithm();
	callAllocAlgorithm();	
}

void displayLink(struct Node *head){
	struct Node *p = head->next;
	while(p){
		printf("id:%d �׵�ַ��%ld ��С��%ld ״̬��%s\n", p->p_id, p->address, p->size, getStatus(p->status));
		p = p->next;
	}
}

int main()
{
	userInterface();
	return 0;
}