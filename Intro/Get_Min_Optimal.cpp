#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> stk;
    int minVal = INT_MAX;
public:

    void push(int val) {
        if(stk.empty()){
            stk.push(val);
            minVal = val;
        } else {
            if(val > minVal){
                stk.push(val);
            }
            else {
                stk.push(2*val-minVal);
                minVal = val;
            }
        }
    }
    
    void pop() {
        if(stk.empty()) return;
        if(stk.top() > minVal){
            stk.pop();
        }
        else {
            int tempTop = stk.top();
            stk.pop();
            minVal = 2*minVal - tempTop; 
        }
    }
    
    int top() {
        if(stk.empty()) return 0;
        if(stk.top() > minVal) return stk.top();
        else {
            return minVal;
        }
    }
    
    int getMin() {
        return minVal;
    }
};

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout<<minStack.getMin()<<endl; // return -3
    minStack.pop();
    cout<<minStack.top();    // return 0
    minStack.getMin();
 return 0;
}