#include "stack.h"
#include<stdio.h>
#include<stdlib.h>

//符号(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
 s->count=0;
 s->top=NULL;
 return OK;
}

Status isEmptyLStack(LinkStack *s)  //判断链表是否为空
{
 return(s->top==NULL?OK:ERROR);
}

Status getTopLStack(LinkStack *s,ElemType *e)  //得到链表头元素
{
 if(s->top==NULL)
    return ERROR;
 *e=s->top->data;
 return OK;
}

Status clearLStack(LinkStack *s)   //清空链表
{
 LinkStackPtr p=s->top;
 if(s->top==NULL||s->count==0)
    return ERROR;
 while(s->top)
 {
    s->top=s->top->next;
    free(p);
    p=s->top;
    s->count--;
 }
 return OK;
}

Status destoryLStack(LinkStack *s)   //销毁链表
{
 LinkStackPtr p=s->top;
 while(s->top)
 {
  s->top=s->top->next;
  free(p);
  p=s->top;
  s->count--;
 }
 return OK;
}

Status LStackLength(LinkStack *s,int *length)    //检测链表长度
{
 if(s->count==0)
    return ERROR;
 *length=s->count;
 return OK;
}

Status pushLStack(LinkStack *s,ElemType datas)   //入栈
{
 LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
 if(!p)return ERROR;
 p->data=datas;
 p->next=s->top;
 s->top=p;
 s->count++;
 return OK;
}

Status popLStack(LinkStack *s,ElemType *datas)   //出栈
{
 if(s->top==NULL||s->count==0)
    return ERROR;
 LinkStackPtr p=s->top;
 *datas=p->data;
 s->top=p->next;
 free(p);
 s->count--;
 return OK;
}

//数字(基于链表的)
Status initLstack(Linkstack *s)   //初始化
{
 s->count=0;
 s->top=NULL;
 return OK;
}

Status isEmptyLstack(Linkstack *s)  //判断链表是否为空
{
 return(s->top==NULL?OK:ERROR);
}

Status getTopLstack(Linkstack *s,Elemtype *e)  //得到链表头元素
{
 if(s->top==NULL)
    return ERROR;
 *e=s->top->data;
 return OK;
}





Status LstackLength(Linkstack *s,int *length)    //检测链表长度
{
 if(s->count==0)
    return ERROR;
 *length=s->count;
 return OK;
}

Status pushLstack(Linkstack *s,Elemtype datas)   //入栈
{
 LinkstackPtr p=(LinkstackPtr)malloc(sizeof(Stacknode));
 if(!p)return ERROR;
 p->data=datas;
 p->next=s->top;
 s->top=p;
 s->count++;
 return OK;
}

Status popLstack(Linkstack *s,Elemtype *datas)   //出栈
{
 if(s->top==NULL||s->count==0)
    return ERROR;
 LinkstackPtr p=s->top;
 *datas=p->data;
 s->top=p->next;
 free(p);
 s->count--;
 return OK;
}

