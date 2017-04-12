#include <malloc.h>
#include "LinkSeq.h"

LinkSeqList* Init_LinkSeqList(LinkSeqList* link) 
{
	//链表不需要提前预估容量
	link = (LinkSeqList*)malloc(sizeof(LinkSeqList));
	if (link != NULL) 
	{
		link->next = NULL;
		link->length = 0;
	}
	return link;
}

void Destroy_LinkSeqList(LinkSeqList* link) 
{
	free(link);
}

void Clear_LinkSeqList(LinkSeqList* link) 
{
	//初始化头节点
	if (link != NULL) 
	{
		link->next = NULL;
		link->length = 0;
	}
}

int Length_LinkSeqList(LinkSeqList* link) 
{
	int length = -1;
	if (link != NULL) 
	{
		length = link->length;
	}
	return length;
}

int Insert_LinkSeqList(LinkSeqList* link, LinkSeqList* insertLink, int pos) 
{
	int ret = (link != NULL) && (pos >= 0) && (insertLink != NULL);
	int i = 0;
	if (ret) 
	{
		//这里必须要用一个指针，因为link最后要记录length
		LinkSeqList* currentLink = link;
		//这里link->next != NULL把只有头节点和插在最后面两种情况排除掉了
		for (i = 0; (i < pos) && (currentLink->next != NULL); i++)
		{
			//循环到插入元素的前一个节点
			currentLink = currentLink->next;
		}

		//这里如果是头节点插入或尾节点插入那insertLink->next = NULL
		insertLink->next = currentLink->next;
		//把前面一个节点的链接指向新插入的节点
		currentLink->next = insertLink;

		link->length++;
	}

	return ret;
}

LinkSeqList* Get_LinkSeqList(LinkSeqList* link, int pos) 
{
	int i = 0;
	LinkSeqList* currentLink = NULL;
	if ((link != NULL) && (0 <= pos) && (pos <= link->length)) 
	{
		currentLink = link;
		for (i = 0; i < pos; i++)
		{
			//循环到获取元素的前一个节点
			currentLink = currentLink->next;
		}
		//当pos=0时，指向表头，然后currentLink->next再指向第一个元素
		currentLink = currentLink->next;
	}
	return currentLink;
}

LinkSeqList* Delete_LinkSeqList(LinkSeqList* link, int pos) 
{
	int i = 0;
	LinkSeqList* ret = NULL;
	if ((link != NULL) && (0 <= pos) && (pos <= link->length)) 
	{
		LinkSeqList* currentLink = link;
		for (i = 0; i < pos; i++)
		{
			//循环到删除元素的前一个节点
			currentLink = currentLink->next;
		}
		
		ret = currentLink->next;
		currentLink->next = ret->next;
	}
	return ret;
}