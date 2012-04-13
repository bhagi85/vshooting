// author: BHAGIRATH BHARDWAJ
// date  : 6/01/2011
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
//#include<devil.h>
char *menu[]= {"GAME","OPTION","DIRECT-X","E-FACTOR","QUIT"};
char *file[]={"PLAY_GAME","DESIGN GAME","LOAD STAGE","PROGRAMMER","SOURCECODE"};
char *dir[]={"make_dir","change_dir","remove_dir","list_dir","display_tree"};
char *stud[]={"enter record","show record","enter mark's","result","modify record"};
char *emp_r[]={"enter record","show record","pay roll","modify record"};
int count[]={4,5,5,5,4};
int ascii,scan;
int   stage_x[10][1000];
int   stage_y[10][1000];

void set_mod(void)
 { int driver=DETECT,mode;
   initgraph(& driver,& mode,"c:\\tc\\bgi");
  }
void getkey(void)
{ union REGS ii,oo;
  while(!kbhit())
     { }
    ii.h.ah=0;
    int86(22,&ii,&oo);
    scan=oo.h.ah;
    ascii=oo.h.al;
   }
void start(void)
 { clrscr();

  int i,x1=100,x2=300, y1=30,j,y2;

  for(i=1;i<=120;i++)
   {  setcolor(15);
    cleardevice();
    line(x1,y1,x2,y1);
    y1=y1+3;
    x1=x1+3;
    delay(60);
    }
     x1=100,x2=300, y1=30;
    setcolor(15);
  for(i=1;i<=120;i++)
   { //setcolor(random(15));
    line(x1,y1,x2,y1);
    y1=y1+3;
    x1=x1+3;
    delay(35);
    }
    x1=100,x2=100, y1=40,y2=100;
   setcolor(1);
   for(i=1;i<=120;i++)
    { line(x1,y1,x2,y1);
     y1=y1+3;
     x1=x1+3;
     delay(50);
     }
   x1=310,x2=500, y1=30,y2;
   setcolor(5);
   for(i=1;i<=60;i++)
    { line(x1,y1,x2,y1);
     y1=y1+3;
     // x1=x1+1;
     delay(25);
     }
   setcolor(15);
   gotoxy(310,95);
   delay(50);
   rectangle(310,200,500,230);
   outtextxy(330,205,"BHAGIRATH BHARDWAJ's");
   delay(45);
   outtextxy(330,220,"virtual fighter");
   setcolor(0);
   rectangle(100,400,300,430);
   setcolor(15);
   outtextxy(110,410,"press any key to continue..... ");
   getch();
   cleardevice();
   //closegraph();
  }

void mainscrean(char **manu,int count)
  { //setbkcolor(5);
    int i,x1=5,x2=650, y1=2;
   // clrscr();
   // cleardevice();
    setcolor(8);
    for(i=1;i<=35;i++)
     { if(i==5)
       {setcolor(1);
	}
       line(x1,y1,x2,y1);
       y1=y1+1;

      if(i==30)
       {setcolor(8);
       }
      }
     x1=4,y1=2;
   for(i=1;i<=count;i++)
    { gotoxy(x1,y1);
     cout<<*manu;
     int n=strlen(*manu);
     x1=x1+n+3;
     **manu++;
      }
  }
int pop_up(char **manu,int x,int y,int num)
 { int i,step=1,y1;
   y1=y;
   setcolor(7);
 for(i=1;i<=num;i++)
 {  setcolor(7);
    rectangle(x,y1,x+120,y1+20);
    rectangle(x+1,y1+1,x+119,y1+19);
    setcolor(2);
     //gotoxy(x+20,y1+5);
    // cout<<*manu;
     outtextxy(x+20,y1+5,*manu);
     y1=y1+20;
    **manu++;
    }

  setcolor(1);
  rectangle(x+3,y+3,x+120-3,y+20-3);
  rectangle(x+4,y+4,x+120-4,y+20-4);
  while(1)
  {
    getkey();
   if(ascii==0)
    {switch(scan)
     {case 80:
       if(step==num)
	 {//step=0;
	  // y=y-20*(num-1);
	  break;
	   }
	else
	{ setcolor(0);
	 rectangle(x+3,y+3,x+120-3,y+20-3);
	 rectangle(x+4,y+4,x+120-4,y+20-4);
	 setcolor(1);
	 y=y+20;
	 rectangle(x+3,y+3,x+120-3,y+20-3);
	 rectangle(x+4,y+4,x+120-4,y+20-4);
	 step++;
	 break;
	 }
      case 72:
	if(step==1)
	 {//step=num+1;
	 // y=y+20*(num-1);
	   break;
	   }
	else
	{ setcolor(0);
	 rectangle(x+3,y+3,x+120-3,y+20-3);
	 rectangle(x+4,y+4,x+120-4,y+20-4);
	 y=y-20;
	 setcolor(1);
	 rectangle(x+3,y+3,x+120-3,y+20-3);
	 rectangle(x+4,y+4,x+120-4,y+20-4);
	 step--;
	 break;
	 }
	};
      }
     else
       {if(ascii==13)
	 { return(step);
	   }
	}
      }
}
void gun(int x, int y)
{  setcolor(1);
   line(x,y+150,300,550);
   line(x+1,y+150,300,550);
   line(x+2,y+150,300,550);
   line(x+3,y+150,300,550);
}
void point(int x,int y)
{ int i;
   cleardevice();
   setcolor(1);
   gun(x,y);
   //setfillstyle(i, getmaxcolor());
   //bar3d(300,500,x,y,5, 3);
    line(x-15,y,x-5,y);
    line(x+5,y,x+15,y);
    line(x,y-15,x,y-5);
    line(x,y+5,x,y+15);
    setcolor(2);
    line(x-18,y-18,x-18,y+18);
    line(x+18,y-18,x+18,y+18);
     for(i=1;i<=10;i++)
     { putpixel(x-18+i,y-18,5);
       putpixel(x-18+i,y+18,5);
       putpixel(x+18-i,y-18,5);
       putpixel(x+18-i,y+18,5);
       delay(3);
      }
   }
