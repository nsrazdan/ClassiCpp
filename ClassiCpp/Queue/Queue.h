#ifndef CLASSICPP_QUEUE_H
#define CLASSICPP_QUEUE_H

#include <stdexcept>
#include <string>
#include <algorithm>

#pragma once
namespace ClassiCpp
{

  template<typename T>
  class Queue
  {
    
  private:
    size_t capacity;
    size_t length;
    T* arr;

  public:
    // Create empty Queue of given capacity
    Queue(size_t capacity)
    {
      this->capacity = capacity;
      this->length = 0;
      this->arr = new T[capacity];
    }

    // Free all memory
    ~Queue()
    {
      delete(this->arr);
    }

    // Return the top item of the queue
    T pop()
    {
      this->checkItemValid(0);
      return(arr[0]);
    }

    // Remove and return the top item of the queue
    T dequeue()
    {
      this->checkItemValid(0);

      T temp = this->pop();
      this->remove(0);
      return(temp);
    }

    // Add item to back of queue
    void enqueue(T item)
    {
      if (this->capacity >= this->length)
      {
        throw std::invalid_argument("Not enough space in queue.");
      }

      arr[length] = item;
      this->length++;
    }

    // Resize queue to given size
    void resize(size_t newCapacity)
    {
      T* newArr = new T[newCapacity];
      size_t upperBound = std::min(newCapacity, this->length);
      
      for (int i = 0; i < upperBound; i++)
      {
        newArr[i] = this->arr[i];
      }

      delete(this->arr);
      this->arr = newArr;
      this->capacity = newCapacity;
    }

    // Resize queue to be double size
    void resizeDouble()
    {
      this->resize(this->capacity * 2);
    }

    // Resize queue to be quarter size
    void resizeQuarter()
    {
      this->resize(this->capacity / 4);
    }


    // Insert item of queue at index
    void insert(T item, int index)
    {

    }

    // Remove item of queue at index
    void remove(int index)
    {
      this->checkItemValid(index);

      int end = this->length - index - 1;
      for (int i = 0; i < end; i++)
      {
        this->arr[index + i] = this->arr[index + i + 1];
      }
      this->arr[index + end] = NULL;
      this->length--;
    }

    // Print out queue and info
    void print()
    {
      std::cout << "----------PRINTING QUEUE----------" << std::endl;
      std::cout << "Capacity: " << std::to_string(this->capacity) << std::endl;
      std::cout << "Length: " << std::to_string(this->length) << std::endl;
      
      std::cout << "Queue: [";
      for (int i = 0; i < this->capacity; i++)
      {
        if (i < this->length)
        {
          std::cout << this->arr[i];
        }
        else
        {
          std::cout << "NULL";
        }
        
        if (i != this->capacity - 1)
        {
          std::cout << " ,";
        }
      }
      std::cout << "]" << std::endl;
    }

    // check if the item at the index is valid
    // throw errors if not
    void checkItemValid(int index)
    {
      if (this->length > index)
      {
        throw std::out_of_range("Index " + std::to_string(index) + " is out of range. Length is " + std::to_string(this->length));
      }
    }
  };
}

#endif