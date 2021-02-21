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

void Read_from_file(vector<TStudent> &Student)
{
    int number_of_students;
    string name_of_directory,
           name,
           name_of_file,
           reader;
    TStudent student;
    cout<<"Enter the name of directory: ";
    getline(cin,name_of_directory);
    char way_to_files[name_of_directory.length()+5];
    for (int i=0;i<name_of_directory.length();i++)
    {
        way_to_files[i]=name_of_directory[i];
    }

    way_to_files[name_of_directory.length()]='/';
    way_to_files[name_of_directory.length()+1]='*';
    way_to_files[name_of_directory.length()+2]='.';
    way_to_files[name_of_directory.length()+3]='c';
    way_to_files[name_of_directory.length()+4]='s';
    way_to_files[name_of_directory.length()+5]='v';
    _finddata_t data;
    intptr_t handle = _findfirst(way_to_files, &data);
    do
    {

        name=data.name;
        name_of_file=name_of_directory+"/"+name;
        ifstream file (name_of_file);
        file >> number_of_students;
        for(int i=0; i<number_of_students;i++)
        {
            getline(file,reader,',');
            student.name=reader;
            for(int j=0; j<5;j++)
            {
                getline(file,reader,',');
                student.grade[j]=stoi(reader);
            }
            getline(file,reader);
            student.averageG=Average(student.grade);
            if(reader=="TRUE")
                student.contract=true;
            else
            {
                student.contract=false;
                Student.push_back(student);
            }
        }
        file.close();

    }while(_findnext(handle,&data)==0);
    _findclose(handle);
}



