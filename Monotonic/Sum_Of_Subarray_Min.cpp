#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> NSE(vector<int> &arr)
    {
        stack<int> st;
        vector<int> ans(arr.size(), arr.size());
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            ans[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> PSEE(vector<int> &arr)
    {
        stack<int> st;
        vector<int> ans(arr.size(), -1);
        for (int i = 0; i <= arr.size() - 1; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int> &arr)
    {
        vector<int> nse = NSE(arr);
        vector<int> psee = PSEE(arr);

        long long total = 0;
        int mod = 1e9 + 7;
        
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            total = (total + (left * right % mod) * arr[i]) % mod;
        }
        return (int)total;
    }   
};

int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution sh;
    cout<<sh.sumSubarrayMins(arr);
    return 0;
}