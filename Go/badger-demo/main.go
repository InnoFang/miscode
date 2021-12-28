package main

import (
	"log"
	"github.com/Connor1996/badger"
)

func main() {
	opts := badger.DefaultOptions
	opts.Dir = "./badger"
	opts.ValueDir = "./badger"
	db, err := badger.Open(opts)
	if err != nil {
		log.Fatalln(err)
	}
	defer db.Close()
}