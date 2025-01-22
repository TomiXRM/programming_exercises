/*
問題
https://atcoder.jp/contests/abc330/tasks/abc330_a
*/

use std::io;

const DEBUG :bool = false;

fn get_input_count_and_thr() -> (i32,i32){
    let mut input_txt = String::new();
    io::stdin().read_line(&mut input_txt).expect("入力に失敗しました");
    let mut iter = input_txt.trim().split_whitespace();

    let num1 = iter.next().unwrap().parse().expect("数値に変換できません");
    let num2 = iter.next().unwrap().parse().expect("数値に変換できません");

    (num1,num2)
}

fn get_input_points() -> Vec<i32> {
    let mut input_text = String::new();
    io::stdin().read_line(&mut input_text).expect("入力に失敗しました");
    input_text.trim().split_whitespace()
    .map(|s| s.parse().expect("数値に変換できません"))
    .collect()
}

fn main() {
    let (person_number,point_thr) = get_input_count_and_thr();
    if DEBUG {println!("N:{} L:{}", person_number, point_thr);}
    let points: Vec<i32> = get_input_points();
    if DEBUG {println!("points:{:?}",points);}

    let count = points.iter().filter(|&&x| x >= point_thr ).count();
    println!("{}",count);
}
