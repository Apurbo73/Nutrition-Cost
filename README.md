### Nutrition Cost

Certainly! Here's a detailed explanation of the program step-by-step:

---

### Problem Context (Inferred):

* You have `N` vitamin packets, each with a type `A[i]` and cost `B[i]`.
* You want to select some subset of **distinct vitamin types** to maximize the value:

  $$
  \text{value} = C \times k - \text{total_cost}
  $$

  where:

  * $k$ = number of distinct vitamin types chosen,
  * $\text{total_cost}$ = sum of the costs of those selected vitamin packets,
  * $C$ is a given constant.

The goal is to find the maximum possible value.

---

### Step 1: Read Number of Test Cases

```cpp
int T;
cin >> T;
while (T--) {
    // process each test case
}
```

* The program supports multiple test cases.
* For each test case, it reads inputs and calculates the answer.

---

### Step 2: Read Input for Each Test Case

```cpp
int N, C;
cin >> N >> C;
vector<int> A(N), B(N);
for (int i = 0; i < N; ++i) cin >> A[i];
for (int i = 0; i < N; ++i) cin >> B[i];
```

* `N`: number of vitamin packets.
* `C`: the constant multiplier used in the formula.
* Arrays `A` and `B`:

  * `A[i]`: vitamin type of the i-th packet.
  * `B[i]`: cost of the i-th packet.

---

### Step 3: Find Minimum Cost for Each Vitamin Type

```cpp
unordered_map<int, int> minCost;
for (int i = 0; i < N; ++i) {
    if (minCost.find(A[i]) == minCost.end() || B[i] < minCost[A[i]])
        minCost[A[i]] = B[i];
}
```

* We want to pick at most one packet per vitamin type (since distinct types).
* For each vitamin type `A[i]`, we store the **minimum cost** of any packet with that type.
* This map `minCost` holds the cheapest cost to obtain each vitamin type.

---

### Step 4: Collect All Minimum Costs and Sort Them

```cpp
vector<int> costs;
for (auto& [vitamin, cost] : minCost)
    costs.push_back(cost);

sort(costs.begin(), costs.end());
```

* Extract the minimum costs into a vector.
* Sort the vector in ascending order so we consider cheaper vitamins first.
* This will help us decide which subset of vitamins to pick to maximize value.

---

### Step 5: Calculate Maximum Value by Trying Increasing Number of Vitamins

```cpp
int Y = 0, maxVal = 0;
for (int i = 0; i < costs.size(); ++i) {
    Y += costs[i]; // sum of costs of first (i+1) cheapest vitamins
    int value = C * (i + 1) - Y;
    if (value > maxVal) maxVal = value;
}
```

* Initialize `Y` to hold the running sum of chosen costs.

* For every possible number of vitamins selected (`i+1`), calculate:

  $$
  \text{value} = C \times (i+1) - \text{sum_of_costs}
  $$

* Keep track of the maximum value encountered.

* This simulates choosing the cheapest 1 vitamin, then cheapest 2 vitamins, and so forth.

---

### Step 6: Output the Result

```cpp
cout << maxVal << endl;
```

* After checking all subsets, output the maximum value for the current test case.

---

### Summary:

* The program efficiently finds the cheapest way to get distinct vitamin types.
* Then it tries all possible counts of distinct vitamins chosen, computing the net value using the given formula.
* It outputs the maximum value achievable.

---

### Example:

Suppose:

* `N = 5, C = 10`

* Vitamin types `A = [1, 2, 1, 3, 2]`

* Costs `B = [3, 4, 2, 5, 1]`

* Minimum costs by vitamin type:

  * Type 1: min(3, 2) = 2
  * Type 2: min(4, 1) = 1
  * Type 3: 5

* Sorted costs: `[1, 2, 5]`

Check values:

* Pick 1 vitamin: `10 * 1 - 1 = 9`
* Pick 2 vitamins: `10 * 2 - (1 + 2) = 20 - 3 = 17`
* Pick 3 vitamins: `10 * 3 - (1 + 2 + 5) = 30 - 8 = 22` ← max

Output: `22`

---

If you'd like, I can help with an even more detailed walkthrough or optimization tips!
