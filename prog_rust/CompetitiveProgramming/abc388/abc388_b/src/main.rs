// https://atcoder.jp/contests/abc388/tasks/abc388_b
use proconio::input;
fn main() {
    input! {
        (n,d) : (usize,u32),
    };

    let mut t_list = vec![0; n];
    let mut l_list = vec![0; n];
    for i in 0..n {
        input! {
            (t,l) : (u32,u32)
        };

        t_list[i] = t;
        l_list[i] = l;
    }
    
    let mut masss = vec![0;n];
    for _d in 0..d {
        for _n in 0..n {
            masss[_n] = t_list[_n] * (l_list[_n] + _d + 1);
        }
        masss.sort();
        println!("{:?}",masss.iter().next_back().unwrap());
    }
}
