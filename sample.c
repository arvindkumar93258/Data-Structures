#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


int main()
{

    //cout<<"Hello world"<<endl;
    char *p = "Arvind";
    char q[] = "Arvind";
    char r[] = {'A', 'r', 'v', 'i', 'n', 'd'};
    printf("%d %d %d",strlen(p), strlen(q), strlen(r));
    printf(p);
    return 0;
}