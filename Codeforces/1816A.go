package main

import "fmt"

func main() {
	var t, a, b int
	fmt.Scan(&t)
	i := 0
	for i < t {
		fmt.Scan(&a, &b)
		fmt.Println(2)
		fmt.Printf("%d %d\n", a-1, 1)
		fmt.Printf("%d %d\n", a, b)
		i++
	}
}
