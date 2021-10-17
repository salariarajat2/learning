#include <bits/stdc++.h>
using namespace std;

//TC = O(N), SC = O(1)

bool areRotations(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}

int main()
{
    string str1 = "AACD", str2 = "ACDA";
    cout << areRotations(str1, str2);
    return 0;
}
