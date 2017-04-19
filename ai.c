#include <stdio.h>
#include "Evaluate.h"
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX_STEP 2
#define NeighborRange 1

extern board[15][15];
extern struct StepValue curAIMove;
struct StepValue{
    int i;
    int j;
    int value;
};
typedef struct StepValue * pStepValue;

int AIMove(int flag, int step); /*flag = 1代表为电脑算，-1为玩家算; step 是迭代深度*/

int AIMove(int flag, int step) /*flag = 1代表为电脑算，-1为玩家算*/
{
    int i, j;
    int CheckRangeFlag = 0;

    int board_value[15][15];
    int SearchRangeImin, SearchRangeImax, SearchRangeJmin, SearchRangeJmax; /*确定搜索范围*/
    struct StepValue curBest = {0, 0, 10000000 * flag};
    pStepValue ptr = &curBest;
    if (step <= 0)
    {
        return Evaluate();
    }
    for (i = 0; i <= side; i++)
    {
        for (j = 0; j <= side; j++)
            board_value[i][j] = 100000000 * flag; /*确定未计算的地方都不会下棋*/
    }
    /*确定搜索范围*/
    for (i = 0; i <= side && CheckRangeFlag == 0; i++)
    {
        for (j = 0; j <= side; j++)
            if (board[i][j] != 0)
            {
                SearchRangeImin = i;
                CheckRangeFlag = 1;
                break;
            }
    }
    CheckRangeFlag = 0;
    for (i = side; i >= 0 && CheckRangeFlag == 0; i--)
    {
        for (j = 0; j < side; j++)
            if (board[i][j] != 0)
            {
                SearchRangeImax = i;
                CheckRangeFlag = 1;
                break;
            }
    }
    CheckRangeFlag = 0;
    for (j = side; j >= 0 && CheckRangeFlag == 0; j--)
    {
        for (i = 0; i <= side; i++)
            if (board[i][j] != 0)
            {
                SearchRangeJmax = j;
                CheckRangeFlag = 1;
                break;
            }
    }
    CheckRangeFlag = 0;
    for (j = 0; j <= side && CheckRangeFlag == 0; j++)
    {
        for (i = 0; i <= side; i++)
            if (board[i][j] != 0)
            {
                SearchRangeJmin = j;
                CheckRangeFlag = 1;
                break;
            }
    }
    CheckRangeFlag = 0;

    for (i = MAX(0, SearchRangeImin - NeighborRange); i <= MIN(side, SearchRangeImax + NeighborRange); i++)
    {
        for (j = MAX(0, SearchRangeJmin - NeighborRange); j <= MIN(side, SearchRangeJmax + NeighborRange); j++)
            if (board[i][j] == 0)
            {
                board[i][j] = 1 + ((1 + flag) / 2);/*根据 flag 判断是下黑棋还是白棋*/
                if (FindFive() == 0)
                {
                    board_value[i][j] = AIMove(-flag, step - 1);
                    board[i][j] = 0;
                } 
                else
                {
                    board_value[i][j] = 100000 * (-flag);
                    board[i][j] = 0;
                }
            }
    }

    if (step == MAX_STEP)
    {
        for (i = MAX(0, SearchRangeImin - NeighborRange); i <= MIN(side, SearchRangeImax + NeighborRange); i++)
        {
            for (j = MAX(0, SearchRangeJmin - NeighborRange); j <= MIN(side, SearchRangeJmax + NeighborRange); j++)
            {
                if (curBest.value >= board_value[i][j] && board[i][j] == 0)
                {
                    curBest.value = board_value[i][j];
                    curBest.i = i;
                    curBest.j = j;
                }
            }
        }
        
        curAIMove.i = curBest.i;
        curAIMove.j = curBest.j;
        board[curBest.i][curBest.j] = 2;
    }
    else if (flag == 1)
    {
        for (i = MAX(0, SearchRangeImin - NeighborRange); i <= MIN(side, SearchRangeImax + NeighborRange); i++)
        {
            for (j = MAX(0, SearchRangeJmin - NeighborRange); j <= MIN(side, SearchRangeJmax + NeighborRange); j++)
            {
                if (curBest.value >= board_value[i][j] && board[i][j] == 0)
                {
                    curBest.value = board_value[i][j];
                    curBest.i = i;
                    curBest.j = j;
                }
            }
        }
        return curBest.value;
    }
    else if (flag == -1)
    {
        for (i = MAX(0, SearchRangeImin - NeighborRange); i <= MIN(side, SearchRangeImax + NeighborRange); i++)
        {
            for (j = MAX(0, SearchRangeJmin - NeighborRange); j <= MIN(side, SearchRangeJmax + NeighborRange); j++)
            {
                if (curBest.value <= board_value[i][j] && board[i][j] == 0)
                {
                    curBest.value = board_value[i][j];
                    curBest.i = i;
                    curBest.j = j;
                }
            }
        }
        
        
        return curBest.value;
    }
}
