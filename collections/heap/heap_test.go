package heap_test

import (
	"math/rand"
	"testing"

	"github.com/haeramkeem/alGo/collections/heap"
)

/**
 * Test of MaxInt
 */
func TestMaxIntPush(t *testing.T) {
	test := heap.NewMaxInt(10)
	test.Push(2)
	test.Push(5)
	test.Push(1)
	test.Push(3)
	test.Push(8)
	test.Push(6)
	test.Push(7)
	test.Push(4)
	if test.Tail != 8 {
		t.Errorf("Want 9, got %d\n", test.Tail)
	}
	ans := []int{ 8, 5, 7, 4, 3, 1, 6, 2 }
	for i, v := range ans {
		if v != test.Tree[i] {
			t.Errorf("Want %d, got %d\n", v, test.Tree[i])
		}
	}
}

func TestMaxIntPop(t *testing.T) {
	test := new(heap.MaxInt)
	test.Tail = 8
	test.Tree = []int{ 8, 5, 7, 4, 3, 1, 6, 2 }
	for i := 0; i < 8 && 1 < test.Tail; i++ {
		if v, _ := test.Pop(); 8 - i != v {
			t.Errorf("Want %d, got %d\n", 8 - i, v)
		}
	}
}

func TestInitMaxInt(t *testing.T) {
	test := heap.InitMaxInt([]int{7, 6, 5, 8, 3, 5, 9, 1, 6})
	compareWith := []int{9, 8, 7, 6, 3, 5, 5, 1, 6}
	for i := 0; i < 9; i++ {
		if test.Tree[i] != compareWith[i] {
			t.Errorf("For index %d, want %d, got %d\n", i, compareWith[i], test.Tree[i])
		}
	}
}

/**
 * Benchmark of MaxInt
 */
func BenchmarkMaxIntPush(b *testing.B) {
	test := heap.NewMaxInt(b.N)
	for i := 0; i < b.N; i++ {
		test.Push(rand.Int())
	}
}

func BenchmarkMaxIntPop(b *testing.B) {
	test := heap.NewMaxInt(b.N)
	for i := 0; i < b.N; i++ {
		test.Push(rand.Int())
	}
	for i := 0; i < b.N; i++ {
		test.Pop()
	}
}

/**
 * Test of MinInt
 */
func TestMinIntPush(t *testing.T) {
	test := heap.NewMinInt(10)
	test.Push(2)
	test.Push(5)
	test.Push(1)
	test.Push(3)
	test.Push(8)
	test.Push(6)
	test.Push(7)
	test.Push(4)
	if test.Tail != 8 {
		t.Errorf("Want 9, got %d\n", test.Tail)
	}
	ans := []int{ 1, 3, 2, 4, 8, 6, 7, 5 }
	for i, v := range ans {
		if v != test.Tree[i] {
			t.Errorf("Want %d, got %d\n", v, test.Tree[i])
		}
	}
}

func TestMinIntPop(t *testing.T) {
	test := new(heap.MinInt)
	test.Tail = 8
	test.Tree = []int{ 1, 3, 2, 4, 8, 6, 7, 5 }
	for i := 1; i <= 8 && 1 < test.Tail; i++ {
		if v, _ := test.Pop(); i != v {
			t.Errorf("Want %d, got %d\n", i, v)
		}
	}
}

func TestInitMinInt(t *testing.T) {
	test := heap.InitMinInt([]int{7, 6, 5, 8, 3, 5, 9, 1, 6})
	compareWith := []int{1, 5, 7, 3, 6, 5, 9, 6, 8}
	for i := 0; i < 9; i++ {
		if test.Tree[i] != compareWith[i] {
			t.Errorf("For index %d, want %d, got %d\n", i, compareWith[i], test.Tree[i])
		}
	}
}

/**
 * Benchmark of MinInt
 */
func BenchmarkMinIntPush(b *testing.B) {
	test := heap.NewMinInt(b.N)
	for i := 0; i < b.N; i++ {
		test.Push(rand.Int())
	}
}

func BenchmarkMinIntPop(b *testing.B) {
	test := heap.NewMinInt(b.N)
	for i := 0; i < b.N; i++ {
		test.Push(rand.Int())
	}
	for i := 0; i < b.N; i++ {
		test.Pop()
	}
}