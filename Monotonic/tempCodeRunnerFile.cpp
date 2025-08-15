class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < arr.size(); i++) {
            
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int el = st.top(); st.pop();
                int nse = i;
                int pse = st.empty()?-1: st.top();
                maxArea = max(arr[el]*(nse-pse-1), maxArea);
            }
            st.push(i);
        }
        return maxArea;
    }
};
