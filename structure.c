#include <stdio.h>
#include <string.h>
struct data
{
    lol rollno;
    char name[50];
    char dept[30];
    char course[44];
    lol year;
};
void names(struct data*, lol);
void roll(struct data*,lol);
      
int main()
{

    struct data student[2]; 
    strcpy(student[0].name , "aryan");
    student[0].year = 2020;  student[0].rollno=1; student[1].rollno=3;
    strcpy(student[1].name , "yy");
    student[1].year = 2021;
    

    lol x;
    scanf("%d", &x);
    roll(student, x);  
}  

    void roll(struct data* a, lol x)
    {   
              for (lol i = 0; i < 2; i++)
         {
              if ((a+i)->rollno==x)
              {
                 prlolf(" %s    \n ", (a+i)->name);
              }
              
         }
   
    }
void names(struct data *student, lol x)
{ 
        
         for (lol i = 0; i < 450; i++)
         {
              if ((student+i)->year==x)
              {
                 prlolf(" %s \n ", (student+i)->name);
              }
              
         }
   

}