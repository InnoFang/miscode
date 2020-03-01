package core

import (
	"github.com/gpmgo/gopm/modules/log"
	"fmt"
)

type BlockChain struct {
	Blocks []*Block
}

func NewBlockChain() *BlockChain {
	genesisBlock := GenGenesisBlock()
	blockChain := BlockChain{}
	blockChain.AppendBlock(&genesisBlock)
	return &blockChain
}

func (bc *BlockChain) SendData(data string) {
	preBlock := bc.Blocks[len(bc.Blocks) - 1]
	newBlock := GenNewBlock(*preBlock, data)
	bc.AppendBlock(&newBlock)
}

func (bc *BlockChain) AppendBlock(newBlock *Block) {
	if len(bc.Blocks) == 0 {
		bc.Blocks = append(bc.Blocks, newBlock)
		return
	}
 	if isValid(*newBlock, *bc.Blocks[len(bc.Blocks)-1]) {
		bc.Blocks = append(bc.Blocks, newBlock)
	} else {
		log.Fatal("invalid block")
	}
}

func (bc *BlockChain) Print() {
	for _, block := range bc.Blocks {
		fmt.Println("Index:", block.Index)
		fmt.Println("Prev.Hash:", block.PrevBlockHash)
		fmt.Println("Curr.Hash:", block.Hash)
		fmt.Println("Data:", block.Data)
		fmt.Println("Timestamp:", block.Timestamp)
		fmt.Println()
	}
}

func isValid(newBlock Block, oldBlock Block) bool {
	if newBlock.Index-1 != oldBlock.Index {
		return false
	}

	if newBlock.PrevBlockHash != oldBlock.Hash {
		return false
	}

	if calculateHash(newBlock) != newBlock.Hash {
		return false
	}
	return true
}
