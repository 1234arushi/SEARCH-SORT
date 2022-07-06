//https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1#
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        
        //A->first term
        //B->Nth term that is to be found that whether it exists or not
        //C->Common difference
        if(C==0)
        {
            if(A==B)
            {
                return 1;
            }
            return 0;
        }
        else
        {
            if((B-A)/C<0)
            {
                return 0;
                
            }
            else
            {
                if((B-A)%C==0)
                {
                    return 1;
                }
                else
                {
                    return 0;//fraction!!
                }
                
            }
            
        }
        
        
       
        return 0;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}  // } Driver Code Ends
