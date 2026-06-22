*This project has been created as part of the 42 curriculum by jakoch and omatalla.*

# push_swap

## Disclaimer

This document is **not intended to be a tutorial or a definitive guide to solving push_swap**.

Its purpose is to document our project, our implementation choices, the lessons we learned, and the reasoning that led us to those decisions. We hope it helps other students, peers, recruiters, and curious readers better understand the problem and perhaps develop even better solutions than ours.

We do not claim that our approach is the best possible one. Push_swap is a fascinating problem precisely because there are many valid ways to solve it, each with different trade-offs. This README reflects our own journey through the project and follows the collaborative spirit of the 42 curriculum, where peer-to-peer learning, discussion, experimentation, and continuous improvement are central values.

---

# Description

**push_swap** is one of the most algorithmically focused projects in the 42 curriculum.

At first glance, the challenge appears simple:

> Sort a list of integers.

However, the project introduces a significant constraint:

You are only allowed to manipulate the numbers through a limited set of stack operations performed on two stacks, **A** and **B**.

The goal is not merely to sort the numbers correctly.

The goal is to sort them using **as few operations as possible**.

This transforms a seemingly straightforward sorting problem into an exercise in:

* Algorithm design
* Complexity analysis
* Data structures
* Performance optimization
* Trade-off evaluation
* Benchmarking and testing

The project also introduces an additional challenge:

Different inputs benefit from different algorithms.

A nearly sorted list behaves very differently from a completely random list, and both behave differently from a list that is almost perfectly reversed.

For this reason, our implementation includes multiple sorting strategies and an adaptive system capable of selecting the most appropriate algorithm according to the measured disorder of the input.

---

# What Should Someone Learn From This Project?

Even without a programming background, this project teaches an important lesson:

**The way a problem is solved matters just as much as solving it.**

Consider two people trying to organize a library.

Both eventually finish.

One uses a systematic strategy and reorganizes everything efficiently.

The other constantly moves books back and forth without a clear plan.

Both achieve the same result, but one required significantly less work.

Push_swap is essentially the same challenge.

The project teaches that:

* Correctness is important.
* Efficiency is important.
* Measuring efficiency is important.
* Different situations require different strategies.
* Understanding a problem deeply often leads to dramatically better results.

---

# Project Objectives

The primary objectives of push_swap are:

* Understand algorithmic complexity.
* Learn to evaluate performance.
* Compare different sorting strategies.
* Work with linked lists and stacks.
* Design adaptive algorithms.
* Handle parsing and validation robustly.
* Produce clean, maintainable C code.
* Analyze trade-offs between competing solutions.
* Develop benchmarking and testing methodologies.

---

# The Rules of the Game

We start with two stacks:

### Stack A

Contains all numbers.

### Stack B

Starts empty.

Example:

```text
A: 4 2 7 1 9
B:
```

The objective is to sort Stack A in ascending order.

Only the following operations are allowed:

| Operation | Description                  |
| --------- | ---------------------------- |
| sa        | Swap first two elements of A |
| sb        | Swap first two elements of B |
| ss        | sa and sb simultaneously     |
| pa        | Push from B to A             |
| pb        | Push from A to B             |
| ra        | Rotate A upwards             |
| rb        | Rotate B upwards             |
| rr        | ra and rb simultaneously     |
| rra       | Reverse rotate A             |
| rrb       | Reverse rotate B             |
| rrr       | rra and rrb simultaneously   |

Every operation counts.

The fewer operations required, the better the solution.

---

# Visualizing the Allowed Operations

One of the easiest ways to understand push_swap is to think of Stack A and Stack B as two vertical piles of numbers.

In the following examples, the **top of each stack is shown first**.

---

## Operation: `sa` (Swap A)

Swap the first two elements at the top of Stack A.

### Before

```text
Stack A

Top
 ↓
[3]
[1]
[2]
Bottom
```

### Execute

```text
sa
```

### After

```text
Stack A

Top
 ↓
[1]
[3]
[2]
Bottom
```

Only the first two elements are exchanged.

### In a Nutshell for Non-Programmers

Imagine looking at the top two cards of a deck and exchanging their positions.

```text
Before:          After:

[3]              [1]
[1]      --->    [3]
[2]              [2]
```

Only the first two cards are affected.

---

## Operation: `pb` (Push B)

Move the top element of Stack A to the top of Stack B.

