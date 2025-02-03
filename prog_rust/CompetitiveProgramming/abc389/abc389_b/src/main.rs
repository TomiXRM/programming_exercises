// https://atcoder.jp/contests/abc389/tasks/abc389_b


fn fact(f: u128) -> u128 {
    if f == 0 {
        1
    } else {
        f.checked_mul(fact(f - 1)).unwrap_or(u128::MAX)
    }
}

use proconio::input;
fn main() {
    input!{
        x : u128,
    };

    // let mut val:u128 = 1;
    // let mut count = 0;
    // loop{
    //     count += 1;
    //     val *= count;
        
    //     if val == x {
    //         println!("{}",count);
    //         break;
    //     }
    //     // println!("count:{} val:{} ",count,val);
    //     if val > x {
    //         println!("なし！");
    //         break;
    //     }
    // }

    let mut count: u128 = 0;
    loop{
        count += 1;
        if fact(count) == x {
            println!("{}",count);
            break;
        }
    }
}
