package main

import (
    "fmt"
    "reflect"
)

func main() {
    // reflect.DeepEqual() compares two elements of any type recursively
    reflect.DeepEqual([]int{ 1, 2, 3 }, []int{ 1, 2, 3}) // true

    // But it cannot compare the empty slice
    reflect.DeepEqual(nil, make([]int, 0)) // false
}
