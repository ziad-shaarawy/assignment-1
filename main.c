#include<stdio.h>
#include<stdlib.h>
struct birth  //structure for the birth of the student
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


struct node     //structure for the linked list node
{
    struct student stu ;
    struct node *next;
};


//**************using the linked list**********************
struct node *head=NULL,*tail=NULL,*added=NULL; //initialization of the pointers used in the linked list


void insert(int index,struct student st)    //the function used to insert at any position of the linked list
{
    added=(struct node *)malloc(sizeof(struct node));  //the pointer used to add a new node in the linked list
    added->stu=st;
    if(index==0)  //if the function is entered to insert at position  zero
    {
        if(head==NULL)     //if the function is entered to create the first node
        {
            added->next=NULL;
            head=tail=added;
        }
        else       //when the function is entered after creating the first node
        {
            added->next=head;
            head=added;
        }
    }
    else
    {
        int i=0;
        struct node *temp=head;
        for(i;i<index-1;i++)
        {
            temp=temp->next;
        }
        added->next=temp->next;
        temp->next=added;
    }
}


void print() //print all the content of the linked list
{
    struct node *temp=head;
    if (temp==NULL)
        printf("no students in the linked list!\n\n");
    while(temp!=NULL)
    {
        printf("name of student is %s\n",temp->stu.name);
        printf("id of student is %d\n",temp->stu.id);
        printf("birth date of student is %d",temp->stu.date.day);
        printf("/%d",temp->stu.date.month);
        printf("/%d\n",temp->stu.date.year);
        printf("score of student is %d\n\n",temp->stu.score);
        temp=temp->next;
    }
}

//***********using dynamic array*************
int element_size =sizeof(struct student);   //the size of one student
int stud_num=0; //a counter that counts the number of students to be added


struct student * insert_array (int index,struct student to_insert,struct student *all_students) //the function used to insert at any position in the array
{
    stud_num++; //increments the number of students
    all_students=(struct student*)realloc(all_students,stud_num*element_size);   //increases the size of the dynamic array by one student
    int i;
    for(i=stud_num-1;i>index;i--)  //shifts all the elements after the index to the right then insert the new student at the specified index
    {
        all_students[i]=all_students[i-1];
    }
    all_students[index]=to_insert;
    return all_students;
}

void print_array(struct student *all_students)  //the function used to print the students in the array
{
    int i=0;
    for(i;i<stud_num;i++)
    {
        printf("name of student is %s\n",all_students[i].name);
        printf("id of student is %d\n",all_students[i].id);
        printf("birth date of student is %d",all_students[i].date.day);
        printf("/%d",all_students[i].date.month);
        printf("/%d\n",all_students[i].date.year);
        printf("score of student is %d\n\n",all_students[i].score);
    }
    if (i==0)
        printf("no students in the array!\n\n");

}

//**********************the main function**********************
int main(int argc,char* argv[])
{

}
