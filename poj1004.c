#include<stdio.h>

int main(){
    float sum = 0.0;
    int m;
    for(m=0;m<12;m++){
        float mo;
        scanf("%f",&mo);
        sum = sum + mo;
    }
    printf("$%0.2f\n",sum/12);
}
