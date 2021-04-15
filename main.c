#include<stdio.h>
#include<stdlib.h>
struct birth
{
    int year;
    int month;
    int day;
};

struct student
{
    char name[100];
    int id;
    struct birth date;
    int score;
};


struct node
{ struct student stu ;
struct node *next;
};

struct node *head=NULL,*tail=NULL,*temp=NULL;

void insert_beg(struct student st)
{temp=(struct node *)malloc(sizeof(struct node));
 temp->stu=st;
 if(head==NULL)
 {temp->next=NULL;
 head=tail=temp;
 }
 else
 {temp->next=head;
  head=temp;
 }
 }



void insert_end(struct student st)
{temp=(struct node *)malloc(sizeof(struct node));
 temp->stu=st;
 if(head==NULL)
 {temp->next=NULL;
 head=tail=temp;
 }
 else
 {temp->next=NULL;
 tail->next=temp;
 tail=temp;

 }
}


void insert_mid(int index,struct student st)
{temp=(struct node *)malloc(sizeof(struct node));
  temp->stu=st;
  if(index==0)
  insert_beg(st);
  else{ int i=0;
  struct node *temp2=head;
  for(i;i<index-1;i++)
      temp2=temp2->next;
  if(temp2==tail)
  insert_end(st);
  else{
  temp->next=temp2->next;
  temp2->next=temp;
}}}


void print() //print all the content of the linked list
{ struct node *temp2=head;
int i=0;
while(temp2!=NULL)
{printf("name of student is %s\n",temp2->stu.name);
 printf("id of student is %d\n",temp2->stu.id);
 printf("birth date of student is %d",temp2->stu.date.day);
 printf("/%d",temp2->stu.date.month);
 printf("/%d\n",temp2->stu.date.year);
 printf("score of student is %d\n\n",temp2->stu.score);

 temp2=temp2->next;
 }}


int element_size =sizeof(struct student);
int stud_num=0;



struct student *insert_beg_array (struct student to_insert,struct student *old_data)
{stud_num++;
    old_data=(struct student*)realloc(old_data,stud_num*element_size);
int i;
for(i=stud_num-1;i!=0;i--)
{
    old_data[i]=old_data[i-1];
}
old_data[0]=to_insert;
return old_data;
}


struct student * insert_end_array (struct student to_insert,struct student *old_data)
{
stud_num++;
old_data=(struct student*)realloc(old_data,stud_num*element_size);
old_data[stud_num-1]=to_insert;
return old_data;
}

struct student * insert_mid_array (int index,struct student to_insert,struct student *old_data)
{stud_num++;
 old_data=(struct student*)realloc(old_data,stud_num*element_size);
int i;
for(i=stud_num-1;i!=index;i--)
{
    old_data[i]=old_data[i-1];
}
old_data[index]=to_insert;
return old_data;
}

void print_array(struct student *old_data)
{ int i=0;
    for(i;i<stud_num;i++)
    {
 printf("name of student is %s\n",old_data[i].name);
 printf("id of student is %d\n",old_data[i].id);
 printf("birth date of student is %d",old_data[i].date.day);
 printf("/%d",old_data[i].date.month);
 printf("/%d\n",old_data[i].date.year);
 printf("score of student is %d\n\n",old_data[i].score);

    }

}


int main ()
{

}
