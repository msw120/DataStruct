#include<stdio.h>
#include "NodeStruct.c"
#include "ElemStruct.c"
//#include "Link.c" 这一句必须注释掉，不然会报错‘Node’：‘struct’ type redefinition

//SNode* CreateLink(SNode* head, int num);
//void DisplayLink(SNode* head);
//上面两句可以注释掉，写在不同的文件里面好像调用方法名是默认调用的
void Exec1();//这一句在VS里面不能注释掉，在main方法里面的其他方法需要加声明
void Exec2();
int main() 
{
	//Exec1();
	Exec2();
	getchar();
	return 0;
}

void Exec1() 
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

void Exec2() 
{
	SqList* sq = NULL;
	sq = InitList_Sq(sq);
}
