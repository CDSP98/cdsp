#include<stdio.h>
#include<stdlib.h>
#include"queue.h"


int main()
{
  AQueue Q;
  LQueue q;
  int i,j,l,s;
  void* k;

  char c;
  float f;

  InitAQueue(&Q);
  InitLQueue(&q);

  printf("\t选择循环队列还是链式队列\n");
  printf("\t1.循环队列\n");
  printf("\t2.链式队列\n");
  while(scanf("%d",&i)!=1)
  {
      printf("输入错误，请重新输入\n");
  }

  for(;1;)
  {

  if(i==1)
  {
     printf("\t循环队列\n");
     printf("\t1.初始化队列\n");
     printf("\t2.销毁队列\n");
     printf("\t3.检查队列是否已满\n");
     printf("\t4.检查队列是否为空\n");
     printf("\t5.查看队头元素\n");
     printf("\t6.确定队列长度\n");
     printf("\t7.入队操作\n");
     printf("\t8.出队操作\n");
     printf("\t9.清空队列\n");
     printf("\t10.遍历函数操作\n");
     printf("\t11及以上 退出\n");
     printf("\t请输入1~11号数字\n");
      while(scanf("%d",&j)!=1)
    {
      printf("输入错误，请重新输入\n");
    }

      switch(j)
    {
        case 1:
            {
                InitAQueue(&Q);
                printf("初始化成功\n");
                break;
            }
        case 2:
            {
                DestoryAQueue(&Q);
                printf("销毁成功\n");
                break;
            }
        case 3:
            {
                if(IsFullAQueue(&Q)==TRUE)
                    printf("队列满\n");
                else
                    printf("队列未满\n");
                break;
            }
        case 4:
            {
                if(IsEmptyAQueue(&Q)==TRUE)
                    printf("队列空\n");
                else
                    printf("队列未空\n");
                break;
            }
        case 5:
            {
                if(GetHeadAQueue(&Q,&k)==TRUE)
                    APrint(&k);
                else
                    printf("获取失败\n");

                    break;
            }
        case 6:
            {
                printf("队列长度为:%d",LengthAQueue(&Q));
                break;
            }
        case 7:
            {
                printf("输入要输入的数据的类型\n1.整形\t2.字符\t3.浮点型\n");
                scanf("%d",&l);
                printf("输入要输入的数据:\n");
                switch(l)
                {
                    case 1:
                        {
                            scanf("%d",&s);
                            if(EnAQueue(&Q,&s)==TRUE)
                                printf("入队成功\n");
                            else
                                printf("入队失败\n");
                                break;
                        }
                    case 2:
                        {
                            scanf("%c",&c);
                            if(EnAQueue(&Q,&c)==TRUE)
                                printf("入队成功\n");
                            else
                                printf("入队失败\n");
                                break;
                        }
                    case 3:
                        {
                            scanf("%f",&f);
                            if(EnAQueue(&Q,&f)==TRUE)
                                printf("入队成功\n");
                            else
                                printf("入队失败\n");
                                break;
                        }

                }
                  break;
            }
         case 8:
            {
                 if(DeAQueue(&Q)==TRUE)
                                printf("出队成功\n");
                 else
                    printf("出队失败\n");
                    break;
            }
         case 9:
            {
                ClearAQueue(&Q);
                break;
            }
         case 10:
            {
                if(TraverseAQueue(&Q,APrint)==TRUE)
                    printf("遍历成功\n");
                else
                printf("遍历失败\n");
                break;
            }
         default:return 0;
    }
  }


  else
  {
     printf("\t链式队列\n");
     printf("\t1.初始化队列\n");
     printf("\t2.销毁队列\n");
     printf("\t3.检查队列是否为空\n");
     printf("\t4.查看队头元素\n");
     printf("\t5.确定队列长度\n");
     printf("\t6.入队操作\n");
     printf("\t7.出队操作\n");
     printf("\t8.清空队列\n");
     printf("\t9.遍历函数操作\n");
     printf("\t10及以上 退出\n");
     printf("\t请输入1~10号数字\n");
      while(scanf("%d",&j)!=1)
    {
      printf("输入错误，请重新输入\n");
    }

     switch(j)
    {
        case 1:
            {
                InitLQueue(&Q);
                printf("初始化成功\n");
                break;
            }
        case 2:
            {
                DestoryLQueue(&Q);
                printf("销毁成功\n");
                break;
            }
        case 3:
            {
                if(IsEmptyLQueue(&Q)==TRUE)
                    printf("队列空\n");
                else
                    printf("队列未空\n");
                break;
            }
        case 4:
            {
                if(GetHeadLQueue(&Q,&k)==TRUE)
                    APrint(&k);
                else
                    printf("获取失败\n");
                    break;
            }
        case 5:
            {
                printf("队列长度为:%d",LengthLQueue(&Q));
                break;
            }
        case 6:
            {
                printf("输入要输入的数据的类型\n1.整形\t2.字符\t3.浮点型\n");
                scanf("%d",&l);
                printf("输入要输入的数据:\n");
                switch(l)
                {
                    case 1:
                        {
                            scanf("%d",&s);
                            if(EnLQueue(&Q,&s)==TRUE)
                                printf("入队成功\n");
                            else
                                printf("入队失败\n");
                                break;
                        }
                    case 2:
                        {
                            scanf("%c",&c);
                            if(EnLQueue(&Q,&c)==TRUE)
                                printf("入队成功\n");
                            else
                                printf("入队失败\n");
                                break;
                        }
                    case 3:
                        {
                            scanf("%f",&f);
                            if(EnLQueue(&Q,&f)==TRUE)
                                printf("入队成功\n");
                            else
                                printf("入队失败\n");
                                break;
                        }

                }
                  break;
            }
         case 7:
            {
                 if(DeLQueue(&Q)==TRUE)
                                printf("出队成功\n");
                 else
                    printf("出队失败\n");
                    break;
            }
         case 8:
            {
                ClearLQueue(&Q);
                break;
            }
         case 9:
            {
                if(TraverseLQueue(&Q,APrint)==TRUE)
                    printf("遍历成功\n");
                else
                printf("遍历失败\n");
                break;
            }
         default:return 0;
    }
  }



  }
}
