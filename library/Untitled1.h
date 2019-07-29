#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
FILE *books;
FILE *members;
FILE *borrows;
int x,y,z;
void print_fles();
int validate_date(int*r,int*g,int*q );
int valid_int(char h[],int *c2);
int string_validate(char name[]);
void print_popular(int i,int top);
void details_due(int i);
int search_return(char isbn []);
int search_borrow();
void print_borrowed();
void Getdate(int*dd,int *mm , int *yy);
int advance(int*day,int*month,int year);
int isLeapYear(int);
void print_md(int);
int read_borrows();
int found_ISBN(char d[]);
int valid_ISBN(char g[]);
int read_member();
int valid_num(char*);
void printmembers(int y);
int search_ISBN();
void Divide_the_date(char k[],int*v,int*r,int*u);
int valid_mail(char x[]);
void details_books(int i);
void details_borrow(int i);
void print_bd(int);
int read_book ();
int limit_br(int l);
void bookmanagement();
void membermanagement();
void borrowmanagement();
void administrativeactions();
void savebooks(int);
void exitprog();
void startup();
void insertbook(int );
void searchbook();
int searchmember();
void details_member(int i);
void addnewcopies();
void deletebook();
void edit();
void registermember();
void removemember();
void borrowbook(int);
void returnbook();
void overdue();
void popular();
void exitwithoutsaving();
typedef struct {
int building;
char street[50];
char city[50];
}address;
typedef struct {
char first_name[50];
char last_name[50];
}name;
typedef struct {
int year;
int month;
int day;
}date;
typedef struct {
char title[50];
char author[50];
char publisher[50];
char ISBN[30];
int available ;
char category[50];
int copies;
date arrive;
}book;
book b[100];
book b_temp[100];

typedef struct {
char e_mail[50];
int age;
int id;
char phone[15];
name memb;
address mem;
}member;
member m[100];
member m_temp[100];
typedef struct {
 char bookborowed[50];
 char ISBN[30];
 int id;
 date borrowed;
 date due ;
 date returned;
}borrow;
borrow br[100];
