//https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1#
// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
       
       
       
       //Method 2: reducing the space complexity for method 1
       //SC->O(1) o/p vector not counted in cacl space complexity
       vector< long long int> v(n,1);
       if(n==1)
       {
           return {1};
       }
       long long int temp=1;
       for(int i=0;i<n;i++)
       {
           v[i]=temp;
           temp*=(long long int)nums[i];
       }
       temp=1;
       for(int i=n-1;i>=0;i--)
       {
           v[i]*=temp;
           temp*=(long long int)nums[i];
       }
       return v;
       
      
       /*Method 1:
       if(n==1)
       {
           return {1};
       }
       long long int left[n],right[n];
       left[0]=1;right[n-1]=1;
       
       vector<long long int> v(n,0);
       for(int i=1;i<n;i++)
       {
           left[i]=(long long int)nums[i-1]*left[i-1];
       }
       for(int j=n-2;j>=0;j--)
       {
           right[j]=(long long int)nums[j+1]*right[j+1];
       }
       for(int i=0;i<n;i++)
       {
           v[i]=left[i]*right[i];
       }
       return v;*/
       
       
      
      /*my method :9/100400
      //error:Floating-point exception (SIGFPE)
       vector< long long int> v(n,0);
       long long int p=1;
       for(int i=0;i<n;i++)
       {
           p*=(long long int)nums[i];
           
       }
       for(int i=0;i<n;i++)
       {
           //v.push_back
           v[i]=p/(long long int)nums[i];
       }
       if(nums.size()==1)
       {
           return {1};
       }
       return v;*/
       
        //code here        
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends
