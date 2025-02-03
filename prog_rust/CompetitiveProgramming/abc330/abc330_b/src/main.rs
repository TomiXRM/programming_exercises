// https://atcoder.jp/contests/abc330/tasks/abc330_b

use std::io;

const DEBUG: bool = false;

fn get_input1() -> (i32, i32, i32) {
    if DEBUG {
        println!("数値を入力してください");
    }

    let mut input_text = String::new();
    io::stdin()
        .read_line(&mut input_text)
        .expect("入力に失敗しました");
    let mut iter = input_text.trim().split_whitespace();

    let n: i32 = iter.next().unwrap().parse().expect("数値に変換できません");
    let l: i32 = iter.next().unwrap().parse().expect("数値に変換できません");
    let r: i32 = iter.next().unwrap().parse().expect("数値に変換できません");

    (n, l, r)
}

fn get_input2() -> Vec<i32> {
    if DEBUG {
        println!("数値を入力してください");
    }
    let mut input_text = String::new();
    io::stdin()
        .read_line(&mut input_text)
        .expect("入力に失敗しました");
    let iter = input_text.trim().split_whitespace();

    let int_vec: Vec<i32> = iter
        .map(|x| x.parse::<i32>().unwrap())
        .collect();
    int_vec
}

fn main() {
    let (n, l, r) = get_input1();
    let int_vec = get_input2();
    if DEBUG {
        println!("input1:{:?}", &(n, l, r));
        println!("input2:{:?}", &int_vec);
    }
    // 1st try
    // let mut vector :Vec<(i32,i32)> = Vec::new();
    // for &num in int_vec.iter() {
    //     let (i, min_value) = (l..=r)
    //         .enumerate()
    //         .map(|(i, x)| (i, (x - num).abs()))
    //         .min_by_key(|(_, val)| *val)
    //         .unwrap();
        
    //     let a :Vec<i32>= (l..=r).collect();
    //     vector.push((a[i], min_value));
    // }
    // if DEBUG {
    //     println!("ans:{:?}", vector);
    // }
    // for (ans,_) in vector{
    //     print!("{} ",ans);
    // }

    // 2nd try
    // int_vec = int_vec.iter().map(
    //     |&ai| ai.min(r).max(l)
    // ).collect();

    // for ai in int_vec.iter(){
    //     if ai == &r || ai == &l {
    //         print!("{} ",ai);
    //     }else{
    //         (l..=r).enumerate().map(
    //             |(i,x)| (i,(x - ai).abs())
    //         ).min_by_key(|(_,x)| print!("{} ",*x));
    //     }
    // }

    // 3rd try
    for &ai in int_vec.iter() {
        let ans = if ai < l {
            l
        } else if ai > r {
            r
        } else {
            ai
        };
        print!("{} ", ans);
    }
    println!(); 
}