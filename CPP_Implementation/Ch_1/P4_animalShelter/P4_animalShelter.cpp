#include<iostream>
#include<queue>
#include<utility>
#include<vector>

using namespace std;

template <typename T, typename U>
class AnimalShelter {

private:
   queue<pair<T, U>> queue_cat;
   queue<pair<T, U>> queue_dog;
   int count = 0;

public:
   AnimalShelter() {
      queue_cat = queue<pair<T, U>>();
      queue_dog = queue<pair<T, U>>();
   }


   void enqueue(vector<U> animal) {
      if (animal[1]) {
         queue_dog.push({ count, animal[0] });
      }
      else {
         queue_cat.push({ count,animal[0] });
      }
      count++;
   }

   vector<U> dequeueAny() {
      if (queue_dog.empty() && queue_cat.empty()) return { -1, -1 }; 
      else if (queue_cat.empty() && queue_dog.size()) return dequeueDog();
      else if (queue_dog.empty() && queue_cat.size()) return dequeueCat(); 
      else if (queue_dog.front() < queue_cat.front()) return dequeueDog(); 
      else return dequeueCat();
   }

   vector<U> dequeueDog() {
      if (queue_dog.empty()) return { -1, -1 }; 
      U temp = queue_dog.front().first;
      queue_dog.pop();
      return { temp, 1 };
   }

   vector<U> dequeueCat() {
      if (queue_cat.empty()) return { -1, -1 }; 
      int temp = queue_cat.front().first;
      queue_cat.pop();
      return { temp, 0 };
   }
};


int main()
{
   AnimalShelter<int, int> shelter = AnimalShelter<int, int>();
   shelter.enqueue(vector<int>{ 0, 0 });
   shelter.enqueue(vector<int>{ 1, 0 });
   auto a = shelter.dequeueCat();
   auto b = shelter.dequeueDog();
   auto c = shelter.dequeueAny();
   
}
