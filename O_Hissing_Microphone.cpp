#include<bits/stdc++.h>
using namespace std;
int main() {

    string s;
    cin>>s;
    stack<char> st;
int flag=0;
    for (char c:s)
    {
        if(c=='s'&&!st.empty()&&c==st.top()){
            flag=1;
        }
        st.push(c);
    }
    
    if(flag){
        cout<<"hiss";
    }else{
        cout<<"no hiss";
    }
    return 0; 
}