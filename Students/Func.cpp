#include "Func.h"


double Average (int* grade)
{
    double sum=0;
    for (int i=0; i<5;i++)
    {
        sum=sum+grade[i];
    }
    sum=round((sum/5)*1000);
    sum=sum/1000;
    return sum;
}

double minGrade (vector<TStudent>& students, int percent)
{
    double AvGrades[students.size()];
    for (int i=0;i<students.size();i++)
    {
        AvGrades[i]=students[i].averageG;
    }
    sortM(AvGrades,students.size());
    return AvGrades[int(floor(students.size()*double(percent)/100))-1];
}

void sortM (double* AvGrade, int n)
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
}

void Read_from_file(vector<TStudent> &Student, string &name_direct_return, int mark)
{
    int number_of_students;
    string name_of_directory,
           name,
           name_of_file,
           reader;
    string end_of_line;
    bool stypendia;
    TStudent student;
    cout<<"Enter the name of directory: ";
    getline(cin,name_of_directory);
    name_direct_return=name_of_directory;
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
        file>>number_of_students;
        getline(file,end_of_line);
        for(int i=0; i<number_of_students;i++)
        {
            stypendia=true;
            getline(file,reader,',');
            student.name=reader;
            for(int j=0; j<5;j++)
            {
                getline(file,reader,',');
                student.grade[j]=stoi(reader);
                if (student.grade[j]<=mark)
                {
                    stypendia=false;
                }
            }
            getline(file,reader);
            student.averageG=Average(student.grade);
            if(reader=="TRUE")
            {
                student.contract=true;
                stypendia=false;
            }
            else
            {
                student.contract=false;
            }
            if (stypendia==true)
            {
                Student.push_back(student);
            }
        }
        file.close();

    }while(_findnext(handle,&data)==0);
    _findclose(handle);
}

void sort_Students(vector<TStudent> &Students)
{
    TStudent Buf;
    for(int i=0;i<Students.size();i++)
    {
        for(int j=i; j<Students.size();j++)
        {
            if(Students[i].averageG<Students[j].averageG)
            {
                Buf=Students[i];
                Students[i]=Students[j];
                Students[j]=Buf;
            }
        }
    }

}

void Output_rating(vector<TStudent> &Students, string &name_of_directory,int percent)
{
    ofstream file(name_of_directory+"/rating.csv");
    for(int i=0; i<Students.size();i++)
    {
        if(i<floor(Students.size()*double(percent)/100))
        {
            file<<Students[i].name<<","<<Students[i].averageG<<endl;
        }

    }
    file.close();
}

