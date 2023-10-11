use std::io::BufRead;

fn readline(iter: &mut std::io::Lines<std::io::StdinLock>) -> String {
    return iter.next().unwrap().unwrap();
}

fn solve(mut n: i64) -> i64 {
    let mut ans = 0;
    while n > 0 {
        ans += n / 5;
        n /= 5;
    }
    ans
}

fn main() {
    let mut stdin_iter = std::io::stdin().lock().lines();

    let n = readline(&mut stdin_iter).parse().unwrap();
    // let dist: Vec<i32> = readline(&mut stdin_iter)
    //     .split(' ')
    //     .map(|s| s.parse::<i32>().unwrap())
    //     .collect();
    // let (y, x) = readline(&mut stdin_iter)
    //     .split_once(' ')
    //     .map(|(a, b)| (a.parse().unwrap(), b.parse().unwrap()))
    //     .unwrap();

    println!("{}", solve(n));
}
