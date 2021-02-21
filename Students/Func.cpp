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

int minGrade (vector<TStudent>& students)
{
    int AvGrades[students.size()];
    for (int i=0;i<students.size();i++)
    {
        AvGrades[i]=students[i].averageG;
    }
    sortM(AvGrades,students.size());
    return AvGrades[int(floor(students.size()*0.4))];
}

int* sortM (int* AvGrade, int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {
            if (AvGrade[i]<AvGrade[j])
            {
                int buf = AvGrade[i];
                AvGrade[i] = AvGrade[j];
                AvGrade[j] = buf;
            }
        }
    }
    return AvGrade;
}
