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

