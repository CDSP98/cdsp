#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include<conio.h >
#include<ctype.h>

int main()
{

    int data,flag=1,i=0,j=0,x,x1,x2;
    char Fuhao='0',strings[100]="\0",string[100]="\0",*str=strings,k;
    LinkStack zifu;
    Linkstack shuzi;
    zifu.top=NULL;
    shuzi.top=NULL;


    initLstack(&shuzi);
    initLStack(&zifu);
    printf("输入你的表达式,以'='结束:");
    scanf("%s",strings);

    if(*str<='9'&&*str>='0')
            pushLstack(&shuzi,atoi(str));
        for(;isdigit(*str);str++);
        pushLStack(&zifu,*str);
        string[i++]=*str++;


    for(j=0,x=0,x1=0,x2=0;flag;str++)
    {
        if(*str<='9'&&*str>='0')
            pushLstack(&shuzi,atoi(str));
        for(;isdigit(*str);str++);
        string[i++]=*str;

        getTopLStack(&zifu,&k);
        if(k=='(')
          pushLStack(&zifu,*str);
        if((*str=='*'||*str=='/')&&(k=='+'||k=='-'))
        pushLStack(&zifu,*str);
        else if(*str!='('&&*str!=')'&&k!='('&&k!=')')
        {
                     for(;zifu.count!=0;)
                     {
                         popLstack(&shuzi,&x1);
                      popLstack(&shuzi,&x2);
                      popLStack(&zifu,&Fuhao);
                      if(x1==0&&Fuhao=='/')
                        {
                            printf("错误，分母不能为0！\n");
                            continue;
                        }
                      switch(Fuhao)
                        {
                            case '+':x=x1+x2;break;
                            case '-':x=x2-x1;break;
                            case '*':x=x1*x2;break;
                            case '/':x=x2/x1;break;
                            default:break;
                        }
                      pushLstack(&shuzi,x);
                     }
                     pushLStack(&zifu,*str);
        }

        if(*str=='(')//出现括号的情况
            {
                j++;
                pushLStack(&zifu,*str);
            }
        else if(*str==')')
            {

                if(j>0)
                {
                  j--;
                 getTopLStack(&zifu,&Fuhao);
                  for(;Fuhao!='(';)
                  {
                      popLStack(&zifu,&Fuhao);
                      popLstack(&shuzi,&x1);
                      popLstack(&shuzi,&x2);
                      if(x1==0&&Fuhao=='/')
                        {
                            printf("错误，分母不能为0！\n");
                            continue;
                        }
                      switch(Fuhao)
                        {
                            case '+':x=x1+x2;break;
                            case '-':x=x2-x1;break;
                            case '*':x=x1*x2;break;
                            case '/':x=x2/x1;break;
                            default:break;
                        }
                      pushLstack(&shuzi,x);
                      getTopLStack(&zifu,&Fuhao);
                  }
                  if(Fuhao=='(')
                        popLStack(&zifu,&Fuhao);
                }
                else
                {
                    printf("括号匹配错误!\n");
                    break;
                }

            }

        if(*str=='=')//表示式结束的时候
        {
             if(j>0)
                {
                    printf("括号匹配错误!\n");
                    break;
                }
           for(;zifu.count!=0;)
                  {
                      popLStack(&zifu,&Fuhao);
                      popLstack(&shuzi,&x1);
                      popLstack(&shuzi,&x2);
                      if(x1==0&&Fuhao=='/')
                        {
                            printf("错误，分母不能为0！\n");
                            continue;
                        }
                      switch(Fuhao)
                        {
                            case '+':x=x1+x2;break;
                            case '-':x=x2-x1;break;
                            case '*':x=x1*x2;break;
                            case '/':x=x2/x1;break;
                            default:break;
                        }
                      pushLstack(&shuzi,x);
                  }
             popLstack(&shuzi,&data);
             printf("=%d",data);
             flag=0;
        }

    }
}
