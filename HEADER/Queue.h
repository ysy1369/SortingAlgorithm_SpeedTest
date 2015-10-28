#include "Rectangle.h"

#ifndef __QUEUE_H__
#define __QUEUE_H__

template <class T>
class Queue
{
public:
   Queue(int queueCapacity); 
   // 처음 크기가 queueCapacity인 공백 큐를 생성
 
   bool IsEmpty() const;
   // 큐의 원소 수가 0이면 ture, 아니면 false 를 반환
 
 
   T& Front() const;
   // 큐의 맨 앞 원소 반환
   T& Rear() const;
   // 큐의 맨 뒤에 있는 원소 반환
 
   int getSize(){ return rear+1;}
   // 큐의 데이터 사이즈 반환

   void Push(const T& item);
   // 큐의 맨 뒤에 item 삽입
 
   void Pop();
   // 큐의 앞 원소를 삭제
 
   void Show() const ;
   // show the elements from the front to rear
 
   void Internal() const { cout<<"rear: "<<rear<<" front: "<<front<<" capacity: "<<capacity<<endl;}
   // show the front and rear value.
 
   ~Queue();
 
private:
   T *queue; // 큐 원소를 위한 배열
   int front; // 맨 처음 원소로부터 반시계 방향으로 한칸 뒤 위치
   int rear; // 마지막 원소의 위치
   int capacity; // 큐 배열의 크기
};

template <class T>
Queue<T>::Queue (int queueCapacity) : capacity(queueCapacity)
{
   if(capacity < 1) throw " Quene capacity must be > 0 ";
   queue = new T[capacity];
   front = rear = 0;
}
// Construct
 
template <class T>
Queue<T>::~Queue()
{
   delete[] queue;
}

template <class T>
inline bool Queue<T>::IsEmpty() const
{
   return (front == rear);
}
 
template <class T>
inline T& Queue<T>::Front() const
{
   if(IsEmpty()) throw " Queue is empty, No front element";
   return queue[(front + 1 ) % capacity];
 
}
 
template <class T>
inline T& Queue<T>::Rear() const
{
   if(IsEmpty()) throw "Queue is empty, No rear element";
   return queue[rear];
}
 
template <class T>
void Queue<T>::Push(const T &x)
{ // 큐의 리어에 x를 삽입
   if((rear + 1) % capacity == front)
   {
      T* newQueue = new T[2*capacity]; 
      // 두배 크기의 배열 할당
 
      int start = (front + 1) % capacity;
      if(start < 2) 
         // 둘러쌀 필요가 없음
         copy(queue + start, queue + start + capacity -1, newQueue);
      else
      {
         //둘러싸서 큐를 만듬
         copy(queue + start, queue + capacity, newQueue);
         copy(queue, queue + rear + 1, newQueue + capacity - start);
      }
 
   // newQueue로 전환
      front = 2*capacity -1;
      rear = capacity -2 ;
      capacity *=2;
      delete[] queue;
      queue = newQueue;
   }
 
   rear = (rear + 1) % capacity;
   queue[rear] = x;
}
 
template <class T>
void Queue<T>::Pop()
{
   // 큐로부터 원소 삭제
   if(IsEmpty()) throw "Queue is empty, Cannot delet";
   front = ( front + 1 ) % capacity;
   queue[front].~T(); // Destruct
}

#endif