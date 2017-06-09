#include <stdio.h>
#include <conio.h>
#include <windows.h> 
#include <stdlib.h>
#include <time.h>
int rad(int min_num, int max_num)
    {
        int result=0,low_num=0,hi_num=0;
        if(min_num<max_num)
        {
            low_num=min_num;
            hi_num=max_num+1;
        }
		else
		{
            low_num=max_num+1;
            hi_num=min_num;
        }
        srand(time(NULL));
        result = (rand()%(hi_num-low_num))+low_num;
        return result;
    }
void gotoxy(int x, int y)
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void vc(int dai, int cot)
{
	for (int i=1; i<=dai; i++)
	{
		gotoxy(cot,i);
		if (i!=dai) printf("|   |");
		else
		{
			gotoxy(cot+1,i-1);
			printf("___");
		}
	}
	for (int i=19; i>=dai+5; i--)
	{
		gotoxy(cot,i);
		if (i!=dai+5) printf("|   |");
		else
		{
			gotoxy(cot+1,i);
			printf("___");
		}
	}
	gotoxy(cot+1,19);
	printf("___");
}
int main()
{
	system("cls");
	int i, dcao, test = 0, cot1, dai1, cot2 = 0, dai2 = 0, cot3 = 0, dai3 = 0, ctrl = 1, a, dem = 1, check = 0, diem = 0;
	gotoxy(21,0);
	for (i=20 ; i<=59 ; i++)
		{
			printf("_");
		}
	gotoxy(20,1);
	for (i=1 ; i<=18 ; i++)
		{
			gotoxy(20,i);
			printf("|\n");
		}
	gotoxy(20,19);
	printf("|");
	gotoxy(21,19);
	for (i=20 ; i<=59 ; i++)
		{
			printf("_");
		}
	gotoxy(62,1);
	for (i=1 ; i<=19 ; i++)
		{
			gotoxy(61,i);
			printf("|");
		}
	gotoxy(32,8);
	printf("OO");
	gotoxy(32,4);
	printf("GET READY!");
	vc(7,50);
	dcao = 8;
	cot1 = 50;
	dai1 = 7;
	a = rad(2,26);
	getch();
	do
	{
		
		a = a*3 + dem;
		if (a>=100) a = a - 100;
		a = a%10 + 3;
		if (a>13) a = a - 9;
		dem++;
		
		system("cls");
		
		gotoxy(21,0);
		for (i=20 ; i<=59 ; i++)
		{
			printf("_");
		}
		gotoxy(20,1);
		for (i=1 ; i<=18 ; i++)
		{
			gotoxy(20,i);
			printf("|\n");
		}
		gotoxy(20,19);
		printf("|");
		gotoxy(21,19);
		for (i=20 ; i<=59 ; i++)
		{
			printf("_");
		}
		gotoxy(62,1);
		for (i=1 ; i<=19 ; i++)
		{
			gotoxy(61,i);
			printf("|");
		}
		
		
//		test = getch();
		if (_kbhit())
		{
			ctrl = 3;
			
		}
		if (ctrl>=1)
		{
			dcao--;
			ctrl--;
		}
		else dcao++;
		cot1--;
		cot2--;
		cot3--;
		if (cot1>=21 && cot1<=56) vc(dai1,cot1);
		if (cot1==39)
		{
			cot2 = 56;
			dai2 = a;
		}
		if (cot2==39)
		{
			cot3 = 56;
			dai3 = a;
		}
		if (cot3==39)
		{
			cot1 = 56;
			dai1 = a;
		}
		if (cot2>=21 && cot2<=56) vc(dai2,cot2);
		if (cot3>=21 && cot3<=56) vc(dai3,cot3);
		gotoxy(32,dcao);
		printf("OO");
		gotoxy(38,22);
		while(kbhit()) getch();
		fflush (stdin) ;
		if (cot1==32 || cot2==32 || cot3==32) diem++;
		printf("Diem: %d", diem);
		Sleep(80);
		if (((dcao<=1||dcao>=19) || ((cot1>=29&&cot1<=33)&&(dcao<=(dai1)||dcao>=(dai1+5))) || ((cot2>=29&&cot2<=33)&&(dcao<=(dai2)||dcao>=(dai2+5))) || ((cot3>=29&&cot3<=33)&&(dcao<=(dai3)||dcao>=(dai3+5)))))
		check = 1;
	}
	while(check==0);
	getch();
	gotoxy(33,23);
	system("cls");
	gotoxy(30,4);
	printf("Diem cua ban la: %d", diem);
	getch();
}