### Before

```text
Stack A          Stack B

Top              Top
 ↓                ↓
[3]
[1]
[2]
Bottom           (empty)
```

### Execute

```text
pb
```

### After

```text
Stack A          Stack B

Top              Top
 ↓                ↓
[1]             [3]
[2]             Bottom
Bottom
```

The element is removed from A and becomes the new top of B.

### In a Nutshell for Non-Programmers

Take the top card from pile A and place it on top of pile B.

```text
Pile A           Pile B

[3]
[1]      --->    [3]
[2]
```

The card leaves the first pile and becomes the new top card of the second pile.

---

## Operation: `pa` (Push A)

Move the top element of Stack B back to Stack A.

### Before

```text
Stack A          Stack B

Top              Top
 ↓                ↓
[1]             [3]
[2]
Bottom          Bottom
```

### Execute

```text
pa
```

### After

```text
Stack A          Stack B

Top              Top
 ↓
[3]
[1]
[2]
Bottom          (empty)
```

### In a Nutshell for Non-Programmers

This is simply the reverse of `pb`.

Take the top card from pile B and place it back on top of pile A.

```text
Pile A           Pile B

[1]              [3]
[2]      --->

becomes

[3]
[1]
[2]
```

The card returns to the first pile.

---

## Operation: `ra` (Rotate A)

Move the first element to the bottom.

### Before

```text
Stack A

Top
 ↓
[1]
[2]
[3]
[4]
Bottom
```

### Execute

```text
ra
```

### After

```text
Stack A

Top
 ↓
[2]
[3]
[4]
[1]
Bottom
```

Everything shifts upward by one position.

### In a Nutshell for Non-Programmers

Take the first card and place it at the very bottom.

```text
Before:          After:

[1]              [2]
[2]              [3]
[3]      --->    [4]
[4]              [1]
```

Everyone moves up one position while the first card goes to the end.

---

## Operation: `rra` (Reverse Rotate A)

Move the last element to the top.

### Before

```text
Stack A

Top
 ↓
[1]
[2]
[3]
[4]
Bottom
```

### Execute

```text
rra
```

### After

```text
Stack A

Top
 ↓
[4]
[1]
[2]
[3]
Bottom
```

Everything shifts downward by one position.

### In a Nutshell for Non-Programmers

Take the last card and move it to the very top.

```text
Before:          After:

[1]              [4]
[2]              [1]
[3]      --->    [2]
[4]              [3]
```

Everyone moves down one position while the last card jumps to the front.

---

# Understanding Disorder Visually

The adaptive strategy begins by measuring the **disorder** of the input.

Disorder is based on the concept of **inversions**.

An inversion occurs whenever:

```text
A larger number appears before a smaller number.
```

### In a Nutshell for Non-Programmers

Imagine a line of people waiting from shortest to tallest.

A disorder (or inversion) happens whenever a taller person is standing before a shorter one.

Example:

```text
1 5 2 4 3
```

Visualizing the mistakes:

```text
1 5 2 4 3
  └─┘
   5 > 2

1 5 2 4 3
  └───┘
   5 > 4

1 5 2 4 3
  └─────┘
    5 > 3

1 5 2 4 3
      └─┘
       4 > 3
```

There are 4 inversions.

The more inversions a list contains, the more disordered it is.

```text
No inversions      → Disorder = 0.00
Some inversions    → Disorder ≈ 0.20 - 0.50
Many inversions    → Disorder close to 1.00
```

This gives the program a simple way to estimate how "messy" the input is before choosing a sorting strategy.

---

## Example 1: Perfectly Sorted

```text
1 2 3 4 5
```

Check all pairs:

```text
1 < 2 ✓
1 < 3 ✓
1 < 4 ✓
1 < 5 ✓

2 < 3 ✓
2 < 4 ✓
2 < 5 ✓

3 < 4 ✓
3 < 5 ✓

4 < 5 ✓
```

Mistakes:

```text
0
```

Disorder:

```text
0 / 10 = 0.00
```

Perfectly sorted.

---

## Example 2: Completely Reversed

```text
5 4 3 2 1
```

Check all pairs:

```text
5 > 4 ✗
5 > 3 ✗
5 > 2 ✗
5 > 1 ✗

4 > 3 ✗
4 > 2 ✗
4 > 1 ✗

3 > 2 ✗
3 > 1 ✗

2 > 1 ✗
```

