//*******************************************************
//      INCLUDED HEADER FILES
//*******************************************************
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<graphics.h>
#include<iomanip.h>

//*******************************************************
//      CLASS NAME : BOOK
//*******************************************************

class book
{
public:
    char name[20];
    char author[20];
    char a[10];
    char buffer[100];
    void getdata();
};
fstream f;
book b1;

//*******************************************************
//      FUNCTIONS TO GET AND SHOW DATA
//*******************************************************

void book::getdata()
{
    cout<<"\n            ENTER DETAILS ABOUT BOOK U WANT TO PURCHASE :";
    cout<<"\n\n\n\t\tEnter Name Of Book : ";
    cin>>name;
    fflush(stdin);
    cout<<"\n\t\tEnter Name Of Author : ";
    cin>>author;
    fflush(stdin);
    cout<<"\n\t\tEnter No. Of Copies : ";
    cin>>a;
}

//*******************************************************
//      TO INVOKE WELCOME SCREEN, CREDIT SCREEN
//                   & ENDING SCREEN
//*******************************************************

void graph()
{
    for(int y=0;y<440;y=y+15)
    {
	fillellipse(70,y,50,50);
	setfillstyle(2,GREEN);
	fillellipse(170,y-40,50,50);
	setfillstyle(3,YELLOW);
	fillellipse(270,y,50,50);
	setfillstyle(2,WHITE);
	fillellipse(370,y,50,50);
	setfillstyle(3,6);
	fillellipse(470,y-40,50,50);
	setfillstyle(2,BLUE);
	fillellipse(570,y,50,50);
	setfillstyle(3,CYAN);
	clearviewport();

	for(int c=440; c<480; ++c)
	{
	    setlinestyle(0,1,3);
	    setcolor(WHITE);

	    line(0,c,325,480);
	    line(680,c,325,480);
	}
	delay(1);
    }

    int x[5];
    for(x[0]=50,x[1]=100,x[2]=200,x[3]=400,x[4]=500,y=450; y>=240; y=y-10,x[0]=x[0]+13,x[2]=x[2]+6,x[1]+=11,x[3]-=4,x[4]-=9)
    {
	fillellipse(x[0],y,20,20);
	setfillstyle(1,GREEN);
	fillellipse(x[1],y,20,20);
	setfillstyle(1,YELLOW);
	fillellipse(x[2],y+10,20,20);
	setfillstyle(1,WHITE);
	fillellipse(300,y-15,20,20);
	setfillstyle(1,6);
	fillellipse(x[3],y-5,20,20);
	setfillstyle(1,BLUE);
	fillellipse(x[4],y+20,20,20);
	setfillstyle(1,CYAN);

	clearviewport();
	for(int c=440; c<480; ++c)
	{
	    setlinestyle(0,1,3);
	    setcolor(RED);
	    line(0,c,325,480);
	    line(680,c,325,480);
	}
	delay(1);
    }

    for (int c=0; c<180; ++c)
    {
	setcolor(BLACK);
	fillellipse(305,240,c*1.7,c);
	delay(0);
    }
    setcolor(BLACK);
    settextstyle(7,0,5);
    outtextxy(25,220,"A&I B O O K - S T O R E");
    getch();
    clearviewport();
}

