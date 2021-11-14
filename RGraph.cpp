#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(0));
	for(int i=1;i<=250;i++)
		for(int j=1;j<=250;j++)
		{
			cout<<rand()%256<<","<<rand()%256<<","<<rand()%256<<endl;
		}
}
