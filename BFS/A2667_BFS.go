/**
 * https://www.acmicpc.net/problem/2667
 *
 * BFS + Stack
 */

package main

import (
	"fmt"
	"sort"
	"strings"
)

type XY struct {
	x	int
	y	int
}

func xy(xx int, yy int) XY {
	return XY{x: xx, y: yy,}
}

func pop(list []XY) (int, int, []XY) {
	if len(list) < 1 { return -1, -1, nil }
	temp := list[len(list) - 1]
	return temp.x, temp.y, list[:len(list) - 1]
}

func around(board [][]string, x int, y int) []XY {
	size := len(board)
	res := make([]XY, 0)
	if x + 1 < size && board[x + 1][y] == "1" {res = append(res, xy(x + 1, y))}
	if x - 1 > -1 && board[x - 1][y] == "1" {res = append(res, xy(x - 1, y))}
	if y + 1 < size && board[x][y + 1] == "1" {res = append(res, xy(x, y + 1))}
	if y - 1 > -1 && board[x][y - 1] == "1" {res = append(res, xy(x, y - 1))}
	return res
}

func main() {
	var rowNum int
	fmt.Scan(&rowNum)

	if rowNum == 0 {
		fmt.Println(0)
		return
	}

	var buf string
	coor := make([][]string, rowNum)
	for i := 0; i < rowNum; i++ {
		fmt.Scan(&buf)
		coor[i] = strings.Split(buf, "")
	}

	result := make([]int, 0)
	for x, xSlice := range coor {
		for y, cell := range xSlice {
			if cell == "1" {
				chunk := make([]XY, 0)
				cnt := 0
				chunk = append(chunk, xy(x, y))
				for {
					xx, yy, poped := pop(chunk)
					if poped != nil {
						chunk = append(poped, around(coor, xx, yy)...)
						if coor[xx][yy] == "1" {
							coor[xx][yy] = ""
							cnt++
						}
					} else {
						break
					}
				}
				result = append(result, cnt)
			}
		}
	}

	sort.Ints(result)
	fmt.Println(len(result))
	for _, item := range result {
		fmt.Println(item)
	}
}