use std::io::BufRead;

fn readline(iter: &mut std::io::Lines<std::io::StdinLock>) -> String {
    return iter.next().unwrap().unwrap();
}

fn solve(y: i32, x: i32) -> i64 {
    let mx = y.max(x) as i64;
    let ans = 1 + mx * (mx - 1);

    let diff = if ((mx & 1) ^ (x > y) as i64) == 0 {
        1
    } else {
        -1
    };

    ans + diff * (mx - y.min(x) as i64)
}

fn main() {
    let mut stdin_iter = std::io::stdin().lock().lines();

    let n: i64 = readline(&mut stdin_iter).parse().unwrap();
    // let dist: Vec<i32> = readline(&mut stdin_iter)
    //     .split(' ')
    //     .map(|s| s.parse::<i32>().unwrap())
    //     .collect();

    for _ in 0..n {
        let (y, x) = readline(&mut stdin_iter)
            .split_once(' ')
            .map(|(a, b)| (a.parse().unwrap(), b.parse().unwrap()))
            .unwrap();
        println!("{}", solve(y, x));
    }
}
