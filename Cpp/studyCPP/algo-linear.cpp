#include "pch.h"
#include "helper.hpp"
using namespace aux;

/*
  List
  Array
  LineSweep , scan
*/


namespace {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* helper_build_list(vector<int> vs) {
        vector<ListNode*> data;
        for (int i : vs) {
            data.push_back(new ListNode(i));
        }

        for (int i = 0; i < data.size() - 1; ++i) {
            data[i]->next = data[i + 1];
        }
        return data.empty() ? NULL : data[0];
    }

    void helper_print_list(ListNode* l) {
        while (l) {
            cout << l->val << " ";
            l = l->next;
        }
        cout << "\n";
    }

    // a= a+b;
    ListNode* helper_add_list(ListNode* a, ListNode* b) {
        if (!a) {
            return b;
        }
        if (!b) {
            return a;
        }
        ListNode* rt = a;
        while (a->next)
        {
            a = a->next;
        }
        a->next = b;
        return rt;
    }
}

//83. Remove Duplicates from Sorted List
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* rt = head;
    while (head)
    {
        int i = head->val;
        ListNode* pst = head->next;
        while (pst)
        {
            if (i != pst->val) {
                break;
            }
            head->next = pst->next;
            delete pst;
            pst = head->next;
        }
        head = head->next;
    }
    return rt;
}

// 92 ,Reverse Linked List II   1<=m<=n<=list.length
//ListNode* reverseBetween(ListNode* head, int m, int n) {
//
//}

//141. Linked List has cycle
bool hasCycle(ListNode* head) {
    // uisng tortoise and hare (hare is 2 step each time)

    ListNode* tortoise = head;
    ListNode* hare = head;  // step 2 forward each time

    do {
        if (tortoise != NULL) {
            tortoise = tortoise->next;
        }
        if (hare != NULL) {
            hare = hare->next;
            if (hare != NULL) {
                hare = hare->next;
            }
        }
    } while (tortoise != hare);

    return tortoise != NULL;

}

//142. Linked List Cycle II
ListNode* detectCycle(ListNode* head) {
    ListNode* tortoise = head;
    ListNode* hare = head;  // step 2 forward each time

    do {
        if (tortoise != NULL) {
            tortoise = tortoise->next;
        }
        if (hare != NULL) {
            hare = hare->next;
            if (hare != NULL) {
                hare = hare->next;
            }
        }
    } while (tortoise != hare);

    if (tortoise == NULL) {
        return NULL;
    }
    // tortoise != NULL, how to find the entry of the loop?
    
    while (tortoise!=head)
    {
        tortoise = tortoise->next;
        head = head->next;
    }
    return tortoise;
}



// 160. Intersection of Two Linked Lists
// two stack -> time limit
// each a in headA will be tested in headB
// allgin to right, and then headA and headB going with same step
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    // sanity check
    if (!headA || !headB) {
        return NULL;
    }
    set<ListNode*> cache;
    while (headA)
    {
        cache.insert(headA);
        headA = headA->next;
    }

    while (headB)
    {
        if (cache.find(headB) != cache.end()) {
            return headB;
        }
        headB = headB->next;
    }

    return NULL;
}
//203. Remove Linked List Elements,  Remove all elements from a list that have value val.
ListNode* removeElements(ListNode* head, int val) {
    if (!head) {
        return head;
    }
    // using dummy head
    ListNode* dummyHead = new ListNode(-1);
    dummyHead->next = head;
    auto pre = dummyHead;    
    while (head)
    {
        if (head -> val != val) {
            pre = head;
            head = head->next;
        }
        else {
            pre->next = head->next;
            delete head;
            head = pre->next;
        }
    }
    head = dummyHead->next;
    delete dummyHead;
    return head;
}


//206 Reverse Linked List
ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    while (head)
    {
        // find post
        ListNode* pst = head->next;
        // reverse
        head->next = pre;
        pre = head;
        // cur ++;
        head = pst;
    }
    return pre;
}

ListNode* reverseList_recursively(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* newHead = reverseList_recursively(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}


TEST(AlgoLinear, LeetCodeList) {
    EXPECT_FALSE(hasCycle(new ListNode(12)));
    // remove dup
    helper_print_list(deleteDuplicates(helper_build_list({ 1,1,2,2,2,3,3,4,4,5,5,5 })));

    // for reverse
    helper_print_list(reverseList(helper_build_list({ 1,2,3,4,5 })));
    helper_print_list(reverseList_recursively(helper_build_list({1,2,3,4,5,6})));

    // for getIntersectionNode
    auto lc = helper_build_list({ 8,4,5 });
    auto la = helper_add_list(helper_build_list({ 4,1 }), lc);
    auto lb = helper_add_list(helper_build_list({ 5,0,1 }), lc);

    EXPECT_TRUE(NULL!= getIntersectionNode(la, lb));
    
    //  remove value =7;
    helper_print_list(removeElements(helper_build_list({ 4,4,1,2,3,4,5,6,4,7,8,5,4,4,4,4,9,4 }), 4));
    
}



// 86 merge two vecotr 
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    int i = 0;
    while (i < n) {
        int cur = nums2[i];
        // merge into nums1
        for (int j = m; j > 0; j--) {
            nums1[j] = cur;
            if (cur < nums1[j - 1]) {
                swap(nums1[j], nums1[j - 1]);
            }
            else {
                break;
            }
        }
        m++;
        i++;
    }
}

TEST(AlgoLinear, LeetCodeArray) {

    vector<int> n1{ 1,2,3,0,0,0 };
    vector<int> n2{ 4,5,6 };
    merge(n1, 3, n2, 3);
    
}



//[[1,4],[3,6],[2,8]] remove [3,6], return count(remainde)
int removeCoveredIntervals(vector<vector<int>> intervals) {
    // sanity check
    if (intervals.size() < 2) {
        return intervals.size();
    }
    // sort first
    std::sort(intervals.begin(), intervals.end(),
        [](vector<int>& l, vector<int>& r) {
            if (l[0] < r[0]) {
                return true;
            }
            else if (l[0] == r[0]) {
                if (l[1] >= r[1]) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    );
    int answer = intervals.size();

    int r_max = intervals[0][1];
    // only compare the val of right in  [left,right) is enough;
    // fixup right_max when iterating
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][1] < r_max) {
            answer--;
        }
        else {
            r_max = intervals[i][1];
        }
    }
    return answer;
}

TEST(AlgoLinear, LeetCodeLineSweep) {
    println("line sweep ->  remove covered range");

    vector<vector<int>> data{ {1,4},{3,6},{2,8} };
    EXPECT_EQ(2, removeCoveredIntervals(data));

}
