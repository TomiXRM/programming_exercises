// https://atcoder.jp/contests/abc389/tasks/abc389_b
use proconio::input;
fn main() {
    input!{
        x : u128,
    };

    let mut val:u128 = 1;
    let mut count = 0;
    loop{
        count += 1;
        val *= count;
        
        if val == x {
            println!("{}",count);
            break;
        }
        // println!("count:{} val:{} ",count,val);
        if val > x {
            println!("なし！");
            break;
        }
    }
}
