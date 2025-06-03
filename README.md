# DataStructures_HashTableDictionary
Implementation and benchmarking of Hash Table Dictionary (C++).

# Data Structures: Hash Table-Based Dictionary

This repository was created for the **Data Structures** course at Wrocław University of Science and Technology.  
It contains the implementation and analysis of various hash table-based dictionary structures.

## 📌 Goal

To implement and compare different variants of hash tables for a dictionary data structure, which maps integer keys to integer values.

## ⚙️ Implemented Variants

At least two or three variants of hash tables, such as:

- Hash table with separate chaining (buckets with lists)
- Open addressing (e.g., linear or quadratic probing)
- Hash table using AVL trees in buckets (for higher grades)

## 🔧 Supported Operations

- `insert(key, value)` – adds a key-value pair to the dictionary  
- `remove(key)` – deletes the pair associated with the given key

## 🧪 Benchmarking

- Performance of the `insert()` and `remove()` operations is measured
- Tests conducted for different input sizes
- Results saved as `.csv` files and used in the final analysis

## 🛠️ Technologies

- Language: **C++**
- No STL containers used
- All data structures implemented from scratch
