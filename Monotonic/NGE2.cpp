
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> tmparr = arr;
        for (int i = 0; i < n; i++)
            tmparr.push_back(arr[i]);

        vector<int> ans(arr.size(), -1);
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= tmparr[i])
                st.pop();

            if (!st.empty())
                ans[i%n] = st.top();

            st.push(tmparr[i]);
        }
        return ans;
    }
};
int main()
{
    vector<int> arr = {1,2,1};
    vector<int> ans;
    Solution sh;
    ans = sh.nextGreaterElements(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}