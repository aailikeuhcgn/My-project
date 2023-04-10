#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 640
struct node //�������
{
int address, size;
struct node *next;
};
typedef struct node RECT;
/*-----��������-------*/
RECT *assignment(RECT *head,int application); //�������
void firstfit(RECT *head,RECT *heada,RECT *back1); //����״���Ӧ�����㷨���շ���
void bestfit(RECT *head,RECT *back1); //��������Ӧ�����㷨���շ�����������
int backcheck(RECT *head,RECT *back1); //�Ϸ��Լ��
void print(RECT *head);
//����ѷ�����������з���
/*-----��������-------*/
RECT *head,*heada,*back,*assign1,*p;
int application1,maxblocknum;
char way; //���ڶ�����䷽ʽ��������Ӧ�������Ӧ�������Ӧ�ȣ�Ŀǰδʹ��
int main()
{
char choose;
int check;
RECT *allocated;
head=malloc(sizeof(RECT)); //�������з�����ĳ�ʼ״̬
p=malloc(sizeof(RECT));
head->size=MAX;
head->address=0;
head->next=p;
maxblocknum=1;
p->size=MAX;
p->address=0;
p->next=NULL;
print(head); //������з�����ĳ�ʼ״̬
//printf("Enter the allocation way (best or first (b/f))\n");
//scanf("%c",&way);
way='f';
heada=malloc(sizeof(RECT)); //�����ѷ��������ĳ�ʼ״̬
heada->size=0;
heada->address=0;
heada->next=NULL;
//print(heada); //������з�����ĳ�ʼ״̬
do
{
printf("Enter the allocate or reclaim (a/r),or press other key to exit.\n");
scanf(" %c",&choose);
//ѡ���������
if(tolower(choose)=='a')
//a Ϊ����
{
printf("Input application:\n");
scanf("%d",&application1);
//��������ռ��С
assign1=assignment(head,application1); //���÷��亯�������ڴ�
if (assign1->address==-1)
//���䲻�ɹ�
printf("Too large application! Allocation fails! \n\n");
else
//����ɹ�
printf("Allocation Success! ADDRESS=%5d\n",assign1->address);
printf("\n*********Unallocated Table*************\n");
print(head); //���
printf("\n*********Allocated Table*** **********\n");
print(heada);
}
else if (tolower(choose)=='r')
//�����ڴ�
{
back=malloc(sizeof(RECT));
printf("Input address and Size:\n");
scanf("%d%d",&back->address,&back->size);//������յ�ַ�ʹ�С
check=backcheck(head,back);
if (check==1)
{
if(tolower(way)=='f')
firstfit(head,heada,back);
//������Ӧ�㷨����
printf("\n*********Unallocated Table*************\n");
print(head); //���
printf("\n*********Allocated Table*** **********\n");
print(heada);
}
}
}while(tolower(choose)=='a'||tolower(choose)=='r');
exit(0);
} //main() end. - 24 -
/*-------�ڴ���亯��-------*/
RECT *assignment(RECT *head,int application)
{
RECT *after,*before,*assign;
assign=malloc(sizeof(RECT));
//�������ռ�
assign->size=application;
assign->next=NULL;
if(application>head->size || application<0)
assign->address=-1;
//������Ч
else
{
before=head;
after=head->next;
while(after->size < application)//�����������Һ��ʵ��ڵ�
{
before=before->next;
after=after->next;
}
if(after->size==application)
//���ڵ��С���������С����ȫ����
{
if(after->size==head->size) maxblocknum--;
before->next=after->next;
assign->address=after->address;
free(after);
}
else
{
if(after->size==head->size) maxblocknum--;
after->size=after->size-application; //��������ռ����ȡ��Ӧ��С����
assign->address=after->address+after->size;
}
if (maxblocknum==0)
//�޸��������ͷ�ڵ�
{
before=head;
head->size=0;
maxblocknum=1;
while(before!=NULL)
{
if(before->size > head->size)
{
head->size=before->size;
maxblocknum=1;
}
else if(before->size==head->size)
maxblocknum++;
before=before->next;
}
}
}
assign1=assign;
//�޸��ѷ����������ӽڵ�
after=heada;
while(after->next!=NULL)
after=after->next;
after->next=assign;
heada->size++;
return assign1;
//���ط�����û�����ַ
}
/*------------------������Ӧ�����㷨------------*/
void firstfit(RECT *head,RECT *heada,RECT *back1)
{
RECT *before,*after,*back2;
int insert,del;
back2=malloc(sizeof(RECT));
back2->address=back1->address;
back2->size=back1->size;
back2->next=back1->next;
before=head;
after=head->next;
insert=0;
while(!insert)
//�������������������
{
if((after==NULL)||((back1->address<=after->address)&&(back1->address>=before->address)))
{
before->next=back1;
back1->next=after;
insert=1;
}
else
{
before=before->next;
after=after->next;
}
}
if(back1->address==before->address+before->size) //����һ��ϲ�
{
before->size=before->size+back1->size;
before->next=back1->next;
free(back1);
back1=before;
}
if((after!=NULL) &&(after->address==back1->address+back1->size))//����һ��ϲ�
{
back1->size=back1->size+after->size;
back1->next=after->next;
free(after);
}
if(head->size<back1->size) //�޸�����ֵ���������
{
head->size=back1->size;
maxblocknum=1;
}
else
if(head->size==back1->size) maxblocknum++;
//�޸��ѷ��������ɾ����Ӧ�ڵ�
before=heada;
after=heada->next;
del=0;
while(!del||after!=NULL) //�����������ѷ����������ɾ��
{
if((after->address==back2->address)&&(after->size==back2->size))
{
before->next=after->next;
free(after);
del=1;
}
else
{
before=before->next;
after=after->next;
}
}
heada->size--;
}
/*-----------------��ӡ�������--------------*/
void print(RECT *output)
{
RECT *before;
int index;
before=output->next;
index=0;
if(output->next==NULL)
printf("NO part for print!\n");
else
{
printf("index****address****end*****size**** \n");
while(before!=NULL)
{
printf("------------------------------------\n");
printf("%-9d%- 9d%- 9d%- 9d\n", index, before->address, before->address+
before->size-1, before->size);
printf("-------------------------------------\n");
index++;
before=before->next;
}
}
}
/*�����տ鵽�Ϸ��ԣ�back1 ΪҪ���յ��ڵ��ַ*/
int backcheck(RECT *head,RECT *back1)
{
RECT *before;
int check=1;
if(back1->address<0 || back1->size<0) check=0; //��ַ�ʹ�С����Ϊ����
before=head->next;
while((before!=NULL)&&check) //��ַ���ܺͿ��������нڵ�����ص�
if(((back1->address<before->address)&&(back1->address+back1->size>before->address))||((back1->address>=before->address)&&(back1->address<before->address+before->size))
)
check=0;
else
before=before->next;
if(check==0) printf("Error input!\n");
return check;
}