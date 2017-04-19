#ifndef _EVALUATE_H
#define _EVALUATE_H

#define side   14
int Evaluate(void); /*价值判断函数*/
int FindOpenRowofFour(void); /*找活四，返回活四个数，下同*/
int FindOpenRowofThree(void); /*找活三*/
int FindJumpThree(void); /*找跳三*/
int FindChongSi(void); /*找冲四*/
int FindOpenRowofTwo(void); /*找活二*/
int FindHasNeighbor(void); /*找有相邻棋子的棋*/
int FindNumOfNeighbor(int i, int j);

int JudgeDraw();
#endif // !_EVALUATE.H


