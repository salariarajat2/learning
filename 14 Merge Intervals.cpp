#include<bits/stdc++.h>
using namespace std;
//TC=O(nlogn)  SC=O(1)
struct Interval
{
    int s, e;
};
 
bool mycomp(Interval a, Interval b)
{ return a.s < b.s; }
 
void mergeIntervals(Interval arr[], int n)
{
    sort(arr, arr+n, mycomp);
 
    int index = 0; 
    for (int i=1; i<n; i++)
    {
        if (arr[index].e >=  arr[i].s)
           {
               // Merge previous and current Intervals
            arr[index].e = max(arr[index].e, arr[i].e);
           arr[index].s = min(arr[index].s, arr[i].s);
        }
        else {
            index++;
            arr[index] = arr[i];
        }   
    }
    cout << "\n The Merged Intervals are: ";
    for (int i = 0; i <= index; i++)
        cout << "[" << arr[i].s << ", " << arr[i].e << "] ";
}

 int main()
{
    Interval arr[] = { {1,4}, {11,12}, {5,10}, {7,10}, {2,4} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}
 
 /*
 
//TC=O(nlogn)  SC=O(n)
struct Interval
{
    int start, end;
};
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}
 
void mergeIntervals(Interval arr[], int n)
{
    if (n <= 0)
        return;

    stack<Interval> s;
    sort(arr, arr+n, compareInterval);
    s.push(arr[0]);
    for (int i = 1 ; i < n; i++)
    {
        Interval top = s.top();

        if (top.end < arr[i].start)
            s.push(arr[i]);
            
        else if (top.end < arr[i].end)
        {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }
    cout << "\n The Merged Intervals are: ";
    while (!s.empty())
    {
        //Interval t = s.top();
        cout << "[" << s.top().start << "," << s.top().end << "] ";
        s.pop();
    }
    return;
}

int main()
{
    Interval arr[] = { {1,4}, {11,12}, {5,10}, {7,10}, {2,4} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}
 */
 

 
/* 
 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
    
    */
