# 6-30-26, CF Round 1107 (Div. 3) Contest Solutions (6/7 solved)

### 1. (A) [Divide and Conquer](https://codeforces.com/contest/2241/problem/A)
##### File: `a.cpp`
This problem was fairly straight forward. All you're looking for is if you can make $x$ equal to $y$ where you can perform any integer division on $x$. Essentially, we're looking if $x$ is a multiple of $y$, so we can just use a ternary operator with the conditional `x % y == 0`. 

### 2. (B) [Good times Good Times](https://codeforces.com/contest/2241/problem/B)
##### File: `b.cpp`
In this problem, we need to validate $y$ s.t. 
1. $y$ is good
2. $x \cdot y$ is good.
3. $2≤y≤10^9$

Instead of brute forcing and trying every possible $y$, we can create a smaller list of "good" candidates. 
```cpp
vector<long long> ys;
```
Then, for each input $x$, we can test the candidates until one works.
```cpp
bool good(long long n){
    // implementation not shown here
}
```
This helper function checks whether `n` has at most two distinct digits. For example:
``` text
8588 -> digits {8, 5} -> good
9447 -> digits {9, 4, 7} -> not good
3333 -> digits {3} -> good
```
To track which digits appeared in `good()`, we can use an array of length 10 to track the 10 digits:
```cpp
bool seen[10];
```
Then, we generate good numbers from 2 through 99, and then add ing the special good numbers, which includes:
```
10, 100, 1000, ...
9, 99, 999, ...
11, 111, 1111, ...
101, 1001, 10001, ...
```
through this code snippet:
```c++
for (int y = 2; y <= 99; y++) {
        if (good(y)) ys.push_back(y);
    }

    long long p = 1;
    long long rep = 0;

    for (int k = 1; k <= 9; k++) {
        p *= 10;
        rep = rep * 10 + 1;

        ys.push_back(p);
        ys.push_back(p - 1);
        ys.push_back(p + 1);
        if (rep >= 2) ys.push_back(rep);
    }
    // rest of the implementation, check b.cpp
}
```
then we sort and remove duplicates. 
**NOTE**: This is a *heuristic candidate solution*, not a guaranteed complete one, as it does not guarantee all good numbers up to $10^9$. 

### 3. (C) [RemovevomeR](https://codeforces.com/contest/2241/problem/C)
##### File: `c.cpp`
The key is to notice that answers can only come out as `1` or `2`, since we can repeatedly delete **one character** from any palindromic substring. A binary string has no palindromic substring of length at least 2 only if its one of these options:
```
0
1
10
01
```
The key observation is to understand the connection bewteen the answer and the number of **transitions** - A.K.A. the number of shifts from a `0` to a `1` or vice versa within the binary string. With transitions, we can treat homogenous substrings with the same number as "blocks". 

If there is one transition (suppose the string is like `000111` or `111000`), then we will always end up with `01` or `10`. So, the answer is `2`.

However, if there at least two transitions (eg. `110011` or `101100`), in which we have more than 2 blocks, we will inevitably create new palindromes across block boundaries (eg. `110011` within `110011`, `101` within `101100`), which allow deletions to continue until only 1 character remains. 
So, all we have to do is do one pass through the string to check for the number of transitions, and then use a simple conditional to check whether the answer will be `2` or `1`.

### 4. (D) [An Alternative Way](https://codeforces.com/contest/2241/problem/D)
**File:** `d.cpp`

The main idea is to transform the operation so that the alternating `+1, -1, +1, -1, ...` pattern becomes a normal range add.

For each index, define:

$$
\text{need}_i = b_i - a_i
$$

This tells us how much each position needs to change. However, the operation alternates signs depending on parity, so we flip the sign on odd indices:

```cpp
need[i] = b[i] - a[i];
if (i % 2 == 1) need[i] *= -1;
```

After this transformation, one operation on a range becomes:
- Add `+1` to the transformed range if it starts at an even index.
- Add `-1` to the transformed range if it starts at an odd index.

So now the problem becomes: can we build the `need` array using range additions where positive ranges can only start at even indices and negative ranges can only start at odd indices?

We track two values:

```cpp
long long pos = 0, neg = 0;
```

where:
- `pos` = currently active positive range effects
- `neg` = currently active negative range effects

At any index, the current transformed value is basically:

$$
\text{pos} - \text{neg}
$$

For even indices, we are allowed to start new positive ranges, but not new negative ranges. So if `need[i]` is too negative and we do not already have enough active negative ranges, the answer is impossible.

