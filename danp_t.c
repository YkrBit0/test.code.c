#include<stdio.h>
#define FREE 0                   // 内存空闲状态 
#define FULL 1                   // 内存占满状态 
#define MAX_ALLOC_SIZE 65536     // 假设系统允许最大分配空间的大小 
#define MIN_MEMORY_DIFFER 2      // 防止碎片化太过严重，定义最小差值（空闲区-程序片大小） 

struct Node{                     // 空闲分区链结点 and 已使用分区链结点
	int p_id;                    // 当前空闲分区结点的id，唯一 
	long address, size;
	int status;	 
	struct Node *pre, *next;

};

struct Node *usedLink, *freeLink, *initMemory;
long start_add, end_add, memory_size; // 起始地址，终止地址，内存大小 
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
	// 空闲分区链 & 已使用分区链 ， 说明：带有头结点，方便后续操作 
	usedLink = (struct Node *)malloc(sizeof(struct Node));
	freeLink = (struct Node *)malloc(sizeof(struct Node));
	initMemory = (struct Node *)malloc(sizeof(struct Node));
	
	if(!freeLink || !usedLink || !initMemory){
		printf("空间申请失败！");
		return 0;
	}
	
	// 初始化已使用分区链表 
	usedLink->p_id = -1;
	usedLink->size = 0;
	usedLink->address = 0;
	usedLink->pre = usedLink->next = NULL;
	usedLink->status = FULL;
	
	// 初始化空闲分区链表 
	freeLink->p_id = -1;
	freeLink->size = 0;
	freeLink->address = 0;
	freeLink->pre = freeLink->next = NULL;
	freeLink->status = FULL;

	// 初始化内存空间 
	initMemory->p_id = -1;
	initMemory->size = 0;
	initMemory->address = 0;
	initMemory->pre = initMemory->next = NULL;
	initMemory->status = FULL;
	
	return 1;
	
}
char *getStatus(int status){
	return status ? "占满" : "空闲";
}
struct Node *deepCopyNode(struct Node *p1, struct Node *p2){  // 对节点进行深拷贝 
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
void sortLink(struct Node *temp){   // 插入排序构造最优适应的空闲分区链 
	// 带头结点，因此此处 freeLink 一定非空 
	struct Node *p = freeLink->next;
	struct Node *preNode = freeLink;

	// 如果是首次添加结点，无需排序 
	if(!p){
		freeLink->next = temp;
		temp->pre = freeLink;
		return;
	}
	
	// 按照空闲分区容量从小到大进行插入排序，获取第一个需要插入的位置 
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
void memoryRecovery(int p_id){  // 回收内存 
	// 使用initMemory 以及 freeLink
	// 将从initMemory 回收的内存链结 使用sortLink() 方法插入到空闲分区链 freeLink 中
	
	// 检索整个initMemory，找到p_id 所在的内存，判断与之邻接的上下两块内存的状态
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
		printf("未找到指定 id 的内存！");
		return;
	}
	// 找到对应id的内存结点，内存指针为 p，获取邻接的两块内存的状态 
	struct Node *freeHead = freeLink->next;
	struct Node *preNode = p->pre, *nextNode = p->next;
	int preNodeStatus = preNode->status, nextNodeStatus = nextNode->status;
	
//	printf("%d\n%\d\n", nextNodeStatus, preNodeStatus);
	
	
	if(preNodeStatus < nextNodeStatus){  // 前空闲后满 
		printf("\n前空闲后满\n");
		// 只修改前一个分区的大小，删除定位到的这个分区 
		preNode->size += p->size;
		preNode->next = nextNode;
		if(nextNode)
			nextNode->pre = preNode;
		free(p);
	}
	else if(preNodeStatus > nextNodeStatus){  // 后空闲前满 
		// 只修改后一个分区的大小，删除定位到的这个分区 
		printf("\n后空闲前满\n");
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
	else if(!nextNodeStatus){  // 前后均不满    
		// 将相邻的三个分区合并 
		printf("\n前后均不满\n");
		preNode->size += p->size;
		if(nextNode)
			preNode->size += nextNode->size;
		preNode->next = NULL;
		free(p);
		free(nextNode);	
	}
	else{  // 前后均满 
		// 为回收区单独建立表项，填写回收区首址及大小，并根据回收区大小插入到空闲分区链的适当位置
		printf("\n前后均满\n");
		struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
		temp->pre = temp->next = NULL;
		temp->address = p->address;
		temp->size = p->size;
		temp->p_id = p->p_id; 
		temp->status = FREE;
		p->status = FREE; 
	}
} 
void bestFitAlloc(long prgSize){  // 最佳适应算法 

	struct Node *p = freeLink->next, *preNode = freeLink; 
	
	// 查找到应当存入的内存块 
	while(p && prgSize > p->size){
		p = p->next;
		preNode = preNode->next;
	}
	if(!p){
		printf("程序大于最大内存片长度，无法装入！");
		return;
	}
	
	p->size = p->size - prgSize;
	if(!p->size || p->size < MIN_MEMORY_DIFFER) // 装满 
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
		// 若每次都对整个空闲分区链排序，效率势必很低
		// 因此我只将定位到的内存片减去程序片大小后"摘下"，然后重新对这个单个结点进行插入排序
		sortLink(p);
	} 
	printf("freeLink:\n");
	displayLink(freeLink);
	printf("usedLink:\n");
	displayLink(usedLink);	
}
void callAllocAlgorithm(){ // 调用分配算法，此处主要用于用户输入信息 

	int prgNum = 0, i = 0;
	long prgSize = 0, p_id = -1;
	printf("请输入添加的程序数量："); 
	scanf("%d", &prgNum);
	for(;i < prgNum;i++){
		printf("\n请输入第 %d 个程序的 id 及大小：", i + 1);
		scanf("%ld%d", &p_id, &prgSize);
		if(prgSize <= 0 || prgSize >= MAX_ALLOC_SIZE){
			printf("内存申请失败！");
			return;
		}
		bestFitAlloc(prgSize);
	} 	

}
void callRecoveryAlgorithm(){
	struct Node *mHead = initMemory, *fHead = freeLink;
	int prgNum = 0, i = 0;
	int p_id = -1;
	printf("请输入回收的内存数量："); 
	scanf("%d", &prgNum);
	for(;i < prgNum;i++){
		printf("\n请输入第 %d 块内存的 id:", i + 1);
		scanf("%ld", &p_id);
		if(p_id == -1){
			printf("无此内存可以回收！");
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
void userInterface(){  // 用户界面 
	
	int i = 0;
	long curAdd = 0;
	int init_success = 0;
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	struct Node *lastNode, *preNode;
		
	// 初始化起始地址与终止地址
	start_add = end_add = -1; 
	
	printf("请初始化内存块的首地址及内存大小：");
	scanf("%ld%ld", &start_add, &memory_size);
	if(memory_size > MAX_ALLOC_SIZE){
		printf("申请内存超过内存大小阈值！");
		return;
	}
	
	init_success = initLink();
	if(!init_success){
		printf("内存申请失败！");
		return;
	}
	// 内存申请成功，执行下面代码，最初连续分配内存空间 
	
	temp->p_id = -1;
	temp->address = start_add;
	temp->size = memory_size;
	temp->pre = temp->next = NULL;
	temp->status = FREE;
	
	insertNode(initMemory, temp);
	lastNode = temp;   // lastNode 指向初始内存最后一个结点 
	preNode = temp->pre;
	
	int p_id = -1, p_num = 0;
	long p_size = -1;
	printf("请输入申请资源的进程个数：");
	scanf("%d", &p_num);
	for(i = 0;i < p_num;i++){
		printf("请输入第 %d 个进程调入的分区号及其大小：", i + 1);
		scanf("%d%ld", &p_id, &p_size);
		// 开始划分连续分区 
		struct Node *p = (struct Node*)malloc(sizeof(struct Node));
		p->address = curAdd;
		p->p_id = p_id;
		p->size = p_size;
		p->status = FULL;
		p->pre = p->next = NULL; 

		curAdd += p_size;
		if(curAdd > start_add + memory_size){
			printf("内存分配超出系统限制！");
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
	// 上面代码测试无误，initMemory内存被连续使用 
	printf("initMemory:\n");
	displayLink(initMemory);
	callRecoveryAlgorithm();
	callAllocAlgorithm();	
}

void displayLink(struct Node *head){
	struct Node *p = head->next;
	while(p){
		printf("id:%d 首地址：%ld 大小：%ld 状态：%s\n", p->p_id, p->address, p->size, getStatus(p->status));
		p = p->next;
	}
}

int main()
{
	userInterface();
	return 0;
}