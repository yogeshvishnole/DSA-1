/* 
Collision handling is a critical part of hash map implementations since different keys can generate the same bucket index (a phenomenon called a collision). Below are the common types of collision-handling techniques and a brief explanation of each:

1. Separate Chaining
How It Works:

Each bucket in the hash table stores a linked list (or another data structure, such as a dynamic array).
When a collision occurs, the new key-value pair is added to the linked list of the corresponding bucket.
During lookups, the hash table traverses the list to find the desired key.
Advantages:

Handles collisions efficiently, even if the number of keys exceeds the bucket count.
Easy to implement.
Allows the hash table to grow dynamically.
Disadvantages:

If many keys map to the same bucket, the linked list grows, causing the time complexity for search, insert, and delete to degrade to O(n) for that bucket.
Example:


Bucket 0: [ ] 
Bucket 1: [ (key1, value1), (key2, value2) ]
Bucket 2: [ (key3, value3) ]
2. Open Addressing
How It Works:

All elements are stored directly in the bucket array itself.
When a collision occurs, the hash table looks for the next available slot in the array using a probing strategy.
Common Probing Strategies:

Linear Probing:
Check the next bucket (index + 1) until an empty slot is found.
Example: If bucket i is full, check i+1, i+2, and so on.
Quadratic Probing:
Check buckets at quadratic intervals (e.g., i+1², i+2²).
Reduces clustering compared to linear probing.
Double Hashing:
Use a secondary hash function to calculate the probing sequence.
Formula: index = (hashCode + i * secondaryHash(key)) % bucketSize.
Advantages:

Eliminates the need for additional data structures like linked lists.
Reduces memory overhead.
Disadvantages:

Performance can degrade with high load factors, as probing can lead to long search times.
Deletion can be tricky since removing an element may disrupt the probing sequence.
Example with Linear Probing:


Initial Table: [ ] [ ] [ ] [ ] [ ] 
Insert key1 → hash to index 1: [ ] [(key1, value1)] [ ] [ ] [ ] 
Insert key2 → hash to index 1 (collision), probe to index 2: 
              [ ] [(key1, value1)] [(key2, value2)] [ ] [ ] 
3. Double Hashing
How It Works:

A form of open addressing, but instead of linear or quadratic probing, a second hash function is used to calculate the next position.
Formula: index = (hashCode + i * secondaryHash(key)) % bucketSize, where i is the probe count.
Advantages:

Reduces clustering more effectively than linear and quadratic probing.
Spreads the keys more uniformly across the bucket array.
Disadvantages:

Slightly more complex than linear probing.
Both hash functions must be carefully designed to avoid cycles.
Example:


Primary hash for key1 → index 3
Secondary hash for key1 → offset 2
Probing sequence: 3 → 5 → 7 → ...
4. Robin Hood Hashing
How It Works:

A form of open addressing where collisions are resolved by ensuring that keys with the "longest probe distance" are swapped with keys with a shorter probe distance.
Ensures that keys that are farthest from their ideal bucket are prioritized for placement.
Advantages:

Minimizes the variance in probe distances, leading to faster lookups on average.
Reduces clustering compared to standard open addressing.
Disadvantages:

Slightly more complex to implement.
Requires careful handling during insertion and deletion.
5. Cuckoo Hashing
How It Works:

Uses two (or more) hash tables with two (or more) independent hash functions.
When a collision occurs, the existing key is "kicked out" and reinserted into the other hash table using the second hash function. This process continues until all keys are placed or a rehash is triggered.
Advantages:

Provides guaranteed O(1) lookups for keys.
Eliminates long chains of collisions.
Disadvantages:

Complex to implement due to the "kicking out" mechanism.
May require rehashing if keys cannot be placed after a certain number of iterations.
6. Separate Dynamic Array (or Bucket Resizing)
How It Works:

Similar to separate chaining, but instead of linked lists, each bucket uses a dynamic array (e.g., std::vector in C++).
New elements are appended to the array, and the array resizes dynamically as needed.
Advantages:

Faster lookups compared to linked lists, especially for small numbers of elements.
Takes advantage of contiguous memory for better cache performance.
Disadvantages:

Memory overhead can increase if buckets grow large.
Requires resizing, which can be costly.
7. Hopscotch Hashing
How It Works:

Combines aspects of separate chaining and open addressing.
Each bucket maintains a small "hopscotch region" (a fixed-size array) to store nearby elements, reducing probe distances.
Advantages:

Very fast lookups due to reduced probe distances.
Good memory utilization.
Disadvantages:

Complex to implement.
Hopscotch regions must be carefully managed to avoid overflows.
Comparison of Techniques
Technique	Time Complexity	Memory Overhead	Ease of Implementation	Notes
Separate Chaining	Avg: O(1), Worst: O(n)	High (extra data structure)	Easy	Most common approach.
Open Addressing	Avg: O(1), Worst: O(n)	Low (uses bucket array)	Moderate	Avoids linked lists.
Double Hashing	Avg: O(1), Worst: O(n)	Low	Moderate	Reduces clustering.
Robin Hood Hashing	Avg: O(1)	Low	Complex	Balances probe distances.
Cuckoo Hashing	O(1) Guaranteed	Moderate	Complex	Very efficient for lookups.
Hopscotch Hashing	Avg: O(1)	Moderate	Complex	Optimizes for proximity.
Summary
The choice of collision-handling technique depends on factors like:
The number of elements relative to the bucket array size (load factor).
The importance of lookup speed vs. memory usage.
Ease of implementation.
Most Common Approach: Separate chaining is widely used due to its simplicity and scalability, but open addressing (with linear or quadratic probing) is popular in scenarios where memory is constrained.
 */