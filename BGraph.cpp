#pragma once
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
//#include<bigint.h>
#include<csignal>
#include<pthread.h>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
#include<string>
#define loop(n) for(int i=1;i<=n;i++)
#define stop while(1) cout<<""
#define pass cout<<""
#define loopv(var,start,stop,step) for(int var=start;var<=stop;var+=step)
#define cls system("cls")
#define cmd(c) system("c")
using namespace std;
typedef struct pixel
{
	int r=0,g=0,b=0;
} pixel;
vector<pixel> p;
void read(pixel& n)
{
	int& r=n.r;
	int& g=n.g;
	int& b=n.b;
	fflush(NULL);
	scanf("%d,%d,%d",&r,&g,&b);
}
void bin(pixel& n)
{
	int& r=n.r;
	int& g=n.g;
	int& b=n.b;
	r=int(r>127);
	g=int(g>127);
	b=int(b>127);
	int c;
	c=0;
	if(r==1)
		c++;
	if(g==1)
		c++;
	if(b==1)
		c++;
	r=g=b=255*int(c>1);
}
int main()
{
	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);
	int h,w;
	char c[128];
	string fn;
	printf("filename:");
	scanf("%s",c);
	fn=c;
	printf("height:");
	scanf("%d",&h);
	printf("width:");
	scanf("%d",&w);
	printf("reading pixels(RGB format)\n");
	freopen(fn.c_str(),"r",stdin);
	pixel t;
	for(int i=1; i<=h*w; i++)
	{
		read(t);
		p.push_back(t);
	}
	system("cls");
	int cnt=-1;
	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=w; j++)
		{
			cnt++;
			bin(p[cnt]);
			//cout<<p[cnt].r<<" "<<p[cnt].g<<" "<<p[cnt].b<<endl;
		}
	}
	cnt=-1;
	while(1)
	{
		for(int i=1; i<=h; i++)
		{
			for(int j=1; j<=w; j++)
			{
				cnt++;
				SetPixel(mydc, i,j, RGB(p[cnt].r,p[cnt].g,p[cnt].b));
			}
		}
		cnt=-1;
	}
}

