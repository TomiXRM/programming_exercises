// https://atcoder.jp/contests/abc330/tasks/abc330_e

use proconio::input;
use std::collections::BTreeMap;

const DEBUG: bool = false;

struct MexInfo {
    value: u64,                  // mex(非負整数)の値
    pos_of_around_mex: Vec<u64>, // 注意スポット
}

fn main() {
    input! {
        (n , q) : (usize, i64),
        // mut a_list : [i64;n],
    };

    let mut a_list: Vec<u64> = vec![0; n];
    let mut map: BTreeMap<u64, Vec<u64>> = BTreeMap::new();
    let mut mex_info: MexInfo = MexInfo {
        value: u64::MAX, // u64::max_value() は u64::MAX と同義です
        pos_of_around_mex: vec![0; 1],
    };
    let mut mex_prev;

    for i in 0..n {
        input! {
            val :u64,
        };
        a_list[i] = val;
        map.entry(val).or_insert(Vec::new()).push(i as u64);
    }

    if DEBUG {
        println!("{:?}", map);
    }

    for _ in 0..q {
        input! {
            (i, val) : (usize,u64),
        }
        let removed_val = a_list[i - 1];
        a_list[i - 1] = val;

        // もし注意スポットに更新があればmexの更新を調査
        if DEBUG {
            println!("remove key{}", removed_val);
        }

        if let Some(v) = map.get(&removed_val) {
            if v.len() == 1 {
                map.remove(&removed_val);
            }
        } else {
            for pos in mex_info.pos_of_around_mex.iter() {
                if (i) as u64 == *pos {
                    if let Some(v) = map.get_mut(&removed_val) {
                        v.retain(|&x| x != i as u64); // i と一致する値を削除
                    }
                }
            }
        }

        map.entry(val).or_insert(Vec::new()).push(i as u64);

        let min_val_in_a_list = *map
            .first_key_value()
            .map(|(x, _)| x)
            .expect("最小値を出せませんでした");
        let max_val_in_a_list = *map
            .last_key_value()
            .map(|(x, _)| x)
            .expect("最大値を出せませんでした");
        if DEBUG {
            println!("min:{} max:{}", min_val_in_a_list, max_val_in_a_list);
        }
        mex_prev = mex_info.value;
        if min_val_in_a_list > 0 {
            mex_info.value = 0; // 確定演出
            mex_info.pos_of_around_mex = vec![0; 1];
            if DEBUG {
                print!("🍣");
            }
        } else {
            for i in min_val_in_a_list..=max_val_in_a_list {
                if !map.contains_key(&i) {
                    if DEBUG {
                        println!("☕️{}", i);
                    }
                    mex_info.value = i;
                    mex_info.pos_of_around_mex = vec![];
                    match map.get(&(mex_info.value - 1)) {
                        Some(v) => mex_info.pos_of_around_mex.extend(v),
                        None => {}
                    }
                    match map.range((mex_info.value - 1)..).nth(1) {
                        Some((_, v)) => mex_info.pos_of_around_mex.extend(v),
                        None => {}
                    }

                    break;
                } else {
                    if DEBUG {
                        println!("🍧{}", i);
                    }
                }
            }
            if mex_prev == mex_info.value {
                mex_info.value = max_val_in_a_list + 1;
                if DEBUG {
                    print!("🍔");
                }
            }
        }
        if DEBUG {
            println!("list:{:?}", a_list);
            println!("map:{:?}", map);
            println!("mex:{}", mex_info.value);
            println!("注意スポット:{:?}", mex_info.pos_of_around_mex);
        }
        println!("{}", mex_info.value);
    }

    // println!("{:?}",a_list);

    // let min_value = *a_list.iter().min().unwrap();
    // let max_value = *a_list.iter().min().unwrap();
}
