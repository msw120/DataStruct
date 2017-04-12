#include "ConstManager.h"
#include <malloc.h>

//线性表初始化
SqList* InitList_Sq(SqList* list) 
{

	//list必须要分配存储空间
	//list = (SqList*)malloc(sizeof(SqList) * LIST_INIT_SIZE);
	//如果上面一句没有分配空间直接分配list->elem会报错
	//list = (SqList*)malloc(sizeof(SqList) + sizeof(ElemType) * LIST_INIT_SIZE);
	list = (SqList*)malloc(sizeof(SqList));
	list->elem = (ElemType*)malloc(sizeof(ElemType) * LIST_INIT_SIZE);

	//如果内存用光分配不了内存，则退出
	if (!list->elem) 
	{
		exit(OVERFLOW);
	}
	list->length = 0;
	list->listsize = LIST_INIT_SIZE;
	return list;
}

void Destroy_Sq(SqList* list) 
{
	free(list);
}

void Clear_SqList(SqList* list) // O(1)
{
	//这里设置length=0后，因为下面的插入方法Insert_Sq是通过list->length来插入的，所以又初始化了
    if( list != NULL )
    {
        list->length = 0;
    }
}

int Length_SqList(SqList* list) // O(1)
{
    int ret = -1;
    
    if( list != NULL )
    {
        ret = list->length;
    }
    
    return ret;
}

Status Insert_Sq(SqList* list, ElemType* node, int pos) 
{
    int ret = (list != NULL);
    int i = 0;
    
    ret = ret && (list->length + 1 <= list->listsize);
    ret = ret && (0 <= pos);
    if( ret )
    {
        if( pos >= list->length )
        {
            pos = list->length;
        }
		//这里list->length的长度是A[5]的5，实际上A[4]为最后一个,A[5]已经增加了一个数组了
		//插入数组必须是最后一个开始操作，如果从插入的后面一个操作加1那原来的数组的值就被覆盖了
        for(i=list->length; i>pos; i--)
        {
			//这样A[5]=A[4],原来最后一个的A[4]就往后移了一位
			//一开始没有数组的时候不会走循环因为list->length=0;pos=0，不然会报错
			list->elem[i] = list->elem[i - 1];
        }
        list->elem[i] = node;
        list->length++;
    }
    
    return ret;
}


ElemType* Get_SqList(SqList* list, int pos) // O(1) 
{
	ElemType ret;
    if( (list != NULL) && (0 <= pos) && (pos < list->length) )
    {
        ret = (ElemType*)(list->elem[pos]);
    }
    
    return ret;
}


ElemType* Delete_SqList(SqList* list, int pos) // O(n)
{
    ElemType* ret = Get_SqList(list, pos);
    int i = 0;
    
    if( ret != NULL )
    {
		//删除数组的操作必须从删除的后面一个数组开始操作，不能从最后一个数组开始操作，不然前面的数被覆盖掉
        for(i=pos+1; i<list->length; i++)
        {
            list->elem[i-1] = list->elem[i];
        }
        list->length--;
    }
    return ret;
}
