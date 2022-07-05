//https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	    long long count=0;
	    for(int i=0;i<n;i++)
	    {
	        int target=sum-arr[i];
	        int left=i+1;
	        int right=n-1;
	        while(left<right)
	        {
	            if(arr[left]+arr[right]>=target)
	            {
	                right--;
	               
	            }
	            else
	            {
	                count+=right-left;
	                left++;
	            }
	         
	           
	            
	        }
	        
	    }
	    return count;
	    // Your code goes here
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
