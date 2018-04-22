#include"queue.h"
#include<stdlib.h>
#include<stdio.h>
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *	@description : ��ʼ������
 *	@param		 : ����ָ��Q
 *	@return		 : None
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
    Q->front=0;
    Q->rear=0;
    Q->data_size=0;
    for(int i=0;i<MAXQUEUE;i++)
    {
        Q->data[i]=NULL;
    }

}

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *	@description : ��ʼ������
 *	@param		 : ����ָ��Q
 *	@return		 : None
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
 Q->front=NULL;
 Q->rear=NULL;
 Q->data_size=0;
}
/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *	@description : ���ٶ���
 *	@param		 : ����ָ��Q
 *	@return		 : None
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
  for(int i=0;i<MAXQUEUE;i++)
    {
        Q->data[i]=NULL;
    }
    Q->front=0;
    Q->rear=0;
    Q->data_size=0;
}
/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *	@description : ���ٶ���
 *	@param		 : ����ָ��Q
 *	@return		 : None
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
  Node* p=Q->front;
  for(;Q->front!=NULL;)
  {
    Q->front=Q->front->next;
    free(p);
    p=Q->front;
  }
  Q->data_size=0;

}
/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *	@description : �������Ƿ�����
 *	@param		 : ����ָ��Q
 *	@return		 : ��-TRUE; δ��-FLASE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
 int t=Q->rear;
 if(Q->rear<Q->front)
    t+=MAXQUEUE;
 if((t-Q->front+1)==MAXQUEUE)
    return TRUE;
 else return FLASE;
}
/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *	@description : �������Ƿ�Ϊ��
 *	@param		 : ����ָ��Q
 *	@return		 : ��-TRUE; δ��-FLASE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
  if(Q->rear==Q->front)
    return TRUE;
 else return FLASE;
}
/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *	@description : �������Ƿ�Ϊ��
 *	@param		 : ����ָ��Q
 *	@return		 : ��-TRUE; δ��-FLASE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
  if(Q->front==NULL&&Q->rear==NULL)
    return TRUE;
  else
    return FLASE;
}
/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *	@description : �鿴��ͷԪ��
 *	@param		 : ����ָ��Q�����Ԫ��e
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void **e)
{
 if(IsEmptyAQueue(Q)==TRUE)
    return FLASE;
 else
 {
     *e=Q->data[Q->front];
     return TRUE;
 }
}
/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *	@description : �鿴��ͷԪ��
 *	@param		 : ����ָ��Q�����Ԫ��e
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void **e)
{
  if(IsEmptyLQueue(Q)==TRUE)
    return FLASE;
  *e=Q->front->data;
  return TRUE;
}
/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *	@description : ȷ�����г���
 *	@param		 : ����ָ��Q
 *	@return		 : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
 int t=Q->rear;
 if(Q->rear<Q->front)
    t+=MAXQUEUE;

 return(t-Q->front+1);
}
/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *	@description : ȷ�����г���
 *	@param		 : ����ָ��Q
 *	@return		 : ���г���count
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
  return(Q->data_size/sizeof(Q->front->data));
}
/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *	@description : ��Ӳ���
 *	@param		 : ����ָ��Q,�������ָ��data
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data)
{
 if(IsFullAQueue(Q)==TRUE)
    return FLASE;
 Q->data[++Q->rear]=data;
 Q->data_size+=sizeof(data);
 return TRUE;
}
/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *	@description : ��Ӳ���
 *	@param		 : ����ָ��Q,�������ָ��data
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data)
{
  if(IsEmptyLQueue(Q)==TRUE)
    return FLASE;

  Node* p=(Node*)malloc(sizeof(Node));
  p->data=data;
  p->next=NULL;
  Q->rear=p;
  if(Q->data_size==0)
    Q->front=p;
  Q->data_size+=sizeof(data);

  return TRUE;
}
/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *	@description : ���Ӳ���
 *	@param		 : ����ָ��Q
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
    if(IsEmptyAQueue(Q)==TRUE)
    return FLASE;
    Q->data_size-=sizeof(Q->data[Q->front]);
    Q->data[Q->front++]=NULL;
    if(Q->front==MAXQUEUE)
        Q->front-=MAXQUEUE;
    return TRUE;
}
/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *	@description : ���Ӳ���
 *	@param		 : ����ָ��Q
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
  if(IsEmptyLQueue(Q)==TRUE)
    return FLASE;

  Node* p;
  p=Q->front;
  Q->data_size-=sizeof(Q->front->data);
  Q->front=Q->front->next;
  free(p);
  p=Q->front;
  return TRUE;
}
/**
 *  @name        : void ClearAQueue(Queue *Q)
 *	@description : ��ն���
 *	@param		 : ����ָ��Q
 *	@return		 : None
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
 DestoryAQueue(Q);
}
/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *	@description : ��ն���
 *	@param		 : ����ָ��Q
 *	@return		 : None
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
  DestoryLQueue(Q);

}
/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *	@description : ������������
 *	@param		 : ����ָ��Q����������ָ��foo
 *	@return		 : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
 int t=Q->front;
 if(IsEmptyAQueue(Q)==TRUE)
    return FLASE;
 for(;t!=Q->rear;)
 {
     (*foo)(Q->data[t++]);
     if(t==MAXQUEUE)
        t-=MAXQUEUE;
 }
 return TRUE;

}
/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *	@description : ������������
 *	@param		 : ����ָ��Q����������ָ��foo
 *	@return		 : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
 Node* p=Q->front;
 if(IsEmptyLQueue(Q)==TRUE)
    return FLASE;

  for(;p!=NULL;p=p->next)//QΪconst,���ܸı�Q�ڲ���ֵ
  {
      (*foo)(p->data);
  }

  return TRUE;
}
/**
 *  @name        : void APrint(void *q)
 *	@description : ��������
 *	@param		 : ָ��q
 *	@return		 : None
 *  @notice      : None
 */
 //APrint(Q->data[front])
 void APrint(void *q)
 {
    int choose=0,flag=0;
    void*p=q;
    for(flag=1;flag!=0;)
    {
        printf("\n\t1:int\n\t2:float\n\t3:char\n\t���������ѡ��");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:printf("%d",*(int*)p);
                   flag=0;break;
            case 2:printf("%f",*(float*)p);
                   flag=0;break;
            case 3:printf("%c",*(char*)p);
                   flag=0;break;
            default:printf("��Чѡ������ѡ\n");

        }
    }
 }
/**
 *  @name        : void LPrint(void *q)
 *	@description : ��������
 *	@param		 : ָ��q
 *	@return		 : None
 *  @notice      : None
 */
 void LPrint(void *q)
 {
    int choose=0,flag=0;
    void*p=q;
    for(flag=1;flag!=0;)
    {
        printf("\n\t1:int\n\t2:float\n\t3:char\n\t���������ѡ��");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:printf("%d",*(int*)p);
                   flag=0;break;
            case 2:printf("%f",*(float*)p);
                   flag=0;break;
            case 3:printf("%c",*(char*)p);
                   flag=0;break;
            default:printf("��Чѡ������ѡ\n");
        }
    }
 }

//#endif // QUEUE_H_INCLUDED
