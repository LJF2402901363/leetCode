// @before-stub-for-debug-begin
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

class Solution {

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //临时数组用于排序后查找到数组中的两个数值
        vector<int> vec(nums);
        //进行排序
        sort(vec.begin(),vec.end());
        //数组左指针
        int left = 0;
        //数组右指针
        int right = vec.size()-1;
        while (left < right)
        {
           if (vec[left] + vec[right] > target)
           {
               //当前值nums[left] + nums[right] > target，那么区间在[left,right-1]中
              right -- ;
           }else if (vec[left] + vec[right] < target )
           {
                //当前值nums[left] + nums[right]  < target，那么区间在[left+1,right]中
               left++;
               
           }else
           {
               break;
           }
           
        }
        
        int  index1 = -1;
        int index2 = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if ( index1 == -1 && nums[i] == vec[left] )
            {
              index1 = i ;
            }else  if (index2 == -1 && nums[i] == vec[right])
            {
               index2 = i;
            }
            
            
        }
        //答案容器
        vector<int> ans;

        if (index1 <= index2){
            //如果第一个索引是小于或等于第二个索引
            ans.push_back(index1);
            ans.push_back(index2);
        }else
        {   
            //如果第一个索引是大于第二个索引
             ans.push_back(index2);
             ans.push_back(index1);
        }
        
         
        return ans;
    }
};
// @lc code=end

