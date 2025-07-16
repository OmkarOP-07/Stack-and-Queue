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
    public :
        Node* top;
        int size = 0;
        void push(int data){
            Node* temp = new Node(data);
            temp->next = top;
            top = temp;
            size = size + 1;
        }

        void pop(){
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
 return 0;
}