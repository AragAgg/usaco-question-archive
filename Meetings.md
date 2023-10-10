---
Question Link: https://usaco.guide/silver/sorting-custom?lang=cpp#problems
Problem Set:
  - Silver
Last edited time: 2023-10-10T13:13
Status: Skipped for now
tags:
  - IDK
  - Sorting
What's up: The question is EXTREMELY HARD for silver. Tried for 30-40 mins without any major breakthrough, so skipping for now. Will come back to it later.
---
### What I’ve though till now

1. Two cows `meet` or `collide` only when both are moving towards each other.
2. We could not simulate it because we might have a case like this:
    
    ```C++
    [BARN] 1 2 3 4 ... 4.9*10^9 _ [COW] _ [COW] _ [COW] _ [COW] ... <FOLLOWS> _ REMAINING NUMBERS.
    ```
    
3. Such a case would likely take too long on a solution that tries to simulate the collisions.
4. one important observation is that the first cow to reach the left barn is the leftmost cow in the original configuration and so on an on.
5. similarly for the right barn cows.