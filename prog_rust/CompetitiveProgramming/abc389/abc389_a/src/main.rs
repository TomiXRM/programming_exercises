// https://atcoder.jp/contests/abc389/tasks/abc389_a
use proconio::input;
// fn main() {
//     input!{
//         s : String,
//     }
//     let a = s.chars().nth(0).unwrap() as i32 - 48;
//     let b = s.chars().nth(2).unwrap() as i32 - 48;
//     println!("{}",a*b);
// }

fn calc_from_string(s: &str) -> Option<i32> {
    let parts: Vec<&str> = s.split('x').collect();
    if parts.len() != 2 {
        return None; // "x" で区切られていない場合は None を返す
    }

    let a = parts[0].parse::<i32>().ok()?;
    let b = parts[1].parse::<i32>().ok()?;
    // 変換できたかをok?で判定して、もし変換に失敗したらこいつがreturn Noneするらしい！！
    // Result型で返却するのがRustなのです！！って感じ

    Some(a * b)
}

fn main() {
    input!{
        s : String,
    }
    match calc_from_string(&s) {
        Some(result) => println!("{}", result),
        None => eprintln!("入力フォーマットが間違ってます！！"),
    }
}