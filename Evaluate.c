#include <stdio.h>
#include <stdlib.h>

#define side   14

extern board[15][15];

int Evaluate(void)
{
    int curSituation = 0;
    int Five = FindFive();
    int OpenRowofThree = FindOpenRowofThree() + FindJumpThree();
    int OpenRowofFour = FindOpenRowofFour();
    int ChongSi = FindChongSi();

    if (OpenRowofThree > 1 || ChongSi > 1 || ChongSi + OpenRowofThree > 1) 
    {
        curSituation = Five * 100000 + 900;
    }
    else
        curSituation = Five * 100000 + OpenRowofFour * 1000 + OpenRowofThree * 100 + ChongSi * 100 + FindMianSan() * 10 + FindOpenRowofTwo() * 10 + FindHasNeighbor();
    return curSituation;

}

int FindFive(void)
{
    int i, j;
    int NumberOfFive = 0;
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
                return 1;
            }
            else if (
                board[i][j] == 2 &&
                board[i + 1][j + 1] == 2 &&
                board[i + 2][j + 2] == 2 &&
                board[i + 3][j + 3] == 2 &&
                board[i + 4][j + 4] == 2
                )
            {
                return -1;
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
                return 1;
            }
            else if (board[i][j] == 2 &&
                board[i][j + 1] == 2 &&
                board[i][j + 2] == 2 &&
                board[i][j + 3] == 2 &&
                board[i][j + 4] == 2)
            {
                return -1;
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
                return 1;
            }
            else if (board[i][j] == 2 &&
                board[i + 1][j] == 2 &&
                board[i + 2][j] == 2 &&
                board[i + 3][j] == 2 &&
                board[i + 4][j] == 2)
            {
                return -1;
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
                return 1;
            }
            else if (
                board[i][j] == 2 &&
                board[i + 1][j - 1] == 2 &&
                board[i + 2][j - 2] == 2 &&
                board[i + 3][j - 3] == 2 &&
                board[i + 4][j - 4] == 2
                )
            {
                return -1;
            }

        }
    }

    return NumberOfFive;
}

int FindOpenRowofFour(void)
{
    int i, j;
    int NumberOfFour = 0;
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 0; j <= side - 5; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j + 1] == 1 &&
                board[i + 2][j + 2] == 1 &&
                board[i + 3][j + 3] == 1 &&
                board[i + 4][j + 4] == 1 &&
                board[i + 5][j + 5] == 0)
            {
                NumberOfFour++;
            }
            else if (
                board[i][j] == 0 &&
                board[i + 1][j + 1] == 2 &&
                board[i + 2][j + 2] == 2 &&
                board[i + 3][j + 3] == 2 &&
                board[i + 4][j + 4] == 2 &&
                board[i + 5][j + 5] == 0
                )
            {
                NumberOfFour--;
            }

        }
    }
    for (i = 0; i <= side; i++)
    {
        for (j = 0; j <= side - 5; j++)
        {
            if (board[i][j] == 0 &&
                board[i][j + 1] == 1 &&
                board[i][j + 2] == 1 &&
                board[i][j + 3] == 1 &&
                board[i][j + 4] == 1 &&
                board[i][j + 5] == 0)
            {
                NumberOfFour++;
            }
            else if (board[i][j] == 0 &&
                board[i][j + 1] == 2 &&
                board[i][j + 2] == 2 &&
                board[i][j + 3] == 2 &&
                board[i][j + 4] == 2 &&
                board[i][j + 5] == 0)
            {
                NumberOfFour--;
            }
        }
    }
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 0; j <= side; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j] == 1 &&
                board[i + 2][j] == 1 &&
                board[i + 3][j] == 1 &&
                board[i + 4][j] == 1 &&
                board[i + 5][j] == 0)
            {
                NumberOfFour++;
            }
            else if (board[i][j] == 0 &&
                board[i + 1][j] == 2 &&
                board[i + 2][j] == 2 &&
                board[i + 3][j] == 2 &&
                board[i + 4][j] == 2 &&
                board[i + 5][j] == 0)
            {
                NumberOfFour--;
            }
        }
    }
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 5; j <= side; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j - 1] == 1 &&
                board[i + 2][j - 2] == 1 &&
                board[i + 3][j - 3] == 1 &&
                board[i + 4][j - 4] == 1 &&
                board[i + 5][j - 5] == 0)
            {
                NumberOfFour++;
            }
            else if (
                board[i][j] == 0 &&
                board[i + 1][j - 1] == 2 &&
                board[i + 2][j - 2] == 2 &&
                board[i + 3][j - 3] == 2 &&
                board[i + 4][j - 4] == 2 &&
                board[i + 5][j - 5] == 0
                )
            {
                NumberOfFour--;
            }

        }
    }
    return NumberOfFour;
}

