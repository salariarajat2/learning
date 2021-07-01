#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str="rajatsalaria";
    
   reverse(str.begin(), str.end());
    cout<<str;
    return 0;
}



//
//why string are mutable?
//
//The string is Immutable in Java because String objects are cached in the String pool. Since cached String literals are shared between multiple clients there is always a risk,
//where one client's action would affect all another client. For example, if one client changes the value of the String "Test" to "TEST", all other clients will also see that value
//as explained in the first example. Since caching of String objects was important from performance reason this risk was avoided by making String class Immutable. At the same time,
//String was made final so that no one can compromise invariant of String class like Immutability, Caching, hashcode calculation, etc by extending and overriding behaviors.
//Another reason why String class is immutable could die due to HashMap.
//
//Since Strings are very popular as the HashMap key, it's important for them to be immutable so that they can retrieve the value object which was stored in HashMap. 
//Since HashMap works in the principle of hashing, which requires the same has value to function properly. Mutable String would produce two different hashcodes at the
//time of insertion and retrieval if contents of String was modified after insertion, potentially losing the value object in the map.


/*hashing

 C++ program to count all duplicates
 from string using hashing
#include <iostream>
using namespace std;
# define NO_OF_CHARS 256
 
class gfg
{
    public :
     
     Fills count array with
    frequency of characters 
    void fillCharCounts(char *str, int *count)
    {
        int i;
        for (i = 0; *(str + i); i++)
        count[*(str + i)]++;
    }
 
     Print duplicates present
    in the passed string 
    void printDups(char *str)
    {
         
        // Create an array of size 256 and fill
        // count of every character in it
        int *count = (int *)calloc(NO_OF_CHARS,
                                      sizeof(int));
        fillCharCounts(str, count);
 
        // Print characters having count more than 0
        int i;
        for (i = 0; i < NO_OF_CHARS; i++)
        if(count[i] > 1)
            printf("%c, count = %d \n", i, count[i]);
 
        free(count);
    }
};
 

int main()
{
    gfg g ;
    char str[] = "test string";
    g.printDups(str);
    //getchar();
    return 0;
}
 
// This code is contributed by SoM15242
Output : 

s,  count = 2
t,  count = 3
Time Complexity: O(n), where n = length of the string passed

Space Complexity: O(NO_OF_CHARS)
*/

