#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> &arr) {
    vector<int> ans(arr.size(), arr.size()); // default = arr.size() if none found
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
        ans[i] = st.empty() ? arr.size() : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> PGEE(vector<int> &arr) {
    vector<int> ans(arr.size(), -1); // default = -1 if none found
    stack<int> st;
    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

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

    for (int i = 0; i < arr.size(); i++)
    {
        long long left = i - psee[i];
        long long right = nse[i] - i;
        total = (total + (left * right % mod) * arr[i]) % mod;
    }
    return (int)total;
}

int sumSubarrayMaxs(vector<int> &arr)
{
    vector<int> nge = NGE(arr);
    vector<int> pge = PGEE(arr);

    long long total = 0;
    int mod = 1e9 + 7;

    for (int i = 0; i < arr.size(); i++) {
        long long left = i - pge[i];
        long long right = nge[i] - i;
        total = (total + (left * right % mod) * arr[i]) % mod;
    }
    return (int)total;
}

long long subArrayRanges(vector<int> &arr)
{
    return sumSubarrayMaxs(arr) - sumSubarrayMins(arr);
}

int main()
{
    vector<int> arr = {1,3,3};
    cout<<sumSubarrayMaxs(arr);

    return 0;
}