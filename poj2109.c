#include<stdio.h>
#include<math.h>

int main(void){
    double p,k,n;
    while(scanf("%lf %lf",&n,&p)!=EOF){
        printf("%.0lf\n",pow(p,1/n));
    }
}
