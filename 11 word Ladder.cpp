#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(N*M*26), Space Complexity: O(N) //n=length of wordlist , M = length of each word

int ladderLength(string start, string end, vector<string> &wordList)
{
    queue<string> q;
    q.push(start);
    unordered_set<string> word;
    for (int i = 0; i < wordList.size(); i++)
    {
        word.insert(wordList[i]);
    }

    if (word.find(end) == word.end())
        return 0;

    int len = 0;
    while (!q.empty())
    {
        len++;
        int qlen = q.size();
        for (int k = 0; k < qlen; k++)
        {
            string s = q.front();
            q.pop();
            for (int i = 0; i < start.size(); i++)
            {
                char c = s[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    s[i] = ch;
                    if (s == end)
                        return len + 1;
                    if (word.find(s) == word.end())
                        continue;

                    word.erase(s);
                    q.push(s);
                }
                s[i] = c;
            }
        }
    }
    return 0;
}

int main()
{
    string start = "hit", end = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout<<ladderLength(start, end, wordList);
}

// ans = 5
