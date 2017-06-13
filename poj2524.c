#include<stdio.h>
#include<string.h>
int student[50002];

int find(int x){
    if(student[x]==-1)
        return x;
    student[x]=find(student[x]);
    return student[x];
}

void build(int i,int j){
    int x=find(i);
    int y=find(j);
    if(x!=y)
        student[x]=y;
}

int main(void){
    int n,m,i,j,k,c,ca=0;
    while(scanf("%d %d",&n,&m)!=EOF){
        if(n==0&&m==0)
            break;
        ca++;
        memset(student,-1,sizeof(student));
        for(k=0;k<m;k++){
            scanf("%d %d",&i,&j);
            build(i,j);
        }
        c = 0;
        for(k=1;k<=n;k++){
            if(student[k]==-1)
                c++;
        }
        printf("Case %d: %d\n",ca,c);
    }
}
