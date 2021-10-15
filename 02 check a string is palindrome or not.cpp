#include <bits/stdc++.h>
using namespace std;
int main()
{
  cout << "enter the string value";
  string str;
  getline(cin, str);

  string s = str;
  reverse(str.begin(), str.end());
  if (s == str)
  {
    cout << "the string is a palindrome" << endl;
  }
  else
  {
    cout << "string is not a palindrome" << endl;
  }
  return 0;
}
