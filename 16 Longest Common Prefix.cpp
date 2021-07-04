#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
// Function to find the longest common prefix between two strings
string LCP(string X, string Y)
{
    int i = 0, j = 0;
    while (i < X.length() && j < Y.length())
    {
        if (X[i] != Y[j]) {
            break;
        }
 
        i++, j++;
    }
 
    return X.substr(0, i);
}
 
// Function to find the longest common prefix (LCP) between a given set of strings
string findLCP(vector<string> &words)
{
    string prefix = words[0];
    for (string s: words) {
        cout<<"s- "<<s<<endl;
    	cout<<"prefix- "<<prefix<<endl;
        prefix = LCP(prefix, s);// s contains new string everytime and prefix contains the matching string.
    }
 
    return prefix;
}
 
int main()
{
    vector<string> words { "techie delight", "tech", "techie","technology", "technical" };
 
    cout << "The longest common prefix is " << findLCP(words);
 
    return 0;
}




/*



time complexity= O(no of strings * lenght of smallest string);
space complexity=O(1)



#include<iostream>
#include<algorithm>
  
using namespace std;
  
// Function to find the longest common prefix
string longestCommonPrefix(string ar[], int n)
{
  
    // If size is 0, return empty string
    if (n == 0)
        return "";
  
    if (n == 1)
        return ar[0];
  
    // Sort the given array
    sort(ar, ar + n);
  
    // Find the minimum length from 
    // first and last string
    int en = min(ar[0].size(), 
                 ar[n - 1].size());
  
    // Now the common prefix in first and 
    // last string is the longest common prefix
    string first = ar[0], last = ar[n - 1];
    int i = 0;
    while (i < en && first[i] == last[i])
        i++;
  
    string pre = first.substr(0, i);
    return pre;
}
  
// Driver Code
int main()
{
    string ar[] = {"geeksforgeeks", "geeks", 
                           "geek", "geezer"};
    int n = sizeof(ar) / sizeof(ar[0]);
    cout << "The longest common prefix is: "
         << longestCommonPrefix(ar, n);
    return 0;
}




#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
// Function to find the longest common prefix between two strings
string LCP(string X, string Y)
{
    int i = 0, j = 0;
    while (i < X.length() && j < Y.length())
    {
        if (X[i] != Y[j]) {
            break;
        }
 
        i++, j++;
    }
 
    return X.substr(0, i);
}
 
// A recursive function to find the longest common prefix (LCP) between a
// given set of strings
string findLCP(vector<string> const &words, int low, int high)
{
    // base case: if `low` is more than `high`, return an empty string
    if (low > high) {
        return string("");
    }
 
    // base case: if `low` is equal to `high`, return the current string
    if (low == high) {
        return words[low];
    }
 
    // find the mid-index
    int mid = (low + high) / 2;
 
    // partition the problem into subproblems and recur for each subproblem
    string X = findLCP(words, low, mid);
    string Y = findLCP(words, mid + 1, high);
 
    // return the longest common prefix of strings `X` and `Y`
    return LCP(X, Y);
}
 
int main()
{
    vector<string> words { "techie delight", "tech", "techie",
                        "technology", "technical" };
 
    cout << "The longest common prefix is "
         << findLCP(words, 0, words.size() - 1);
 
    return 0;
}*/
  
