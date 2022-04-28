// P5_morris_traversal.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <iostream>
#include <stdlib.h>
#include <stack>

template< class T>
class Node {
public:
   T value;
   Node* left;
   Node* right;
   Node(T d) {
      value = d;
      left = nullptr;
      right = nullptr;
   }
};

template< class T>
class BinaryTree {
public:
   Node<T>* root;
   BinaryTree() {
      root = nullptr;
   }
   BinaryTree(T d) {
      root = new Node<T>(d);
   }
   Node<T>* insertLevelOrder(T arr[], Node<T>* current_root, int i, int n)
   {
      // Base case for recursion
      if (i < n)
      {
         Node<T>* current_root = new Node<T>(arr[i]);

         // insert left child
         current_root->left = insertLevelOrder(arr,
            current_root->left, 2 * i + 1, n);

         // insert right child
         current_root->right = insertLevelOrder(arr,
            current_root->right, 2 * i + 2, n);
         return current_root;
      }
      return nullptr;
   }
   void construct_tree_random(size_t num, size_t max_num) {
      Node<T>* current = root;
      T* arr = new T[num];
      srand(0);
      for (int i = 0; i < num; i++)
      {
         int rand_num = rand() % max_num;
         arr[i] = rand_num;
      }
      root = insertLevelOrder(arr, current, 0, num);


      delete[] arr;
   }

   void printBT_inOrder(const std::string& prefix, const Node<T>* node, bool isLeft)
   {
      if (node != nullptr)
      {
         std::cout << prefix;

         std::cout << (isLeft ? "├──" : "└──");

         // print the value of the node
         std::cout << node->value << std::endl;

         // enter the next tree level - left and right branch
         printBT_inOrder(prefix + (isLeft ? "│   " : "    "), node->left, true);
         printBT_inOrder(prefix + (isLeft ? "│   " : "    "), node->right, false);
      }
   }
   
   void printBT(const Node<T>* node)
   {
      printBT_inOrder("", node, false);
   }

   void print_inOrder()
   {
      Node<T>* node = root;
      std::stack<Node<T>*> node_stack;

      //node_stack.push(node->right);
      node_stack.push(node);
      node = node->left;

      while (!node_stack.empty() || node)
      {
         while (node)
         {
            node_stack.push(node);
            node = node->left;
         }
         node = node_stack.top();
         std::cout << node->value << ' ';
         node_stack.pop();
         node = node->right;
      }
      std::cout << std::endl;
   }

   void print_inOrder_Morris()
   {
      if (!root) return;
      Node<T>* node = root;
      Node<T>* pred = nullptr;
      while (node)
      {
         if (node->left)
         {
            pred = node->left;
            while (pred->right && pred->right!=node)
            {
               pred = pred->right;
            }
            if (!pred->right)
            {
               pred->right = node;
               node = node->left;
               continue;
            }
            pred->right = nullptr;
         }
         std::cout << node->value << ' ';
         node = node->right;
      }
   }
   
};

int main()
{
   BinaryTree<int> bt = BinaryTree<int>(0);
   bt.construct_tree_random(20, 20);
   bt.printBT(bt.root);
   std::cout << "In order: " << std::endl;
   bt.print_inOrder();
   bt.print_inOrder_Morris();
   return 0;
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
