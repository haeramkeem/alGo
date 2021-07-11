package main

import (
	"fmt"
	"strings"
)

type XY struct {
	x, y	int
}

func new(xx, yy int) XY {
	return XY{x: xx, y: yy}
}

func edge(m [][]string, x, y int) bool {
	if (x == 0 && y == 0) || (x == 0 && y == 9) || (x == 9 && y == 0) || (x == 9 && y == 9) {return true}
	if (x < 9 && 0 < y && y < 9 && m[x][y - 1] == "1" && m[x][y + 1] == "1" && m[x + 1][y - 1] == "0" && m[x + 1][y] == "1" && m[x + 1][y + 1] == "0") ||
		(x > 0 && 0 < y && y < 9 && m[x][y - 1] == "1" && m[x][y + 1] == "1" && m[x - 1][y - 1] == "0" && m[x - 1][y] == "1" && m[x - 1][y + 1] == "0") ||
		(y < 9 && 0 < x && x < 9 && m[x - 1][y] == "1" && m[x + 1][y] == "1" && m[x - 1][y + 1] == "0" && m[x][y + 1] == "1" && m[x + 1][y + 1] == "0") ||
		(y > 0 && 0 < x && x < 9 && m[x - 1][y] == "1" && m[x + 1][y] == "1" && m[x - 1][y - 1] == "0" && m[x][y - 1] == "1" && m[x + 1][y - 1] == "0") {return false}
	cnt := 0
	if x == 0 || y == 0 || m[x - 1][y - 1] == "0" {cnt++}
	if x == 0 || m[x - 1][y] == "0" {cnt++}
	if x == 0 || y == 9 || m[x - 1][y + 1] == "0" {cnt++}
	if x == 9 || y == 0 || m[x + 1][y - 1] == "0" {cnt++}
	if x == 9 || m[x + 1][y] == "0" {cnt++}
	if x == 9 || y == 9 || m[x + 1][y + 1] == "0" {cnt++}
	if y == 0 || m[x][y - 1] == "0" {cnt++}
	if y == 9 || m[x][y + 1] == "0" {cnt++}
	return cnt >= 5
}

func main() {
	input := make([][]string, 10)
	var temp string
	for i := 0; i < 10; i++ {
		fmt.Scan(&temp)
		input[i] = strings.Split(temp, "")
	}

	edges := make([]XY, 0)
	for x, xSlice := range input {
		for y, cell := range xSlice {
			if cell == "1" {
				if edge(input, x, y) {
					edges = append(edges, new(x, y));
				}
			}
		}
	}
	
	if len(edges) != 3 {fmt.Println(0); return}

	for i := 0; i < 3; i++ {
		for j := i + 1; j < 3; j++ {
			if edges[i].x == edges[j].x {
				h := edges[i].x
				var l, r int
				if edges[i].y < edges[j].y {
					l = edges[i].y; r = edges[j].y
				} else {
					l = edges[j].y; r = edges[i].y
				}
				var lp, rp, hp int
				if edges[3 - i - j].x > edges[i].x {hp = 1} else {hp = -1}
				if l < edges[3 - i - j].y && edges[3 - i - j].y < r {
					lp = 1; rp = -1
				} else if edges[3 - i - j].y == l {
					lp = 0; rp = -1
				} else if edges[3 - i - j].y == r {
					lp = 1; rp = 0
				} else {
					fmt.Println(0); return
				}
				for l < r {
					for iter := l; iter < r + 1; iter++ {
						if input[h][iter] != "1" {fmt.Println(0); return}
					}
					h += hp; r += rp; l += lp
				}
				fmt.Println(edges[0].x + 1, edges[0].y + 1)
				fmt.Println(edges[1].x + 1, edges[1].y + 1)
				fmt.Println(edges[2].x + 1, edges[2].y + 1)
				return
			}else if edges[i].y == edges[j].y {
				var d, t int
				if edges[i].x < edges[j].x {
					d = edges[i].x; t = edges[j].x
				} else {
					d = edges[j].x; t = edges[i].x
				}
				h := edges[i].y; var hp int
				if d < edges[3 - i - j].x && edges[3 - i - j].x < t {
					if edges[i].y < edges[3 - i - j].y {hp = 1} else {hp = -1}
				}
				for d < t{
					for iter := d; iter < t + 1; iter++ {
						if input[iter][h] != "1" {fmt.Println(0); return}
					}
					h += hp; d++; t--
				}
				fmt.Println(edges[0].x + 1, edges[0].y + 1)
				fmt.Println(edges[1].x + 1, edges[1].y + 1)
				fmt.Println(edges[2].x + 1, edges[2].y + 1)
				return
			}
		}
	}
}

/*
001 100
011 110
111 111

001 100
011 110
111 111
011 110
001 100

00100
01110
11111
*/

/*
111 111
011 110
001 100

11111
01110
00100
*/

/*
		"0000000000",
		"0000000000",
		"0000000000",
		"0000000000",
		"0000000000",
		"0111111111",
		"0011111110",
		"0001111100",
		"0000111000",
		"0000010000",

		"0000000000",
		"0000010000",
		"0000111000",
		"0001111100",
		"0011111110",
		"0111111111",
		"0000000000",
		"0000000000",
		"0000000000",
		"0000000000",
*/

// buf := []string{
// 	"0000000000",
// 	"0000000000",
// 	"0011111100",
// 	"0000000100",
// 	"0000000100",
// 	"0000000100",
// 	"0000000100",
// 	"0000000000",
// 	"0000000000",
// 	"0000000000",
// }
// input := make([][]string, 10)
// for i, line := range buf {
// 	input[i] = strings.Split(line, "")
// }