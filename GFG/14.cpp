//https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    static int countbits(int a)
    {
        int count=0;
        while(a)
        {
            if(a&1)
            {
                count++;
            }
            a=a>>1;
        }
        return count;
    }
    
    /*static bool comp(int a,int b)
    {
        return __builtin_popcount(a)>__builtin_popcount(b);
    }*/
    void sortBySetBitCount(int arr[], int n)
    {
        
        //Method 1:
        
        
        
        
        vector <vector<int>> count(32);
        int setbitcount=0;
        for(int i=0;i<n;i++)
        {
            setbitcount=countbits(arr[i]);
            count[setbitcount].push_back(arr[i]);
        }
        int j=0;
        //if we dont have 31 bits then that vector will be empty
        
        for(int i=31;i>=0;i--)
        {
            vector<int> v1=count[i];
            for(int i=0;i<v1.size();i++)
            {
                arr[j++]=v1[i];
            }
        }
        
        //Method 2:
        //stable_sort(arr,arr+n,comp);
        // Your code goes here
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
