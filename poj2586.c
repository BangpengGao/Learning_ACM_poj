#include<stdio.h>

int main(void){
    int s,d,k;
    while(scanf("%d %d",&s,&d)!=EOF){
        if(s==0||d==0){
            printf("Deficit\n");
            continue;
        }
        if(4*s - d <= 0)
            k=10*s-2*d;
        else if(3*s-2*d<=0)
            k = 8*s-4*d;
        else if(2*s-3*d<=0)
            k = 6*s-6*d;
        else if(s-4*d<=0)
            k = 3*s-9*d;
        else
            k = -1;
        if(k>=0)
            printf("%d\n",k);
        else
            printf("Deficit\n");
    }
}
