#ifndef _AI_EJING_H
#define _AI_EJING_H
int AIMove(int BorW, int step);
struct StepValue{
    int i;
    int j;
    int value;
};
typedef struct StepValue * pStepValue;

#endif
