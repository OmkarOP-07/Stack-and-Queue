// Brute Force Approach
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> PGE(vector<int> &arr)
{
    vector<int> ans(arr.size(), -1);
    stack<int> st;
    for (int i = 0; i <= arr.size() - 1; i++)
    {
        while (!st.empty() && st.top() <= 0)
            st.pop();
        ans[i] = st.empty() ? 0 : st.top();
        
        st.push(arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> PGE_Arr = PGE(arr);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout<<endl;
    for (auto it : PGE_Arr)
    {
        cout << it << " ";
    }
}