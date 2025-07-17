#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            next = NULL;
        }
};

class myQueue {
    public:
        int size = 0;
        Node* start = NULL;
        Node* end = NULL;
        
        void enqueue(int data){
            Node* temp = new Node(data);
                if(start == NULL && end == NULL){
                    start = temp;
                    end = temp;
                    temp->next = NULL;
                    return;
                }
                end->next = temp;
                end = temp;
            size = size+1;
        }

        void dequeue(){
            if(start == NULL && end == NULL){
                cout<<"queue is empty"<<endl;
                return;
            }
            if(start == end){
                Node* temp = start;
                start = NULL;
                end = NULL;
                delete temp;
                size = size - 1;
            } else {
                Node* temp = start;
                start = start->next;
                delete temp;
                size = size -1;
            }
        }
        int top(){
            return start->data;
        }
};

int main()
{
    myQueue q;
    q.enqueue(9);
    q.enqueue(5);
    cout<<q.top()<<endl;
    q.dequeue();
    cout<<q.top();
 return 0;
}