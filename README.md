# Library
競プロlibrary

___plantUMLが使えるかどうかの検証__
```plantuml
class Combination{
    - fac : vector<long long> 
    - finv : vector<long long> 
    - inv : vector<long long>
    + Combination(n : int)
    + calc(n : int, k : int) : long long
}
note top : コンストラクタで 0 ~ n までの階乗と逆元をもとめる。calc関数 で O(1) で値を求める。
```

