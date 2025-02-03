use std::io;
fn main() {
    let input = io::stdin();

    let mut line = String::new();
    input.read_line(&mut line).unwrap();
    let list:Vec<i32> = line.split_whitespace().map(|s| s.parse::<i32>().unwrap()).collect();

    let n = list[0];
    let s = list[1];
    if n <= &s-1{
        println!("{}",(s - 1) * s / 2);
    }else{
        println!("{}",(n - 1) * n / 2);
    }
    
}
