package refs

import (
	"fmt"
	"sort"
)

type By func(s1, s2 *[]int) bool

type DataSorter struct {
	data	[][]int
	by		func(s1, s2 *[]int) bool
}

func (d *DataSorter) Len() int {
	return len(d.data)
}

func (d *DataSorter) Less(i, j int) bool {
	return d.by(&d.data[i], &d.data[j]) // by 함수로 대소관계 판단
}

func (d *DataSorter) Swap(i, j int) {
	d.data[i], d.data[j] = d.data[j], d.data[i] // 데이터 위치를 바꿈
}

func (by By) Sort(data [][]int) {
	sorter := &DataSorter{
		data: data,
		by: by,
	}
	sort.Sort(sorter)
}

func KeySortRef() {
	a := make([][]int, 3)
	a[0] = []int{1}
	a[2] = []int{2, 3}
	a[1] = []int{4, 5, 6}

	criteria := func(s1, s2 *[]int) bool {
		return len(*s1) > len(*s2)
	}

	By(criteria).Sort(a)
	fmt.Println(a)
}