#include<stdio.h>
#include<math.h>

int main(){
    long double r;int n;long double exp;
    while(scanf("%f %d",&r,&n)!=EOF){
        if(r<=0||r>=99.999||n<=0||n>25){
            continue;
        }
        exp = pow(r,n);
        printf("%Lf\n",exp);
    }
}
