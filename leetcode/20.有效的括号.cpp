/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include<stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            switch (c)
            {
            case '[':
            case '{':
            case  '(':
            stack.push(c);
                break;
            case ']':
            if (stack.size()>0 && stack.top() == '[')
            {
               stack.pop();
            }
            else{
                return false;
            };
            break;
            case '}':
            if (stack.size()>0 && stack.top() == '{')
            {
                stack.pop();
            }else
            {
                return false;
            };
            break;
            case  ')':
            if (stack.size()>0 && stack.top() == '(')   {
                stack.pop();
            }else
            {
                return false;
            }
           break;
           default:
            break;
            }
        }
        if (stack.size() == 0)
        {
            return true;
        }else{
            return false;
        }
        
        
        
        
        
        
        
    }
};
// @lc code=end

