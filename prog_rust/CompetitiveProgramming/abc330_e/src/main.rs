// https://atcoder.jp/contests/abc330/tasks/abc330_e

use proconio::input;
use std::collections::BTreeMap;

const DEBUG: bool = false;

fn print_map(map: &BTreeMap<u128, u128>) {
    for (_, (key, value)) in map.iter().enumerate() {
        println!("#{}: count:{}", key, value);
    }
}

fn update_map(map: &mut BTreeMap<u128, u128>, value: &u128, removed_value: &u128) {
    if let Some(count) = map.get_mut(value) {
        *count += 1;
    } else {
        map.entry(value.clone()).or_insert(1);
    }

    if let Some(count) = map.get_mut(removed_value) {
        *count -= 1;
        if *count == 0 {
            map.remove(removed_value);
        }
    }
}

fn calc_mex(map: &BTreeMap<u128, u128>) {
    let mut mex = u128::MAX;
    let min_key = *map
        .first_key_value()
        .map(|(k, _)| k)
        .expect("最小値が取り出せませんでした");
    let max_key = *map
        .last_key_value()
        .map(|(k, _)| k)
        .expect("最大値が取り出せませんでした");
    if DEBUG {
        println!("min:{} max:{} ", min_key, max_key);
    }

    if min_key == 1 {
        mex = 0;
    } else {
        for k in (min_key + 1)..=(max_key + 1) {
            if !map.contains_key(&k) {
                mex = k;
                break;
            }
        }
    }
    if DEBUG {
        print!("mex:");
    }
    println!("{}", mex);
}

fn main() {
    input! {
        (n , q) : (u128, u128),
    };

    let mut a_list = vec![0; n as usize];
    let mut map: BTreeMap<u128, u128> = BTreeMap::new();

    // 数列A1~Anの受け取り
    for i in 0..n {
        input! {
            value :u128
        }
        a_list[i as usize] = value;
        //  数列Aの要素aについて、重複数を数える
        update_map(&mut map, &value, &u128::MAX);
        // calc_mex(&map);
    }
    if DEBUG {
        println!("{:?}", a_list);
        print_map(&map);
    }

    for _ in 0..q {
        input! {
            (index, input_value) : (u128,u128),
        };

        let removed_value = a_list[index as usize - 1];
        a_list[index as usize - 1] = input_value; // 数値の置き換え
        update_map(&mut map, &input_value, &removed_value);
        calc_mex(&map);
        if DEBUG {
            println!("{:?}", a_list);
            print_map(&map);
        }
    }
}
