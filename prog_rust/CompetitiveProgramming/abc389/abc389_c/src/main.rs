// https://atcoder.jp/contests/abc389/tasks/abc389_c

use std::collections::VecDeque;
use proconio::input;

fn main() {
    input!{
        q : usize,
    }

    let mut deque: VecDeque<i128> = VecDeque::new();
    deque.push_back(0); // 初期値 0 を追加
    let mut removed: i128 = 0;

    for _ in 0..q {
        input! {
            t : i128
        }

        match t {
            1 => {
                input! {
                    l : i128
                }
                deque.push_back(deque.back().copied().unwrap() + l);
            }
            2 => {
                removed += deque[1] - deque[0];
                deque.pop_front();
            }
            _ => {
                input! {
                    k : i128
                }
                let k: i128 = k - 1;
                let ans: i128 = deque[k.try_into().unwrap()] - removed;
                println!("{}", ans);
            }
        }
        println!("removed:{} deque{:?}",removed, deque);
    }
}

// use std::collections::VecDeque;
// use std::io::stdin;

// fn main() {
//     let mut str_q = String::new();
//     stdin()
//         .read_line(&mut str_q)
//         .expect("読み込みに失敗しました");
//     let q = str_q
//         .trim()
//         .parse::<u128>()
//         .expect("Qには数値を入力してください");

//     let mut pos_que: VecDeque<u128> = VecDeque::new(); // 長さを保存するDeque

//     let mut query = String::new();
//     for _ in 0..q {
//         query.clear();
//         stdin()
//             .read_line(&mut query)
//             .expect("読み込みに失敗しました");
//         let mut s_iter = query.split_whitespace();
//         let query = s_iter.next().unwrap().parse::<u128>();
//         match query {
//             Ok(1_u128) => {
//                 let l = s_iter
//                     .next()
//                     .unwrap()
//                     .parse::<u128>()
//                     .expect("lの値を取得できませんでした");
//                 pos_que.push_back(l);
//             }
//             Ok(2_u128) => {
//                 // let pos_front_before =
//                 pos_que.pop_front().expect("pos_queが空です");
//             }
//             Ok(3_u128) => {
//                 let k = s_iter
//                     .next()
//                     .unwrap()
//                     .parse::<usize>()
//                     .expect("kの値を取得できませんでした");
//                 let sum = pos_que.iter().take(k - 1).sum::<u128>();
//                 // println!("sum:{} p:{}",sum,sum + fromt_pos_offset);
//                 println!("{}", sum);
//             }
//             Err(err) => {
//                 println!("{}", err);
//             }
//             _ => {
//                 panic!("どういうことですか？");
//             }
//         }
//         // println!("pos_que{:?} offset:{}", pos_que,fromt_pos_offset);
//     }
// }

// use std::collections::VecDeque;
// use std::io;

// const DEBUG: bool = false;
// fn main() {
//     let mut s = String::new();
//     io::stdin().read_line(&mut s).expect("Fail to read");
//     let q = s.trim().parse::<u128>().unwrap();

//     let mut snake_list: VecDeque<(u128, u128)> = VecDeque::new(); // 長さ,Pos

//     // let mut query: Vec<usize> = Vec::new();
//     let mut s = String::new();
//     for _ in 0..q {
//         s.clear();
//         io::stdin().read_line(&mut s).expect("Fail to read");

//         // println!("s:{}",s);
//         let mut iter = s.split_whitespace();
//         let q_pattern = iter.next().unwrap().parse::<u128>().unwrap();
//         match q_pattern {
//             1 => {
//                 if DEBUG {
//                     println!("🍕");
//                 }
//                 let l = iter.next().unwrap().parse::<u128>().unwrap();
//                 // println!("{:?}",l);

//                 // 長さlのヘビを末尾に追加
//                 if snake_list.len() == 0 {
//                     // 元の列が空の場合は座標 0へ
//                     snake_list.push_back((l, 0)); // 長さ,Pos
//                 } else {
//                     let (len, pos) = snake_list.iter().next_back().expect("リストが空かも");
//                     snake_list.push_back((l, pos + len)); // 長さ,Pos
//                 }
//             }
//             2 => {
//                 if DEBUG {
//                     println!("🍟");
//                 }
//                 let (len, _) = snake_list.pop_front().expect("へびおらず");
//                 for snake in snake_list.iter_mut() {
//                     snake.1 -= len;
//                 }
//             }
//             3 => {
//                 if DEBUG {
//                     println!("🍣");
//                 }
//                 let k = iter.next().unwrap().parse::<u128>().unwrap();
//                 // println!("{:?}",k);

//                 let (_, pos) = snake_list[(k - 1) as usize];
//                 println!("{}", pos);
//             }
//             _ => {}
//         }
//         if DEBUG {
//             println!("{:?}", snake_list);
//         }
//     }
// }
