use std::collections::VecDeque;

fn main() {
    
    let list: [i32; 10] = [1, 5, 9, 1, 20, 5, 3, 6, 5, 4];
    let target = 15;

    let mut queue = VecDeque::new();
    let mut range_memo: Vec<(usize, usize)> = Vec::new(); // 区間を保存するためのベクタ
    let mut sum = 0;
    let mut left = 0;

    println!("{:?} len:{}", list, list.len());
    for right in 0..list.len() {
        queue.push_back(list[right]);
        sum += list[right];

        while sum > target && left < right {
            sum -= queue.pop_front().unwrap();
            left += 1;
        }

        if sum == target {
            range_memo.push((left, right)); // 区間を保存
        }
    }
    // 結果を表示
    println!("{:?}", range_memo); 
    for (i, (s, t)) in range_memo.iter().enumerate() {
        print!("{i}: range[{s},{t}] values:");
        for j in range_memo[i].0..=range_memo[i].1 {
            print!(" {}", list[j]);
        }
        print!("\n");
    }
}