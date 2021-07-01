#include <iostream>
#include<string.h>
using namespace std;
int main()
{
    char string[80];
    cout<<"Enter string: ";
    cin.getline(string,80);
    cout<<"Duplicate characters are following"<<endl;
    for(int i=0;i<strlen(string);i++){                     // nested loop statement
        for(int j=i+1;j<strlen(string);j++){
            if(string[i]==string[j]){                   // logic to detect duplicate character
                cout<<string[i]<<endl;                  // duplicate character
                break;
            }
        }
    }
    return 0;
}
/*



boolean shuffleCheck(String first, String second, String result) {

 
    if(first.length() + second.length() != result.length()) {
      return false;
    }
   
    int i = 0, j = 0, k = 0;

 
    while (k != result.length()) {

     
      if (i < first.length() && first.charAt(i) == result.charAt(k))
        i++;

      
      else if (j < second.length() && second.charAt(j) == result.charAt(k))
        j++;

     
      else {
        return false;
      }

   
      k++;
    }


    if(i < first.length() || j < second.length()) {
      return false;
    }

    return true;
  }

int main() {

    string first = "XY";
    string second = "12";
    string[] results = {"1XY2", "Y12X"};

    for (string result : results) {
      if (shuffleCheck(first, second, result) == true) {
        System.out.println(result + " is a valid shuffle of " + first + " and " + second);
      }
      else {
        System.out.println(result + " is not a valid shuffle of " + first + " and " + second);
      }
    }
  }







#include <bits/stdc++.h>
using namespace std;
void printDups(string str)
{    int c=0,max=0;
    map<char, int> count;
    for (int i = 0; i < str.length(); i++) {
        count[str[i]]++;
    }
 
    for (auto a :count) {
        if (a.second > 1)
        {
        
        	if(max<a.second)
        	{
        		max=a.second;
			}
        	cout << a.first << ", count = " << a.second<<"\n";
        	 c++;
		}
    }
    cout<<"char repeating highest is  "<<max<<endl;
    cout<<"the total repeting char are  "<<c;
}
int main()
{
    string str = "testrrrrstring";
    
    printDups(str);
    return 0;
}
*/

