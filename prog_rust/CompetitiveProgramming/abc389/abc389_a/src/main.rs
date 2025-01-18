// https://atcoder.jp/contests/abc389/tasks/abc389_a
use proconio::input;
fn main() {
    input!{
        s : String,
    }

    let a = s.chars().nth(0).unwrap() as i32 - 48;
    let b = s.chars().nth(2).unwrap() as i32 - 48;

    println!("{}",a*b);

}
