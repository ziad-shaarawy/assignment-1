#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
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

void insert_beg(struct student st)  //the function used to insert at the beginning of the linked list
{
    added=(struct node *)malloc(sizeof(struct node));   //the pointer used to add a new node in the linked list
    added->stu=st;
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



void insert_end(struct student st)      //the function used to insert at the end of the linked list
{
    added=(struct node *)malloc(sizeof(struct node)); //the pointer used to add a new node in the linked list
    added->stu=st;
    if(head==NULL)     //if the function is entered to create the first node
    {
        added->next=NULL;
        head=tail=added;
    }
    else       //when the function is entered after creating the first node
    {
        added->next=NULL;
        tail->next=added;
        tail=added;
    }
}


void insert_mid(int index,struct student st)    //the function used to insert at any position of the linked list
{
  if(index==0)  //if the function is entered to insert at position  zero
    insert_beg(st);
  else
  {
    int i=0;
    struct node *temp=head;
    for(i;i<index-1;i++)
    {
        temp=temp->next;
    }

  if(temp==tail)    //if the function is used to insert at the end of the array
    insert_end(st);
  else
  {
    added=(struct node *)malloc(sizeof(struct node));  //the pointer used to add a new node in the linked list
    added->stu=st;
    added->next=temp->next;
    temp->next=added;
  }
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



struct student *insert_beg_array (struct student to_insert,struct student *all_students) //the function used to insert at the beginning of the array
{
    stud_num++; //increments the number of students
    all_students=(struct student*)realloc(all_students,stud_num*element_size); //increases the size of the dynamic array by one student
    int i;
    for(i=stud_num-1;i!=0;i--)  //shifts the last element to the right then insert the new students at the beginning
    {
        all_students[i]=all_students[i-1];
    }
    all_students[0]=to_insert;
    return all_students;
}


struct student * insert_end_array (struct student to_insert,struct student *all_students)   //the function used to insert at the beginning of the array
{
    stud_num++; //increments the number of students
    all_students=(struct student*)realloc(all_students,stud_num*element_size);  //increases the size of the dynamic array by one student
    all_students[stud_num-1]=to_insert; //inserts the new student at the end of the array
    return all_students;
}

struct student * insert_mid_array (int index,struct student to_insert,struct student *all_students) //the function used to insert at any position in the array
{
    if (index>stud_num)
    stud_num++; //increments the number of students
    all_students=(struct student*)realloc(all_students,stud_num*element_size);   //increases the size of the dynamic array by one student
    int i;
    for(i=stud_num-1;i!=index;i--)  //shifts all the elements after the index to the right then insert the new student at the specified index
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
int main ()
{
    struct student *students_array=(struct student *)malloc(0);
    while (1)
    {
        struct student st;
        int first_choice,sec_choice,index;
        printf("please choose from the following options:\n\n");
        printf("enter '1' to use the linked list\n");
        printf("enter '2' to use the dynamic array\n");
        printf("enter '3' to exit\n");
        scanf("%d",&first_choice);
        system("cls");
        switch (first_choice)
        {
        case 1:
            printf("please choose from the following options:\n\n");
            printf("enter '1' to insert student at the beginning\n");
            printf("enter '2' to insert student at the end\n");
            printf("enter '3' to insert student at the middle\n");
            printf("enter '4' to print all the student in the linked list\n");
            scanf("%d",&sec_choice);
            system("cls");
            switch (sec_choice)
            {
            case 1:
                printf("enter the name of the student: ");
                fflush(stdin);
                gets(st.name);
                printf("enter the id of the student: ");
                scanf("%d",&st.id);
                printf("enter the year of birth: ");
                scanf("%d,",&st.date.year);
                printf("enter the month of birth: ");
                scanf("%d,",&st.date.month);
                printf("enter the day of birth: ");
                scanf("%d,",&st.date.day);
                printf("enter the score of the student: ");
                scanf("%d,",&st.score);
                insert_beg(st);
                printf("the student is added successfully!\n\n");
                break;
            case 2:
                printf("enter the name of the student: ");
                fflush(stdin);
                gets(st.name);
                printf("enter the id of the student: ");
                scanf("%d",&st.id);
                printf("enter the year of birth: ");
                scanf("%d,",&st.date.year);
                printf("enter the month of birth: ");
                scanf("%d,",&st.date.month);
                printf("enter the day of birth: ");
                scanf("%d,",&st.date.day);
                printf("enter the score of the student: ");
                scanf("%d,",&st.score);
                insert_end(st);
                printf("the student is added successfully!\n\n");
                break;
            case 3:
                printf("enter the name of the student: ");
                fflush(stdin);
                gets(st.name);
                printf("enter the id of the student: ");
                scanf("%d",&st.id);
                printf("enter the year of birth: ");
                scanf("%d,",&st.date.year);
                printf("enter the month of birth: ");
                scanf("%d,",&st.date.month);
                printf("enter the day of birth: ");
                scanf("%d,",&st.date.day);
                printf("enter the score of the student: ");
                scanf("%d,",&st.score);
                printf("enter the index of the student: ");
                scanf("%d",&index);
                insert_mid(index,st);
                printf("the student is added successfully!\n\n");
                break;
            case 4:
                print();
                break;
            }
            break;
        case 2:
            printf("please choose from the following options:\n\n");
            printf("enter '1' if to insert student at the beginning\n");
            printf("enter '2' to insert student at the end\n");
            printf("enter '3' to insert student at the middle\n");
            printf("enter '4' to print all the student in the array\n");
            scanf("%d",&sec_choice);
            system("cls");
            switch (sec_choice)
            {
            case 1:
                printf("enter the name of the student: ");
                fflush(stdin);
                gets(st.name);
                printf("enter the id of the student: ");
                scanf("%d",&st.id);
                printf("enter the year of birth: ");
                scanf("%d,",&st.date.year);
                printf("enter the month of birth: ");
                scanf("%d,",&st.date.month);
                printf("enter the day of birth: ");
                scanf("%d,",&st.date.day);
                printf("enter the score of the student: ");
                scanf("%d,",&st.score);
                students_array=insert_beg_array(st,students_array);
                printf("the student is added successfully!\n\n");
                break;
            case 2:
                printf("enter the name of the student: ");
                fflush(stdin);
                gets(st.name);
                printf("enter the id of the student: ");
                scanf("%d",&st.id);
                printf("enter the year of birth: ");
                scanf("%d,",&st.date.year);
                printf("enter the month of birth: ");
                scanf("%d,",&st.date.month);
                printf("enter the day of birth: ");
                scanf("%d,",&st.date.day);
                printf("enter the score of the student: ");
                scanf("%d,",&st.score);
                students_array=insert_end_array(st,students_array);
                printf("the student is added successfully!\n\n");
                break;
            case 3:
                printf("enter the name of the student: ");
                fflush(stdin);
                gets(st.name);
                printf("enter the id of the student: ");
                scanf("%d",&st.id);
                printf("enter the year of birth: ");
                scanf("%d,",&st.date.year);
                printf("enter the month of birth: ");
                scanf("%d,",&st.date.month);
                printf("enter the day of birth: ");
                scanf("%d,",&st.date.day);
                printf("enter the score of the student: ");
                scanf("%d,",&st.score);
                printf("enter the index of the student: ");
                scanf("%d",&index);
                students_array=insert_mid_array(index,st,students_array);
                printf("the student is added successfully!\n\n");
                break;
            case 4:
                print_array(students_array);
                break;
            }
            break;
        case 3:
            exit(0);

        }
    }

}
