#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string pretfix_to_infix(string s){
    stack<string> st;
    int n = s.size()-1;
    while(n >= 0){
        if(s[n] >= 'A' && s[n] <= 'Z' ||
           s[n] >= 'a' && s[n] <= 'z') {
            st.push(string(1,s[n]));
        } else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string tempTop = "(" + t1 + s[n] + t2 + ")";
            st.push(tempTop);
        }
        n--;
    }
   
    return st.top();
}

int main()
{
    string s = "*+AB-CD";
    cout<<pretfix_to_infix(s);
 return 0;
}