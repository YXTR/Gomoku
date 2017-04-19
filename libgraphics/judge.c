int board[20][20] = {0};
int JudgeDraw(void)
{
	int i, j;
	for(i = 0 ; i <= 9; i ++)
	{
		for(j = 0; j <= 9; j ++)
		{
			if(
			   (board[i][j] == 1 && 
			    board[i + 1][j + 1] == 1 &&
			    board[i + 2][j + 2] == 1 &&
			    board[i + 3][j + 3] ==1 &&
			    board[i + 4][j + 4] == 1) ||
			   (board[i][j] == 1 && 
			    board[i + 1][j] == 1 &&
			    board[i + 2][j] == 1 &&
			    board[i + 3][j] == 1 &&
			    board[i + 4][j] == 1) ||
		       (board[i][j] == 1 && 
			    board[i][j + 1] ==1 &&
			    board[i][j + 2] == 1 &&
			    board[i][j + 3] == 1 &&
			    board[i][j + 4] == 1) 
			  )
			   return 1;
			 else if(
			   (board[i][j] == 2 && 
			    board[i + 1][j + 1] == 2 &&
			    board[i + 2][j + 2] == 2 &&
			    board[i + 3][j + 3] ==2 &&
			    board[i + 4][j + 4] == 2) ||
			   (board[i][j] == 2 && 
			    board[i + 1][j] == 2 &&
			    board[i + 2][j] == 2 &&
			    board[i + 3][j] == 2 &&
			    board[i + 4][j] == 2) ||
		       (board[i][j] = 2 && 
			    board[i][j + 1] == 2 &&
			    board[i][j + 2] == 2 &&
			    board[i][j + 3] == 2 &&
			    board[i][j + 4] == 2) 
			  )
			   return 2;
			 else
			   return 3;
		}
	}
}


int Judege(void)
{
	int i, j;
	for(i = 0; i <= 14; i ++)
	{
		for(j = 0; j <= 14; j ++)
		{
			if(board[i][j] == 0)
			{
				return (JudgeDraw());
			}
		}
	}
	if(JudgeDraw() == 1 || 
	   JudgeDraw() == 2)
		return (JudgeDraw());
		else 
		return 0;
}

