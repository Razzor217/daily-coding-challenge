# Hashing metrics: Uniformity

[Pearson's chi-squared test](https://en.wikipedia.org/wiki/Pearson's_chi-squared_test#Calculating_the_test-statistic)
can be used to evaluate the uniformity of hash functions:

$$\chi^2=\sum_{j=0}^{m-1} \left(b_j-\frac{n}{m}\right)^2$$

where $b_j$ denotes the number of keys corresponding to the hash value $j$,
$n$ marks the number of keys and $m$ denotes the number of hash values.