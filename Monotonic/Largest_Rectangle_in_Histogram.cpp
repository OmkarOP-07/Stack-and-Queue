#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                int el=st.top();
                st.pop();
                int left=st.empty()?-1:st.top();
                int right=i;
                ans=max(ans,arr[el]*(right-left-1));
            }
            st.push(i);
        }
         while(!st.empty()){
                int el=st.top();
                st.pop();
                int left=st.empty()?-1:st.top();
                int right=n;
                ans=max(ans,arr[el]*(right-left-1));
            }
        return ans;
    }
};


int main() {
    Solution sh;
    vector<int> arr = {2,1,5,6,2,3};
    cout << sh.largestRectangleArea(arr);
}
