use std::{
    fmt::Debug,
    io::{BufRead, Lines, StdinLock},
    str::FromStr,
};

fn main() {
    let mut reader = Reader::new(std::io::stdin().lock().lines());
    let (n, _): (i32, i32) = reader.next_pair();
    let graph: Vec<Vec<u8>> = (0..n)
        .into_iter()
        .map(|_| reader.next_line().bytes().collect())
        .collect();

    let ans = solve(graph);
    println!("{ans}");
}

fn solve(mut graph: Vec<Vec<u8>>) -> i32 {
    let mut ans = 0;
    for i in 0..graph.len() {
        for j in 0..graph[i].len() {
            if graph[i][j] == '.' as u8 {
                ans += 1;
                dfs(&mut graph, i, j);
            }
        }
    }
    return ans;
}

fn dfs(graph: &mut Vec<Vec<u8>>, x: usize, y: usize) {
    graph[x][y] = 42;
    for (i, j) in [(1, 0), (0, 1), (-1, 0), (0, -1)] {
        let i = i + x as i32;
        let j = j + y as i32;
        if !(0..graph.len() as i32).contains(&i) || !(0..graph[0].len() as i32).contains(&j) {
            continue;
        }

        let i = i as usize;
        let j = j as usize;
        if graph[i][j] == '.' as u8 {
            dfs(graph, i, j);
        }
    }
}

struct Reader<'a> {
    lines: Lines<StdinLock<'a>>,
}

impl<'a> Reader<'a> {
    pub fn new(lines: Lines<StdinLock<'a>>) -> Reader {
        return Reader { lines };
    }

    pub fn next_line(&mut self) -> String {
        return self.lines.next().unwrap().unwrap();
    }

    pub fn next_pair<T, U>(&mut self) -> (T, U)
    where
        T: FromStr,
        <T as FromStr>::Err: Debug,
        U: FromStr,
        <U as FromStr>::Err: Debug,
    {
        return self
            .next_line()
            .split_once(char::is_whitespace)
            .map(|(a, b)| (a.parse::<T>().unwrap(), b.parse::<U>().unwrap()))
            .unwrap();
    }
}
