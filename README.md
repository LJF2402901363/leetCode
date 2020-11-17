# LeetCode刷题

## 1.[两数之和](https://leetcode-cn.com/problems/two-sum/description/)

|  Category  |  Difficulty   | Likes | Dislikes |
| :--------: | :-----------: | :---: | :------: |
| algorithms | Easy (49.47%) | 9609  |    -     |

<details style="color: rgb(212, 212, 212); font-family: -apple-system, BlinkMacSystemFont, &quot;Segoe WPC&quot;, &quot;Segoe UI&quot;, system-ui, Ubuntu, &quot;Droid Sans&quot;, sans-serif, &quot;Microsoft Yahei UI&quot;; font-size: 14px; font-style: normal; font-variant-ligatures: normal; font-variant-caps: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; -webkit-text-stroke-width: 0px; text-decoration-style: initial; text-decoration-color: initial;"><summary><strong>Tags</strong></summary></details>

<details style="color: rgb(212, 212, 212); font-family: -apple-system, BlinkMacSystemFont, &quot;Segoe WPC&quot;, &quot;Segoe UI&quot;, system-ui, Ubuntu, &quot;Droid Sans&quot;, sans-serif, &quot;Microsoft Yahei UI&quot;; font-size: 14px; font-style: normal; font-variant-ligatures: normal; font-variant-caps: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; -webkit-text-stroke-width: 0px; text-decoration-style: initial; text-decoration-color: initial;"><summary><strong>Companies</strong></summary></details>

给定一个整数数组 `nums` 和一个目标值 `target`，请你在该数组中找出和为目标值的那 **两个** 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

 

**示例:**

```
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```



### 1.1解法一：双重循环逐个遍历，时间复杂度O(n^2)，但是时间超时了。没有通过。

~~~c++
#include<vector>
#include<iostream>
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
        vector<int> vec;
         for (int i = 0; i < nums.size(); i++)
         {
            for (int j = i+1; j < nums.size(); j++)
            {
                //找到符合条件的两个元素
                if(nums[i] + nums[j]  == target){
                    //将第一个加数加入到容器中
                    vec.push_back(i);
                      //将第二个加数加入到容器中
                    vec.push_back(j);
                    return vec;
                }
            }
            

         }
         
        return vec;
    }
~~~

![image-20201115130432135](E:/C++Code/vscodeworkplace/image/image-tow-sum.png)

### 1.2首先进行快速排序然后使用双指针进行查找：

```
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
```

![image-20201115190544036](E:\leetcode\image\image-tow-sum-2.png)

## 2.[两数相加](https://leetcode-cn.com/problems/add-two-numbers/description/)

|  Category  |   Difficulty    | Likes | Dislikes |
| :--------: | :-------------: | :---: | :------: |
| algorithms | Medium (38.90%) | 5261  |    -     |

<details style="color: rgb(212, 212, 212); font-family: -apple-system, BlinkMacSystemFont, &quot;Segoe WPC&quot;, &quot;Segoe UI&quot;, system-ui, Ubuntu, &quot;Droid Sans&quot;, sans-serif, &quot;Microsoft Yahei UI&quot;; font-size: 14px; font-style: normal; font-variant-ligatures: normal; font-variant-caps: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; -webkit-text-stroke-width: 0px; text-decoration-style: initial; text-decoration-color: initial;"><summary><strong>Tags</strong></summary></details>

<details style="color: rgb(212, 212, 212); font-family: -apple-system, BlinkMacSystemFont, &quot;Segoe WPC&quot;, &quot;Segoe UI&quot;, system-ui, Ubuntu, &quot;Droid Sans&quot;, sans-serif, &quot;Microsoft Yahei UI&quot;; font-size: 14px; font-style: normal; font-variant-ligatures: normal; font-variant-caps: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; -webkit-text-stroke-width: 0px; text-decoration-style: initial; text-decoration-color: initial;"><summary><strong>Companies</strong></summary></details>

给出两个 **非空** 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 **逆序** 的方式存储的，并且它们的每个节点只能存储 **一位** 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

**示例：**

```
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```





------

