#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string arr, int k) {
    stack<char> st;
    if(k >= arr.size())
        return "0";

    for (int i = 0; i < arr.size(); i++)
    {
        while(!st.empty() && k > 0 && st.top() >= arr[i]){
            st.pop();
            k--;
        }
        st.push(arr[i]);
    }
    string ans = "";
    while(k != 0){
        st.pop();
        k--;
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    while (ans.size() != 0 && ans.back() == '0')
    {
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s = "1432219";
    int k = 3;
    cout<<removeKdigits(s, k);
 return 0;
}