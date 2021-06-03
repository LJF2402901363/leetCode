#                                    LeetCode刷题

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

![image-20201115130432135](E:/leetcode/image/image-tow-sum.png)

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

![image-20201115190544036](E:/leetcode/image/image-tow-sum-2.png)

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

![image-20201117001755570](E:/leetcode/image/image-%E4%B8%A4%E6%95%B0%E7%9B%B8%E5%8A%A0.png)

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
输入: "([)]"输出: false
```

**示例 5:**

```
输入: "{[]}"输出: true
```

```java
/* * @lc app=leetcode.cn id=20 lang=cpp * * [20] 有效的括号 */// @lc code=start#include<stack>class Solution {public:    bool isValid(string s) {        //实例化符号栈        stack<char> stack;        //遍历字符串中的每个字符        for (int i = 0; i < s.size(); i++)        {            //获取字符            char c = s[i];            switch (c)            {            //符号入栈            case '[':            case '{':            case  '(':            stack.push(c);                break;            case ']':            //处理符号出栈            if (stack.size()>0 && stack.top() == '[')            {               stack.pop();            }            else{                return false;            };            break;            case '}':            if (stack.size()>0 && stack.top() == '{')            {                stack.pop();            }else            {                return false;            };            break;            case  ')':            if (stack.size()>0 && stack.top() == '(')   {                stack.pop();            }else            {                return false;            }           break;           default:            break;            }        }        //判断最后的栈中的元素个数        if (stack.size() == 0)        {            return true;        }else{            return false;        }            }};// @lc code=end
```

## 4.[数组中重复的数据](https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/description/)

|  Category  |   Difficulty    | Likes | Dislikes |
| :--------: | :-------------: | :---: | :------: |
| algorithms | Medium (67.81%) |  350  |    -     |

<details style="color: rgb(212, 212, 212); font-family: -apple-system, BlinkMacSystemFont, &quot;Segoe WPC&quot;, &quot;Segoe UI&quot;, system-ui, Ubuntu, &quot;Droid Sans&quot;, sans-serif, &quot;Microsoft Yahei UI&quot;; font-size: 14px; font-style: normal; font-variant-ligatures: normal; font-variant-caps: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; -webkit-text-stroke-width: 0px; text-decoration-thickness: initial; text-decoration-style: initial; text-decoration-color: initial;"><summary><strong>Tags</strong></summary></details>

<details style="color: rgb(212, 212, 212); font-family: -apple-system, BlinkMacSystemFont, &quot;Segoe WPC&quot;, &quot;Segoe UI&quot;, system-ui, Ubuntu, &quot;Droid Sans&quot;, sans-serif, &quot;Microsoft Yahei UI&quot;; font-size: 14px; font-style: normal; font-variant-ligatures: normal; font-variant-caps: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: start; text-indent: 0px; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; -webkit-text-stroke-width: 0px; text-decoration-thickness: initial; text-decoration-style: initial; text-decoration-color: initial;"><summary><strong>Companies</strong></summary></details>

给定一个整数数组 a，其中1 ≤ a[i] ≤ *n* （*n*为数组长度）, 其中有些元素出现**两次**而其他元素出现**一次**。

找到所有出现**两次**的元素。

你可以不用到任何额外空间并在O(*n*)时间复杂度内解决这个问题吗？

**示例：**

```
输入:[4,3,2,7,8,2,3,1]输出:[2,3]
```

解决方案：

```c++
// @before-stub-for-debug-begin#include <vector>using namespace std;// @before-stub-for-debug-end/* * @lc app=leetcode.cn id=442 lang=cpp * [442] 数组中重复的数据 *由于每个元素是  1<=a[i]<=n,所以可以将每个元素移动到 索引为 a[i]-1的位置。比如说元素1移动到索引为0的位置。 *从i=0开始，判断 a[i] ==[a[i]-1],如果不相等则交换，直到相等为止。 */// @lc code=startclass Solution {public:    vector<int> findDuplicates(vector<int>& nums) {      vector<int> result;      for (int i = 0; i < nums.size(); i++)      {          //从i=0开始，判断 a[i] ==[a[i]-1],如果不相等则交换，直到相等为止。          while ( nums[i] != nums[nums[i]-1])          {            swap(nums,i,nums[i]-1);          }                }       //将重复的元素添加到结果集合中      for(int i = 0;i < nums.size();i++){          if(nums[i] != i+1){            result.push_back(nums[i]);          }      }      return result;    } void swap(vector<int> &nums,int i,int j){     /*      nums[i] = nums[i]^nums[j]; 	  nums[j]=nums[i]^nums[j];      nums[i]=nums[i]^nums[j];     */   int  temp = nums[i];   nums[i] = nums[j];   nums[j] = temp;    }};// @lc code=end
```

![image-20210325101224075](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210325101224075.png)

## 5. 数组中重复的数字

### 5.1题目链接

[牛客网](https://www.nowcoder.com/practice/6fe361ede7e54db1b84adc81d09d8524?tpId=13&tqId=11203&tab=answerKey&from=cyc_github)

### 5.2题目描述

在一个长度为 n 的数组里的所有数字都在 0 到 n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字是重复的，也不知道每个数字重复几次。请找出数组中任意一个重复的数字。

```
Input:{2, 3, 1, 0, 2, 5}Output:2
```

### 5.3解题思路

要求时间复杂度 O(N)，空间复杂度 O(1)。因此不能使用排序的方法，也不能使用额外的标记数组。

对于这种数组元素在 [0, n-1] 范围内的问题，可以将值为 i 的元素调整到第 i 个位置上进行求解。在调整过程中，如果第 i 位置上已经有一个值为 i 的元素，就可以知道 i 值重复。

以 (2, 3, 1, 0, 2, 5) 为例，遍历到位置 4 时，该位置上的数为 2，但是第 2 个位置上已经有一个 2 的值了，因此可以知道 2 重复：

[![img](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/68747470733a2f2f63732d6e6f7465732d313235363130393739362e636f732e61702d6775616e677a686f752e6d7971636c6f75642e636f6d2f36343362366631382d663933332d346163352d616137612d6533303464626437666534392e676966)](https://camo.githubusercontent.com/77142c99e11d0abb12732318adcb4cc2aa2a98350c33526db8a5b9b8e7e69f9b/68747470733a2f2f63732d6e6f7465732d313235363130393739362e636f732e61702d6775616e677a686f752e6d7971636c6f75642e636f6d2f36343362366631382d663933332d346163352d616137612d6533303464626437666534392e676966)

### 方法一：

```
public int duplicate(int[] nums) {    for (int i = 0; i < nums.length; i++) {        while (nums[i] != i) {            if (nums[i] == nums[nums[i]]) {                return  nums[i];            }            swap(nums, i, nums[i]);        }        swap(nums, i, nums[i]);    }    return -1;}private void swap(int[] nums, int i, int j) {    int t = nums[i];    nums[i] = nums[j];    nums[j] = t;}
```

### 方法二：

```c++
class Solution {public:    /**     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可     *     *      * @param numbers int整型vector      * @return int整型     */    int duplicate(vector<int>& numbers) {      for(int i = 0;i < numbers.size();i++){          while( numbers[i]!=numbers[numbers[i]]){             swap(numbers,i,numbers[i]);          }      }        for(int i = 0 ;i < numbers.size();i++){            if(numbers[i]!=i){                return numbers[i];            }        }        return -1;    }       void swap( vector<int>& numbers,int i,int j){       int tem  = numbers[i];       numbers[i] = numbers[j];       numbers[j] = tem;    }};
```

##  6.二维数组中的查找

### 6.1题目链接

[牛客网](https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 6.2题目描述

给定一个二维数组，其每一行从左到右递增排序，从上到下也是递增排序。给定一个数，判断这个数是否在该二维数组中。

```
Consider the following matrix:[  [1,   4,  7, 11, 15],  [2,   5,  8, 12, 19],  [3,   6,  9, 16, 22],  [10, 13, 14, 17, 24],  [18, 21, 23, 26, 30]]Given target = 5, return true.Given target = 20, return false.
```

### 6.4解题思路

要求时间复杂度 O(M + N)，空间复杂度 O(1)。其中 M 为行数，N 为 列数。

该二维数组中的一个数，小于它的数一定在其左边，大于它的数一定在其下边。因此，从右上角开始查找，就可以根据 target 和当前元素的大小关系来快速地缩小查找区间，每次减少一行或者一列的元素。当前元素的查找区间为左下角的所有元素。

[![img](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/68747470733a2f2f63732d6e6f7465732d313235363130393739362e636f732e61702d6775616e677a686f752e6d7971636c6f75642e636f6d2f33356138633731312d306463302d343631332d393566332d6265393663366336653130342e676966)](https://camo.githubusercontent.com/9bbc6e61a30a135426de546d99f97eda04ca0a3065f0d6b5e6b36e7fce658b16/68747470733a2f2f63732d6e6f7465732d313235363130393739362e636f732e61702d6775616e677a686f752e6d7971636c6f75642e636f6d2f33356138633731312d306463302d343631332d393566332d6265393663366336653130342e676966)



```c++
class Solution {public:    bool Find(int target, vector<vector<int> > array) {                int cols = array[0].size();        int i =0;        int j = cols -1;        for(;i <array.size()&&j>=0;){                            if(target < array[i][j]){                j--;            }else if(target > array[i][j]){                i++;            }else{                return true;                        }        }        return false;    }};}
```

## 7.替换空格

### 7.1题目链接

[牛客网](https://www.nowcoder.com/practice/0e26e5551f2b489b9f58bc83aa4b6c68?tpId=13&tqId=11155&tab=answerKey&from=cyc_github)

### 7.2题目描述

将一个字符串中的空格替换成 "%20"。

```
Input:"A B"Output:"A%20B"
```

### 7.3

#### 7.3.1直接了当法

```c++
class Solution {public:    /**     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可     *     *      * @param s string字符串      * @return string字符串     */    string replaceSpace(string s) {        string str = "";        int index = 0;       for(int i = 0 ; i < s.size();i++){           if(s[i]==' '){               str +="%20";               index = i;           }else{               str +=s[i];           }       }        return str;    }};
```

![image-20210326002322766](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210326002322766.png)

#### 7.3.2解题思路

① 在字符串尾部填充任意字符，使得字符串的长度等于替换之后的长度。因为一个空格要替换成三个字符（%20），所以当遍历到一个空格时，需要在尾部填充两个任意字符。

② 令 P1 指向字符串原来的末尾位置，P2 指向字符串现在的末尾位置。P1 和 P2 从后向前遍历，当 P1 遍历到一个空格时，就需要令 P2 指向的位置依次填充 02%（注意是逆序的），否则就填充上 P1 指向字符的值。从后向前遍是为了在改变 P2 所指向的内容时，不会影响到 P1 遍历原来字符串的内容。

③ 当 P2 遇到 P1 时（P2 <= P1），或者遍历结束（P1 < 0），退出。

[![img](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/68747470733a2f2f63732d6e6f7465732d313235363130393739362e636f732e61702d6775616e677a686f752e6d7971636c6f75642e636f6d2f66376331666561322d633165372d346433312d393462352d3064396466383565303933632e676966)





```c++
class Solution {public:    /**     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可     *     *      * @param s string字符串      * @return string字符串     */    string replaceSpace(string s) {        string str = s;        int index = s.length();        //没找到一个空格就在字符串后面加两个空格        for(int i = index-1;i>=0;i--){            if(s[i]==' '){                str.append("  ");            }        }        if(str.length() == s.length()){            return s;        }        int p1 = s.length()-1;        int p2 = str.length()-1;        while(p1 != p2){           //替换空格            if(s[p1] == ' '){                str[p2--]='0';                str[p2--]='2';                str[p2--]='%';            }else{                //替换非空格字符                str[p2--]=s[p1];            }            p1--;        }                return str;    }};
```





![image-20210326100348725](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210326100348725.png)

## 8 顺时针打印矩阵

8.1题目链接

[牛客网](https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a?tpId=13&tqId=11172&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 8.2题目描述

按顺时针的方向，从外到里打印矩阵的值。下图的矩阵打印结果为：1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10

![image-20210326100806349](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210326100806349.png)

一层一层从外到里打印，观察可知每一层打印都有相同的处理步骤，唯一不同的是上下左右的边界不同了。因此使用四个变量 r1, r2, c1, c2 分别存储上下左右边界值，从而定义当前最外层。打印当前最外层的顺序：从左到右打印最上一行->从上到下打印最右一行->从右到左打印最下一行->从下到上打印最左一行。应当注意只有在 r1 != r2 时才打印最下一行，也就是在当前最外层的行数大于 1 时才打印最下一行，这是因为当前最外层只有一行时，继续打印最下一行，会导致重复打印。打印最左一行也要做同样处理。

![img](https://camo.githubusercontent.com/c5416e2433b193677ffc99342faf5340920d5cd90decd6046f17b0c1b6db2856/68747470733a2f2f63732d6e6f7465732d313235363130393739362e636f732e61702d6775616e677a686f752e6d7971636c6f75642e636f6d2f696d6167652d32303230313130343031303630393232332e706e67)



```c++
class Solution {public:    vector<int> printMatrix(vector<vector<int> > matrix) {        vector<int> vec  ;        int right = 0;        int down =0;        int left = matrix[0].size()-1;        int up = matrix.size()-1;       while(down <= up&&right<=left){        //向右打印        for(int i = right ;i <= left;i++){            vec.push_back(matrix[down][i]);        }        //向下打印          for(int i = down+1 ;i <= up;i++){            vec.push_back(matrix[i][left]);        }            if(up!=down){                 //向左打印             for(int i = left-1 ;i>=right;i--){            vec.push_back(matrix[up][i]);        }            }      if(left!=right){          //向上打印             for(int i = up-1 ;i>down;i--){            vec.push_back(matrix[i][right]);        }         }                 left--;           right++;           down++;           up--;      }        return vec;    } };
```

![image-20210326130530308](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210326130530308.png)

## 9.第一个只出现一次的字符位置

### 9.1题目链接

[牛客网](https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 9.2题目描述

在一个字符串中找到第一个只出现一次的字符，并返回它的位置。字符串只包含 ASCII 码字符。

```
Input: abaccOutput: b
```

### 9.3解题思路

最直观的解法是使用 HashMap 对出现次数进行统计：字符做为 key，出现次数作为 value，遍历字符串每次都将 key 对应的 value 加 1。最后再遍历这个 HashMap 就可以找出出现次数为 1 的字符。

考虑到要统计的字符范围有限，也可以使用整型数组代替 HashMap。ASCII 码只有 128 个字符，因此可以使用长度为 128 的整型数组来存储每个字符出现的次数。

```c++
class Solution {public:    int FirstNotRepeatingChar(string str) {        int chars[128];        for(int i = 0;i < 128;i ++) chars[i] = 0;        for(int i =0;i < str.length();i++){            chars[str[i]]++;        }              for(int i =0;i < str.length();i++){            if(chars[str[i]] == 1){                return i;            }        }        return -1;    }};
```

![image-20210326132231157](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210326132231157.png)

以上实现的空间复杂度还不是最优的。考虑到只需要找到只出现一次的字符，那么需要统计的次数信息只有 0,1,更大，使用两个比特位就能存储这些信息。

```
public int FirstNotRepeatingChar2(String str) {    BitSet bs1 = new BitSet(128);    BitSet bs2 = new BitSet(128);    for (char c : str.toCharArray()) {        if (!bs1.get(c) && !bs2.get(c))            bs1.set(c);     // 0 0 -> 0 1        else if (bs1.get(c) && !bs2.get(c))            bs2.set(c);     // 0 1 -> 1 1    }    for (int i = 0; i < str.length(); i++) {        char c = str.charAt(i);        if (bs1.get(c) && !bs2.get(c))  // 0 1            return i;    }    return -1;}
```

## 10用两个栈实现队列

### 10.1题目链接

[牛客网](https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 10.2题目描述

用两个栈来实现一个队列，完成队列的 Push 和 Pop 操作。

### 10.3解题思路

in 栈用来处理入栈（push）操作，out 栈用来处理出栈（pop）操作。一个元素进入 in 栈之后，出栈的顺序被反转。当元素要出栈时，需要先进入 out 栈，此时元素出栈顺序再一次被反转，因此出栈顺序就和最开始入栈顺序是相同的，先进入的元素先退出，这就是队列的顺序。

[![img](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/68747470733a2f2f63732d6e6f7465732d313235363130393739362e636f732e61702d6775616e677a686f752e6d7971636c6f75642e636f6d2f33656132383062352d626537642d343731622d616337362d6666303230333834333537632e676966)

```c++
class Solution{public:    void push(int node) {        //直接入栈        stack1.push(node);    }    int pop() {        //当栈2为空时候把栈1的元素都放到栈2中，并弹出栈1的元素       if(stack2.empty()){            while(!stack1.empty()){           stack2.push(stack1.top());           stack1.pop();       }          }      int node = stack2.top();       stack2.pop();       return  node;                   } private:    stack<int> stack1;    stack<int> stack2;};
```

![image-20210326154825998](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210326154825998.png)

## 11.包含 min 函数的栈

### 11.1题目链接

[牛客网](https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 11.2题目描述

实现一个包含 min() 函数的栈，该方法返回当前栈中最小的值。

### 11.3解题思路

使用一个额外的 minStack，栈顶元素为当前栈中最小的值。在对栈进行 push 入栈和 pop 出栈操作时，同样需要对 minStack 进行入栈出栈操作，从而使 minStack 栈顶元素一直为当前栈中最小的值。在进行 push 操作时，需要比较入栈元素和当前栈中最小值，将值较小的元素 push 到 minStack 中。

[![img](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/68747470733a2f2f63732d6e6f7465732d313235363130393739362e636f732e61702d6775616e677a686f752e6d7971636c6f75642e636f6d2f696d6167652d32303230313130343031333933363132362e706e67)



```c++
class Solution {public:    void push(int value) {        //data栈入栈       dataStack.push(value);        //如果min栈为空则直接入栈       if(minStack.empty()){           minStack.push(value);       }else{           //min栈不为空，则比较value和min栈的栈顶元素，把小的一方放进min栈           int top = minStack.top();           if(value > top){               minStack.push(top);           }else{               minStack.push(value);           }       }    }    void pop() {      dataStack.pop();      minStack.pop();    }    int top() {      return  dataStack.top();    }    int min() {     return  minStack.top();     }private:    stack<int> dataStack;    stack<int> minStack;};
```



![image-20210326161433056](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210326161433056.png)

## 12.栈的压入、弹出序列

### 12.1题目链接

[牛客网](https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 12.2题目描述

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。

例如序列 1,2,3,4,5 是某栈的压入顺序，序列 4,5,3,2,1 是该压栈序列对应的一个弹出序列，但 4,3,5,1,2 就不可能是该压栈序列的弹出序列。

### 12.3解题思路

使用一个栈来模拟压入弹出操作。每次入栈一个元素后，都要判断一下栈顶元素是不是当前出栈序列 popSequence 的第一个元素，如果是的话则执行出栈操作并将 popSequence 往后移一位，继续进行判断。

```c++
class Solution {public:    bool IsPopOrder(vector<int> pushV,vector<int> popV) {        stack<int> stack;        int i =0;        int j =0;        int index = 0;        for(;i < popV.size();i++){            while(index < pushV.size()){                if(!stack.empty()){                    if(stack.top()!=popV[i]){                    stack.push(pushV[index++]);               }else{                        break;                    }                                                }else{                    stack.push(pushV[index++]);              }                         }            if(stack.top()!=popV[i]){                return false;            }            stack.pop();        }        if(stack.empty()){            return true;        }else{            return false;        }            }};
```

![image-20210327105458041](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210327105458041.png)

```c++
class Solution {public:    bool IsPopOrder(vector<int> pushV,vector<int> popV) {              stack<int> stack;        int index = 0;      for(int i = 0;i < pushV.size();i++){          stack.push(pushV[i]);          while(index < popV.size()&&!stack.empty()&&stack.top()==popV[index]){              stack.pop();              index ++;          }      }        return stack.empty();    }};
```



##  14.数据流中的中位数

### 14.1题目链接

[牛客网](https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&tqId=11216&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 14.2题目描述

如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。



### 14.3解决方法

#### 14.3.1没插入一个元素就存放到一个vector中，然后每次获取中位数时候就首先排序，然后再返回结果

```c++
class Solution {public:    void Insert(int num) {        vec.push_back(num);            }    double GetMedian() {         int n = vec.size();          quickSort(vec,0,n-1);       if( n %2 == 0){           return (vec[n/2] +vec[n/2-1])/2.0;       }else{           return vec[n/2];       }            }        void quickSort(vector<int> & vec,int i ,int j){        if(i < j ){            int index = partIndex(vec,i,j);            quickSort(vec,0,index -1);            quickSort(vec,index + 1, j);        }    }        int partIndex(vector<int> & vec,int i ,int j){        int key = vec[i];        while(i < j ){            while(i < j && key >= vec[j]){                j -- ;            }            if(i  < j){                vec[i] = vec[j];            }               while(i < j && key <= vec[i]){                i ++ ;            }            if(i  < j){                vec[j] = vec[i];            }        }                vec[i] = key;        return i;    }private:    vector<int> vec;};
```

![image-20210327155859136](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210327155859136.png)

#### 14.3.2，插入的时候排序，二分法。

```java
import java.util.List;import java.util.ArrayList;public class Solution {   List<Integer> list = new ArrayList<>(10);    public void Insert(Integer num) {        if(list.size() == 0){            list.add(num);            return ;        }     int left = 0;     int right = list.size()-1;     int mid = 0;     while(left < right){         mid = (left + right)/2;         if(list.get(mid) < num){             left = mid + 1;         }else{             right = mid - 1;         }     }          list.add(left,num);         return;    }    public Double GetMedian() {        int index = list.size();        if(index % 2 == 0){            return (list.get(index /2) + list.get(index /2 -1))/2.0;        }else{          return list.get(index/2) * 1.0;        }    }}
```

#### 14.3.3利用两个堆顶解题

**思路如下：**
  将读入的数据分为几乎数量相同的两部分，一部分数字小，另一部分大。**小的一部分采用大顶堆存放，大的一部分采用小顶堆存放。这样两个堆的堆顶就是整个数据流中，最中间的两个数。**当总个数为偶数时，使两个堆的数目相同，则中位数=大顶堆的最大数字与小顶堆的最小数字的平均值；而总个数为奇数时，使小顶堆的个数比大顶堆多一，则中位数=小顶堆的最小数字。
**插入的步骤如下**：
　　1.若已读取的个数为偶数（包括0）时，两个堆的数目已经相同，**再插入一个数时，应该选一个数插入到小顶堆中**，从而实现小顶堆的个数多一。但是，**不能直接插到小顶堆**，本应该选择一个数加入到小顶堆中，但是**必须选一个较大的数放入小顶堆，而插入的这个数不一定符合要求（大顶堆的数不服它），所以这个数要和大顶堆的最大数（先进大顶堆）打一群架，谁赢了（谁大）谁进小顶堆。**
　　2。若已读取的个数为奇数时，小顶堆的个数多一，所以要将某个数字插入到大顶堆中，此时方法与上面类似。新进来的数要和小顶堆的堆顶（最小值）打一架，打输的（更小的那个数）进入大顶堆。
  本方法的空间复杂度是O(1)，空间复杂度是O(logn)，相比于以上几个方法，可以说是最优选择。因此也是大家使用最多的解法。堆有多种方式实现，数组或者基于队列实现。这里使用PriorityQueue实现，PriorityQueue默认是一个小顶堆，因此我们需要自己实现大顶堆，这里传入自定义的Comparator函数可以实现大顶堆

```java
import java.util.PriorityQueue;import java.util.Comparator;public class Solution {    //小顶堆    PriorityQueue<Integer> minHeap = new PriorityQueue<>();    //大顶堆需要实现一下比较器    PriorityQueue<Integer> maxHeap = new PriorityQueue<>(    new Comparator<Integer>(){        @Override        public int compare(Integer i1,Integer i2){            return i2 -i1;        }    }    );    int count = 0;    public void Insert(Integer num) {        //如果是个数为偶数个的话，先插入到大顶堆，并调整，然后将大顶堆中最大的元素插入到小顶堆中。        if(count % 2 == 0){            maxHeap.offer(num);            int max = maxHeap.poll();            minHeap.offer(max);        }else{            //如果个数为奇数个的话，则先插入到小顶堆，然后将小顶堆中最小元素插入到大顶堆中            minHeap.offer(num);            int min = minHeap.poll();            maxHeap.offer(min);        }          count ++;    }    public Double GetMedian() {        //当前为偶数个时候，则取小顶堆和大顶堆的堆顶元素平均值        if(count % 2 == 0){            return new Double(minHeap.peek() + maxHeap.peek()) /2;        }else{            //当前为奇数个时候，则直接从小顶堆中取出元素即可。            return new Double(minHeap.peek());        }    }}
```

![image-20210328225715166](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210328225715166.png)

## 15.滑动窗口的最大值

### 15.1题目链接

[牛客网](https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&tqId=11217&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 15.2题目描述

给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。

例如，如果输入数组 {2, 3, 4, 2, 6, 2, 5, 1} 及滑动窗口的大小 3，那么一共存在 6 个滑动窗口，他们的最大值分别为 {4, 4, 6, 6, 6, 5}。

![image-20210506222204436](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210506222204436.png)



## 15.3解题思路一：

维护一个大小为窗口大小的大顶堆，顶堆元素则为当前窗口的最大值。

假设窗口的大小为 M，数组的长度为 N。在窗口向右移动时，需要先在堆中删除离开窗口的元素，并将新到达的元素添加到堆中，这两个操作的时间复杂度都为 log2M，因此算法的时间复杂度为 O(Nlog2M)，空间复杂度为 O(M)。

```java
public ArrayList<Integer> maxInWindows(int[] num, int size) {    ArrayList<Integer> ret = new ArrayList<>();    if (size > num.length || size < 1)        return ret;    PriorityQueue<Integer> heap = new PriorityQueue<>((o1, o2) -> o2 - o1);  /* 大顶堆 */    for (int i = 0; i < size; i++)        heap.add(num[i]);    ret.add(heap.peek());    for (int i = 0, j = i + size; j < num.length; i++, j++) {            /* 维护一个大小为 size 的大顶堆 */        heap.remove(num[i]);        heap.add(num[j]);        ret.add(heap.peek());    }    return ret;}
```

![image-20210506222538247](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210506222538247.png)



#### 15.4解题思路二：

```java
import java.util.*;public class Solution {    public ArrayList<Integer> maxInWindows(int [] num, int size) {        ArrayList<Integer>  arr = new ArrayList<>();        if(size > num.length||size == 0) return arr ;        for(int i = 0; i < num.length-size + 1;i++){            int max =  getMax(num,i,i+size);            arr.add(max);        }        return arr;    }        public  int getMax(int[] num,int start,int end){        int max = Integer.MIN_VALUE;            for(int j = start;j<end;j++){                if(max < num[j]){                    max = num[j];                }            }        return max;    }}
```

![image-20210506222426797](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210506222426797.png)

## 16.和为 S 的两个数字

### 16.1题目链接

[牛客网](https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?tpId=13&tqId=11195&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 16.2题目描述

在有序数组中找出两个数，使得和为给定的数 S。如果有多对数字的和等于 S，输出两个数的乘积最小的。

### 16.3解题思路

使用双指针，一个指针指向元素较小的值，一个指针指向元素较大的值。指向较小元素的指针从头向尾遍历，指向较大元素的指针从尾向头遍历。

- 如果两个指针指向元素的和 sum == target，那么这两个元素即为所求。
- 如果 sum > target，移动较大的元素，使 sum 变小一些；
- 如果 sum < target，移动较小的元素，使 sum 变大一些。

```java
import java.util.ArrayList;public class Solution {    public ArrayList<Integer> FindNumbersWithSum(int [] array,int sum) {         ArrayList<Integer>  ret = new  ArrayList<Integer>();        int min = 0;        int max = array.length -1;        int sult = 0;        boolean fla = false;        int p1 = -1;        int p2 = -1;        while(min < max ){            int target = array[min] + array[max];            if(target < sum){                min ++;            }else if(target > sum){                max --;            }else{                if(fla == false){                   fla = true;                    sult = array[min] * array[max];                    p1 = min;                    p2 = max;                }else{                    if(sult > array[min] * array[max]){                        sult = array[min] * array[max];                         p1 = min;                         p2 = max;                    }                }               min++;            }        }          if(p1 != -1 && p2 != -2){               ret.add(array[p1]);               ret.add(array[p2]);           }        return ret;    }}
```

![image-20210506232138172](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210506232138172.png)





### 解题方案二[x*x > (x-1) * (x+1)]因此不需要判定哪个积最小，第一组就是最小：

```java
import java.util.*;public class Solution {    public ArrayList<Integer> FindNumbersWithSum(int[] nums, int target) {    int i = 0, j = nums.length - 1;    while (i < j) {        int cur = nums[i] + nums[j];        if (cur == target)            return new ArrayList<>(Arrays.asList(nums[i], nums[j]));        if (cur < target)            i++;        else            j--;    }    return new ArrayList<>();}}
```

![image-20210506233310947](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210506233310947.png)

## 17.和为 S 的连续正数序列

### 17.1题目描述

[牛客网](https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 17.2题目描述

输出所有和为 S 的连续正数序列。例如和为 100 的连续序列有：

```
[9, 10, 11, 12, 13, 14, 15, 16][18, 19, 20, 21, 22]。
```

### 17.3解题思路一

```java
public ArrayList<ArrayList<Integer>> FindContinuousSequence(int sum) {    ArrayList<ArrayList<Integer>> ret = new ArrayList<>();    int start = 1, end = 2;    int curSum = 3;    while (end < sum) {        if (curSum > sum) {            curSum -= start;            start++;        } else if (curSum < sum) {            end++;            curSum += end;        } else {            ArrayList<Integer> list = new ArrayList<>();            for (int i = start; i <= end; i++)                list.add(i);            ret.add(list);            curSum -= start;            start++;            end++;            curSum += end;        }    }    return ret;}
```

### 解题思路二：

```java
import java.util.ArrayList;public class Solution {    public ArrayList<ArrayList<Integer> > FindContinuousSequence(int sum) {      ArrayList<ArrayList<Integer> > result = new ArrayList<ArrayList<Integer> >();      if(sum <= 0){           return result;      }             for(int i = 1;i < sum;i++){           int index = i;            int count = 0;           ArrayList<Integer>  sumList = new ArrayList<Integer> ();          while(count < sum ){               count += index;              sumList.add(index);               if(count < sum){                  index ++;              }else if(count == sum){                   result.add(sumList);                   break;               }else{                   break;               }                                    }      }      return result;    }}
```

![image-20210507114046020](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210507114046020.png)

## 18.翻转单词顺序列

### 题目描述

[牛客网](https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&tqId=11197&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 题目描述

```
Input:"I am a student."Output:"student. a am I"
```

### 解题思路

#### 方法一(使用双指针)：

**先翻转每个单词，再翻转整个字符串。**

题目应该有一个隐含条件，就是不能用额外的空间。虽然 Java 的题目输入参数为 String 类型，需要先创建一个字符数组使得空间复杂度为 O(N)，但是正确的参数类型应该和原书一样，为字符数组，并且只能使用该字符数组的空间。任何使用了额外空间的解法在面试时都会大打折扣，包括递归解法。

```java
public String ReverseSentence(String str) {    int n = str.length();    char[] chars = str.toCharArray();    int i = 0, j = 0;    while (j <= n) {        if (j == n || chars[j] == ' ') {            reverse(chars, i, j - 1);            i = j + 1;        }        j++;    }    reverse(chars, 0, n - 1);    return new String(chars);}private void reverse(char[] c, int i, int j) {    while (i < j)        swap(c, i++, j--);}private void swap(char[] c, int i, int j) {    char t = c[i];    c[i] = c[j];    c[j] = t;}
```



![image-20210508200202178](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210508200202178.png)

#### 方法二（使用了栈额外的空间O(N ))：

```java
import java.util.*;import java.lang.Character;public class Solution {    public String ReverseSentence(String str) {        Stack<String> stack = new Stack<>();        String[] strs = str.split(" ");        for(String s:strs){            stack.push(s);        }        String s = "";        int count = 0;        while(!stack.isEmpty()){            if(count != strs.length-1){                s += stack.pop()+" ";              }else{                 s += stack.pop();              }            count ++;                  }        return s;    }}
```

## 19.左旋转字符串

### 19.1题目描述

汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

### 19.2题目来源

[左旋转字符串_牛客题霸_牛客网 (nowcoder.com)](https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&from=cyc_github&tab=answerKey)

### 19.3示例1

#### 输入

```
"abcXYZdef",3
```

#### 返回值

```
"XYZdefabc"
```

### 19.4解决方案

首先翻转前n个字符，然后翻转后 len - n 个字符，最后翻转全部字符得到答案。

```java
public class Solution {    public String LeftRotateString(String str,int n) {        if(str == null || str.length()==0){            return "";        }        if(n == 0){            return str;        }        char[] chars = str.toCharArray();        int len = str.length();        //翻转前n个字符        reverse(chars,0,n-1);        //翻转右 len - k 个字符        reverse(chars,n,len-1);        //翻转全部字符        reverse(chars,0,len -1);      return new String(chars);    }    public void reverse(char[] chars,int i,int j){        while(i < j){            swap(chars,i++,j--);        }    }    public void swap(char[] chars,int i,int j){        char c = chars[i];        chars[i] = chars[j];        chars[j] = c;    }}
```

## 20.从尾到头打印链表

### 20.1题目描述

输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

### 20.2题目来源

[从尾到头打印链表_牛客题霸_牛客网 (nowcoder.com)](https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&from=cyc_github&tab=answerKey)

### 20.3题目实例

![image-20210508203317269](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210508203317269.png)

### 20.4解决方案

#### 20.4.1使用一个栈来打印

```java
/***  struct ListNode {*        int val;*        struct ListNode *next;*        ListNode(int x) :*              val(x), next(NULL) {*        }*  };*/class Solution {public:    vector<int> printListFromTailToHead(ListNode* head) {        stack<int> stack ;        vector<int> vec;        if(head == NULL){            return vec;        }        ListNode* p = head;        while(p != NULL){             stack.push(p->val);             p = p->next;        }                while(!stack.empty()){            vec.push_back(stack.top());            stack.pop();        }        return vec;    }};
```

![image-20210508203412599](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210508203412599.png)

#### 20.4.2解决方案二：递归遍历

```java
/***    public class ListNode {*        int val;*        ListNode next = null;**        ListNode(int val) {*            this.val = val;*        }*    }**/import java.util.ArrayList;public class Solution {    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {       ArrayList<Integer>  list = new ArrayList<>();        reverse(list,listNode);        return list;    }        public void reverse(ArrayList<Integer> list,ListNode no qde){        if(node == null){            return;        }else{            ListNode p = node.next;            reverse(list,p);            list.add(node.val);        }            }}
```

![image-20210508205411293](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210508205411293.png)

## 21.删除链表中重复的节点

### 21.1题目来源

[删除链表中重复的结点_牛客题霸_牛客网 (nowcoder.com)](https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&from=cyc_github&tab=answerKey)

### 21.2题目描述

在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

### 21.3题目示例

![image-20210508205717908](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210508205717908.png)

### 21.4解决方案

```java
/* public class ListNode {    int val;    ListNode next = null;    ListNode(int val) {        this.val = val;    }}*/public class Solution {    public ListNode deleteDuplication(ListNode pHead) {      if(pHead == null || pHead.next == null){          return pHead;      }        ListNode p1 = pHead;        ListNode p = null;        ListNode curr = null;        boolean flag = false;        while(p1 != null){            boolean fla = false;            ListNode p2 = p1.next;            while(p2 != null && p1.val == p2.val){                p2 = p2.next;                fla = true;            }            if(fla){                p1=p2;               if(p1==null){                    if(p == null){                p = p1;                curr = p1;            }else{                curr.next = p1;                curr = p1;            }               }            }else{                if(p == null){                p = p1;                curr = p1;            }else{                curr.next = p1;                curr = p1;            }                  p1 = p1.next;                             }                              }              return p;    }}
```

## 22.链表中倒数第 K 个结点

### 22.1题目来源

[链表中倒数第k个结点_牛客题霸_牛客网 (nowcoder.com)](https://www.nowcoder.com/practice/886370fe658f41b498d40fb34ae76ff9?tpId=13&tqId=11167&tab=answerKey&from=cyc_github)

### 22.2题目描述

输入一个链表，输出该链表中倒数第k个结点。

如果该链表长度小于k，请返回空。

### 22.3解题思路

设链表的长度为 N。设置两个指针 P1 和 P2，先让 P1 移动 K 个节点，则还有 N - K 个节点可以移动。此时让 P1 和 P2 同时移动，可以知道当 P1 移动到链表结尾时，P2 移动到第 N - K 个节点处，该位置就是倒数第 K 个节点。

```java
import java.util.*;/* * public class ListNode { *   int val; *   ListNode next = null; *   public ListNode(int val) { *     this.val = val; *   } * } */public class Solution {    /**     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可     *     *      * @param pHead ListNode类      * @param k int整型      * @return ListNode类     */    public ListNode FindKthToTail (ListNode pHead, int k) {       ListNode p = pHead;       ListNode p1 = null;        int count =  0;        while( p != null){            if(count == k){                p1 = p;              break;               }             count++;            p = p.next;        }        if(count < k){            return null;        }        p = pHead;        while( p1 != null){            p = p.next;            p1 = p1.next;        }        return p;    }}
```

## 23.链表中环的入口结点

### 23.1题目来源

[链表中环的入口结点_牛客题霸_牛客网 (nowcoder.com)](https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&from=cyc_github&tab=answerKey)

### 23.2题目描述

给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。要求不能使用额外的空间。

### 23.3解题方案

  设置快慢指针，都从链表头出发，快指针每次**走两步**，慢指针一次**走一步**，假如有环，一定相遇于环中某点(结论1)。接着让两个指针分别从相遇点和链表头出发，两者都改为每次**走一步**，最终相遇于环入口(结论2)。以下是两个结论证明：

### 两个结论：

**1、设置快慢指针，假如有环，他们最后一定相遇。**

**2、两个指针分别从链表头和相遇点继续出发，每次走一步，最后一定相遇与环入口。**

**证明结论1**：设置快慢指针fast和low，fast每次走两步，low每次走一步。假如有环，两者一定会相遇（因为low一旦进环，可看作fast在后面追赶low的过程，每次两者都接近一步，最后一定能追上）。

**证明结论2：**

设：

链表头到环入口长度为--**a**

环入口到相遇点长度为--**b**

相遇点到环入口长度为--**c**

![image-20210509010625023](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509010625023.png)

则：相遇时

**快指针路程=a+(b+c)k+b** ，k>=1 其中b+c为环的长度，k为绕环的圈数（k>=1,即最少一圈，不能是0圈，不然和慢指针走的一样长，矛盾）。

**慢指针路程=a+b**

快指针走的路程是慢指针的两倍，所以：

**（a+b）\*2=a+(b+c)k+b**

化简可得：

**a=(k-1)(b+c)+c** 这个式子的意思是： **链表头到环入口的距离=相遇点到环入口的距离+（k-1）圈环长度**。其中k>=1,所以**k-1>=0**圈。所以两个指针分别从链表头和相遇点出发，最后一定相遇于环入口。

```java
/* public class ListNode {    int val;    ListNode next = null;    ListNode(int val) {        this.val = val;    }}*/public class Solution {    public ListNode EntryNodeOfLoop(ListNode pHead) {        if(pHead == null ){            return null;        }        ListNode p1 = pHead;        ListNode p2 = pHead;        while(p2 != null){            p1 = p1.next;            if(p2.next == null || p2.next.next == null){                return null;            }            p2 = p2.next.next;            if(p1 == p2){               break;            }        }        if(p2 == null){            return null;        }        p1 = pHead;        while(p1 != p2){            p1 = p1.next;            p2 = p2.next;        }        return p1;    }}
```

![image-20210509010707933](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509010707933.png)

## 24.反转链表

## 24.1题目来源

[反转链表_牛客题霸_牛客网 (nowcoder.com)](https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&from=cyc_github&tab=answerKey)

### 24.1题目描述

输入一个链表，反转链表后，输出新链表的表头。

### 24.2示例

输入

```
{1,2,3}
```

输出

```
{3,2,1}
```

### 24.3解决办法

#### 方法一：头插法

```java
/*struct ListNode {	int val;	struct ListNode *next;	ListNode(int x) :			val(x), next(NULL) {	}};*/class Solution {public:    ListNode* ReverseList(ListNode* pHead) {        ListNode*  p = pHead;        ListNode* root = NULL;        ListNode* currNode = NULL;        while(p!=nullptr){            currNode = p;            p = p->next;            currNode->next = root;            root = currNode;        }        return root;    }};
```

![image-20210509011242264](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509011242264.png)

#### 方法二：递归头插法

```java
/*public class ListNode {    int val;    ListNode next = null;    ListNode(int val) {        this.val = val;    }}*/public class Solution {     ListNode root = null;     ListNode curr = null;    public ListNode ReverseList(ListNode head) {         if(head == null){        return null;    }               reverrse(head);        return root;            }        public void  reverrse(ListNode node){        if(node == null){            return;        }        ListNode p = node.next;        reverrse(p);        if(root == null){            root = node;            curr = node;        }else{        curr.next = node;        curr = node;        node.next = null;        }          }}
```

![image-20210509013411350](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509013411350.png)

## 25. 合并两个排序的链表

### 25.1题目来源

[合并两个排序的链表_牛客题霸_牛客网 (nowcoder.com)](https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&from=cyc_github&tab=answerKey)

### 25.2题目描述

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

### 25.3示例

![image-20210509013626379](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509013626379.png)

### 25.4解决方案

#### 方案一：迭代遍历

```java
/*public class ListNode {    int val;    ListNode next = null;    ListNode(int val) {        this.val = val;    }}*/public class Solution {    public ListNode Merge(ListNode list1,ListNode list2) {        if(list1 == null){            return list2;        }        if(list2 == null){            return list1;        }        ListNode p1 = list1;        ListNode p2 = list2;        ListNode root = null;        ListNode curr = null;        ListNode p = null;        while(p1 != null && p2 != null){            if(p1.val<=p2.val){                p = p1;                p1 = p1.next;            }else{                p = p2;                p2 = p2.next;            }            if( root == null){                root = p;                curr = p;            }else{                 curr.next = p;                 curr = p;            }        }       while(p1!=null){                curr.next = p1;                 curr = p1;               p1 = p1.next;       }        while(p2!=null){                curr.next = p2;                 curr = p2;               p2 = p2.next;       }        return root;    }}
```

![image-20210509014812166](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509014812166.png)

#### 方案二：递归遍历

```java
public ListNode Merge(ListNode list1, ListNode list2) {    if (list1 == null)        return list2;    if (list2 == null)        return list1;    if (list1.val <= list2.val) {        list1.next = Merge(list1.next, list2);        return list1;    } else {        list2.next = Merge(list1, list2.next);        return list2;    }}
```

![image-20210509015103421](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509015103421.png)

## 26.两个链表的第一个公共节点

### 26.1题目来源

[两个链表的第一个公共结点_牛客题霸_牛客网 (nowcoder.com)](https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&from=cyc_github&tab=answerKey)

### 26.2题目描述

输入两个无环的单链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）

### 26.3示例

![image-20210509015829253](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509015829253.png)

### 26.4解决方案

设 A 的长度为 a + c，B 的长度为 b + c，其中 c 为尾部公共部分长度，可知 a + c + b = b + c + a。

当访问链表 A 的指针访问到链表尾部时，令它从链表 B 的头部重新开始访问链表 B；同样地，当访问链表 B 的指针访问到链表尾部时，令它从链表 A 的头部重新开始访问链表 A。这样就能控制访问 A 和 B 两个链表的指针能同时访问到交点。

```java
/*public class ListNode {    int val;    ListNode next = null;    ListNode(int val) {        this.val = val;    }}*/public class Solution {    public ListNode FindFirstCommonNode(ListNode pHead1, ListNode pHead2) {      ListNode p1 = pHead1;        ListNode p2 = pHead2;        while(p1 != p2 ){            p1 = (p1 == null?pHead2:p1.next);             p2 = (p2 == null?pHead1:p2.next);        }        return p2;    }}
```

![image-20210509015755576](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509015755576.png)

## 27.二进制中 1 的个数

### 27.1题目链接

[牛客网](https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 27.2题目描述

输入一个整数，输出该数二进制表示中 1 的个数。

### 27.3解题思路

n&(n-1) 位运算可以将 n 的位级表示中最低的那一位 1 设置为 0。不断将 1 设置为 0，直到 n 为 0。时间复杂度：O(M)，其中 M 表示 1 的个数。

![image-20210509104433900](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509104433900.png)

```java
public class Solution {    public int NumberOf1(int n) {       int count = 0 ;        while(n != 0){            count++;            n &=(n-1);        }        return count;    }}
```

## 28数组中只出现一次的数字

### 28.1题目链接

[牛客网](https://www.nowcoder.com/practice/389fc1c3d3be4479a154f63f495abff8?tpId=13&tqId=11193&tab=answerKey&from=cyc_github)

### 28.2题目描述

一个整型数组里除了两个数字之外，其他的数字都出现了两次，找出这两个数。

### 28.3解题思路

#### 方案一：暴力解决

```java
import java.util.*;public class Solution {    /**     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可     *     *      * @param array int整型一维数组      * @return int整型一维数组     */    public int[] FindNumsAppearOnce (int[] array) {       int[] arr = new int[2];        int index = 0;        for(int i = 0;i < array.length;i++){            boolean fla = false;            for(int j = 0;j < array.length;j++){                if((array[i]-array[j])==0 && i !=j){                    fla =true;                    break;                }            }            if(fla == false){                arr[index++] = array[i];            }        }              if(arr[0]>arr[1]){            int c = arr[0];            arr[0] = arr[1];            arr[1] =c;        }        return arr;    }}
```

![image-20210509114017798](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509114017798.png)

#### 方案二：异或法

两个相等的元素异或的结果为 0，而 0 与任意数 x 异或的结果都为 x。

对本题给的数组的所有元素执行异或操作，得到的是两个不存在重复的元素异或的结果。例如对于数组 [x,x,y,y,z,k]，x^x^y^y^z^k = 0^y^y^z^k = y^y^z^k = 0^z^k = z^k。

两个不相等的元素在位级表示上一定会有所不同，因此这两个元素异或得到的结果 diff 一定不为 0。位运算 diff & -diff 能得到 diff 位级表示中最右侧为 1 的位，令 diff = diff & -diff。将 diff 作为区分两个元素的依据，一定有一个元素对 diff 进行异或的结果为 0，另一个结果非 0。设不相等的两个元素分别为 z 和 k，遍历数组所有元素，判断元素与 diff 的异或结果是否为 0，如果是的话将元素与 z 进行异或并赋值给 z，否则与 k 进行异或并赋值给 k。数组中相等的元素一定会同时与 z 或者与 k 进行异或操作，而不是一个与 z 进行异或，一个与 k 进行异或。而且这些相等的元素异或的结果为 0，因此最后 z 和 k 只是不相等的两个元素与 0 异或的结果，也就是不相等两个元素本身

```java
public int[] FindNumsAppearOnce (int[] nums) {    int[] res = new int[2];    int diff = 0;    for (int num : nums)        diff ^= num;    diff &= -diff;    for (int num : nums) {        if ((num & diff) == 0)            res[0] ^= num;        else            res[1] ^= num;    }    if (res[0] > res[1]) {        swap(res);    }    return res;}private void swap(int[] nums) {    int t = nums[0];    nums[0] = nums[1];    nums[1] = t;}
```

## 29.求 1+2+3+...+n

### 29.1题目链接

[NowCoder](https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 29.2题目描述

要求不能使用乘除法、for、while、if、else、switch、case 等关键字及条件判断语句 A ? B : C。



### 29.3解决方案

```c++
class Solution {public:    int Sum_Solution(int n) {               return sum_solution(n);    }   int sum_solution(int n){        if(n == 1){            return 1;        }        return n + sum_solution(n-1);   }};
```



![image-20210509154835963](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509154835963.png)

## 30.不用加减乘除做加法

### 30.1题目链接

[NowCoder](https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 30.2题目描述

写一个函数，求两个整数之和，要求不得使用 +、-、*、/ 四则运算符号。

### 30.3解决方案

#### 方案一（递归）：

a ^ b 表示没有考虑进位的情况下两数的和，(a & b) << 1 就是进位。

递归会终止的原因是 (a & b) << 1 最右边会多一个 0，那么继续递归，进位最右边的 0 会慢慢增多，最后进位会变为 0，递归终止。

![image-20210509161707724](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509161707724.png)

#### 方案二：非递归

```java
class Solution {public:    int Add(int num1, int num2) {      while(true){          if(num2 == 0){              return num1;          }else{                            int cxor = num1 ^ num2;              int cand = num1 & num2;              num2 = cand << 1;              num1 = cxor;          }                }    }};
```

![image-20210509162113536](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509162113536.png)

## 31.斐波那契数列

### 31.1题目链接

[牛客网](https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 31.2题目描述

求斐波那契数列的第 n 项，n <= 39。

[![img](https://camo.githubusercontent.com/88b00490c460e10d59df9094f891e3a7980360fd1e4f7366b4ef3b20008e710a/68747470733a2f2f63732d6e6f7465732d313235363130393739362e636f732e61702d6775616e677a686f752e6d7971636c6f75642e636f6d2f34356265393538372d363036392d346162372d623961632d3834306462316135333734342e6a7067)](https://camo.githubusercontent.com/88b00490c460e10d59df9094f891e3a7980360fd1e4f7366b4ef3b20008e710a/68747470733a2f2f63732d6e6f7465732d313235363130393739362e636f732e61702d6775616e677a686f752e6d7971636c6f75642e636f6d2f34356265393538372d363036392d346162372d623961632d3834306462316135333734342e6a7067)

### 31.3解题思路

如果使用递归求解，会重复计算一些子问题。例如，计算 f(4) 需要计算 f(3) 和 f(2)，计算 f(3) 需要计算 f(2) 和 f(1)，可以看到 f(2) 被重复计算了。

#### 方案一（递归）：

```c++
class Solution {public:    int Fibonacci(int n) {      if(n == 0 || n == 1){          return n;      }        return Fibonacci(n-1)+Fibonacci(n-2);    }};
```

![image-20210509170638367](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509170638367.png)

#### 方案二迭代：

```java
public class Solution {    public int Fibonacci( int n) {         if(n == 1 || n == 0){            return n;        }        int[] dp = new int[n+1];         dp[0] = 0;         dp[1] = 1;        for(int i = 2;i <=n ;i ++){            dp[i] = dp[i-1]+dp[i-2];        }        return dp[n];    }}
```

![image-20210509172157865](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509172157865.png)

#### 方案三：改进的迭代法

```java
public class Solution {    public int Fibonacci( int n) {         if(n == 1 || n == 0){            return n;        }        int[] dp = new int[3];         dp[0] = 0;         dp[1] = 1;        for(int i = 2;i <=n ;i ++){            dp[i%3] = dp[(i-1)%3]+dp[(i-2)%3];        }        return dp[n%3];    }}
```

```java
public class Solution {    public int Fibonacci( int n) {         if(n == 1 || n == 0){            return n;        }       int p1 = 0;       int p2 = 1;        int p3 = 0;        for(int i = 2;i <=n ;i ++){            p3 = p1 + p2;            p1 = p2;            p2 = p3;        }        return p3;    }}
```

![image-20210509173046119](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509173046119.png)



## 32.矩形覆盖

### 32.1题目来源

[矩形覆盖_牛客题霸_牛客网 (nowcoder.com)](https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&tqId=11163&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&from=cyc_github&tab=answerKey)

### 32.2题目描述

我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

比如n=3时，2*3的矩形块有3种覆盖方法：

### 32.3题目示例

![image-20210509173824644](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509173824644.png)

### 32.3解决方案

自然而然可以得出规律： f(n) = f(n-1) + f(n-2)， (n > 2)。

![image-20210509174226987](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509174226987.png)

```java
public class Solution {    public int rectCover(int target) {      if(target == 1 || target == 2){          return target;      }        int p1 = 1;        int p2 = 2;        int p3 = 0;       for(int i = 3;i <= target;i++){           p3 = p1 + p2;           p1 = p2 ;           p2 = p3;       }        return p3;    }}
```

![image-20210509174032592](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509174032592.png)

## 33.跳台阶

### 33.1题目链接

[牛客网](https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 33.2题目描述

一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

![image-20210509181146806](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509181146806.png)

### 33.3解决方案：

```c++
public class Solution {    public int jumpFloor(int target) {            if(target == 1 || target == 2){                return target;            }        int p1 = 1;        int p2 = 2;        int p3 = 0;        for(int i = 3;i <= target;i++){            p3 = p1 + p2 ;            p1 = p2;            p2 = p3;        }        return p3;    }}
```

![image-20210509185348380](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210509185348380.png)

## 34.变态跳台阶

### 34.1题目链接

[牛客网](https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 34.2题目描述

一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级... 它也可以跳上 n 级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法

![image-20210510233520781](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210510233520781.png)

### 34.3解决方案

#### 方法一：动态规划



```java
import java.util.Arrays;public class Solution {    public int jumpFloorII(int target) {      int[] dp = new int[target];      Arrays.fill(dp,1);        for(int i = 0;i < target;i++){            for(int j = 0;j < i;j++){                dp[i] +=dp[j];            }        }        return dp[target-1];    }}
```









![image-20210510233437675](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210510233437675.png)

#### 方法二：数学推导

跳上 n-1 级台阶，可以从 n-2 级跳 1 级上去，也可以从 n-3 级跳 2 级上去...，那么

```
f(n-1) = f(n-2) + f(n-3) + ... + f(0)
```

同样，跳上 n 级台阶，可以从 n-1 级跳 1 级上去，也可以从 n-2 级跳 2 级上去... ，那么

```
f(n) = f(n-1) + f(n-2) + ... + f(0)
```

综上可得

```
f(n) - f(n-1) = f(n-1)
```

即

```
f(n) = 2*f(n-1)
```

```java
public class Solution {    public int jumpFloorII(int target) {        if(target == 1){            return 1;        }       int sum = 1;       for(int i = 1;i < target;i++){           sum *=2;       }        return sum;    }}
```

![image-20210510234348332](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210510234348332.png)

## 35.连续子数组的最大和

### 35.1题目来源

[NowCoder](https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 35.2题目描述

{6, -3, -2, 7, -15, 1, 2, 2}，连续子数组的最大和为 8（从第 0 个开始，到第 3 个为止）。

### 35.3解题思路

```java
import java.lang.Integer;public class Solution {    public int FindGreatestSumOfSubArray(int[] array) {       if(array == null || array.length == 0){           return 0;       }        int sum = 0 ;        int greatestSum = Integer.MIN_VALUE;        for(int num : array){            sum = sum <= 0? num:sum + num;            greatestSum = Math.max(sum,greatestSum);        }        return greatestSum;    }}
```

![image-20210511000343435](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210511000343435.png)

## 36.重建二叉树

### 36.1题目链接

[牛客网](https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github)

### 36.2题目描述

根据二叉树的前序遍历和中序遍历的结果，重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

![image-20210516215843328](https://gitee.com/ljf2402901363/picgo-images/raw/master/typora/image-20210516215843328.png)



### 36.4解题思路

前序遍历的第一个值为根节点的值，使用这个值将中序遍历结果分成两部分，左部分为树的左子树中序遍历结果，右部分为树的右子树中序遍历的结果。然后分别对左右子树递归地求解。

[![img](https://camo.githubusercontent.com/550cb39fb6e602a26349b0bbdcbaf32eccf9cbc1a8b77731079d9c3e04e6f6be/68747470733a2f2f63732d6e6f7465732d313235363130393739362e636f732e61702d6775616e677a686f752e6d7971636c6f75642e636f6d2f36306334613434632d373832392d343234322d623361312d3236633362353133616166302e676966)](https://camo.githubusercontent.com/550cb39fb6e602a26349b0bbdcbaf32eccf9cbc1a8b77731079d9c3e04e6f6be/68747470733a2f2f63732d6e6f7465732d313235363130393739362e636f732e61702d6775616e677a686f752e6d7971636c6f75642e636f6d2f36306334613434632d373832392d343234322d623361312d3236633362353133616166302e676966)



```java 
java// 缓存中序遍历数组每个值对应的索引
private Map<Integer, Integer> indexForInOrders = new HashMap<>();

public TreeNode reConstructBinaryTree(int[] pre, int[] in) {
    for (int i = 0; i < in.length; i++)
        indexForInOrders.put(in[i], i);
    return reConstructBinaryTree(pre, 0, pre.length - 1, 0);
}

private TreeNode reConstructBinaryTree(int[] pre, int preL, int preR, int inL) {
    if (preL > preR)
        return null;
    TreeNode root = new TreeNode(pre[preL]);
    int inIndex = indexForInOrders.get(root.val);
    int leftTreeSize = inIndex - inL;
    root.left = reConstructBinaryTree(pre, preL + 1, preL + leftTreeSize, inL);
    root.right = reConstructBinaryTree(pre, preL + leftTreeSize + 1, preR, inL + leftTreeSize + 1);
    return root;
}
```

