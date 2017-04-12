#ifndef _STATICLINKSEQ_H_
#define _STATICLINKSEQ_H_

typedef void VoidType_StaticList;
typedef void VoidType_StaticListNode;

VoidType_StaticList* StaticList_Create(int capacity);

void StaticList_Destroy(VoidType_StaticList* list);

void StaticList_Clear(VoidType_StaticList* list);

int StaticList_Length(VoidType_StaticList* list);

int StaticList_Capacity(VoidType_StaticList* list);

int StaticList_Insert(VoidType_StaticList* list, VoidType_StaticListNode* node, int pos);

VoidType_StaticListNode* StaticList_Get(VoidType_StaticList* list, int pos);

VoidType_StaticListNode* StaticList_Delete(VoidType_StaticList* list, int pos);

#endif // !_STATICLINKSEQ_H_