Mistakes:

```text
10
```

Total pairs:

```text
10
```

Disorder:

```text
10 / 10 = 1.00
```

Maximum disorder.

---

## Example 3: Partially Sorted

```text
1 3 2 5 4
```

Inversions:

```text
3 > 2 ✗
5 > 4 ✗
```

Mistakes:

```text
2
```

Total pairs:

```text
10
```

Disorder:

```text
2 / 10 = 0.20
```

Only slightly disordered.

---

# How Our Adaptive Strategy Uses Disorder

```text
                Disorder
                    │
                    ▼

          ┌─────────────────┐
          │   < 0.20        │
          └─────────────────┘
                    │
                    ▼
              Simple Sort
                 O(n²)

          ┌─────────────────┐
          │ 0.20 - 0.50     │
          └─────────────────┘
                    │
                    ▼
              Medium Sort
                O(n√n)

          ┌─────────────────┐
          │   ≥ 0.50        │
          └─────────────────┘
                    │
                    ▼
              Complex Sort
               O(n log n)
```

## What Do These Disorder Ranges Look Like in Practice?

The disorder score is useful for the program, but humans usually understand examples more easily than percentages.

The following examples illustrate the kind of inputs that typically fall into each disorder range.

### Low Disorder (< 0.20)

These inputs are already close to being sorted.

```text
1 2 3 5 4 6 7 8
```

Only a small mistake exists:

```text
1 2 3 5 4 6 7 8
      └─┘
       5 > 4
```

Visual intuition:

```text
Almost sorted
│
├─ Most numbers already where they belong
├─ Few inversions
└─ Small corrections needed
```

Strategy selected:

```text
Simple Sort
O(n²)
```

Even though O(n²) sounds less efficient on paper, the input is already so close to being sorted that a simple strategy often performs very well.

---

### Medium Disorder (0.20 - 0.50)

These inputs contain a noticeable amount of disorder but still preserve some structure.

```text
1 6 3 8 2 7 4 5
```

Some inversions:

```text
1 6 3 8 2 7 4 5
  └─┘
   6 > 3

1 6 3 8 2 7 4 5
  └─────┘
     6 > 2

1 6 3 8 2 7 4 5
      └─────┘
         8 > 2

1 6 3 8 2 7 4 5
          └─┘
           7 > 4
```

Visual intuition:

```text
Partially mixed
│
├─ Some regions already ordered
├─ Some regions clearly misplaced
└─ Moderate number of inversions
```

Strategy selected:

```text
Medium Sort
O(n√n)
```

This is where chunk-based approaches often shine because the input is neither nearly sorted nor completely chaotic.

---

### High Disorder (≥ 0.50)

These inputs are highly disordered or nearly reversed.

```text
8 7 6 5 4 3 2 1
```

Inversions are everywhere:

```text
8 > 7
8 > 6
8 > 5
8 > 4
...

7 > 6
7 > 5
...

6 > 5
...
```

Visual intuition:

```text
Highly disordered
│
├─ Most numbers misplaced
├─ Large number of inversions
└─ Very little useful structure remains
```

Strategy selected:

```text
Complex Sort
O(n log n)
```

At this level of disorder, more sophisticated algorithms become increasingly valuable because the amount of work required grows rapidly as the input size increases.

---

### The Big Picture

```text
Already Sorted
      │
      ▼
1 2 3 4 5 6 7 8
Disorder = 0.00


Almost Sorted
      │
      ▼
1 2 3 5 4 6 7 8
Disorder < 0.20
      │
      ▼
Simple Sort


Partially Mixed
      │
      ▼
1 6 3 8 2 7 4 5
Disorder ≈ 0.20 - 0.50
      │
      ▼
Medium Sort


Highly Mixed / Reverse Order
      │
      ▼
8 7 6 5 4 3 2 1
Disorder ≥ 0.50
      │
      ▼
Complex Sort
```

One of the key lessons we learned during this project is that two inputs containing the same amount of numbers can require completely different strategies depending on how disordered they are. Measuring disorder before sorting allows the program to make a more informed decision and adapt its behavior to the characteristics of the input.

This decision tree is the heart of our implementation and reflects one of the most important lessons we learned during the project:

> The best algorithm depends not only on the size of the input, but also on how disordered that input is.

A list that is already almost sorted can often be solved efficiently with a simpler strategy, while highly disordered or nearly reversed inputs benefit from more advanced approaches.

