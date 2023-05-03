#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>//for use the boolean expressions
#include "lib1.h"

#define MAX_VAL 25


struct customer * insert(struct customer * customerHead)
{
    struct customer * c1 = (struct customer *)malloc(sizeof(struct customer));
    printf("Customer Number  : ");  scanf("%d",&c1->no);
    getchar();//after scanf automatically adds \n and it makes problem for gets function
    printf("Customer Name    : ");  gets(c1->name);
    printf("Customer Surname : ");  gets(c1->surname);
    printf("Customer Fee     : ");  scanf("%d",&c1->fee);
    getchar();
    printf("Customer Adress  : ");  gets(c1->adress);

    if (customerHead==NULL)//if linked ilst is empty
    {
        customerHead=c1;
        customerHead->next=customerHead;
        printf("List has been created. First customer inserted succesfully.\n");
    }
    else 
    {
        struct customer * temp = customerHead;
        while (temp->next != customerHead)//until came to the end of the list
            temp=temp->next;
        temp->next=c1;//add the new element end of the list
        c1->next=customerHead;
        printf("Customer added to list succesfully.\n");
    }
    return customerHead;
}

void print(struct customer * customerHead)
{
    system("cls");
    if(customerHead==NULL)
    {
        printf("Empty list!\n");
    }
    else
    {
        struct customer * temp = customerHead;
        while (temp->next!=customerHead)
        {
            printf("No : %-10d\tName : %-15s\tSurname : %-15s\tFee : %-10d\tAdress : %-15s\n",temp->no,temp->name,temp->surname,temp->fee,temp->adress);
            temp=temp->next;
        }
         printf("No : %-10d\tName : %-15s\tSurname : %-15s\tFee : %-10d\tAdress : %-15s\n",temp->no,temp->name,temp->surname,temp->fee,temp->adress);
    }
}

struct customer * deleter(int customerNo,struct customer * customerHead)
{
    bool control = false;
    if (customerHead==NULL)
    {
        printf("Empty list");
    }
    else
    {
        if(customerHead->no==customerNo && customerHead->next==customerHead)
        {
            free(customerHead);
            customerHead=NULL;
            printf("\nLast customer has been deleted.\n");
            control = true;
        }
        else if(customerHead->no=customerNo && customerHead->next!=customerHead)
        {
            struct customer * temp=customerHead;
            while (temp->next != customerHead)
                temp=temp->next;
            struct customer * temp2=customerHead->next;
            free(customerHead);
            customerHead=temp2;
            temp->next=customerHead;
            printf("The customer who has a number %d has been deleted.\n",customerNo);
            control=true;            
        }
        else
        {
            struct customer * temp,*temp2;
            temp=customerHead;
            temp2=customerHead;
            while (temp2->next!=customerHead)
            {
                if (temp2->no==customerNo)
                {
                    temp->next = temp2->next;
                    free(temp2);
                    printf("The customer who has a number %d has been deleted.\n",customerNo);
                    control=true;
                }
                temp=temp2;
                temp2=temp2->next;
            }
            if (temp2->no==customerNo)
            {
                temp->next=customerHead;
                free(temp2);
                printf("The customer who has a number %d has been deleted.\n",customerNo);
                control=true;
            }
        }
        if(!control)
        {
            printf("The customer who has a number %d couldn't found! Please enter another number.\n");
        }
    }
    return customerHead;
}

struct customer * search(int customerNo, struct customer * customerHead)
{
    bool control = false;
    if (customerHead==NULL)
    {
        printf("Empty List!\n");
        control=true;
    }
    else
    {
        struct customer * temp = customerHead;
        while (temp->next!=customerHead)
        {
            if (temp->no == customerNo)
            {
                printf("Customer informations : ");
                printf("No : %-10d\tName : %-15s\tSurname : %-15s\tFee : %-10d\tAdress : %-15s\n",temp->no,temp->name,temp->surname,temp->fee,temp->adress);
                control=true;
            }
            temp=temp->next;
        }
        if (temp->no==customerNo)
        {
            printf("Customer informations : ");
            printf("No : %-10d\tName : %-15s\tSurname : %-15s\tFee : %-10d\tAdress : %-15s\n",temp->no,temp->name,temp->surname,temp->fee,temp->adress);
            control=true;
        }
    }
    if(!control)
        printf("Customer who has number %d couldn't found.",customerNo);

    return customerHead;
}

int totalRevenue(struct customer * customerHead)
{
    int sum=0;
    if (customerHead==NULL)
        return 0;
    else
    {
        struct customer * temp = customerHead;
        while (temp->next!=customerHead)
        {
            sum+=temp->fee;
            temp=temp->next;
        }
        sum+=temp->fee;
    }
    return sum;
}

int menu(void)
{
    int secim;
    printf("1->Insert\n");
    printf("2->Delete\n");
    printf("3->Display\n");
    printf("4->Search\n");
    printf("5->Total Revenue\n");
    printf("0->EXITt\n");
    printf("\nYapmak istediginiz islemi seciniz : "); scanf("%d",&secim);
    return secim;
}   

int main(void)
{
    int secim;
    struct customerHead * customerHead = NULL;
    int customerNo;
    printf("\n******** CUSTOMER MANAGEMENT SYSTEM *************\n");
    while(1)
    {
        secim=menu();
        switch(secim)
        {
            case 1:
                customerHead=insert(customerHead);
                break;
            case 2:
                printf("Enter the customer number that you want to delete : ");
                scanf("%d",&customerNo);
                customerHead=delete(customerNo,customerHead);
                break;
            case 3:
                print(customerHead);
                break;
            case 4:
                printf("Enter the customer number that you want to search : ");
                scanf("%d",&customerNo);
                customerHead=search(customerNo,customerHead);
                break;
            case 5:
                system("cls");
                printf("Total revenue of the system is %d .\n",totalRevenue(customerHead));
                break;
            case 0:
                exit(0);
        }
    }
    return 0;
}
