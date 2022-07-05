//https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1#
// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        
        //Method 1:
        unordered_map<int,vector<int>> map;
        //int->key:sum  vector<int> ->indexes where we get sum
        vector<pair<int,int>> out;
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            
            if(sum==0)
            {
                out.push_back(make_pair(0,i));//is it always we get pair starting 
                                              //at index 0?
            }
            if(map.find(sum)!=map.end())//it says we have found sum in map
            {
                vector<int> vc=map[sum];//vc vector stores all the indexes of 
                                        //that sum
                
                for(auto it=vc.begin();it!=vc.end();it++)
                {
                    out.push_back(make_pair(*it+1,i));
                }
            }
            map[sum].push_back(i);//pushing index where we got that sum
        }
        return out.size();
        
       
       /*Method 2: 
        unordered_map<ll,ll> umap;
        
        ll count=0;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==0)//  ||arr[i]==0 not used!!
            {
                count++;
            }
            if(umap.find(sum)!=umap.end())
            {
                count+=umap[sum];
            }
            umap[sum]++;
        }
        return count;*/
        //code here
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends
