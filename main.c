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
    struct birth year;
    int score;
};


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
