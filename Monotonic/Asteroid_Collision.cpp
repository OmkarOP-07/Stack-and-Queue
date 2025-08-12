#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int i = 0; i < asteroids.size(); i++){
            if(asteroids[i] > 0 ) st.push_back(asteroids[i]);
            else {
               //if the stack has elements that could collide
               while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i]))
                    st.pop_back();
            
            if(!st.empty() && st.back() == abs(asteroids[i]))
                st.pop_back();
            else if(st.empty() || st.back() < 0)
                st.push_back(asteroids[i]);
            }
        }
        return st;
    }
};

int main()
{
    vector<int> arr = {5, 10, -5};
    Solution sh;
    vector<int> ans = sh.asteroidCollision(arr);
    for (auto it : ans){
        cout<<it<<" ";
    }
 return 0;
}