```
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //生成链表的头结点
        ListNode* head = nullptr;
        //临时节点指针用于构建新的链表
        ListNode* temp = nullptr;
        //创建节点时的值
        int value = 0;
        //进位值，两数相加产生进位
        int carry =  0;
        while (l1 != nullptr && l2 != nullptr )
        {
              //获取两个数的和的个位
             value = (l1->val + l2->val + carry) % 10 ;
             //产生的进位
            carry = (carry +  l1->val + l2->val) / 10 ;
            if (head == nullptr)
            {
            //新链表的头结点开辟空间
              head =  new ListNode(value);
              temp = head;
            }else
            {   //开辟新的节点
                ListNode* node = new ListNode(value);
                //尾插法插入节点
                temp->next = node;
                temp =  node;
            }
            //指针移动到一下个节点
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            //获取两个数的和的个位
            value = (l1->val + carry) % 10 ;
            //产生的进位
            carry = (carry +  l1->val ) / 10 ;
            //创建新节点
            ListNode* node = new ListNode(value);
            //尾插法插入新节点到新链表
            temp->next = node;
            temp = node;
            //l1链表指针移动到下一个节点
            l1 = l1->next;
        }
        while (l2 != nullptr){
        //获取两个数的和的个位
        value = (l2->val + carry) % 10 ;
        //产生的进位
        carry = (carry +  l2->val ) / 10 ;
        //创建新节点
        ListNode* node = new ListNode(value);
        //尾插法添加节点到新链表中
        temp->next = node;
        temp = node;
        //l2链表指针移动到一下个节点
        l2 = l2->next;
    }
        //最后处理结果要是进入为1则新增一个节点，否则不用处理
        if (carry == 1)
        {
            //创建新节点并添加到链表中
            ListNode* node = new ListNode(carry);
            temp->next = node;
            temp = node;
        }
        
        return head;
    };
    
};
// @lc code=end


```

![image-20201117001755570](E:\leetcode\image\image-两数相加.png)

## 3.[有效的括号](https://leetcode-cn.com/problems/valid-parentheses/description/)

|  Category  |  Difficulty   | Likes | Dislikes |
| :--------: | :-----------: | :---: | :------: |
| algorithms | Easy (43.26%) | 1988  |    -     |

<details style="color: rgb(212, 212, 212); font-family: -apple-system, BlinkMacSystemFont, &quot;Segoe WPC&quot;, &quot;Segoe UI&quot;, system-ui, Ubuntu, &quot;Droid Sans&quot;, sans-serif, &quot;Microsoft Yahei UI&quot;; font-size: 14px; font-style: normal; font-variant-ligatures: normal; font-variant-caps: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; -webkit-text-stroke-width: 0px; text-decoration-style: initial; text-decoration-color: initial;"><summary><strong>Tags</strong></summary></details>

<details style="color: rgb(212, 212, 212); font-family: -apple-system, BlinkMacSystemFont, &quot;Segoe WPC&quot;, &quot;Segoe UI&quot;, system-ui, Ubuntu, &quot;Droid Sans&quot;, sans-serif, &quot;Microsoft Yahei UI&quot;; font-size: 14px; font-style: normal; font-variant-ligatures: normal; font-variant-caps: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; -webkit-text-stroke-width: 0px; text-decoration-style: initial; text-decoration-color: initial;"><summary><strong>Companies</strong></summary></details>

给定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串，判断字符串是否有效。

有效字符串需满足：

1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。

注意空字符串可被认为是有效字符串。

**示例 1:**

```
输入: "()"
输出: true
```

**示例 2:**

```
输入: "()[]{}"
输出: true
```

**示例 3:**

```
输入: "(]"
输出: false
```

**示例 4:**

```
输入: "([)]"
输出: false
```

**示例 5:**

```
输入: "{[]}"
输出: true
```

```
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
        //实例化符号栈
        stack<char> stack;


        //遍历字符串中的每个字符
        for (int i = 0; i < s.size(); i++)
        {
            //获取字符
            char c = s[i];
            switch (c)
            {
            //符号入栈
            case '[':
            case '{':
            case  '(':
            stack.push(c);
                break;
            case ']':
            //处理符号出栈
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
        //判断最后的栈中的元素个数
        if (stack.size() == 0)
        {
            return true;
        }else{
            return false;
        }
        
    }
};
// @lc code=end


```

