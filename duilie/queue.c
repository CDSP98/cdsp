#include"queue.h"
#include<stdlib.h>
#include<stdio.h>
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *	@description : 初始化队列
 *	@param		 : 队列指针Q
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
 *	@description : 初始化队列
 *	@param		 : 队列指针Q
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
 *	@description : 销毁队列
 *	@param		 : 队列指针Q
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
 *	@description : 销毁队列
 *	@param		 : 队列指针Q
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
 *	@description : 检查队列是否已满
 *	@param		 : 队列指针Q
 *	@return		 : 满-TRUE; 未满-FLASE
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
 *	@description : 检查队列是否为空
 *	@param		 : 队列指针Q
 *	@return		 : 空-TRUE; 未空-FLASE
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
 *	@description : 检查队列是否为空
 *	@param		 : 队列指针Q
 *	@return		 : 空-TRUE; 未空-FLASE
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
 *	@description : 查看队头元素
 *	@param		 : 队列指针Q，存放元素e
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : 队列是否空
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
 *	@description : 查看队头元素
 *	@param		 : 队列指针Q，存放元素e
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : 队列是否空
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
 *	@description : 确定队列长度
 *	@param		 : 队列指针Q
 *	@return		 : 队列长度count
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
 *	@description : 确定队列长度
 *	@param		 : 队列指针Q
 *	@return		 : 队列长度count
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
  return(Q->data_size/sizeof(Q->front->data));
}
/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *	@description : 入队操作
 *	@param		 : 队列指针Q,入队数据指针data
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : 队列是否满了或为空
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
 *	@description : 入队操作
 *	@param		 : 队列指针Q,入队数据指针data
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : 队列是否为空
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
 *	@description : 出队操作
 *	@param		 : 队列指针Q
 *	@return		 : 成功-TRUE; 失败-FLASE
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
 *	@description : 出队操作
 *	@param		 : 队列指针Q
 *	@return		 : 成功-TRUE; 失败-FLASE
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
 *	@description : 清空队列
 *	@param		 : 队列指针Q
 *	@return		 : None
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
 DestoryAQueue(Q);
}
/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *	@description : 清空队列
 *	@param		 : 队列指针Q
 *	@return		 : None
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
  DestoryLQueue(Q);

}
/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *	@description : 遍历函数操作
 *	@param		 : 队列指针Q，操作函数指针foo
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
 *	@description : 遍历函数操作
 *	@param		 : 队列指针Q，操作函数指针foo
 *	@return		 : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
 Node* p=Q->front;
 if(IsEmptyLQueue(Q)==TRUE)
    return FLASE;

  for(;p!=NULL;p=p->next)//Q为const,不能改变Q内部的值
  {
      (*foo)(p->data);
  }

  return TRUE;
}
/**
 *  @name        : void APrint(void *q)
 *	@description : 操作函数
 *	@param		 : 指针q
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
        printf("\n\t1:int\n\t2:float\n\t3:char\n\t请输入你的选择：");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:printf("%d",*(int*)p);
                   flag=0;break;
            case 2:printf("%f",*(float*)p);
                   flag=0;break;
            case 3:printf("%c",*(char*)p);
                   flag=0;break;
            default:printf("无效选择，请重选\n");

        }
    }
 }
/**
 *  @name        : void LPrint(void *q)
 *	@description : 操作函数
 *	@param		 : 指针q
 *	@return		 : None
 *  @notice      : None
 */
 void LPrint(void *q)
 {
    int choose=0,flag=0;
    void*p=q;
    for(flag=1;flag!=0;)
    {
        printf("\n\t1:int\n\t2:float\n\t3:char\n\t请输入你的选择：");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:printf("%d",*(int*)p);
                   flag=0;break;
            case 2:printf("%f",*(float*)p);
                   flag=0;break;
            case 3:printf("%c",*(char*)p);
                   flag=0;break;
            default:printf("无效选择，请重选\n");
        }
    }
 }

//#endif // QUEUE_H_INCLUDED
