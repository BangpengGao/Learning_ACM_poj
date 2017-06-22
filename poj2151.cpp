#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
const int MAX=1010;
const int N=40;
int m,t,n,index;
double x[2][N],dp,p[MAX][N];

int main(void){
    while(cin>>m>>t>>n){
        if(m==0&&t==0&&n==0)
            break;
        double p1=1,p2=1,temp=1;
        for(int i=1;i<=t;++i){
            temp=1;
            for(int j=1;j<=m;++j){
                cin>>p[i][j];
                temp=temp*(1-p[i][j]);
            }
            p1=p1*(1-temp);
        }
        for(int i=1;i<=t;++i){
            index=0;
            memset(x,0,sizeof(x));
            x[0][0]=1;
            for(int j=1;j<=m;++j){
                index=index^1;
                for(int k=1;k<=m;++k)
                    x[index][k]=p[i][j]*x[index^1][k-1]+(1-p[i][j])*x[index^1][k];
                x[index][0]=x[index^1][0]*(1-p[i][j]);
            }
            dp=0;
            for(int j=1;j<=n-1;++j)
                dp+=x[index][j];
            p2=p2*dp;
        }
        printf("%0.3f\n",p1-p2);
    }
}
