#include <malloc.h>
#include "StaticLinkSeq.h"

#define AVAILABLE -1

typedef struct _tag_StaticListNode
{
    unsigned int data;
    int next;
} TStaticListNode;

typedef struct _tag_StaticList
{
    int capacity;
	//这里的header不能定义成node[0]，因为作为数组讲node[1]是最小定义，node[0]会报错
    TStaticListNode header;
	//可以定义长度为0的数组，这样的数组被称为零长数组或者柔性数组，通常被用在结构体中存放长度可变的数据
	//struct TStaticList *p = malloc(sizeof(struct TStaticList) + 50);
	//这样，node这个数组就相当于拥有50个字节，因此它的合法范围是data[0] - data[49]
	//柔性数组成员只作为一个符号地址存在，而且必须是结构体的最后一个成员
    TStaticListNode node[];
} TStaticList;



VoidType_StaticList* StaticList_Create(int capacity) // O(n)
{
    TStaticList* ret = NULL;
    int i = 0;
    
	//capacity的容量必须要提前估计好，这也是静态链表和线性表的缺点
    if( capacity >= 0 )
    {
		//这里capacity + 1，capacity是node[]的容量，+1是header的容量
        ret = (TStaticList*)malloc(sizeof(TStaticList) + sizeof(TStaticListNode) * (capacity + 1));
    }
    
    if( ret != NULL )
    {
        ret->capacity = capacity;
		//这里用TStaticList内部的head节点data来记录数据的长度
        ret->header.data = 0;
		//header.next=0，表示head没有指向任何节点
        ret->header.next = 0;
        
		//要注意i=1;表示跳过表头， i<=capacity表示最后一个下标值，因为上面申请的容量是(capacity + 1)
		//比如capacity=5，那下标就是node[1]-node[5],而不是node[0]-node[4]，因为node[0]是head的不属于数组的值
        for(i=1; i<=capacity; i++)
        {
			//因为next=0表示没有指向任何节点也就是最后的节点，所以用-1来表示下标可以用的数组
            ret->node[i].next = AVAILABLE;
        }
    }
    
    return ret;
}


void StaticList_Destroy(VoidType_StaticList* list) // O(1)
{
    free(list);
}

void StaticList_Clear(VoidType_StaticList* list) // O(n)
{
    TStaticList* sList = (TStaticList*)list;
    int i = 0;
    
    if( sList != NULL )
    {
		//头节点用来记录数组状态
        sList->header.data = 0;
        sList->header.next = 0;
        
        for(i=1; i<=sList->capacity; i++)
        {
			//所有的标识位标识为可用
            sList->node[i].next = AVAILABLE;
        }
    }
}

int StaticList_Length(VoidType_StaticList* list) // O(1)
{
    TStaticList* sList = (TStaticList*)list;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->header.data;
    }
    
    return ret;
}

int StaticList_Capacity(VoidType_StaticList* list) // O(1)
{
    TStaticList* sList = (TStaticList*)list;
    int ret = -1;
    
    if( sList != NULL )
    {
        ret = sList->capacity;
    }
    
    return ret;
}

int StaticList_Insert(VoidType_StaticList* list, VoidType_StaticListNode* node, int pos)  // O(n)
{
    TStaticList* sList = (TStaticList*)list;
    int ret = (sList != NULL);
    int current = 0;
    int index = 0;
    int i = 0;
    
    ret = ret && (sList->header.data + 1 <= sList->capacity);
    ret = ret && (pos >=0) && (node != NULL);
    
    if( ret )
    {
        for(i=1; i<=sList->capacity; i++)
        {
			//如果发现下标的值为AVAILABLE(-1)，就说明此下标可用
            if( sList->node[i].next == AVAILABLE )
            {
                index = i;
                break;
            }
        }
        
        sList->node[index].data = (unsigned int)node;
        
        sList->node[0] = sList->header;
        
        for(i=0; (i<pos) && (sList->node[current].next != 0); i++)
        {
            current = sList->node[current].next;
        }
        
        sList->node[index].next = sList->node[current].next;
        sList->node[current].next = index;
        
        sList->node[0].data++;
        
        sList->header = sList->node[0];
    }
    
    return ret;
}

VoidType_StaticListNode* StaticList_Get(VoidType_StaticList* list, int pos)  // O(n)
{
    TStaticList* sList = (TStaticList*)list;
    VoidType_StaticListNode* ret = NULL;
    int current = 0;
    int object = 0;
    int i = 0;
    
    if( (sList != NULL) && (0 <= pos) && (pos < sList->header.data) )
    {
        sList->node[0] = sList->header;
        
        for(i=0; i<pos; i++)
        {
			//i是从0开始循环，也就是从head开始
            current = sList->node[current].next;
        }
        //i是从0开始循环，也就是从head开始,所以还要再next才是它的下标
        object = sList->node[current].next;
        
        ret = (VoidType_StaticListNode*)(sList->node[object].data);
    }
    
    return ret;
}


VoidType_StaticListNode* StaticList_Delete(VoidType_StaticList* list, int pos) // O(n)
{
    TStaticList* sList = (TStaticList*)list;
    VoidType_StaticListNode* ret = NULL;
    int current = 0;
    int object = 0;
    int i = 0;
    
    if( (sList != NULL) && (0 <= pos) && (pos < sList->header.data) )
    {
        sList->node[0] = sList->header;
        
        for(i=0; i<pos; i++)
        {
            current = sList->node[current].next;
        }
        
        object = sList->node[current].next;
        
        sList->node[current].next = sList->node[object].next;
        
        sList->node[0].data--;
        
        sList->header = sList->node[0];
        
        sList->node[object].next = AVAILABLE;
        
        ret = (VoidType_StaticListNode*)(sList->node[object].data);
    }
    
    return ret;
}