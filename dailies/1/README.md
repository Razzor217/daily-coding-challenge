# Interfaces for hash functions and hash tables

## Hash function

Hash functions map a (potentially) large set of keys to a smaller set of hash
values.
They provide a single function which returns the hash value to a given key in
constant time.

They are implemented as functors, specializing the following template:

```cpp
template <typename key_type, typename size_type>
struct hash
{
    virtual
    size_type
    operator()(key_type const&) const = 0;
};
```
Additional template parameters may be to the specialized table.



## Hash table

Hash tables use hash functions to search data elements within a large data
set.
They enable insertion and lookup in constant time.

They are implemented as specializations of the following template:

```cpp
template <typename key_type, typename T, typename hash_func>
struct table
{
    using value_type = std::pair<key_type, T>;

    virtual
    bool
    insert(value_type const&) = 0;

    virtual
    T&
    find(key_type const&) = 0;
};
```

Additional template parameters (e.g. for additional hash functions) may be added
to the specialized table.

