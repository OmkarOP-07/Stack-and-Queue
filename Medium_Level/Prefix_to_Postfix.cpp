#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string Prefix_to_Postfix(string s){
    int n = s.size()-1;
    stack<string> st;
    while(n >= 0){
        if(s[n] >= 'A' && s[n] <= 'Z'
        || s[n] >= 'a' && s[n] <= 'z'){
            st.push(string(1,s[n]));
        }
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string temp = t1 + t2 + s[n];
            st.push(temp);
        }
        n--;
    }
    return st.top();
}

int main()
{
    string s = "*+AB-CD";
    cout<<"Postfix expression :"<<Prefix_to_Postfix(s);
 return 0;
}