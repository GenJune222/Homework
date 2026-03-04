#include <iostream>
#include "BiList.h"

int main()
{
  const int arr[] = {1, 2, 3, 4, 5};
  size_t size = sizeof(arr) / sizeof(arr[0]);

  BiList<int>* list = convert(arr, size);

  std::cout << "Список после convert: ";
  printList(list);

  add(list, 0);
  std::cout << "Добавление 0 в начало списка: ";
  printList(list);

  insert(list, 99);
  std::cout << "Вставка 99 после текущего элемента: ";
  printList(list);

  cut(list);
  std::cout << "Удаление текущего элемента: ";
  printList(list);

  erase(list);
  std::cout << "Удаление элемента после текущего: ";
  printList(list);

  clear(list);

  return 0;
}