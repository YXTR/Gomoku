#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "random.h"
#include "strlib.h"
#include "judge.h" 
#include "conio.h"
#include "ai.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>
#include <string.h>

#define width 0.4
#define radius 0.18
#define side   14
#define WelcomeLocx ox + 0.3 * width + hei
#define WelcomeLocy oy + hei - 3.9 * width
#define WelComeSizex wid - hei - 0.6 * width
#define WelComeSizey 3 * width 
#define WelComeWLocx ox + 0.5 * width + hei
#define WelComeWLocy oy + hei - 2.6 * width
#define NobLocx ox + width + hei
#define NobLocy oy + hei - 8 * width
#define NoSizex wid - hei - 2 * width
#define NoSizey 3 * width
#define NoLocx  ox + 2.2 * width + hei
#define NoLocy  oy + hei - 6.7 * width
#define NumLocx  ox + 2.2 * width + hei
#define NumLocy  oy + hei - 6.7 * width
#define NoLocx  ox + 2.2 * width + hei
#define NoLocy  oy + hei - 6.7 * width
#define NumLocx  ox + 2.2 * width + hei
#define NumLocy  oy + hei - 6.7 * width
#define UndoLocx ox + 1 * width + hei
#define UndoLocy oy + 3.3 * width
#define UndoLocyy UndoLocy - 0.3 * width
#define PALocx ox + 3.5 * width + hei
#define PALocy oy + 3 * width
#define PASizex 3.7 * width
#define PASizey width
#define PAWLocx ox + 3.7 * width + hei
#define PAWLocy oy + 3.3 * width
#define BMLocx ox + 1.6 * width + hei
#define BMLocy oy + 1 * width
#define SizeBM 4.75
#define BMWLocx ox + 1.6 * width + hei
#define BMWLocy oy + 1.3 * width

#define PGLocx ox + 0.27 * wid
#define PGLocy oy + 0.4 * hei
#define PGSizex 4.2 * width
#define PGSizey width
#define PGWLocx ox + 0.28 * wid
#define PGWLocy oy + 0.415 * hei
#define PCLocx ox + 0.55 * wid
#define PCLocy oy + 0.4 * hei
#define SizePC 5.25
#define PCWLocx ox + 0.56 * wid
#define PCWLocy oy + 0.415 * hei
#ifndef MAX_STEP
#define MAX_STEP 2
#endif
struct Piece
{
	int x;
	int y;
} bp[1000], wp[1000];
struct StepValue curAIMove;
bool isPlay = FALSE, isMenu = TRUE, withAI = TRUE;
char num[20];
int board[15][15] = {0};
int pintx, pinty;
static double wid, hei; 
int flag = 0, fb = 0, fw = 0;
double osx, osy, ox = 0, oy = 0;
void DrawBox(double x, double y);
void DrawBorder(double x, double y);
void DrawBlackPiece(double x, double y);
void DrawWhitePiece(double x, double y);
void CreateBoard();
void BlackWin();
void WhiteWin();
void Draw();
int JudgeDraw();
int isFull();
void DrawMenu();
double distance(double mx, double my, double x, double y); 
void ClearBoard();
void MouseEventProcess(int x, int y, int button, int event);/*鼠标消息回调函数*/

void Main() /*仅初始化执行一次*/
{
	int i;
    InitGraphics();/*图形初始化*/
    SetWindowTitle("欢迎血虐人工智障");
    SetFont("Comic Sans MS");
	wid = GetWindowWidth(); 
    hei = GetWindowHeight();
    SetPenSize(1);
    DrawMenu();
	registerMouseEvent(MouseEventProcess);/*注册鼠标消息回调函数*/
}

