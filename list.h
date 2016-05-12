/*
单链表（带头节点）：
    初始化，链表的长度，插入数据，删除数据，销毁链表
    
AUTH ：mackchanges
*/

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int Status;
typedef int Datatype;

typedef struct LNode{
    Datatype data;
    struct LNode *next;
}ListNode,*ListNodeh;

void initList(ListNodeh *L){
    *L = (ListNodeh)malloc(sizeof(ListNode));
    (*L)->next = NULL;
}
Status listLength(ListNodeh L){
    int j=1;
    ListNodeh p=L->next;
    while(p){
        p = p->next;
        j++;
    }
    return j;
}

Status insertList(ListNodeh L,int i,int data){//插入函数
    ListNodeh p;
    int j=0;
    p = L->next;
    //将节点移动到要插入的位置i与i-1之间
    while(p&&j<i-1){
        p = p->next;
        j++;
    }
    if(!p||j>i-1){
        return 0;
    }
    //生成一个新的节点用于保存
    ListNodeh s = (ListNodeh)malloc(sizeof(ListNode));
    s->data = data;
    s->next = p->next;
    p->next = s;
    return 1;
}
Status listDel(ListNodeh L,int i,Datatype *data){
    //删除第i个元素，并有data返回其值
    int j = 0;
    ListNodeh p,q;
    p = L->next;
    while(p&&j<i-1){    //将指针移动到i-1处
        p = p->next;
        j++;
    }
    if(!p && j>i-1)    //移除位置出错
        return 0;
    q = p->next;
    p->next = q->next;
    *data = q->data;
    free(q);
    return 1;
}

void DestroyList(ListNodeh *L){
    ListNodeh q;
    while(*L){
        q = (*L)->next;
        free(*L);
        (*L) = q;
    }
}
