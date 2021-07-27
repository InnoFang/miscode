package main

import (
	"bytes"
	"container/heap"
	"fmt"
	"strconv"
	"strings"
)

// URLTop10 .
func URLTop10(nWorkers int) RoundsArgs {
	// YOUR CODE HERE :)
	// And don't forget to document your idea.

	var args RoundsArgs

	args = append(args, RoundArgs{
		MapFunc:    URLCountMap,
		ReduceFunc: URLCountReduce,
		NReduce:    nWorkers,
	})

	args = append(args, RoundArgs{
		MapFunc:    URLTop10Map,
		ReduceFunc: URLTop10Reduce,
		NReduce:    1,
	})

	return args
}

func URLCountMap(filename string, contents string) []KeyValue {
	lines := strings.Split(contents, "\n")
	counter := make(map[string]int)
	for _, line := range lines {
		line = strings.TrimSpace(line)
		if len(line) == 0 {
			continue
		}
		counter[line] += 1
	}
	kvs := make([]KeyValue, 0, len(lines))
	for k, v := range counter {
		kvs = append(kvs, KeyValue{Key: k, Value: strconv.Itoa(v)})
	}
	return kvs
}

func URLCountReduce(key string, values []string) string {
	sum := 0
	for _, val := range values {
		v, err := strconv.Atoi(val)
		if err != nil {
			panic(err)
		}
		sum += v
	}
	return fmt.Sprintf("%s %s\n", key, strconv.Itoa(sum))
}

func URLTop10Map(filename, contents string) []KeyValue {
	mh := &MinHeap{}
	heap.Init(mh)

	lines := strings.Split(contents, "\n")
	for _, line := range lines {
		tmp := strings.Split(line, " ")
		if len(tmp) < 2 {
			continue
		}
		key, value_s := tmp[0], tmp[1]
		value_i, err := strconv.Atoi(value_s)
		if err != nil {
			panic(err)
		}
		heap.Push(mh, &Item{key, value_i})

		if mh.Len() > 10 {
			heap.Pop(mh)
		}
	}

	kvs := make([]KeyValue, 0, len(lines))
	for mh.Len() > 0 {
		item := heap.Pop(mh).(*Item)
		content := fmt.Sprintf("%v %v\n", item.Key, item.Value)
		kvs = append(kvs, KeyValue{"", content})
	}
	return kvs
}

func URLTop10Reduce(key string, values []string) string {
	mh := &MinHeap{}
	heap.Init(mh)

	for _, v := range values {
		v := strings.TrimSpace(v)
		if len(v) == 0 {
			continue
		}
		tmp := strings.Split(v, " ")
		key, value_s := tmp[0], tmp[1]
		value_i, err := strconv.Atoi(value_s)
		if err != nil {
			panic(err)
		}
		heap.Push(mh, &Item{key, value_i})

		if mh.Len() > 10 {
			heap.Pop(mh)
		}
	}

	top10item := make([]*Item, 0, 10)
	for mh.Len() > 0 {
		item := heap.Pop(mh).(*Item)
		top10item = append(top10item, item)
	}

	buf := new(bytes.Buffer)
	for i := len(top10item) - 1; i >= 0; i-- {
		k, v := top10item[i].Key, top10item[i].Value
		fmt.Fprintf(buf, "%s: %d\n", k, v)
	}
	return buf.String()
}

type Item struct {
	Key   string
	Value int
}

type MinHeap []*Item

func (mh MinHeap) Len() int      { return len(mh) }
func (mh MinHeap) Swap(i, j int) { mh[i], mh[j] = mh[j], mh[i] }
func (mh MinHeap) Less(i, j int) bool {
	if mh[i].Value == mh[j].Value {
		return mh[i].Key > mh[j].Key
	}
	return mh[i].Value < mh[j].Value
}
func (mh *MinHeap) Push(x interface{}) { *mh = append(*mh, x.(*Item)) }
func (mh *MinHeap) Pop() interface{} {
	old := *mh
	n := len(old)
	x := old[n-1]
	old[n-1] = nil
	*mh = old[0 : n-1]
	return x
}
