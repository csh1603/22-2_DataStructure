#include "PQueue.hpp"

PQueue::PQueue(int cap) {
	capacity = cap + 1;
	heap = new int[capacity]; // �Է¹��� ũ�⸸ŭ �迭�� ���� ����
	capacity--;
}

PQueue::~PQueue() {
	delete[] heap;
}

void PQueue::insert(int data) {
	size++;
	heap[size] = data;

	int num = size;

	//�����ؾߵ� max heap

	int child = size;
	while (child > 1) {
		int parent = (int)(child / 2);
		if (heap[parent] < heap[child]) {
			int temp = heap[parent];
			heap[parent] = heap[child];
			heap[child] = temp;
		}
		child = parent;
	}
}

void PQueue::removeData(int data) {
	int del = find(data);
	heap[del] = heap[size];
	heap[size] = NULL;
	size--;

	//�����ؾߵ� max heap
	int left = del * 2;
	int right = del * 2 + 1;
	while (left < size) {
		int num = (heap[left] > heap[right]) ? heap[left] : heap[right];
		int index = (num == heap[left]) ? left : right;
		if (num > heap[del]) {
			heap[index] = heap[del];
			heap[del] = num;
		}
		del = index;
		left = del * 2;
		right = del * 2 + 1;
	}
}

int PQueue::find(int data) {
	for (int i = 1; i < size + 1; i++) {
		if (heap[i] == data)
			return i - 1;
	}
}

void PQueue::display() {
	for (int i = 1; i < size + 1; i++) {
		cout << heap[i] << " ";
	}
	cout << endl;
}

void PQueue::heapSort() {
	//pop�ϰ� �����ϰ� pop �ݺ�
	int temp, s = size;
	while (s > 1) {
		int root = 1;
		temp = heap[s];
		heap[s] = heap[root];
		heap[root] = temp;
		s--;
		int left = 2;
		int right = 3;
		while (left < s) {
			int num = (heap[left] >= heap[right]) ? heap[left] : heap[right];
			int index = (num == heap[left]) ? left : right;
			if (num > heap[root]) {
				heap[index] = heap[root];
				heap[root] = num;
			}
			root = index;
			left = root * 2;
			right = root * 2 + 1;
		}
	}

}
