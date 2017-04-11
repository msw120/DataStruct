#include<stdio.h>
#include "NodeStruct.c"
#include "ConstManager.h"
//#include "Link.c" 这一句必须注释掉，不然会报错‘Node’：‘struct’ type redefinition

//SNode* CreateLink(SNode* head, int num);
//void DisplayLink(SNode* head);
//上面两句可以注释掉，写在不同的文件里面好像调用方法名是默认调用的
void Exec_P1();//这一句在VS里面不能注释掉，在main方法里面的其他方法需要加声明
void Exec_P2();
int main() 
{
	//Exec_P1();
	Exec_P2();
	//Exec_P3();
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

	//释放内存
	Destroy_Sq(sq);
}

