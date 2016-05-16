#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int Status;
typedef int Datatype;

typedef struct snode{
    Datatype data;
    struct snode *next;
}Snode,*SNode;

void init(SNode *s){   //带头节点无需每次都改变头节点（用双重指针）
    *s = (SNode)malloc(sizeof(Snode));
    (*s)->next = NULL;
}

Status push(SNode s,int data){
    SNode p = (SNode)malloc(sizeof(Snode));
    p->data = data;
    p->next = s->next;
    s->next = p;
    return 1;
}

Status pop(SNode s,int *e){
    if(s->next==NULL)
        return 0;
    SNode p;
    p = s->next;
    s->next = p->next; //重置头节点
    *e = p->data;
    free(p);
    return 1;
}
Status GetTop(SNode s,int *e){
    SNode p=s->next;
    if(p==NULL)
        return 0;
    *e = p->data;
    return 1;
}

