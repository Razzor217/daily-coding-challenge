# Interface for graph objects

A graph is an ordered pair $G=(V,E)$, where $V$ is a set of vertices, and
$E$ is a set of edges, s.t.

$$\forall e\in E:\quad e=\{x,y\},\;x,y\in V,\;x\neq y$$

Hypergraphs generalize graphs, allowing edges with multiple endpoints.

```cpp
class edge
{
public:
    const_iterator begin() const;
    const_iterator end() const;
};
```

```cpp
class graph
{
public:
    size_type vertices() const;
    size_type edges() const;

    const_edge_iterator begin() const;
    const_edge_iterator end() const;
};
```

Currently, graphs in this library are designed to be read-only,
i.e. they are initialized with a set of edges and can be queried afterwards.
This library does not allow addition/deletion of vertices or edges
within a single graph instance.
