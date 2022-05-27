package main

import (
    "fmt"
)

func main() {
    slice := &[]int{ 1, 2, 3 }

    fmt.Println(*slice[0]) // This is an error
    fmt.Println((*slice)[0]) // This is a correct usage
}
