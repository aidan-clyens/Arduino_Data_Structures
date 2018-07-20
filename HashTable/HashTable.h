/***********************************************************/
/*    Hash Table
/*
/*    A hash table that uses quadratic probing.
/*    To be used with Arduino, so this uses no C++ standard
/*    library functions.
/*
/*    Aidan Clyens
/*    July  18, 2018
/***********************************************************/
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "Arduino.h"

enum bin_state_t { UNOCCUPIED, OCCUPIED, ERASED };

template <typename Type>
class HashTable {
    public:
        HashTable( int = 5 );
        ~HashTable();

        //  Size
        int size() const;
        int capacity() const;
        bool empty() const;

        //  Element Access
        Type at( int ) const;
        bool member( Type const & ) const;

        //  Modifiers
        void insert( Type const & );
        bool erase( Type const &);
        void clear();

        //  Misc.
        double load_factor() const;
        void print();

    private:
        int hash( Type const & ) const;

        int power;
        int table_size;
        int erased_count;
        int array_capacity;
        Type *array;
        bin_state_t *occupied;
};

/***************************************
*           Constructors
****************************************/
/*
 * Default Hash Table Constructor
 */
template <typename Type>
HashTable<Type>::HashTable(int n):
power( n ),
table_size( 0 ),
erased_count( 0 ),
array_capacity( 1 << power ),
array( new Type[array_capacity] ),
occupied( new bin_state_t[array_capacity] )
{
    //  Initialize all bin of the hash table as UNOCCUPIED
    for (int i = 0; i < array_capacity; ++i) {
        occupied[i] = UNOCCUPIED;
    }
}

/*
 * Hash Table Destructor
 */
template <typename Type>
HashTable<Type>::~HashTable() {
    delete[] array;
    delete[] occupied;
}

/***************************************
*        Public Size Functions
****************************************/
/*
 * size
 */
template <typename Type>
int HashTable<Type>::size() const {
    return table_size;
}

/*
 * capacity
 */
template <typename Type>
int HashTable<Type>::capacity() const {
    return array_capacity;
}

/*
 * empty
 */
template <typename Type>
bool HashTable<Type>::empty() const {
    return (table_size == 0);
}

/***************************************
*    Public Element Access Functions
****************************************/
/*
 * at
 */
template <typename Type>
Type HashTable<Type>::at(int n) const {
    return array[n];
}

/*
 * member
 */
template <typename Type>
bool HashTable<Type>::member(Type const &obj) const {
    //  Create the hash value of the object to use as the starting index
    int index = hash(obj);

    for (int i = 0; i < array_capacity; ++i) {
        //  Use quadratic probing to search the hash table
        index = (index + i) % array_capacity;
        //  Return true if the object if found
        if (occupied[index] == OCCUPIED && array[index] == obj) {
            return true;
        }
    }

    return false;
}

/***************************************
*       Public Modifier Functions
****************************************/
/*
 * insert
 */
template <typename Type>
void HashTable<Type>::insert(Type const &obj) {
    //  Return if hash table is full
    if (table_size == array_capacity) return;
    //  Return if the object is already in the hash table
    if (member(obj)) return;
    //  Create the hash value of the object to use as the starting index
    int index = hash(obj);
    int i = 0;

    while (occupied[index] == OCCUPIED) {
        //  Use quadratic probing to search for an UNOCCUPIED or ERASED bin
        index = (index + i) % array_capacity;
        ++i;
    }
    //  Insert the object into the first empty bin and mark it as occupied
    array[index] = obj;
    occupied[index] = OCCUPIED;
    ++table_size;
}

/*
 * erase
 */
template <typename Type>
bool HashTable<Type>::erase(Type const &obj) {
    //  Create the hash value of the object to use as the starting index
    int index = hash(obj);

    //  Use quadratic probing to iterate through the hash table
    for (int i = 0; i < array_capacity; ++i) {
        index = (index + i) % array_capacity;
        //  If the current bin is OCCUPIED and equals the object, mark it as ERASED
        if (occupied[index] == OCCUPIED && array[index] == obj) {
            occupied[index] = ERASED;
            --table_size;
            ++erased_count;

            return true;
        }
    }

    return false;
}

/*
 * clear
 */
template <typename Type>
void HashTable<Type>::clear() {
    //  Iterate through the table and mark all bins as UNOCCUPIED
    for (int i = 0; i < array_capacity; ++i) {
        occupied[i] = UNOCCUPIED;
        table_size = 0;
        erased_count = 0;
    }
}

/***************************************
*            Misc. Functions
****************************************/
/*
 * load_factor
 */
template <typename Type>
double HashTable<Type>::load_factor() const {
    return (static_cast<double>(table_size) + static_cast<double>(erased_count)) / static_cast<double>(array_capacity);
}

/*
 * print
 */
template <typename Type>
void HashTable<Type>::print() {
    for (int i = 0; i < array_capacity; ++i) {
        if (occupied[i] == UNOCCUPIED) Serial.print("U");
        else if (occupied[i] == ERASED) Serial.print("E");
        else if (occupied[i] == OCCUPIED) Serial.print(array[i]);

        Serial.print(" ");
    }
    Serial.println();
}

/***************************************
*         Private Functions
****************************************/
/*
 * hash
 */
template <typename Type>
int HashTable<Type>::hash(Type const &obj) const {
    int n = static_cast<int>(obj);
    int hash = n % array_capacity;

    return (hash >= 0) ? hash : hash + array_capacity;
}

#endif
