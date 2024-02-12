#pragma once
#include <memory>

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
};

template <typename T>
T LinkedList<T>::get(int index) {
  auto node = this->head;

  if (index > this->length) {
    return T();
  }

  for (int i = 0; i < index; i++) {
    node = node->next;
  }

  return node->data;
};

template <typename T>
T LinkedList<T>::remove(T target) {
  auto node = this->head;
  std::shared_ptr<Node<T>> prev;

  while (node != nullptr) {
    if (node->data == target) {
      prev->next = node->next;
      T value = node->data;
      this->length--;
      return value;
    }
    prev = node;
    node = node->next;
  }

  throw std::invalid_argument("Value not found");
};

template <typename T>
T LinkedList<T>::removeAt(int index) {
  auto node = this->head;
  std::shared_ptr<Node<T>> prev;

  for (int i = 0; i < index; i++) {
    prev = node;
    node = node->next;
  }

  prev->next = node->next;
  T value = node->data;

  this->length--;
  return value;
};

template <typename T>
void LinkedList<T>::prepend(T data) {
  auto new_node = std::make_shared<Node<T>>(data);
  new_node->next = this->head;
  this->head = new_node;
  this->length++;
};

template <typename T>
void LinkedList<T>::append(T data) {
  auto new_node = std::make_shared<Node<T>>(data);
  if (this->length == 0) {
    this->head = this->tail = new_node;
    this->length++;
    return;
  }
  this->tail->next = new_node;
  this->tail = new_node;
  this->length++;
};
