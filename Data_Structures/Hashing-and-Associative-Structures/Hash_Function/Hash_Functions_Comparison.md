# Common Hash Functions in C++

This document summarizes the key hash functions used in hashing techniques, explains their differences, use-cases, and when to prefer each one.

---

## 1. Division Method

### Formula:
```cpp
index = key % table_size;
```

###  Pros:
- Very simple and fast.
- Works best when `table_size` is a **prime number**.

###  Cons:
- High collision risk if `table_size` is not chosen wisely.
- Performs poorly if keys share similar patterns.

###  Use When:
- You need simplicity and speed.
- Your keys are randomly distributed.
- You're using a prime number as the table size.

---

##  2. Multiplication Method

###  Formula:
```cpp
index = floor(table_size * fmod(key * A, 1));
```
Where `A` is a real number (commonly 0.6180339887).

### Pros:
- Better distribution than division.
- Works even when `table_size` is not prime.

### Cons:
- Requires floating-point math.
- Slightly slower than division.
- Choosing a good `A` value is important.

### Use When:
- You want better distribution.
- Keys may have regular patterns.

---

## 3. Mid-Square Method

### Steps:
1. Square the key.
2. Extract middle digits.
3. Take result modulo `table_size`.

### Pros:
- Spreads out values well when keys have patterns.
- Effective for fixed-length numeric keys.

### Cons:
- Requires squaring and digit manipulation.
- Not suitable for large or string-based keys.

### Use When:
- Keys are clustered or sequential (e.g., IDs).
- You want uniform distribution without prime table size.

---

## 4. Folding Method

### Steps:
1. Divide the key into equal-size parts.
2. Add the parts together.
3. Take modulo with `table_size`.

### Pros:
- Effective for long numbers (e.g., phone numbers).
- Simple and easy to implement.

### Cons:
- Still susceptible to collisions for similar parts.
- Only works well with numeric keys.

### Use When:
- Keys are long integers like phone numbers or IDs.
- You want a quick hash for large values.

---

## Summary Table

| Method            | Complexity | Collision Resistance | Ideal Use Case                                  |
|-------------------|------------|----------------------|--------------------------------------------------|
| Division          | Very Low   | Low (unless prime `m`) | Quick/simple numeric keys                        |
| Multiplication    | Low        | Medium               | More uniform hashing with minimal effort        |
| Mid-Square        | Medium     | Medium–High          | Clustered digits, IDs                            |
| Folding           | Medium     | Medium               | Large numeric keys like phone numbers            |

---

