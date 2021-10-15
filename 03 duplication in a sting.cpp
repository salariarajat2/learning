#include <bits/stdc++.h>
using namespace std;

//TC= O(N), SC = O(1)

void printDups(string str)
{
  unordered_map<char, int> count;
  for (int i = 0; i < str.length(); i++)
  {
    count[str[i]]++;
  }

  for (auto it : count)
  {
    if (it.second > 1)
      cout << it.first << ", count = " << it.second
           << "\n";
  }
}

int main()
{
  string str = "test string";
  printDups(str);
  return 0;
}

/*
boolean shuffleCheck(String first, String second, String result)
{

  if (first.length() + second.length() != result.length())
  {
    return false;
  }

  int i = 0, j = 0, k = 0;

  while (k != result.length())
  {

    if (i < first.length() && first.charAt(i) == result.charAt(k))
      i++;

    else if (j < second.length() && second.charAt(j) == result.charAt(k))
      j++;

    else
    {
      return false;
    }

    k++;
  }

  if (i < first.length() || j < second.length())
  {
    return false;
  }

  return true;
}

int main()
{

  string first = "XY";
  string second = "12";
  string[] results = {"1XY2", "Y12X"};

  for (string result : results)
  {
    if (shuffleCheck(first, second, result) == true)
    {
      System.out.println(result + " is a valid shuffle of " + first + " and " + second);
    }
    else
    {
      System.out.println(result + " is not a valid shuffle of " + first + " and " + second);
    }
  }
}





//TC= O(N^2), SC = O(1)

int main()
{
  char string[80];
  cout << "Enter string: ";
  cin.getline(string, 80);
  cout << "Duplicate characters are following" << endl;
  for (int i = 0; i < strlen(string); i++)
  { // nested loop statement
    for (int j = i + 1; j < strlen(string); j++)
    {
      if (string[i] == string[j])
      {                            // logic to detect duplicate character
        cout << string[i] << endl; // duplicate character
        break;
      }
    }
  }
  return 0;
}


*/
