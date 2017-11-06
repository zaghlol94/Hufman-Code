#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

template<class T> class Q {
    int array_size, heap_size;
    T** A;   

public:
    Q(int s);
    ~Q();
    bool isEmpty();
    bool isFull();
    T** getArray();
    int getArraySize();
    T* minimum();
    T* extractMin();
    bool insert(T*);

private:
    int left(int i);
    int right(int i);
    int parent(int i);
    void decreaseKey(int, T*);
    void minHeapify(int);
};

#endif 
