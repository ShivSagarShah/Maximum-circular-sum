/*
You are provided n numbers (both +ve and -ve). Numbers are arranged in a circular form. You need to find the maximum sum of consecutive numbers.

Input Format
First line contains integer t which is number of test case.
For each test case, it contains an integer n which is the size of array and next line contains n space separated integers denoting the elements of the array.

Constraints
1<=t<=100
1<=n<=1000
|Ai| <= 10000

Output Format
Print the maximum circular sum for each testcase in a new line.

Sample Input
1
7
8 -8 9 -9 10 -11 12

Sample Output
22

Explanation
Maximum Circular Sum = 22 (12 + 8 - 8 + 9 - 9 + 10)
*/

#include<iostream>
using namespace std;
int main()
{
    int t, n, a[1000], b[100];
    cin>>t;
    while (t--)
    {
        cin>>n;
        int csum = 0;
        int ms = 0, cs = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            b[i] = (-a[i]); //Step 1: negate the elements of array
            csum = csum + a[i]; // Step 2: find the cumulative sum of the original array
            cs = cs + a[i];
            if (cs<0)
            {
                cs = 0;
            }
            ms = max(ms,cs);
        }
        int cand1 = ms; //Step 3: find the maximum sum of original array using Kadene"s Algo

        ms = 0, cs = 0;  
        for (int i = 0; i < n; i++)
        {
            cs = cs + b[i];
            if (cs<0)
            {
                cs = 0;
            }
            ms = max(ms,cs);
        }   
        int cand = ms; //Step 4: find the maximum sum of negation array using Kadene"s Algo
        int cand2 = csum - (-cand); //Step 5: Add the cumulative sum of original array and maximum sum of negation array
        cout<<max(cand1, cand2)<<endl; //Step 6: Maximum of these two will be the answer
    }
    return 0;
}
/* original array ka jo sum aaya hai usme agar hum vo sum add kar de jiske kaaran vo kam ho gaya hai to hume maximum sum mil sakta hai isliye negation kiya array ka 
11 - (-11)
agar humara maximum sum linear array mein fall nhi karta hai to uske liye hai upar waala condition otherwise normal 
*/
