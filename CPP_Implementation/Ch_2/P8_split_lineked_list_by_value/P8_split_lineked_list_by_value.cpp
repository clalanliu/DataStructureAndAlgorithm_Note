// P8_split_lineked_list_by_value.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
   void splitLinkedList(T pivot)
   {
      Node<T>* smaller_head = new  Node<T>(0);
      Node<T>* same_head = new  Node<T>(0);
      Node<T>* larger_head = new  Node<T>(0);
      Node<T>* smaller_tail = smaller_head;
      Node<T>* same_tail = same_head;
      Node<T>* larger_tail = larger_head;

      Node<T>* current_node = this->begin();
      while (current_node != nullptr) {
         if (current_node->data == pivot)same_tail = append_node_after_node(same_tail, current_node);
         if (current_node->data <  pivot)smaller_tail = append_node_after_node(smaller_tail, current_node);
         if (current_node->data >  pivot)larger_tail = append_node_after_node(larger_tail, current_node);

         current_node = current_node->next;
      }
      if (smaller_head->next)
      {
         this->head = smaller_head->next;
         if (same_head->next)
         {
            smaller_tail->next = same_head->next;
            same_tail->next = larger_head->next;
         }
         else
            smaller_tail->next = larger_head->next;
      }
      else
      {
         if (same_head->next)
         {
            this->head = same_head->next;
            same_tail->next = larger_head->next;
         }
         else
            this->head = larger_head->next;
      }
      larger_tail->next = nullptr;
      this->current = larger_tail;

      return;

   }
   Node<T>* append_node_after_node(Node<T>* tail, Node<T>* to_be_pushed)
   {
      tail->next = to_be_pushed;
      tail = to_be_pushed;
      return tail;
   }
   
};


int main()
{
   NodeList<int> A;
   size_t vector_length = 20;
   for (size_t i = 0; i < vector_length; i++) {
      A.push(rand() % 20);
   }

   std::cout << std::endl << "Linked List A:" << std::endl;
   auto current = A.begin();
   for (size_t i = 0; i < vector_length; i++) {
      std::cout << current->data << ' ';
      current = current->next;
   }

   std::cout << std::endl << "Prior: " << 10 << std::endl;
   A.splitLinkedList(10);
   current = A.begin();
   for (size_t i = 0; i < vector_length; i++) {
      std::cout << current->data << ' ';
      current = current->next;
   }


   std::cout << std::endl << "Prior: " << 40 << std::endl;
   A.splitLinkedList(40);
   current = A.begin();
   for (size_t i = 0; i < vector_length; i++) {
      std::cout << current->data << ' ';
      current = current->next;
   }

   std::cout << std::endl << "Prior: " << 5 << std::endl;
   A.splitLinkedList(5);
   current = A.begin();
   for (size_t i = 0; i < vector_length; i++) {
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
