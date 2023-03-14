//23. Merge k Sorted Lists
//time complexity O(n*len*log(len)), where n = first.size + second.size, len = lists.size
//space complexity O(n*len*log(len))
ListNode* merge_two_lists(ListNode* first, ListNode* second) {
    if(first == nullptr){
        return second;
    }
    if(second == nullptr){
        return first;
    }
    ListNode* tmp1 = first;
    ListNode* tmp2 = second;
    ListNode* result = new ListNode();
    ListNode* tmp = result;
    while (tmp1 && tmp2) {
        ListNode* current = new ListNode();
        if (tmp1->val <= tmp2->val) {
            current->val = tmp1->val;
            tmp1 = tmp1->next;
        }
        else {
            current->val = tmp2->val;
            tmp2 = tmp2->next;
        }
        tmp->next = current;
        tmp = tmp->next;
    }
    while (tmp1) {
        ListNode* current = new ListNode();
        current->val = tmp1->val;
        tmp->next = current;
        tmp1 = tmp1->next;
        tmp = tmp->next;
    }
    while (tmp2) {
        ListNode* current = new ListNode();
        current->val = tmp2->val;
        tmp->next = current;
        tmp2 = tmp2->next;
        tmp = tmp->next;
    }
    tmp = result;
    result = result->next;
    delete tmp;
    return result;
}
    
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
        return nullptr;
    }
    int len = lists.size();
    while (len > 1) {
        for (int i = 0; i < len / 2; ++i) {
            lists[i] = merge_two_lists(lists[i], lists[len - 1 - i]);
        }
        len = (len + 1) / 2;
    }
    return lists.front();
}