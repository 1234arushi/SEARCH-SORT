//https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        
        //Method 1: TC->O(N^3)??N log n?  SC->O(1)
        vector <vector<int>> res;
        
        if(arr.empty())
        {
            return res;
        }
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int target_sum=k-(arr[i]+arr[j]);
                int front=j+1;
                int back=n-1;
                while(front<back)
                {
                    int two_sum =arr[front]+arr[back];
                    if(two_sum<target_sum)
                    {
                        front++;
                    }
                    else if(two_sum>target_sum)
                    {
                        back--;
                    }
                    else
                    {
                        vector<int> quad;
                        quad.push_back(arr[i]);
                        quad.push_back(arr[j]);
                        quad.push_back(arr[front]);
                        quad.push_back(arr[back]);
                        res.push_back(quad);
                        front++;back--;
                        while(arr[front-1]==arr[front] && front<back)
                        {
                            front++;
                        }
                        while(arr[back+1]==arr[back] && front<back)
                        {
                            back--;
                        }
                        
                    }
                }
                while(j+1<n && arr[j+1]==arr[j])
                {
                    j++;
                }
                
            }
            while(i+1<n && arr[i+1]==arr[i])
            {
                i++;
            }
        }
        return res;
        
       
                               
                          
        
        //runtime error
        /*unordered_map<int,int> umap;
        for(int i=0;i<arr.size();i++)
        {
            umap[arr[i]]++;
        }
        vector <vector<int>> vi;
        
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                for(int k=j+1;k<arr.size();k++)
                {
                    int x=k-(arr[i]+arr[j]+arr[k]);
                    if(umap[x])
                    {
                        vector<int> v;
                        v.push_back(arr[i]);
                        v.push_back(arr[j]);
                        v.push_back(arr[k]);
                        v.push_back(x);
                        vi.push_back(v);
                        
                    }
                    
    
                    
                }
            }
        
            umap[arr[i]]++;
        }*/
        // Your code goes here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
