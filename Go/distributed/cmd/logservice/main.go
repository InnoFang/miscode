package main

import (
	"context"
	"distributed/log"
	"distributed/registry"
	"distributed/service"
	"fmt"
	stlog "log"
)

func main() {
	log.Run("./distributed.log")
	host, port := "localhost", "4000"

	serviceAddress := fmt.Sprintf("http://%s:%s", host, port)
	r := registry.Registration{
		ServiceName: "Log Service",
		ServiceURL: serviceAddress,
	}

	ctx, err := service.Start(
		context.Background(),
		host,
		port,
		r,
		log.RegisterHandlers,
	)

	if err != nil {
		// If the custom log service doesn't launch successfully, use the standard log supported by Go
		stlog.Fatalln(err)
	}

	// when getting the cancel signal from the goroutines, end log service
	<- ctx.Done()
	fmt.Println("Shutting down log service.")
}