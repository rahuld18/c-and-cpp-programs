

#include<dos.h>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>

#define N 500

int function[35];
int strobe[5] = { 0,0,0,0,0 };
int store[16] = { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 };
int inputs[16];
int output=0,count=0,decieq,choice;

int driver=DETECT,mode;

/***********FUNCTIONS FOR  BEGINING GUI***************/

struct stars
{

	int x,y,x1,y1,z,c;

}STARS[N];

void init()
{

	int i,t;

	for(i=0;i<N;i++)
	{

	STARS[i].c=2;
	STARS[i].x = random(640);
	STARS[i].y = random(460);
	STARS[i].x1= random(320);
	STARS[i].y1= random(220);

	t=random(325);
	if(t==0)
	STARS[i].z=t+random(25)+1;//TO AVOID ERROR(division by 0)

	else
	STARS[i].z=t;

	}

}

void draw()
{

	int i;

	for(i=0;i<N;i++)
	{

	if(STARS[i].y<480)
	putpixel(STARS[i].x,STARS[i].y,STARS[i].c);
	}

}

void erase()
{

	int i;

	for(i=0;i<N;i++)
	putpixel(STARS[i].x,STARS[i].y,0);  //putting black
	    //color at stars position

}
	/* if you use z+=2 stars will go away from you , but remember to
	change the condition :-
	if(STARS[i].z<1) {STARS[i].z=325;}
	to if(STARS[i].z>325) {STARS[i].z=1;} */
void move()
{

	int i;
	for(i=0;i<N;i++)
	{

	STARS[i].x=((STARS[i].x1 * 640)/STARS[i].z)+320;//320 x-origin
	STARS[i].y=((STARS[i].y1 * 300)/STARS[i].z) +220;//220 y-origin
	STARS[i].z-=2;

	if(STARS[i].z<1)
	STARS[i].z=325;

	else if(STARS[i].z<162)
	STARS[i].c=15;

	else STARS[i].c=7;

	}

}

void showstars()
{

	int i;

	init();
	while(!kbhit())
	{

	setcolor(3);  //3 for cyan
	settextstyle(1,0,3);
	outtextxy(230,5,"PROJECT ON");
	settextstyle(10,0,3);
	setcolor(i);
	outtextxy(170,30,"MULTIPLEXERS");

	setcolor(5);
	settextstyle(1,0,3);
	move();
	draw();
	delay(15);
	erase();
	i++;

	}

	closegraph();
	restorecrtmode();

}

