#include<stdio.h>
int stu[30100],num[30100],n,m;
int Find(int j){
    if(stu[j]==j)
        return j;
    return stu[j] = Find(stu[j]);
}

void init(){
    int i;
    for(i=0;i<n;i++){
        stu[i] = i;
        num[i] = 1;
    }
}

int main(void){
    int k,x,y,s,t,i,j;
    while(scanf("%d %d",&n,&m)!=EOF){
        if(n==0&&m==0)
            break;
        if(m==0){
            printf("1\n");
            continue;
        }
        init();
        for(i=1;i<=m;i++){
            scanf("%d",&k);
            scanf("%d",&s);
            x = Find(s);
            for(j=1;j<k;j++){
                scanf("%d",&t);
                y = Find(t);
                if(x!=y){
                    stu[y] = x;
                    num[x] += num[y];
                }
            }
        }
        printf("%d\n",num[Find(0)]);
    }
}
