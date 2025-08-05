#include<iostream>
#include<bits/stdc++.h>
using namespace std;


string postfix_to_infix(string s){
    stack<string> st;
    int i = 0;
    while(i < s.size()){
        if(s[i] >= 'A' && s[i] <= 'Z' ||
           s[i] >= 'a' && s[i] <= 'z') {
            st.push(string(1,s[i]));
        } else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string tempTop = "(" + t2 + s[i] + t1 + ")";
            st.push(tempTop);
        }
        i++;
    }
    return st.top();
}

int main()
{
    string s = "AB-DE+F*/";
    cout<<"Input :"<<s<<endl;
    cout<<"Output :"<<postfix_to_infix(s);
    return 0;
}