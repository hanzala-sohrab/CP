package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	var t, n int
	in := bufio.NewReader(os.Stdin)
	fmt.Fscan(in, &t)
	i := 0
	for i < t {
		fmt.Fscan(in, &n)
		a := make([]int, n)
		j := 0
		for j < n {
			fmt.Fscan(in, &a[j])
			j++
		}
		sort.Ints(a)
		if a[0]%2 == 1 {
			fmt.Println("YES")
			i++
			continue
		}
		j = 0
		possible := true
		for j < n {
			if a[j]%2 == 1 {
				possible = false
				break
			}
			j++
		}
		if possible {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
		i++
	}
}
