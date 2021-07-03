#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int main()
 {
	long long t;
	cin>>t;
	while(t--){
	    long long i,n;
	    cin>>n;
	    long long a[n];
	    for(i=0;i<n;i++)    
	        cin>>a[i];
	    next_permutation(a,a+n);
	    for(i=0;i<n;i++){
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}





/*
using namespace std;
void findNextGreater(char number[], int n) {
   int i, j;
   for (i = n-1; i > 0; i--)
   {
   	 if (number[i] > number[i-1])
         break;
   if (i==0) {
      cout<<"Next number is not possible";
      return;
   }
   }
     
   int x = number[i-1], smallest = i;
   for (j = i+1; j < n; j++)
   {
   	if (number[j] > x && number[j] < number[smallest])
         smallest = j;
   }
      
   char temp = number[smallest];
   number[smallest] = number[i-1];
   number[i-1] = temp;
   sort(number + i, number + n);
   cout<<number;
   return;
}

int main(){
   char number[] = "12345986";
   int n = strlen(number);
   cout<<"The next number with same set of digits is ";
   findNextGreater(number, n);
   return 0;
}*/


