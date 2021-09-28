#include <bits/stdc++.h>
using namespace std;
// TC- O(log(N))
int main()
{
    int n, nb;
    cin >> n >> nb;
    int *a = new int(n);
    int *b = new int(nb);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < nb; i++)
    {
        cin >> b[i];
    }
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);
    for (int i = 0; i < nb; i++)
        s.insert(b[i]);
    return s.size();

    return 0;
}

/*
    
  set<int> s;
        for(int i=0;i<n;i++)
        {
            s.insert(a[i]);
        }
        for(int i=0;i<nb;i++)
        {
            s.insert(b[i]);
        }
        cout<<s.size();
    
    
    unordered_map <int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[a[i]]++;
    }
    for(int j=0;j<m;j++)
    {
        mp[b[j]]++;
    }
    return mp.size();
    
    */



/* for intersection

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  unordered_map<int, int> mp;
    vector<int> v;
    set<int> s;

    for (int i = 0; i < nums1.size(); i++)
    {
        mp[nums1[i]]++;
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        if (mp[nums2[i]])
        {
            s.insert(nums2[i]);
            mp.erase(nums2[i]);
        }
    }

    for (auto it : s)
    {
        v.push_back(it);
    }
    return v;
    }
};

*/