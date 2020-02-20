package main

import (
	"LearnGo/interfaces/real"
	"LearnGo/interfaces/mock"
	"fmt"
)

type Retriever interface {
	Get(url string) string
}

func download(r Retriever) string {
	return r.Get("https://www.baidu.com")
}

func main() {
	var r Retriever
	//r = mock.Retriever{"this is a fake imooc.com"}
	r = &real.Retriever{}

	switch v := r.(type) { // 获取类型
	case mock.Retriever:
		fmt.Println("Contents: ", v.Contents)
	case *real.Retriever:
		fmt.Println("UserAgent: ", v.UserAgent)
	}

	if mockRetriever, ok := r.(mock.Retriever); ok {
		fmt.Println(mockRetriever.Contents)
	} else {
		fmt.Println("not a mock")
	}
	//fmt.Println(download(r))
}
