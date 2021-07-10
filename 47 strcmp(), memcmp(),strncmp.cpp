//The strcmp() function returns a:
//
//positive value if the first differing character in lhs is greater than the corresponding character in rhs.
//negative value if the first differing character in lhs is less than the corresponding character in rhs.
//0? if hs and rhs are equal.


#include <cstring>
#include <iostream>

using namespace std;

void display(char *lhs, char *rhs, int result)
{
    if(result > 0)
        cout << rhs << " precedes " << lhs << endl;
    else if (result < 0)
        cout << lhs << " precedes " << rhs << endl;
    else
        cout << lhs << " and " << rhs << " are same" << endl;
}

int main()
{
    char lhs[] = "Armstrong";
    char rhs[] = "Army";
    int result;

    result = strcmp(lhs,rhs);
    display(lhs,rhs,result);

    result = strcmp(lhs,lhs);
    display(lhs,lhs,result);

    return 0;
}

//The strncmp() function in C++ compares a specified number of characters of two null terminating strings. The comparison is done lexicographically.

#include <cstring>
#include <iostream>

using namespace std;

void display(char *lhs, char *rhs, int result, int count)
{
    if(result > 0)
        cout << rhs << " precedes " << lhs << endl;
    else if (result < 0)
        cout << lhs << " precedes " << rhs << endl;
    else
        cout << "First " << count << " characters of " << lhs << " and " << rhs << " are same" << endl;
}

int main()
{
    char lhs[] = "Armstrong";
    char rhs[] = "Army";
    int result;

    result = strncmp(lhs,rhs,3);
    display(lhs,rhs,result,3);

    result = strncmp(lhs,rhs,4);
    display(lhs,rhs,result,4);

    return 0;
    
    
    //The memcmp() function in C++ compares a specified number of characters of two pointer objects
    
    #include <cstring>
#include <iostream>

using namespace std;

void display(char *lhs, char *rhs, int result, int count)
{
    if(result > 0)
        cout << rhs << " precedes " << lhs << endl;
    else if (result < 0)
        cout << lhs << " precedes " << rhs << endl;
    else
        cout << "First " << count << " characters of " << lhs << " and " << rhs << " are same" << endl;
}

int main()
{
    char lhs[] = "Hello World!";
    char rhs[] = "Hello Earth!";
    int result;

    result = memcmp(lhs, rhs, 5);
    display(lhs, rhs, result, 5);
    
    result = memcmp(lhs, rhs, 7);
    display(lhs, rhs, result, 7);
    return 0;
}9
