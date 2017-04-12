#include <stdio.h>
#include <malloc.h>
#include "NodeStruct.c"
#include "ConstManager.h"
#include "LinkList\LinkSeq.h"
#include "StaticLinkList\StaticLinkSeq.h"
#include "CircleLinkList\CircleLinkList.h"
//#include "Link.c" 这一句必须注释掉，不然会报错‘Node’：‘struct’ type redefinition

//SNode* CreateLink(SNode* head, int num);
//void DisplayLink(SNode* head);
//上面两句可以注释掉，写在不同的文件里面好像调用方法名是默认调用的
void Exec_P1();//这一句在VS里面不能注释掉，在main方法里面的其他方法需要加声明
void Exec_P2();
void Exec_P3();
void Exec_P4();
void Exec_P5();

int main() 
{
	//Exec_P1();

	//线性表Demo
	//Exec_P2();

	//线性链表Demo
	//Exec_P3();

	//静态链表Demo
	//Exec_P4();

	//循环链表
	Exec_P5();
	getchar();
	return 0;
}

void Exec_P1() 
{
	SNode* firstHead = NULL;
	SNode* lastHead = NULL;
	//创建先进先出节点
	firstHead = CreateFirstLink(firstHead);
	//插入节点
	firstHead = InsertLink(firstHead);
	//firstHead = DeleteLink(firstHead);
	DisplayLink(firstHead);
	//创建先进后出节点
	//lastHead = CreateLastLink(lastHead);
	//DisplayLink(lastHead);
}

//线性表Demo
void Exec_P2() 
{
	SqList* sq = NULL;
	sq = InitList_Sq(sq);

	int i = 0;
    int j = 1;
    int k = 2;
    int x = 3;
    int y = 4;
    int z = 5;
    int index = 0;
    
    Insert_Sq(sq, &i, 0);
    Insert_Sq(sq, &j, 0);
    Insert_Sq(sq, &k, 0);
    Insert_Sq(sq, &x, 0);
    Insert_Sq(sq, &y, 0);
    Insert_Sq(sq, &z, 0);

	for(index=0; index<Length_SqList(sq); index++)
    {
        int* p = (int*)Get_SqList(sq, index);
        
        printf("%d\n", *p);
    }

	//删除指定数据
	//while( Length_SqList(sq) > 0 )
 //   {
 //       int* p = (int*)Delete_SqList(sq, 0);
 //       printf("%d\n", *p);
 //   }

	//释放内存,清空线性表
	//Destroy_Sq(sq);
}

//线性链表Demo
void Exec_P3() 
{
	LinkSeqList* link = NULL;
	link = Init_LinkSeqList(link);

	int i = 0;
	for (i = 0; i < 5; i++)
	{
		LinkSeqList* insertNode = (LinkSeqList*)malloc(sizeof(LinkSeqList));
		insertNode->length = i;
		Insert_LinkSeqList(link, insertNode, i);
	}

	for (i = 0; i < Length_LinkSeqList(link); i++) 
	{
		LinkSeqList* currentLink = Get_LinkSeqList(link, i);
		printf("%d\n", currentLink->length);
	}
}


//静态链表Demo
void Exec_P4() 
{
	VoidType_StaticList* list = StaticList_Create(10);
    
    int index = 0;
    
    int i = 0;
    int j = 1;
    int k = 2;
    int x = 3;
    int y = 4;
    int z = 5;
    
    StaticList_Insert(list, &i, 0);
    StaticList_Insert(list, &j, 0);
    StaticList_Insert(list, &k, 0);
    
    for(index=0; index<StaticList_Length(list); index++)
    {
        int* p = (int*)StaticList_Get(list, index);
        
        printf("%d\n", *p);
    }
    
    printf("\n");
    
    while( StaticList_Length(list) > 0 )
    {
        int* p = (int*)StaticList_Delete(list, 0);
        
        printf("%d\n", *p);
    }
    
    printf("\n");
    
    StaticList_Insert(list, &x, 0);
    StaticList_Insert(list, &y, 0);
    StaticList_Insert(list, &z, 0);
    
    printf("Capacity: %d Length: %d\n", StaticList_Capacity(list), StaticList_Length(list));
    
    for(index=0; index<StaticList_Length(list); index++)
    {
        int* p = (int*)StaticList_Get(list, index);
        
        printf("%d\n", *p);
    }
    
    StaticList_Destroy(list);
}


struct Value
{
    CircleListNode header;
    int v;
};
void Exec_P5() 
{
	int i = 0;
    CircleList* list = CircleList_Create();
    
    struct Value v1;
    struct Value v2;
    struct Value v3;
    struct Value v4;
    struct Value v5;
    struct Value v6;
    struct Value v7;
    struct Value v8;
    
    v1.v = 1;
    v2.v = 2;
    v3.v = 3;
    v4.v = 4;
    v5.v = 5;
    v6.v = 6;
    v7.v = 7;
    v8.v = 8;
    
    CircleList_Insert(list, (CircleListNode*)&v1, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v2, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v3, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v4, CircleList_Length(list));
    
    CircleList_Insert(list, (CircleListNode*)&v5, 5);
    CircleList_Delete(list, 0);
    
    for(i=0; i<2*CircleList_Length(list); i++)
    {
        struct Value* pv = (struct Value*)CircleList_Get(list, i);
        
        printf("%d\n", pv->v);
    }
    
    printf("\n");
    
    while( CircleList_Length(list) > 0 )
    {
        struct Value* pv = (struct Value*)CircleList_Delete(list, 0);
        
        printf("%d\n", pv->v);
    }
    
    printf("\n");
    
    CircleList_Insert(list, (CircleListNode*)&v1, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v2, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v3, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v4, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v5, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v6, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v7, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&v8, CircleList_Length(list));
    
    for(i=0; i<CircleList_Length(list); i++)
    {
        struct Value* pv = (struct Value*)CircleList_Next(list);
        
        printf("%d\n", pv->v);
    }
    
    printf("\n");
    
    CircleList_Reset(list);
    
    while( CircleList_Length(list) > 0 )
    {
        struct Value* pv = NULL;
        
        for(i=1; i<3; i++)
        {
            CircleList_Next(list);
        }
        
        pv = (struct Value*)CircleList_Current(list);
        
        printf("%d\n", pv->v);
        
        CircleList_DeleteNode(list, (CircleListNode*)pv);
    }
    
    CircleList_Destroy(list);
}
