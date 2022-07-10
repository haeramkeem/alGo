package refs

import (
	"bufio"
	"fmt"
	"os"
)

func BufioRef() {
	//Using stdin buf
	stdin := bufio.NewReader(os.Stdin)
	var n int; var s string
	fmt.Fscan(stdin, &n, &s)

	//Using stdout buf
	stdout := bufio.NewWriter(os.Stdout); defer stdout.Flush()
	fmt.Fprintln(stdout, n, s)
}