int FindOpenRowofThree(void)
{
    int i, j;
    int NumberOfThree = 0;
    for (i = 0; i <= side - 4; i++)
    {
        for (j = 0; j <= side - 4; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j + 1] == 1 &&
                board[i + 2][j + 2] == 1 &&
                board[i + 3][j + 3] == 1 &&
                board[i + 4][j + 4] == 0 )
            {
                NumberOfThree++;
            }
            else if (
                board[i][j] == 0 &&
                board[i + 1][j + 1] == 2 &&
                board[i + 2][j + 2] == 2 &&
                board[i + 3][j + 3] == 2 &&
                board[i + 4][j + 4] == 0 
                )
            {
                NumberOfThree--;
            }

        }
    }
    for (i = 0; i <= side; i++)
    {
        for (j = 0; j <= side - 4; j++)
        {
            if (board[i][j] == 0 &&
                board[i][j + 1] == 1 &&
                board[i][j + 2] == 1 &&
                board[i][j + 3] == 1 &&
                board[i][j + 4] == 0)
            {
                NumberOfThree++;
            }
            else if (board[i][j] == 0 &&
                board[i][j + 1] == 2 &&
                board[i][j + 2] == 2 &&
                board[i][j + 3] == 2 &&
                board[i][j + 4] == 0)
            {
                NumberOfThree--;
            }
        }
    }
    for (i = 0; i <= side - 4; i++)
    {
        for (j = 0; j <= side; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j] == 1 &&
                board[i + 2][j] == 1 &&
                board[i + 3][j] == 1 &&
                board[i + 4][j] == 0)
            {
                NumberOfThree++;
            }
            else if (board[i][j] == 0 &&
                board[i + 1][j] == 2 &&
                board[i + 2][j] == 2 &&
                board[i + 3][j] == 2 &&
                board[i + 4][j] == 0)
            {
                NumberOfThree--;
            }
        }
    }
    for (i = 0; i <= side - 4; i++)
    {
        for (j = 4; j <= side; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j - 1] == 1 &&
                board[i + 2][j - 2] == 1 &&
                board[i + 3][j - 3] == 1 &&
                board[i + 4][j - 4] == 0)
            {
                NumberOfThree++;
            }
            else if (
                board[i][j] == 0 &&
                board[i + 1][j - 1] == 2 &&
                board[i + 2][j - 2] == 2 &&
                board[i + 3][j - 3] == 2 &&
                board[i + 4][j - 4] == 0
                )
            {
                NumberOfThree--;
            }

        }
    }

    return NumberOfThree;
}
int FindJumpThree(void)
{
    int i, j;
    int NumberOfFour = 0;
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 0; j <= side - 5; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j + 1] == 1 &&
                board[i + 2][j + 2] == 0 &&
                board[i + 3][j + 3] == 1 &&
                board[i + 4][j + 4] == 1 &&
                board[i + 5][j + 5] == 0)
            {
                NumberOfFour++;
            }
            else if (
                board[i][j] == 0 &&
                board[i + 1][j + 1] == 2 &&
                board[i + 2][j + 2] == 0 &&
                board[i + 3][j + 3] == 2 &&
                board[i + 4][j + 4] == 2 &&
                board[i + 5][j + 5] == 0
                )
            {
                NumberOfFour--;
            }

        }
    }
    for (i = 0; i <= side; i++)
    {
        for (j = 0; j <= side - 5; j++)
        {
            if (board[i][j] == 0 &&
                board[i][j + 1] == 1 &&
                board[i][j + 2] == 0 &&
                board[i][j + 3] == 1 &&
                board[i][j + 4] == 1 &&
                board[i][j + 5] == 0)
            {
                NumberOfFour++;
            }
            else if (board[i][j] == 0 &&
                board[i][j + 1] == 2 &&
                board[i][j + 2] == 0 &&
                board[i][j + 3] == 2 &&
                board[i][j + 4] == 2 &&
                board[i][j + 5] == 0)
            {
                NumberOfFour--;
            }
        }
    }
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 0; j <= side; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j] == 1 &&
                board[i + 2][j] == 0 &&
                board[i + 3][j] == 1 &&
                board[i + 4][j] == 1 &&
                board[i + 5][j] == 0)
            {
                NumberOfFour++;
            }
            else if (board[i][j] == 0 &&
                board[i + 1][j] == 2 &&
                board[i + 2][j] == 0 &&
                board[i + 3][j] == 2 &&
                board[i + 4][j] == 2 &&
                board[i + 5][j] == 0)
            {
                NumberOfFour--;
            }
        }
    }
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 5; j <= side; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j - 1] == 1 &&
                board[i + 2][j - 2] == 0 &&
                board[i + 3][j - 3] == 1 &&
                board[i + 4][j - 4] == 1 &&
                board[i + 5][j - 5] == 0)
            {
                NumberOfFour++;
            }
            else if (
                board[i][j] == 0 &&
                board[i + 1][j - 1] == 2 &&
                board[i + 2][j - 2] == 0 &&
                board[i + 3][j - 3] == 2 &&
                board[i + 4][j - 4] == 2 &&
                board[i + 5][j - 5] == 0
                )
            {
                NumberOfFour--;
            }

        }
    }
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 0; j <= side - 5; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j + 1] == 1 &&
                board[i + 2][j + 2] == 1 &&
                board[i + 3][j + 3] == 0 &&
                board[i + 4][j + 4] == 1 &&
                board[i + 5][j + 5] == 0)
            {
                NumberOfFour++;
            }
            else if (
                board[i][j] == 0 &&
                board[i + 1][j + 1] == 2 &&
                board[i + 2][j + 2] == 2 &&
                board[i + 3][j + 3] == 0 &&
                board[i + 4][j + 4] == 2 &&
                board[i + 5][j + 5] == 0
                )
            {
                NumberOfFour--;
            }

        }
    }
    for (i = 0; i <= side; i++)
    {
        for (j = 0; j <= side - 5; j++)
        {
            if (board[i][j] == 0 &&
                board[i][j + 1] == 1 &&
                board[i][j + 2] == 1 &&
                board[i][j + 3] == 0 &&
                board[i][j + 4] == 1 &&
                board[i][j + 5] == 0)
            {
                NumberOfFour++;
            }
            else if (board[i][j] == 0 &&
                board[i][j + 1] == 2 &&
                board[i][j + 2] == 2 &&
                board[i][j + 3] == 0 &&
                board[i][j + 4] == 2 &&
                board[i][j + 5] == 0)
            {
                NumberOfFour--;
            }
        }
    }
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 0; j <= side; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j] == 1 &&
                board[i + 2][j] == 1 &&
                board[i + 3][j] == 0 &&
                board[i + 4][j] == 1 &&
                board[i + 5][j] == 0)
            {
                NumberOfFour++;
            }
            else if (board[i][j] == 0 &&
                board[i + 1][j] == 2 &&
                board[i + 2][j] == 2 &&
                board[i + 3][j] == 0 &&
                board[i + 4][j] == 2 &&
                board[i + 5][j] == 0)
            {
                NumberOfFour--;
            }
        }
    }
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 5; j <= side; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j - 1] == 1 &&
                board[i + 2][j - 2] == 1 &&
                board[i + 3][j - 3] == 0 &&
                board[i + 4][j - 4] == 1 &&
                board[i + 5][j - 5] == 0)
            {
                NumberOfFour++;
            }
            else if (
                board[i][j] == 0 &&
                board[i + 1][j - 1] == 2 &&
                board[i + 2][j - 2] == 2 &&
                board[i + 3][j - 3] == 0 &&
                board[i + 4][j - 4] == 2 &&
                board[i + 5][j - 5] == 0
                )
            {
                NumberOfFour--;
            }
        }
    }
    return NumberOfFour;
}

