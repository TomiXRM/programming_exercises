use proconio::input;
use std::io;
fn main() {
    input! {
        (h,w):(u32,u32),
    };

    let mut s_list:Vec<Vec<char>> = Vec::new();
    for _ in 0..h{
        let mut line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        // let _list:Vec<char> = line.split_whitespace().map(|s| s).collect();
        let _list = line.chars().collect();
        s_list.push(_list);
    }
    // print!("{:?}",s_list);
}
