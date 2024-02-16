#include<stdio.h>
#include<string.h>

typedef struct student
{
    char name[15];
    int marks[5];
    int avg_marks;

}std;


void main()
{
    std s1;
    int sum=0;
    strcpy(s1.name, "Gojo");
    
    for(int i=0;i<5;i++){
        s1.marks[i] = 80;
    }

    for(int i=0;i<5;i++)
    {
        sum+= s1.marks[i];
        
    }
    s1.avg_marks=sum/5;
    printf("name=%s, avg=%d",s1.name,s1.avg_marks);
    sum=0;
    
    
    std s2;
    strcpy(s2.name, "Geto");

    for(int i=0;i<5;i++){
        s2.marks[i] = 70;
    }
    for(int i=0;i<5;i++)
    {
        sum+= s2.marks[i];
        
    }
    s2.avg_marks=sum/5;
    printf("name=%s, avg=%d",s2.name,s2.avg_marks);


}