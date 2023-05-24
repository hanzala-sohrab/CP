package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	var t int
	fmt.Fscan(in, &t)
	i := 0
	for i < t {
		var n int
		var s string
		m := make(map[string]int)
		fmt.Fscan(in, &n)
		fmt.Fscan(in, &s)
		j := 0
		cnt := 0
		for j < n-1 {
			melody := s[j : j+2]
			if m[melody] == 0 {
				cnt += 1
				m[melody] = 1
			}
			j += 1
		}
		fmt.Println(cnt)
		i += 1
	}
}
