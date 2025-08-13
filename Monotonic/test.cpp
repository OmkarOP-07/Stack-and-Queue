// Brute Force Approach
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> PGEE(vector<int> &arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), -1);
    for (int i = 0; i <= arr.size() - 1; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}
int main()
{
    vector<int> arr = {3, 2, 1, 5, 8, 2, 9};
    vector<int> PGE_Arr = PGEE(arr);
    for (auto it : PGE_Arr)
    {
        cout << it << " ";
    }
}