#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> &arr)
{
    vector<int> ans(arr.size(), -1);
    stack<int> st;
    for (int i = arr.size()-1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();

        ans[i] = st.empty() ? -1:st.top();

        st.push(arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 1, 6, 3, 2};
    vector<int> ans;
    ans = solution(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}