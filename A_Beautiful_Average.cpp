#include<bits/stdc++.h>
using namespace std;
int main() {
int t;
cin>>t;
    while (t--)
    {
        int max=INT_MIN;
        int n;
        cin>>n;
       int arr[n];
       for(int i=0 ;i<n;i++){
        int el;
        cin>>el;
        if(max<el){
            max=el;
        }
       
       }
       cout<<max<<endl;
    }
    
    return 0; 
}