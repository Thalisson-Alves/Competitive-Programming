use std::{
    fmt::Debug,
    io::{BufRead, Lines, StdinLock},
    str::FromStr,
};

fn main() {
    let mut reader = Reader::new(std::io::stdin().lock().lines());
    let (n, m): (usize, usize) = reader.pair();
    let mut ufds = UFDS::new(n);
    for _ in 0..m {
        let (a, b): (usize, usize) = reader.pair();
        ufds.union_set(a - 1, b - 1);
    }

    let ans = solve(ufds);
    println!("{}", ans.len());
    for (x, y) in ans {
        println!("{} {}", x+1, y+1);
    }
}

fn solve(ufds: UFDS) -> Vec<(usize, usize)> {
    return ufds
        .founders()
        .zip(ufds.founders().skip(1))
        .map(|(&a, &b)| (a, b))
        .collect();
}

struct UFDS {
    parents: Vec<usize>,
    sizes: Vec<usize>,
}

impl UFDS {
    fn new(n: usize) -> UFDS {
        return UFDS {
            parents: (0..n).collect(),
            sizes: vec![1; n],
        };
    }

    fn find_set(&mut self, x: usize) -> usize {
        if self.parents[x] == x {
            return x;
        }

        self.parents[x] = self.find_set(self.parents[x]);
        return self.parents[x];
    }

    fn same_set(&mut self, a: usize, b: usize) -> bool {
        return self.find_set(a) == self.find_set(b);
    }

    fn union_set(&mut self, a: usize, b: usize) {
        let mut a = self.find_set(a);
        let mut b = self.find_set(b);

        if a == b {
            return;
        }

        if self.sizes[a] > self.sizes[b] {
            (a, b) = (b, a);
        }

        self.parents[a] = b;
        self.sizes[b] += self.sizes[a];
    }

    fn founders(&self) -> impl std::iter::Iterator<Item = &usize> {
        return self
            .parents
            .iter()
            .enumerate()
            .filter(|(i, &x)| x == *i)
            .map(|(_, x)| x);
    }
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
}
