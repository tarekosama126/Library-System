#include<time.h>    /* To get the current Date */
#include <stdio.h> /*  File functions   */
#include <stdlib.h>  /* Used function system("cls") */
#include"Untitled1.h" /* All declaration of functions and global variables in the program   */
#include <ctype.h> /*  Used for testing type  of input ,   2 functions : isAlpha()   isdigit() */
#include<windows.h> /*  Used Function Sleep()   */

/*To make sure the input is a string  */
int string_validate(char name[])
{
    int i,h,flag=0;
    for(i=0; i<strlen(name); i++)
    {
        if(name[i]==' ')
            continue;
        h=isalpha(name[i]);
        if(h==2||h==1)
        {
            flag=1;
            continue;
        }
        else
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
        return 1;
    else
    {
        printf("Enter a valid name please...\n");
        Sleep(3000);
        system("cls");
        return 0;
    }
}
/*To change type of the date (char) to integer*/
void Divide_the_date(char k[],int*v,int*r,int*u)
{
    int h,o=0,j,p=0;
    char a[20];
    memset(a,0,20);
    h=strlen(k);
    for(j=0; j<=h; j++)
    {
        if(k[j]=='\0')
        {
            *u=atoi(a);
            memset(a,0,20);
            break;
        }
        else if (k[j]=='/')
        {
            o++;
            switch(o)
            {
            case 1:
                *v=atoi(a);
                memset(a,0,20);
                p=0;
                break;
            case 2:
                *r=atoi(a);
                memset(a,0,20);
                p=0;
                break;
            default:
                break;
            }
        }
        else
        {
            a[p]=k[j];
            p++;
        }
    }
}
/* To Enter The required data for adding each book */
void insertbook(int x)
{
    int r,g,q;
    int c2=-1;
    char h[30]= {'\0'};
    if(books==NULL)
    {
        x=0;
    }
    system("cls");
    do
    {
        printf("Enter the title of the book \n");
        gets(b[x].title);
        system("cls");
    }
    while(string_validate(b[x].title)!=1);
    do
    {
        system("cls");
        if((found_ISBN(b[x].ISBN)==0))
        {
            printf("This book already exists..\n");
        }
        printf("Enter the ISBN of the book \n");
        gets(b[x].ISBN);
        if(b[x].ISBN=='\n')
        {
            continue;
        }
    }
    while((found_ISBN(b[x].ISBN)==1&&valid_ISBN(b[x].ISBN)==0)||(found_ISBN(b[x].ISBN)==0&&valid_ISBN(b[x].ISBN)==1));

    system("cls");
    do
    {
        printf("Enter the number of copies of the book \n");
        scanf("%s",h);
        c2=-1;
        b[x].copies=valid_int(h,&c2);
        if(c2>=0)
        {
            system("cls");
            printf("Enter a valid integer...\n");
            Sleep(1500);
            system("cls");
            continue;
        }

        system("cls");
    }
    while(!valid_int(h,&c2)&&(b[x].copies<=0) );
    do
    {
        printf("Enter the author of the book: \n");
        getchar();
        gets(b[x].author);
        system("cls");
    }
    while(string_validate(b[x].author)!=1);
    system("cls");
    do
    {
        printf("Enter the publisher of the book: \n");
        gets(b[x].publisher);
        system("cls");
    }
    while(string_validate(b[x].publisher)!=1);
    system("cls");
    do
    {
        printf("Enter the category of the book: \n");
        gets(b[x].category);
        system("cls");
    }
    while(string_validate(b[x].category)!=1);
    system("cls");

    b[x].available=b[x].copies;

    do
    {
        system("cls");

    }
    while(!validate_date(&r,&g,&q));
     b[x].arrive.day=r;
    b[x].arrive.month=g;
    b[x].arrive.year=q;

    system("cls");
    int flag=0;
    do
    {
        printf("1)Insert another book without saving\n2)back\n3)End\n4)save changes \n");
        switch(getch())
        {


        case'1':
            fflush(stdin);
            insertbook(x);
            flag=0;
        case'2':
             fflush(stdin);
            bookmanagement();
            flag=0;
        case'3':
            exitprog();
            flag=0;
            break;
        case'4':
            x++;
            savebooks(x);
            system("cls");
             fflush(stdin);
            startup();
            flag=0;
            break;
        default:
            system("cls");
            printf("Enter a valid choice \n");
            Sleep(1500);
            system("cls");
            flag=1;
        }
    }
    while(flag=1);

}
/* To search for a required book with various ways */
void searchbook()
{
    system("cls");
    int i,u,flag=0;
    rewind(books);
    do
    {
        printf("Search by:\n1)Author name\n2)ISBN\n3)Category\n4)Title\n5)back \n");
        switch(getch())
        {
        case'1':
        {
            flag=0;
            system("cls");
            char d[50];
            memset(d,'\0',50);
            do
            {
                printf("Please enter the Author name :\n");
                gets(d);
                system("cls");
            }
            while(string_validate(d)!=1);

            system("cls");
            int count=0;
            for(i=0; i<x; i++)
            {
                if((strcmp(d,b[i].author)==0))
                {
                    printf("the book number %d\n",count+1);
                    details_books(i);
                    count++;
                }
            }
            if(count==0)
            {
                printf("No such a author name found....");
                Sleep(1500);
                system("cls");
                 fflush(stdin);
                searchbook();
            }
            Sleep(10000);
            system("cls");
             fflush(stdin);
            startup();
            break;
        }
        case'2':

        {
            flag=0;
            system("cls");
            char d[50];
            memset(d,'\0',50);
            do
            {
                printf("Please enter the ISBN :\n");
                gets(d);
                system("cls");
            }
            while(!valid_ISBN(d));
            int count=0;
            for(i=0; i<x; i++)
            {
                if((strcmp(d,b[i].ISBN)==0))
                {
                    printf("the book number %d\n",count+1);
                    details_books(i);
                    count++;
                }
            }
            if(count==0)
            {
                printf("No such an ISBN  found.....");
                Sleep(1500);
                system("cls");
                 fflush(stdin);
                searchbook();
            }
            Sleep(10000);
            system("cls");
             fflush(stdin);
            startup();
            break;
        }
        case'3':
        {
            flag=0;
            system("cls");
            char d[50];
            memset(d,'\0',50);
            do
            {
                printf("Please enter the Category :\n");
                gets(d);
                system("cls");
            }
            while(string_validate(d)!=1);
            system("cls");
            int count=0;
            for(i=0; i<x; i++)
            {
                if((strcmp(d,b[i].category)==0))
                {
                    printf("the book number %d\n",count+1);
                    details_books(i);
                    count++;
                }
            }
            if(count==0)
            {
                printf("No such category found....");
                Sleep(1500);
                system("cls");
                 fflush(stdin);
                searchbook();
            }
            Sleep(10000);
            system("cls");
             fflush(stdin);
            startup();
            break;
        }

        case'4':
        {
            flag=0;
            system("cls");
            char d[50];
            memset(d,'\0',50);
            do
            {
                printf("Please enter the title :\n");
                gets(d);
                system("cls");
            }
            while(string_validate(d)!=1);
            system("cls");
            int count=0;
            for(u=0;u<2;u++){
                    if(u==0){
                strupr (d);
            for(i=0; i<x; i++)
            {
                if(strstr(b[i].title,d) != NULL)
                {
                    printf("the book number %d\n",count+1);
                    details_books(i);
                    count++;
                }
            }}
              if(u==1){
                strlwr(d);
            for(i=0; i<x; i++)
            {
                if(strstr(b[i].title,d) != NULL)
                {
                    printf("the book number %d\n",count+1);
                    details_books(i);
                    count++;
                }
            }
            }}
            if(count==0)
            {
                printf("No such a title found...");
                Sleep(3000);
                system("cls");
                 fflush(stdin);
                searchbook();
            }
            Sleep(10000);
            system("cls");
             fflush(stdin);
            startup();
            break;
        }
        case '5':
            system("cls");
             fflush(stdin);
            bookmanagement();
        default:
            printf("Choose a valid way of search... \n");
            Sleep(1500);
             fflush(stdin);
            searchbook();
            break;
        }
    }
    while(flag==1);
}
/* to Search by the ISBN and return it's index  */
int search_ISBN()
{
    system("cls");
    int i,j;
    system("cls");
    char d[50];
    memset(d,'\0',50);
    do
    {
        printf("Please enter the ISBN :\n");
        gets(d);
        system("cls");
    }
    while(!valid_ISBN(d));
    int count=0;
    for(i=0; i<x; i++)
    {
        if((strcmp(d,b[i].ISBN)==0))
        {
            printf("the book number %d\n",count+1);
            details_books(i);
            count++;
            j=i;
            break;
        }
    }
    if(count==0)
    {
        printf("No such book found..\n");
        Sleep(1500);
        system("cls");
         fflush(stdin);
        search_ISBN();
    }
    Sleep(5000);
    system("cls");
    return j;
}
/*To add new copies by using the search_ISBN()  */
void addnewcopies()
{
    int i,c2=-1,w;
    char h[20] = {'\0'};
    i=search_ISBN();
    do
    {
        printf("enter the number of copies added:\n");
        scanf("%s",h);
        c2=-1;
        w=valid_int(h,&c2);
        if(c2>=0)
        {
            system("cls");
            printf("enter a valid integer\n");
            Sleep(1500);
            system("cls");
            continue;
        }

        system("cls");
    }
    while(!valid_int(h,&c2)&& w<=0);
    int flag=0;
    do
    {
        system("cls");
        printf("Choose:\n1)Save\n2)Back without saving");
        switch(getch())
        {
        case'1':
            system("cls");
            flag=0;
            (b[i].copies)=(b[i].copies)+w;
            savebooks(x);
            fflush(stdin);
            startup();
        case'2':
            flag=0;
            system("cls");
            fflush(stdin);
            startup();

        default:
            system("cls");
            printf("Enter a Valid integer ..\n");
            Sleep(1000);
            system("cls");
        }
    }
    while(flag=1);
}
/* to delete a book by using the search_ISBN() */
void deletebook()
{
    int j,i,f,flag=0;
    f=search_ISBN();
    /*stimulating the shifting method after the deleting process */
    for(i=0,j=0; j<x-1; i++,j++)
    {
        if(i==f)
            i++;
        strcpy(b_temp[j].title,b[i].title);
        strcpy(b_temp[j].author,b[i].author);
        strcpy(b_temp[j].publisher,b[i].publisher);
        strcpy(b_temp[j].ISBN,b[i].ISBN);
        strcpy(b_temp[j].category,b[i].category);
        b_temp[j].copies=b[i].copies;
        b_temp[j].available=b[i].available;
        b_temp[j].arrive.day=b[i].arrive.day;
        b_temp[j].arrive.month=b[i].arrive.month;
        b_temp[j].arrive.year=b[i].arrive.year;
    }

    system("cls");
    do
    {
        printf("Choose:\n1)Confirming the delete\n2)Back without saving\n ");
        switch(getch())
        {
        case '1':
            flag=0;
            x--;
            print_bd(x);
            system("cls");
            fflush(stdin);
            startup();
        case '2':
            flag=0;
            savebooks(x);
            system("cls");
            fflush(stdin);
            startup();
        default:
            flag=1;
            system("cls");
            printf("Enter a valid choice\n");
            Sleep(1000);
            system("cls");
        }
    }
    while(flag=1);
}
/* To Enter The required data for adding each member */
void registermember()
{
    char h[30]= {'\0'};
    int c2=-1,flag=0;
    if(members==NULL)
    {
        y=0;
    }
    system("cls");

    do
    {
        printf("Enter the first name of the member: \n");
        gets(m[y].memb.first_name);
        system("cls");
    }
    while(string_validate(m[y].memb.first_name)!=1);
    system("cls");
    do
    {
        printf("Enter the last name of the member \n");
        gets(m[y].memb.last_name);
        system("cls");
    }
    while(string_validate(m[y].memb.last_name)!=1);
    system("cls");
    do
    {
        printf("Enter the ID of the member: \n");
        scanf("%s",h);
        c2=-1;
        m[y].id=valid_int(h,&c2);
        if(c2>=0||m[y].id==0)
        {
            system("cls");
            printf("enter a valid integer\n");
            Sleep(1500);
            system("cls");
            continue;
        }
        system("cls");
    }
    while(valid_int(h,&c2) && !found_ID(m[y].id) || (!valid_int(h,&c2) && found_ID(m[y].id))||m[y].id==0);

    system("cls");
    do
    {
        printf("Enter the building number : \n");
        scanf("%s",h);
        c2=-1;
        m[y].mem.building=valid_int(h,&c2);
        if(c2>=0||m[y].mem.building==0)
        {
            system("cls");
            printf("enter a valid integer\n");
            Sleep(1500);
            system("cls");
            continue;
        }

        system("cls");
    }
    while(!valid_int(h,&c2)||m[y].mem.building==0);


    do
    {
        printf("Enter the street name:\n");
        getchar();
        gets(m[y].mem.street);
        system("cls");
    }
    while(string_validate(m[y].mem.street)!=1);

    do
    {
        printf("Enter the city name : \n");
        gets(m[y].mem.city);
        system("cls");
    }
    while(string_validate(m[y].mem.city)!=1);
    system("cls");
    do
    {
        printf("Enter the member's phone number: \n");
        scanf("%s",m[y].phone);
        system("cls");
    }
    while(!valid_num(m[y].phone));

    do
    {
        system("cls");
        printf("Enter the member age: \n");
        scanf("%s",h);
        c2=-1;
        m[y].age=valid_int(h,&c2);
        if(c2>=0||m[y].age==0)
        {
            system("cls");
            printf("enter a valid integer\n");
            Sleep(1500);
            system("cls");
            continue;
        }
        if(m[y].age>90||m[y].age==0)
        {
            system("cls");
            printf("Enter a valid age ....\n");
            Sleep(1500);
            system("cls");
        }
    }
    while((!valid_int(h,&c2)||m[y].age>90) || (valid_int(h,&c2)&&m[y].age>90)||m[y].age==0);


    do
    {
        system("cls");
        printf("Enter the member email: \n");
        scanf("%s",m[y].e_mail);
        system("cls");
    }
    while(!valid_mail(m[y].e_mail));
    do
    {
        printf("1)Insert another member without saving\n2)Back\n3)End\n4)save changes \n");
        switch(getch())
        {
        case'1':
            flag=0;
            system("cls");
            fflush(stdin);
            registermember(y);
        case'2':
            flag=0;
            system("cls");
            fflush(stdin);
            membermanagement();
        case'3':
            flag=0;
            system("cls");
            exitprog();
        case'4':
            flag=0;
            y++;
            printmembers(y);
            system("cls");
            fflush(stdin);
            startup();
        default:
            flag=1;
            printf("Enter a valid choice \n");
            Sleep(2000);
        }
    }
    while(flag=1);

}
/* to delete a member by using the searchmember() */
void removemember()
{
    int j,i,f,flag=0;
    f=searchmember();
    for(i=0,j=0; j<y-1; i++,j++)
    {
        if(i==f)
            i++;
        strcpy(m_temp[j].e_mail,m[i].e_mail);
        strcpy(m_temp[j].phone,m[i].phone);
        strcpy(m_temp[j].memb.first_name,m[i].memb.first_name);
        strcpy(m_temp[j].memb.last_name,m[i].memb.last_name);
        strcpy(m_temp[j].mem.city,m[i].mem.city);
        strcpy(m_temp[j].mem.street,m[i].mem.street);
        m_temp[j].age=m[i].age;
        m_temp[j].id=m[i].id;
        m_temp[j].mem.building=m[i].mem.building;
    }
    do
    {
        printf("1)Confirming the delete\n2)back to menu without saving\n ");
        switch(getch())
        {
        case '1':
            flag=0;
            y--;
            print_md(y);
            system("cls");
            fflush(stdin);
            startup();
        case '2':
            flag=0;
            printmembers(y);
            system("cls");
            fflush(stdin);
            startup();
        default:
            flag=1;
            system("cls");
            printf("Enter a valid choice\n");
            Sleep(1000);
            system("cls");
        }
    }
    while(flag=1);
}
/*A function that takes both ISBN & ID and calculates the borrowed and the Due date (by using getdate() , advance() )*/
void borrowbook(int j)
{
    int f,i,h,k=0;
    int day,month,year;

    do
    {
        k=0;
        i=search_ISBN();
        if(b[i].available==0)
        {
            printf("There is no available copies for this book\n");
            Sleep(1500);
            k++;
        }
    }
    while(k);
    (b[i].available)-=1;
    do
    {
        f=searchmember();
        (br[j].id)=(m[f].id);
        h=limit_br(br[j].id);
        if(h==0)
        {
            printf("You've reached the maximum amount of borrowed books \n");
            Sleep(3000);
            continue;
        }
        else
        {
            break;
        }
    }
    while(!h);
    strcpy(br[j].ISBN,b[i].ISBN);
    Getdate(&day,&month,&year);
    br[j].borrowed.day=day;
    br[j].borrowed.month=month;
    br[j].borrowed.year=year;
    br[j].due.year=advance(&day,&month,year);
    br[j].due.day=day;
    br[j].due.month=month;
    system("cls");
    z++;
    print_borrowed();
    savebooks(x);
    startup();
}
/*A function that gets ID, ISBN ;(If index is found) it will return the borrowed book   */
void returnbook()
{
    char isbn[20];
    int p,j,day,month,year;
    do{
    printf("Enter the ISBN of the book\n");
    gets(isbn);}
    while(!valid_ISBN(isbn));
    p=search_return(isbn);
    if(p==1000){
            fflush(stdin);
        returnbook();}
    Getdate(&day,&month,&year);
    b[p].available+=1;
    do{
    fflush(stdin);
    j=search_borrow(isbn);
    if(j!=1000){
        break;
    }
    }while(1);
    br[j].returned.day=day;
    br[j].returned.month=month;
    br[j].returned.year=year;
    savebooks(x);
    print_borrowed();
    Sleep(1500);
    fflush(stdin);
    system("cls");
    startup();
}
/*A function that calculates and prints the late borrowed books which should be returned*/
void overdue()
{
    int i,day,month,year;
    Getdate(&day,&month,&year);
    system("cls");
    printf("The overdues are:\n\n");
    for(i=0; i<z; i++)
    {
        if((br[i].returned.day!=0))
        {
            if (br[i].due.year < br[i].returned.year || br[i].due.year == br[i].returned.year && br[i].due.month < br[i].returned.month || br[i].due.year == br[i].returned.year && br[i].due.month == br[i].returned.month && br[i].due.day < br[i].returned.day)
                details_due(i);
        }
        else if(br[i].returned.day==0)
        {

            if (br[i].due.year < year || br[i].due.year == year && br[i].due.month < month || br[i].due.year == year && br[i].due.month == month && br[i].due.day < day)
                details_due(i);

        }
    }
    Sleep(3000);
    int flag=0;
    do
    {
        printf("\n\n\nChoose:\na)Return to menu\nb)Exit\n");
        switch(getch())
        {
        case 'a':
            flag=0;
            system("cls");
            fflush(stdin);
            startup();

        case 'b':
            flag=0;
            system("cls");
            exit(1);
        default:
            flag=1;
            system("cls");
            printf("Enter a valid choice ....\n");
            Sleep(3000);
        }
    }
    while(flag=1);




}
/*A function that calculates  and prints  the most borrowed 5 books*/
void popular()
{
    system("cls");
    printf("ISBN\t\tTop\n");
    int i,j,counters[x],top1=0,top2=0,top3=0,top4=0,top5=0,i1=1000,i2=1000,i3=1000,i4=1000,i5=1000;
    memset(counters,0,x*sizeof(int));
    for(i=0; i<x; i++)
    {
        for(j=0; j<z; j++)
        {
            if(strcmp(b[i].ISBN,br[j].ISBN)==0)
            {
                counters[i]++;
            }
        }
    }

    for(i=0; i<x; i++)
    {
        if(counters[i]>top1)
        {
            top1=counters[i];
            i1=i;
        }
    }
    if(i1!=1000)
        print_popular(i1,top1);

    for(i=0; i<x; i++)
    {
        if(counters[i]==top1 && counters[i]!=0){
            if(top2==0){
                top2=top1;}
                if(i==i1){
                    continue;
                }else if(i2!=1000){break;}else{
                i2=i;
                }
            }
            continue;}
        if(counters[i]>top2)
        {
            top2=counters[i];
            i2=i;
        }

    if(i2!=1000)
        print_popular(i2,top2);
    for(i=0; i<x; i++)
    {
        if(counters[i]==top1 && counters[i]!=0 ||counters[i]==top2 && counters[i]!=0)
        {
            if(top3==0){
                top3=top2;}
                if(i==i2||i==i1){
                    continue;
                }else if(i3!=1000){break;}else{
                i3=i;
                }
            }
            continue;}
        if(counters[i]>top3)
        {
            top3=counters[i];
            i3=i;
        }
    if(i3!=1000)
        print_popular(i3,top3);
    for(i=0; i<x; i++)
    {
        if(counters[i]==top1 && counters[i]!=0 ||counters[i]==top2 && counters[i]!=0 || counters[i]==top3 &&counters[i]!=0)
        {
           if(top4==0){
                top4=top3;}
                if(i==i2||i==i1||i==i3){
                    continue;
                }else if(i4!=1000){break;}else{
                i4=i;
                }
            }
            continue;}

        if(counters[i]>top4)
        {
            top4=counters[i];
            i4=i;
        }
    if(i4!=1000)
        print_popular(i4,top4);
    for(i=0; i<x; i++)
    {
        if(counters[i]==top1 && counters[i]!=0 ||counters[i]==top2 && counters[i]!=0 || counters[i]==top3 &&counters[i]!=0 ||counters[i]==top4 && counters[i]!=0)
        {if(top5==0){
                top5=top4;}
                if(i==i2||i==i1||i==i3||i==i4){
                    continue;
                }else if(i5!=1000){break;}else{
                i5=i;
                }
            }
            continue;

        if(counters[i]>top5)
        {
            top5=counters[i];
            i5=i;
        }
    }
    if(i5!=1000)
        print_popular(i5,top5);
    int flag=0;
    Sleep(3000);
    do
    {
        printf("\n\n\nChoose:\na)Return to main menu\nb)Exit\n");
        switch(getch())
        {
        case 'a':
            flag=0;
            system("cls");
            fflush(stdin);
            startup();

        case 'b':
            flag=0;
            system("cls");
            exit(1);
        default:
            flag=1;
            system("cls");
            printf("Enter a valid choice ....\n");
            Sleep(3000);
        }

    }
    while(flag=1);
}
/*A function that exits the program without saving */
void exitwithoutsaving()
{
    exit(1);
}
/*A function that displays and directs the book management menu*/
void bookmanagement()
{
    int flag=0;
    do
    {
        printf("Choose\na)Insert\nb)Search\nc)Add new copies\nd)Delete\ne)Back\n");
        switch(getch())
        {
        case 'a':
            flag=0;
            insertbook(x);
        case 'b':
            searchbook();
            flag=0;
        case 'c':
            addnewcopies();
            flag=0;
        case 'd':
            deletebook();
            flag=0;
        case 'e':
            system("cls");
            fflush(stdin);
            startup();
            flag=0;
        default:
            system("cls");
            printf("enter a valid choice \n");
            Sleep(1000);
            system("cls");
            flag=1;
        }
    }
    while(flag=1);
}
/*A function that displays and directs the member management menu*/
void membermanagement()
{
    int flag=0;
    do
    {
        printf("Choose\na)register\nb)remove\nc)back\n");
        switch(getch())
        {
        case 'a':
            flag=0;
            registermember();
        case'b':
            flag=0;
            removemember();
        case 'c':
            system("cls");
            fflush(stdin);
            startup();
            flag=0;
        default:
            system("cls");
            printf("enter a valid choice \n");
            Sleep(1000);
            system("cls");

            flag=1;
        }
    }
    while(flag=1);
}
/*A function that displays and directs the borrow management menu*/
void borrowmanagement()
{
    int flag=0;
    do
    {
        printf("Choose:\na)borrow\nb)return\nc)back\n");
        switch(getch())
        {
        case 'a':
            borrowbook(z);
            flag=0;
        case 'b':
            returnbook();
            flag=0;
        case 'c':
            system("cls");
            fflush(stdin);
            startup();
            flag=0;
        default:
            system("cls");
            printf("enter a valid choice \n");
            Sleep(1000);
            system("cls");
            flag=1;
        }
    }
    while(flag=1);
}
/*A function that displays and directs the adminstrative management menu*/
void administrativeactions()
{
    int flag=0;
    do
    {
        printf("Choose:\na)Overdue\nb)Popular books\nc)Back\n");
        switch(getch())
        {
        case 'a':
            flag=0;
            overdue();

        case'b':
            flag=0;
            popular();

        case 'c':
            system("cls");
            fflush(stdin);
            startup();
            flag=0;
        default:
            system("cls");
            printf("enter a valid choice \n");
            Sleep(1000);
            system("cls");
            flag=1;

        }
    }
    while(flag=1);
}
/*A function that writes in books.txt  */
void savebooks(int x)
{
    int i;
    books=fopen("books.TXT","w");
    for(i=0; i<x; i++)
    {
        fprintf(books,b[i].title);
        fprintf(books,",");
        fprintf(books,b[i].ISBN);
        fprintf(books,",");
        fprintf(books,"%d",b[i].copies);
        fprintf(books,",");
        fprintf(books,b[i].author);
        fprintf(books,",");
        fprintf(books,b[i].publisher);
        fprintf(books,",");
        fprintf(books,b[i].category);
        fprintf(books,",");
        fprintf(books,"%d",b[i].available);
        fprintf(books,",");
        fprintf(books,"%d",b[i].arrive.day);
        fprintf(books,"/");
        fprintf(books,"%d",b[i].arrive.month);
        fprintf(books,"/");
        fprintf(books,"%d",b[i].arrive.year);
        fprintf(books,"\n");
    }
    fclose(books);
}
/*A function that closes the program */
void exitprog()
{

    printf("Choose:\na)Exit\nb)Back\n");
    switch(getch())
    {
    case 'a':
        exitwithoutsaving();
        break;
    case 'b':
        system("cls");
        fflush(stdin);
        startup();
        break;
    default:
        Sleep(1000);
        printf("enter a valid choice \n");
        system("cls");
        exitprog();
        break;
    }
}
/*A function that shows the main menu*/
void startup()
{
    x=read_book();
    y=read_member();
    z=read_borrows();

    printf("Choose:\n1)Book management\n2)Member management\n3)Borrow management \n4)Administrative actions \n5)print files \n6)save changes\n7)exit");

    printf("\n\n\n\n\n\n\n\nNumber of saved books: %d\n",x);
    printf("Number of saved members: %d\n",y);
    printf("Number of borrowed books: %d\n",z);
    switch(getch())
    {
    case '1':
        system("cls");
        bookmanagement();
        break;
    case '2':
        system("cls");
        membermanagement();
        break;
    case '3':
        system("cls");
        borrowmanagement();
        break;
    case '4':
        system("cls");
        administrativeactions();
        break;
    case'5':
        print_files();
        break;
    case '6':
        system("cls");
        savebooks(x);
        printmembers(y);
        print_borrowed();
        printf("Saved successfully ... \n");
        Sleep(1500);
        system("cls");
        fflush(stdin);
        startup();
        break;
    case '7':
        system("cls");
        exitprog();
        break;
    default:
        system("cls");
        printf("enter a valid choice \n");
        Sleep(1000);
        system("cls");
        fflush(stdin);
        startup();
        break;
    }
}
/*A function that reads from books.txt  */
int read_book ()
{
    books=fopen("books.txt","r");
    rewind(books);
    int count=0,x=0,i=0,n,v,r,u;
    char k[50];
    memset(k,0,50);
    char c;
    while(1)
    {
        c = fgetc(books);
        if( feof(books) )
        {
            break ;
        }
        if(c=='\n')
        {
            Divide_the_date(k,&v,&r,&u);
            b[x].arrive.day=v;
            b[x].arrive.month=r;
            b[x].arrive.year=u;
            memset(k,0,50);
            i=0;
            x++;
            count=0;
        }
        else if(c==',')
        {
            count++;
            switch(count)
            {

            case 1:
                strcpy(b[x].title,k);
                memset(k,0,50);
                i=0;
                break;
            case 2:
                strcpy(b[x].ISBN,k);
                memset(k,0,50);
                i=0;
                break;
            case 3:
                n=atoi(k);
                b[x].copies=n;
                memset(k,0,50);
                i=0;
                break;
            case 4:
                strcpy(b[x].author,k);
                memset(k,0,50);
                i=0;
                break;
            case 5:
                strcpy(b[x].publisher,k);
                memset(k,0,50);
                i=0;
                break;
            case 6:
                strcpy(b[x].category,k);
                memset(k,0,50);
                i=0;
                break;
            case 7:
                n=atoi(k);
                b[x].available=n;
                memset(k,0,50);
                i=0;
                break;
            default:
                break;
            }
        }
        else
        {
            k[i]=c;
            i++;
        }
    }

    return x;
}
/* A function that checks the validation of the entered e-mail*/
int valid_mail(char x[])
{
    int count=0;
    int countp=0;
    int i,j;
    int t,t2;
    int k=0;
    if(!isalpha(x[0]))
    {
        system("cls");
        printf("\nInvalid e-mail\n");
        Sleep(1000);
        system("cls");
        return 0;
    }
    for(i=0 ; i<strlen(x) ; i++)
    {
        if(x[i]=='@')
        {
            count++;
            t=i;
        }
    }
    if(count==1)
    {
        for(j=0; j<t ; j++)
        {
            if(!(x[j]=='_' || x[j]=='.' || isalpha(x[j]) || isdigit(x[j])))
            {
                system("cls");
                printf("\nInvalid e-mail\n");
                Sleep(1000);
                system("cls");
                return 0;
            }
        }
        if(k==0)
        {
            for(i=t; i<strlen(x) ; i++)
            {
                if(x[i]=='.')
                {
                    t2=i;
                    countp++;
                }
            }
            if(countp==1)
            {
                for(i=t+1; i<t2; i++)
                {
                    if(!(isalpha(x[i])))
                    {
                        system("cls");
                        printf("\nInvalid e-mail\n");
                        Sleep(1000);
                        system("cls");
                        return 0;
                    }
                    else
                    {
                        k=1;
                    }
                }
                if(k==1)
                {
                    if(x[t2+4]!='\0')
                    {
                        system("cls");
                        printf("\nInvalid e-mail\n");
                        Sleep(1000);
                        system("cls");
                        return 0;
                    }
                }
            }
            else
            {
                system("cls");
                printf("\nInvalid e-mail\n");
                Sleep(1000);
                system("cls");
                return 0;
            }
        }
    }
    else
    {
        system("cls");
        printf("\nInvalid e-mail\n");
        Sleep(1000);
        system("cls");
        return 0;
    }
    return 1;
}
/*A function used to print each book's details*/
void details_books(int i)
{
    printf("title:%s\nISBN:%s\nNumber of copies:%d\nAuthor:%s\nPublisher:%s\ncategory:%s\navailable:%d\nDate:%d/%d/%d\n\n\n ",b[i].title,b[i].ISBN,b[i].copies,b[i].author,b[i].publisher,b[i].category,b[i].available,b[i].arrive.day,b[i].arrive.month,b[i].arrive.year);
}
/* A function that searches for a member through the ID */
int searchmember()
{
    system("cls");
    int i,j,c2=0;
    char h[30]= {'\0'};
    rewind(members);
    system("cls");
    do
    {
        printf("Please enter the ID :\n");
        scanf("%s",h);
        c2=0;
        j=valid_int(h,&c2);
        if(c2>=0||j==0)
        {
            system("cls");
            printf("enter a valid integer\n");
            Sleep(1500);
            system("cls");
            continue;
        }

        system("cls");
    }
    while(!valid_int(h,&c2)||j==0);

    int count=0;
    for(i=0; i<y; i++)
    {
        if(j==m[i].id)
        {
            return i;
            break;
        }
    }
    if(count==0)
    {
        printf("No such a member found");
        Sleep(1500);
        system("cls");
        fflush(stdin);
        searchmember();
    }
}
/* A function that reads from members.txt  */
int read_member()
{
    members=fopen("members.txt","r");
    rewind(members);
    int count=0,y=0,i=0,n;
    char k[50];
    memset(k,0,50);
    char c;
    while(1)
    {
        c = fgetc(members);
        if( feof(members) )
        {
            break ;
        }
        if(c=='\n')
        {
            strcpy(m[y].e_mail,k);
            memset(k,0,50);
            i=0;
            y++;
            count=0;
        }
        else if(c==',')
        {
            count++;
            switch(count)
            {
            case 1:
                strcpy(m[y].memb.last_name,k);
                memset(k,0,50);
                i=0;
                break;
            case 2:
                strcpy(m[y].memb.first_name,k);
                memset(k,0,50);
                i=0;
                break;
            case 3:
                n=atoi(k);
                m[y].id=n;
                memset(k,0,50);
                i=0;
                break;
            case 4:
                n=atoi(k);
                m[y].mem.building=n;
                memset(k,0,50);
                i=0;
                break;
            case 5:
                strcpy(m[y].mem.street,k);
                memset(k,0,50);
                i=0;
                break;
            case 6:
                strcpy(m[y].mem.city,k);
                memset(k,0,50);
                i=0;
                break;
            case 7:
                strcpy(m[y].phone,k);
                memset(k,0,50);
                i=0;
                break;
            case 8:
                n=atoi(k);
                m[y].age=n;
                memset(k,0,50);
                i=0;
                break;
            default:
                break;
            }
        }
        else
        {
            k[i]=c;
            i++;
        }
    }
    fclose(members);
    return y;
}
/*A function that prints in a books.txt after deleting process*/
void print_bd(int x)
{
    int i;
    books=fopen("books.TXT","w");
    for(i=0; i<x; i++)
    {
        fprintf(books,b_temp[i].title);
        fprintf(books,",");
        fprintf(books,b_temp[i].ISBN);
        fprintf(books,",");
        fprintf(books,"%d",b_temp[i].copies);
        fprintf(books,",");
        fprintf(books,b_temp[i].author);
        fprintf(books,",");
        fprintf(books,b_temp[i].publisher);
        fprintf(books,",");
        fprintf(books,b_temp[i].category);
        fprintf(books,",");
        fprintf(books,"%d",b_temp[i].available);
        fprintf(books,",");
        fprintf(books,"%d",b_temp[i].arrive.day);
        fprintf(books,"/");
        fprintf(books,"%d",b_temp[i].arrive.month);
        fprintf(books,"/");
        fprintf(books,"%d",b_temp[i].arrive.year);
        fprintf(books,"\n");
    }
    fclose(books);
}
/*A function that prints in a members.txt after deleting process*/
void print_md(int y)
{
    int i;
    members=fopen("members.TXT","w");
    for(i=0; i<y; i++)
    {
        fprintf(members,m_temp[i].memb.last_name);
        fprintf(members,",");
        fprintf(members,m_temp[i].memb.first_name);
        fprintf(members,",");
        fprintf(members,"%d",m_temp[i].id);
        fprintf(members,",");
        fprintf(members,"%d",m_temp[i].mem.building);
        fprintf(members,",");
        fprintf(members,m_temp[i].mem.street);
        fprintf(members,",");
        fprintf(members,m_temp[i].mem.city);
        fprintf(members,",");
        fprintf(members,m_temp[i].phone);
        fprintf(members,",");
        fprintf(members,"%d",m_temp[i].age);
        fprintf(members,",");
        fprintf(members,m_temp[i].e_mail);
        fprintf(members,"\n");
    }
    fclose(members);
}
/*A function that writes in members.txt  */
void printmembers(int y)
{
    int i;
    members=fopen("members.TXT","w");
    for(i=0; i<y; i++)
    {
        fprintf(members,m[i].memb.last_name);
        fprintf(members,",");
        fprintf(members,m[i].memb.first_name);
        fprintf(members,",");
        fprintf(members,"%d",m[i].id);
        fprintf(members,",");
        fprintf(members,"%d",m[i].mem.building);
        fprintf(members,",");
        fprintf(members,m[i].mem.street);
        fprintf(members,",");
        fprintf(members,m[i].mem.city);
        fprintf(members,",");
        fprintf(members,m[i].phone);
        fprintf(members,",");
        fprintf(members,"%d",m[i].age);
        fprintf(members,",");
        fprintf(members,m[i].e_mail);
        fprintf(members,"\n");
    }
    fclose(members);
}
/*A function that prints the member's details*/
void details_member(int i)
{
    printf("First name:%s \nLast name: %s \nID:%d \nBuilding no.:%d \nStreet:%s \nCity:%s \nPhone number:%s \nAge:%d \nE-mail: %s \n\n\n\n ",m[i].memb.first_name,m[i].memb.last_name,m[i].id,m[i].mem.building,m[i].mem.street,m[i].mem.city,m[i].phone,m[i].age,m[i].e_mail);
}
/*A function that writes in borrows.txt  */
void print_borrowed()
{
    int i;
    borrows=fopen("borrows.TXT","w");
    for(i=0; i<z; i++)
    {
        fprintf(borrows,br[i].ISBN);
        fprintf(borrows,",");
        fprintf(borrows,"%d",br[i].id);
        fprintf(borrows,",");
        fprintf(borrows,"%d",br[i].borrowed.day);
        fprintf(borrows,"/");
        fprintf(borrows,"%d",br[i].borrowed.month);
        fprintf(borrows,"/");
        fprintf(borrows,"%d",br[i].borrowed.year);
        fprintf(borrows,",");
        fprintf(borrows,"%d",br[i].due.day);
        fprintf(borrows,"/");
        fprintf(borrows,"%d",br[i].due.month);
        fprintf(borrows,"/");
        fprintf(borrows,"%d",br[i].due.year);
        fprintf(borrows,",");
        fprintf(borrows,"%d",br[i].returned.day);
        fprintf(borrows,"/");
        fprintf(borrows,"%d",br[i].returned.month);
        fprintf(borrows,"/");
        fprintf(borrows,"%d",br[i].returned.year);
        fprintf(borrows,"\n");
    }
    fclose(borrows);
}
/*A function that reads from borrows.txt  */
int read_borrows()
{
    borrows=fopen("borrows.txt","r");
    rewind(borrows);
    int count=0,z=0,i=0,n,v,y,u;
    char k[50];
    memset(k,0,50);
    char c;
    while(1)
    {
        c = fgetc(borrows);
        if( feof(borrows) )
        {
            break ;
        }
        if(c=='\n')
        {
            Divide_the_date(k,&v,&y,&u);
            br[z].returned.day=v;
            br[z].returned.month=y;
            br[z].returned.year=u;
            memset(k,0,50);
            u=0;
            y=0;
            v=0;
            i=0;
            z++;
            count=0;
        }
        else if(c==',')
        {
            count++;
            switch(count)
            {
            case 1:
                strcpy(br[z].ISBN,k);
                memset(k,0,50);
                i=0;
                break;
            case 2:
                n=atoi(k);
                br[z].id=n;
                memset(k,0,50);
                i=0;
                break;
            case 3:
                Divide_the_date(k,&v,&y,&u);
                br[z].borrowed.day=v;
                br[z].borrowed.month=y;
                br[z].borrowed.year=u;
                memset(k,0,50);
                u=0;
                y=0;
                v=0;
                i=0;
                break;
            case 4:
                Divide_the_date(k,&v,&y,&u);
                br[z].due.day=v;
                br[z].due.month=y;
                br[z].due.year=u;
                memset(k,0,50);
                u=0;
                y=0;
                v=0;
                i=0;
                break;
            default:
                break;
            }
        }
        else
        {
            k[i]=c;
            i++;
        }
    }
    fclose(borrows);
    return z;
}
/*A function that reads date from the Operating System*/
void Getdate(int*dd,int*mm,int*yy)
{
    time_t t=time(NULL);
    struct tm tm=*localtime(&t);
    *dd=tm.tm_mday;
    *mm=tm.tm_mon+1;
    *yy=tm.tm_year+1900;
}
/*A function that reads the date and calculates the days to advance till returning the book*/
int advance(int*day,int*month,int year)
{
    char h[30]= {'\0'};
    int n,c2=-1;
    int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int daysToAdvance,i;
    n=isLeapYear(year);
    if(n==1)
        daysPerMonth[1]=29;
    do
    {
        printf("Enter days to advance:\n");
        scanf("%s",h);
        c2=-1;
        daysToAdvance=valid_int(h,&c2);
        if(c2>=0||daysToAdvance==0)
        {
            system("cls");
            printf("enter a valid integer\n");
            Sleep(1500);
            system("cls");
            continue;
        }

        system("cls");
    }
    while(!valid_int(h,&c2)&&daysToAdvance<=0 || (valid_int(h,&c2))&&daysToAdvance<=0);
    for(i=0; i<daysToAdvance; i++)
    {
        (*day)++;
        if (*day>daysPerMonth[*month-1])
        {
            (*day)= 1;
            (*month)++;
            if ((*month)==13)
            {
                (*month)=1;
                year++;
            }
        }
    }
    return year;
}
/*A function that checks if this year is a Leap year */
int isLeapYear(int year)
{
    if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0))
        return 1;
    else
        return 0;
}
/*A function used to search for the borrowed books and takes the isbn , scans ID then returns to the returnbook function*/
int search_borrow(char isbn[])
{
    int i;

    int ID;
system("cls");
    printf("Enter the ID of the member\n");
    scanf("%d",&ID);
    for(i=0; i<z; i++)
    {
        if((strcmp(br[i].ISBN,isbn)==0)&&(br[i].id==ID))
        {
            return i;
        }
    }
    if(i==z)
    {
        printf("NOT FOUND\n");
        return 1000;
    }
}
/*A function that searches the ISBN of the book if found in books.txt or not*/
int search_return(char isbn [])
{
    int i;
    for(i=0; i<x; i++)
    {
        if((strcmp(b[i].ISBN,isbn)==0))
        {
            return i;
        }
    }
    if(i==x)
    {
        system("cls");
        printf("BOOK ISBN NOT FOUND.... \n");
        Sleep(1500);
        system("cls");
        return 1000;
    }
}
/*A function that prints the details of the overdue books */
void details_due(int i)
{
    printf("Member ID:%d\t\tBook ISBN:%s\n\n\n",br[i].id,br[i].ISBN);
}
/*A function that prints the popular books */
void print_popular(int i,int top)
{
    printf("%s\t\t%d\n\n",b[i].ISBN,top);
}
/*A function that validates the phone number entered by the user*/
int valid_num(char *num)
{
    int len;
    len = strlen(num);
    if(len==11&&num[0]=='0'&&num[1]=='1')
        return 1;
    else
    {
        system("cls");
        printf("invalid phone number....");
        Sleep(1500);
        system("cls");
        return 0;
    }
}
/*A function that checks if the ISBN is already found or not*/
int found_ISBN(char d[])
{
    int i;
    int count=0;
    for(i=0; i<x; i++)
    {
        if((strcmp(d,b[i].ISBN)==0))
        {
            count=1;
            return 0;
            /* FOUND AND REJECTED*/
        }
    }
    if(count==0)
        return 1;
    /* NOT FOUND IT WILL ACCEPT THE ISBN */
}
/*A function that checks if the ISBN is valid  - formal- or not*/
int valid_ISBN(char g[])
{
    int i,count=0,h,sum=0;

    for(i=0; i<strlen(g); i++)
    {
        if(g[i]=='-')
            count++;

    }
    if(count)
    {
        for(i=0; i<strlen(g); i++)
        {
            if(g[i]=='-')
                continue;
            h=isdigit(g[i]);
            if(!h)
            {
                system("cls");
                printf("Invalid ISBN\n");
                Sleep(1500);
                system("cls");
                return 0;
            }
            else
                sum+=1;
        }
    }
    if(count&&sum==13)
        return 1;
    else
    {
        system("cls");
        printf("Invalid ISBN\n");
        Sleep(1500);
        system("cls");
        return 0;
    }
}
/*A function that checks if the ID is already found or not*/
int found_ID(int d)
{
    int i;
    int count=0;
    for(i=0; i<y; i++)
    {
        if(d==m[i].id)
        {
            count=1;
            system("cls");
            printf("The ID is already used ...\n");
            Sleep(1500);
            system("cls");
            return 0;
            /* FOUND AND REJECTED*/
        }
    }
    if(count==0)
        return 1;
    /* NOT FOUND IT WILL ACCEPT THE ID */
}
/*A function that checks if the member already reached the maximum amount of borrowed books or not '3'*/
int limit_br(int l)
{

    int i,count=0;
    for(i=0; i<z; i++)
    {
        if((l==br[i].id)&&br[i].returned.day==0)
            count ++;
    }


    if(count>=3)
    {
        return 0;
    }
    else
        return 1;

}
/*A function that validates any integer */
int valid_int(char h[], int *c2)
{

    int i,j;

    for(i=0; i<strlen(h); i++)
    {
        if(isdigit(h[i])==0)
        {
            (*c2)++;
            return 0;
        }
        else if(!(isdigit(h[i])==0))
        {
            if(i==strlen(h)-1)
            {
                j=atoi(h);
                return j;
            }
            continue;
        }

    }
}
/*A function that validates the date */
int validate_date(int*r,int*g,int*q )
{
    int d,m,y,k;
    int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int flag=0;
    printf("Enter the publisher date\n");
    scanf("%d\n%d\n%d",&d,&m,&y);
if(d<=0||m<=0||y<=1900||y>2017)
        {
            system("cls");
        printf("Enter a valid date");
        Sleep(1500);
        return 0;
    }
    k=isLeapYear(y);
    if(k==1)
        daysPerMonth[1]=29;
    if (m<13)
    {
        if( d <= daysPerMonth[m-1] )
            flag=1;
    }

    if (flag==1)
    {
        *r=d;
        *g=m;
        *q=y;
        return 1;
    }
    else
    {
        printf("Invalid Date\n");
        return 0;
    }
}
/*A function that prints the details of the borrowed  books*/
void details_borrow(int i){

    printf("ISBN:%s\nID:%d\nBorrowed Date:%d/%d/%d\nDue Date:%d/%d/%d\nReturned Date:%d/%d/%d\n\n\n\n",br[i].ISBN,br[i].id,br[i].borrowed.day,br[i].borrowed.month,br[i].borrowed.year,br[i].due.day,br[i].due.month,br[i].due.year,br[i].returned.day,br[i].returned.month,br[i].returned.year);

}
/*A function that  holds a switch for printing the files*/
void print_files(){
    system("cls");
    int i,flag=0;
    do{
    printf("Choose:\n1)Print Saved Books\n2)Print Saved members\n3)Print saved borrowing\n4)back\n");
switch(getch()){
case '1':
    system("cls");
printf("Books:\n\n");
for(i=0;i<x;i++){
    details_books(i);
}
Sleep(10000);
system("cls");
flag=0;
startup();
case '2':
    system("cls");
printf("Members:\n\n");
for(i=0;i<y;i++){
    details_member(i);
}
Sleep(10000);
system("cls");
flag=0;
startup();
case '3':
printf("Borrows:\n\n");
for(i=0;i<z;i++){
    details_borrow(i);
}
Sleep(10000);
system("cls");
flag=0;
startup();
case '4':
    system("cls");
    Sleep(500);
    startup();

default:
    system("cls");
    printf("Enter a valid choice ... \n");
    Sleep(3000);
system("cls");
flag=1;
}
    }while(flag=1);
    }
