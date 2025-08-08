// Brute Force Approach
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> &arr)
{
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
}
vector<int> PGE(vector<int> &arr)
{
    vector<int> ans(arr.size(), -1);
    stack<int> st;
    for (int i = 0; i <= arr.size() - 1; i++)
    {
        while (!st.empty() && st.top() <= 0)
            st.pop();
        ans[i] = st.empty() ? 0 : st.top();
        
        if(!st.empty()){
            if(arr[i] >= st.top()){
                st.push(arr[i]);
            }
        }
        else {
            st.push(arr[i]);
        }
    }
    return ans;
}


int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> NGE_Arr = NGE(arr);
    vector<int> PGE_Arr = PGE(arr);
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (NGE_Arr[i] != 0 && PGE_Arr[i] != 0)
        {
            if( NGE_Arr[i] > arr[i] && PGE_Arr[i] > arr[i] )
                count = count + abs(NGE_Arr[i] - PGE_Arr[i]);
                
        }
        // cout<<count<<endl;
    }
    cout<<count;
    return 0;
}

//1 2 2 3 3 1 3 -1 -1 2 -1 -1
//1 2 2 3 3 1 3  0  0 2  0  0 