```cpp
if (i % 2 == 0) {
    long long requiredNeg = max(0LL, -need[i]);

    if (neg < requiredNeg) {
        good = false;
        break;
    }

    pos = neg + need[i];
}
```

For odd indices, the opposite happens. We are allowed to start new negative ranges, but not new positive ranges. So if `need[i]` is too positive and we do not already have enough active positive ranges, the answer is impossible.

```cpp
else {
    long long requiredPos = max(0LL, need[i]);

    if (pos < requiredPos) {
        good = false;
        break;
    }

    neg = pos - need[i];
}
```

If we can pass through the whole array without contradiction, then it is possible to make `a` equal to `b`.

The key observation is that multiplying odd indices by `-1` turns the weird alternating operation into a normal signed range operation.

**Time complexity:** `O(n)` per test case.

***

### 5. [(E) Fair and Square](https://codeforces.com/contest/2241/problem/E)
**File:** `e.cpp`

For a triplet `\{u,v,w\}`, we need:

$$
p(u,v) \cdot p(v,w) \cdot p(w,u)
$$

to be a perfect square.

At first, this looks like a path-product problem, but the main observation is that for any three vertices in a tree, their three paths form a Y-shape.

Every vertex on the branches appears exactly twice across the three paths, so those values automatically contribute a square. Only the center / meeting vertex of the three paths appears three times. Therefore, the whole product is a perfect square if and only if the center vertex has a square value.

So we only need to count triplets whose center vertex `x` satisfies:

$$
\text{isSquare}(a[x])
$$

To do this, we root the tree at node `1` and compute subtree sizes:

```cpp
function<void(int, int)> dfs = [&](int u, int p){
    parent[u] = p;
    sub[u] = 1;

    for (int v: g[u]){
        if (v == p) continue;
        dfs(v, u);
        sub[u] += sub[v];
    }
};
```

Now, for each possible center vertex `x`, imagine removing `x` from the tree. This splits the tree into several components.

For every neighbor `v` of `x`, the component size is:

```cpp
if (v == parent[x]) {
    sz = n - sub[x];
} else {
    sz = sub[v];
}
```

There are two types of good triplets centered at `x`.
- First, the triplet can include `x`. Then the other two vertices must come from two different components.
- Second, the triplet can exclude `x`. Then the three chosen vertices must come from three different components.

We count these using running sums:

```cpp
triples += pairs * sz;
pairs += sum * sz;
sum += sz;
```

Here:
- `sum` stores total size of previous components
- `pairs` stores ways to choose two vertices from two previous components
- `triples` stores ways to choose three vertices from three different components

Then for square-valued center `x`, we add:

```cpp
ans += pairs + triples;
```

because:
- `pairs` = triplets containing `x`
- `triples` = triplets not containing `x`

**Time complexity:** `O(n)` per test case, after DFS.

***

### 6. (F) [A Bit Odd](https://codeforces.com/contest/2241/problem/F)
**File:** `f.cpp`

In this game, a move consists of deleting a subsequence with an odd number of inversions.

In a binary string, an inversion can only be a pair:

$$
(1,0)
$$

because an inversion means a larger value appears before a smaller value.

The key observation is that leading zeroes and trailing ones are useless.
- Leading zeroes cannot form inversions with anything before them.
- Trailing ones cannot form inversions with anything after them.

So we trim them:

```cpp
while (l < n && s[l] == '0') l++;
while (r >= l && s[r] == '1') r--;
```

Now we only analyze the middle part of the string.

The losing position for Alice happens when every run / block in this middle section has even length.

For example:

```text
011001
```

After trimming the leading `0`, the middle is:

```text
1100
```

The runs are:
- `11`
- `00`

Both have even length, so Bob wins.

But if any run has odd length, Alice can force a win.

So we scan the remaining middle portion and compute the lengths of each run:

```cpp
int i = l;

while (i <= r){
    int j = i;

    while (j <= r && s[j] == s[i]){
        j++;
    }

    int len = j - i;

    if (len % 2 == 1){
        alice_win = true;
        break;
    }

    i = j;
}
```

If at least one run has odd length, print:

```cpp
Alice
```

Otherwise, print:

```cpp
Bob
```

The important pattern is:
- Trim leading `0`s
- Trim trailing `1`s
- Check run lengths in the remaining middle
- Odd-length run means Alice wins
- All even-length runs means Bob wins

**Time complexity:** `O(n)` per test case.