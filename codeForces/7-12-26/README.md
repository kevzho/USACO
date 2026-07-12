# Codeforces Round 1108 (Div. 2)

Solutions for the first three problems from the round.

## A — farmpiggie and Subset Sum

**Goal:** Construct a permutation `p` of an even length `n` such that no
choice of signs in

`±(1 · p1) ± (2 · p2) ± ... ± (n · pn)`

(where a term may also be omitted) can make the result equal to `1`.

### Approach

Output adjacent values in swapped pairs:

```text
2 1 4 3 6 5 ... n (n - 1)
```

At every 1-indexed position `i`, the product `i * p[i]` is even:

- if `i` is even, the product is automatically even;
- if `i` is odd, `p[i]` is the next even number.

Every chosen term is therefore even, so every possible final sum is even.
It can never be `1`, which is odd.

**Complexity:** `O(n)` time and `O(n)` space in this implementation (the
array could also be printed directly in `O(1)` extra space).

## B — ezraft and Array

**Goal:** Construct `n` distinct positive integers such that their total sum
is divisible by every element, or report that it is impossible.

### Approach

- `n = 1`: output `1`.
- `n = 2`: output `-1`.
- `n >= 3`: output

```text
1, 2, 3, 6, 12, 24, ...
```

Each value after the first two is the sum of all earlier values. For example,
after `[1, 2, 3]`, the current sum is `6`, so append `6`; the new sum becomes
`12`, so append `12`, and so on.

When a value `S` is appended, it is the old total sum. Thus the new total is
`2S`, which is divisible by the newly appended `S`. It remains divisible by
all earlier values because `S` was divisible by all of them. This proves the
invariant by induction. The numbers are also distinct because the total sum
strictly increases.

For `n = 2`, suppose distinct positive values are `x < y`. Since `y` must
divide `x + y`, it must divide `x`, which is impossible because `0 < x < y`.

**Complexity:** `O(n)` time and `O(n)` space. The largest produced value for
`n <= 50` fits in `long long` and is below the problem limit.

## C — 0mar and Alternating Sums

**Goal:** Count subsequences with alternating sum zero in a non-decreasing
array consisting of `-1` values followed by positive values.

### Why a sum-DP TLEs

The original idea kept a hash map from every reachable alternating sum to its
number of ways. The number of distinct sums can be exponential in the number
of distinct values, so repeatedly rebuilding those maps is too slow.

### Key observation: even-length subsequences

For a selected non-decreasing sequence of even length,

```text
b1 - b2 + b3 - b4 + ... + b(k-1) - bk
```

each pair difference is non-positive. The total is zero exactly when every
pair contains equal values. Therefore, every equal-value group contributes an
even number of selected elements.

A group of size `m` has `2^(m - 1)` even-sized subsets. If the whole array has
`G` distinct-value groups, the number of even-length valid subsequences is:

```text
2^(n - G)
```

This includes the empty subsequence.

### Odd-length subsequences

Let `c` be the number of `-1` elements. A valid odd-length subsequence must
choose an odd number of `-1`s. Those contribute `-1` to the alternating sum.
The positive portion has even length and starts with a minus sign, so it must
contribute exactly `+1`:

```text
(x2 - x1) + (x4 - x3) + ... = 1
```

Every difference is a non-negative integer. Hence exactly one pair must be
`(v, v + 1)`, while all other pairs must contain equal values.

For each adjacent pair of positive value groups whose values differ by one:

- select an odd count from the two special groups;
- select an even count from every other positive group;
- select an odd count from the `-1` group.

Odd and even subsets of a group of size `m` both have count `2^(m - 1)`. Let:

- `P` = number of positive elements;
- `H` = number of distinct positive-value groups;
- `E` = number of adjacent positive groups with values differing by `1`.

The odd-length contribution is:

```text
E * 2^(P - H) * 2^(c - 1)
```

when `c > 0`; otherwise it is zero. Add this to the even-length contribution,
all modulo `1,000,000,007`.

**Complexity:** `O(n)` time per test case and `O(n)` space for the input array.
