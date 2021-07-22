# Greedy

Greedy is most common used ( first-come-up naive ) algorithm to solve contest problem

- [x] 42  Trapping Water
- [x] 135 Candy
- [ ] 502 IPO

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