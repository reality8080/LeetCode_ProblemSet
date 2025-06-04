#include<iostream>
#include<vector>



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        int carry=0;
        while(curr1!=nullptr||curr2!=nullptr){
            int sum = carry+(curr1?curr1->val:0)+(curr2?curr2->val:0);
            carry = sum/10;
            curr1->val=sum%10;
            if(curr1->next==nullptr&&curr2->next==nullptr&&carry==0){
                return l1;
            }
            if(curr1->next==nullptr){
                curr1->next=new ListNode(0);
            }
            if(curr2->next==nullptr){
                curr2->next=new ListNode(0);
            }
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return l1;
    }
};

ListNode* taoDanhSachLienKet(const std::vector<int>& vals) {
    if (vals.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Hàm tiện ích: In các phần tử của danh sách liên kết
void inDanhSachLienKet(ListNode* head) {
    ListNode* current = head;
    std::cout << "[";
    while (current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr) {
            std::cout << ",";
        }
        current = current->next;
    }
    std::cout << "]" << std::endl;
}

// Hàm tiện ích: Xóa danh sách liên kết để giải phóng bộ nhớ
void xoaDanhSachLienKet(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* nodeTiepTheo = current->next;
        delete current;
        current = nodeTiepTheo;
    }
}

int main() {
    Solution sol; // Tạo đối tượng từ lớp Solution

    // --- Ví dụ 1 ---
    std::cout << "--- Vi du 1 ---" << std::endl;
    std::vector<int> daySo1_vd1 = {9,9,9,9,9,9,9,9,9,9}; // Biểu diễn số 342
    std::vector<int> daySo2_vd1 = {9,9,9,9,9,9}; // Biểu diễn số 465
    ListNode* l1_vd1 = taoDanhSachLienKet(daySo1_vd1);
    ListNode* l2_vd1 = taoDanhSachLienKet(daySo2_vd1);

    std::cout << "Dau vao l1: ";
    inDanhSachLienKet(l1_vd1);
    std::cout << "Dau vao l2: ";
    inDanhSachLienKet(l2_vd1);

    ListNode* ketQua_vd1 = sol.addTwoNumbers(l1_vd1, l2_vd1);
    std::cout << "Dau ra (tu doan code cua ban): ";
    inDanhSachLienKet(ketQua_vd1); // Sẽ in ra [2,4,3]
    
    // Giải phóng bộ nhớ
    // Lưu ý: vì hàm addTwoNumbers trả về l1, ketQua_vd1 và l1_vd1 trỏ đến cùng một danh sách.
    // xoaDanhSachLienKet(l1_vd1) sẽ xóa danh sách mà cả hai con trỏ này trỏ tới.
    // l2_vd1 là một danh sách riêng biệt và cũng cần được xóa.
    if (ketQua_vd1 != l1_vd1) { // Điều này sẽ không xảy ra với code hiện tại
        xoaDanhSachLienKet(ketQua_vd1); 
    }
    xoaDanhSachLienKet(l1_vd1); 
    xoaDanhSachLienKet(l2_vd1);
    l1_vd1 = nullptr; 
    l2_vd1 = nullptr;
    ketQua_vd1 = nullptr;
    return 0;
}