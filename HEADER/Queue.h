#include "Rectangle.h"

#ifndef __QUEUE_H__
#define __QUEUE_H__

template <class T>
class Queue
{
public:
   Queue(int queueCapacity); 
   // ó�� ũ�Ⱑ queueCapacity�� ���� ť�� ����
 
   bool IsEmpty() const;
   // ť�� ���� ���� 0�̸� ture, �ƴϸ� false �� ��ȯ
 
 
   T& Front() const;
   // ť�� �� �� ���� ��ȯ
   T& Rear() const;
   // ť�� �� �ڿ� �ִ� ���� ��ȯ
 
   int getSize(){ return rear+1;}
   // ť�� ������ ������ ��ȯ

   void Push(const T& item);
   // ť�� �� �ڿ� item ����
 
   void Pop();
   // ť�� �� ���Ҹ� ����
 
   void Show() const ;
   // show the elements from the front to rear
 
   void Internal() const { cout<<"rear: "<<rear<<" front: "<<front<<" capacity: "<<capacity<<endl;}
   // show the front and rear value.
 
   ~Queue();
 
private:
   T *queue; // ť ���Ҹ� ���� �迭
   int front; // �� ó�� ���ҷκ��� �ݽð� �������� ��ĭ �� ��ġ
   int rear; // ������ ������ ��ġ
   int capacity; // ť �迭�� ũ��
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
{ // ť�� ��� x�� ����
   if((rear + 1) % capacity == front)
   {
      T* newQueue = new T[2*capacity]; 
      // �ι� ũ���� �迭 �Ҵ�
 
      int start = (front + 1) % capacity;
      if(start < 2) 
         // �ѷ��� �ʿ䰡 ����
         copy(queue + start, queue + start + capacity -1, newQueue);
      else
      {
         //�ѷ��μ� ť�� ����
         copy(queue + start, queue + capacity, newQueue);
         copy(queue, queue + rear + 1, newQueue + capacity - start);
      }
 
   // newQueue�� ��ȯ
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
   // ť�κ��� ���� ����
   if(IsEmpty()) throw "Queue is empty, Cannot delet";
   front = ( front + 1 ) % capacity;
   queue[front].~T(); // Destruct
}

#endif