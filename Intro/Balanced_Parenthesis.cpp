#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if(s[i] == '(' || s[i] == '{' || s[i] == '['){
//                 st.push(s[i]);
//             } else {
//                 switch (s[i])
//                 {
//                 case ')':
//                     if(st.top() == '(') 
//                     st.pop();
//                     else 
//                     return false;
//                     break;
//                 case ']':
//                     if(st.top() == '[') 
//                     st.pop();
//                     else 
//                     return false;
//                     break;
//                 case '}':
//                     if(st.top() == '{') 
//                     st.pop();
//                     else 
//                     return false;
//                 break;
//                 default:
//                     break;
//                 }
//             }
//         }
        
//         if(!st.empty()) return false;

//         return true;
//     }
// };

class Solution {
    public:
        bool isValid(string s){
             stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            } else {
                if(st.empty()) return false;
                char ch = st.top();
                if(s[i] == ')' && ch == '('
                || s[i] == ']' && ch == '['
                || s[i] == '}' && ch == '{'){
                    st.pop();
                } else {
                    return false;
                };
            }
        }
        return st.empty();
    }
};

int main()
{
    string str = "{}]";
    Solution s1;
    cout<<s1.isValid(str);
 return 0;
}