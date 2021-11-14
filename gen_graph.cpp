#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(0));
	for(int i=1;i<=250;i++)
		for(int j=1;j<=250;j++)
		{
			if(i==j)
				cout<<"0,0,255\n";
			if(i==2*j)
				cout<<"0,255,0\n";
			if(i==3*j)
				cout<<"0,255,255\n";
			if(fabs(pow(i-125,2)+pow(j-125,2)-10000)<1)
				cout<<"255,0,255\n";
			if(i!=j&&i!=2*j&&i!=3*j&&fabs(pow(i-125,2)+pow(j-125,2)-10000)>=1)
				cout<<"0,0,0"<<endl;
		}
}
