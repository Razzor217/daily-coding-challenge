# Merkle-Damgard transformation

The Merkle-Damgard transformation allows the construction of a hash function $h$
that maps messages of any length to a fixed-size hash, i.e.

$$h:\{0,1\}^*\to\{0,1\}^m$$

This is achieved by repeatedly compressing the concatenation of the previous
output $y_{i-1}$ and a message block $x_i$ using a compression function $f$:

$$f:\{0,1\}^{m+k}\to\{0,1\}^m,\quad y_i:=f(y_{i-1}||x_i)$$

where $y_0$ is a hash-specific initialization vector.

An [example](src/example.cpp) demonstrates how the hash function can be used
to hash messages of arbitrary length.
