import argparse
from collections.abc import Callable
from pathlib import Path
from typing import Iterable


def get_markdown_for(
    base_dir: Path, should_be_link: Callable[[Path], bool]
) -> Iterable[str]:
    """Generate markdown for a directory tree.

    Args:
        base_dir: The base directory.
        should_be_link: A function that returns whether a path should be a link.

    Returns:
        An iterable of strings containing the markdown for the directory tree.
    """

    base_dir = base_dir.resolve()
    assert base_dir.is_dir(), f"{base_dir} is not a directory"

    space_chars = "_-"

    def helper(path: Path, depth=0) -> Iterable[str]:
        # skip first level
        if depth == 0:
            for child in sorted(path.iterdir()):
                yield from helper(child, depth + 1)
            return

        name = path.stem
        for char in space_chars:
            name = name.replace(char, " ")
        name = name.title()
        if path.suffix and path.suffix != ".cpp":
            name += f" ({path.suffix[1:]})"

        if should_be_link(path):
            yield f"- [{name}]({path.relative_to(base_dir.parent)})"
        elif path.is_dir():
            yield f"\n{'#' * (depth + 2)} {name}\n"

            for child in sorted(path.iterdir()):
                yield from helper(child, depth + 1)

    return helper(base_dir)


README_TEMPLATE = """# Competitive Programming

Welcome to my Competitive Programming repository! This collection includes implementations of various algorithms relevant to Competitive Programming (CP) and my submissions to online judges. Whether you're a beginner looking to learn new algorithms or an experienced coder seeking efficient implementations, this repository aims to be a valuable resource for your CP journey.

## Algorithms

The `code` directory is organized into various subdirectories, each focusing on a specific category of algorithms. Here's a breakdown of the available algorithms:

{ALGORITHMS_SECTION}

## Submissions

The `submissions` directory holds my accepted submissions to different online judges. Each problem is labeled with its respective judge and problem ID.

Reviewing these submissions can provide insights into different problem-solving techniques, optimization strategies, and coding styles. It's a great way to learn from both successful and unsuccessful attempts.

{SUBMISSIONS_SECTION}

## Contributing

If you find a bug or want to add a new algorithm, feel free to open an issue or submit a pull request. I'm always looking to improve my code!

- **Obs 1:** If you want to add a new algorithm, please make sure to include a link to the problems you used to test it.
- **Obs 2:** You don't need to add a new algorithm to the README. The script `generate_readme.py` will do it for you.

## References

### Resources

Enhance your Competitive Programming skills with the following valuable resources:

- [TEP](https://github.com/edsomjr/TEP)
- [Algorithms for Competitive Programming](https://cp-algorithms.com/)
- [USACO Guide](https://usaco.guide/)
- [Competitive Programing Book](https://cpbook.net/details?cp=4)
- [Competitive Programmer's Handbook](https://cses.fi/book/book.pdf)

### Other Repositories

Explore additional repositories with extensive algorithm implementations:

- [UFMG Lib](https://github.com/brunomaletta/Biblioteca)
- [Iagorrr's Lib](https://github.com/iagorrr/Competitive-Programming-Algorithms)
"""


def main(args: argparse.Namespace):
    with open(args.readme_path, "w") as f:
        f.write(
            README_TEMPLATE.format(
                ALGORITHMS_SECTION="\n".join(
                    get_markdown_for(args.code_dir, Path.is_file)
                ),
                SUBMISSIONS_SECTION="\n".join(
                    # Stop at the first level of directories
                    get_markdown_for(args.submissions_dir, Path.is_dir)
                ),
            ).replace("\n\n\n", "\n\n")
        )


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate README.md")
    parser.add_argument(
        "--code-dir",
        type=Path,
        default=Path(__file__).parent.parent / "code",
        help="Path to the algorithms directory. (default: %(default)s)",
    )
    parser.add_argument(
        "--submissions-dir",
        type=Path,
        default=Path(__file__).parent.parent / "submissions",
        help="Path to the submissions directory. (default: %(default)s)",
    )
    parser.add_argument(
        "--readme-path",
        type=Path,
        default=Path(__file__).parent.parent / "README.md",
        help="Path to the README.md file. (default: %(default)s)",
    )
    args = parser.parse_args()

    main(args)