Measuring disorder before performing any operations allows the program to adapt its behavior and choose a strategy that is more appropriate for the characteristics of the data.

---

# Understanding Algorithmic Complexity

One of the central ideas of this project is **Big-O complexity**.

Big-O describes how the amount of work grows as the input size grows.

### O(n²)

Work grows very quickly.

Example:

| Elements | Approximate Work |
| -------- | ---------------- |
| 10       | 100              |
| 100      | 10,000           |
| 500      | 250,000          |

---

### O(n√n)

Moderate growth.

Better than O(n²), worse than O(n log n).

---

### O(n log n)

Efficient scaling.

Example:

| Elements | Approximate Work |
| -------- | ---------------- |
| 100      | ~664             |
| 500      | ~4483            |
| 1000     | ~9965            |

This is why modern high-performance sorting algorithms typically target O(n log n).

---

# Understanding Disorder

The project introduces a metric called **disorder**.

Disorder measures how far a list is from being sorted.

The value ranges between:

```text
0.0 = perfectly sorted
1.0 = maximally disordered
```

The metric is calculated by counting inversions.

An inversion occurs whenever:

```text
larger value appears before smaller value
```

Example:

```text
1 2 3 4 5
```

Disorder:

```text
0.00
```

---

Example:

```text
5 4 3 2 1
```

Disorder:

```text
1.00
```

---

Example:

```text
1 3 2 5 4
```

Disorder:

```text
somewhere between 0 and 1
```

---

# Why Disorder Matters

One of the most important discoveries we made during the project was:

> Not all unsorted inputs are equally unsorted.

Two lists may contain the same number of elements yet require completely different approaches.

### Low Disorder (< 0.2)

Almost sorted.

Example:

```text
1 2 3 5 4 6 7 8
```

Only a few elements are misplaced.

Using a highly sophisticated algorithm here may actually perform worse than a simpler strategy.

---

### Medium Disorder (0.2 – 0.5)

Partially mixed.

Example:

```text
1 6 3 8 2 7 4 5
```

A chunk-based approach often performs well.

---

### High Disorder (> 0.5)

Highly random or near reverse order.

Example:

```text
8 7 6 5 4 3 2 1
```

Efficient large-scale algorithms become significantly more attractive.

---

# Our Sorting Strategies

The subject requires four strategies:

| Strategy | Complexity |
| -------- | ---------- |
| Simple   | O(n²)      |
| Medium   | O(n√n)     |
| Complex  | O(n log n) |
| Adaptive | Dynamic    |

---

# Strategy 1: Simple Sort

### Idea

Selection-style minimum extraction.

Algorithm:

```text
Find minimum
Bring minimum to top
Push to B
Repeat
Sort remaining tiny core
Push everything back
```

Visual overview:

```text
A -> Find Min -> pb
A -> Find Min -> pb
A -> Find Min -> pb

Sort remaining 3 values

pa
pa
pa
```

### Why We Chose It

Advantages:

* Easy to understand
* Reliable
* Excellent educational baseline
* Naturally O(n²)

Disadvantages:

* Scales poorly for large inputs

---

# Strategy 2: Medium Sort

### Idea

Chunk-Based Sorting

After ranking values:

```text
0 ... n-1
```

The input is divided into chunks.

Approximate chunk size:

```c
sqrt(n) * 3
```
Values belonging to the current chunk are pushed into Stack B.

After all chunks are processed:

```text
Bring max in B to top
pa
Bring next max
pa
...
```

### Selecting the Chunk Size

One of the most important design decisions in our chunk-based sorting strategy was determining the optimal chunk size.

A chunk that is too small tends to create excessive rotations and unnecessary stack movements. A chunk that is too large reduces the benefits of partitioning the data and makes the algorithm behave less efficiently. The goal is therefore to find a balance between these two extremes.

To better understand this trade-off, we performed a small sensitivity analysis using several chunk-size formulas:

```c
sqrt(n) * 2
```

```c
sqrt(n) * 3
```

```c
sqrt(n) * 4
```

```c
sqrt(n) * 5
```

where:

* `n` is the number of elements to sort.
* `sqrt(n)` grows more slowly than `n`, which helps keep the number of chunks manageable as the input size increases.

For each configuration, we tested the algorithm with inputs of different sizes and different levels of disorder, comparing the total number of operations generated by the program.

