#include <iostream>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

class ListNode{
public:
    int value;
    ListNode* next;
    ListNode(int value){
        this->value = value;
        next = nullptr;
    }

    ListNode* insertatstart(ListNode* head, int value){
        ListNode* newnode = new ListNode(value);

        if(head == nullptr){
            return newnode;
        }

        newnode->next = head;
        return newnode;
    }

    ListNode* insertatmid(ListNode* head, int value, int pos){
        if(head == nullptr){
            return nullptr;
        }

        if(pos == 1){
            return insertatstart(head, value);
        }

        ListNode* temp = head;

        for( int i = 0 ; i < pos - 1 && temp->next != nullptr; i++){
            temp = temp -> next;
        }

        if(temp -> next == nullptr) return nullptr;

        ListNode* newnode = new ListNode(value);

        newnode->next = temp->next;
        temp->next = newnode;

        return head;
    }

    ListNode* insertatend(ListNode* head, int value){

        if(head == nullptr) return insertatstart(head, value);

        ListNode* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        ListNode* deleter = temp;
        deleter = deleter->next;
        
        temp->next = nullptr;

        deleter->next = nullptr;
        delete deleter;

        return head;
    }

    ListNode* deleteatmid(ListNode* head, int pos){
        if(head == nullptr && head->next == nullptr) return nullptr;
        ListNode* temp = head;

        for(int i = 0; i < pos - 1 && temp->next!= nullptr; i++){
            temp = temp -> next;
        }

        if(temp->next == nullptr) return nullptr;
        
        temp->next == temp->next->next;

        return head;
    }

    // similar way for head start and end
};

class dequeue{
public:
    void dequealgo(vector<int> arr, int k){
        deque<int> dq;
        for( int i = 0; i < arr.size() ; i++){
            while( !dq.empty() && arr[dq.back()] <= arr[i] ){
                dq.pop_back();
            }
            while( !dq.empty() && dq.front() <= i-k ){
                dq.pop_front();
            }
            dq.push_back(i);
            if( i < k-1 ){
                //dq.pop_front(); ans
            }
        }
    }
};

class Stackingmono{
public:
    vector<int> monostack(vector<int> arr){
        vector<int> ans(arr.size(), 0);
        stack<int> st;
        for(int i = arr.size()-1; i >= 0; i++){
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top() - i;
            }
            
            st.push(i);
        }
        return ans;
        
    }
};

// circular linked list logic - already done 
