#include<stdio.h>
#include<malloc.h>
void main()
{
    char *a = "hey";
//got rid of free(a)
    a = "hello";   
    printf("%s",a);
}