void welcome()
{

	int i, j, x, y, color;
	int MaxColors;
	struct palettetype palette;
	struct viewporttype vp;
	int height, width;

	initgraph(&driver,&mode,"f:\tc\bgi");

	MaxColors = getmaxcolor() + 1;

	textcolor(4+BLINK);
	printf("
				  WELCOME");
	textcolor(15);

	getpalette( &palette );
	setviewport(0,50,630,470,1);
	getviewsettings( &vp );

	width  = (vp.right - vp.left) / 15;	//width
	height = (vp.bottom - vp.top) / 10;	// height

	x = y = 0;	// Start in upper corner
	color = 1;	// Begin at 1st color

	for( j=0 ; j<10 ; ++j )
	{	// 10 rows of boxes

	for( i=0 ; i<15 ; ++i )
	{	// 15 columns

	setfillstyle( SOLID_FILL, color++ );//Set the color
	bar( x, y, x+width, y+height );	    // Draw the box
	x += width + 1;	      // Advance to next col
	color = 1 + (color % (MaxColors - 2));// Set new color
	}	// End of i loop

	x = 0;	// Goto 1st column
	y += height + 1;	// Goto next row

	}	// End of j loop

	while( !kbhit() )	// Until a key is hit
	setpalette( 1+random(MaxColors - 2), random( 65 ) );


	setallpalette( &palette );
	getch();
	closegraph();
	restorecrtmode();
	initgraph(&driver,&mode,"f:\tc\bgi");
	showstars();

}

/*********Begining GUI ends.Text mode begins*********/

/**************MULTIPLEXER FUNCTIONS*****************/

void message(int num)  //gives a message to user
{                      //everytime select input is entered

printf("
Only first %d select inputs considered.rest rejected(if any)

",num);

}

int check(int num) //For checking that a particular no.
{                       //is present in function or not

	int ctr2;

	for(ctr2=0;ctr2<count;ctr2++)
	if(function[ctr2]==num)
	return (1);    //true

	return(0);                     //false

}

void check_invalid_strobe(int ctr2)   //for checking invalid select
input
{

	if(strobe[ctr2]>1 || strobe[ctr2]<0)
	{

	printf("
Invalid select input");
	exit(2);

	}

}

void decide_output(int count)   //decides whether output is 1 or 0
{                                  //for normal mux implementation

	int ctr2;

	for(ctr2=0;ctr2<count;ctr2++)
	{

	if(decieq==function[ctr2])
	{

	output = 1;
	break;

	}

	}

}

void decide_complex_inputs(int num)   //decides inputs of a Mux which
{                                     //implements a function of a
higher
	      //level Mux
	int ctr2;

	for(ctr2=0;ctr2<num;ctr2++)
	{

	if(check(ctr2))
	{

	if(check(ctr2+num))
	inputs[ctr2]=1;

	else
	{

	inputs[ctr2]=!(strobe[0]);
	store[ctr2] = 0;

	}

	}

	else
	{

	if(check(ctr2+num))
	{

	inputs[ctr2]=strobe[0];
	store[ctr2] = 1;

	}

	else
	inputs[ctr2]=0;

	}

	}

}

void display_complex_input(int num) //displays inputs of a Mux which
{                                    //implements a function of a
higher
	     //level Mux
	int i;

	for(i=0;i<num;i++)
	{

	if(store[i]==0)
	printf("
Input %d = %s(%d)",i,"a bar",inputs[i]);

	else if(store[i]==1)
	printf("
Input %d = %c(%d)",i,'a',inputs[i]);

	else
	printf("
Input %d = %d",i,inputs[i]);

	}

}

void take_input(int num)    //for taking select input in normal Mux
{

	int ctr2;

	printf("
Enter the select input: ");
	for(ctr2=0;ctr2<num;ctr2++)
	{

	scanf("%d",&strobe[ctr2]);
	check_invalid_strobe(ctr2);

	}

}

void take_input_a(int num)  //for taking input a in case of complex
{                             //implementation of a function

	printf("
Enter the value of a(MSB of select input for %d:1) : ",num);
	scanf("%d",&strobe[0]);
	check_invalid_strobe(0);
	printf("
Only one value of MSB considered.rest rejected(if any)
");

}

void take_complex_select_input(int num)
{

	int ctr2;

	printf("
Enter the select input: ");
	for(ctr2=1;ctr2<num;ctr2++)
	{

	scanf("%d",&strobe[ctr2]);
	check_invalid_strobe(ctr2);

	}
	printf("

Only first %d select inputs considered.rest rejected(if
any)",num-1);
	printf("

Press any key to continue....");
	getch();

}

void display_output()
{

	printf("
Output is : %d",output);
	printf("
Input %d is selected as output.",decieq);
	printf("

Press any key to continue.....");
	getch();

}

void display_complex_output()
{

	output = inputs[decieq];
	printf("

Output is: %d",output);
	printf("
Input %d is selected as output.",decieq);
	printf("

Press any key to continue....");
	getch();

}

void two_is_to_one()
{

	take_input(1);
	message(1);

	decieq = strobe[0]*1;

	decide_output(count);
	display_output();

}

void four_is_to_one()
{

	int ctr2;

	take_input(2);
	message(2);

	decieq =  strobe[0]*2 + strobe[1]*1;

	decide_output(count);
	display_output();

}

void eight_is_to_one()
{

	int ctr2;

	take_input(3);
	message(3);

	decieq = strobe[0]*4 + strobe[1]*2 + strobe[2]*1;

	decide_output(count);
	display_output();

}

void sixteen_is_to_one()
{

	int ctr2;

	take_input(4);
	message(4);

	decieq = strobe[0]*8 + strobe[1]*4 + strobe[2]*2 + strobe[3]*1;

	decide_output(count);
	display_output();

}

void thirtytwo_is_to_one()
{

	int ctr2;

	take_input(5);
	message(5);

	decieq = strobe[0]*16 + strobe[1]*8 + strobe[2]*4 + strobe[3]*2 +
strobe[4]*1;

	decide_output(count);
	display_output();

}

void complex_two_is_to_one()
{

	int ctr2;

	take_input_a(4);
	take_complex_select_input(2);
	message(1);
	decide_complex_inputs(2);

	decieq = strobe[1]*1;

	clrscr();
	display_complex_input(2);
	display_complex_output();

}

void complex_four_is_to_one()
{

	int ctr2;

	take_input_a(8);
	take_complex_select_input(3);
	message(2);
	decide_complex_inputs(4);

	decieq = strobe[1]*2 + strobe[2]*1;

	clrscr();
	display_complex_input(4);
	display_complex_output();

}

void complex_eight_is_to_one()
{

	int ctr2;

	take_input_a(16);
	take_complex_select_input(4);
	message(3);
	decide_complex_inputs(8);

	decieq = strobe[1]*4 + strobe[2]*2 + strobe[3]*1;

	clrscr();
	display_complex_input(8);
	display_complex_output();

}

void complex_sixteen_is_to_one()
{

	int ctr2;
	take_input_a(32);
	take_complex_select_input(5);
	message(4);
	decide_complex_inputs(16);

	decieq = strobe[1]*8 + strobe[2]*4 + strobe[3]*2 + strobe[4]*1;

	clrscr();
	display_complex_input(16);
	display_complex_output();

}

/**********MULTIPLEXING FUNCTIONS END*******************/

/****************CIRCUIT GUI****************************/


void common_gui(int num)
{

	int y[32],i,i2,k;
	double j=log(num)/log(2);
	char str[2];
	int stepsize=((280+num*3)-180)/(j+1);

	for(i=0;i<32;i++)
	y[i]=80 + (i+1)*10;

	initgraph(&driver,&mode,"f:\tc\bgi");

	outtextxy(20,5,"RED: logic level 1");
	outtextxy(250,5,"Press any key to continue.....");
	outtextxy(20,15,"GREEN:logic level 0");

	for(i=0;i<num;i++)
	{

	if(check(i))
	{

	setcolor(WHITE);
	circle(150,y[i],2);
	setfillstyle(SOLID_FILL,RED);
	floodfill(150,y[i],WHITE);

	}

	else
	{

	setcolor(15);
	circle(150,y[i],2);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(150,y[i],WHITE);

	}

	line(154,y[i],180,y[i]);

	}

	rectangle(180,40,280+num*3,y[i-1]+40);
	line(280+num*3,(y[i-1]-40)/2 + 60,280+3*num+40,(y[i-1]-40)/2 + 60);

	if(output==1)
	{

	setcolor(15);
	circle(280+num*3+44,(y[i-1]-40)/2 + 60,4);
	setfillstyle(SOLID_FILL,RED);
	floodfill(280+num*3+44,(y[i-1]-40)/2 + 60,WHITE);

	}

	else
	{

	setcolor(15);
	circle(280+num*3+44,(y[i-1]-40)/2 + 60,4);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(280+num*3+44,(y[i-1]-40)/2 +60,WHITE);

	}
	outtextxy(280+num*3+50,(y[i-1]-40)/2 + 60," Y(Output =   )");
	itoa(output,str,10);
	outtextxy(280+num*3+150,(y[i-1]-40)/2 + 60,str);
	itoa(num,str,10);

	outtextxy(140,y[i-1]+72,"  Block Diagram of ");
	outtextxy(290,y[i-1]+72,str);
	outtextxy(293,y[i-1]+72,"  : 1 Mux");

	outtextxy((280+num*3-180)/2 + 150,y[(i-1)/2],str);
	outtextxy((280+num*3-180)/2 + 160,y[(i-1)/2],"  : 1");
	outtextxy((280+num*3-180)/2 + 150,y[(i-1)/2+2],"  MUX");

	outtextxy(280+num*3+170,(y[i-1]-40)/2 + 60,"(I ");
	itoa(decieq,str,10);
	outtextxy(280+num*3+185,(y[i-1]-40)/2 + 60,str);
	outtextxy(280+num*3+192,(y[i-1]-40)/2 + 60," )");

	outtextxy(130,y[0]-5,"I0");
	itoa(num-1,str,10);
	outtextxy(126,y[i-1],"I");
	outtextxy(133,y[i-1],str);

	for(i2=0;i2<j;i2++)
	for(k=0;k<20;k++)
	{
	line(180+(i2+1)*stepsize,y[i-1]+40,180+(i2+1)*stepsize,y[i-1]+60);
	if(strobe[i2]==0)
	{

	setcolor(15);
	circle(180+(i2+1)*stepsize,y[i-1]+62,2);
	setfillstyle(SOLID_FILL,2);
	floodfill(180+(i2+1)*stepsize,y[i-1]+62,15);

	}

	else
	{

	setcolor(15);
	circle(180+(i2+1)*stepsize,y[i-1]+62,2);
	setfillstyle(SOLID_FILL,4);
	floodfill(180+(i2+1)*stepsize,y[i-1]+62,15);

	}

	}

	outtextxy(185+(i2)*stepsize,y[i-1]+62,"S0");
	itoa(j-1,str,10);
	outtextxy(162+stepsize,y[i-1]+62,"S ");
	outtextxy(170+stepsize,y[i-1]+62,str);

	if(num==2)
	{
	setcolor(0);
	outtextxy(162+stepsize,y[i-1]+62,"S0");
	setcolor(15);

	}

	getch();

}

void common_complex_gui(int num)
{

	int y[32],i,i2,k;
	double j=log(num)/log(2);
	char str[2];
	int stepsize=((280+num*3)-180)/(j+1);

	for(i=0;i<32;i++)
	y[i]=80 + (i+1)*10;

	initgraph(&driver,&mode,"f:\tc\bgi");

	outtextxy(20,5,"RED: logic level 1");
	outtextxy(250,5,"Press anu key to continue.....");
	outtextxy(20,15,"GREEN:logic level zero");

	for(i=0;i<num;i++)
	{

	if(inputs[i]==1)
	{

	setcolor(WHITE);
	circle(150,y[i],2);
	setfillstyle(SOLID_FILL,RED);
	floodfill(150,y[i],WHITE);

	}

	else
	{

	setcolor(15);
	circle(150,y[i],2);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(150,y[i],WHITE);

	}

	line(154,y[i],180,y[i]);

	}

	rectangle(180,40,280+num*3,y[i-1]+40);
	line(280+num*3,(y[i-1]-40)/2 + 60,280+3*num+40,(y[i-1]-40)/2 + 60);

	if(output==1)
	{

	setcolor(15);
	circle(280+num*3+44,(y[i-1]-40)/2 + 60,4);
	setfillstyle(SOLID_FILL,RED);
	floodfill(280+num*3+44,(y[i-1]-40)/2 + 60,WHITE);

	}

	else
	{

	setcolor(15);
	circle(280+num*3+44,(y[i-1]-40)/2 + 60,4);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(280+num*3+44,(y[i-1]-40)/2 +60,WHITE);

	}

	outtextxy(280+num*3+50,(y[i-1]-40)/2 + 60," Y(Output =   )");
	itoa(output,str,10);
	outtextxy(280+num*3+150,(y[i-1]-40)/2 + 60,str);
	itoa(num,str,10);

	outtextxy(140,y[i-1]+72,"  Block Diagram of ");
	outtextxy(290,y[i-1]+72,str);
	outtextxy(293,y[i-1]+72,"  : 1 Mux");

	outtextxy((280+num*3-180)/2 + 150,y[(i-1)/2],str);
	outtextxy((280+num*3-180)/2 + 160,y[(i-1)/2],"  : 1");
	outtextxy((280+num*3-180)/2 + 150,y[(i-1)/2+2],"  MUX");

	outtextxy(280+num*3+170,(y[i-1]-40)/2 + 60,"(I ");
	itoa(decieq,str,10);
	outtextxy(280+num*3+185,(y[i-1]-40)/2 + 60,str);
	outtextxy(280+num*3+192,(y[i-1]-40)/2 + 60," )");

	outtextxy(130,y[0]-5,"I0");
	itoa(num-1,str,10);
	outtextxy(126,y[i-1],"I");
	outtextxy(133,y[i-1],str);

	for(i2=1;i2<=j;i2++)
	for(k=0;k<20;k++)
	{
	line(180+(i2)*stepsize,y[i-1]+40,180+(i2)*stepsize,y[i-1]+60);
	if(strobe[i2]==0)
	{

	setcolor(15);
	circle(180+(i2)*stepsize,y[i-1]+62,2);
	setfillstyle(SOLID_FILL,2);
	floodfill(180+(i2)*stepsize,y[i-1]+62,15);

	}

	else
	{

	setcolor(15);
	circle(180+(i2)*stepsize,y[i-1]+62,2);
	setfillstyle(SOLID_FILL,4);
	floodfill(180+(i2)*stepsize,y[i-1]+62,15);

	}

	}

	outtextxy(185+(i2-1)*stepsize,y[i-1]+62,"S0");
	itoa(j-1,str,10);
	outtextxy(162+stepsize,y[i-1]+62,"S ");
	outtextxy(170+stepsize,y[i-1]+62,str);

	if(num==2)
	{
	setcolor(0);
	outtextxy(162+stepsize,y[i-1]+62,"S0");
	setcolor(15);

	}

	getch();

}

/************CIRCUIT GUI ENDS**********************/

/********************MAIN FUNCTION*****************/

void main()
{

	int ctr=0;

	welcome();

clrscr();
printf("
Prog to implement a function using a multiplexer logic:-");

printf("

Enter the function in minterms only.");
printf("
Enter the function in form a b c d where a<b<c<d.");
printf("
Press enter or provide spaces after each input.");
printf("
Any value in input function cannot be repeated.");
printf("
Enter the select input in form of 1's & 0's.");
printf("
All the entered inputs are assumed to be high.");
printf("
Maximun value of the minterm that can be accepted :31




");

	textcolor(4+BLINK);
	textbackground(3);
	cprintf("Press any key to continue.......");
	textcolor(15);
	textbackground(0);

	getch();
	printf("

How many input will you provide: ");
	scanf("%d",&count);

	if(count>32)
	{

	printf("
Invalid function input.inputs can't be greater than 32");
	exit(1);

	}

	clrscr();
	printf("Enter the function to be implemented :	");
	for(ctr=0;ctr<count;ctr++)
	{

	scanf("%d",&function[ctr]);

	if(function[ctr]>31)
	{

	printf("
Invalid function input");
	exit(1);

	}

	}

	printf("
Only first %d inputs considered.rest rejected(if any)",count);

	fflush(stdin);

	if(function[count-1] <= 1)
	{
	two_is_to_one();
	common_gui(2);

	}

	else if(function[count-1] <= 3)
	{

	label1:

	printf("

Implement using:-
1.)4:1 Mux
2.)2:1 Mux
Enter your choice?");
	scanf("%d",&choice);

	switch(choice)
	{

	case 1:	four_is_to_one();
	common_gui(4);
	break;

	case 2:	complex_two_is_to_one();
	common_complex_gui(2);
	break;

	default : printf("
Invalid choice");
	  goto label1;

	}

	}

	else if(function[count-1] <= 7)
	{

	label2:

	printf("

Implement using:-
1.)8:1 Mux
2.)4:1 Mux
Enter your choice?");
	scanf("%d",&choice);

	switch(choice)
	{

	case 1:	eight_is_to_one();
	common_gui(8);
	break;

	case 2:	complex_four_is_to_one();
	common_complex_gui(4);
	break;

	default : printf("
Invalid choice");
	  goto label2;

	}

	}

	else if(function[count-1] <= 15)
	{

	label3:

	printf("

Implement using:-
1.)16:1 Mux
2.)8:1 Mux
Enter your choice?");
	scanf("%d",&choice);

	switch(choice)
	{

	case 1:	sixteen_is_to_one();
	common_gui(16);
	break;

	case 2:	complex_eight_is_to_one();
	common_complex_gui(8);
	break;

	default : printf("
Invalid choice");
	  goto label3;

	}

	}

	else if(function[count-1] <= 31)
	{

	label4:

	printf("

Implement using:-
1.)32:1 Mux
2.)16:1 Mux
Enter your choice?");
	scanf("%d",&choice);

	switch(choice)
	{

	case 1:	thirtytwo_is_to_one();
	common_gui(32);
	break;

	case 2:	complex_sixteen_is_to_one();
	common_complex_gui(16);
	break;

	default : printf("
Invalid choice");
	  goto label4;

	}

	}

	getch();

