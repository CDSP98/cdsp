
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void main()
{
  int a=0,b=1,sizes=0,length=0,*Length=&length;
  ElemType e=0,*E=&e;
  SqStack se,*s=&se;
  LinkStack SE,*S=&SE;
  se.elem=NULL;
  SE.top=NULL;
  yi:
    system("cls");
    printf("\t选择顺序栈还是链式栈\n");
    printf("\t1.顺序栈\n");
    printf("\t2.链式栈\n");
        if(scanf("%d",&a)==0)
    {
      printf("\t数据类型错误\n");
      system("pause");
      getchar();
    }
    if(a==1)
    {
     while(b)
     {
        system("pause");
        system("cls");
        printf("\t顺序栈:\n");
        printf("\t1.初始化栈\n");
        printf("\t2.判断栈是否为空\n");
        printf("\t3.得到栈顶元素\n");
        printf("\t4.清空栈\n");
        printf("\t5.销毁栈\n");
        printf("\t6.检测栈长度\n");
        printf("\t7.入栈\n");
        printf("\t8.出栈\n");
        printf("\t9.退出\n");
        printf("\t请输入1~9号数字\n");
        printf("\t后续的输入的数值应在-2^15~2^15之间\n");
        while(scanf("%d",&b)!=1)
        {
         printf("数据类型错误\n");
         fflush(stdin);
        }
      switch(b)
      {
          case 1:
              {
                printf("请输入数组栈的大小sizes=");
                if(scanf("%d",&sizes)==0)
                {
                   printf("\t数据类型错误\n");
                   system("pause");

                }

                  if(initStack(s,sizes)==OK)
                    printf("OK\n");
                  else printf("ERROR\n");
                    break;
              }

          case 2:
            {
              if(isEmptyStack(s)==OK)
                    printf("OK\n");
              else
                printf("ERROR\n");
              break;
            }

          case 3:
            {
               if(getTopStack(s,E)==OK)
               {
                   printf("OK\n");
                   printf("栈顶数据为%d\n",e);
               }
               else
                printf("ERROR\n");
              break;
            }

          case 4:
            {
              if(clearStack(s)==OK)
                    printf("OK\n");
              else printf("ERROR\n");
                break;
            }

          case 5:
            {
              if(destoryStack(s)==OK)
                    printf("OK\n");
              else printf("ERROR\n");
                break;
            }

          case 6:
            {
              if(StackLength(s,Length)==OK)
              {
                  printf("OK\n");
                  printf("栈长度为:%d",length);
              }
              else printf("ERROR\n");
                break;
            }

          case 7:
            {
              printf("输入入栈的数据:");
              if(scanf("%d",E)==0)
                {
                   printf("\t数据类型错误\n");
                   break;
                }
              if(pushStack(s,e)==OK)
                    printf("OK\n");
              else
                printf("ERROR\n");
              break;
            }

          case 8:
            {
              if(popStack(s,E)==OK)
              {
                  printf("OK\n");
                  printf("出栈的数据为:%d",e);
              }
              else
                printf("ERROR\n");
              break;
            }

          default:destoryStack(s);b=0;
      }
     }
    }
    else if(a==2)
    {
     while(b)
     {
        system("pause");
        system("cls");
        printf("\t链式栈:\n");
        printf("\t1.初始化栈\n");
        printf("\t2.判断栈是否为空\n");
        printf("\t3.得到栈顶元素\n");
        printf("\t4.清空栈\n");
        printf("\t5.销毁栈\n");
        printf("\t6.检测栈长度\n");
        printf("\t7.入栈\n");
        printf("\t8.出栈\n");
        printf("\t9.退出\n");
        printf("\t请输入1~9号数字\n");
        printf("\t后续的输入的数值应在-2^15~2^15之间\n");
       while(scanf("%d",&b)!=1)
        {
         printf("数据类型错误\n");
         fflush(stdin);
        }
      switch(b)
      {
          case 1:
              {
                  if(initLStack(S)==OK)
                    printf("OK\n");
                  else printf("ERROR\n");
                    break;
              }

          case 2:
            {
              if(isEmptyLStack(S)==OK)
                    printf("OK\n");
              else
                printf("ERROR\n");
              break;
            }

          case 3:
            {
               if(getTopLStack(S,E)==OK)
               {
                   printf("OK\n");
                   printf("栈顶数据为%d\n",e);
               }
               else
                printf("ERROR\n");
              break;
            }

          case 4:
            {
              if(clearLStack(S)==OK)
                    printf("OK\n");
              else printf("ERROR\n");
                break;
            }

          case 5:
            {
              if(destoryLStack(S)==OK)
                    printf("OK\n");
              else printf("ERROR\n");
                break;
            }

          case 6:
            {
              if(LStackLength(S,Length)==OK)
              {
                  printf("OK\n");
                  printf("栈长度为:%d",length);
              }
              else
                printf("ERROR\n");
                break;
            }

          case 7:
            {
              printf("输入入栈的数据:");
              if(scanf("%d",E)==0)
                {
                   printf("\t数据类型错误\n");
                   system("pause");
                   break;
                }
              if(pushLStack(S,e)==OK)
                    printf("OK\n");
              else
                printf("ERROR\n");
              break;
            }

          case 8:
            {
              if(popLStack(S,E)==OK)
              {
                  printf("OK\n");
                  printf("出栈的数据为:%d",e);
              }
              else
                printf("ERROR\n");
              break;
            }

          default:destoryLStack(S);b=0;
    }
    }
   }
    else
    {
       printf("\t数据错误\n");
       printf("\t请重新输入\n");
       goto yi;
    }

}
