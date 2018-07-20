/****************************************************
 *  Hash Table Example
 *
 *  Aidan Clyens
 *  July 18, 2018
 */
 #include <HashTable.h>

//  Create a hash table of type 'int' with a power of 4
//  The capacity of the hash table will be 2^4
HashTable<int> table(4);

void setup() {
    Serial.begin(9600);

    //  Insert new elements to the hash table
    table.insert(16);
    table.insert(18);
    table.insert(4);
    table.insert(6);
    table.insert(10);
    table.insert(2);
    table.insert(3);
    table.insert(-6);

    //  Erase elements from the hash table
    table.erase(16);
    table.erase(4);

    //  Get the size of the hash table
    Serial.print("size = ");
    Serial.println(table.size());

    //  Get the capacity of the hash table
    Serial.print("capacity = ");
    Serial.println(table.capacity());

    //  Determine if the hash table is empty or not
    Serial.print("empty: ");
    if (table.empty()) Serial.println("True");
    else Serial.println("False");

    //  Check if an element is a member of the hash table
    Serial.print("18 is in the table: ");
    if (table.member(18)) Serial.println("True");
    else Serial.println("False");

    Serial.print("12 is in the table: ");
    if (table.member(12)) Serial.println("True");
    else Serial.println("False");

    //  Access a specific bin of the hash table
    Serial.print("The contents of the bin at index 10 is: ");
    Serial.println(table.at(10));

    //  Get the load factor of the hash table
    Serial.print("The load factor of the hash table is: ");
    Serial.println(table.load_factor());

    //  Print the hash table to the serial monitor
    table.print();
}

void loop() {
    //  Empty
}
