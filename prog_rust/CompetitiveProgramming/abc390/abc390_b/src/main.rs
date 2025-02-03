// use proconio::input;
// // use std::io;

// fn main() {
//     input! {
//         n: usize,
//     };

//     // let mut line = String::new();
//     // io::stdin().read_line(&mut line).unwrap();
//     // let list:Vec<u128> = line.split_whitespace().map(|s| s.parse::<u128>().unwrap()).collect();

//     let mut list: Vec<u128> = Vec::new()  ;
//     for _ in 0..n{
//         input! {
//             inpu: u128,
//         };
//         list.push(inpu);
//     }

//     // println!("{:?}",list);
//     if list[0] == 0 {
//         println!("No");
//         return;
//     }

//     if list.iter().skip(1).any(|&x| x == 0) {
//         if list.iter().skip(1).all(|&x| x == 0) {
//           println!("Yes");
//         } else {
//           println!("No");
//         }
//         return;
//     }

//     let ratio = list[1] as f64 / list[0] as f64;

//     for i in 1..list.len() {
//         if list[i] as f64 / list[i - 1] as f64 != ratio {
//             println!("No");
//             return;
//         }
//     }

//     println!("Yes");
// }


use proconio::input;
fn main(){
    // let an = vec![3,6,12,24,48];
    input! {
        n : usize
    };
    let mut an = vec![0;n];
    for i in 0..n{
        input! {
            a : u128
        };
        an[i] = a;
    }

    let mut flag = true;

    for i in 0..an.len() - 2{
        // println!("{}x{} == {}x{}",an[i+1],an[i+1],an[i+2],an[i]);
        if an[i+1] * an[i+1] != an[i+2] * an[i]{
            flag = false;
            // println!("{i}");
            break;
        }
    }
    
    if flag{
        println!("Yes");
    }else{
        println!("No");
    }
}