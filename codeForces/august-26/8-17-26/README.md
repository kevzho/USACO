# Personal Solutions

---

## A — Creating Abbreviations (`a1.cpp`, `a2.cpp`)

**Statement.** Set `S` starts with `n` lowercase words. Each operation takes a sequence of
words from `S`, forms the abbreviation from their first letters, and adds it back to `S`.
Given the `n` words and `m` abbreviations, could all `m` have been produced in some order?

### Step 1 — only first letters matter

A word contributes exactly one thing: its initial. So collapse `S` to a set of ≤ 26
available letters. An abbreviation `a` is formable iff **every** character of `a` is
currently available.

### Step 2 — the letter set never grows

Here is the whole problem. To build `a = a₁a₂…a_k` you need a word starting with `a₁`,
so letter `a₁` was **already** available. Adding `a` to `S` contributes exactly `a₁` — a
letter that was already there.

The available-letter set is therefore **invariant**: fixed by the `n` initial words,
never changed by any operation.

### Consequences

- Order is irrelevant. The "does a suitable order exist" framing is a red herring.
- Answer is `YES` iff every character of every abbreviation is an initial of some
  original word.

```cpp
bool have[26] = {};
for each word w:      have[w[0] - 'a'] = true;
for each abbrev a:    for (char c : a) if (!have[c - 'A']) ok = false;
```

### About the two files

`a1.cpp` is the safe version written before noticing Step 2: it loops, creating any
formable abbreviation and adding its first letter, until no progress. Correct, and it's
what you'd write if you weren't sure the set was invariant. `a2.cpp` is the one-pass
version. `a1` provably terminates after one useful pass, so they always agree.

**Gotcha.** Keep reading the whole test case even after `ok` turns false — you must
consume all input before the next test case.

**Complexity.** O(total input length).

---

## B — Gigantomachy (`b.cpp`)

**Statement.** Two giants, non-increasing mountain ranges `a` and `b`, both starting on
mountain 1. Each turn: throw a boulder at the mountain the opponent stands on
(height −1); the opponent hops forward if the next mountain is now strictly higher;
a giant on height 0 with nothing ahead concedes. Bea goes first. Who wins?

### Step 1 — this is not a simulation

Heights reach 10⁹, so turn-by-turn simulation is ~10⁹ steps per test. Need a closed form.

### Step 2 — only the current mountain is ever hit

Since the range is non-increasing, the mountain ahead is never *initially* higher. A
giant hops only because his own mountain got chipped down. Mountains ahead keep their
original heights untouched. So each giant's whole existence reduces to one number: how
many boulders he absorbs.

### Step 3 — telescope

| stage | hits absorbed |
|---|---|
| on mountain `p`, until `a_{p+1} > h` | `a_p − a_{p+1} + 1` |
| … | … |
| on mountain `n`, ground to 0 | `a_n` |

He leaves mountain `p` at height `a_{p+1} − 1` (strictly-higher rule) and lands on the
next at its **full** height `a_{p+1}` — so each hop wastes exactly one extra boulder.
The `a_i` terms cancel in pairs; the `+1`s just get counted:

```
H_a = (a₁ − a_n) + (n − 1) + a_n = a₁ + n − 1
```

Every middle height is irrelevant.

### Step 4 — who runs out first

Ver concedes on turn `2·H_b`; Bea would concede on turn `2·H_a + 1`. So Bea wins iff
`H_b ≤ H_a`:

```
answer = 1  if  a₁ + n ≥ b₁ + m
         2  otherwise
```

**Ties go to Bea** — first-mover advantage. `>=`, not `>`. This is the single most
likely place to lose the problem.

**Complexity.** O(n + m), all of it reading input you then discard.

---

## C — Camera Placement on a Tree (`c.cpp`)

**Statement.** Rooted tree, root 1, `p_i < i`. The Beaver walks from the root to one of
`m` dam vertices. Cameras sit on edges; you observe which camera edges were traversed.
Minimum cameras to always identify the destination, and where.

### Step 1 — what you actually observe

The walk is the unique root→`a` path, downward only. The observation is exactly **the set
of camera edges on that path**. Two dams are confused iff those sets are equal.

### Step 2 — cameras become cuts

Delete every camera edge. Claim: two dams share a signature iff they land in the same
component. (Contract the *non*-camera edges: you get a tree whose nodes are the
components, and in a tree distinct nodes have distinct root-paths.) So:

> **Delete the fewest edges so no component holds two dams.**

### Step 3 — the answer is always `m − 1`

You need ≥ `m` components, so ≥ `m − 1` cuts. And `m − 1` always suffices, regardless of
tree shape: assign each vertex to the **deepest dam at-or-above it**. Each class is
connected (the path from that dam down to `v` contains no other dam) and holds one dam.
The leftover class — vertices with no dam above them, containing the root — holds zero
dams; absorb it into an adjacent dam's class (0 + 1 = 1, still connected). `m` parts.

Nothing in that argument referenced structure. The tree-ness is what does the work:
removing an edge always splits a component in exactly two, since no cycle can hold the
halves together. In a general graph this is minimum multiway cut — NP-hard, and often
far more than `m − 1` edges.

### Step 4 — which edges

The class assignment changes exactly when you step *into* a dam, so the boundary edges
are **the edges above dams**. That's `m` cuts if the root isn't a dam — one too many,
because the root's class wastes a component holding no dam. Skip one: let that dam share
the root's class and inherit the free **empty signature**.

