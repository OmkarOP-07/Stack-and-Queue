#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            next = NULL;
        }
};

class Stack {
    private:
    stack<pair<int,int>> st;
    public :
        Node* top;
        int size = 0;
        void push(int data){
            if(st.empty()){
                st.push({data,data});
            } else {
                st.push({data, min(data, st.top().second)});
            }
            Node* temp = new Node(data);
            temp->next = top;
            top = temp;
            size = size + 1;
        }

        void pop(){
            st.pop();
            Node* temp = top;
            top = top->next;
            delete temp;
            size = size-1;
        }

        int getSize(){
            return size;
        }

        int getTop(){
            return top->data;
        }
        int getMin(){
            return st.top().second;
        }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<"TOP now :"<<st.getTop()<<endl;
    st.pop();
    cout<<"TOP after popping out an element :"<<st.getTop()<<endl;
    cout<<"Size of the stack :"<<st.getSize()<<endl;
    cout<<"Min Val :"<<st.getMin();
 return 0;
}