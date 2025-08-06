#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> ans(arr1.size(), -1);
        vector<int> temp(arr2.size(), -1);
        stack<int> st;
        for (int i = arr2.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= arr2[i])
                st.pop();

            if (st.empty())
                temp[i] = -1;
            else
                temp[i] = st.top();

            st.push(arr2[i]);
        }

        for (int i = 0; i <arr1.size(); i++)
        {
            int j = 0;
            while (arr1[i] != arr2[j])
            {
                j++;
            }
            ans[i] = temp[j];
        }
        return ans;
    }
};

int main()
{
    vector<int> arr1 = {4,1,2};
    vector<int> arr2 = {1,3,4,2};
    Solution sh;
    vector<int> ans = sh.nextGreaterElement(arr1,arr2);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}