#include<iostream>
#include<cstring>
using namespace std;

int runCustomerSimulation(int n, string seq)
{
    char seen[26] = {0};
    int res = 0,occupied = 0; 
    
    for (int i=0; seq[i]; i++)
    {
        int ind = seq[i] - 'A';
        
        if (seen[ind] == 0)
        {
            seen[ind] = 1;
            
            if (occupied < n)
            {
                occupied++;
                seen[ind] = 2;
            }
  
            else
                res++;
        }
           else
        {
           if (seen[ind] == 2)
               occupied--;
           seen[ind] = 0;
        }
    }
    return res;
}

int main()
{
    cout << runCustomerSimulation(2, "ABBAJJKZKZ")<<"  person does not get any of the computer" << endl;
    cout << runCustomerSimulation(3, "GACCBDDBAGEE")<<"  person does not get any of the computer" << endl;
    cout << runCustomerSimulation(3, "GACCBGDDBAEE")<<"  person does not get any of the computer" << endl;
    cout << runCustomerSimulation(1, "ABCBCA")<<"  person does not get any of the computer" << endl;
    cout << runCustomerSimulation(1, "ABCBCADEED")<<"  person does not get any of the computer" << endl;
    return 0;
}
