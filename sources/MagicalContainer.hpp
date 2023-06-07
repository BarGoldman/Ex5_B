#ifndef MC
#define MC

#include <vector>

using namespace std;
namespace ariel
{
};

class MagicalContainer
{
private:
    vector<int> _element;
    vector<int *> _primeElement;

public:
    MagicalContainer(); // constructor

    void addElement(int num);

    int size() const;

    void removeElement(int num);

    ///////////////////////////////////////// AscendingIterator ////////////////////////

    class AscendingIterator
    {
    private:
        MagicalContainer &_container;
        int _position;

    public:
        AscendingIterator(MagicalContainer &container, int position = 0); // Default constructor
        AscendingIterator(const AscendingIterator &other);                // Copy constructor

        ~AscendingIterator(){} // Destructor

        // for tidy
        AscendingIterator(AscendingIterator &&other) = default; 
        AscendingIterator &operator=(AscendingIterator &&other) = delete;

        AscendingIterator &operator=(const AscendingIterator &other); // Assignment operator

        // Equality comparison (operator==)
        bool operator==(const AscendingIterator &other) const;

        // Inequality comparison (operator!=)
        bool operator!=(const AscendingIterator &other) const;
        bool operator>(const AscendingIterator &other) const;
        bool operator<(const AscendingIterator &other) const;

        // Dereference operator (operator*)
        int operator*() const;

        // Pre-increment operator (operator++)
        AscendingIterator &operator++();

        AscendingIterator begin();
        AscendingIterator end();
    };

    ///////////////////////////////////////// SideCrossIterator ////////////////////////

    class SideCrossIterator
    {
    private:
        MagicalContainer &_container;
        int _position;
        int _counter;

    public:
        SideCrossIterator(MagicalContainer &container, int position = 0 , int counter = 0); // Default constructor
        SideCrossIterator(const SideCrossIterator &other);                // Copy constructor

        ~SideCrossIterator() {} // Destructor
        // for tidy
        SideCrossIterator(SideCrossIterator &&other) = default;
        SideCrossIterator &operator=(SideCrossIterator &&other) = delete;

        SideCrossIterator &operator=(const SideCrossIterator &other); // Assignment operator

        // Equality comparison (operator==)
        bool operator==(const SideCrossIterator &other) const;

        // Inequality comparison (operator!=)
        bool operator!=(const SideCrossIterator &other) const;
        bool operator>(const SideCrossIterator &other) const;
        bool operator<(const SideCrossIterator &other) const;

        // Dereference operator (operator*)
        int operator*() const;

        // Pre-increment operator (operator++)
        SideCrossIterator &operator++();

        SideCrossIterator begin();
        SideCrossIterator end();
    };

    ///////////////////////////////////////// PrimeIterator ////////////////////////
    class PrimeIterator
    {
    private:
        MagicalContainer &_container;
        int _position;

    public:
        PrimeIterator(MagicalContainer &container , int position = 0); // Default constructor
        PrimeIterator(const PrimeIterator &other);  // Copy constructor

        ~PrimeIterator() {} // Destructor

        // for tidy
        PrimeIterator(PrimeIterator &&other) = default;
        PrimeIterator &operator=(PrimeIterator &&other) = delete;

        PrimeIterator &operator=(const PrimeIterator &other); // Assignment operator

        // Equality comparison (operator==)
        bool operator==(const PrimeIterator &other) const;

        // Inequality comparison (operator!=)
        bool operator!=(const PrimeIterator &other) const;
        bool operator>(const PrimeIterator &other) const;
        bool operator<(const PrimeIterator &other) const;

        // Dereference operator (operator*)
        int operator*() const;

        // Pre-increment operator (operator++)
        PrimeIterator &operator++();

        PrimeIterator begin();
        PrimeIterator end();
    };
};

#endif