Conceptually, the trade-off can be visualized as:

```text
Smaller Chunks                     Larger Chunks
      │                                   │
      ▼                                   ▼

More precise partitioning         Less partitioning

More chunk transitions            Fewer chunk transitions

More rotations                    Larger groups to manage

Potentially more operations       Potentially more operations
```

After comparing the results, we found that:

```c
sqrt(n) * 3
```

provided the most consistent performance across small, medium, and large inputs.

```text
Chunk Size Tested        Overall Result

sqrt(n) * 2             Too many chunk transitions
sqrt(n) * 3             Best balance

sqrt(n) * 4             Chunks became too large
sqrt(n) * 5             for small number sizes
```

As a result, our final implementation uses:

```c
chunk_size = (int)sqrt(n) * 3;
```

This value is not mathematically optimal for every possible input, but in our testing it offered the best compromise between operation count, stability, and overall performance across a wide variety of input sizes and disorder levels.


### Why We Chose It

Chunk sorting provides a good middle ground.

Advantages:

* Better scaling than simple extraction
* Reasonable operation count
* Effective for medium disorder

Disadvantages:

* Requires tuning
* Performance depends on chunk size

---

# Strategy 3: Complex Sort

### Idea

Binary Radix Sort

This is our O(n log n) solution.

The algorithm operates on normalized ranks rather than raw values.

Example:

Original:

```text
42 100 -5 7
```

Ranks:

```text
2 3 0 1
```

After normalization:

For every bit position:

```text
bit = 0 -> pb
bit = 1 -> ra
```

Then:

```text
pa until B empty
```

Repeat for all bits.

### Why We Chose It

Advantages:

* Excellent scalability
* Consistent performance
* Predictable operation count
* Widely proven in push_swap

Disadvantages:

* Less intuitive
* Additional preprocessing required

---

# Strategy 4: Adaptive Strategy

The adaptive strategy is the default behavior.

Rather than always using the same algorithm, the program first measures disorder.

Then:

```text
Disorder < 0.20
        ↓
Simple

0.20 ≤ Disorder < 0.50
        ↓
Medium

Disorder ≥ 0.50
        ↓
Complex
```

This allows the program to match the algorithm to the characteristics of the input.

---

# Tiny Sort Optimization

All three algorithms include a shared optimization for very small inputs.

```text
2 numbers
3 numbers
4 numbers
5 numbers
```

For these cases we use a dedicated helper:

```c
tiny_sort()
```

Why?

Because complexity differences become largely irrelevant at extremely small sizes.

For tiny inputs, specialized solutions produce significantly fewer operations than running the full algorithmic machinery.

This optimization does not change the asymptotic complexity of the algorithms.

Instead, it improves practical performance while preserving the intended strategy for larger datasets.

---

# From Input To Output: Following the Journey Through the Program

One of the easiest ways to understand the project is to follow the life cycle of the data.

```text
User Input
    ↓
Parsing
    ↓
Validation
    ↓
Stack Construction
    ↓
Disorder Calculation
    ↓
Strategy Selection
    ↓
Sorting Algorithm
    ↓
Operation Output
    ↓
Benchmark Statistics
```

---

## Step 1: Parsing

The program accepts:

```bash
./push_swap 4 2 7 1
```

or:

```bash
./push_swap "4 2 7 1"
```

Both produce identical results.

Files:

```text
parse/input.c
parse/numbers.c
parse/flags.c
```

Responsibilities:

* Parse flags
* Parse numbers
* Split strings when needed

---

## Step 2: Validation

Files:

```text
parse/validation.c
utils/error_handle.c
```

Checks:

* Invalid syntax
* Empty inputs
* Duplicates
* Integer overflow
* Integer underflow

Examples:

```bash
./push_swap 1 2 2
```

```text
Error
```

---

## Step 3: Building the Stack

File:

```text
stack/stack_setup.c
```

The validated numbers become nodes in a doubly linked list.

```text
Top
 ↓
[4] ⇄ [2] ⇄ [7] ⇄ [1]
 ↑
Bottom
```

---

## Step 4: Measuring Disorder

File:

```text
bench/disorder.c
```

The program computes the inversion ratio.

This becomes the basis for adaptive decision making.

---

## Step 5: Choosing a Strategy

Files:

```text
bench/disorder.c
algo/choose_algo.c
```

