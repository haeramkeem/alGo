package main

import "fmt"

func findMax(input []int) (int, int) {
	max := -2147483648
	index := -1
	for i, v := range input {
		if v > max { max = v; index = i }
	}

	return max, index
}

func main() {
	var h, w int
	fmt.Scan(&h, &w)
	input := make([]int, w)
	max := -2147483648
	maxIdx := -1
	for i := range input {
		fmt.Scan(&input[i])
		if input[i] > max { max = input[i]; maxIdx = i }
	}

	output := 0
	r := maxIdx
	for {
		if r < 1 { break }
		lh, l := findMax(input[:r])
		for i := l + 1; i < r; i++ {
			output += lh - input[i]
		}
		r = l
	}
	l := maxIdx + 1
	for {
		if l > w - 2 { break }
		rh, r := findMax(input[l:])
		for i := l; i < r + l; i++ {
			output += rh - input[i]
		}
		l = r + l + 1
	}

	fmt.Println(output)
}