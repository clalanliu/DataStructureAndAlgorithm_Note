﻿#include <iostream>
#include <stack>
#include <stdlib.h>

using namespace std;

template <typename T> class StackWithGetMin
{
private:
   stack<T> stack_data;
   stack<T> stack_min;

public:
   StackWithGetMin() {
      this->stack_data = stack<T>();
      this->stack_min = stack<T>();
   }

   T pop() {
      if (this->stack_data.empty()) {
         throw runtime_error("Error: The stack is empty.");
      }
      T t = this->stack_data.top();
      this->stack_data.pop();
      if (t == this->getMin()) {
         this->stack_min.pop();
      }
      return t;
   }

   T top() {
      if (this->stack_data.empty()) {
         throw runtime_error("Error: The stack is empty.");
      }
      return this->stack_data.top();
   }

   void push(T t) {
      if (this->stack_min.empty() || t <= this->getMin()) {
         this->stack_min.push(t);
      }
      this->stack_data.push(t);
   }

   T getMin() {
      if (this->stack_min.empty()) {
         throw runtime_error("Error: The stack is empty.");
      }
      else {
         return this->stack_min.top();
      }
   }
};

int main()
{
   StackWithGetMin<int> mystack = StackWithGetMin<int>();
   cout << "Push array:" << endl;
   for (int i = 0; i < 10; i++) {
      mystack.push(rand() % 10);
      cout << mystack.top() << ' ' << mystack.getMin() << endl;
   }

   cout << "Pop stack:" << endl;
   for (int i = 0; i < 10; i++) {
      cout << mystack.top() << ' ' << mystack.getMin() << endl;
      mystack.pop();
   }
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
