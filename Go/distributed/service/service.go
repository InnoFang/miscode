package service

import (
	"context"
	"distributed/registry"
	"fmt"
	"log"
	"net/http"
)

func Start(ctx context.Context, host, port string, reg registry.Registration,
	registerHandlersFunc func()) (context.Context, error) {
	registerHandlersFunc()
	ctx = startService(ctx, reg.ServiceName, host, port)

	err := registry.RegisterService(reg)
	if err != nil {
		return ctx, err
	}
	return ctx, nil
}

func startService(ctx context.Context, serviceName registry.ServiceName, host, port string) context.Context {
	ctx, cancel := context.WithCancel(ctx)

	var srv http.Server
	// configure server address
	srv.Addr = ":" + port


	go func() {
		// If occur some errors when launching the service, print error message
		log.Println(srv.ListenAndServe())

		// and cancel this service
		err := registry.ShutdownService(fmt.Sprintf("http://%s:%s", host, port))
		if err != nil {
			log.Println(err)
		}
		cancel()
	} ()

	go func() {
		// Client can cancel this service manually
		fmt.Println(serviceName, "started. Press any key to stop.")

		// Press any key to continue, otherwise always waiting for client to input
		var s string
		fmt.Scanln(&s)

		// shutdown this service
		err := registry.ShutdownService(fmt.Sprintf("http://%s:%s", host, port))
		if err != nil {
			log.Println(err)
		}
		srv.Shutdown(ctx)
		cancel()
	} ()

	return ctx
}


