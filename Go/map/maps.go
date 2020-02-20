package _map

import "fmt"

func main() {
	m := map[string]string {
		"name" : "Inno",
		"id" : "1234",
		"gender" : "male",
	}
	fmt.Println(m)

	for k, v := range m {
		fmt.Println(k, v)
	}

	// 获取元素
	name := m["name"]
	fmt.Println(name)

	// 判断元素是否存在
	if age, ok := m["age"]; ok {
		fmt.Println("age:", age)
	} else {
		fmt.Println("There is not a key called age!")
	}


}
