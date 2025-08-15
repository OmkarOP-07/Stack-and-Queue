#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &arr) {
    stack<int> st;
    int n = arr.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            int el = st.top();
            st.pop();
            int left = st.empty() ? -1 : st.top();
            int right = i;
            ans = max(ans, arr[el] * (right - left - 1));
        }
        st.push(i);
    }
    while (!st.empty()) {
        int el = st.top();
        st.pop();
        int left = st.empty() ? -1 : st.top();
        int right = n;
        ans = max(ans, arr[el] * (right - left - 1));
    }
    return ans;
}

int maximalRectangle(vector<vector<char>> &arr) {
    int rows = arr.size();
    if (rows == 0) return 0;
    int cols = arr[0].size();
    
    vector<vector<int>> ans(rows, vector<int>(cols, 0));
    
    // Build histogram heights
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == '0')
                ans[i][j] = 0;
            else
                ans[i][j] = (i == 0 ? 1 : ans[i-1][j] + 1);
        }
    }

    int maxArea = 0;
    for (int i = 0; i < rows; i++) {
        maxArea = max(maxArea, largestRectangleArea(ans[i]));
    }
    return maxArea;
}

int main() {
    vector<vector<char>> arr = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    cout << maximalRectangle(arr);
    return 0;
}