void MouseEventProcess(int x, int y, int button, int event)
{
	double x1, y1, x2, y2, dx, dy, px, py;
	static bool isMove = FALSE; /*移动标志*/
 	static double omx = 0.0, omy = 0.0;/*前一鼠标坐标*/
    double mx, my;/*当前鼠标坐标*/
 	mx = ScaleXInches(x);
	my = ScaleYInches(y);
	osx = hei / 2 - side * 1.0 / 2 * width;
	osy = hei / 2 + side * 1.0 / 2 * width;
	if(!isMenu)
	switch (event) 
	{
		case BUTTON_DOWN:
		{
			{
				CreateBoard();
				if(button ==LEFT_BUTTON)
				{
					px = mx - osx;
					py = osy - my;
					pintx = (int)(px / width + 0.5);
					pinty = (int)(py / width + 0.5);						
					if(isPlay && (px > -width / 2) && (py > -width / 2) && !board[pintx][pinty] && (pintx <= side) && (pinty <= side))
					{
                        flag++;
						if(flag % 2 == 0) 
						{
						    fb++;
						    board[pintx][pinty] = 2;
						    bp[fb].x = pintx;
						    bp[fb].y = pinty;
					    }
						else
						{
						    fw++;
						    board[pintx][pinty] = 1;
						    wp[fw].x = pintx;
						    wp[fw].y = pinty;
					    }
					    CreateBoard();	
					}
					else if (flag > 0 && (mx >= UndoLocx) && (my >= UndoLocyy) && (mx <= UndoLocx + 2 * width) && (my <= UndoLocy + width))
					{
						isPlay = TRUE;
						if(flag % 2 == 0) 
						{
							board[bp[fb].x][bp[fb].y] = 0;
						    fb--;
						}
						else
						{
							board[wp[fw].x][wp[fw].y] = 0;
						    fw--;
						}
						flag--;
						if (withAI == TRUE)
						{
						   if(flag % 2 == 0) 
                        {
							board[bp[fb].x][bp[fb].y] = 0;
						    fb--;
						}
						else
						{
							board[wp[fw].x][wp[fw].y] = 0;
						    fw--;
						}
						flag--;
						}
					    CreateBoard();
					}
					else if (flag > 0 && (mx >= PALocx) && (my >= PALocy) && (mx <= PALocx + PASizex) && (my <= PALocy + PASizey)) ClearBoard();
					else if ((mx >= BMLocx) && (my >= BMLocy) && (mx <= BMLocx + SizeBM * width) && (my <= BMLocy + width))
					{
			   		    ClearBoard();
			   		    DrawMenu();
			   		    isPlay = FALSE;
			   		    isMenu = TRUE;
			   		}
		    	}
		  		MovePen(hei / 2 - 2.2 * width, hei / 2);
		   		if(JudgeDraw() == 3 && isFull() == 1) Draw();
		  		else
		   		{
			    switch(JudgeDraw())
	   			    {
		   			    case 1 :WhiteWin(); break;
		   			    case 2 :BlackWin(); break;
	    		    }
			   	}
			   	if (isPlay == TRUE && withAI == TRUE && flag != 0 && fw > fb)
                {
                    flag++;
                    fb++;
                    curAIMove.value = AIMove(1, MAX_STEP);
					bp[fb].x = curAIMove.i;
					bp[fb].y = curAIMove.j;
                    CreateBoard();
                    
		   		    if(JudgeDraw() == 2) 
                    {
                        MovePen(hei / 2 - 2.2 * width, hei / 2);
                        BlackWin(); 
                    } 
		  		    
                }
		    }
		    break;
		}
		case BUTTON_UP:
		    {
		        break;
		    }
    }
	if(!isPlay && isMenu)
		switch (event) 
    	{
	    	case BUTTON_DOWN:
	    	{
	    		if(button ==LEFT_BUTTON)
	    		{
	    			if ((mx >= PGLocx) && (my >= PGLocy) && (mx <= PGLocx + PGSizex) && (my <= PGLocy + PGSizey))
	    			{
		    	        ClearBoard();
		    	        withAI = FALSE;
		    	    }
		    	    else if ((mx >= PCLocx) && (my >= PCLocy) && (mx <= PCLocx + SizePC * width) && (my <= PCLocy + width))
		    	    {
		    	    	ClearBoard();
		    	    	withAI = TRUE;
					}
		    	}
	        } 
			break;
	    }
}

void DrawBox(double x, double y)
{
	StartFilledRegion(1);
	DrawBorder(x, y);
	EndFilledRegion();
}

void DrawBorder(double x, double y)
{
    DrawLine(x, 0);	
    DrawLine(0, y);	
    DrawLine(-x, 0);
    DrawLine(0, -y);	
} 

