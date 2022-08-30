//https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        
        //Method 2:using hash table
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
            
        }
        for(int i=0;i<t.size();i++)
        {
            if(m.find(t[i])!=m.end() &&m[t[i]])//t[i] exists in map
            {
                m[t[i]]--;
            }
            else
            {
                return t[i];
                
            }
        }
        return '-1';
        
        //Method 1.1:
        /*char c=0;
        for(char cs:s)
        {
            c^=cs;
        }
        for(char ct:t)
        {
            c^=ct;
        }
        return c;*/
      
        
        
        //Method 1:using bit manipulation:
        
        /*int xor1=0,xor2=0;
        for(int i=0;i<s.size();i++)
        {
            xor1^=int(s[i]);
        }
        for(int i=0;i<t.size();i++)
        {
            xor2^=int(t[i]);
        }
        return char(xor1^xor2);*/
        
    }
};
