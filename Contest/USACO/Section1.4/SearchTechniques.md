# Sample Problem: n Queens [Traditional]
Place n queens on an n x n chess board so that no queen is attacked by another queen.

## Depth First Search (DFS)
The most obvious solution to code is to add queens recursively to the board one by one, trying all possible queen placements. It is easy to exploit the fact that there must be exactly one queen in each column: at each step in the recursion, just choose where in the current column to put the queen.


```cpp
search(col)
    if filled all columns
        print solution and exit 
    for each row
        if board(row, col) is not attacked
           place queen at (row, col)
           search(col+1)
           remove queen at (row, col)
```

# Sample Problem: Knight Cover [Traditional]
Place as few knights as possible on an n x n chess board so that every square is attacked. A knight is not considered to attack the square on which it sits.

## Breadth First Search (BFS)
In this case, it is desirable to try all the solutions with only k knights before moving on to those with k+1 knights. This is called breadth first search. The usual way to implement breadth first search is to use a queue of states:

```cpp
 process(state)
     for each possible next state from this one
         enqueue next state
 search()
     enqueue initial state
     while !empty(queue)
         state = get state from queue
         process(state)
 ```


## Depth First with Iterative Deepening (ID)
An alternative to breadth first search is iterative deepening. Instead of a single breadth first search, run D depth first searches in succession, each search allowed to go one row deeper than the previous one. That is, the first search is allowed only to explore to row 1, the second to row 2, and so on. This ``simulates'' a breadth first search at a cost in time but a savings in space.

```cpp
truncated_dfsearch(hnextpos, depth)
    if board is covered
        print solution and exit 

    if depth == 0
        return 

    for i from nextpos to n*n
        put knight at i
        truncated_dfsearch(i+1, depth-1)
        remove knight at i 

dfid_search
     for depth = 0 to max_depth
        truncated_dfsearch(0, depth)
```

## Examples

1. Superprime Rib
2. Betsy's Tour
3. Udder Travel
4. Desert Crossing
5. Addition Chains
