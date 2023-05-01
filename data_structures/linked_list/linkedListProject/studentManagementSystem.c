#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>//to use boolean statement

//student management system with linked list

struct student // define the student struct 
{
    int no;
    char name[20];
    char surname[25];
    int midterm,final;
    float average;
    struct student * next;
};

typedef struct student std;

struct student * insert(struct student * stdHead)
{
    struct student * std = (struct student*)malloc(sizeof(struct student));
    printf("Student Number  : ");    scanf("%d",&std->no);
    printf("Student Name    : ");    scanf(" %s",std->name);
    printf("Student Surname : ");    scanf(" %s",std->surname);
    printf("Student Midterm : ");    scanf("%d",&std->midterm);
    printf("Student Final   : " );    scanf("%d",&std->final);
    std->average = std->midterm * 0.6 + std->final * 0.4;

    if (stdHead==NULL)//if linked list is empty insert the first student
    {
        stdHead=std;
        stdHead -> next = NULL;
        printf("List has been created and first student is recorded.\n");
    }
    else//if linked list is not empty insert the student to head of the linked list
    {
        std->next = stdHead;
        stdHead=std;
        printf("Student inserted succesfully.\n");
    }
    return stdHead;
}

struct student * display(struct student * stdHead)//function to print all students
{
    system("cls");//to clear the screen 
    if (stdHead == NULL)
    {
        printf("Linked list is empty!\n");
    }
    else
    {
        struct student * temp = stdHead;
        int i=1;
        while (temp != NULL)//while temp is not equal to NULL print all students
        {
            printf("*******************************\n");
            printf("\n%d. Name : %-15s\tSurname : %-15s \tSchool Number : %-15d \t Average : %2.f\n",i,temp->name,temp->surname,temp->no,temp->average);
            i++;
            temp=temp->next;
        }
    }
    return stdHead;
}

bool search(int studentNo,struct student * stdHead)//function for search any student
{
    struct student * temp = stdHead;
    while (temp!=NULL)
    {
        if (temp -> no == studentNo)
        {
            printf("\nName : %-15s\tSurname : %-15s \tSchool Number : %-15d \t Average : %2.f\n",temp->name,temp->surname,temp->no,temp->average);
            return true;
        }
        temp=temp->next;
    }
    printf("No student with this number!\n");
    return false;
}

struct student * highestMark(struct student * stdHead)//funtion to show highest mark student 
{
    if (stdHead==NULL)//if linked list is empty return null
    {
        printf("List is empty!");
        return stdHead;
    }
    struct student * temp = stdHead;
    struct student * max = stdHead;//variable that keeps the highest mark student
    while (temp!=NULL)
    {
        if (max->average < temp->average)//if temp variable's average higher than max variable's average change the max variable
        {
            max=temp;
        }
        temp=temp->next;
    }
    printf("Highest mark student information : \n");
    printf("\nName : %-15s\tSurname : %-15s \tSchool Number : %-15d \t Average : %2.f\n",max->name,max->surname,max->no,max->average);
    return stdHead;
}

struct student * delete(int studentNo,struct student * stdHead)//fuction for delete student 
{
    bool result = false;//inialize the result variable
    struct student * temp = stdHead;
    if (stdHead==NULL)//if linked list is empty
    {
        printf("Empty list!\n");
        return stdHead;
    }
    else
    {
        if(stdHead->no == studentNo && stdHead->next==NULL)//if linked list has one element 
        {
            free(stdHead);
            stdHead=NULL;
            printf("Last student has been deleted!\n");
            result=true;
        }
        else if(stdHead->no==studentNo && stdHead->next!=NULL)//to delete the first element and first element next is not equal to null
        {
            struct student * temp = stdHead->next;
            free(stdHead);
            stdHead=temp;
            printf("Student who has a number %d has been deleted.\n",studentNo);
            result = true;
        }
        else
        {
            struct student * temp,*temp2;
            temp=stdHead;
            while (temp->next!=NULL)
            {
                if (temp->no==studentNo)
                {
                    temp->next=temp2->next;
                    free(temp);
                    printf("Student who has a number %d has been deleted.\n",studentNo);
                    result=true;
                    break;
                }
                temp2=temp;
                temp=temp->next;
            }
            if (temp->no==studentNo)
            {
              temp2->next=NULL;
              free(temp);
              printf("Student who has a number %d has been deleted.\n",studentNo);
              result=true;    
            }
            
        }
        if(!result)
            printf("Student couldn't found!\n");
    }
    return stdHead;
}



int main(void)
{
    int studentNo;
    int choose;
    struct student * head=NULL;//head node
    printf("\t\t*********** STUDENT MANAGEMENT SYSTEM ****************\n");
    while(1)
    {
        printf("1->Insert Student\n");
        printf("2->Delete Student\n");
        printf("3->Search Student\n");
        printf("4->Display Students\n");
        printf("5->Best Student\n");
        printf("0->EXIT\n");
        printf("Select Your Option : ");
        scanf("%d",&choose);

        switch(choose)
        {
            case 0:
                exit(0);
                break;
            case 1:
                head=insert(head);
                break;
            case 2:
                printf("Enter the student number to delete : ");    scanf("%d",&studentNo);
                head=delete(studentNo,head);
                break;
            case 3:
                printf("Enter the student number to search : ");    scanf("%d",&studentNo);
                search(studentNo,head);
                break;
            case 4:
                head=display(head);
                break;
            case 5:
                head=highestMark(head);
                break;
            default:
                printf("Enter your choose again!");
        }
    }
    return 0;
}