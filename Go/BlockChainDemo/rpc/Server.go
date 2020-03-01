package main

import (
	"LearnGo/BlockChainDemo/core"
	"net/http"
	"encoding/json"
	"io"
)

var blockChain *core.BlockChain

func run() {
	http.HandleFunc("/blockchain/get", blockChainGetHandler)
	http.HandleFunc("/blockchain/write", blockChainWriteHandler)
	http.ListenAndServe("localhost:8888", nil)
}

func blockChainGetHandler(writer http.ResponseWriter, request *http.Request) {
	ctn, err := json.Marshal(blockChain)
	if err != nil {
		http.Error(writer, err.Error(), http.StatusInternalServerError)
		return
	}
	io.WriteString(writer, string(ctn))
}

func blockChainWriteHandler(writer http.ResponseWriter, request *http.Request) {
	blockData := request.URL.Query().Get("data")
	blockChain.SendData(blockData)
	blockChainGetHandler(writer, request)

}

func main() {
	blockChain = core.NewBlockChain()
	run()
}