void point1(int x,int y)
{ int i;
    setcolor(1);
    line(x-15,y,x-5,y);
    line(x+5,y,x+15,y);
    line(x,y-15,x,y-5);
    line(x,y+5,x,y+15);
    setcolor(2);
    line(x-18,y-18,x-18,y+18);
    line(x+18,y-18,x+18,y+18);
     for(i=1;i<=10;i++)
     { putpixel(x-18+i,y-18,5);
       putpixel(x-18+i,y+18,5);
       putpixel(x+18-i,y-18,5);
       putpixel(x+18-i,y+18,5);
       delay(3);
      }
   }

void fire(int x , int y)
{ setcolor(5);
  for(int i=0;i<150;i++)
  { cleardevice();
    circle(x,y+150-i,4);
    circle(x,y+150-i,3);
    circle(x,y+150-i,2);
    delay(1);
  }

 }
int shoot(void)
 { int i,step=1,y=300,x=300,y1;
   cleardevice();
   point(x,y);
while(1)
  {
    getkey();
    if(ascii==0)
    {switch(scan)
     {case 80:
	 y=y+6;
	 point(x,y);
	break;

      case 72:
	 y=y-6;
	 point(x,y);

	 break;
       case 75:
	  x=x-6;
	 point(x,y);
       break;

       case 77:
	  x=x+6;
	 point(x,y);
       break;

	};
      }
     else
       {if(ascii==27)
	 { return(0);
	   }
	if(ascii==32)
	{fire(x,y);
	 point(x,y);
	 }
	}
      }
}
int shoot_build(void)
 { int i,step=1,y=300,x=300,y1;
   cleardevice();
   point(x,y);
while(1)
  {
    getkey();
    if(ascii==0)
    {switch(scan)
     {case 80:
	 y=y+6;
	 point1(x,y);
	break;

      case 72:
	 y=y-6;
	 point1(x,y);

	 break;
       case 75:
	  x=x-6;
	 point1(x,y);
       break;

       case 77:
	  x=x+6;
	 point1(x,y);
       break;

	};
      }
     else
       {if(ascii==27)
	 { return(0);
	   }

	}
      }
}


int stage_design(void)
 {int i=0,j=0,y=300,x=300,y1;
  stage_x[i][j]=300;
 stage_y[i][j]=300;
 point(x,y);
while(1)
  {
    getkey();
   if(ascii==0)
    {switch(scan)
     {case 80:
	 y=y+6;
	 point(x,y);
	stage_x[i][j]=x;
	stage_y[i][j]=y;
	j++;
	break;

      case 72:
	 y=y-6;
	 point(x,y);
	stage_x[i][j]=x;
	stage_y[i][j]=y;
	j++;

	 break;
       case 75:
	  x=x-6;
	 point(x,y);
	stage_x[i][j]=x;
	stage_y[i][j]=y;
	j++;

       break;

	 case 77:
	  x=x+6;
	 point(x,y);
	stage_x[i][j]=x;
	stage_y[i][j]=y;
	j++;

       break;

	};
      }
     else
       {if(ascii==13)
	 {  stage_x[i][j]=32000;
	    stage_y[i][j]=32000;

	   return(0);
	   }
	}
      }
}

void target(int a,int b)
{ setcolor(4);
  circle(a,b,30);
  circle(a,b,28);
  circle(a,b,26);
  circle(a,b,24);

}
void stage_load()
{ int i=0,j=0,x,y;
 while((stage_x[i][j]!=32000)||(stage_y[i][j]!=32000))
 {  x=stage_x[i][j];
    y=stage_y[i][j];
    point(x,y);

   if(stage_x[i][j]%10==0)
   { target(stage_x[i][j],stage_y[i][j]);
    }
   j++;
   }
 //  shoot();

}
void gserver(int ch)
{ switch(ch)
  {case 1:
      shoot();
      break;
   case 2:
     shoot_build();
     break;
   case 3:
     cleardevice();
     stage_load();
    break;
   };

  }

main()
{clrscr();
  int choice;
  char ch;
  set_mod();
  start();
  //set_mod();
  while(1)
 { cleardevice();
   //bh_devil();
  mainscrean(menu,5);
  ch=getche();
 switch(ch)
  {case 'g':
     choice=pop_up(file,20,40,count[1]);
     gserver(choice);
     break;
   case 'o':
    choice=pop_up(dir,80,40,count[2]);
    // dserver(choice);
    break;
   case 'd':
    choice=pop_up(stud,150,40,count[3]);
  //   sserver(choice);
     break;
   case 'e':
      choice=pop_up(emp_r,240,40,count[4]);
   //  eserver(choice);
    break;
  case 'q':
  return 0;


  // getch();
    };
  // last();
   }

 }
