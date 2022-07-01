//https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1#
// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    
    //TC:O(n log n) SC:O(1)
    
    /*sort(arr,arr+size);
    for(int i=0;i<size;i++)
    {
        
        
        //binary search
        int l=0;
        int r=1;
        while(l<=r && r<size)
        {
            int diff=arr[r]-arr[l];//cuz of sort element at rth pos
                                   // is bigger than element at lth pos
            
            if(diff==n && l!=r)//we need distinct element in pairs so l!=r
            {
                return true;
            }
            else if(diff>n)
            //try to reduce the diff
            {
                l++;
                
            }
            else
            {
                r++;
            }
        }
        return false;
    }*/
    
    unordered_map<int,int> umap;
    for(int i=0;i<size;i++)
    {
        umap[arr[i]]++;
        if(n==0 && umap[arr[i]]>1)
        {
            return true;
        }
    }
    //if there were no duplicates
    if (n==0)
    {
        return false;
    }
    
    for(int i=0;i<size;i++)
    {
        int x=arr[i]+n;
        
        if(umap[x])
        {
            return true;
            
        }
    }
    return false;
    //5 0       error for this i/p
    //1 2 6 3 4
    //code
    
}
