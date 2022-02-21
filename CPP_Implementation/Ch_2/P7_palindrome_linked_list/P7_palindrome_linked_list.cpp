// P7_palindrome_linked_list.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class Node
{
public:
   T data;
   Node* next;

   Node(T d) {
      data = d;
      next = NULL;
   }
};

template<typename T>
class NodeList
{
private:
   Node<T>* head;
   Node<T>* current;
public:
   NodeList() {
      head = NULL;
      current = head;
   }
   Node<T>* begin() {
      return head;
   }
   void push(T d) {
      if (head == NULL) {
         head = new Node<T>(d);
         current = head;
         return;
      }
      current->next = new Node<T>(d);
      current = current->next;
   }
   friend std::ostream& operator << (std::ostream& out, NodeList& L)
   {
      Node<T>* current_node = L.begin();
      while (current_node != nullptr) {
         out << current_node->data << ' ';
         current_node = current_node->next;
      }
      return out;
   }
   Node<T>* reverse_list(Node<T>* to) {
      Node<T>* prev_node = to;
      Node<T>* curr_node = to->next;
      Node<T>* next_node;

      while (curr_node!=nullptr) {
         next_node = curr_node->next;
         curr_node->next = prev_node;
         prev_node = curr_node;
         curr_node = next_node;
      }
      curr_node = prev_node;
      return curr_node;
   }
   bool check_palindrom() {
      if (head == nullptr || head->next == nullptr) return true;
      Node<T>* fast = head;
      Node<T>* slow = head;
      int count = 1;
      while (fast->next != nullptr && fast->next->next != nullptr) {
         slow = slow->next;
         fast = fast->next->next;
         count++;
      }
      Node<T>* right_current = reverse_list(slow);
      Node<T>* left_current = head;
      slow->next = nullptr;
      while (right_current != nullptr && left_current != nullptr) {
         //std::cout << left_current->data << ' ' << right_current->data << std::endl;
         if (left_current->data != right_current->data) return false;
         left_current = left_current->next;
         right_current = right_current->next;
      }
      return true;
   }
};


int main()
{
   NodeList<int> A;
   NodeList<int> B;
   NodeList<int> C;
   NodeList<int> D;
   int A_nums[7] = {1,3,5,7,5,3,1};
   int B_nums[7] = {1,3,5,8,7,3,1};
   int C_nums[8] = { 1,3,5,7,7,5,3,1 };
   int D_nums[8] = { 1,3,5,8,8,7,3,1 };

   for (size_t i = 0; i < sizeof(A_nums)/sizeof(A_nums[0]); i++) {
      A.push(A_nums[i]);
   }
   for (size_t i = 0; i < sizeof(B_nums) / sizeof(B_nums[0]); i++) {
      B.push(B_nums[i]);
   }
   for (size_t i = 0; i < sizeof(C_nums) / sizeof(C_nums[0]); i++) {
      C.push(C_nums[i]);
   }
   for (size_t i = 0; i < sizeof(D_nums) / sizeof(D_nums[0]); i++) {
      D.push(D_nums[i]);
   }

   std::cout << std::endl << "List A:" << std::endl << A;
   std::cout << std::endl << "List B:" << std::endl << B;
   std::cout << std::endl << "List C:" << std::endl << C;
   std::cout << std::endl << "List D:" << std::endl << D;

   std::cout << std::endl << "Is Palindrom ?" << std::endl;
   std::cout << A.check_palindrom() << std::endl;
   std::cout << B.check_palindrom() << std::endl;
   std::cout << C.check_palindrom() << std::endl;
   std::cout << D.check_palindrom() << std::endl;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
