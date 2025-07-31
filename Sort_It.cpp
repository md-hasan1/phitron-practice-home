#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int cls;
    string section;
    int id;
    int math_marks;
    int eng_marks;
};

bool compare(Student a, Student b)
{
    int s1 = a.math_marks + a.eng_marks;
    int s2 = b.math_marks + b.eng_marks;
    if (s1 == s2)
    {
        return a.id < b.id;
    }
    else
    {
        return s1 > s2;
    }
}
int main()
{
    int n;
    cin>>n;
    Student s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].name >> s[i].cls >> s[i].section >> s[i].id >> s[i].math_marks >> s[i].eng_marks;
    }

 
        sort(s, s + n, compare);
    
    for (int i = 0; i < n; i++)
    {
        cout << s[i].name << " " << s[i].cls << " " << s[i].section << " " << s[i].id << " " << s[i].math_marks << " " << s[i].eng_marks << endl;
    }

    return 0;
}