void main()
{
    clrscr();
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
    graph();
    rectangle(10,10,630,470);
    setbkcolor(RED);
    rectangle(10,10,630,470);
    settextstyle(GOTHIC_FONT,0,4);
    setcolor(WHITE);
    outtextxy(30,35,"Developed By:-");
    settextstyle(3,0,3);
    outtextxy(120,130,"Syed Mohammed Idris {1HK18IS094}");
    getch();
    char s;
    book b1;
z:

    fstream f;
    f.open("book.txt",ios::out|ios::in|ios::ate|ios::app);
    clearviewport();
    settextstyle(10,HORIZ_DIR,3);
    setbkcolor(GREEN);
    rectangle(10,10,630,470);
    outtextxy(80,15,"WHAT DO U WANT TO DO?");
    settextstyle(SANS_SERIF_FONT,0,3);
    outtextxy(200,80,"1 . ADD A BOOK");
    outtextxy(200,130,"2 . SHOW ALL BOOKS");
    outtextxy(200,180,"3 . CHECK AVAILABILITY");
    outtextxy(200,230,"4 . MODIFY A BOOK");
    outtextxy(200,280,"5 . DELETE A BOOK");
    outtextxy(200,330,"6 . EXIT");
    int ch;
    settextstyle(7,0,4);
    outtextxy(40,373, "ENTER UR CHOICE:");
    f.seekg(0);
    gotoxy(48,25);
    cin>>ch;
    char x;
    gotoxy(1,1);

    switch(ch)
    {

//*******************************************************
//      CASE       : 1
//      DETAILS    : TO ADD A BOOK RECORD
//*******************************************************

    case 1:
	gotoxy(1,1);
	clearviewport();
	rectangle(10,10,630,470);
	setbkcolor(RED);
	textbackground(13);
	textcolor(6);
	clrscr();
	fstream f;
	f.open("book.txt",ios::in|ios::out|ios::ate|ios::app);
	char ans;
	b1.getdata();
	strcpy(b1.buffer,b1.name);
	strcat(b1.buffer,"|");
	strcat(b1.buffer,b1.author);
	strcat(b1.buffer,"|");
	strcat(b1.buffer,b1.a);
	strcat(b1.buffer,"\n");
	f<<b1.buffer;
	f.close();
	getch();
	settextstyle(7,0,1);
	outtextxy(250,410,"Do You Want To Continue:(Y/N)");

	ans=getchar();
	if(ans=='Y' || ans=='y')
	    goto z;
	else
	    break;

//*******************************************************
//      CASE       : 2
//      DETAILS    : TO SHOW ALL BOOK RECORDS
//*******************************************************

    case 2:
    {
	clearviewport();
	rectangle(10,10,630,470);
	setbkcolor(LIGHTBLUE);
	outtextxy(150,15,"ALL BOOKS DETAILS:");
	settextstyle(SANS_SERIF_FONT,0,2);
	textbackground(3);
	textcolor(6);
	cout<<"\n\n";
	fstream f;
	f.open("book.txt",ios::in);
	char ans;
	f.seekg(0);
	cout<<"\n\n\t\tBOOK"<<setw(20)<<" AUTHOR"<<setw(20)<<"COPIES"<<endl;
	cout<<"\t============================================================";
	while(!f.eof())
	{
	 f.getline(b1.name,20,'|');
	 f.getline(b1.author,20,'|');
	 f.getline(b1.a,10,'\n');
	 cout<<"\n\t"<<b1.name<<setw(20)<<b1.author<<setw(20)<<b1.a;
	}
	f.close();
	settextstyle(7,0,1);
	outtextxy(250,410,"Do You Want To Continue:(Y/N)");
	cin>>ans;
	if(ans=='y'|| ans=='Y')
	    goto z;
	else
	{
	    closegraph();
	    exit(1);
	}
    }

//*******************************************************
//      CASE       : 3
//      DETAILS    : TO CHECK AVAILABILITY
//*******************************************************

    case 3:
    {
	gotoxy(60,25);
	clearviewport();
	rectangle(10,10,630,470);
	setbkcolor(DARKGRAY);
	textbackground(3);
	textcolor(5);
	clrscr();
	char ans;
	ifstream f;
	book b1;
	char name[20];
	char author[20];
	char a[10];
	f.open("book.txt",ios::in);
	cout<<"\n\n\n          Enter book name whose record to be seen  :";
	cin>>name;

	while(!f.eof())
	{
	 f.getline(b1.name,20,'|');
	 f.getline(b1.author,20,'|');
	 f.getline(b1.a,10,'\n');
	 if(strcmp(b1.name,name)==0)
	 {
	  cout<<"\n   Record Found!!";
	  cout<<"\n\n   BOOK   :"<<b1.name;
	 cout<<"\n   AUTHOR :"<<b1.author;
	 cout<<"\n   COPIES :"<<b1.a;
	 }
	 }
	f.close();
	settextstyle(7,0,1);
	outtextxy(250,410,"Do You Want To Continue:(Y/N)");
	ans=getchar();
	if(ans=='Y'||ans=='y')
	    goto z;
	else
	    break;
    }

//*******************************************************
//      CASE       : 4
//      DETAILS    : TO MODIFY A RECORD
//*******************************************************

    case 4:
    {
	clearviewport();
	rectangle(10,10,630,470);
	setbkcolor(BLACK);
	setcolor(WHITE);
	clrscr();
	char ans;
	fstream f;
	char name[20];
	char author[20];
	char a[10];
	char buffer[100];
	int i,j;
	book b1[40];
	f.open("book.txt",ios::in);
	cout<<"\n";
	cout<<" Enter book name whose record to be modified  :";
	cin>>name;
	i=0;
	while(!f.eof())
	{
	 f.getline(b1[i].name,20,'|');
	 f.getline(b1[i].author,20,'|');
	 f.getline(b1[i].a,10,'\n');
	 i++;
	}
	i--;

	for(j=0;j<=i;j++)
	{
	  if(strcmp(name,b1[j].name)==0)
	  {
		cout<<"\n        Name     :"<<b1[j].name;
		cout<<"\n        Author   :"<<b1[j].author;
		cout<<"\n        Copies   :" <<b1[j].a;

		cout<<"\n\n                 Enter New Values" ;
		cout<<"\n\n        Enter the book name  :";
		cin>>b1[j].name;
		cout<<"\n        Enter author name    :";
		cin>>b1[j].author;
		cout<<"\n        Enter no.of copies  :";
		cin>>b1[j].a;
		break;
	   }
	 }
	f.close();
	f.open("book.txt",ios::out);
	for(j=0;j<i;j++)
	{
	  strcpy(buffer,b1[j].name);
	strcat(buffer,"|");
	strcat(buffer,b1[j].author);
	strcat(buffer,"|");
	strcat(buffer,b1[j].a);
	strcat(buffer,"\n");
	f<<buffer;
	}
	f.close();
	settextstyle(7,0,1);
	outtextxy(250,410,"Do You Want To Continue:(Y/N)");
	ans=getchar();
	if(ans=='Y'||ans=='y')
	{
	    goto z;
	}
	else
	    break;
    }

//*******************************************************
//      CASE       : 5
//      DETAILS    : TO DELETE A BOOK'S RECORD
//*******************************************************

    case 5:
    {
	clearviewport();
	rectangle(10,10,630,470);
	setbkcolor(BLUE);
	setcolor(WHITE);
	char name[20];
	char author[20];
	char a[10];
	char buffer[100];
	f.close();
	settextstyle(7,0,3);
	outtextxy(200,30,"DELETING:-");
	cout<<"\n\n\n\n\n\n    Enter the name of the book you want to delete:\t";
	cin>>name;
	ifstream f("book.txt",ios::in);
	ofstream f1("book2.txt",ios::out);
	while(!f.eof())
	{
	 f.getline(b1.name,20,'|');
	 f.getline(b1.author,20,'|');
	 f.getline(b1.a,10,'\n');
	 if(strcmp(b1.name,name)!=0)
	 {
	  strcpy(b1.buffer,b1.name);
	strcat(b1.buffer,"|");
	strcat(b1.buffer,b1.author);
	strcat(b1.buffer,"|");
	strcat(b1.buffer,b1.a);
	strcat(b1.buffer,"\n");
	f1<<b1.buffer;
	 }
	}
	f.close();
	f1.close();
	remove ("book.txt");
	rename ("book2.txt","book.txt");
	cout<<"\n\n\n\n\n\tPress Any Key...";
	getch();
	goto z;
    }

//*******************************************************
//      CASE       : 6
//      DETAILS    : TO EXIT
//*******************************************************

    case 6:
    {
	clearviewport();
	rectangle(10,10,630,470);
	setbkcolor(BROWN);
	setcolor(BLUE);
	settextstyle(8,0,4);
	outtextxy(100,200,"YOU'RE ABOUT TO LEAVE!");
	if(getch())
	{
	    fflush(stdin);
	    clearviewport();
	    rectangle(10,10,630,470);
	    setbkcolor(LIGHTBLUE);
	    setcolor(RED);
	    window(10,10,40,11);
	    settextstyle(8,0,4);
	    outtextxy(120,200,"\"THANKS FOR VISITING\"");
	    getch();
	    closegraph();
	    exit(1);
	}
	else
	{
	    goto z;
	}
    }
    default:
	goto z;
    }
}
