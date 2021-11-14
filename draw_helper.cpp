#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
typedef struct pixel
{
	int r,g,b;
} pixel;
int x1,x2,y1,y2,h,w,r,g,b;
vector<pixel> p;
void read(pixel& n)
{
	int& r=n.r;
	int& g=n.g;
	int& b=n.b;
	fflush(NULL);
	scanf("%d,%d,%d",&r,&g,&b);
}
void set(int x,int y)
{
	if(p.empty())
	{
		pixel t;
		for(int i=1; i<=h*w; i++)
		{
			read(t);
			p.push_back(t);
		}
		t={r,g,b};
		p[y*w+x]=t;
	}
}
int main()
{
	bool open=false;
	string n;
	string c;
	while(1)
	{
		cin>>c;
		if(c=="help")
		{
			cout<<"interactive plotting shell\n";
			cout<<"commands:\n";
			cout<<"\topen <file> <height> <width>\n";
			cout<<"\tclose\n";
			cout<<"\tpreview\n";
			cout<<"\tcolor <r> <g> <b>\n";
			cout<<"\tline <x1> <y1> <x2> <y2>\n";
			cout<<"\trect <x1> <y1> <x2> <y2>\n";
			cout<<"\tcircle <x> <y> <r>\n";
		}
		else
		{
			if(c=="open")
			{
				open=true;
				cin>>n>>h>>w;
				ofstream fout(n.c_str());
			}
			else
			{
				if(c=="close")
				{
					open=false;
					fout.close();
				}
				else
				{
					if(c=="preview")
					{
						HWND myconsole = GetConsoleWindow();
						HDC mydc = GetDC(myconsole);
						printf("reading pixels(RGB format)\n");
						freopen(n.c_str(),"r",stdin);
						pixel t;
						for(int i=1; i<=h*w; i++)
						{
							read(t);
							p.push_back(t);
						}
						system("cls");
						int cnt=-1;
						while(1)
						{
							for(int i=1; i<=h; i++)
							{
								for(int j=1; j<=w; j++)
								{
									cnt++;
									SetPixel(mydc, i,j, RGB(p[cnt].r,p[cnt].g,p[cnt].b));
									if(_kbhit())
									{
										system("cls");
										break;
									}
								}
							}
							cnt=-1;
							if(_kbhit())
							{
								system("cls");
								break;
							}
						}
					}
					else
					{
						if(c=="color")
						{
							cin>>r>>g>>b;
						}
						else
						{
							if(c=="line")
							{
								cin>>x1>>y1>>x2>>y2;
								double d;
								int y;
								d=(x1-x2)/(y1-y2);
								for(int i=min(x1,x2);i<=max(x1,x2);i++)
								{
									y=int((i-x1)*d+y1);
									set(i,y);
								}
							}
							else
							{
								if(c=="rect")
								{
									cin>>x1>>y1>>x2>>y2;
									for(int i=min(x1,x2);i<=max(x1,x2);i++)
										for(int j=min(y1,y2);j<=max(y1,y2);j++)
											set(i,j);
								}
								else
								{
									if(c=="circle")
									{
										cin>>x1>>y1>>x2;
										int r=x2;
										for(int i=0;i<=w-1;i++)
										{
											set(i,sqrt(pow(r,2)-pow(i-x1,2))+y1);
											set(i,-sqrt(pow(r,2)-pow(i-x1,2))+y1);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
