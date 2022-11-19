#include "Queue.hpp"

template<typename T>
Queue<T>::Queue(int size) {// constructor
    queue = new T[size];

    queue_size = size;
    front_p = 0;
    rear_p = -1;
}

template<typename T>
Queue<T>::~Queue() {// destructor
    clear();
    delete[] queue;
}

template<typename T>
void Queue<T>::enqueue(T data) {// enqueue
    if (size() == queue_size) {
    cout << "Queue is full" << endl;
    }
    else if (rear_p == -1 || rear_p+1 == queue_size) {
        rear_p = 0;
        queue[rear_p] = data;
    }
    else {
        queue[++rear_p] = data;
    }
}

template<typename T>
void Queue<T>::dequeue() {// dequeue
    if (size()==0)
        std::cout << "Queue is empty" << std::endl;
    else {
        front_p++;
        if (front_p == queue_size)
            front_p = 0;
    }
}

template<typename T>
T Queue<T>::front() {// return front data
    if (isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return 0;
    }
    else
        return queue[front_p];
}

template<typename T>
bool Queue<T>::isEmpty() {// return 1 if empty
    return (size() == 0);
}

template<typename T>
bool Queue<T>::isFull() {// return 1 if full
    return (size() == queue_size);
}

template<typename T>
int Queue<T>::size() {// return size of the queue
    int queue_count = 0;
    if (rear_p == -1) {
        queue_count = 0;
    }
    else if (rear_p < front_p) {
        for (int i = front_p; i < queue_size; i++) {
            queue_count++;
        }
        for (int i = 0; i < rear_p + 1; i++) {
            queue_count++;
        }
    }
    else {
        for (int i = front_p; i < rear_p + 1; i++)
            queue_count++;
    }
    return queue_count;
}

template<typename T>
void Queue<T>::clear() {// clear the queue
    front_p = 0;
    rear_p = -1;
}

template<typename T>
void Queue<T>::printQueue() {// print all elements in the queue

    if (isEmpty()) {
        std::cout << "Queue is empty";
    }
    else if (rear_p < front_p) {
        for (int i = front_p; i < queue_size; i++) {
            std::cout << queue[i] << " ";
        }
        for (int i = 0; i < rear_p + 1; i++) {
            std::cout << queue[i] << " ";
        }
    }
    else {
        for (int i = front_p; i < rear_p + 1; i++)
            std::cout << queue[i] << " ";
    }
    std::cout << endl;
}