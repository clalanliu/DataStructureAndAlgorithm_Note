// P7_sliding_window_maximum.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <deque>


template<typename T>
size_t find_index_of_max_of_array(T* arr, size_t arr_len)
{
   T max = arr[0];
   size_t max_index = 0;
   for (size_t j = 0; j < arr_len; ++j) {
      if (arr[j] > max) {
         max = arr[j];
         max_index = j;
      }
   }
   return max_index;
}

template <typename T>
T* sliding_window_maximum(T* arr, size_t arr_len, size_t window_len)
{
   std::deque<T> max_and_remaining_Q = std::deque<T>();
   T* max_array = new T[arr_len]{0};
   // Initial Step
   max_and_remaining_Q.push_back(find_index_of_max_of_array(arr, window_len));
   max_array[window_len - 1] = arr[max_and_remaining_Q.back()];

   for (size_t i = window_len; i < arr_len; i++) {
      // Remove the elements which
       // are out of this window
      if ((!max_and_remaining_Q.empty()) && max_and_remaining_Q.front() <= i - window_len) {
         // Remove from front of queue
         max_and_remaining_Q.pop_front();
      }
      while ((!max_and_remaining_Q.empty()) && arr[max_and_remaining_Q.back()] < arr[i]) {
         max_and_remaining_Q.pop_back();
      }
      max_and_remaining_Q.push_back(i);
      max_array[i] = arr[max_and_remaining_Q.front()];
   }
   return max_array;
}

int main()
{
   const size_t arr_len = 20;
   const size_t win_len = 4;
   int arr[arr_len];
   for (int i = 0; i < arr_len; i++) {
      arr[i] = (rand() % 10);
      std::cout << arr[i] << " ";
   }
   std::cout << std::endl;
   int* window_max_arr = sliding_window_maximum<int>(arr, arr_len, win_len);
   for (int i = 0; i < arr_len; i++) {
      std::cout << window_max_arr[i] << " ";
   }
   std::cout << std::endl;
   delete window_max_arr;
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
