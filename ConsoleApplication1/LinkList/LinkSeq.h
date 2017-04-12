#ifndef _LINKSEQ_H_
#define _LINKSEQ_H_

#define TRUE  1
#define FALSE 0
#define OK    1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

typedef struct LinkNode
{
	struct LinkNode* next;  //存储空间基址
	int length;      // 当前长度
}LinkSeqList;

LinkSeqList* Init_LinkSeqList(LinkSeqList* link);

void Destroy_LinkSeqList(LinkSeqList* link);

void Clear_LinkSeqList(LinkSeqList* link);

int Length_LinkSeqList(LinkSeqList* link);

Status Insert_LinkSeqList(LinkSeqList* link, LinkSeqList* insertLink, int pos);

LinkSeqList* Get_LinkSeqList(LinkSeqList* link, int pos);

LinkSeqList* Delete_LinkSeqList(LinkSeqList* link, int pos);

#endif // !_LINKSEQ_H_

