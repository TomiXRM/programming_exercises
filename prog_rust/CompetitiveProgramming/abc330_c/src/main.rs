// https://atcoder.jp/contests/abc330/tasks/abc330_c
// 結局できんかった。くやしいね

use std::io;

const DEBUG :bool = true;
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let main_value :f32 = input.trim().parse().expect("数値に変換できませんでした");

    let a :f32 = main_value.sqrt().trunc();
    let a_list:Vec<f32> = (-1..=4).map(|x| a - (x as f32)).collect();

    if DEBUG {println!("a_list:{:?}",&a_list);}

    let mut b_list :Vec<f32> = Vec::new();

    for a_ in a_list.iter(){
        
        let x = main_value - a_.powi(2);

        b_list.push(if x.is_sign_positive() {
            x.sqrt().trunc()
        }else{
            0.0
        });
        
    }

    if DEBUG {println!("b_list:{:?}",&b_list);}

    let mut min_val = std::i32::MAX;
    for (a, b) in a_list.iter().zip(b_list.iter()) {
        let val = main_value - a.powi(2) - b.powi(2);
        if DEBUG { print!("{} ", val); }
        if val.is_sign_negative() {
            continue;
        }
        min_val = min_val.min(val as i32);
    }

    println!("{}",min_val);

    // if DEBUG {println!("{},{}",a,b);}

    // let x = main_value - a.powi(2) - b.powi(2);
    // println!("{}",x);

}