Decision tree:

```text
Low Disorder
      ↓
   Simple

Medium Disorder
      ↓
   Medium

High Disorder
      ↓
   Complex
```

---

## Step 6: Sorting

Files:

```text
algo/simple.c
algo/medium.c
algo/complex.c
algo/tiny_sort.c
```

The selected algorithm generates a sequence of valid push_swap operations.

Example:

```text
pb
ra
pb
rra
pa
pa
```

These operations are printed to stdout.

---

## Step 7: Benchmarking

Optional:

```bash
./push_swap --bench 4 2 7 1
```

Outputs:

```text
Disorder
Strategy
Complexity
Total Operations
Operation Breakdown
```

This makes performance visible and measurable.

---

# Project Architecture

```text
src/
│
├── algo/
│   ├── choose_algo.c
│   ├── simple.c
│   ├── medium.c
│   ├── complex.c
│   └── tiny_sort.c
│
├── bench/
│   ├── disorder.c
│   └── output.c
│
├── ops/
│   ├── push.c
│   ├── swap.c
│   ├── rotate.c
│   └── reverse_rotate.c
│
├── parse/
│   ├── flags.c
│   ├── input.c
│   ├── numbers.c
│   └── validation.c
│
├── stack/
│   ├── stack_setup.c
│   ├── stack_utils.c
│   └── stack_free.c
│
└── utils/
    ├── algo_utils.c
    ├── helpers.c
    └── error_handle.c
```

---

# Data Structures

### Node

```c
typedef struct s_node
{
    int value;
    struct s_node *next;
    struct s_node *prev;
} t_node;
```

Represents a single number.

---

### Stack

```c
typedef struct s_stack
{
    int size;
    t_node *top;
    t_node *bottom;
} t_stack;
```

Represents Stack A or Stack B.

---

### Configuration

```c
typedef struct s_config
```

Stores:

* Strategy selection
* Disorder
* Benchmark counters
* Flags
* Statistics

---

# Performance Targets

The project benchmarks:

### 100 Numbers

| Result    | Operations |
| --------- | ---------- |
| Pass      | < 2000     |
| Good      | < 1500     |
| Excellent | < 700      |

---

### 500 Numbers

| Result    | Operations |
| --------- | ---------- |
| Pass      | < 12000    |
| Good      | < 8000     |
| Excellent | < 5500     |

---

# Lessons Learned

This project reinforced several important ideas:

### Correct Is Not Enough

A solution can be perfectly correct and still perform poorly.

---

### Measuring Matters

Without metrics, optimization becomes guesswork.

---

### Different Inputs Need Different Tools

Adaptive systems often outperform one-size-fits-all solutions.

---

### Complexity Is Practical

Big-O is not merely theoretical.

The difference becomes very visible when operation counts are measured.

---

### Simplicity Has Value

A straightforward algorithm can outperform a sophisticated one when the input is small or nearly sorted.

---

# Team Contributions

## Jason Koch

42 Berlin – jakoch

GitHub: https://github.com/jaay13

Email: [jakoch@student.42berlin.de](mailto:jakoch@student.42berlin.de)

Jason acted as the team lead and was primarily responsible for the implementation strategy and the overall coding process.

His stronger prior programming experience was particularly valuable when translating ideas into practical C implementations based on linked lists, nodes, stack manipulation, and algorithm design.

---

## Oscar Matallana

42 Berlin – omatalla

GitHub: https://github.com/oscarmatallana

Email: [omatalla@student.42berlin.de](mailto:omatalla@student.42berlin.de)

Oscar was primarily responsible for research, code review, quality assurance, documentation, testing, benchmarking, and conceptual analysis.

His focus was on ensuring a deep understanding of the problem, evaluating algorithmic trade-offs, validating implementation decisions, and documenting both the project and its learning outcomes.

---

# Peer Acknowledgements

We would like to thank our peers:

* Matthias Sars
* Emre Kirgin

for several valuable discussions regarding:

* Algorithm selection
* Complexity analysis
* Disorder measurement
* Performance benchmarking
* Trade-offs between sorting strategies

These conversations significantly hProcess: push_swap
0 leaks for 0 total leaked bytes.elped us refine our understanding of how different algorithms behave under different input sizes and disorder ranges.

---

# Instructions

## Compilation

Clone the repository:

```bash
git clone https://github.com/jaay13/42-push_swap.git
cd 42-push_swap
```