The skipped dam must have no dam above it. Since `p_i < i`, every ancestor has a smaller
number, so the **smallest-numbered dam** qualifies automatically. And if the root is a
dam, it *is* the minimum — the two cases unify:

> **Camera on the edge above every dam except the lowest-numbered one.**

The parent array can be read and thrown away.

### Caveats

- **Multiple answers are valid.** The judge uses a special checker. Cutting *above* a dam
  (at an ancestor) instead of *at* it is equally correct, so diffing against the sample
  output produces spurious mismatches. Write a validator instead: walk up parent pointers,
  compute each dam's signature, assert all distinct and `k == m − 1`.
- **`p_i < i` is load-bearing** for the "smallest index" shortcut. With arbitrary parent
  order you'd need the actual shallowest dam, or a bottom-up sweep:
  `cnt[v] ∈ {0,1}`; for `i = n…2`, cut edge `i` if `cnt[i] == 1 && cnt[p_i] == 1`, else
  `cnt[p_i] += cnt[i]`. That version needs no DFS either — `p_i < i` means children have
  larger indices, so a reverse index loop is already a valid post-order.

**Complexity.** O(n) per test.

---

## D — Bermuda Rectangle (`d.cpp`)

**Statement.** A rectangle `[0,a] × [0,b]` with integer sides and `a·b = S`. For each
query `(x, y)`, how many unit cells of `[0,x] × [0,y]` lie inside *some* such rectangle?

### Step 1 — the coverage condition

Cell `(i,j)` is inside `[0,a] × [0,b]` iff `i ≤ a` and `j ≤ b`. So it's reachable iff some
divisor `a ≥ i` has cofactor `S/a ≥ j`. Since `S/a` shrinks as `a` grows, take the
*smallest* divisor `≥ i`:

```
f(i) = S / min{ d : d | S, d ≥ i }
```

Cell `(i,j)` is reachable iff `j ≤ f(i)`, so

```
answer(x, y) = Σ_{i=1..x} min(y, f(i))
```

### Step 2 — `f` is a step function over divisors

`x` reaches 10¹², so the sum can't be walked. But for `i ∈ [d_{k−1}+1, d_k]` the smallest
divisor `≥ i` is `d_k`, so `f ≡ v_k = S/d_k` on that whole block. A number below 10¹² has
at most **6720** divisors, so there are ≤ 6720 blocks. Prefix-sum them:

```
P[k] = Σ_{j≤k} (d_j − d_{j−1}) · v_j
```

### Step 3 — the clean query formula

Define `U(z) = Σ_{i≤z} f(i)` = the union area restricted to the first `z` columns:

```
U(z) = P[k−1] + (z − d_{k−1}) · v_k ,   k = blk(z)
```

`f` is decreasing, so the columns where the cap `y` binds form a **prefix**. Since
`v_k > y ⟺ d_k · y < S`, let `c = min(x, d_{T−1})` with `T` the first index where
`d_T ≥ ⌈S/y⌉`. Then:

```
answer = y·c + U(x) − U(c)
         ↑      ↑
      capped   uncapped staircase
      prefix
```

Columns `1…c` each contribute a full `y`; the rest contribute `f(i)` verbatim. No partial-
block arithmetic, no case split — and the fully-covered case falls out free, because
`d_{T−1} ≥ x` forces `c = x` and the formula collapses to `x·y`.

### The traps

- **Use `⌈S/y⌉`, never `d·y ≥ S`.** Equivalent predicates for positive integers, but
  `d·y` reaches 10²⁴ and overflows. The division doesn't.
- **The `d[0] = 0` sentinel is load-bearing.** It makes `U(z)` uniform inside the first
  block, and makes `c = 0` when nothing is capped, so no guard is needed. Note
  `vector<ll> d{0}` (one element, value 0) — `d(0)` would build an **empty** vector and
  every `d[k−1]` would read out of bounds.
- **The answer needs 64 bits.** It reaches ~`D·S ≈ 6.7·10¹⁵`. But `y·c` is safe: every
  `d_k ≤ c` satisfies `d_k·y < S`, so that product stays under 10¹².
- **`auto` on the lambdas is mandatory** — a lambda's type is compiler-generated and
  unnameable. `std::function` would work but adds indirection in a 3·10⁵-iteration loop.
- **`Σ√S ≤ 10⁶`** is the constraint telling you per-test divisor enumeration is intended.

**Complexity.** O(√S + D log D) setup per test, O(log D) per query.

**Hand check.** `S = 4` → `f = [4,2,1,1]`. Query `(4,4)` = `4+2+1+1 = 8`, matching the
rectangles `1×4`, `2×2`, `4×1` covering 4 cells, then 2 new, then 2 new.

---

## Cross-cutting notes

**Difficulty.** Rough estimates: A ≈ 800, B ≈ 900–1000, C ≈ 1300–1400, D ≈ 1700–1800.
On the USACO scale that's Bronze, Bronze, Silver, low Gold.

**Recurring pattern in three of the four.** Something that looks like it needs simulation
or search collapses to a closed form once you find the invariant:
- A — the available-letter set never changes
- B — only the current mountain is ever hit, so everything telescopes
- C — cut count equals component count minus one, and `m` components always suffice

**On fast I/O.** All four are fine with `cin`/`cout` plus
`ios_base::sync_with_stdio(false)` — that handles ~10⁷ integers/second, and the largest
input here is ~6·10⁵ tokens. Reach for hand-rolled `fread` only above roughly 5·10⁶
numbers; below that it's ~40 lines of off-by-one risk for no gain. Do keep `'\n'` over
`endl`, which flushes every line.