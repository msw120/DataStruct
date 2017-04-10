#include "ConstManager.h"
#include "ElemStruct.c"
#include<malloc.h>

//线性表初始化
Status InitList_Sq(SqList* list) 
{
	//list必须要分配存储空间
	list = (SqList*)malloc(sizeof(SqList) * LIST_INIT_SIZE);
	//如果上面一句没有分配空间直接分配list->elem会报错
	list->elem = (ElemType*)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
	//如果内存用光分配不了内存，则退出
	if (!list->elem) 
	{
		exit(OVERFLOW);
	}
	list->length = 0;
	list->listsize = LIST_INIT_SIZE;
	return OK;
}


//
