use std::io::BufRead;

fn readline(iter: &mut std::io::Lines<std::io::StdinLock>) -> String {
    return iter.next().unwrap().unwrap();
}

fn solve(k: i64) -> i64 {
    if k == 1 {
        return 0;
    } else if k == 2 {
        return 6;
    } else if k == 3 {
        return 28;
    }

    let twos = 4;
    let threes = 8;
    let fours = (k - 3) * 4;
    let sixes = 0.max(k - 4) * 4;
    let eights = 0.max(k - 4).pow(2);

    let mut total = k.pow(2);
    total *= total - 1;

    (total - (twos * 2 + threes * 3 + fours * 4 + sixes * 6 + eights * 8)) / 2
}

fn main() {
    let mut stdin_iter = std::io::stdin().lock().lines();

    let n: i64 = readline(&mut stdin_iter).parse().unwrap();
    // let dist: Vec<i32> = readline(&mut stdin_iter)
    //     .split(' ')
    //     .map(|s| s.parse::<i32>().unwrap())
    //     .collect();
    // let (y, x) = readline(&mut stdin_iter)
    //     .split_once(' ')
    //     .map(|(a, b)| (a.parse().unwrap(), b.parse().unwrap()))
    //     .unwrap();

    for x in 1..=n {
        // let x = readline(&mut stdin_iter).parse().unwrap();
        println!("{}", solve(x));
    }
}
