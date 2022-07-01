//https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        
        int l=0;
        int h=nums.size()-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[l]<=nums[mid])//nums[l...mid] is sorted so we'll quickly check 
            //whether the target is present here ot not
            {
                //checking whether that target element is present b/w 
                //nums[low] and nums[mid]
                if(target>=nums[l] && target<=nums[mid])
                {
                    h=mid-1;//confirms that  element is in left subarray
                }
                else
                {
                    l=mid+1; //target element is in right subarray
                }
                
            }
            else//If nums[l..mid] first subarray is not sorted, then
            //nums[mid... h] must be sorted subarray
            {
                //checking whether it's actually present in right subarray or not
                if(target>=nums[mid] && target<=nums[h])
                {
                    l=mid+1;
                }
                else
                {
                    h=mid-1;
                }
                
            }
        }
        return -1;
        
        
        /*My method:Only test case 1 passed!!
        int l=0;
        int r=nums.size()-1;
        int mid=(l+r)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        else if(target>nums[mid])
        {
            r=mid-1;//left subarray search
        }
        else
        {
            l=mid+1;
        }
        while(l<=r)
        {
            mid=(l+r)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(target>nums[mid])
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return -1;*/
    }
};
