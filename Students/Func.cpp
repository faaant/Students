#include "Func.h"

double Average (double* grade)
{
    double sum=0;
    for (int i=0; i<5;i++)
    {
        sum=sum+grade[i];
    }
    return sum/5;
}

double minGrade (vector<TStudent>& students)
{
    double AvGrades[students.size()];
    for (int i=0;i<students.size();i++)
    {
        AvGrades[i]=students[i].averageG;
    }
    sortM(AvGrades,students.size());
    return AvGrades[floor(students.size()*0.4)];
}

double* sortM (double* AvGrade, int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {
            if (AvGrade[i]<AvGrade[j])
            {
                double buf = AvGrade[i];
                AvGrade[i] = AvGrade[j];
                AvGrade[j] = buf;
            }
        }
    }
    return AvGrade;
}
