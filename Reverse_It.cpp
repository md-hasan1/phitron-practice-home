#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    int roll_no;
    char section;
    int marks;
};
int main()
{
    int t;
    cin >> t;
    Student s[t];
    int point = t;
    for (int i = 0; i < t; i++)
    {
        cin >> s[i].name >> s[i].roll_no >> s[i].section >> s[i].marks;
    }
    for (int i = 0; i < point; i++)
    {
       
        swap(s[i].section, s[point - 1].section);
        point--;
    }
    for (int i = 0; i < t; i++){
        cout << s[i].name << " " << s[i].roll_no << " " << s[i].section << " " << s[i].marks << endl;
    }
    return 0;
}