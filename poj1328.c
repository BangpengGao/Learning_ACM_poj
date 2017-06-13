#include<stdio.h>
#include<math.h>

typedef struct island{
    float x;
    float y;
    float reminder;
    int visit;
};

struct island isl[1001];

void sort_island(struct island *land, int n){
    int i,j;
    struct island iss;
    for(i=1;i<n;i++){
        iss = land[i];
        j = i-1;
        while(j>=0&&land[j].reminder>iss.reminder){
            land[j+1] = land[j];
            j--;
        }
        land[j+1] = iss;
    }
}

int main(){
    int i,j,k,n,d,c=0,out=0;
    while(scanf("%d %d",&n,&d)!=EOF){
        if(n<=0&&d<=0)
            break;
        c++;out = 0;
        for(i=0;i<n;i++){
            scanf("%f %f",&isl[i].x,&isl[i].y);
            if(isl[i].y > d || isl[i].y < 0.0 || d < 0)
                out = 1;
            isl[i].reminder = sqrt(pow(d,2.0) - pow(isl[i].y, 2.0));
        }
        if(out==1){
            printf("Case %d: -1\n",c);
            continue;
        }
        sort_island(isl,n);
        for(i=0;i<n;i++){
            isl[i].visit = 0;
        }
        i=0;k=0;
        while(i<n){
            if(isl[i].visit == 0){
                isl[i].visit = 1;
                k++;
                for(j=1;j<n;j++){
                    if(((isl[i].reminder+isl[j].reminder)>=fabs(isl[i].x-isl[j].x)) && isl[j].visit == 0){
                        isl[j].visit = 1;
                    }
                }
            }
            i++;
        }
        printf("Case %d: %d\n",c,k);
    }
}
