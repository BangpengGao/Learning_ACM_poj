#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
using namespace std;

const int N = 5e5+5;
typedef long long LL;
struct Node{
    int val,pos;
}a[N];
int tree[N], index[N], n;

bool cmp(const Node &x, const Node &y){
    return x.val < y.val;
}

#define lowbit(x)(x&-x)
void add(int idx){
    while(idx<=n){
        tree[idx]++,idx+=lowbit(idx);
    }
}
int sum(int idx){
    int s = 0;
    while(idx>0){
        s+=tree[idx],idx -= lowbit(idx);
    }
    return s;
}

int main(void){
    while(scanf("%d", &n)!=EOF && n){
        memset(tree, 0, sizeof(tree));
        for(int i=1; i<=n; i++)
            scanf("%d",&(a[i].val)),a[i].pos=i;
        sort(a+1, a+n+1, cmp);
        for(int i=1;i<=n;i++)
            index[a[i].pos] = i;

        LL ans = 0;
        for(int i=1;i<=n;i++)
            add(index[i]),ans += i-sum(index[i]);
        printf("%lld\n",ans);
    }
    return 0;
}
