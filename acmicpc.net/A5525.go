package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	stdin := bufio.NewReader(os.Stdin)
	var n, m int; var s string
	fmt.Fscan(stdin, &n, &m, &s);

	output := 0
	for i := 0; i < m - 2; i++ {
		if s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I' {
			var ptr int
			for ptr = i + 1; ptr + 3 < m && s[ptr + 2] == 'O' && s[ptr + 3] == 'I'; ptr += 2 {}
			if ptr + 1 - i >= 2 * n {output += 1 + (ptr + 1 - i - 2 * n) / 2}
			i = ptr + 1
		}
	}

	stdout := bufio.NewWriter(os.Stdout); defer stdout.Flush()
	fmt.Fprintln(stdout, output)
}