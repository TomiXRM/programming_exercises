// https://atcoder.jp/contests/abc388/tasks/abc388_a
use proconio::input;

fn main() {
    input!{
      s : String,
    };
    let (s,_) = s.split_at(1);
    println!("{}UPC",s);
}
