#include<iostream>
#include<bits/stdc++.h>
using namespace std;



    class Solution {
    public:
        int priority(char ch){
            if(ch == '^') return 3;
            else if(ch == '*' || ch == '/') return 2;
            else if(ch == '+' || ch == '-') return 1;
            else return -1;
        }

        string Infix_To_Postfix(string s) {
            int i = 0;
            stack<char> st;
            string ans;
            while (i < s.size())   
            {
                if(s[i] >= 'A' && s[i] <= 'Z' ||
                s[i] >= 'a' && s[i] <= 'z' ||
                s[i] >= '0' && s[i] <= '9'){
                    ans += s[i];
                } else if (s[i] == '(')
                {
                    st.push(s[i]);
                } else if (s[i] == ')'){
                    while (!st.empty() && st.top() != '(')
                    {
                        ans += st.top();
                        st.pop();
                    }
                    if (!st.empty()) st.pop();
                }
                else {
                    while(!st.empty() && priority(s[i]) <= priority(st.top())){
                        ans += st.top();    
                        st.pop();
                    }
                    st.push(s[i]);
                }
                i++;
            }
            while(!st.empty()){
                ans += st.top();
                st.pop();
            }
            return ans;
        }
    };

int main()
{
    Solution sh;
    cout<<sh.Infix_To_Postfix("a+b*(c^d-e)^(f+g*h)-i");
 return 0;
}