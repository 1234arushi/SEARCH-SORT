//https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    
    
    //Method 2:using binary search that takes log n time
   
    
    int firstpos=-1;
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        int mid=(start+end)/2;//how to show floor val in this
        if(x<arr[mid])
        {
            end=mid-1;
        }
        else if(x>arr[mid])
        {
            start=mid+1;
        }
        else
        {
            if(mid==0|| arr[mid-1]!=arr[mid])
            {
                firstpos=mid;
                break;
            }
            else
            {
                end=mid-1;
            }
        }
        
    }
   
    
    int lastpos=-1;
    start=0;
    end=n-1;
    
    while(start<=end)
    {
        int mid=(start+end)/2;//how to show floor val in this
        if(x<arr[mid])
        {
            end=mid-1;
        }
        else if(x>arr[mid])
        {
            start=mid+1;
        }
        else
        {
            if(mid==n-1|| arr[mid+1]!=arr[mid])
            {
                lastpos=mid;
                break;
            }
            else
            {
                start=mid+1;
            }
            
            
        }
        
    }
    return {firstpos,lastpos};//as -1,-1 initially initialize
                            // to these variables so if we dont find common
                            //element then it will return -1,-1
    /*Method 1:
    vector<int> v;
    
    for(int i=0;i<n;i++)
    {
        
        if(arr[i]==x)
        {
            v.push_back(i);
        }
        
    }
    if(v.size()==0)
    {
        return {-1,-1};
    }
    else
    {
        /*int max=v[0],min=v[0];
        for(int i=1;i<v.size();i++)
        {
            if(v[i]>max)
            {
                max=v[i];
            }
            else if(v[i]<min)
            {
                min=v[i];
            }
            
        }
        return {min,max};
        //return {v.front(),v.back()};
        
        
        return {*min_element(v.begin(),v.end()),*max_element(v.begin(),v.end())};
        
    }
    return 0;*/
    // code here
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends
