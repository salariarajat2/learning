#include <bits/stdc++.h>
using namespace std;

//TC = O(2^n)

void printSubsequence(string t, int i, int n, string input)
{
	if (i == n)
		cout << t << endl;
	else
	{
		printSubsequence(t, i + 1, n, input);
		t += input[i];
		printSubsequence(t, i + 1, n, input);
	}
}
int main()
{
	string input = "acd";
	printSubsequence("", 0, input.length(), input);
}
