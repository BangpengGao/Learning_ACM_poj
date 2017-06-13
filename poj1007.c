#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct DNA{
    int measure;
    char sequence[100];
};

struct DNA dna[100];

void struct_sort(struct DNA *a,int m){
    struct DNA temp;
    int i,j;
    for(i=1;i<m;i++){
        temp = a[i];
        j = i-1;
        while(j>=0 && a[j].measure > temp.measure){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

int main(){
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    getchar();
    for(i=0;i<m;i++){
        scanf("%s",&dna[i].sequence);
        dna[i].measure = 0;
        for(j=0;j<n;j++){
            if(dna[i].sequence[j] == 'A')
                continue;
            for(k=j+1;k<n;k++){
                if(dna[i].sequence[j] > dna[i].sequence[k])
                    dna[i].measure += 1;
            }
        }
    }
    struct_sort(dna,m);
    for(i=0;i<m;i++)
        printf("%s\n",dna[i].sequence);
}
