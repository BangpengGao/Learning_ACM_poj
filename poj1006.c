#include<stdio.h>

int main(){
    int p,e,i,d,k=1,t;
    while(scanf("%d %d %d %d", &p, &e, &i, &d) != EOF){
        if(p == -1 && e == -1 && i == -1 && d == -1)
            break;
        p = p % 23; e = e % 28; i = i % 33; t = d + 1;
        while(t < 21252 + d){
            if(t % 23 == p && t % 28 == e && t % 33 == i){
                printf("Case %d: the next triple peak occurs in %d days.\n",k,t-d);
                break;
            }
            t++;
        }
        if(t == 21252 + d)
            printf("Case %d: the next triple peak occurs in 21252 days.\n",k);
        k++;
    }
}
