#include <bits/stdc++.h>
using namespace std;

bool is_safe(vector<vector<int>> &v, int row, int col, int x)
{
    for (int i = 0; i < 9; i++)
    {
        // checking row
        if (v[row][i] == x)
        {
            return 0;
        }

        // checking col
        if (v[i][col] == x)
        {
            return 0;
        }

        // checking small box
        if (v[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == x) // important line & formula used
        {
            return 0;
        }
    }
    return 1;
}

bool solve(vector<vector<int>> &v)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (v[row][col] == 0) // find empty space
            {
                for (int guess = 1; guess <= 9; guess++)
                {
                    if (is_safe(v, row, col, guess))
                    {
                        v[row][col] = guess;
                        bool age_ka = solve(v);
                        if (age_ka)
                        {
                            return 1;
                        }
                        else
                        {
                            v[row][col] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

bool sudoku_solver(vector<vector<int>> &v) // Time complexity = O(9^m)  m = no. of empty spaces, Time complexity = O(m)
{
    return solve(v);
}

int main()
{
    vector<vector<int>> v;
    for (int i = 0; i < 9; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 9; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }

    bool flag = sudoku_solver(v);

    if (flag)
    {
        cout << "PUZZLE SOLVED\n";
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "PUZZLE IMPOSSIBLE TO SOLVE\n";
    }

    return 0;
}