/*****************************************
 * Instructions
 *  - Replace 'uwuserid' with your uWaterloo User ID
 *  - Select the current calendar term and enter the year
 *  - List students with whom you had discussions and who helped you
 *
 * uWaterloo User ID:  azclyens @uwaterloo.ca
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  (Winter) 2018
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *
 * The following is a list of uWaterloo User IDs of those students
 * I had discussions with in preparing this project:
 *    -
 *
 * The following is a list of uWaterloo User IDs of those students
 * who helped me with this project (describe their help; e.g., debugging):
 *    - zsnafzig
 *    - Used a test case written by him to help test my code.
 *****************************************/

#ifndef DOUBLE_HASH_TABLE_H
#define DOUBLE_HASH_TABLE_H

#ifndef nullptr
#define nullptr 0
#endif

#include "Exception.h"
#include "ece250.h"

enum bin_state_t { UNOCCUPIED, OCCUPIED, ERASED };

template <typename Type>
class Quadratic_hash_table {
	private:
		int count;
		int power;
		int array_size;
		int mask;
		int erased;
		Type *array;
		bin_state_t *occupied;

		int hash( Type const & ) const;

	public:
		Quadratic_hash_table( int = 5 );
		~Quadratic_hash_table();
		//	Accessors
		int size() const;
		int capacity() const;
		double load_factor() const;
		bool empty() const;
		bool member( Type const & ) const;
		Type bin( int ) const;

		void print() const;

		//	Mutators
		void insert( Type const & );
		bool erase( Type const & );
		void clear();

	// Friends

	template <typename T>
	friend std::ostream &operator<<( std::ostream &, Quadratic_hash_table<T> const & );
};

/*
 * Quadratic Hash Table Constructor
 */
template <typename Type>
Quadratic_hash_table<Type>::Quadratic_hash_table( int m ):
count( 0 ), power( m ),
erased( 0 ),
array_size( 1 << power ),
mask( array_size - 1 ),
array( new Type[array_size] ),
occupied( new bin_state_t[array_size] ) {

	for ( int i = 0; i < array_size; ++i ) {
		occupied[i] = UNOCCUPIED;
	}
}


/*
 * Quadratic Hash Table Destructor
 */
template <typename Type>
Quadratic_hash_table<Type>::~Quadratic_hash_table() {
	delete[] array;
	delete[] occupied;
}

/************************************************
*			Private Member Functions			*
************************************************/

/*
 * Generate a hash value for the argument objects
 */
template <typename Type>
int Quadratic_hash_table<Type>::hash(Type const &obj) const {
	int n = static_cast<int>(obj);
	int hash = n % capacity();
	//	Only return a non-negative hash value
	return (hash >= 0) ? hash : hash + capacity();
}

/************************************************
*			Public Member Functions				*
************************************************/

/*
 * Returns the size of the hash table
 */
template <typename Type>
int Quadratic_hash_table<Type>::size() const {
	return count;
}

/*
 * Returns the capacity of the hash table
 */
template <typename Type>
int Quadratic_hash_table<Type>::capacity() const {
	return array_size;
}

/*
 * Returns the load factor of the hash table, the ratio of occupied and erased bins over the total number of bins
 */
template <typename Type>
double Quadratic_hash_table<Type>::load_factor() const {
	return (static_cast<double>(count) + static_cast<double>(erased)) / static_cast<double>(array_size);
}

/*
 * Returns true if the hash table is empty, false otherwise
 */
template <typename Type>
bool Quadratic_hash_table<Type>::empty() const {
	return (count == 0);
}

/*
 * Returns true if obj is a member of the hash table, false otherwise
 */
template <typename Type>
bool Quadratic_hash_table<Type>::member(Type const &obj) const {
	int index = hash(obj);

	//	Iterate through the hash table using quadratic probing
	for (int i = 0; i < capacity(); ++i) {
		index = (index + i) % capacity();
		//	If the current bin is occupied and the value contained is equal to the argument, return true
		if (occupied[index] == OCCUPIED) {
			if (bin(index) == obj) return true;
		}
	}

	return false;
}

/*
 * Returns the entry in bin n
 */
template <typename Type>
Type Quadratic_hash_table<Type>::bin(int n) const {
	return array[n];
}

/*
 * A print function, used for testing
 */
template <typename Type>
void Quadratic_hash_table<Type>::print() const {
	//	Empty
}

/*
 * Insert the argument object into the hash table into the appropriate bin, using quadratic probing
 */
template <typename Type>
void Quadratic_hash_table<Type>::insert(Type const &obj) {
	//	Throw an overflow exception if the hash table is full
	if (size() == capacity()) {
		throw overflow();
	}

	//	Do nothing if the argument object is already in the hash table
	if (member(obj)) return;
	
	//	Set the initial bin
	int index = hash(obj);
	int i = 0;

	//	Iterate until an empty bin is found (either UNOCCUPIED or ERASED)
	while (occupied[index] == OCCUPIED) {
		index = (index + i) % capacity();
		++i;
	}

	array[index] = obj;
	occupied[index] = OCCUPIED;
	++count;
}

/*
 * Erase the argument object from the hash table, if it exists in the hash table
 */
template <typename Type>
bool Quadratic_hash_table<Type>::erase(Type const &obj) {

	int index = hash(obj);

	//	Iterate through the hash table using quadratic probing
	for (int i = 0; i < capacity(); ++i) {
		index = (index + i) % capacity();
		//	If the current bin is occupied and the value contained is equal to the argument, set it's occupied flag to ERASED
		if (occupied[index] == OCCUPIED) {
			if (bin(index) == obj) {
				occupied[index] = ERASED;
				--count;
				++erased;
				return true;
			}
		}
	}

	return false;
}

/*
 * Removes all elements from the hash table
 */
template <typename Type>
void Quadratic_hash_table<Type>::clear() {
	//	Set each object's occupied flag to UNOCCUPIED
	for (int i = 0; i < capacity(); ++i) {
		occupied[i] = UNOCCUPIED;
	}

	count = 0;
	erased = 0;
}

/*
 * Overrides the '<<' operator to print the hash table
 */
template <typename T>
std::ostream &operator<<( std::ostream &out, Quadratic_hash_table<T> const &hash ) {
	for ( int i = 0; i < hash.capacity(); ++i ) {
		if ( hash.occupied[i] == UNOCCUPIED ) {
			out << "- ";
		} else if ( hash.occupied[i] == ERASED ) {
			out << "x ";
		} else {
			out << hash.array[i] << ' ';
		}
	}

	return out;
}

#endif