int FindChongSi(void)
{
    int i, j;
    int NumberOfFour = 0;
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 0; j <= side - 5; j++)
        {
            if (board[i][j] == 2 &&
                board[i + 1][j + 1] == 1 &&
                board[i + 2][j + 2] == 1 &&
                board[i + 3][j + 3] == 1 &&
                board[i + 4][j + 4] == 1 &&
                board[i + 5][j + 5] == 0)
            {
                NumberOfFour++;
            }
            else if (
                board[i][j] == 1 &&
                board[i + 1][j + 1] == 2 &&
                board[i + 2][j + 2] == 2 &&
                board[i + 3][j + 3] == 2 &&
                board[i + 4][j + 4] == 2 &&
                board[i + 5][j + 5] == 0
                )
            {
                NumberOfFour--;
            }

        }
    }
    for (i = 0; i <= side; i++)
    {
        for (j = 0; j <= side - 5; j++)
        {
            if (board[i][j] == 2 &&
                board[i][j + 1] == 1 &&
                board[i][j + 2] == 1 &&
                board[i][j + 3] == 1 &&
                board[i][j + 4] == 1 &&
                board[i][j + 5] == 0)
            {
                NumberOfFour++;
            }
            else if (board[i][j] == 1 &&
                board[i][j + 1] == 2 &&
                board[i][j + 2] == 2 &&
                board[i][j + 3] == 2 &&
                board[i][j + 4] == 2 &&
                board[i][j + 5] == 0)
            {
                NumberOfFour--;
            }
        }
    }
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 0; j <= side; j++)
        {
            if (board[i][j] == 2 &&
                board[i + 1][j] == 1 &&
                board[i + 2][j] == 1 &&
                board[i + 3][j] == 1 &&
                board[i + 4][j] == 1 &&
                board[i + 5][j] == 0)
            {
                NumberOfFour++;
            }
            else if (board[i][j] == 1 &&
                board[i + 1][j] == 2 &&
                board[i + 2][j] == 2 &&
                board[i + 3][j] == 2 &&
                board[i + 4][j] == 2 &&
                board[i + 5][j] == 0)
            {
                NumberOfFour--;
            }
        }
    }
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 5; j <= side; j++)
        {
            if (board[i][j] == 2 &&
                board[i + 1][j - 1] == 1 &&
                board[i + 2][j - 2] == 1 &&
                board[i + 3][j - 3] == 1 &&
                board[i + 4][j - 4] == 1 &&
                board[i + 5][j - 5] == 0)
            {
                NumberOfFour++;
            }
            else if (
                board[i][j] == 1 &&
                board[i + 1][j - 1] == 2 &&
                board[i + 2][j - 2] == 2 &&
                board[i + 3][j - 3] == 2 &&
                board[i + 4][j - 4] == 2 &&
                board[i + 5][j - 5] == 0
                )
            {
                NumberOfFour--;
            }

        }
    }
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 0; j <= side - 5; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j + 1] == 1 &&
                board[i + 2][j + 2] == 1 &&
                board[i + 3][j + 3] == 1 &&
                board[i + 4][j + 4] == 1 &&
                board[i + 5][j + 5] == 2)
            {
                NumberOfFour++;
            }
            else if (
                board[i][j] == 0 &&
                board[i + 1][j + 1] == 2 &&
                board[i + 2][j + 2] == 2 &&
                board[i + 3][j + 3] == 2 &&
                board[i + 4][j + 4] == 2 &&
                board[i + 5][j + 5] == 1
                )
            {
                NumberOfFour--;
            }

        }
    }
    for (i = 0; i <= side; i++)
    {
        for (j = 0; j <= side - 5; j++)
        {
            if (board[i][j] == 0 &&
                board[i][j + 1] == 1 &&
                board[i][j + 2] == 1 &&
                board[i][j + 3] == 1 &&
                board[i][j + 4] == 1 &&
                board[i][j + 5] == 2)
            {
                NumberOfFour++;
            }
            else if (board[i][j] == 0 &&
                board[i][j + 1] == 2 &&
                board[i][j + 2] == 2 &&
                board[i][j + 3] == 2 &&
                board[i][j + 4] == 2 &&
                board[i][j + 5] == 1)
            {
                NumberOfFour--;
            }
        }
    }
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 0; j <= side; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j] == 1 &&
                board[i + 2][j] == 1 &&
                board[i + 3][j] == 1 &&
                board[i + 4][j] == 1 &&
                board[i + 5][j] == 2)
            {
                NumberOfFour++;
            }
            else if (board[i][j] == 0 &&
                board[i + 1][j] == 2 &&
                board[i + 2][j] == 2 &&
                board[i + 3][j] == 2 &&
                board[i + 4][j] == 2 &&
                board[i + 5][j] == 1)
            {
                NumberOfFour--;
            }
        }
    }
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 5; j <= side; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j - 1] == 1 &&
                board[i + 2][j - 2] == 1 &&
                board[i + 3][j - 3] == 1 &&
                board[i + 4][j - 4] == 1 &&
                board[i + 5][j - 5] == 2)
            {
                NumberOfFour++;
            }
            else if (
                board[i][j] == 0 &&
                board[i + 1][j - 1] == 2 &&
                board[i + 2][j - 2] == 2 &&
                board[i + 3][j - 3] == 2 &&
                board[i + 4][j - 4] == 2 &&
                board[i + 5][j - 5] == 1
                )
            {
                NumberOfFour--;
            }

        }
    }
    for (i = 0; i <= side - 4; i++)
    {
        for (j = 0; j <= side - 4; j++)
        {
            if (board[i][j] == 1 &&
                board[i + 1][j + 1] == 0 &&
                board[i + 2][j + 2] == 1 &&
                board[i + 3][j + 3] == 1 &&
                board[i + 4][j + 4] == 1)
            {
                NumberOfFour++;
            }
            else if (
                board[i][j] == 2 &&
                board[i + 1][j + 1] == 0 &&
                board[i + 2][j + 2] == 2 &&
                board[i + 3][j + 3] == 2 &&
                board[i + 4][j + 4] == 2
                )
            {
                NumberOfFour--;
            }

        }
    }
    for (i = 0; i <= side; i++)
    {
        for (j = 0; j <= side - 4; j++)
        {
            if (board[i][j] == 1 &&
                board[i][j + 1] == 0 &&
                board[i][j + 2] == 1 &&
                board[i][j + 3] == 1 &&
                board[i][j + 4] == 1)
            {
                NumberOfFour++;
            }
            else if (board[i][j] == 2 &&
                board[i][j + 1] == 0 &&
                board[i][j + 2] == 2 &&
                board[i][j + 3] == 2 &&
                board[i][j + 4] == 2)
            {
                NumberOfFour--;
            }
        }
    }
    for (i = 0; i <= side - 4; i++)
    {
        for (j = 0; j <= side; j++)
        {
            if (board[i][j] == 1 &&
                board[i + 1][j] == 0 &&
                board[i + 2][j] == 1 &&
                board[i + 3][j] == 1 &&
                board[i + 4][j] == 1)
            {
                NumberOfFour++;
            }
            else if (board[i][j] == 2 &&
                board[i + 1][j] == 0 &&
                board[i + 2][j] == 2 &&
                board[i + 3][j] == 2 &&
                board[i + 4][j] == 2)
            {
                NumberOfFour--;
            }
        }
    }
    for (i = 0; i <= side - 4; i++)
    {
        for (j = 4; j <= side; j++)
        {
            if (board[i][j] == 1 &&
                board[i + 1][j - 1] == 0 &&
                board[i + 2][j - 2] == 1 &&
                board[i + 3][j - 3] == 1 &&
                board[i + 4][j - 4] == 1)
            {
                NumberOfFour++;
            }
            else if (
                board[i][j] == 2 &&
                board[i + 1][j - 1] == 0 &&
                board[i + 2][j - 2] == 2 &&
                board[i + 3][j - 3] == 2 &&
                board[i + 4][j - 4] == 2
                )
            {
                NumberOfFour--;
            }

        }
    }
    for (i = 0; i <= side - 4; i++)
    {
        for (j = 0; j <= side - 4; j++)
        {
            if (board[i][j] == 1 &&
                board[i + 1][j + 1] == 1 &&
                board[i + 2][j + 2] == 0 &&
                board[i + 3][j + 3] == 1 &&
                board[i + 4][j + 4] == 1)
            {
                NumberOfFour++;
            }
            else if (
                board[i][j] == 2 &&
                board[i + 1][j + 1] == 2 &&
                board[i + 2][j + 2] == 0 &&
                board[i + 3][j + 3] == 2 &&
                board[i + 4][j + 4] == 2
                )
            {
                NumberOfFour--;
            }

        }
    }
    for (i = 0; i <= side; i++)
    {
        for (j = 0; j <= side - 4; j++)
        {
            if (board[i][j] == 1 &&
                board[i][j + 1] == 1 &&
                board[i][j + 2] == 0 &&
                board[i][j + 3] == 1 &&
                board[i][j + 4] == 1)
            {
                NumberOfFour++;
            }
            else if (board[i][j] == 2 &&
                board[i][j + 1] == 2 &&
                board[i][j + 2] == 0 &&
                board[i][j + 3] == 2 &&
                board[i][j + 4] == 2)
            {
                NumberOfFour--;
            }
        }
    }
    for (i = 0; i <= side - 4; i++)
    {
        for (j = 0; j <= side; j++)
        {
            if (board[i][j] == 1 &&
                board[i + 1][j] == 1 &&
                board[i + 2][j] == 0 &&
                board[i + 3][j] == 1 &&
                board[i + 4][j] == 1)
            {
                NumberOfFour++;
            }
            else if (board[i][j] == 2 &&
                board[i + 1][j] == 2 &&
                board[i + 2][j] == 0 &&
                board[i + 3][j] == 2 &&
                board[i + 4][j] == 2)
            {
                NumberOfFour--;
            }
        }
    }
    for (i = 0; i <= side - 4; i++)
    {
        for (j = 4; j <= side; j++)
        {
            if (board[i][j] == 1 &&
                board[i + 1][j - 1] == 1 &&
                board[i + 2][j - 2] == 0 &&
                board[i + 3][j - 3] == 1 &&
                board[i + 4][j - 4] == 1)
            {
                NumberOfFour++;
            }
            else if (
                board[i][j] == 2 &&
                board[i + 1][j - 1] == 2 &&
                board[i + 2][j - 2] == 0 &&
                board[i + 3][j - 3] == 2 &&
                board[i + 4][j - 4] == 2
                )
            {
                NumberOfFour--;
            }

        }
    }
    for (i = 0; i <= side - 4; i++)
    {
        for (j = 0; j <= side - 4; j++)
        {
            if (board[i][j] == 1 &&
                board[i + 1][j + 1] == 1 &&
                board[i + 2][j + 2] == 1 &&
                board[i + 3][j + 3] == 0 &&
                board[i + 4][j + 4] == 1)
            {
                NumberOfFour++;
            }
            else if (
                board[i][j] == 2 &&
                board[i + 1][j + 1] == 2 &&
                board[i + 2][j + 2] == 2 &&
                board[i + 3][j + 3] == 0 &&
                board[i + 4][j + 4] == 2
                )
            {
                NumberOfFour--;
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
                board[i][j + 3] == 0 &&
                board[i][j + 4] == 1)
            {
                NumberOfFour++;
            }
            else if (board[i][j] == 2 &&
                board[i][j + 1] == 2 &&
                board[i][j + 2] == 2 &&
                board[i][j + 3] == 0 &&
                board[i][j + 4] == 2)
            {
                NumberOfFour--;
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
                board[i + 3][j] == 0 &&
                board[i + 4][j] == 1)
            {
                NumberOfFour++;
            }
            else if (board[i][j] == 2 &&
                board[i + 1][j] == 2 &&
                board[i + 2][j] == 2 &&
                board[i + 3][j] == 0 &&
                board[i + 4][j] == 2)
            {
                NumberOfFour--;
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
                board[i + 3][j - 3] == 0 &&
                board[i + 4][j - 4] == 1)
            {
                NumberOfFour++;
            }
            else if (
                board[i][j] == 2 &&
                board[i + 1][j - 1] == 2 &&
                board[i + 2][j - 2] == 2 &&
                board[i + 3][j - 3] == 0 &&
                board[i + 4][j - 4] == 2
                )
            {
                NumberOfFour--;
            }

        }
    }
    return NumberOfFour;
}

