//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        
        
        //Method 4:swap sort TC->O(n) SC->O(1)
        
        int *a=new int[2];
        int i=0;
        while(i<n)
        {
            if(arr[i]!=arr[arr[i]-1])
            {
                swap(arr[i],arr[arr[i]-1]);
            }
            else
            {
                i++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=i+1)
            {
                a[1]=i+1;
                a[0]=arr[i];
            }
            
        }
        return a;
        
        
        
        
        /*Method 3:XOR ->most optimal sol TC->O(n) SC->O(1)
        int xorr=0;
        //xorr of all the elements in our array
        for(int i=0;i<n;i++)
        {
            xorr=xorr^arr[i];
            //xorr^=(i+1)
            
        }
        
        
        //xorring the xorr with all the elements
        //in the range[1..n]
        for(int i=1;i<=n;i++)
        {
            xorr=xorr^i;
        }
        
        //now the curretn xorr=x^y where 
        // x/y are either missing or repeating
        //element-check notes !!
        
        //getting the rightmost set bit in xorr
        int set_bit_no=xorr & ~(xorr-1);
                       //xorr & (-xorr)
        
        //creating 2 baskets for array elements by comparing 
        //set_bit_no :one that conatins elements that have 
        //set_bit_no at same position and other conatins opposite
        int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] & set_bit_no)//==1?
            {
                x^=arr[i];
                
            }
            else
            {
                y^=arr[i];
            }
        }
        //creating 2 baskets for elements[1...n]by comparing 
        //set_bit_no :one that conatins elements that have 
        //set_bit_no at same position and other conatins opposite
        for(int i=1;i<=n;i++)
        {
            if(i&set_bit_no)
            {
                x^=i;
            }
            else
            {
                y^=i;
            }
        }
        int*a=new int[2];
        for(int i=0;i<n;i++)
        {
            if(arr[i]==x)
            {
                a[1]=y;
                a[0]=x;
            }
            else if(arr[i]==y)
            {
                a[1]=x;
                a[0]=y;
            }
        }
        return a;*/
        
        
       
        
        
        /*Method 2:using sum and sum of squares TC->O(n) sc->O(1)
        //200/340 test case passed  :P
        int *a=new int[2];
        long long int sum=(n*(n+1))/2;//[1+2+3+..+n]
        long long int sum_sq=(n*(n+1)*(2*n+1))/6;
        //[1^2+2^2+...+n^2]
        for(int i=0;i<n;i++)
        {
            sum-=(long long int)arr[i];
            sum_sq-=(long long int)arr[i]*(long long int)arr[i];
            
        }
        //missing element
        a[1]=(sum+sum_sq/sum)/2;//check notes !!
        //repeating element
        a[0]=a[1]-sum;
        return a;*/
        
        
        
        /*Method 1:Using hash array  TC->O(n) SC->O(n)
        int temp[n+1]={0};
        int *a=new int[2];
        for(int i=0;i<n;i++)
        {
            temp[arr[i]]++;
        }
        for(int i=1;i<n+1;i++)
        {
            if(temp[i]>1)
            {
                a[0]=i;
                
            }
            else if(temp[i]==0)
            {
                a[1]=i;
            }
        }
        return a;*/
        
        
        /*my kind of sol:
        unordered_map<int,int> umap;
        int *a=new int[2];
        
        for(int i=0;i<n;i++)
        {
            umap[arr[i]]++;
            
        }
        
        for(int i=0;i<n;i++)
        {
            if(umap[i+1]==0)
            {
                a[1]=i+1;
               
            }
            
            if(umap[arr[i]]>1)
            {
                a[0]=arr[i];
            }
        }
        return a;*/
        // code here
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
