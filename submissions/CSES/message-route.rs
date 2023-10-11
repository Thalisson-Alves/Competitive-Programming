use std::{
    fmt::Debug,
    io::{BufRead, Lines, StdinLock},
    str::FromStr,
};

fn main() {
    let mut reader = Reader::new(std::io::stdin().lock().lines());
    let (n, m): (usize, usize) = reader.pair();
    let mut graph = vec![vec![]; n];
    for _ in 0..m {
        let (mut a, mut b): (usize, usize) = reader.pair();
        a -= 1; b -= 1;
        graph[a].push(b);
        graph[b].push(a);
    }

    let ans = solve(graph);
    if ans.is_empty() {
        println!("IMPOSSIBLE");
        return;
    }
    println!("{}", ans.len());
    println!(
        "{}",
        ans.into_iter()
            .map(|x| (x + 1).to_string())
            .collect::<Vec<String>>()
            .join(" ")
    );
}

fn solve(graph: Vec<Vec<usize>>) -> Vec<usize> {
    return bfs(&graph, 0, &graph.len() - 1);
}

fn bfs(graph: &Vec<Vec<usize>>, start: usize, end: usize) -> Vec<usize> {
    let mut queue = std::collections::VecDeque::new();
    queue.push_back(start);
    let mut vis = std::collections::HashSet::new();
    vis.insert(start);
    let mut came_from = vec![usize::MAX; graph.len()];

    while !queue.is_empty() {
        let cur = queue.pop_front().unwrap();
        if cur == end {
            let mut cur = cur;
            let mut ans = vec![cur];
            while cur != start {
                ans.push(came_from[cur]);
                cur = came_from[cur];
            }
            return ans.into_iter().rev().collect();
        }

        for x in &graph[cur] {
            if vis.contains(&x) {
                continue;
            }

            queue.push_back(*x);
            vis.insert(*x);
            came_from[*x] = cur;
        }
    }

    return vec![];
}

struct Reader<'a> {
    lines: Lines<StdinLock<'a>>,
}

impl<'a> Reader<'a> {
    pub fn new(lines: Lines<StdinLock<'a>>) -> Reader {
        return Reader { lines };
    }

    pub fn line(&mut self) -> String {
        return self.lines.next().unwrap().unwrap();
    }

    pub fn pair<T, U>(&mut self) -> (T, U)
    where
        T: FromStr,
        <T as FromStr>::Err: Debug,
        U: FromStr,
        <U as FromStr>::Err: Debug,
    {
        return self
            .line()
            .split_once(char::is_whitespace)
            .map(|(a, b)| (a.parse::<T>().unwrap(), b.parse::<U>().unwrap()))
            .unwrap();
    }

    pub fn vec<T>(&mut self) -> Vec<T>
    where
        T: FromStr,
        <T as FromStr>::Err: Debug,
    {
        return self
            .line()
            .split(char::is_whitespace)
            .map(|x| x.parse::<T>().unwrap())
            .collect();
    }
}
