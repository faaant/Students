#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <direct.h>
#include <fstream>
using namespace std;

struct TStudent
{
    string name;
    int grade[5];
    bool contract;
    double averageG;
};

double Average (int*);
double minGrade (vector<TStudent>&, int);
void sortM (double*, int);
void Read_from_file(vector<TStudent> &,string &,int);
void sort_Students(vector<TStudent> &);
void Output_rating(vector<TStudent> &,string &,int);

