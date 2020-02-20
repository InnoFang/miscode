package mock

type Retriever struct {
	Contents string
}

// 只要实现了接口方法，就被认为实现了接口
func (r Retriever) Get(url string) string {
	return r.Contents
}