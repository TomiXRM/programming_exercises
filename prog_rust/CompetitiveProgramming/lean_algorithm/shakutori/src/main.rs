fn main() {
    let list: [i32; 10] = [1, 5, 9, 1, 20, 5, 3, 6, 5, 4];

    let mut range_memo: Vec<(usize, usize)> = Vec::new();
    println!("{:?} len:{}", list, list.len());

    let mut right_pos = 0_usize;
    let mut left_pos = 0_usize;
    let mut sum = 0_i32;

    let target = 15;

    // 要素1個目(初期値)を入れておく
    sum += list[right_pos];

    loop {
        while sum >= target && left_pos < right_pos {
            if sum == target {
                range_memo.push((left_pos, right_pos));
            }

            println!(
                "l:{} r:{} sum:{} {:?}",
                left_pos, right_pos, sum, range_memo
            );

            sum -= list[left_pos];
            left_pos += 1;
        }

        println!(
            "l:{} r:{} sum:{} {:?}",
            left_pos, right_pos, sum, range_memo
        );

        if right_pos < list.len() - 1 {
            right_pos += 1;
            sum += list[right_pos];
        } else {
            sum -= list[left_pos];
            left_pos += 1;
        }

        // 終了条件をチェック
        if left_pos >= list.len() || right_pos >= list.len() {
            break;
        }
        if left_pos == list.len() - 1 && right_pos == list.len() - 1 {
            break;
        }
    }
}

// fn main() {
//     let list: [i32; 10] = [1, 5, 9, 1, 20, 5, 3, 6, 5, 4];

//     let mut range_memo: Vec<(usize, usize)> = Vec::new();
//     println!("{:?}", list);

//     let mut right_pos = 0_usize;
//     let mut left_pos = 0_usize;
//     let mut right_pos_prev = 1_usize;
//     let mut sum = 0_i32;
//     let mut count_least_15 = 0_u32;

//     while right_pos < 10 && left_pos < 10 {
//         // sumを作るシーケンス
//         if right_pos_prev != right_pos {
//             sum += list[right_pos];
//         }
//         right_pos_prev = right_pos.clone();
//         // right,leftの位置を移動させるシーケンス
//         print!("sum:{sum} ");
//         if sum >= 15 {
//             if sum == 15 {
//                 range_memo.push((left_pos, right_pos));
//                 println!("🍔l:{} r:{} {:?}", left_pos, right_pos, range_memo);
//                 sum -= list[left_pos];
//                 if right_pos < 10 - 1 {
//                     left_pos += 1;
//                     right_pos += 1;
//                 } else {
//                     left_pos += 1;
//                 }
//             } else {
//                 println!("🍕l:{} r:{} {:?}", left_pos, right_pos, range_memo);
//                 if left_pos == right_pos {
//                     right_pos += 1;
//                 }
//                 sum -= list[left_pos];
//                 left_pos += 1;
//             }
//         } else {
//             // if sum < 15
//             count_least_15 += 1;
//             println!("🍣l:{} r:{} {:?}", left_pos, right_pos, range_memo);
//             if right_pos < 10 - 1 {
//                 right_pos += 1;
//             } else {
//                 left_pos += 1;
//             }
//         }
//     }

//     println!("15以下の区間の数:{count_least_15}");
// }
