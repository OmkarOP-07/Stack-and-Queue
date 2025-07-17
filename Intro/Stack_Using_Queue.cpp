#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack {
    public: 
        queue<int> q;
        void push(int data){
            int size = q.size();
            q.push(data);
            for(int i = 0; i < size; i++){
                q.push(q.front());
                q.pop();
            }
        }
        void pop(){
            q.pop();
        }
        
        int top(){
            return q.front();
        }
        bool isEmpty(){
            return q.empty();
        }
};

int main()
{
    Stack st;
    st.push(8);
    st.push(3);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
 return 0;
}