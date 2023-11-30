import argparse
import subprocess
import difflib


def get_diff(solution: str, target: str, test_case: str) -> str:
    test_input = test_case
    a = subprocess.run(f'echo "{test_input}" | {solution}',
                       stdout=subprocess.PIPE, shell=True)
    b = subprocess.run(f'echo "{test_input}" | {target}',
                       stdout=subprocess.PIPE, shell=True)

    dif = difflib.unified_diff(
        a.stdout.decode('utf-8').splitlines(keepends=True),
        b.stdout.decode('utf-8').splitlines(keepends=True),
        fromfile='solution',
        tofile='target',
    )

    return ''.join(dif) if dif else ''


def main():
    args = parse_args()
    print(f'Testing {args.solution} against {args.target}')

    wrong = 0
    for i in range(args.num):
        generator = subprocess.run(
            [args.generator, '-n', '1'],
            stdout=subprocess.PIPE,
        )
        if generator.returncode != 0:
            print(f'\nGenerator failed, exit code {generator.returncode}')
            continue

        test_case = generator.stdout.decode('utf-8')

        try:
            dif = get_diff(args.solution, args.target, test_case)
            if not dif:
                print(f'Passed test case {i}', end='\r', flush=True)
                continue

            print(f'\nFailed on test case {i}')
            with open(f'failed-{wrong}.txt', 'w') as f:
                f.write(test_case)
            with open(f'failed-{wrong}.dif', 'w') as f:
                f.write(dif)

            wrong += 1
            if wrong >= args.wrong:
                break
        except KeyboardInterrupt:
            print(f'\nStopped after {i} test cases, last one was:')
            print(test_case)
            exit()

    if wrong:
        print(f'\nFailed {wrong} test cases')
    else:
        print(f'\nPassed {args.num} test cases')


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('-g', '--generator', type=str, default='./generator',
                        help='Generator to generate test cases')
    parser.add_argument('-s', '--solution', type=str, default='./a',
                        help='Solution that works')
    parser.add_argument('-t', '--target', type=str, default='./brute',
                        help='Target solution to check against')
    parser.add_argument('-n', '--num', type=int, default=500,
                        help='Number of test cases to generate')
    parser.add_argument('-w', '--wrong', type=int, default=10,)
    return parser.parse_args()


if __name__ == '__main__':
    main()
