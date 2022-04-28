﻿// P4_binary_tree_and_string_conversion.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//


#include <iostream>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <queue>

const std::vector<std::string> split(const std::string& str, const std::string& pattern) {
   std::vector<std::string> result;
   std::string::size_type begin, end;

   end = str.find(pattern);
   begin = 0;

   while (end != std::string::npos) {
      if (end - begin != 0) {
         result.push_back(str.substr(begin, end - begin));
      }
      begin = end + pattern.size();
      end = str.find(pattern, begin);
   }

   if (begin != str.length()) {
      result.push_back(str.substr(begin));
   }
   return result;
}

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
   void printBT_preOrder(const std::string& prefix, const Node<T>* node, bool isLeft)
   {
      if (node != nullptr)
      {
         printBT_preOrder(prefix + (isLeft ? "│   " : "    "), node->left, true);
         std::cout << prefix;

         std::cout << (isLeft ? "┌──" : "└──");

         // print the value of the node
         std::cout << node->value << std::endl;

         // enter the next tree level - left and right branch

         printBT_preOrder(prefix + (isLeft ? "│   " : "    "), node->right, false);
      }
   }

   void printBT(const Node<T>* node)
   {
      printBT_inOrder("", node, false);
   }

   void print_preOrder()
   {
      Node<T>* node = root;
      std::stack<Node<T>*> node_stack;
      node_stack.push(root);
      while (!node_stack.empty())
      {
         node = node_stack.top();
         node_stack.pop();
         // print the value of the node
         std::cout << node->value << ' ';

         // enter the next tree level - left and right branch
         if (node->right) node_stack.push(node->right);
         if (node->left) node_stack.push(node->left);
      }

      std::cout << std::endl;
   }

   void toString(std::string& str)
   {
      Node<T>* node = root;
      std::stack<Node<T>*> node_stack;
      node_stack.push(root);
      while (!node_stack.empty())
      {
         node = node_stack.top();
         node_stack.pop();
         // print the value of the node
         str.append(std::to_string(node->value) + "!");
         if (!node->right)
            str.append("#!");
         if (!node->left)
            str.append("#!");
            

         // enter the next tree level - left and right branch
         if (node->right) node_stack.push(node->right);
         if (node->left) node_stack.push(node->left);
      }
   }

   void fromString(std::string& str)
   {
      std::vector<std::string> ret = split(str, "!");
      std::queue<std::string> value_queue;
      for (size_t i = 0; i < ret.size(); i++)
      {
         value_queue.push(ret[i]);
      }
      root = string2tree(value_queue);
   }
   Node<T>* string2tree(std::queue<std::string>& node_queue)
   {
      if (node_queue.empty())
      {
         return nullptr;
      }
      std::string value = node_queue.front();
      node_queue.pop();
      if (!value.compare("#"))
      {
         return nullptr;
      }
      Node<T>* node = new Node<T>(std::stoi(value));
      node->left = string2tree(node_queue);
      node->right = string2tree(node_queue);
      return node;
   }
};

int main()
{
   BinaryTree<int> bt = BinaryTree<int>(0);
   bt.construct_tree_random(20, 20);
   bt.printBT(bt.root);
   std::cout << "Pre order: " << std::endl;
   bt.print_preOrder();
   std::string out;
   bt.toString(out);
   std::cout << out << std::endl;
   BinaryTree<int> bt_2 = BinaryTree<int>();
   bt_2.fromString(out);
   bt_2.printBT(bt_2.root);
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
