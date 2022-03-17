// P10_add_two_numbers_represented_by_linked_lists.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
   Node* prev;

   Node(T d) {
      data = d;
      next = NULL;
      prev = NULL;
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
   void reverse_list() {
      Node<T>* prev_node = head;
      head = head->next;
      Node<T>* next_node;

      prev_node->next = NULL;
      while (head) {
         next_node = head->next;
         head->next = prev_node;
         prev_node = head;
         head = next_node;
      }
      head = prev_node;
   }
};

int main()
{
   NodeList<int> A;
   NodeList<int> B;
   size_t vector_length_A = 6;
   for (size_t i = 0; i < vector_length_A; i++) {
      A.push(rand() % 10);
   }
   size_t vector_length_B = 12;
   for (size_t i = 0; i < vector_length_B; i++) {
      B.push(rand() % 10);
   }

   std::cout << std::endl << "Linked List A:" << std::endl;
   auto current = A.begin();
   for (size_t i = 0; i < vector_length_A; i++) {
      std::cout << current->data << ' ';
      current = current->next;
   }
   std::cout << std::endl << "Reverse linked list:" << std::endl;
   A.reverse_list();

   current = A.begin();
   for (size_t i = 0; i < vector_length_A; i++) {
      std::cout << current->data << ' ';
      current = current->next;
   }

   std::cout << std::endl << "Linked List A:" << std::endl;
   current = B.begin();
   for (size_t i = 0; i < vector_length_B; i++) {
      std::cout << current->data << ' ';
      current = current->next;
   }
   std::cout << std::endl << "Reverse linked list:" << std::endl;
   B.reverse_list();

   current = B.begin();
   for (size_t i = 0; i < vector_length_B; i++) {
      std::cout << current->data << ' ';
      current = current->next;
   }

   NodeList<int> AB;
   auto current_A = A.begin();
   auto current_B = B.begin();
   auto current_AB = AB.begin();
   size_t vector_length_AB = (vector_length_A > vector_length_B) ? vector_length_A: vector_length_B;
   int num_A, num_B, carry = 0;
   for (size_t i = 0; i < vector_length_AB; i++) {
      if (current_A != nullptr)
      {
         num_A = current_A -> data;
         current_A = current_A->next;
      }
      else
      {
         num_A = 0;
      }
      if (current_B != nullptr)
      {
         num_B = current_B -> data;
         current_B = current_B->next;
      }
      else
      {
         num_B = 0;
      }
      AB.push((num_A + num_B + carry) % 10);
      carry = (num_A + num_B + carry) / 10;
      
      
   }
   if (carry > 0)
   {
      AB.push(carry);
   }
   AB.reverse_list();

   std::cout << std::endl << "Summation:" << std::endl;
   current = AB.begin();
   for (size_t i = 0; i < vector_length_B; i++) {
      std::cout << current->data << ' ';
      current = current->next;
   }
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
