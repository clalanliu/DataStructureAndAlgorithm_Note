// P5_reverse_part_of_linked_list.cpp : ���ɮץ]�t 'main' �禡�C�{���|��ӳB�}�l����ε�������C
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
   Node<T>* reverse_list(Node<T>* to, size_t legnth) {
      Node<T>* prev_node = to;
      Node<T>* curr_node = to->next;
      Node<T>* next_node;

      for (size_t i = 0; i < legnth; i++) {
         next_node = curr_node->next;
         curr_node->next = prev_node;
         prev_node = curr_node;
         curr_node = next_node;
      }
      curr_node = prev_node;
      return curr_node;
   }
   void reverse_list_range(size_t from, size_t to) {
      Node<T>* from_node = head;
      size_t length = to - from;
      for (; from > 1; from--) {
         from_node = from_node->next;
      }
      Node<T>* to_node = from_node;
      for (size_t i = 0; i < length; i++) {
         to_node = to_node->next;
      }

      Node<T>* to_node_next = to_node->next;

      Node<T>* reversed_head = reverse_list(from_node, length);
      from_node->next->next = to_node_next;
      from_node->next = to_node;
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
   std::cout << std::endl << "Reverse linked list:" << std::endl;
   A.reverse_list_range(3, 8);

   current = A.begin();
   for (size_t i = 0; i < vector_length; i++) {
      std::cout << current->data << ' ';
      current = current->next;
   }
}

// ����{��: Ctrl + F5 �� [����] > [�Ұʦ�������] �\���
// �����{��: F5 �� [����] > [�Ұʰ���] �\���

// �}�l�ϥΪ�����: 
//   1. �ϥ� [����`��] �����A�s�W/�޲z�ɮ�
//   2. �ϥ� [Team Explorer] �����A�s�u���l�ɱ���
//   3. �ϥ� [��X] �����A�Ѿ\�իؿ�X�P��L�T��
//   4. �ϥ� [���~�M��] �����A�˵����~
//   5. �e�� [�M��] > [�s�W����]�A�إ߷s���{���X�ɮסA�άO�e�� [�M��] > [�s�W�{������]�A�N�{���{���X�ɮ׷s�W�ܱM��
//   6. ����n�A���}�Ҧ��M�׮ɡA�Ыe�� [�ɮ�] > [�}��] > [�M��]�A�M���� .sln �ɮ�
