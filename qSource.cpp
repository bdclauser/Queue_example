#include <iostream>

using namespace std;

const int SIZE = 10;

template <typename T>
class miniQueue
{
private:
	T arr[SIZE];
	int front, back, count;
public:
	miniQueue() : front(0), back(0), count(0) {}
	void push(const T& item);
	void pop();
	T& first() const;
	void display() const;
};

template <typename T>
void miniQueue<T>::push(const T& item)
{
	if (count == SIZE)
		throw exception("full");
	arr[back] = item;
	count++;
	back = (back + 1) % SIZE;
}

template <typename T>
void miniQueue<T>::pop()
{
	if (count == 0)
		throw exception("empty");
	front = (front + 1) % SIZE;
	count--;
}

template <typename T>
T& miniQueue<T>::first() const
{
	return arr[front];
}

template <typename T>
void miniQueue<T>::display() const
{
	if (count == 0)
		throw exception("Empty");
	for (int i = front; i < front + count; i++)
		cout << arr[i % SIZE] << "\t";
	cout << endl;

}

void main()
{
	miniQueue<char> lettersQ;

	lettersQ.push('D');
	lettersQ.push('R');
	lettersQ.push('A');
	lettersQ.push('A');
	lettersQ.pop();
	lettersQ.push('I');
	lettersQ.push('W');
	lettersQ.push('K');
	lettersQ.push('H');
	lettersQ.push('L');
	lettersQ.push('O');
	lettersQ.push('P');
	lettersQ.pop();
	lettersQ.pop();
	lettersQ.push('B');
	lettersQ.push('C');

	lettersQ.display();
}