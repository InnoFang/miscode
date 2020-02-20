package main

import (
	"regexp"
	"fmt"
)

const text = `
This is a email: abc123@haha.com, 
but this is not: aa@123
more example:
666#123.com
ok@com
bar@foo.org
kk@jj.ii
long@time.no.see
`

func main() {
	re := regexp.MustCompile(`([a-zA-Z0-9]+)@(.+)\.([a-zA-Z0-9]+)`)
	match := re.FindAllStringSubmatch(text, -1)
	for _, m := range match {
		fmt.Println(m)
	}
}
