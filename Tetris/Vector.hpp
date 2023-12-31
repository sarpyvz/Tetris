//#pragma once
//
//template<class T>
//class Vector {
//private:
//	T* vet;
//	int logic;
//	int Rsize;
//
//	bool full();
//	void change();
//public:
//	Vector();
//	~Vector();
//	bool empty();
//	void push_back(T val);
//	void pop_back();
//	int size();
//	T& operator[](int index);
//	T& operator=(const Vector<T>& obj);
//};
//
//template<class T>
//bool Vector<T>::full() {
//	return (this->logic == this->Rsize);
//}
//
//template<class T>
//void Vector<T>::change() {
//	int newSize = this->Rsize << 1;
//	newSize++;
//
//	T* aux = new T[newSize];
//
//	for (int i = 0; i < this->logic; i++) aux[i] = this->vet[i];
//
//
//	delete[] this->vet;
//
//	this->vet = aux;
//	this->Rsize = newSize;
//}
//
//template<class T>
//Vector<T>::Vector() {
//	this->vet = nullptr;
//	this->logic = 0;
//	this->Rsize = 0;
//}
//
//template<class T>
//Vector<T>::~Vector() {
//	delete[] this->vet;
//	this->logic = 0;
//	this->Rsize = 0;
//}
//
//template<class T>
//bool Vector<T>::empty() {
//	return (this->logic == 0);
//}
//
//template<class T>
//void Vector<T>::push_back(T val) {
//	if (this->full()) {
//		this->change();
//	}
//
//	this->vet[this->logic] = val;
//	this->logic++;
//}
//
//template<class T>
//void Vector<T>::pop_back() {
//	this->logic--;
//}
//
//template<class T>
//int Vector<T>::size() {
//	return (this->logic);
//}
//
//template<class T>
//T& Vector<T>::operator[](int index) {
//	return this->vet[index];
//}
//
//template <class T>
//T& Vector<T>::operator = (const Vector<T>& obj) {
//	Rsize = obj.Rsize;
//	data = new T[Rsize - 1];
//	for (int i = 0; i <= size; i++) {
//		data[i] = obj.
//	}
//}