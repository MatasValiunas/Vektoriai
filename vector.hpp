#pragma once

#include <algorithm>
#include <limits>
#include <iostream>

using namespace std;

template <class T>
class Vector {
private:
    T * elem;
    unsigned int _size;
    unsigned int _capacity;

public:
// Konstruktoriai
    Vector();
    Vector(unsigned int size);
    Vector(unsigned int size, const T & initial);
    Vector(const Vector<T> & v);   

// Destruktorius
    ~Vector();

// Iteratoriai
    typedef T * iterator;
    iterator begin();
    iterator end(); 

// Dydziai
    unsigned int capacity() const;
    size_t max_size() const;
    unsigned int size() const;
    bool empty() const;
    void reserve(unsigned int capacity);   
    void resize(unsigned int size);
    void shrink_to_fit();

// Elementu pasiekimas
    T & operator[](unsigned int index);  
    T & at(int pos);
    T & front();
    T & back();

// Modifikatoriai
    void push_back(const T & value); 
    void pop_back(); 
    void clear();
    iterator insert(iterator ndx, const T& val);
    iterator erase(iterator ndx);
    iterator erase(iterator first, iterator last);
    void swap(Vector& vect);
    void swap(T& x, T& y);

// Operatoriai
    Vector<T> & operator=(const Vector<T> &);
    Vector<T> & operator=(Vector&&);
    bool operator==(const Vector<T>& vect) const;
    bool operator>=(const Vector<T>& vect) const;
    bool operator<=(const Vector<T>& vect) const;
    bool operator!=(const Vector<T>& vect) const;
    bool operator>(const Vector<T>& vect) const;
    bool operator<(const Vector<T>& vect) const;
};


// Konstruktoriai
template<class T>
Vector<T>::Vector(){
    _capacity = 0;
    _size = 0;
    elem = 0;
}

template<class T>
Vector<T>::Vector(const Vector<T> & v){
    _size = v._size;
    _capacity = v._capacity;
    elem = new T[_size];  
    for (unsigned int i = 0; i < _size; i++)
        elem[i] = v.elem[i];  
}

template<class T>
Vector<T>::Vector(unsigned int size){
    _capacity = size;
    _size = size;
    elem = new T[size];
}

template<class T>
Vector<T>::Vector(unsigned int size, const T & initial){
    _size = size;
    _capacity = size;
    elem = new T [size];
    for (unsigned int i = 0; i < size; i++)
        elem[i] = initial;
}


// Destruktorius
template<class T>
Vector<T>::~Vector(){
    delete[] elem;
}


// Iteratoriai
template<class T>
typename Vector<T>::iterator Vector<T>::begin(){
    return elem;
}

template<class T>
typename Vector<T>::iterator Vector<T>::end(){
    return elem + size();
}


// Dydziai
template<class T>
unsigned int Vector<T>::capacity()const{
    return _capacity;
}

template <class T>
size_t Vector<T>::max_size() const 
{
    return std::numeric_limits<size_t>::max();
}

template<class T>
unsigned int Vector<T>::size()const{
    return _size;
}

template <class T>
bool Vector<T>::empty() const{
    return (_size == 0);
}

template<class T>
void Vector<T>::reserve(unsigned int capacity){
    if(elem == 0){
        _size = 0;
        _capacity = 0;
    }    
    T * NewElem = new T [capacity];
    unsigned int l_Size = capacity < _size ? capacity : _size;

    for (unsigned int i = 0; i < l_Size; i++)
        NewElem[i] = elem[i];

    _capacity = capacity;
    delete[] elem;
    elem = NewElem;
}

template<class T>
void Vector<T>::resize(unsigned int size){
    reserve(size);
    _size = size;
}

template <class T>
void Vector<T>::shrink_to_fit() {
    T* temp = new T[_size];

    for (int i = 0; i < _size; i++)
        temp[i] = elem[i];

    delete[] elem;
    elem = temp;
    _capacity = _size;
}

// Elementu pasiekimas
template<class T>
T& Vector<T>::operator[](unsigned int index){
    return elem[index];
}  

template <class T>
T& Vector<T>::at(int pos){
    if (pos >= _size)
        cout << "The index is not in range.";
    return elem[pos];
}

template<class T>
T& Vector<T>::front(){
    return elem[0];
}

template<class T>
T& Vector<T>::back(){
    return elem[_size - 1];
}


// Modifikatoriai
template<class T>
void Vector<T>::push_back(const T & v){
    if (_size >= _capacity)
        reserve(_capacity +5);
    elem[_size++] = v;
}

