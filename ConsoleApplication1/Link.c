#include<stdio.h>
#include"NodeStruct.c"


//创建先进先出单向链表
SNode* CreateFirstLink(SNode* head) 
{
	SNode* p = NULL;
	SNode* p1 = NULL;
	int num = 0;
	scanf_s("%d", &num);
	p = (SNode*)malloc(sizeof(SNode));
	p->NodeData = num;
	p->Next = NULL;
	head = p;
	p1 = p;
	scanf_s("%d", &num);
	while (num != 0)
	{
		p = (SNode*)malloc(sizeof(SNode));
		p->NodeData = num;
		p->Next = NULL;
		p1->Next = p;
		p1 = p;
		scanf_s("%d", &num);
	}
	
	return head;
}

//创建先进后出单向链表
SNode* CreateLastLink(SNode* head) 
{
	SNode* p = NULL;
	SNode* p1 = NULL;

	int num = 0;
	scanf_s("%d", &num);
	while (num != 0)
	{
		p = (SNode*)malloc(sizeof(SNode));
		p->NodeData = num;
		p->Next = head;
		head = p;
		scanf_s("%d", &num);
	}
	return head;
}

//单向链表的插入
SNode* InsertLink(SNode* head) 
{
	int num = 0;
	SNode* p;
	p = (SNode*)malloc(sizeof(SNode));
	if (p == NULL) 
	{
		printf("开辟内存失败");
		exit(1);
	}
	printf("please input insert num,order by num\n");
	scanf_s("%d", &num);
	p->NodeData = num;
	p->Next = NULL;

	if (head == NULL) //空表
	{
		head = p;
	}
	else //非空表
	{
		SNode* p1;
		SNode* p2;
		
		p1 = head;
		p2 = head;
		while (p1 != NULL && p1->NodeData < num)
		{
			p2 = p1;
			p1 = p1->Next;
		}
		if(p1 == head) //插在表头
		{
			p->Next = head;
			//如果只有上面一句代码，head的值不会变，需要将head的指针移到p
			head = p;
		}
		else if(p1 != NULL) //插在中间
		{
			p2->Next = p;
			p->Next = p1;
		}
		else  //插在表尾
		{
			p2->Next = p;
		}
		return head;
	}


}

//删除单向链表的某个节点
SNode* DeleteLink(SNode* head) 
{
	if (head == NULL) 
	{
		printf("Empty Link\n");
		return head;
	}
	else
	{
		int num = 0;
		scanf_s("%d", &num);
		SNode* p1;
		SNode* p2;
		p1 = head;
		p2 = head;
		while (p1 != NULL && p1->NodeData != num) 
		{
			p2 = p1;
			p1 = p1->Next;
		}

		if (p1 == NULL) 
		{
			printf("Not found node\n");
		}
		else if(p1 == head) //删除头节点
		{
			//p2 = p2->Next;
			//注意不能用上面的代码，head的值不会改变
			head = head->Next;
		}
		else if(p1->Next != NULL) //删除中间节点
		{
			p2->Next = p1->Next;
		}
		else //删除尾节点
		{
			p2->Next = NULL;
		}
		//这里的free不太清楚，p2不能free，不然head值也被free，搞不懂
		free(p1);
		//这里return的值不能是P1,P2，因为他们的指针已经next了，只能返回head
		return head;
	}

}

void DisplayLink(SNode* head) 
{
	while (head != NULL)
	{
		printf("[%d] ", head->NodeData);
		head = head->Next;
	}
	
}