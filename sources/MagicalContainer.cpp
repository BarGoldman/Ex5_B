#include "MagicalContainer.hpp"

#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <iostream>

using namespace std;

bool isPrime(int num)
{
    if (num == 0 || num == 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}


MagicalContainer::MagicalContainer(){};
void MagicalContainer::addElement(int num)
{
    // To find the right location to add the number, I used the following website:
    // https://www.geeksforgeeks.org/upper_bound-in-cpp/

    // upper_bound - find the element in the range that is bigger then num
    // if he did not find some _element return the end place
    auto it = upper_bound(_element.begin(), _element.end(), num);
    _element.insert(it, num);

    // now we want to chack if is prime number:
    if (isPrime(num))
    {
        int *numPtr = new int(num);
        auto primeIt = std::upper_bound(_primeElement.begin(), _primeElement.end(), numPtr,
                                        [](const int *a, const int *b)
                                        { return *a < *b; });
        _primeElement.insert(primeIt, numPtr);
    }
}


int MagicalContainer::size() const
{
    return _element.size();
}

void MagicalContainer::removeElement(int num)
{
    if (_element.size() == 0)
    {
        throw std::runtime_error("you try remove from empty container");
    }
    auto it = find(_element.begin(), _element.end(), num);
    if (it != _element.end())
    {
        _element.erase(it);
    }
    else
    {
        throw std::runtime_error("the element thes not excist ");
    }
    if (isPrime(num))
    {
        auto it = std::find_if(_primeElement.begin(), _primeElement.end(),
                               [num](const int *ptr)
                               { return *ptr == num; });

        if (it != _primeElement.end())
        {
            delete *it;
            _primeElement.erase(it);
        }
    }
}

///////////////////////////////////////// AscendingIterator ////////////////////////

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container, int position) : _container(container), _position(position)
{
}
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : _container(other._container), _position(other._position)
{
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if((this) != &other){
        throw runtime_error("terators are pointing at different containers");
    }
    _container = other._container;
    _position = other._position;
    return *this;
}


// the position betwin other to this is the same:
// Equality comparison (operator==)
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    return (_position == other._position);
}

// the position betwin other to this is NOT the same:
// Inequality comparison (operator!=)
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return !(_position == other._position);
}

// the position betwin other to this is bigger/smaller:
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    return (_position > other._position);
}
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    return (_position < other._position);
}


//get the val
// Dereference operator (operator*)
int MagicalContainer::AscendingIterator::operator*() const
{
    return (_container._element[(size_t)_position]);
}

// Pre-increment operator (operator++)
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    if(_position >= _container.size()){
        throw runtime_error("you try to increment beyond the end");
    }
    _position = _position + 1;
    return (*this);
}


// the first position of the container
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return AscendingIterator(_container);
}


// the end position of the container:
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    return AscendingIterator(_container, _container.size());
}

///////////////////////////////////////// SideCrossIterator ////////////////////////

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container , int position , int counter) : _container(container) , _position(position) , _counter(counter) {}
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : _container(other._container), _position(other._position) , _counter(other._counter)
{
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if((this) != &other){
        throw runtime_error("terators are pointing at different containers");
    }
    _container = other._container;
    _position = other._position;
    _counter = other._counter;
    return *this;
}
// Equality comparison (operator==)
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    return (_position == other._position);
}
// Inequality comparison (operator!=)
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return !(_position == other._position);
}
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    return true;
}
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    return true;
}

// Dereference operator (operator*)
int MagicalContainer::SideCrossIterator::operator*() const
{
    return (_container._element[(size_t)_position]);
}

// Pre-increment operator (operator++)
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    if (_position >= _container._element.size())
    {
        throw runtime_error("you try to increment beyond the end");
    }
    // if _position is even
    if(_position % 2 == 0 ){
        _position = _position - _counter;
    }
    // if posotion is odd
    else{
        _position = (_container._element.size() - 1) - _counter;
        ++_counter;
    }
    return (*this);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    return SideCrossIterator(_container);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    return SideCrossIterator(_container,_container._element.size());
}

///////////////////////////////////////// PrimeIterator ////////////////////////

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container , int position) : _container(container) , _position(position) {
    
}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : _container(other._container), _position(other._position)
{
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other){
    if((this) != &other){
        throw runtime_error("terators are pointing at different containers");
    }
    _container = other._container;
    _position = other._position;
    return *this;
}

// Equality comparison (operator==)
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    cout<< "this position: " << _position << endl;
    cout<< "this position: " << other._position << endl;
    return (_position == other._position);
}
// Inequality comparison (operator!=)
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return !(_position == other._position);
}
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    return (_position > other._position);
}
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    return (_position < other._position);
}

// Dereference operator (operator*)
int MagicalContainer::PrimeIterator::operator*() const
{
    return *(_container._primeElement[(size_t)_position]);
}

// Pre-increment operator (operator++)
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    cout << "prime size: " << _container._primeElement.size() << endl;
    cout << "position: " << _position << endl;
    if(_position >= _container._primeElement.size()){
        throw runtime_error("you try to increment beyond the end");
    }
    _position = _position + 1;
    return (*this);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    return PrimeIterator(_container);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    return PrimeIterator(_container, _container._primeElement.size());
}
