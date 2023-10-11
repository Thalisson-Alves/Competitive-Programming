use std::{
    collections::{HashSet, VecDeque},
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
    if ans.is_empty() {
        println!("NO");
        return;
    }

    println!("YES");
    println!("{}", ans.len());
    println!("{ans}");
}

fn solve(graph: Vec<Vec<u8>>) -> String {
    let mut start = (0, 0);
    let mut end = (0, 0);
    for i in 0..graph.len() {
        for j in 0..graph[i].len() {
            if graph[i][j] == 'A' as u8 {
                start = (i, j);
            } else if graph[i][j] == 'B' as u8 {
                end = (i, j);
            }
        }
    }

    return bfs(graph, start, end);
}

fn bfs(graph: Vec<Vec<u8>>, start: (usize, usize), end: (usize, usize)) -> String {
    let mut queue = VecDeque::new();
    queue.push_back(start);
    let mut vis = HashSet::new();
    vis.insert(start);
    let mut came_from = vec![vec![0_u8; graph[0].len()]; graph.len()];
    while !queue.is_empty() {
        let mut cur = queue.pop_front().unwrap();
        if cur == end {
            let mut ans = String::new();
            while cur != start {
                let direction = came_from[cur.0][cur.1] as char;
                ans.push(direction);
                cur = match direction {
                    'D' => (cur.0 - 1, cur.1),
                    'R' => (cur.0, cur.1 - 1),
                    'U' => (cur.0 + 1, cur.1),
                    'L' => (cur.0, cur.1 + 1),
                    _ => (0, 0),
                };
            }
            return ans.chars().rev().collect();
        }

        for (x, y, d) in [(1, 0, 'D' as u8), (0, 1, 'R' as u8), (-1, 0, 'U' as u8), (0, -1, 'L' as u8)] {
            let x = x + cur.0 as i32;
            let y = y + cur.1 as i32;

            if 0 > x || x >= graph.len() as i32 || 0 > y || y >= graph[0].len() as i32 {
                continue;
            }

            let x = x as usize;
            let y = y as usize;

            if graph[x][y] == '#' as u8 || vis.contains(&(x, y)) {
                continue;
            }

            queue.push_back((x, y));
            vis.insert((x, y));
            came_from[x][y] = d;
        }
    }

    return String::new();
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
