#ifndef BILIST_H
#define BILIST_H
#include <cstddef>

template< class T >
struct BiList {
  T data;
  BiList<T>* next;
  BiList<T>* prev;
};

template <class T>
void clear (BiList<T>*& h){
  if (!h) {
    return;
  }
  if (h->prev) {
    h->prev->next = nullptr;
  }
  while (h) {
    BiList<T>* curr = h->next;
    delete h;
    h = curr;
  }
}

template <class T>
BiList<T>* convert(const T* d, size_t s) {
  if (s == 0) {
    return nullptr;
  }
  BiList<T>* head = s? new BiList<T>{d[0], nullptr, nullptr}: nullptr;
  BiList<T>* current = head;
  try {
    for (size_t i = 1; i < s; ++i) {
      BiList<T>* n = new BiList<T>{d[i], nullptr, current};
      current->next = n;
      current = n;
    }
  }catch (...) {
    clear(head);
    throw;
  }
  current->next = head;
  head->prev = current;
  return head;
}

template <class T>
BiList<T>* add (BiList<T>*& h, const T& d) {
  BiList<T>* node = new BiList<T>{d,h};
  if (h == nullptr) {
    node->next = node;
    node->prev = node;
    h = node;
  }else {
    BiList<T>* prev_h = h->prev;
    node->next = h;
    node->prev = prev_h;

    prev_h->next = node;
    h->prev = node;
    h = node;
  }
  return node;
}

template <class T>
BiList<T>* insert (BiList<T>*& h, const T& d) {
  BiList<T>* node = new BiList<T>{d,h->next};
  BiList<T>* next_h = h->next;

  node->prev = h;
  node->next = next_h;
  h->next = node;
  next_h->prev = node;

  return node;
}

template <class T>
BiList<T>* cut(BiList<T>*& h) {
  if (h == nullptr) {
    return nullptr;
  }
  if (h->next == h && h->prev == h) {
    delete h;
    h = nullptr;
    return nullptr;
  }
  BiList<T>* node = h->next;
  BiList<T>* prev_h = h->prev;

  node->prev = prev_h;
  prev_h->next = node;

  BiList<T>* result = node;
  delete h;
  h = result;

  return result;
}

template <class T>
BiList<T>* erase(BiList<T>* h) {
  if (h == nullptr) {
    return nullptr;
  }
  BiList<T>* node = h->next;
  if (node == h) {
    return h;
  }
  if (node->next == h) {
    h->prev = node->next;
  }
  BiList<T>* nextNode = node->next;

  h->next = nextNode;
  nextNode->prev = h;
  delete node;

  return nextNode;
}

template< class T >
void printList(BiList<T> * h)
{
  if (!h)
  {
    return;
  }
  std::cout << h->data << " ";
  BiList<T> * current = h->next;
  while (current != h)
  {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << "\n";
}
#endif