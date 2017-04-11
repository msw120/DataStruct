#ifndef _CONSTMANAGER_H_
#define _CONSTMANAGER_H_

#define TRUE  1
#define FALSE 0
#define OK    1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

#define LIST_INIT_SIZE 10 //线性表存储空间的初始分配量
#define LISTINCREMENT 1   //线性表存储空间的分配增量
typedef int ElemType;
typedef struct 
{
	ElemType *elem;  //存储空间基址
	int length;      // 当前长度
	int listsize;    //当前分配的存储容量(以sizeof(ElemType)为单位)
}SqList;

SqList* InitList_Sq(SqList* list);

void Destroy_Sq(SqList* list);

int Length_SqList(SqList* list);

Status Insert_Sq(SqList* list, ElemType* node, int pos);

ElemType* Get_SqList(SqList* list, int pos);

ElemType* Delete_SqList(SqList* list, int pos);


#endif // !_CONSTMANAGER_H_



