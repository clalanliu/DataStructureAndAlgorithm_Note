// P1_stack_with_getMin.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stack>
#include <stdlib.h>

using namespace std;

template <typename T> class TwoStacksQueue
{
private:
   stack<T> stack_push;
   stack<T> stack_pop;

public:
   TwoStacksQueue() {
      this->stack_push = stack<T>();
      this->stack_pop = stack<T>();
   }

   T pop() {
      if (this->stack_push.empty() && this->stack_pop.empty()) {
         throw runtime_error("Error: The stack is empty.");
      }
      if (this->stack_pop.empty()) {
         while (!stack_push.empty()) {
            stack_pop.push(stack_push.top());
            stack_push.pop();
         }
      }
      T t = stack_pop.top();
      stack_pop.pop();
      return t;
   }

   T peek() {
      if (this->stack_push.empty() && this->stack_pop.empty()) {
         throw runtime_error("Error: The stack is empty.");
      }
      if (this->stack_pop.empty()) {
         while (!stack_push.empty()) {
            stack_pop.push(stack_push.top());
            stack_push.pop();
         }
      }
      T t = stack_pop.top();
      return t;
   }

   void push(T t) {
      this->stack_push.push(t);
   }
};

int main()
{
   TwoStacksQueue<int> mystack = TwoStacksQueue<int>();
   cout << "Push array:" << endl;
   for (int i = 0; i < 5; i++) {
      int t = rand() % 10;
      mystack.push(t);
      cout << t << ' ';
   }
   cout << endl;

   cout << "Pop array:" << endl;
   for (int i = 0; i < 4; i++) {
      cout << mystack.pop() << ' ';
   }
   cout << endl;

   cout << "Push array:" << endl;
   for (int i = 0; i < 5; i++) {
      int t = rand() % 10;
      mystack.push(t);
      cout << t << ' ';
   }
   cout << endl;

   cout << "Pop array:" << endl;
   for (int i = 0; i < 5; i++) {
      cout << mystack.pop() << ' ';
   }
   cout << endl;
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
