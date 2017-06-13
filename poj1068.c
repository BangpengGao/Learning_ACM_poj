#include<stdio.h>
#include<string.h>
char p[50];
int top=0;

void insert_k(int n){
    while(n>0){
        p[top++]='(';
        n--;
    }
    p[top++]=')';
}

int find_k(int i){
    int k,c=0,t=1;
    for(k=i;k>=0;k--){
        if(p[k]==')'){
            t++;
            continue;
        }
        if(p[k]=='('){
            t--;
            c++;
            if(t==0)
                return c;
        }
    }
}

int main(void){
    int t,n,i,j,left[25];
    scanf("%d",&t);
    while(t>0){
        scanf("%d",&n);
        left[0]=0;top = 0;
        for(i=1;i<=n;i++){
            scanf("%d",&left[i]);
            insert_k(left[i]-left[i-1]);
        }
        j=0;
        for(i=0;i<top;i++){
            if(p[i]==')'){
                j++;
                if(j<n)
                    printf("%d ",find_k(i-1));
                else{
                    printf("%d\n",find_k(i-1));
                    break;
                }
            }
        }
        t--;
    }
}