template<class T>
void Vector<T>::pop_back(){
    _size--;
}

template <class T>
void Vector<T>::clear(){
    _capacity = 0;
    _size = 0;
    elem = 0;
}

template<class valueType>
typename Vector<valueType>::iterator Vector<valueType>::erase(iterator ndx) 
{
    int i = 0;
    auto it = (this).begin();
    for (it; it != ndx; it++, i++);
    for (auto it = ndx + 1; it != (this).end(); it++, i++)
        elem[i] = elem[i + 1];
    _size--;
    return ndx;
}

template<class valueType>
typename Vector<valueType>::iterator Vector<valueType>::erase(iterator first, iterator last) 
{
    int i = 0;
    int temp = 0;
    auto it = (this).begin();
    for (it; it != first; it++, i++);
    for (it = first; it != last; it++, temp++, i++);
    for (auto it = last; it != (this).end(); it++, i++)
        elem[i - temp] = elem[i];
    _size -= temp;
    return last;
}

template<class T>
void Vector<T>::swap(Vector& vect){
    swap(elem, vect.elem);
    swap(_size, vect._size);
    swap(_capacity, vect._capacity);
}

template <class T>
void Vector<T>::swap(T& x, T& y){
    T temp = x;
    x = y;
    y = temp;
}

template<class T>
typename Vector<T>::iterator Vector<T>::insert(iterator iter, const T& val){
    int i = 0;

    if (_capacity > _size) 
    {
        for (iterator it(elem + _size); it != iter; it--, i++)
            elem[_size - i] = elem[_size - i - 1];
        iter = val;
        _size++;
    }
    else 
    {
        T temp = new T [_size + 1];
        for (iterator it(elem); it != iter; it++, i++)
            temp[i] = elem[i];
        temp[i] = val;
        i++;

        for (iterator it(elem + i + 1); it != elem + _size + 2; it++, i++)
            temp[i] = elem[i - 1];
        delete[] elem;
        elem = temp;
        _size++;
        _capacity = _size;
    }
    return iter;
}

// Operatoriai
template <class T>
Vector<T>& Vector<T>::operator=(Vector&& vec){
    if (&vec == this)
        return *this;
    elem = vec.elem;
    elem = vec._size;
    _capacity = vec._capacity;
    vec.elem = nullptr;
    vec._size = 0;
    vec._capacity = 0;
    return *this;
}

template<class T>
Vector<T> & Vector<T>::operator=(const Vector<T> & v){
    delete[ ] elem;
    _size = v._size;
    _capacity = v._capacity;
    elem = new T [_size];
    for (unsigned int i = 0; i < _size; i++)
        elem[i] = v.elem[i];
    return *this;
}
template<class T>
bool Vector<T>::operator==(const Vector<T>& vect) const {
    if (_size == vect._size && _capacity == vect._capacity) 
    {
        for (int i = 0; i < _size; i++)
            if (elem[i] != vect.elem[i])
                return false;
        return true;
    }
    return false;
}

template<class T>
bool Vector<T>::operator>=(const Vector<T>& vect) const{
    if (_size == vect._size && _capacity == vect._capacity)
    {
        for (int i = 0; i < _size; i++)
            if (elem[i] <= vect.elem[i])
                return false;
        return true;
    }
    else return (_size >= vect._size && _capacity >= vect._capacity);
}

template<class T>
bool Vector<T>::operator<=(const Vector<T>& vect) const{
    if (_size == vect._size && _capacity == vect._capacity)
    {
        for (int i = 0; i < _size; i++)
            if (elem[i] >= vect.elem[i])
                return false;
        return true;
    }
    else return (_size <= vect._size && _capacity <= vect._capacity);
}

template<class T>
bool Vector<T>::operator!=(const Vector<T>& vect) const{
    return !operator==(vect);
}

template<class T>
bool Vector<T>::operator>(const Vector<T>& vect) const{
    if (_size == vect._size && _capacity == vect._capacity)
    {
        for (int i = 0; i < _size; i++)
            if (elem[i] < vect.elem[i])
                return false;
        return true;
    }
    else return (_size > vect._size && _capacity > vect._capacity);
}

template<class T>
bool Vector<T>::operator<(const Vector<T>& vect) const{
    if (_size == vect._size && _capacity == vect._capacity)
    {
        for (int i = 0; i < _size; i++)
            if (elem[i] > vect.elem[i])
                return false;
        return true;
    }
    else return (_size < vect._size && _capacity < vect._capacity);
}