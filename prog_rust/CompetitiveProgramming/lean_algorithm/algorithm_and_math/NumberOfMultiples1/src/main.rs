// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_g
use num::integer::lcm;
use std::io;

// 問題:N以下の正の整数の中で、Xの倍数または Yの倍数であるものの個数はいくつありますか？
fn main() {
    let input = io::stdin();

    let mut line = String::new();
    input.read_line(&mut line).unwrap();
    let s: Vec<i64> = line
        .split_whitespace()
        .map(|s| s.parse::<i64>().unwrap())
        .collect();

    let n = s[0];
    let x = s[1];
    let y = s[2];

    // [1,n]まで愚直に求める例。しかしこれは計算量が多い。
    // let count = (1..n)
    //     .filter(|val| (val % x == 0) || (val % y == 0))
    //     .count();

    /* 包除原理
    - 1~nまでの間にxの倍数の数値はn/x個ある
    - [1 2 3 4 5 6 7 8 9 10]の中に2の倍数は 10/2で5個。
    - 同じくyの倍数もn/y個あることになる。
    - しかしn/xとn/yを足すだけでは答えは出ない。
    - 何故ならxの倍数でありyの倍数である値をダブってカウントしていることになる。
    - そこで使えるのがxとyの最小公倍数という概念。n/{xとyの最小公倍数}で重複を数えられる
    - 最小公倍数はユークリッドの互除法で求められる。 lcm(a, b) = a * b / gcd(a, b)
    - x倍の個数 + y倍の個数 - {xとyの最小公倍数}倍の個数
    */
    let count = (n / x) + (n / y) - (n / lcm(x, y));
    println!("{count}");
}
