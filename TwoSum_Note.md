### Point

- 使用 find 在 [3, 3] 的情況, for loop 第二次時仍找到第一個 3, i=1, but v->second = 0
```auto v = myMap.find(target - nums[i]);```
- for loop 第一次找 3 時不 push, 因此加入 myMap[target - nums[i]] != i 的篩選, 因此 for loop 第二輪時 i =1, 但 v 仍是第一個 3, 即 v->second = 0,  此時 myMap[target - nums[i]] = 0, 這個情況才 push
```if (v != myMap.end() && myMap[target - nums[i]] != i)```
- 這種做法無法得到 [0, 1] (第一個 3 的 index 是 0, 第二個 3 的 index 是 1), 而是會得到 [1, 0] 

### Other

- 嘗試在找到第一個 3 之後, 使用 myMap.erase(nums[i]), 希望能在第二次 loop 時找到第二個 3, 但 compile 失敗
- 似乎也可以用 myMap.count(target - nums[i]) 做做看
