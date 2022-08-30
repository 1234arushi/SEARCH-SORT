//https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        int l=1,r=x;
        int mid;
        while(l<=r) 
        {
            mid=l+(r-l)/2;
            if(mid==x/mid)//m==x/m
            {
                return mid;
                
            }
            else if(mid<x/mid) 
            {
                l=mid+1;
                
            }
            else
            {
                r=mid-1;
                
            }
            
            
        }
        if(mid>x/mid)//truncated val
        {
            return mid-1;
            
        }
        return mid;//purpose?
    }
};
