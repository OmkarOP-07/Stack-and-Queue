// Brute Force Approach
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> funct(vector<vector<int>> &arr)
{
    int rows = static_cast<int>(arr.size());
    int cols = static_cast<int>(arr[0].size());

    for (int i = 1; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] != 0)
            {
                arr[i][j] += arr[i - 1][j];
            }
        }
    }
    return arr;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}};
    arr = funct(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}