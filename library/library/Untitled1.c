#include <stdio.h>
#include <stdlib.h>
#include"Untitled1.h"
#include<windows.h>
void insertbook(){
    static int x=0 ;
    FILE *books=fopen("C:\\Users\\Tarek Osama\\Downloads\\library\\library\\books.TXT","a");
printf("Enter the title of the book \n");
getchar();
gets(b[x].title);
fputs(b[x].title,books);
fprintf(books,",");
printf("Enter the ISBN of the book \n");
gets(b[x].ISBN);
fputs(b[x].ISBN,books);
fprintf(books,",");
printf("Enter the number of copies of the book \n");
scanf("%d",&(b[x].copies));
fprintf(books,"%d",b[x].copies);
fprintf(books,",");
printf("Enter the date in this format day,month,year \n");
scanf("%d%d%d",&(b[x].arrive.day),&(b[x].arrive.month),&(b[x].arrive.year));
fprintf(books,"%d",b[x].arrive.day);
fprintf(books,"/");
fprintf(books,"%d",b[x].arrive.month);
fprintf(books,"/");
fprintf(books,"%d",b[x].arrive.year);
fprintf(books,",");
getchar();
printf("Enter the author of the book \n");
gets(b[x].author);
fputs(b[x].author,books);
fprintf(books,",");
printf("Enter the publisher of the book \n");
gets(b[x].publisher);
fputs(b[x].publisher,books);
fprintf(books,",");
printf("Enter the category of the book \n");
gets(b[x].category);
fputs(b[x].category,books);
fprintf(books,",");
    char g;
printf("Enter number of available books \n");
scanf("%d",&(b[x].available));
fprintf(books,"%d",b[x].available);
fprintf(books,"\n");
fclose(books);
    printf("Enter '1' for insert another book     '2' for back       '3' for end\n");
getchar();
scanf("%c",&g);
switch(g){
case'1':
    insertbook();
case'2':
    bookmanagement();
case'3':
    exitprog();
default:
    printf("enter a valid choice \n");
    insertbook();
}}
void searchbook(){
    static int x=0;
char d[50];
FILE *books=fopen("C:\\Users\\Tarek Osama\\Downloads\\library\\library\\books.TXT","r+");
rewind(books);
printf("enter book ISBN\n");
getchar();
gets(d);
while(fread(&b,sizeof(b),1,books)==1)
        {
        if(strcmp(b[x].ISBN,d)==0)
        {

            printf("The Book is available");
            printf("ID:%s",b[x].ISBN);
            printf(" Name:%s",b[x].title);
            printf("Author:%s ",b[x].author);
}}}
void addnewcopies(){}
void deletebook(){}
void edit(){}
void registermember(){static int x =0;
printf("%d",x);
    FILE *members=fopen("C:\\Users\\Tarek Osama\\Downloads\\library\\library\\members.TXT","a");
printf("Enter your First and Last name \n");
getchar();
gets(m[x].memb.first_name);
system("clr");
fputs(m[x].memb.first_name,members);
fprintf(members,",");
gets(m[x].memb.last_name);
fputs(m[x].memb.last_name,members);
fprintf(members,",");
printf("Enter your ID \n");
scanf("%d",&(m[x].id));
fprintf(members,"%d",m[x].id);
fprintf(members,",");
printf("Enter your e_mail \n");
getchar();
gets(m[x].e_mail);
fputs(m[x].e_mail,members);
fprintf(members,",");
printf("Enter your address in this format street,building then city \n");
gets(m[x].mem.street);
fputs(m[x].mem.street,members);
fprintf(members,",");
gets(m[x].mem.building);
fputs(m[x].mem.building,members);
fprintf(members,",");
gets(m[x].mem.city);
fputs(m[x].mem.city,members);
fprintf(members,",");
printf("Enter your age \n");
scanf("%d",&(m[x].age));
fprintf(members,"%d",m[x].age);
fprintf(members,",");
printf("Enter your phone number \n");
scanf("%d",&(m[x].phone));
fprintf(members,"0");
fprintf(members,"%d",m[x].phone);
fprintf(members,"\n");
char g;
fclose(members);
x++;
    printf("Enter '1' for insert another member     '2' for back       '3' for end\n");
getchar();
scanf("%c",&g);
switch(g){
case'1':
    registermember();
case'2':
    membermanagement();
case'3':
    exitprog();
default:
    printf("enter a valid choice \n");
    registermember();

}}
void removemember(){}
void borrowbook(){}
void returnbook(){}
void overdue(){}
void popular(){}
void saveandexit(){exit(0);}
void exitwithoutsaving(){}
void bookmanagement(){
char selection ;
printf("Enter 'a' for insert\n 'b' for search\n 'c' for add new copies\n 'd' for delete\n 'e' for edit\n 'f'for back\n");
getchar();
scanf( "%c",&selection);
switch(selection){
case 'a':
    insertbook();
    break;
case 'b':
    searchbook();
    break;
case 'c':
    addnewcopies();
    break;
case 'd':
    deletebook();
    break;
case 'e':
    edit();
    break;
case 'f':
    getchar();
    startup();
    break;
default:
    printf("enter a valid choice \n");
    bookmanagement();
    break;
}
}
void membermanagement(){
    char selection ;
    printf("Enter 'a'for register\n 'b'for remove\n 'c'for back\n");
getchar();
scanf( "%c",&selection);
switch(selection){
case 'a':
    registermember();
    break;
case'b':
    removemember();
    break;
case 'c':
     getchar();
    startup();
    break;
    default:
    printf("enter a valid choice \n");
    membermanagement();
    break;
}
}
void borrowmanagement(){
    char selection ;
    printf("Enter 'a'for borrow\n 'b'for return\n 'c'for back\n");
getchar();
scanf( "%c",&selection);
switch(selection){
case 'a':
    borrowbook();
    break;
case 'b':
    returnbook();
    break;
    case 'c':
     getchar();
    startup();
    break;
    default:
    printf("enter a valid choice \n");
    borrowmanagement();
    break;
}
}
void administrativeactions(){
char selection ;
    printf("Enter 'a'for overdue\n 'b'for popular books\n 'c'for back\n");
getchar();
scanf( "%c",&selection);
switch(selection){
case 'a':
    overdue();
    break;
case'b':
    popular();
    break;
    case 'c':
     getchar();
    startup();
    break;
    default:
    printf("enter a valid choice \n");
    administrativeactions();
    break;
}
}
void savechanges(){}
void exitprog(){
char selection ;
    printf("Enter 'a'for save&exit\n 'b'for exit without saving\n 'c'for back\n");
getchar();
scanf( "%c",&selection);
switch(selection){
case 'a':
    saveandexit();
    break;
case'b':
    exitwithoutsaving();
    break;
    case 'c':
     getchar();
    startup();
    break;
    default:
    printf("enter a valid choice \n");
    exitprog();
    break;
}
}
void startup(){
    char selection ;
    printf("Enter '1' for book management\n '2' for member management \n'3' for borrow management \n'4' for administrative actions \n'5' for save changes \n'6' for exit\n");
scanf( "%c",&selection);
switch(selection){
case '1':
bookmanagement();
break;
case '2':
membermanagement();
break;
case '3':
    borrowmanagement();
    break;
case '4':
    administrativeactions();
    break;
    case '5':
        savechanges();
        break;
        case '6':
            exitprog();
            break;
        default:
            printf("enter a valid choice \n");
            startup();
            break;
}
}

