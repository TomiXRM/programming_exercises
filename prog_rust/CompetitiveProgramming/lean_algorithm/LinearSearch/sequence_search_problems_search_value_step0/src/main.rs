// https://paiza.jp/works/mondai/sequence_search_problems/sequence_search_problems_search_value_step0/edit?language_uid=rust
// 指定された値の個数 Rust(Beta)編（paizaランク D 相当）
use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    line.clear();
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();

    let list: Vec<i32> = line
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    line.clear();
    io::stdin().read_line(&mut line).unwrap();
    let k: i32 = line.trim().parse().unwrap();

    let count = list.iter().filter(|&&a| a == k).count();
    println!("{count}");
}
