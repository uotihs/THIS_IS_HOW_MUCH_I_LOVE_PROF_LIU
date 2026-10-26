#ifndef BOOK_H
#define BOOK_H
 
enum Type {NOVEL, COMICS, MANUAL, TEXTBOOK};
 
struct Book {
    char title[128];
    enum Type type;
    char ISBN[128];
    char authors[128];
    unsigned int importance;
};
 
#endif

#ifndef DATE_H
#define DATE_H
 
struct Date {
    unsigned int year;
    unsigned int month;
    unsigned int day;
};
 
#endif

#include "book.h"
#include "date.h"
// #include <stdio.h>
int days[12] ={31,28,31,30,31,30,31,31,30,31,30,31};
int daysruan[12] ={31,29,31,30,31,30,31,31,30,31,30,31};

unsigned int returnDay(struct Date day1)
{
    unsigned int dayCount = 0;

    for(int i=1000;i<day1.year;i++)
    {
        if(i % 4 ==0 && i % 100 != 0 || i % 400 == 0)
        {
            dayCount+=366;
        }
        else
        {
            dayCount+=365;
        }
    }
    int run1 = 0;
    if(day1.year % 4 ==0 && day1.year % 100 != 0 || day1.year % 400 == 0)
    {
        run1 = 1;
    }
    for(int i = 0 ; i<day1.month-1;i++)
    {
        if(run1) dayCount+= daysruan[i];
        else dayCount+= days[i];
    }
    dayCount += day1.day;
    
    return dayCount;
}
 
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned)
{
    unsigned int dayLimit = 0;
    unsigned int days = returnDay(date_returned)-returnDay(date_borrowed)+1;
    // printf("%d" ,days);

    if(book.type == NOVEL)
    {
        dayLimit = 90;
        


    }
    else if(book.type == COMICS)
    {
        dayLimit = 10;



    }else if(book.type == MANUAL)
    {
        dayLimit = 100;




    }else if(book.type == TEXTBOOK)
    {
        dayLimit = 5;





    }

    if(days <= dayLimit)
    {return 0;}

    int first = -1;
    int distance = 0;
    for(int i =0; i<64;i++)
    {
        if((book.importance >> i) & 1 == 1)
        {
            if(first == -1)
            {
                first = i;
            }
            else 
            {
                distance = i - first -1 ;
                break;
            }
        }
    }
    // printf("%d",distance);

    return (unsigned)distance*(days-dayLimit);



}



// #include "book.h"
// #include "date.h"
 
// unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned);
 
// int main(){
//     struct Book book = {
//         "Neon Genesis Evangelion",
//         COMICS,
//         "978-159-116-400-5",
//         "Yoshiyuki Sadamoto",
//         17
//     };
//     struct Date date_borrowed, date_returned;
//     date_borrowed.year  = 2007;
//     date_borrowed.month = 11;
//     date_borrowed.day   = 14;
//     date_returned.year  = 2007;
//     date_returned.month = 12;
//     date_returned.day   = 3;
//     printf("The fine is $%d.\n", library_fine(book, date_borrowed, date_returned));
//     return 0;
// }