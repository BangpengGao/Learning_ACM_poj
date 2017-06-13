#include<stdio.h>
#include<string.h>

char Tzolkin_month[21][10] = {"0","imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int changeMonth(char* month){
    int i,ASCII = 0;
    for(i=0;month[i]!='\0';i++)
        ASCII += month[i];

    switch(ASCII){
        case 335:return 1;
        case 221:return 2;
        case 339:return 3;
        case 471:return 4;
        case 438:return 5;
        case 345:return 6;
        case 674:return 7;
        case 328:return 8;
        case 414:return 9;
        case 338:return 10;
        case 318:return 11;
        case 304:return 12;
        case 305:return 13;
        case 636:return 14;
        case 433:return 15;
        case 329:return 16;
        case 534:return 17;
        case 546:return 18;
        case 552:return 19;
    }
}

int main(){
    int n,i=0;
    int day,year,mon,all_day;
    char month[10],dot;
    int d[6000],y[6000];
    char m[6000][10];
    scanf("%d",&n);
    while(i<n &&scanf("%d %s %s %d",&day,&dot,&month,&year)!=EOF){
        mon = changeMonth(month);
        all_day = 365*year+20*(mon-1)+day;
        year = all_day/260;
        mon = all_day%20+1;
        day = all_day%13+1;

        d[i] = day;y[i] = year;strcpy(m[i], Tzolkin_month[mon]);
        i++;
    }
    printf("%d\n",n);
    for(i=0;i<n;i++)
        printf("%d %s %d\n",d[i],m[i],y[i]);
}
