#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char tn[110000][110];
int num[110000];

int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int n,i,j,t,flag=0;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++){
        num[i] = 0;
        scanf("%s",&tn[i]);
        for(j=0;tn[i][j]!='\0';j++){
            if(tn[i][j]=='-')
                continue;
            if(tn[i][j]=='A'||tn[i][j]=='B'||tn[i][j]=='C')
                num[i]=num[i]*10+2;
            else if(tn[i][j]=='D'||tn[i][j]=='E'||tn[i][j]=='F')
                num[i]=num[i]*10+3;
            else if(tn[i][j]=='G'||tn[i][j]=='H'||tn[i][j]=='I')
                num[i]=num[i]*10+4;
            else if(tn[i][j]=='J'||tn[i][j]=='K'||tn[i][j]=='L')
                num[i]=num[i]*10+5;
            else if(tn[i][j]=='M'||tn[i][j]=='N'||tn[i][j]=='O')
                num[i]=num[i]*10+6;
            else if(tn[i][j]=='P'||tn[i][j]=='R'||tn[i][j]=='S')
                num[i]=num[i]*10+7;
            else if(tn[i][j]=='T'||tn[i][j]=='U'||tn[i][j]=='V')
                num[i]=num[i]*10+8;
            else if(tn[i][j]=='W'||tn[i][j]=='X'||tn[i][j]=='Y')
                num[i]=num[i]*10+9;
            else
                num[i]=num[i]*10+tn[i][j]-'0';
        }
    }
    flag = 0;
    qsort(num,n,sizeof(num[0]),cmp);
    for(i=0;i<n;i++){
        t=1;
        for(j=i+1;j<n;j++){
            if(num[i]==num[j])
                t++;
            else
                break;
        }
        if(t>1){
            printf("%0.3d-%0.4d %d\n",num[i]/10000,num[i]%10000,t);
            flag=1;
        }
        i = j - 1;
    }
    if(flag==0)
        printf("No duplicates.\n");
}

