// https://atcoder.jp/contests/abc389/tasks/abc389_c
use std::collections::VecDeque;
use std::io;

const DEBUG: bool = false;
fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).expect("Fail to read");
    let q = s.trim().parse::<u128>().unwrap();

    let mut snake_list: VecDeque<(u128, u128)> = VecDeque::new(); // 長さ,Pos

    // let mut query: Vec<usize> = Vec::new();
    let mut s = String::new();
    for _ in 0..q {
        s.clear();
        io::stdin().read_line(&mut s).expect("Fail to read");

        // println!("s:{}",s);
        let mut iter = s.split_whitespace();
        let q_pattern = iter.next().unwrap().parse::<u128>().unwrap();
        match q_pattern {
            1 => {
                if DEBUG {
                    println!("🍕");
                }
                let l = iter.next().unwrap().parse::<u128>().unwrap();
                // println!("{:?}",l);

                // 長さlのヘビを末尾に追加
                if snake_list.len() == 0 {
                    // 元の列が空の場合は座標 0へ
                    snake_list.push_back((l, 0)); // 長さ,Pos
                } else {
                    let (len, pos) = snake_list.iter().next_back().expect("リストが空かも");
                    snake_list.push_back((l, pos + len)); // 長さ,Pos
                }
            }
            2 => {
                if DEBUG {
                    println!("🍟");
                }
                let (len, _) = snake_list.pop_front().expect("へびおらず");
                for snake in snake_list.iter_mut() {
                    snake.1 -= len;
                }
            }
            3 => {
                if DEBUG {
                    println!("🍣");
                }
                let k = iter.next().unwrap().parse::<u128>().unwrap();
                // println!("{:?}",k);

                let (_, pos) = snake_list[(k - 1) as usize];
                println!("{}", pos);
            }
            _ => {}
        }
        if DEBUG {
            println!("{:?}", snake_list);
        }
    }
}
