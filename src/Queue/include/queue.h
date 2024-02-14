#pragma once
#include <iostream>
#include <memory>
#include <string>
#define CAPACITY 10

template <typename T>
class Node {
 public:
  Node(T data) : value(data){};
  std::shared_ptr<Node<T>> next;
  T value;
};

template <typename T>
class Queue {
 public:
  Queue() = default;
  int length;
  std::shared_ptr<Node<T>> head, tail;
  T deque();
  void enqueue(T data);
  T peek();
};

template <typename T>
T Queue<T>::peek() {
  return T(head->value);
}

template <typename T>
T Queue<T>::deque() {
  if (head == nullptr) {
    throw std::range_error("empty queue");
  }
  T value = head->value;
  head = head->next;

  length--;
  return value;
};

template <typename T>
void Queue<T>::enqueue(T data) {
  auto new_node = std::make_shared<Node<T>>(data);
  if (head == nullptr) {
    head = tail = new_node;
    length++;
    return;
  }
  tail->next = new_node;
  tail = new_node;
  length++;
};