int FindMianSan(void)
{
    int i, j;
    int NumberOfThree = 0;
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 0; j <= side - 5; j++)
        {
            if (board[i][j] == 2 &&
                board[i + 1][j + 1] == 1 &&
                board[i + 2][j + 2] == 1 &&
                board[i + 3][j + 3] == 1 &&
                board[i + 4][j + 4] == 0 &&
                board[i + 5][j + 5] == 0)
            {
                NumberOfThree++;
            }
            else if (
                board[i][j] == 1 &&
                board[i + 1][j + 1] == 2 &&
                board[i + 2][j + 2] == 2 &&
                board[i + 3][j + 3] == 2 &&
                board[i + 4][j + 4] == 0 &&
                board[i + 5][j + 5] == 0
                )
            {
                NumberOfThree--;
            }

        }
    }
    for (i = 0; i <= side; i++)
    {
        for (j = 0; j <= side - 5; j++)
        {
            if (board[i][j] == 2 &&
                board[i][j + 1] == 1 &&
                board[i][j + 2] == 1 &&
                board[i][j + 3] == 1 &&
                board[i][j + 4] == 0 &&
                board[i][j + 5] == 0)
            {
                NumberOfThree++;
            }
            else if (board[i][j] == 1 &&
                board[i][j + 1] == 2 &&
                board[i][j + 2] == 2 &&
                board[i][j + 3] == 2 &&
                board[i][j + 4] == 0 &&
                board[i][j + 5] == 0)
            {
                NumberOfThree--;
            }
        }
    }
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 0; j <= side; j++)
        {
            if (board[i][j] == 2 &&
                board[i + 1][j] == 1 &&
                board[i + 2][j] == 1 &&
                board[i + 3][j] == 1 &&
                board[i + 4][j] == 0 &&
                board[i + 5][j] == 0)
            {
                NumberOfThree++;
            }
            else if (board[i][j] == 1 &&
                board[i + 1][j] == 2 &&
                board[i + 2][j] == 2 &&
                board[i + 3][j] == 2 &&
                board[i + 4][j] == 0 &&
                board[i + 5][j] == 0)
            {
                NumberOfThree--;
            }
        }
    }
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 5; j <= side; j++)
        {
            if (board[i][j] == 2 &&
                board[i + 1][j - 1] == 1 &&
                board[i + 2][j - 2] == 1 &&
                board[i + 3][j - 3] == 1 &&
                board[i + 4][j - 4] == 0 &&
                board[i + 5][j - 5] == 0)
            {
                NumberOfThree++;
            }
            else if (
                board[i][j] == 1 &&
                board[i + 1][j - 1] == 2 &&
                board[i + 2][j - 2] == 2 &&
                board[i + 3][j - 3] == 2 &&
                board[i + 4][j - 4] == 2 &&
                board[i + 5][j - 5] == 0
                )
            {
                NumberOfThree--;
            }

        }
    }
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 0; j <= side - 5; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j + 1] == 0 &&
                board[i + 2][j + 2] == 1 &&
                board[i + 3][j + 3] == 1 &&
                board[i + 4][j + 4] == 1 &&
                board[i + 5][j + 5] == 2)
            {
                NumberOfThree++;
            }
            else if (
                board[i][j] == 0 &&
                board[i + 1][j + 1] == 0 &&
                board[i + 2][j + 2] == 2 &&
                board[i + 3][j + 3] == 2 &&
                board[i + 4][j + 4] == 2 &&
                board[i + 5][j + 5] == 1
                )
            {
                NumberOfThree--;
            }

        }
    }
    for (i = 0; i <= side; i++)
    {
        for (j = 0; j <= side - 5; j++)
        {
            if (board[i][j] == 0 &&
                board[i][j + 1] == 0 &&
                board[i][j + 2] == 1 &&
                board[i][j + 3] == 1 &&
                board[i][j + 4] == 1 &&
                board[i][j + 5] == 2)
            {
                NumberOfThree++;
            }
            else if (board[i][j] == 0 &&
                board[i][j + 1] == 0 &&
                board[i][j + 2] == 2 &&
                board[i][j + 3] == 2 &&
                board[i][j + 4] == 2 &&
                board[i][j + 5] == 1)
            {
                NumberOfThree--;
            }
        }
    }
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 0; j <= side; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j] == 0 &&
                board[i + 2][j] == 1 &&
                board[i + 3][j] == 1 &&
                board[i + 4][j] == 1 &&
                board[i + 5][j] == 2)
            {
                NumberOfThree++;
            }
            else if (board[i][j] == 0 &&
                board[i + 1][j] == 0 &&
                board[i + 2][j] == 2 &&
                board[i + 3][j] == 2 &&
                board[i + 4][j] == 2 &&
                board[i + 5][j] == 1)
            {
                NumberOfThree--;
            }
        }
    }
    for (i = 0; i <= side - 5; i++)
    {
        for (j = 5; j <= side; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j - 1] == 0 &&
                board[i + 2][j - 2] == 1 &&
                board[i + 3][j - 3] == 1 &&
                board[i + 4][j - 4] == 1 &&
                board[i + 5][j - 5] == 2)
            {
                NumberOfThree++;
            }
            else if (
                board[i][j] == 0 &&
                board[i + 1][j - 1] == 0 &&
                board[i + 2][j - 2] == 2 &&
                board[i + 3][j - 3] == 2 &&
                board[i + 4][j - 4] == 2 &&
                board[i + 5][j - 5] == 1
                )
            {
                NumberOfThree--;
            }

        }
    }
    return NumberOfThree;
}

