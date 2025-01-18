// https://atcoder.jp/contests/abc330/tasks/abc330_e
use proconio::input;
use std::collections::BTreeSet;
use std::io::{self, Write};

fn main() {
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());

    input! {
        n: usize,
        q: usize,
        a: [usize; n],
    }

    let mut count: Vec<usize> = vec![0; n + 1];
    for &val in &a {
        if val <= n {
            count[val] += 1;
        }
    }

    let mut st: BTreeSet<usize> = BTreeSet::new();
    for i in 0..=n {
        if count[i] == 0 {
            st.insert(i);
        }
    }

    let mut a = a; 
    for _ in 0..q {
        input! {
            i: usize,
            x: usize,
        }
        let i = i - 1;

        let t = a[i];
        if t <= n {
            count[t] -= 1;
            if count[t] == 0 {
                st.insert(t);
            }
        }

        a[i] = x;
        if x <= n {
            if count[x] == 0 {
                st.remove(&x);
            }
            count[x] += 1;
        }

        writeln!(out, "{}", st.iter().next().unwrap()).unwrap();
    }
}