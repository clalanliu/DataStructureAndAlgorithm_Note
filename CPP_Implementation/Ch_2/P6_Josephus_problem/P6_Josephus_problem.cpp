// P6_Josephus_problem.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
         head->next = head;
         current = head;
         return;
      }
      current->next = new Node<T>(d);
      current->next->next = head;
      current = current->next;
   }
   friend std::ostream& operator << (std::ostream& out, NodeList& L)
   {
      Node<T>* current_node = L.begin();
      while(current_node->next!= L.begin()) {
         out << current_node->data << ' ';
         current_node = current_node->next;
      }
      out << current_node->data << std::endl;
      return out;
   }
   Node<T>* josephus_delete(size_t josephus_kill_step) {
      std::cout << *this;
      if (head == NULL || head->next == head || josephus_kill_step < 1) {
         return head;
      }
      Node<int>* current_node = head;
      while (current_node->next != this->begin()) {
         current_node = current_node->next;
      }
      Node<int>* next_node;
      while (head->next != head) {
         size_t count = 1;
         for (; count < josephus_kill_step; count++) {
            current_node = current_node->next;
         }
         next_node = current_node->next;
         current_node->next = current_node->next->next;
         if (head == next_node)head = next_node->next;
         delete next_node;
         std::cout << *this;
      }
   }
};


int main()
{
   NodeList<int> A;
   size_t vector_length = 41;
   size_t josephus_kill_step = 3;
   for (size_t i = 0; i < vector_length; i++) {
      A.push(i+1);
   }

   std::cout << std::endl << "List A:" << std::endl;
   auto current = A.begin();
   for (size_t i = 0; i < vector_length; i++) {
      std::cout << current->data << ' ';
      current = current->next;
   }
   std::cout << std::endl << "Naive Josephus Deleting:" << std::endl;
   A.josephus_delete(josephus_kill_step);
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
