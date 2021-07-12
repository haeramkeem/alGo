package main

import (
	"fmt"
	"strings"
)

func dial(c string) int {
	if c == "A" || c == "B" || c == "C" {return 3}
	if c == "D" || c == "E" || c == "F" {return 4}
	if c == "G" || c == "H" || c == "I" {return 5}
	if c == "J" || c == "K" || c == "L" {return 6}
	if c == "M" || c == "N" || c == "O" {return 7}
	if c == "P" || c == "Q" || c == "R" || c == "S" {return 8}
	if c == "T" || c == "U" || c == "V" {return 9}
	if c == "W" || c == "X" || c == "Y" || c == "Z" {return 10}
	return 0
}

func main() {
	var input []string
	var temp string
	fmt.Scan(&temp)
	input = strings.Split(temp, "")

	output := 0
	for _, c := range input {
		output += dial(c)
	}
	fmt.Println(output)
}