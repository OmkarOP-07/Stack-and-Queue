#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Queue{
    private:
        stack<int> s1;
        stack<int> s2;
    public:
    
    void push(int x){
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop(){
        s1.pop();
    }
    int top(){
        return s1.top();
    }
    int size(){
        return s1.size();
    }
};

int main()
{
    Queue q1;
    q1.push(3);
    q1.push(4);
    q1.push(5);
    
    cout<<q1.top()<<endl;
    q1.pop();
    cout<<q1.top()<<endl;
    q1.pop();
    cout<<q1.top();
 return 0;
}