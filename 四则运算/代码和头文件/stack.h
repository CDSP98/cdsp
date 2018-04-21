typedef char ElemType;
typedef int Elemtype;

typedef enum Status
{
    ERROR = 0,OK = 1
}Status;

typedef struct Stacknode
{
    Elemtype data;
    struct Stacknode *next;
}Stacknode,*LinkstackPtr;

typedef struct Linkstack
{
    LinkstackPtr top;
    int count;
}Linkstack;

typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;

Status initLStack(LinkStack *s);
Status isEmptyLStack(LinkStack *s);
Status getTopLStack(LinkStack *s,ElemType *e);
Status clearLStack(LinkStack *s);
Status destoryLStack(LinkStack *s);
Status LStackLength(LinkStack *s,int *length);
Status pushLStack(LinkStack *s,ElemType datas);
Status popLStack(LinkStack *s,ElemType *datas);

Status initLstack(Linkstack *s);
Status isEmptyLstack(Linkstack *s);
Status getTopLstack(Linkstack *s,Elemtype *e);
Status clearLstack(Linkstack *s);
Status destorystack(Linkstack *s);
Status LstackLength(Linkstack *s,int *length);
Status pushLstack(Linkstack *s,Elemtype datas);
Status popLstack(Linkstack *s,Elemtype *datas);
