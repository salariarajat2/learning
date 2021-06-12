
#include <iostream>
using namespace std;
 
 //The time and space complexity is O(n) and O(1)
 
//int main()
//{
//    int price[] = { 2, 30, 15, 10, 8, 25, 80 };
//    int n = 7;
//    int profit = 0;
//    // valley-peak approach
//    
//    for (int i = 1; i < n; i++)
//    {
//        int sub = price[i] - price[i - 1];
//        if (sub > 0)
//            profit += sub;
//    }
// 
//    cout << "Maximum Profit=" << profit;
//    return 0;
//}
 



int maxProfit(int price[], int n)
{
    int* profit = new int[n];
    for (int i = 0; i < n; i++)  profit[i] = 0;

    int max_price = price[n - 1];
    for (int i = n - 2; i >= 0; i--) {
    	
        if (price[i] > max_price) max_price = price[i];
        //cout<<"max price"<<max_price<<"   ";
        profit[i]= max(profit[i + 1], max_price - price[i]);
        //cout<<"profit "<<profit[i]<<endl;
    }
 
    int min_price = price[0];
    for (int i = 1; i < n; i++) {
        if (price[i] < min_price) min_price = price[i];
        //cout<<"min price"<<min_price<<"   ";
        profit[i] = max(profit[i - 1],profit[i] + (price[i] - min_price));
        // cout<<"profit "<<profit[i]<<endl;
    }
    int result = profit[n - 1];
 
    delete[] profit; 
 
    return result;
}
 
int main()
{
    int price[] = { 2, 30, 15, 10, 8, 25, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    cout << "Maximum Profit = " << maxProfit(price, n);
    return 0;
}


