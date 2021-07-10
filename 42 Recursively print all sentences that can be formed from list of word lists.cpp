#include <iostream>
#include <string>
#define R 3
#define C 3
using namespace std;
 
void printUtil(string arr[R][C], int m, int n, string result[R])
{
    
    result[m] = arr[m][n];// Add current word to result array
    if (m==R-1)// If it is the last word, then print
    {
        for (int i=0; i<R; i++)
        {
           cout << result[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i=0; i<C; i++) // Recur for next row
    {
       if (arr[m+1][i] != "")
       {
          printUtil(arr, m+1, i, result);
       }
    }
}

void printAllSentences(string arr[R][C])
{
   string result[R];
   for (int i=0; i<C; i++)
   {
     if (arr[0][i] != "")
     {
        printUtil(arr, 0, i, result);
     }
   }
}
 
int main()
{
   string arr[R][C]  = {{"you", "we"},{"have", "are"},{"sleep", "eat", "drink"}};
   printAllSentences(arr);
   return 0;
}
