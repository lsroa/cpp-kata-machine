#pragma once
#include <iostream>
#include <memory>
#include <ostream>

template <typename T>
class Node {
 public:
  Node(T data) : data(data){};
  std::shared_ptr<Node> next;
  T data;
};

template <typename T>
class LinkedList {
 public:
  LinkedList() = default;
  std::shared_ptr<Node<T>> head;
  std::shared_ptr<Node<T>> tail;
  int length;
  void append(T data);
  void prepend(T data);
  T get(int index);
  T remove(T data);
  T removeAt(int index);
  friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list);
};

template <typename T>
T LinkedList<T>::get(int index) {
  auto node = head;

  if (index > length) {
    std::invalid_argument("Invalid index");
  }

  for (int i = 0; i < index; i++) {
    node = node->next;
  }

  return node->data;
};

template <typename T>
T LinkedList<T>::remove(T target) {
  auto node = head;
  std::shared_ptr<Node<T>> prev;

  if (head->data == target) {
    T value = head->data;
    head = head->next;
    length--;
    return value;
  }

  while (node != nullptr) {
    if (node->data == target) {
      prev->next = node->next;
      T value = node->data;
      length--;
      return value;
    }
    prev = node;
    node = node->next;
  }

  throw std::invalid_argument("Value not found");
};

template <typename T>
T LinkedList<T>::removeAt(int index) {
  auto node = head;
  std::shared_ptr<Node<T>> prev;

  if (index == 0) {
    auto [new_head, value] = (*head);
    head = new_head;
    length--;
    return value;
  }

  for (int i = 0; i < index; i++) {
    prev = node;
    node = node->next;
  }

  prev->next = node->next;
  T value = node->data;

  length--;
  return value;
};

template <typename T>
void LinkedList<T>::prepend(T data) {
  auto new_node = std::make_shared<Node<T>>(data);

  if (length == 0) {
    head = tail = new_node;
    length++;
    return;
  }

  new_node->next = head;
  head = new_node;
  length++;
};

template <typename T>
void LinkedList<T>::append(T data) {
  auto new_node = std::make_shared<Node<T>>(data);
  if (length == 0) {
    head = tail = new_node;
    length++;
    return;
  }
  tail->next = new_node;
  tail = new_node;
  length++;
};
