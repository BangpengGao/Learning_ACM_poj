#include<stdio.h>

int main(){
    float c,cards[300];
    int i,k;
    cards[0] = 0.5;
    for(i = 1; i < 300; i++)
        cards[i] = cards[i-1] + 1.0/(i+2);
    while(scanf("%f",&c) != EOF && c > 0.00){
        if(c > 5.20)
            continue;
        if(c<=0.5)
            printf("1 card(s)\n");
        else{
            for(i=0;i<300;i++){
                if(cards[i]>c){
                    k = i + 1;
                    break;
                }
            }
            printf("%d card(s)\n",k);
        }
    }
}
