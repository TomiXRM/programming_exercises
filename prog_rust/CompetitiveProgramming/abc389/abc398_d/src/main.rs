use proconio::input;

fn xy_to_r(x: &f64, y: &f64) -> f64 {
    (x * x + y * y).sqrt()
}

fn gen_xy_from_center(x: u64, y: u64) -> [(f64, f64); 4] {
    let mut point_list = [(0.0, 0.0); 4];
    let x = x as f64;
    let y = y as f64;

    point_list[0] = (x + 0.5, y + 0.5);
    point_list[1] = (x + 0.5, y - 0.5);
    point_list[2] = (x - 0.5, y - 0.5);
    point_list[3] = (x - 0.5, y + 0.5);

    point_list
}

fn main() {
    input! {
        r : u64,
    };
    korega_seikai(&(r as i64));
    let r_f64: f64 = r as f64;
    let mut count = 0;
    let mut count_on_y_line = 0;
    let mut iter_count = 0;
    let box_count = r * r * 4;

    for y_inc in 0..r {
        for x_inc in 0..r {
            iter_count += 1;
            // let y_inc = r - y_inc;
            // let x_inc = r - x_inc;
            if gen_xy_from_center(x_inc, y_inc)
                .iter()
                .filter(|(x, y)| xy_to_r(x, y) < r_f64)
                .count() == 4 {
                count += 1;
                if x_inc == 0 {
                    count_on_y_line += 1;
                }
                
            }else{
                // print!("🍣");
                break;
            }
            // println!("{x_inc},{y_inc}");
        }
    }

    // println!("{count} {count_on_y_line}");
    let ans = 4 * (count - count_on_y_line) + 1;
    print!("ans:");
    println!("{ans}");
    println!("iter{iter_count} box_count:{box_count}");
}


fn korega_seikai(r :&i64){
    let in_circle = |a: i64, b: i64| {
        (2 * a + 1) * (2 * a + 1) + (2 * b + 1) * (2 * b + 1) <= 4 * r * r
    };

    let mut cnt = 0;
    let mut up = r - 1;
    let mut res = (r - 1) * 4 + 1;
    for x in 1.. {
        if !in_circle(x, 1) {
            break;
        }
        while !in_circle(x, up) {
            up -= 1;
        }
        cnt += up;
    }
    res += cnt * 4;
    println!("{}", res);
}
