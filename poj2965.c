#include<stdio.h>

int main(){
    int i,j,k;
    int times[5][5]={0};
    char n[10];
    for(i=1;i<=4;i++){
        scanf("%s",&n);
        for(j=0;j<4;j++){
            if(n[j]=='+'){
                for(k=1;k<=4;k++){
                    times[i][k]++;
                    if(k!=i)
                        times[k][j+1]++;
                }
            }
        }
        getchar();
    }
    j = 0;
    for(i=1;i<=4;i++){
        for(k=1;k<=4;k++){
            if(times[i][k]%2)
                j++;
        }
    }
    printf("%d\n",j);
    for(i=1;i<=4;i++){
        for(k=1;k<=4;k++){
            if(times[i][k]%2)
                printf("%d %d\n",i,k);
        }
    }
}
