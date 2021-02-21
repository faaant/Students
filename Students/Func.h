#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct TStudent
{
    string name;
    int grade[5];
    bool contract;
    int averageG;
};

int Average (int*);
int minGrade (vector<TStudent>&);
int* sortM (int*, int);
