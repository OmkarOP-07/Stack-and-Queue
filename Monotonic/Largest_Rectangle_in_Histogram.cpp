#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> NSE(vector<int> &arr) {
        stack<int> st;
        vector<int> ans(arr.size(), arr.size());
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> PSE(vector<int> &arr) {
        stack<int> st;
        vector<int> ans(arr.size(), -1);
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& arr) {
        if (arr.size() == 1) return arr[0];
        
        vector<int> NSE_arr = NSE(arr);
        vector<int> PSE_arr = PSE(arr);

        int greatest = 0;
        for (int i = 0; i < arr.size(); i++) {
            int width = NSE_arr[i] - PSE_arr[i] - 1;
            int area = arr[i] * width;
            greatest = max(greatest, area);
        }
        return greatest;
    }
};

int main() {
    Solution sh;
    vector<int> arr = {2,1,5,6,2,3};
    cout << sh.largestRectangleArea(arr);
}
