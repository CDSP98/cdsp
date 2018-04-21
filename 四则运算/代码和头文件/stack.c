#include "stack.h"
#include<stdio.h>
#include<stdlib.h>

//����(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
 s->count=0;
 s->top=NULL;
 return OK;
}

Status isEmptyLStack(LinkStack *s)  //�ж������Ƿ�Ϊ��
{
 return(s->top==NULL?OK:ERROR);
}

Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�����ͷԪ��
{
 if(s->top==NULL)
    return ERROR;
 *e=s->top->data;
 return OK;
}

Status clearLStack(LinkStack *s)   //�������
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

Status destoryLStack(LinkStack *s)   //��������
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

Status LStackLength(LinkStack *s,int *length)    //���������
{
 if(s->count==0)
    return ERROR;
 *length=s->count;
 return OK;
}

Status pushLStack(LinkStack *s,ElemType datas)   //��ջ
{
 LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
 if(!p)return ERROR;
 p->data=datas;
 p->next=s->top;
 s->top=p;
 s->count++;
 return OK;
}

Status popLStack(LinkStack *s,ElemType *datas)   //��ջ
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

//����(���������)
Status initLstack(Linkstack *s)   //��ʼ��
{
 s->count=0;
 s->top=NULL;
 return OK;
}

Status isEmptyLstack(Linkstack *s)  //�ж������Ƿ�Ϊ��
{
 return(s->top==NULL?OK:ERROR);
}

Status getTopLstack(Linkstack *s,Elemtype *e)  //�õ�����ͷԪ��
{
 if(s->top==NULL)
    return ERROR;
 *e=s->top->data;
 return OK;
}





Status LstackLength(Linkstack *s,int *length)    //���������
{
 if(s->count==0)
    return ERROR;
 *length=s->count;
 return OK;
}

Status pushLstack(Linkstack *s,Elemtype datas)   //��ջ
{
 LinkstackPtr p=(LinkstackPtr)malloc(sizeof(Stacknode));
 if(!p)return ERROR;
 p->data=datas;
 p->next=s->top;
 s->top=p;
 s->count++;
 return OK;
}

Status popLstack(Linkstack *s,Elemtype *datas)   //��ջ
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

