#include <iostream>
#include <chrono>
#include <thread>
#include "Queue.h"

using namespace ClassiCpp;
int main()
{
  ClassiCpp::Queue<int> q = Queue<int>(10);
  for (int i = 0; i < 5; i++)
  {
    q.enqueue(i);
  }

  std::cout << "Hello World!\n";

  for (int i = 0; i < 5; i++)
  {
    std::cout << q.dequeue();
  }

  std::chrono::milliseconds timespan(5000);
  std::this_thread::sleep_for(timespan);
}