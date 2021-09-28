# Greedy

Greedy is most common used ( first-come-up naive ) algorithm to solve contest problem

There are four main steps for a greedy stays ahead proof.


Step 1: Define your solutions. Describe the form your greedy solution takes, and what form some
other solution takes (possibly the optimal solution). For example, let A be the solution constructed by the greedy algorithm, and let O be a (possibly optimal) solution.


Step 2: Find a measure. Find a measure by which greedy stays ahead of the other solution you
chose to compare with. Let a1,...,ak be the first k measures of the greedy algorithm, and let
o1,...,om be the first m measures of the other solution (m = k sometimes).


Step 3: Prove that greedy stays ahead. Show that the partial solutions constructed by greedy
are always just as good as the initial segments of your other solution, based on the measure you selected.
• for all indices r ≤ min(k, m), prove by induction that ar ≥ or or that ar ≤ or, which ever
the case may be. Don’t forget to use your algorithm to help you argue the inductive step.


Step 4: Prove optimality. Prove that since greedy stays ahead of the other solution with respect to the measure you selected, then it is optimal.

[ref](http://www.cs.cornell.edu/courses/cs482/2007su/ahead.pdf)

## TODO List
- [x] 135  Candy
- [x] 435 Non Overlapping Intervals
- [x] 455  Assign Cookies
- [x] 502  IPO
- [x] 646  Max Length of Pair Chain
- [x] 1509 Min Difference Between Largest and Smallest Value in Three Moves
- [x] 1640 Check Array Formation Through Concatenation
- [x] 1921 Eliminate Max Number of Monster
- [x] 1963 Min Number of Swaps to Make the String Balanced


### priority_queue comparitor
```cpp
struct mycomp {
    constexpr bool operator()(
        pii const& a,
        pii const& b)
        const noexcept
        {
            if(a.first == b.first){ // determine first
                return a.second > b.second; // determin second
            }else{
                return a.first > b.first;
            }
        }
}
```
