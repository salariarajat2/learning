#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e, i;
    cin >> n >> e;
    vector<int> adj_1[n];
    vector<int> adj_2[n];
    for (i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_1[u].push_back(v);
    }
    for (i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_2[u].push_back(v);
    }
    for (i = 0; i < n; i++)
    {
        reverse(adj_1[i].begin(), adj_1[i].end());
    }
    int flag = 0;
    for (i = 0; i < n; i++)
    {
        if (adj_1[i] != adj_2[i])
        {
            flag = 1;
            cout << "0" << endl;
            break;
        }
    }
    if (flag == 0)
        cout << "1" << endl;
}

/*
3 2
1 2 1 3
1 3 1 2

ans = 1
*/




/*
// Time Complexity: O(N^2), Auxiliary Space: O(n)

void mirror(int lTree[], int rTree[], int nodes, int n)
{
    stack<int> st;
    queue<int> q;
    int temp[n], count = 0;
    st.push(lTree[0]);
    q.push(rTree[0]);
    while (!st.empty() && !q.empty())
    {
        int a = st.top();
        int b = q.front();
        if (a != b)
            break;
        st.pop();
        q.pop();
        for (int i = 0; i < n - 1; i++)
            if (lTree[i] == a && i % 2 == 0)
                st.push(lTree[i + 1]);
        while (!q.empty())
        {
            temp[count++] = q.front();
            q.pop();
        }
        for (int j = 0; j < n - 1; j++)
            if (rTree[j] == b && j % 2 == 0)
                q.push(rTree[j + 1]);
        for (int i = 0; i < count; i++)
            q.push(temp[i]);
        count = 0;
    }
    if (st.empty() && q.empty())
        cout << 1;
    else
        cout << 0;
}


*/



/*
// Time Complexity: O(N), Auxiliary Space: O(n^2)

int checkMirrorTree(int M, int N, int u1[ ], int v1[ ] , int u2[], int v2[]) 
    {

        unordered_map<int , stack<int>>mp;
   
        // Traverse first tree nodes
        for (int i = 0 ; i < N ; i++ )
        {
           mp[u1[i]].push(v1[i]);
        }
         
        // Traverse second tree nodes
        for (int i = 0 ; i < N ; i++)
        {
            if(mp[u2[i]].top() != v2[i]) 
                  return 0;
            mp[u2[i]].pop();
        }
   
        return 1;
    }
 
// Driver code
int main()
{
    int M = 7, N = 6;
     
    //Tree 1
    int u1[] = { 1, 1, 1, 10, 10, 10 };
    int v1[] = { 10, 7, 3, 4, 5, 6 };
   
    //Tree 2
    int u2[] = { 1, 1, 1, 10, 10, 10 };
    int v2[] = { 3, 7, 10, 6, 5, 4 };
 
    if(checkMirrorTree(M, N, u1, v1, u2, v2))
       cout<<"Yes";
    else
       cout<<"No";
   
    return 0;
}

*/
