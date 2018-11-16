#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

struct Student{
    string Name;
    string GroupId;
    map <string,unsigned> Ratings;
};

void Print(const vector<Student> &s);

void showmenu();

array <string, 5> subj={"Physics","Maths", "Foreign", "History", "Political Science"};

int main() {
vector <Student> students(5);
    students[0].Name="Alex";
    students[1].Name="John";
    students[2].Name="Bob";
    students[3].Name="Kate";
    students[4].Name="Ann";
    for (int i=0;i<5;i++)
        students[i].GroupId="IU8-33";
    for(int i=0;i<5;i++)
    {
        students[i].Ratings.insert(pair<string,unsigned>(subj[4],4));
    }
    for(int i=0;i<5;i++)
    {
        int a,b,c,d;
        cout<<"Enter marks for "<<students[i].Name<<":"<<endl;
        cout<<subj[0]<<": ";
        cin>>a;
        cout<<subj[1]<<": ";
        cin>>b;
        cout<<subj[2]<<": ";
        cin>>c;
        cout<<subj[3]<<": ";
        cin>>d;
        students[i].Ratings={{subj[0],a},
                            {subj[1],b},
                            {subj[2],c},
                            {subj[3],d}};

    }
    showmenu();
    int choice;
    cin>>choice;
    while (choice!=6)
    {
        switch (choice)
        {
            case 1:
            {
                vector<string> names;
                for (int i=0;i<5;i++)
                {
                    names.push_back(students[i].Name);
                }
                sort(names.begin(),names.end());
                for (int i=0;i<5;i++)
                    cout<<names[i]<<endl;
            }
                break;
            case 2:
            {
                sort(students.begin(), students.end(), [](Student &s1, Student &s2)
                {
                    return (s1.Ratings["Phisics"]+s1.Ratings["Maths"]+s1.Ratings["Foreign"]+s1.Ratings["History"]+s1.Ratings["Political Science"]) / 5 >
                           (s2.Ratings["Phisics"]+s2.Ratings["Maths"]+s2.Ratings["Foreign"]+s2.Ratings["History"]+s2.Ratings["Political Science"]) / 5;
                });
Print(students);

                cout << endl;
            }
                break;
            case 3:
            {
                cout << count_if(students.begin(), students.end(), [](Student &s)
                {
                    return s.Ratings["Physics"]==2 || s.Ratings["Maths"]==2 ||
                           s.Ratings["Foreign"]==2 || s.Ratings["History"]==2 || s.Ratings["Political Science"]==2;
                });
                cout << " students have an unsatisfactory grade in at least one subject." << endl;
            }
                break;
            case 4:
            {
                cout << count_if(students.begin(), students.end(), [](Student &s)
                {
                    return s.Ratings["Physics"]==5 && s.Ratings["Maths"]==5 &&
                           s.Ratings["Foreign"]==5 && s.Ratings["History"]==5 && s.Ratings["Political Science"]==5;
                });
                cout << " students passed all exams for an excellent mark." << endl<<endl;
            }
                break;
            case 5:{
                vector<Student> exlents;
                copy_if(students.begin(), students.end(), back_inserter(exlents), [](Student &s)
                {
                    return s.Ratings["Maths"] == 5;
                });

                for (auto stud : exlents)
                {
                    cout << stud.Name << endl;
                }
                cout << endl;
            }
                break;
            default:
                cout << "Thats not a choice!" << endl;
        }
        cout<<endl;
        showmenu();
        cin>>choice;
    }
    return 0;
}

void showmenu(){
    cout<<"Menu:\n1)Sort by name\t\t2)Sort by average\n3)Unsatisfactory\t4)Excellent\n5)Maths(exc)\t\t6)Quit\n";
}

void Print(const vector<Student> &s)
{
    for (auto el : s)
    {
        cout << el.Name <<". Average rating: "<<double(el.Ratings["Phisics"]+el.Ratings["Maths"]+el.Ratings["Foreign"]+el.Ratings["History"]+el.Ratings["Political Science"])/ 5 <<endl;
    }
}
