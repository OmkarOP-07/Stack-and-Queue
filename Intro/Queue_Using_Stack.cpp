#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Queue{
    private:
        stack<int> s1;
        stack<int> s2;
    public:
    
    void push(int x){
        for (int i = 0; i < s1.size(); i++)
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        for (int i = 0; i < s2.size(); i++)
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
    cout<<q1.top()<<endl;
    q1.push(4);
    cout<<q1.top()<<endl;
    q1.push(5);
    cout<<q1.top()<<endl;

    q1.pop();
    cout<<q1.top()<<endl;
    q1.pop();
    cout<<q1.top()<<endl;
    q1.pop();
    cout<<q1.top();
 return 0;
}