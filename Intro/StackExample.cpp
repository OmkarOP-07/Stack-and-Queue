#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;


int main()
{
    queue<char> name;
    name.push('O');
    name.push('M');
    name.push('K');
    name.push('A');
    name.push('R');
    cout<<name.front()<<endl;
    name.pop();
    cout<<name.front()<<endl;
    name.pop();
    cout<<name.front()<<endl;
    name.pop();
    cout<<name.front()<<endl;
    name.pop();
    cout<<name.front()<<endl;
    name.pop();
 return 0;
 
}