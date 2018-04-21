#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ������
{
  s->elem=(ElemType*)malloc(sizes*sizeof(ElemType));
  if(s->elem==NULL)
    return ERROR;
  s->size=sizes;
  s->top=-1;
  return OK;
}


Status isEmptyStack(SqStack *s)   //�ж������Ƿ�Ϊ��
{
 return(s->top==-1||s==NULL||s->elem==NULL?OK:ERROR);
}


Status getTopStack(SqStack *s,ElemType *e)   //�õ�����ͷԪ��
{
 if(s->top==-1||s==NULL||s->elem==NULL)
    return ERROR;
 *e=s->elem[s->top];
 return OK;
}


Status clearStack(SqStack *s)   //�������
{
 if(s==NULL||s->elem==NULL)
    return ERROR;
 s->top=-1;
 return OK;
}


Status destoryStack(SqStack *s)  //��������
{
  if(s==NULL||s->elem==NULL)
    return ERROR;
  free(s->elem);
  return OK;
}


Status StackLength(SqStack *s,int* length)   //���������
{
 if(s==NULL||s->elem==NULL)
    return ERROR;
 *length=s->top+1;
 return OK;
}

Status pushStack(SqStack *s,ElemType datas)  //��ջ
{
 if(s==NULL||s->top>=s->size-1||s->elem==NULL)
    return ERROR;
 s->elem[++s->top]=datas;
 return OK;
}

Status popStack(SqStack *s,ElemType *datas)   //��ջ
{
 if(s==NULL||s->top==-1||s->elem==NULL)
    return ERROR;
 *datas=s->elem[s->top--];
 return OK;
}

//��ջ(���������)
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
