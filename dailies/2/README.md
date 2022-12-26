# Set of simple Hash Functions

Definition of a small set of simple hash functions which implement the
[previously defined interface](../1/README.md).

## Identity

Self-explanatory, $h(k)=k$.

## Division method

$h(k) = k \mod m$ where $m$ denotes the hash table's size.

## Multiplication method

$h(k) = \lfloor m (kA \mod 1) \rfloor$ where $m$ denotes the hash table's size
and $0<A<1$. In this implementation, constants $s$ and $w$ are chosen s.t.
$A=\frac{s}{w}$.

### Bit shifts

Multiplication method where $w=2^{32}$ and $m=2^M$.

### XOR correction

Bit shift method with XOR correction for the common mistake.
