# PrintRange

Lets you input two numbers and prints the range in between. Ascending or descending.

Two integers are read from standard input, and every integer from the first to the second is
printed, **inclusive**, one per line:

- ascending when the first number is smaller than the second,
- descending when the first number is larger than the second,
- the number by itself when the two are equal.

The whole program is a single file, `printRange.cpp`.

## Build

```
make
```

The binary is written to `printRange` in the repository root. The `Makefile` records the build
that everything else in this repository assumes:

```
g++ -std=c++17 -Wall -Wextra -o printRange printRange.cpp
```

`make clean` removes the binary. The compiled artifact is covered by `.gitignore` and is never
committed.

## Run

A prompt is printed for each of the two numbers and each number is read from standard input, so
running the binary with a terminal attached makes it wait for input rather than print anything
useful on its own. Input is supplied by piping it in:

```
printf '%s\n' 1 5 | ./printRange
```

The `printf '%s\n' <first> <last>` form is used rather than `printf '<first>\n<last>\n'` because
a negative endpoint written the second way is parsed by `printf` as an option.

Each number must be readable as an `int`. If either is not — a word, a number with other
characters attached such as `5abc` or `1.5`, a value outside the range of `int`, or no input at
all — a message naming that number is printed to standard error, no range is printed, and the
program exits with status 1. Either endpoint may be the largest or smallest value of `int`; the
range still ends on it.

## Example

Ascending:

```
$ printf '%s\n' 1 5 | ./printRange
What is the first number in the range?
What is the last number in the range?
1
2
3
4
5
```

Descending:

```
$ printf '%s\n' 5 1 | ./printRange
What is the first number in the range?
What is the last number in the range?
5
4
3
2
1
```

Equal endpoints:

```
$ printf '%s\n' 3 3 | ./printRange
What is the first number in the range?
What is the last number in the range?
3
```

Crossing zero:

```
$ printf '%s\n' -2 2 | ./printRange
What is the first number in the range?
What is the last number in the range?
-2
-1
0
1
2
```

Unreadable input:

```
$ printf '%s\n' 3 xyz | ./printRange
What is the first number in the range?
What is the last number in the range?
The last number could not be read as an integer.
$ echo $?
1
```

Both prompts are printed on standard output ahead of the range, so the first two lines of every
session are prompts. A wide range is therefore counted with the prompts dropped — 1 through 100
inclusive leaves 100 lines:

```
$ printf '%s\n' 1 100 | ./printRange | tail -n +3 | wc -l
100
```

## Continuous integration

The `build` workflow in `.github/workflows/build.yml` builds the program with `make` on every
push to `master` and on every pull request, then checks the output of each branch above against
a literal expected block (including ranges that end on the largest and smallest `int`), that
unreadable input is rejected with status 1 and the expected message, the line count of the
1-through-100 range, and that `make clean` removes the binary.

## License

Stephenson Software Non-Commercial License. See [LICENSE](LICENSE).
