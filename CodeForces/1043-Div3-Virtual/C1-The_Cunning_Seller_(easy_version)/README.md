# C1. The Cunning Seller (easy version)

time limit per test: 2 seconds\
memory limit per test: 256 megabytes

This is the easy version of the problem. The easy version differs from the hard one in that it requires determining the minimum cost with the least number of deals, while the hard version requires determining the minimum cost with a limited number of deals.

After the cunning seller sold three watermelons instead of one, he decided to increase his profit — namely, he bought even more watermelons. Now he can sell `3x` watermelons for `3^(x+1) + x ⋅ 3^(x−1)` coins, where `x` is a non-negative integer. Such a sale is called a _deal_.

A calculating buyer came to him, but he has critically little time. Because of this, he wants to buy exactly `n` watermelons, making the least possible number of deals.

The buyer is in a hurry and has therefore turned to you to determine the minimum number of coins he must pay the seller for `n` watermelons, considering that he will make the least possible number of deals.

## Input

The first line contains an integer `t` (1 ≤ `t` ≤ 104) — the number of test cases. The description of each test case follows.

In a single line of each test case, there is one integer `n` (1 ≤ `n` ≤ 109) — how many watermelons need to be bought.

## Output

For each test case, output a single integer — the minimum cost of the watermelons.

### Example

#### Input

```txt
7
1
3
8
2
10
20
260010000
```

#### Output

```txt
3
10
26
6
36
72
2250964728
```

## Note

Note that there is no point in buying more watermelons than needed, so we won't consider deals where there are more watermelons than necessary.

Let's consider the costs of the first two deal options:

Deal A: `1` watermelon — `3` coins.

Deal B: `3` watermelons — `10` coins.

In the first sample, the only way to buy `1` watermelon is to use Deal A, so the answer is `3`.

In the second sample, you can buy `3` watermelons with a single Deal B for `10` coins.

In the third sample, you can make `2` Deals A and `2` Deals B, which will cost a total of `26` coins. If we make `3` deals, we can get `3`, `5`, `7`, or `9` watermelons. If we make fewer than `3` deals, we will get no more than `6` watermelons, which means it is impossible to buy `8` watermelons for less than `4` deals.
