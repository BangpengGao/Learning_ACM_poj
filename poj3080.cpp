#include<iostream>
#include<string.h>
using namespace std;

const int len=60;

int main(int i,int j)
{
	int test;
	cin>>test;
	for(int t=1;t<=test;t++)
	{
		int n;  //DNA����
		cin>>n;
		char** DNA=new char*[n];
		for(int p=0;p<n;p++)
		{
			DNA[p]=new char[len+1];
			cin>>DNA[p];
		}

		char obj[len+1];  //����DNA�Ĺ�����
		int StrLen=0;    //�����������
		int length=1;    //��ǰö�ٵĹ���������

		for(i=0;;i++)  //ö�ٹ�����dna[]
		{
			/*��ȡDNA[0][]����piΪ��㣬����Ϊlength���Ӵ�dna[]*/
			char dna[len+1];
			int pi=i;
			if(pi+length>len)
			{
				length++;
				i=-1;
				if(length>len)
					break;
				continue;
			}
			for(j=0;j<length;j++)
				dna[j]=DNA[0][pi++];
			dna[j]='\0';

			/*�������DNA[][]�Ƿ񶼴����ַ���dna[]*/
			bool flag=true;
			for(int k=1;k<n;k++)
				if(!strstr(DNA[k],dna))  //����һ��DNA������dna[]
				{
					flag=false;
					break;
				}

			/*ȷ����󹫹���*/
			if(flag)
			{
				if(StrLen<length)
				{
					StrLen=length;
					strcpy(obj,dna);
				}
				else if(StrLen==length)
				{
					if(strcmp(obj,dna)>0)  //������ͬ���ȵĹ�����ʱ��ȡ��С�ֵ���Ĵ�
						strcpy(obj,dna);
				}
			}
		}

		if(StrLen<3)
			cout<<"no significant commonalities"<<endl;
		else
			cout<<obj<<endl;

		delete DNA;
	}
	return 0;
}
