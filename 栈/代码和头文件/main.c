
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
    printf("\tѡ��˳��ջ������ʽջ\n");
    printf("\t1.˳��ջ\n");
    printf("\t2.��ʽջ\n");
        if(scanf("%d",&a)==0)
    {
      printf("\t�������ʹ���\n");
      system("pause");
      getchar();
    }
    if(a==1)
    {
     while(b)
     {
        system("pause");
        system("cls");
        printf("\t˳��ջ:\n");
        printf("\t1.��ʼ��ջ\n");
        printf("\t2.�ж�ջ�Ƿ�Ϊ��\n");
        printf("\t3.�õ�ջ��Ԫ��\n");
        printf("\t4.���ջ\n");
        printf("\t5.����ջ\n");
        printf("\t6.���ջ����\n");
        printf("\t7.��ջ\n");
        printf("\t8.��ջ\n");
        printf("\t9.�˳�\n");
        printf("\t������1~9������\n");
        printf("\t�������������ֵӦ��-2^15~2^15֮��\n");
        while(scanf("%d",&b)!=1)
        {
         printf("�������ʹ���\n");
         fflush(stdin);
        }
      switch(b)
      {
          case 1:
              {
                printf("����������ջ�Ĵ�Сsizes=");
                if(scanf("%d",&sizes)==0)
                {
                   printf("\t�������ʹ���\n");
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
                   printf("ջ������Ϊ%d\n",e);
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
                  printf("ջ����Ϊ:%d",length);
              }
              else printf("ERROR\n");
                break;
            }

          case 7:
            {
              printf("������ջ������:");
              if(scanf("%d",E)==0)
                {
                   printf("\t�������ʹ���\n");
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
                  printf("��ջ������Ϊ:%d",e);
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
        printf("\t��ʽջ:\n");
        printf("\t1.��ʼ��ջ\n");
        printf("\t2.�ж�ջ�Ƿ�Ϊ��\n");
        printf("\t3.�õ�ջ��Ԫ��\n");
        printf("\t4.���ջ\n");
        printf("\t5.����ջ\n");
        printf("\t6.���ջ����\n");
        printf("\t7.��ջ\n");
        printf("\t8.��ջ\n");
        printf("\t9.�˳�\n");
        printf("\t������1~9������\n");
        printf("\t�������������ֵӦ��-2^15~2^15֮��\n");
       while(scanf("%d",&b)!=1)
        {
         printf("�������ʹ���\n");
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
                   printf("ջ������Ϊ%d\n",e);
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
                  printf("ջ����Ϊ:%d",length);
              }
              else
                printf("ERROR\n");
                break;
            }

          case 7:
            {
              printf("������ջ������:");
              if(scanf("%d",E)==0)
                {
                   printf("\t�������ʹ���\n");
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
                  printf("��ջ������Ϊ:%d",e);
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
       printf("\t���ݴ���\n");
       printf("\t����������\n");
       goto yi;
    }

}
