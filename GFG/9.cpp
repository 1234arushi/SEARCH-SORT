//https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1#
// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    
    
    
    
    int majorityElement(int a[], int size)
    {
        //this works when it's said that majority element exitss 
        //otherwise it fails
        /*Method:Moore's voting algo
        int count=0;
        int candidate=0;
        int n=size;
        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                candidate=a[i];
            }
           
            if(a[i]==candidate)
            {
                count++;
            }
            else
            {
                count--;
                
            }
        }
        return candidate;*/
        
    
    
        
        //my method:
        unordered_map<int,int> umap;
        int n=size;
        for(int i=0;i<n;i++)
        {
            umap[a[i]]++;
        }
        unordered_map<int,int>::iterator itr;
        for(itr=umap.begin();itr!=umap.end();itr++)
        {
            if(itr->second>n/2)
            {
                return itr->first;
                
            }
        }
        return -1;
        
        // your code here
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends
