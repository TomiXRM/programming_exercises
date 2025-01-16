// https://atcoder.jp/contests/abc330/tasks/abc330_d

use proconio::input;

const DEBUG: bool = false;
// fn main() {
//     input! {
//         n : usize,
//         str_list : [String;n],
//     }

//     let mut sheet = vec![vec![' '; n]; n];

//     /* oとxが書かれた2次元配列を作る(スプレッドシートみたいな感じ)
//       ooo
//       oxx
//       xxo
//        ↓
//     [[o,o,o],
//     [o,x,x],
//     [x,x,o]]
//     */
//     for i in 0..n {
//         for (j, word) in str_list[i].chars().enumerate() {
//             sheet[i][j] = word;
//         }
//     }

//     if DEBUG {
//         println!("sheet:");
//         println!("{:?}", sheet);
//     }

//     // oが入ってる番地をvectorに保存する
//     let mut o_addr_list_xy: Vec<Vec<usize>> = Vec::new();
//     for i in 0..n {
//         // 行ごとの処理
//         let _o_addr_list_x: Vec<usize> = str_list[i]
//             .chars()
//             .enumerate()
//             .filter(|(_, word)| *word == 'o')
//             .map(|(x, _)| x)
//             .collect();

//         o_addr_list_xy.push(_o_addr_list_x);
//     }
//     // tupleに変換
//     let mut o_addr_tuple_vec: Vec<(usize, usize)> = Vec::new();
//     for (i, row) in o_addr_list_xy.iter().enumerate() {
//         for &j in row {
//             o_addr_tuple_vec.push((j, i));
//         }
//     }

//     // oになっている座標(x,y)のうち、xが_xになっている座標の数をカウントして返す関数
//     let count_func_x = |_x| -> usize {
//         return o_addr_tuple_vec.iter().filter(|&&(x, _)| x == _x).count();
//     };

//     // oになっている座標(x,y)のうち、yが_yになっている座標の数をカウントして返す関数
//     let count_func_y = |_y| -> usize {
//         return o_addr_tuple_vec.iter().filter(|&&(_, y)| y == _y).count();
//     };

//     //
//     let mut count = 0;
//     for (x, y) in o_addr_tuple_vec.iter() {
//         count += (count_func_x(*x) - 1) * (count_func_y(*y) - 1);
//     }

//     if DEBUG {
//         print!("count : ");
//     }
//     println!("{}", count);
// }


fn main() {
    input! {
        n : usize,
        str_list : [String;n],
    }

    let mut sheet = vec![vec![' '; n]; n];

    for i in 0..n {
        for (j, word) in str_list[i].chars().enumerate() {
            sheet[i][j] = word;
        }
    }

    if DEBUG {
        println!("sheet:");
        println!("{:?}", sheet);
    }

    // 各x座標における'o'の個数をカウント
    let mut count_x = vec![0; n];
    // 各y座標における'o'の個数をカウント
    let mut count_y = vec![0; n];

    for i in 0..n {
        for j in 0..n {
            if sheet[i][j] == 'o' {
                count_x[j] += 1;
                count_y[i] += 1;
            }
        }
    }

    let mut count = 0;
    for i in 0..n {
        for j in 0..n {
            if sheet[i][j] == 'o' {
                count += (count_x[j] - 1) * (count_y[i] - 1);
            }
        }
    }

    if DEBUG {
        print!("count : ");
    }
    println!("{}", count);
}