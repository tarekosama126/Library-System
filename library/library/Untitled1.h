#include <stdio.h>
#include <stdlib.h>
void bookmanagement();
void membermanagement();
void borrowmanagement();
void administrativeactions();
void savechanges();
void exitprog();
void startup();
void insertbook();
void searchbook();
void addnewcopies();
void deletebook();
void edit();
void registermember();
void removemember();
void borrowbook();
void returnbook();
void overdue();
void popular();
void saveandexit();
void exitwithoutsaving();
typedef struct {
char building[50];
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
char ISBN[13];
int available ;
char category[50];
int copies;
date arrive;
}book;
book b[100];

typedef struct {
char e_mail[50];
int age;
int id;
int phone;
name memb;
address mem;
}member;
member m[100];
typedef struct {
 char bookborowed[50];
 char ISBN[13];
 int id;
 date borrowed;
 date due ;
 date returned;
}relation;

