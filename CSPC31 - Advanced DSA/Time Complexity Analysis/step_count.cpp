/*
 *  Comparing the execution time with the step count for analysis and
 *  deduction of the time complexity of the following algorithms.
 */

#include <ctime>
#include <iostream>
#include <stack>
using namespace std;

int A[5][5] = {
    {0, 1, 2, 3, 4},
    {5, 6, 7, 8, 9},
    {0, 1, 2, 3, 4},
    {5, 6, 7, 8, 9},
    {0, 1, 2, 3, 4},
};
int B[5][5] = {
    {5, 6, 7, 8, 9},
    {0, 1, 2, 3, 4},
    {5, 6, 7, 8, 9},
    {0, 1, 2, 3, 4},
    {5, 6, 7, 8, 9},
};

void matrix_addition() {
    int sum[5][5];

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            sum[i][j] = A[i][j] + B[i][j];
}

void matrix_multiplication() {
    int product[5][5];

    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j) {
            product[i][j] = 0;
            for(int k = 0; k < 5; ++k)
                product[i][j] += A[i][k] * B[k][j];
        }
}

void stack_operations() {
    stack<int> s;

    // step count:
    // i = 0           --> 1
    // i < 100000      --> n - 1
    // i++             --> n - 1
    // loop            --> 3n - 1
    for (int i = 0; i < 100000; i++) {
        s.push(i);
    }

    int top = s.top();

    while (!s.empty()) {
        s.pop();
    }
}

int main() {
    int n = 50;
    clock_t exec_time;
    clock_t avg_exec_time;

    avg_exec_time = 0;
    for (int i = 0; i < n; i++) {
        exec_time = clock();
        matrix_addition();
        avg_exec_time += clock() - exec_time;
    }
    avg_exec_time /= n;
    cout << "Matrix Addition --> " << (float)avg_exec_time/CLOCKS_PER_SEC << endl;

    avg_exec_time = 0;
    for (int i = 0; i < n; i++) {
        exec_time = clock();
        matrix_multiplication();
        avg_exec_time += clock() - exec_time;
    }
    avg_exec_time /= n;
    cout << "Matrix Multiplication --> " << (float)avg_exec_time/CLOCKS_PER_SEC << endl;

    avg_exec_time = 0;
    for (int i = 0; i < n; i++) {
        exec_time = clock();
        stack_operations();
        avg_exec_time += clock() - exec_time;
    }
    avg_exec_time /= n;
    cout << "Stack Operations --> " << (float)avg_exec_time/CLOCKS_PER_SEC << endl;
}
