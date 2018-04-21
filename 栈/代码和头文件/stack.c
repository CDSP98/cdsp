#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化链表
{
  s->elem=(ElemType*)malloc(sizes*sizeof(ElemType));
  if(s->elem==NULL)
    return ERROR;
  s->size=sizes;
  s->top=-1;
  return OK;
}


Status isEmptyStack(SqStack *s)   //判断链表是否为空
{
 return(s->top==-1||s==NULL||s->elem==NULL?OK:ERROR);
}


Status getTopStack(SqStack *s,ElemType *e)   //得到链表头元素
{
 if(s->top==-1||s==NULL||s->elem==NULL)
    return ERROR;
 *e=s->elem[s->top];
 return OK;
}


Status clearStack(SqStack *s)   //清空链表
{
 if(s==NULL||s->elem==NULL)
    return ERROR;
 s->top=-1;
 return OK;
}


Status destoryStack(SqStack *s)  //销毁链表
{
  if(s==NULL||s->elem==NULL)
    return ERROR;
  free(s->elem);
  return OK;
}


Status StackLength(SqStack *s,int* length)   //检测链表长度
{
 if(s==NULL||s->elem==NULL)
    return ERROR;
 *length=s->top+1;
 return OK;
}

Status pushStack(SqStack *s,ElemType datas)  //入栈
{
 if(s==NULL||s->top>=s->size-1||s->elem==NULL)
    return ERROR;
 s->elem[++s->top]=datas;
 return OK;
}

Status popStack(SqStack *s,ElemType *datas)   //出栈
{
 if(s==NULL||s->top==-1||s->elem==NULL)
    return ERROR;
 *datas=s->elem[s->top--];
 return OK;
}

//链栈(基于链表的)
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