void DrawBlackPiece(double x, double y)
{
	MovePen(x + radius, y);
	int i;
	double r = radius;
	SetPenColor("Dark Gray");
	MovePen(x + r, y) ;
	StartFilledRegion(1);
	DrawArc(r, 0, 360);
	EndFilledRegion();
	SetPenColor("Black");
	DrawArc(r, 0, 360);
	SetPenColor("White");
	MovePen(x + 0.6 * r, y + 0.45 * r);
	StartFilledRegion(1);
	DrawArc(0.15 * r, 0, 360);
	EndFilledRegion();
	MovePen(x + 0.5 * r, y + 0.52 * r);
	StartFilledRegion(1);
	DrawArc(0.15 * r, 0, 360);
	EndFilledRegion();
}

void DrawWhitePiece(double x, double y)
{
	MovePen(x + radius, y);
	int i;
	double r = radius;
	SetPenColor("Dark White");
	MovePen(x + r, y) ;
	StartFilledRegion(1);
	DrawArc(r, 0, 360);
	EndFilledRegion();
	SetPenColor("Black");
	DrawArc(r, 0, 360);
	SetPenColor("White");
	MovePen(x + 0.6 * r, y + 0.45 * r);
	StartFilledRegion(1);
	DrawArc(0.15 * r, 0, 360);
	EndFilledRegion();
	MovePen(x + 0.5 * r, y + 0.52 * r);
	StartFilledRegion(1);
	DrawArc(0.15 * r, 0, 360);
	EndFilledRegion();
}

void CreateBoard()
{
	SetPointSize(25);
	SetPenSize(1);
	int i, j;
	double x, y;
	MovePen(ox, oy);
	SetPenColor("Light Yellow");
	DrawBox(hei, hei);
	x = hei / 2 - side * 1.0 / 2 * width;
	y = hei / 2 - side * 1.0 / 2 * width;
	SetPenColor("Black");
	for(i = 0; i < side; i++)
	for(j = 0; j < side; j++)
	{
		MovePen(x + i * width, y + j * width);
		DrawBorder(width, width);
	}
	MovePen(ox + hei, oy);
	SetPenColor("White");
	DrawBox(wid - hei, hei);
	SetPenColor("Black");
	
	MovePen(WelcomeLocx, WelcomeLocy);
	DrawBorder(WelComeSizex, WelComeSizey); 
	MovePen(WelComeWLocx, WelComeWLocy);
	DrawTextString("Welcome to Gomoku");
	
	MovePen(NobLocx, NobLocy);
    DrawBorder(NoSizex, NoSizey); 
   	MovePen(NoLocx, NoLocy); 
	if(flag < pow(side + 1, 2))
	{ 
    	DrawTextString("  No."); 
	
	    MovePen(NumLocx, NumLocy);
	    sprintf(num, "%d", flag + 1);
	    DrawTextString("        ");
	    for(i = 1; i <= 3 - strlen(num); i++)DrawTextString(" ");
    	DrawTextString(num); 
    }
    else
    {
    	MovePen(NoLocx - width, NoLocy); 
    	DrawTextString("The board is full.");
	}
	
	MovePen(UndoLocx, UndoLocyy);
	DrawBorder(2 * width, width);
	MovePen(UndoLocx, UndoLocy);
	DrawTextString(" Undo"); 
	
	MovePen(PALocx, PALocy);
	DrawBorder(PASizex, PASizey);
	MovePen(PAWLocx, PAWLocy);
	DrawTextString("Play Again"); 
	
	MovePen(BMLocx, BMLocy);
	DrawBorder(SizeBM * width, width);
	MovePen(BMWLocx, BMWLocy);
	DrawTextString(" Back to Menu"); 
	
	for(i = 1; i <= fb; i++)DrawBlackPiece(osx + bp[i].x * width, osy - bp[i].y * width);
    for(i = 1; i <= fw; i++)DrawWhitePiece(osx + wp[i].x * width, osy - wp[i].y * width);
    
    SetPenSize(3);
    SetPenColor("Red");
    if(fb == fw) MovePen(osx + bp[fb].x * width + radius, osy - bp[fb].y * width);
    else         MovePen(osx + wp[fw].x * width + radius, osy - wp[fw].y * width);
    if(flag)     DrawArc(radius, 0, 360);
}

