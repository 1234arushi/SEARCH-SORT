//https://leetcode.com/problems/fair-candy-swap/

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        
        //another approach:more concise than below
        int diff=(accumulate(bobSizes.begin(),bobSizes.end(),0)-accumulate(aliceSizes.begin(),aliceSizes.end(),0))/2;
        unordered_set<int> s(bobSizes.begin(),bobSizes.end());
        for(int x:aliceSizes)
        {
            if(s.find(x+diff)!=s.end())
            {
                return {x,x+diff};
            }
        }
        return {-1};
        
        /*int total_candiesA=0,total_candiesB=0;
        for(int x:aliceSizes)
        {
            total_candiesA+=x;
            
        }
        for(int y:bobSizes)
        {
            total_candiesB+=y;
            
        }
        int delta=(total_candiesB-total_candiesA)/2;
        set<int> s;
        for(int y:bobSizes)
        {
            s.insert(y);
        }
        for(int x:aliceSizes)
        {
            if(s.find(x+delta)!=s.end())//exists
            {
                return {x,x+delta};
            }
        }
        return {0};*/
    }
};
