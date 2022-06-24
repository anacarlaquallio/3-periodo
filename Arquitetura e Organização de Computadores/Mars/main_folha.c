#include <stdio.h>
#include <stdlib.h>
int exemplo_folha(int x,int y,int w,int z);
void main()
{
    int f,g,h,i,j;
    f=0;
    g=4;
    h=3;
    i=2;
    j=1;
		
    f=exemplo_folha(g,h,i,j);
    printf("f= %d\n",f);
}
int exemplo_folha(int x,int y,int w,int z){
    int f;
    
    f=(x+y)-(w+z);
    return f;
}

