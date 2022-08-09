# Interfaces for hash functions and hash tables

## Hash function

Hash functions map a (potentially) large set of keys to a smaller set of hash
values.
They provide a single function which returns the hash value to a given key in
constant time.

```cpp
template <class key_type, class value_type, size_type size>
value hash(key const&);
```

## Hash table

Hash tables use hash functions to search data elements within a large data
set.
They enable insertion and lookup in constant time.

```cpp
template <class key_type, class value_type, class hash_func, size_type size>
void insert(value_type const&);

template <class key_type, class value_type, class hash_func, size_type size>
value_type find(key_type const&);
```

