#include<stdio.h>
#include<string.h>
int sta[120];
char str[120];
int p,q,r,s,t;

void tautology(){
    int top=0,i;
    int len = strlen(str);
    for(i=len-1;i>=0;i--){
        if(str[i]=='p') sta[top++]=p;
        else if(str[i]=='q') sta[top++]=q;
        else if(str[i]=='r') sta[top++]=r;
        else if(str[i]=='s') sta[top++]=s;
        else if(str[i]=='t') sta[top++]=t;
        else if(str[i]=='K'){
            int x=sta[--top];
            int y=sta[--top];
            sta[top++]=(x&&y);
        }
        else if(str[i]=='A'){
            int x=sta[--top];
            int y=sta[--top];
            sta[top++]=(x||y);
        }
        else if(str[i]=='N'){
            int x=sta[--top];
            sta[top++]=(!x);
        }
        else if(str[i]=='C'){
            int x=sta[--top];
            int y=sta[--top];
            if(x==0&&y==1)
                sta[top++]=0;
            else
                sta[top++]=1;
        }
        else if(str[i]=='E'){
            int x=sta[--top];
            int y=sta[--top];
            if(x==y)
                sta[top++]=1;
            else
                sta[top++]=0;
        }
    }
}

int start(){
    for(p=0;p<=1;p++){
        for(q=0;q<=1;q++){
            for(r=0;r<=1;r++){
                for(s=0;s<=1;s++){
                    for(t=0;t<=1;t++){
                        tautology();
                        if(sta[0]==0)
                            return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main(void){
    while(scanf("%s",&str)){
        if(str[0]=='0')
            break;
        if(start())
            printf("tautology\n");
        else
            printf("not\n");
    }
}
