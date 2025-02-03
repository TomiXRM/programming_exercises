// use proconio::input;
fn main() {
    // input! {
    //     n :usize
    // };

    // let mut list = vec![0;n];
    // for i in 0..n{
    //     input! {
    //         a :u128
    //     };
    //     list[i] = a;
    // }

    // println!("{:?}",list);

    // 2,13
    // 3,12
    // 2のn乗-1の数(8,16,32,64...)は全てのビットが1になる
    let da = vec![71,74,45,34,31,60]; 

    let sum = da[0] + da[1];
    let xor = da[0] ^ da[1];

    println!("sum:{} sumbit:{:05b} ",sum,sum);
    println!("xor:{} xorbit:{:05b} ",xor,xor);
}
