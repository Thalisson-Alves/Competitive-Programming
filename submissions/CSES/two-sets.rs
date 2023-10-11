use std::io::BufRead;

fn readline(iter: &mut std::io::Lines<std::io::StdinLock>) -> String {
    return iter.next().unwrap().unwrap();
}

fn solve(n: i64) -> Option<(Vec<i64>, Vec<i64>)> {
    let sum = n * (n + 1) / 2;
    if (sum & 1) == 1 {
        return None;
    }

    let mut sum = sum >> 1;
    let mut first: Vec<i64> = (1..=n).rev().take_while(|x| {
        if sum >= *x {
            sum -= x;
            true
        } else {
            false
        }
    }).collect();
    if sum > 0 {
        first.push(sum);
    }
    first.reverse();

    let second = (1..=n).filter(|x| first.binary_search(x).is_err()).collect();
    return Some((first, second));
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

    if let Some((a, b)) = solve(n) {
        println!("YES");
        println!("{}", a.len());
        println!("{}", a.into_iter().map(|x| x.to_string()).collect::<Vec<_>>().join(" "));
        println!("{}", b.len());
        println!("{}", b.into_iter().map(|x| x.to_string()).collect::<Vec<_>>().join(" "));
    } else {
        println!("NO");
    }
}
