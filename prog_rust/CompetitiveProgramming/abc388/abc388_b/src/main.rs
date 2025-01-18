// https://atcoder.jp/contests/abc388/tasks/abc388_b
use proconio::input;
fn main() {
    input! {
        (n,d) : (u32,u32),
    };

    let mut t_list = vec![0; n as usize];
    let mut l_list = vec![0; n as usize];
    for i in 0..n {
        input! {
            (t,l) : (u32,u32)
        };

        t_list[i as usize] = t;
        l_list[i as usize] = l;
    }
    
    let mut masss = vec![0;n as usize];
    for _d in 0..d {
        for _n in 0..n {
            masss[_n as usize] = t_list[_n as usize] * (l_list[_n as usize] + _d + 1);
        }
        masss.sort();
        println!("{:?}",masss.iter().next_back().unwrap());
    }
}
