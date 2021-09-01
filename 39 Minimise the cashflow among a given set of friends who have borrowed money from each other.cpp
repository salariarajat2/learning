#include <bits/stdc++.h>
using namespace std;
#define N 3

// Time Complexity: O(N^2)

int getMin(int amount[])
{
    int minInd = 0;
    for (int i = 1; i < N; i++)
        if (amount[i] < amount[minInd])
            minInd = i;
    return minInd;
}

int getMax(int amount[])
{
    int maxInd = 0;
    for (int i = 1; i < N; i++)
        if (amount[i] > amount[maxInd])
            maxInd = i;
    return maxInd;
}

void minCashFlowRec(int amount[])
{
    int mxCredit = getMax(amount), mxDebit = getMin(amount);

    if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
        return;

    int mi = min(-amount[mxDebit], amount[mxCredit]);
    amount[mxCredit] -= mi;
    amount[mxDebit] += mi;

    cout << "Person " << mxDebit << " pays " << mi
         << " to "
         << "Person " << mxCredit << endl;

    minCashFlowRec(amount);
}

void minCashFlow(int graph[][N])
{
    int amount[N] = {0};

    for (int p = 0; p < N; p++)
        for (int i = 0; i < N; i++)
            amount[p] += (graph[i][p] - graph[p][i]);

    minCashFlowRec(amount);
}

// Driver program to test above function
int main()
{
    int graph[N][N] = {
        {0, 1000, 2000},
        {0, 0, 5000},
        {0, 0, 0},
    };

    minCashFlow(graph);
    return 0;
}