int JudgeDraw()
{
    int i, j, flag = 3;
    for (i = 0; i <= side - 4; i++)
    {
        for (j = 0; j <= side - 4; j++)
        {
            if (board[i][j] == 1 && 
                board[i + 1][j + 1] == 1 && 
                board[i + 2][j + 2] == 1 && 
                board[i + 3][j + 3] == 1 && 
                board[i + 4][j + 4] == 1) 
            {
                flag = 1;
                return flag;
            }
            else if (
                board[i][j] == 2 &&
                    board[i + 1][j + 1] == 2 &&
                    board[i + 2][j + 2] == 2 &&
                    board[i + 3][j + 3] == 2 &&
                    board[i + 4][j + 4] == 2
                )
            {
                flag = 2; return flag;
            }

        }
    }
    for (i = 0; i <= side; i++)
    {
        for (j = 0; j <= side - 4; j++)
        {
            if (board[i][j] == 1 && 
                board[i][j + 1] == 1 && 
                board[i][j + 2] == 1 && 
                board[i][j + 3] == 1 && 
                board[i][j + 4] == 1)
            {
                flag = 1;
                return flag;
            }
            else if (board[i][j] == 2 &&
                board[i][j + 1] == 2 && 
                board[i][j + 2] == 2 && 
                board[i][j + 3] == 2 && 
                board[i][j + 4] == 2)
            {
                flag = 2;
                return flag;
            }
        }
    }
    for (i = 0; i <= side - 4; i++)
    {
        for (j = 0; j <= side; j++)
        {
            if (board[i][j] == 1 &&
                board[i + 1][j] == 1 &&
                board[i + 2][j] == 1 &&
                board[i + 3][j] == 1 &&
                board[i + 4][j] == 1)
            {
                flag = 1;
                return flag;
            }
            else if (board[i][j] == 2 &&
                board[i + 1][j] == 2 &&
                board[i + 2][j] == 2 &&
                board[i + 3][j] == 2 &&
                board[i + 4][j] == 2)
            {
                flag = 2;
                return flag;
            }
        }
    }
    for (i = 0; i <= side - 4; i++)
    {
        for (j = 4; j <= side; j++)
        {
            if (board[i][j] == 1 &&
                board[i + 1][j - 1] == 1 &&
                board[i + 2][j - 2] == 1 &&
                board[i + 3][j - 3] == 1 &&
                board[i + 4][j - 4] == 1)
            {
                flag = 1;
                return flag;
            }
            else if (
                board[i][j] == 2 &&
                board[i + 1][j - 1] == 2 &&
                board[i + 2][j - 2] == 2 &&
                board[i + 3][j - 3] == 2 &&
                board[i + 4][j - 4] == 2
                )
            {
                flag = 2; return flag;
            }

        }
    }

    return flag;

}

int isFull()
{
	int i, j, flag = 1;
	for(i = 0; i <= side; i ++)
	{
		for(j = 0; j <= side; j ++)
		{
			if(board[i][j] == 0)
			{
				flag = 0;
			}
		}
	}
	return flag;
}

double distance(double mx, double my, double x, double y)
{
	return sqrt(pow(mx - x, 2) + pow(my - y, 2));
}

void BlackWin()
{
	SetPointSize(30);
	DrawTextString("Black Wins!");
	isPlay = FALSE;
}

void WhiteWin()
{
	SetPointSize(30);
	DrawTextString("White Wins!");
	isPlay = FALSE;
}

void Draw()
{
	SetPointSize(30);
	DrawTextString("   Draw!");
	isPlay = FALSE;
}

void DrawMenu()
{
	isPlay = FALSE;
	isMenu = TRUE;
	SetPenColor("White");
	MovePen(0, 0);
	DrawBox(wid, hei);
	SetPointSize(50);
	SetPenColor("Black");
	MovePen(wid / 2 - 6 * width, 0.65 * hei);
	DrawTextString("Welcome to Gomoku");
	SetPointSize(20);
	MovePen(wid / 2 - 3 * width, 0.55 * hei);
	DrawTextString("唐睿源 闫徐天任 赵瀚清 制作");
	SetPointSize(20);
	MovePen(PGLocx, PGLocy);
	DrawBorder(PGSizex, PGSizey);
	MovePen(PGWLocx, PGWLocy);
	DrawTextString("Start the Game"); 
	MovePen(PCLocx, PCLocy);
	DrawBorder(SizePC * width, width);
	MovePen(PCWLocx, PCWLocy);
	DrawTextString("Play White With AI"); 
}

void ClearBoard()
{
	isPlay = TRUE; 
	isMenu = FALSE;
    flag = fb = fw = 0;
	memset(board, 0, sizeof(board));
	memset(wp, 0, sizeof(wp));
	memset(bp, 0, sizeof(bp));
    CreateBoard();
}

