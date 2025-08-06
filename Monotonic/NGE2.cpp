
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
       
        vector<int> ans(arr.size(), -1);
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= arr[i%n])
                st.pop();

            if (!st.empty())
                ans[i%n] = st.top();

            st.push(arr[i%n]);
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