int FindOpenRowofTwo(void)
{
    int i, j;
    int NumberOfTwo = 0;
    for (i = 0; i <= side - 4; i++)
    {
        for (j = 0; j <= side - 4; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j + 1] == 1 &&
                board[i + 2][j + 2] == 1 &&
                board[i + 3][j + 3] == 0)
            {
                NumberOfTwo++;
            }
            else if (
                board[i][j] == 0 &&
                board[i + 1][j + 1] == 2 &&
                board[i + 2][j + 2] == 2 &&
                board[i + 3][j + 3] == 0
                )
            {
                NumberOfTwo--;
            }

        }
    }
    for (i = 0; i <= side; i++)
    {
        for (j = 0; j <= side - 4; j++)
        {
            if (board[i][j] == 0 &&
                board[i][j + 1] == 1 &&
                board[i][j + 2] == 1 &&
                board[i][j + 3] == 0)
            {
                NumberOfTwo++;
            }
            else if (board[i][j] == 0 &&
                board[i][j + 1] == 2 &&
                board[i][j + 2] == 2 &&
                board[i][j + 3] == 0)
            {
                NumberOfTwo--;
            }
        }
    }
    for (i = 0; i <= side - 4; i++)
    {
        for (j = 0; j <= side; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j] == 1 &&
                board[i + 2][j] == 1 &&
                board[i + 3][j] == 0)
            {
                NumberOfTwo++;
            }
            else if (board[i][j] == 0 &&
                board[i + 1][j] == 2 &&
                board[i + 2][j] == 2 &&
                board[i + 3][j] == 0)
            {
                NumberOfTwo--;
            }
        }
    }
    for (i = 0; i <= side - 4; i++)
    {
        for (j = 4; j <= side; j++)
        {
            if (board[i][j] == 0 &&
                board[i + 1][j - 1] == 1 &&
                board[i + 2][j - 2] == 1 &&
                board[i + 3][j - 3] == 0)
            {
                NumberOfTwo++;
            }
            else if (
                board[i][j] == 0 &&
                board[i + 1][j - 1] == 2 &&
                board[i + 2][j - 2] == 2 &&
                board[i + 3][j - 3] == 0
                )
            {
                NumberOfTwo--;
            }

        }
    }

    return NumberOfTwo;
    return 0;
}

int FindHasNeighbor(void)
{
    int i, j, Value = 0;
    for (i = 3; i <= side - 3; i++)
    {
        for (j = 3; j <= side - 3; j++)
        {
            if (board[i][j] == 0)
                break;
            else if (board[i][j] == 1)
                Value += FindNumOfNeighbor(i, j);
            else if (board[i][j] == 2)
                Value -= FindNumOfNeighbor(i, j);
        }
    }
    return Value;
}

int FindNumOfNeighbor(int I, int J)
{
    int number = 0;
    int i, j;
    for (i = -2; i <= 2; i++)
    {
        for (j = -2; j <= 2; j++)
        {
            if (board[i + I][j + J] != 0)
                number++; 
        }
    }
    return number;
}
