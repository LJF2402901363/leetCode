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

