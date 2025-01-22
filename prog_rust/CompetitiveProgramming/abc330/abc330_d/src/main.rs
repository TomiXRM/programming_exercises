// https://atcoder.jp/contests/abc330/tasks/abc330_d

use proconio::input;

const DEBUG: bool = false;

fn main() {
    input! {
        n : usize,
        str_list : [String;n]
    }

    if DEBUG {
        println!("{:?}", str_list);
    }

    let mut row_o_count_list = vec![0; n];
    let mut col_o_count_list = vec![0; n];
    let mut o_addr_list: Vec<(usize, usize)> = Vec::new();

    for (i, text) in str_list.iter().enumerate() {
        for (j, word) in text.chars().enumerate() {
            if DEBUG {
                println!("i:{} j:{} text:{} word:{}", i, j, text, word);
            }
            if word == 'o' {
                row_o_count_list[i] += 1;
                col_o_count_list[j] += 1;
                o_addr_list.push((i, j));
            }
        }
    }

    let ans = o_addr_list
        .iter()
        .map(|(i, j)| (row_o_count_list[*i] - 1) * (col_o_count_list[*j] - 1))
        .sum::<i128>();

    if DEBUG {
        println!("{:?}", o_addr_list);
    }

    println!("{}", ans);
}
