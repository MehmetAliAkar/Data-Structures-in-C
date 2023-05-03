#ifndef lib1_H
#define lib1_H

struct customer{
    int no;
    char name[25];
    char surname[25];
    int fee;
    char adress[20];
    struct customer * next;
};

struct customer * insert(struct customer * customerHead);
void print(struct customer * customerHead);
struct customer * deleter(int customerNo,struct customer * customerHead);
struct customer * search(int customerNo, struct customer * customerHead);
int totalRevenue(struct customer * customerHead);
int menu(void);

#endif
