#include <iostream>
#include <stack>
#include <stdlib.h>

using namespace std;


template <typename T>
void PrintStack(stack<T> s)
{
   // If stack is empty then return
   if (s.empty())
      return;
   int x = s.top();
   // Pop the top element of the stack
   s.pop();
   // Recursively call the function PrintStack
   PrintStack(s);
   // Print the stack element starting
   // from the bottom
   cout << x << " ";
   // Push the same element onto the stack
   // to preserve the order
   s.push(x);
}

template <typename T>
class StackWithReverse: public stack<T>
{
public:
   T get_and_remove_last_element() {
      T top = this->top();
      this->pop();
      if (this->empty()) {
         return top;
      }
      else {
         T last = this->get_and_remove_last_element();
         this->push(top);
         return last;
      }
   }

   void reverse() {
      if (this->empty()) {
         return;
      }
      else {
         T last = this->get_and_remove_last_element();
         PrintStack<T>(*this);
         cout << endl;
         this->reverse();
         this->push(last);
      }
   }
};

int main()
{
   StackWithReverse<int> mystack = StackWithReverse<int>();
   cout << "Push array:" << endl;
   for (int i = 0; i < 10; i++) {
      mystack.push(rand() % 10);
      cout << mystack.top() << ' ';
   }
   cout << endl;

   cout << "Reverse stack:" << endl;
   mystack.reverse();
   for (int i = 0; i < 10; i++) {
      cout << mystack.top() << ' ';
      mystack.pop();
   }
   cout << endl;
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
