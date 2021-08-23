#include <stack>
#include <iostream>

using std::stack;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     * 
     * k个节点一组，逆转单链表
     * @param head ListNode类 头节点
     * @param k int整型 组大小
     * @return ListNode类
     */
    ListNode* revertLinkList(ListNode* head, int k) {
        if (head == nullptr || k <= 1) {
            return head;
        }
        stack<ListNode*> st;
        ListNode* ans = nullptr;
        ListNode* tmp = nullptr;
        while (head) {
            st.push(head);
            head = head->next;
            if (st.size() == k) {
                while (!st.empty()) {
                    if (ans == nullptr) {
                        ans = st.top();
                        tmp = st.top();
                    } else {
                        tmp->next = st.top();
                        tmp = tmp->next;
                    }
                    st.pop();            
                }
            }
        }
        stack<ListNode*> x;
        while (!st.empty()) {
            x.push(st.top()); st.pop();
        }
        while (!x.empty()) {
            if (ans == nullptr) {
                ans = x.top();
                tmp = x.top();
            } else {
                tmp->next = x.top();
                tmp = tmp->next;
            }
            x.pop();
        }
        tmp->next = nullptr;
        return ans;
    }
};

int
main()
{
    printf("Hello\n");
}