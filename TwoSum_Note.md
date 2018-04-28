### Point

- 使用 find 在 [3, 3] 的情況, for loop 第二次時仍找到第一個 3, i=1, but v->second = 0

```auto v = myMap.find(target - nums[i]);```

- for loop 第一次找 3 時不 push, 因此加入 myMap[target - nums[i]] != i 的篩選, 因此 for loop 第二輪時 i =1, 但 v 仍是第一個 3, 即 v->second = 0,  此時 myMap[target - nums[i]] = 0, 這個情況才 push

```if (v != myMap.end() && myMap[target - nums[i]] != i)```

- 這種做法無法得到 [0, 1] (第一個 3 的 index 是 0, 第二個 3 的 index 是 1), 而是會得到 [1, 0] 

### Complexity Analysis

- 使用 hash table 的做法用空間換取時間, Time complexity : O(n). Space complexity : O(n). 兩層迴圈的暴力法 Time complexity : O(n^2). Space complexity : O(1).
- 改進版是 one-pass hash table, 一個 for loop 同時處理找到資料就塞進答案, 找不到就建立 table, 一樣是 Time complexity : O(n). Space complexity : O(n). 
- [Leetcode article solution](https://leetcode.com/articles/two-sum/)

### Other

- 嘗試在找到第一個 3 之後, 使用 myMap.erase(nums[i]), 希望能在第二次 loop 時找到第二個 3, 但 compile 失敗
- 似乎也可以用 myMap.count(target - nums[i]) 做做看