Compile:

```bash
make
```

Clean objects:

```bash
make clean
```

Remove all generated files:

```bash
make fclean
```

Rebuild:

```bash
make re
```

---

## Usage

Adaptive mode (default):

```bash
./push_swap 4 67 3 87 23
```

```bash
./push_swap --adaptive 4 67 3 87 23
```

Force simple strategy:

```bash
./push_swap --simple 4 67 3 87 23
```

Force medium strategy:

```bash
./push_swap --medium 4 67 3 87 23
```

Force complex strategy:

```bash
./push_swap --complex 4 67 3 87 23
```

Benchmark mode:

```bash
./push_swap --bench 4 67 3 87 23
```

---

# Testing

We tested the project with:

### Manual Tests

* Sorted inputs
* Reverse sorted inputs
* Random inputs
* Duplicate values
* Invalid values
* Overflow values
* Single argument strings
* Multiple argument formats

### Benchmark Tests

* 100 random numbers
* 500 random numbers
* Low disorder inputs
* Medium disorder inputs
* High disorder inputs

### Validation Tests

* Error handling
* Memory management
* Leak checking
* Edge cases

---

# Bonus Part: Checker

As part of the bonus section, we implemented our own **checker** program.

The checker receives a list of integers, reads a sequence of Push_swap operations from standard input, executes those operations on the stacks, and verifies whether the final result is valid.

If Stack A is sorted in ascending order and Stack B is empty after executing all operations, the program prints:

```text
OK
```

Otherwise, it prints:

```text
KO
```

The checker also validates the input and operation stream, detecting invalid instructions, duplicate values, integer overflows, and other parsing errors.

Implementing the checker provided a valuable way to test and validate our sorting algorithms during development. It also reinforced our understanding of the Push_swap operation set by requiring us to execute and verify every operation exactly as defined by the subject.

In many ways, the checker became our most important debugging and validation tool, allowing us to confirm not only that our algorithms produced a sequence of operations, but that those operations actually sorted the input correctly.

---

## Compilation

Build:

```bash
make bonus
```

---

## Usage

### Checker only:

```bash
./checker 4 67 3 87 23
```

Once you run the checker, it will wait for you to list the operations you want to test to sort the given argument list (in this usage example, the argument list is "4 67 3 87 23", so you now need to input the operations to sort it, such as pa, sa and so on). Once you are ready listing your sorting operations, let the checker test them by pressing:

```text
CTRL + D
```

### Checker and push_swap:

Make sure you run, both:

```bash
make && make bonus
```

And then run the following command:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG 
```
To let the checker test the output of our push_swap program.

---

# Resources

## Books

**The C Programming Language**
Brian Kernighan & Dennis Ritchie

**C Programming For Dummies**
Dan Gookin

**Grokking Algorithms: An Illustrated Guide for Programmers and Other Curious People**
Aditya Y. Bhargava

---

## Previous Projects

* Libft
* ft_printf
* get_next_line

These projects provided much of the foundation required for push_swap, particularly regarding:

* Memory management
* Linked lists
* Parsing
* String manipulation
* Debugging

---

## Internal References

* Oscar's documentation from previous projects
* Personal benchmarking notes
* Peer discussions and evaluations

---

# AI Usage

AI tools were used as supplementary educational resources throughout the project.

Typical uses included:

* Exploring algorithmic complexity
* Discussing disorder metrics
* Reviewing trade-offs between sorting approaches
* Understanding radix sorting
* Understanding chunk-based sorting
* Reviewing linked-list manipulation logic
* Brainstorming benchmarking methodologies
* Reviewing documentation quality
* Generating alternative explanations for technical concepts

All implementation decisions, coding, debugging, testing, benchmarking, and validation were performed by the project authors.

Every AI-generated explanation or suggestion was critically reviewed, discussed, tested, and validated before being considered for use.

---

# Final Reflection

If we had to summarize the main lesson of push_swap in a single sentence, it would be:

> Sorting is easy. Sorting efficiently under constraints is where computer science becomes interesting.

Push_swap is ultimately a project about understanding that constraints change everything. Once operations become limited and measurable, algorithmic thinking becomes indispensable. The project challenged us to think not only about whether a solution works, but about why it works, when it works best, and how much it costs to get there.

That mindset extends far beyond sorting numbers and is one of the most valuable lessons we take away from this project.
