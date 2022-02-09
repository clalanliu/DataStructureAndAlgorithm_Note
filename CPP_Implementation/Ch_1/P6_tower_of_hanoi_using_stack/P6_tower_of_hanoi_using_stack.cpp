// P6_tower_of_hanoi_using_stack.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stack>
#include <limits>

using namespace std;

enum Action: int{
   None, L2M, M2L, R2M, M2R
};
inline const char* ToString(Action v)
{
   switch (v)
   {
   case L2M:   return "Left to Middle";
   case M2L:   return "Middle to Left";
   case R2M:   return "Right to Middle";
   case M2R:   return "Middle to Right";
   }
}

class hanoi_tower {
   stack<int> L_stack; 
   stack<int> M_stack; 
   stack<int> R_stack; 
   stack<Action> record;
   int step;
   int total_layer;

public:
   hanoi_tower(int layer) {
      L_stack = stack<int>({INT_MAX});
      M_stack = stack<int>({INT_MAX});
      R_stack = stack<int>({INT_MAX});
      record = stack<Action>({Action::None});
      step = 0;
      total_layer = layer;
      for (int i = layer; i >0; i--) {
         L_stack.push(i);
      }
      cout << "Left tower: "; print_stack(L_stack);  cout << endl;
      cout << "Mid. tower: "; print_stack(M_stack);  cout << endl;
      cout << "Right tower: "; print_stack(R_stack); cout << endl;
   }
   void print_stack(stack<int> s)
   {
      if (s.size() == 1)
         return;
      int x = s.top();
      s.pop();
      print_stack(s);
      cout << x << " ";
      s.push(x);
   }
   void play() {
      while (R_stack.size()< total_layer+1) {
         step += move_layer_A2B(L_stack, M_stack, Action::L2M, Action::M2L);
         step += move_layer_A2B(M_stack, L_stack, Action::M2L, Action::L2M);
         step += move_layer_A2B(R_stack, M_stack, Action::R2M, Action::M2R);
         step += move_layer_A2B(M_stack, R_stack, Action::M2R, Action::R2M);
      }
      cout << "Total Step = " << step << endl;
      cout << "Left tower: "; print_stack(L_stack);  cout << endl;
      cout << "Mid. tower: "; print_stack(M_stack);  cout << endl;
      cout << "Right tower: "; print_stack(R_stack); cout << endl;
   }
   int move_layer_A2B(stack<int>& A, stack<int>& B, Action ac, Action reverse_ac) {
      if (record.top() != reverse_ac && A.top() < B.top()) {
         B.push(A.top());
         A.pop();
         record.push(ac);
         cout << "Put " << B.top() << " from " << ToString(ac) << endl;
         return 1;
      }
      return 0;
   }

};

int main()
{
   hanoi_tower tower = hanoi_tower(5);
   tower.play();
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
