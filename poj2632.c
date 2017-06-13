#include<stdio.h>
#include<string.h>

int map[105][105]={0};
int crash;

struct robots{
    int x;
    int y;
    char direction;
};

struct instruction{
    int robot;
    char action;
    int repeat;
};

void moves(struct robots ro,struct instruction ins,char d,int n,int m){
    int i;
    if(d=='W'){
        for(i=1;i<=ins.repeat;i++){
            if(ro.x-i<1){
                printf("Robot %d crashes into the wall\n",ins.robot);
                crash = 1;
                break;
            }
            else if(map[ro.x-i][ro.y]!=0){
                printf("Robot %d crashes into robot %d\n",ins.robot,map[ro.x-i][ro.y]);
                crash = 1;
                break;
            }
        }
    }
    else if(d=='E'){
        for(i=1;i<=ins.repeat;i++){
            if(ro.x+i>n){
                printf("Robot %d crashes into the wall\n",ins.robot);
                crash = 1;
                break;
            }
            else if(map[ro.x+i][ro.y]!=0){
                printf("Robot %d crashes into robot %d\n",ins.robot,map[ro.x+i][ro.y]);
                crash = 1;
                break;
            }
        }
    }
    else if(d=='N'){
        for(i=1;i<=ins.repeat;i++){
            if(ro.y+i>m){
                printf("Robot %d crashes into the wall\n",ins.robot);
                crash = 1;
                break;
            }
            else if(map[ro.x][ro.y+i]!=0){
                printf("Robot %d crashes into robot %d\n",ins.robot,map[ro.x][ro.y+i]);
                crash = 1;
                break;
            }
        }
    }
    else if(d=='S'){
        for(i=1;i<=ins.repeat;i++){
            if(ro.y-i<1){
                printf("Robot %d crashes into the wall\n",ins.robot);
                crash = 1;
                break;
            }
            else if(map[ro.x][ro.y-i]!=0){
                printf("Robot %d crashes into robot %d\n",ins.robot,map[ro.x][ro.y-i]);
                crash = 1;
                break;
            }
        }
    }
}

int main(void){
    int k,a,b,n,m,i,j;
    struct robots robs[105];
    struct instruction in[105];
    scanf("%d",&k);
    while(k--){
        map[105][105]=0;
        crash = 0;
        scanf("%d %d",&a,&b);
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%d %d %c",&robs[i].x,&robs[i].y,&robs[i].direction);
            map[robs[i].x][robs[i].y] = i;
        }
        for(i=1;i<=m;i++){
            scanf("%d %c %d",&in[i].robot,&in[i].action,&in[i].repeat);
            if(robs[in[i].robot].direction == 'W'){
                if(in[i].action == 'F'&&crash==0){
                    moves(robs[in[i].robot],in[i],'W',a,b);
                }
                else if(in[i].action == 'L'&&crash==0){
                    moves(robs[in[i].robot],in[i],'S',a,b);
                }
                else if(in[i].action == 'R'&&crash==0){
                    moves(robs[in[i].robot],in[i],'N',a,b);
                }
            }
            else if(robs[in[i].robot].direction == 'S'){
                if(in[i].action == 'F'&&crash==0){
                    moves(robs[in[i].robot],in[i],'S',a,b);
                }
                else if(in[i].action == 'L'&&crash==0){
                    moves(robs[in[i].robot],in[i],'E',a,b);
                }
                else if(in[i].action == 'R'&&crash==0){
                    moves(robs[in[i].robot],in[i],'W',a,b);
                }
            }
            else if(robs[in[i].robot].direction == 'E'){
                if(in[i].action == 'F'&&crash==0){
                    moves(robs[in[i].robot],in[i],'E',a,b);
                }
                else if(in[i].action == 'L'&&crash==0){
                    moves(robs[in[i].robot],in[i],'N',a,b);
                }
                else if(in[i].action == 'R'&&crash==0){
                    moves(robs[in[i].robot],in[i],'S',a,b);
                }
            }
            else if(robs[in[i].robot].direction == 'N'){
                if(in[i].action == 'F'&&crash==0){
                    moves(robs[in[i].robot],in[i],'N',a,b);
                }
                else if(in[i].action == 'L'&&crash==0){
                    moves(robs[in[i].robot],in[i],'W',a,b);
                }
                else if(in[i].action == 'R'&&crash==0){
                    moves(robs[in[i].robot],in[i],'E',a,b);
                }
            }
        }
        if(crash == 0)
            printf("OK\n");
    }
}
