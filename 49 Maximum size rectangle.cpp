#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}



int histogramArea(int arr[],int n){
    stack<int> s;
    int res=0;
    for(int i=0;i<n;i++)
    {
     while(s.empty()==false&&arr[s.top()]>=arr[i])
     {
         int top=s.top();
         s.pop();
         int curr=arr[top]*(s.empty()?i:(i-s.top()-1));
         res=max(res,curr);
      }
     s.push(i);
    }
    while(!s.empty())
    {
        int tp=s.top();
        s.pop();
        int curr=arr[tp]*(s.empty()?n:(n-s.top()-1));
        res=max(res,curr);
    }
    return res;
    
}
int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    int max_area = 0;
    int *arr = new int[m];
    for(int j=0;j<m;j++){
        arr[j] = M[0][j];
    }
    int curr_area = histogramArea(arr, m);
    max_area = max(curr_area, max_area);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]==0){
                arr[j] =0;
            }
            else{
                arr[j]+=M[i][j];
            }
        }
        curr_area = histogramArea(arr,m);
        max_area = max(curr_area, max_area);
    }
    return max_area;
}



/*
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends


int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    
    int cur_row[m];
    int res=0;
    for(int i=0;i<m;i++)
    cur_row[i]=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(M[i][j]==0)
            cur_row[j]=0;
            
            else cur_row[j]++;
        }
        
        stack<int> s;
        
        int best_row_res=0;
        
        int k=0;
        
        while(k<m)
        {
            
            if(s.empty()||cur_row[k]>=cur_row[s.top()])
            {
                s.push(k);
                k++;
            }
            
            else
            {
                int top=s.top();
                s.pop();
                
                int possible_res;
                
                if(s.empty())
                possible_res=cur_row[top]*k;
                
                else possible_res=cur_row[top]*(k-s.top()-1);
                
                if(possible_res>best_row_res)
                best_row_res=possible_res;
            }
        }
        
        while(!s.empty())
        {
                int top=s.top();
                s.pop();
                
                int possible_res;
                
                if(s.empty())
                possible_res=cur_row[top]*k;
                
                else possible_res=cur_row[top]*(k-s.top()-1);
                
                if(possible_res>best_row_res)
                best_row_res=possible_res;
        }
        
        if(best_row_res>res)
        res=best_row_res;
        
    }
    
    return res;
    
}

/*
3
4 4
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
*/




