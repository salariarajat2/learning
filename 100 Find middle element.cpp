#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(1), Space Complexity: O(1)

    int middle(int A, int B, int C){
        // int valu
        if((A > B and A < C) or (A < B and A > C)){
            return A;
            
        }
        if((B > A and B < C) or ( B < A and B > C)){
            return B;
        }
        if((C > B and C < A) or (C < B and C > A)){
            return C;
            
        }
    }
    
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}
