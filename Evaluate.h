#ifndef _EVALUATE_H
#define _EVALUATE_H

#define side   14
int Evaluate(void); /*��ֵ�жϺ���*/
int FindOpenRowofFour(void); /*�һ��ģ����ػ��ĸ�������ͬ*/
int FindOpenRowofThree(void); /*�һ���*/
int FindJumpThree(void); /*������*/
int FindChongSi(void); /*�ҳ���*/
int FindOpenRowofTwo(void); /*�һ��*/
int FindHasNeighbor(void); /*�����������ӵ���*/
int FindNumOfNeighbor(int i, int j);

int JudgeDraw();
#endif // !_EVALUATE.H


