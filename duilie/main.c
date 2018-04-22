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

  printf("\tѡ��ѭ�����л�����ʽ����\n");
  printf("\t1.ѭ������\n");
  printf("\t2.��ʽ����\n");
  while(scanf("%d",&i)!=1)
  {
      printf("�����������������\n");
  }

  for(;1;)
  {

  if(i==1)
  {
     printf("\tѭ������\n");
     printf("\t1.��ʼ������\n");
     printf("\t2.���ٶ���\n");
     printf("\t3.�������Ƿ�����\n");
     printf("\t4.�������Ƿ�Ϊ��\n");
     printf("\t5.�鿴��ͷԪ��\n");
     printf("\t6.ȷ�����г���\n");
     printf("\t7.��Ӳ���\n");
     printf("\t8.���Ӳ���\n");
     printf("\t9.��ն���\n");
     printf("\t10.������������\n");
     printf("\t11������ �˳�\n");
     printf("\t������1~11������\n");
      while(scanf("%d",&j)!=1)
    {
      printf("�����������������\n");
    }

      switch(j)
    {
        case 1:
            {
                InitAQueue(&Q);
                printf("��ʼ���ɹ�\n");
                break;
            }
        case 2:
            {
                DestoryAQueue(&Q);
                printf("���ٳɹ�\n");
                break;
            }
        case 3:
            {
                if(IsFullAQueue(&Q)==TRUE)
                    printf("������\n");
                else
                    printf("����δ��\n");
                break;
            }
        case 4:
            {
                if(IsEmptyAQueue(&Q)==TRUE)
                    printf("���п�\n");
                else
                    printf("����δ��\n");
                break;
            }
        case 5:
            {
                if(GetHeadAQueue(&Q,&k)==TRUE)
                    APrint(&k);
                else
                    printf("��ȡʧ��\n");

                    break;
            }
        case 6:
            {
                printf("���г���Ϊ:%d",LengthAQueue(&Q));
                break;
            }
        case 7:
            {
                printf("����Ҫ��������ݵ�����\n1.����\t2.�ַ�\t3.������\n");
                scanf("%d",&l);
                printf("����Ҫ���������:\n");
                switch(l)
                {
                    case 1:
                        {
                            scanf("%d",&s);
                            if(EnAQueue(&Q,&s)==TRUE)
                                printf("��ӳɹ�\n");
                            else
                                printf("���ʧ��\n");
                                break;
                        }
                    case 2:
                        {
                            scanf("%c",&c);
                            if(EnAQueue(&Q,&c)==TRUE)
                                printf("��ӳɹ�\n");
                            else
                                printf("���ʧ��\n");
                                break;
                        }
                    case 3:
                        {
                            scanf("%f",&f);
                            if(EnAQueue(&Q,&f)==TRUE)
                                printf("��ӳɹ�\n");
                            else
                                printf("���ʧ��\n");
                                break;
                        }

                }
                  break;
            }
         case 8:
            {
                 if(DeAQueue(&Q)==TRUE)
                                printf("���ӳɹ�\n");
                 else
                    printf("����ʧ��\n");
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
                    printf("�����ɹ�\n");
                else
                printf("����ʧ��\n");
                break;
            }
         default:return 0;
    }
  }


  else
  {
     printf("\t��ʽ����\n");
     printf("\t1.��ʼ������\n");
     printf("\t2.���ٶ���\n");
     printf("\t3.�������Ƿ�Ϊ��\n");
     printf("\t4.�鿴��ͷԪ��\n");
     printf("\t5.ȷ�����г���\n");
     printf("\t6.��Ӳ���\n");
     printf("\t7.���Ӳ���\n");
     printf("\t8.��ն���\n");
     printf("\t9.������������\n");
     printf("\t10������ �˳�\n");
     printf("\t������1~10������\n");
      while(scanf("%d",&j)!=1)
    {
      printf("�����������������\n");
    }

     switch(j)
    {
        case 1:
            {
                InitLQueue(&Q);
                printf("��ʼ���ɹ�\n");
                break;
            }
        case 2:
            {
                DestoryLQueue(&Q);
                printf("���ٳɹ�\n");
                break;
            }
        case 3:
            {
                if(IsEmptyLQueue(&Q)==TRUE)
                    printf("���п�\n");
                else
                    printf("����δ��\n");
                break;
            }
        case 4:
            {
                if(GetHeadLQueue(&Q,&k)==TRUE)
                    APrint(&k);
                else
                    printf("��ȡʧ��\n");
                    break;
            }
        case 5:
            {
                printf("���г���Ϊ:%d",LengthLQueue(&Q));
                break;
            }
        case 6:
            {
                printf("����Ҫ��������ݵ�����\n1.����\t2.�ַ�\t3.������\n");
                scanf("%d",&l);
                printf("����Ҫ���������:\n");
                switch(l)
                {
                    case 1:
                        {
                            scanf("%d",&s);
                            if(EnLQueue(&Q,&s)==TRUE)
                                printf("��ӳɹ�\n");
                            else
                                printf("���ʧ��\n");
                                break;
                        }
                    case 2:
                        {
                            scanf("%c",&c);
                            if(EnLQueue(&Q,&c)==TRUE)
                                printf("��ӳɹ�\n");
                            else
                                printf("���ʧ��\n");
                                break;
                        }
                    case 3:
                        {
                            scanf("%f",&f);
                            if(EnLQueue(&Q,&f)==TRUE)
                                printf("��ӳɹ�\n");
                            else
                                printf("���ʧ��\n");
                                break;
                        }

                }
                  break;
            }
         case 7:
            {
                 if(DeLQueue(&Q)==TRUE)
                                printf("���ӳɹ�\n");
                 else
                    printf("����ʧ��\n");
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
                    printf("�����ɹ�\n");
                else
                printf("����ʧ��\n");
                break;
            }
         default:return 0;
    }
  }



  }
}
