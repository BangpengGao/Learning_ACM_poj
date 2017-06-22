#include<iostream>
#include<cmath>
#include<string.h>
#include<algorithm>
using namespace std;

const int size=100001;
const int mod=99991;

int feature[size][30];
int sum[size][30];
int c[size][30];
int N,K,MaxLen;

typedef class HASH{
public:
    int pi;
    class HASH* next;
    HASH(){
        next = 0;
    }
}HashTable;

HashTable* hash[mod];

bool cmp(int ai,int bi){
    for(int j=0;j<K;j++)
        if(c[ai][j]!=c[bi][j])
            return false;
    return true;
}

void Hash(int ci){
    int key=0;
    for(int j=1;j<K;j++)
        key+=c[ci][j];
    key=abs(key)%mod;

    if(!hash[key]){
        HashTable* pn=new HashTable;
        pn->pi=ci;
        hash[key]=pn;
    }
    else{
        HashTable* pn=hash[key];
        if(cmp(pn->pi,ci)){
            int dist=ci-(pn->pi);
            if(MaxLen<dist)
                MaxLen=dist;
            return;
        }
        else{
            while(pn->next){
                if(cmp(pn->next->pi,ci)){
                    int dist=ci-(pn->next->pi);
                    if(MaxLen<dist)
                        MaxLen=dist;
                    return;
                }
                pn=pn->next;
            }

            HashTable* temp = new HashTable;
            temp->pi = ci;
            pn->next=temp;
        }
    }
    return;
}

int main(void){
    while(cin>>N>>K){
        for(int p=0;p<K;p++){
            c[0][p]=0;
            sum[0][p]=0;
        }
        memset(hash,0,sizeof(hash));
        Hash(0);
        MaxLen=0;

        for(int i=1;i<=N;i++){
            int Dexf;
            cin>>Dexf;
            for(int j=0;j<K;j++){
                feature[i][j]=Dexf%2;
                Dexf/=2;

                sum[i][j]=sum[i-1][j]+feature[i][j];
                c[i][j]=sum[i][j]-sum[i][0];
            }
            Hash(i);
        }

        cout<<MaxLen<<endl;
    }
    return 0;
}
