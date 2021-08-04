# Greedy

Greedy is most common used ( first-come-up naive ) algorithm to solve contest problem

- [x] 42  Trapping Water
- [x] 135 Candy
- [x] 502 IPO
- [x] 1640 Check Array Formation Through Concatenation


### Jump Game

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

### 1640 Follow up?

I solve this question by only greedy without considering repetitive start of the subarray and corresponding data-structure of storing each.
