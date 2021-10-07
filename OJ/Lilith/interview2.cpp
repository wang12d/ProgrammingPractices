#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    using mpq = priority_queue<int, vector<int>, greater<int>>;
    ListNode* sortList(ListNode* head) {
        mpq pq;
        ListNode* ans{head};
        while (head) {
            pq.push(head->val);
            head = head->next;
        }
        mpq secondPQ;
        ListNode* tmp{ans}; int cnt{0};
        mpq* a;
        mpq* b;
        while (true) {
            if (cnt & 1) {
                a = &secondPQ;
                b = &pq;
            }  else {
                a = &pq;
                b = &secondPQ;
            }
            if (a->empty()) {
                break;
            }
            tmp->val = a->top(); a->pop();
            int prev = tmp->val; tmp = tmp->next;
            while (!a->empty()) {
                while (!a->empty() && prev  == a->top()) {
                    b->push(a->top()); a->pop();
                }
                if (!a->empty()) {
                    tmp->val = a->top();
                    a->pop(); prev = tmp->val;
                    tmp = tmp->next;
                }
            }
            cnt++;
        }
        return ans;
    }
};