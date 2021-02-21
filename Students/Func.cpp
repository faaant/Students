#include "Func.h"

int Average (int* grade)
{
    int sum=0;
    for (int i=0; i<5;i++)
    {
        sum=sum+grade[i];
    }
    return sum/5;
}

