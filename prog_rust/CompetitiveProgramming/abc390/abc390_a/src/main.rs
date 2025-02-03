
use proconio::input;
fn main() {
    input! {
        mut a_list : [i32;5]

    }
    let mut count = 0;
    let mut at_list = a_list.clone();
    at_list.sort();

    

    for i in 0..a_list.len()-1{
        if a_list[i] > a_list[i+1] {
            let temp = a_list[i+1];
            a_list[i+1] = a_list[i];
            a_list[i] = temp;
            count+=1;
        }
    }
    // print!("change:{:?}",a_list);
    if a_list == at_list && count == 1{
        print!("Yes");
    }else{
        print!("No");
    }
}
