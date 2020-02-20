package main

import (
	"net/http"
	"LearnGo/filelistingserver/filelisting"
	"os"
	"github.com/gpmgo/gopm/modules/log"
)

type userError interface {
	error
	Message() string
}

type appHandler func(writer http.ResponseWriter, request *http.Request) error

func errWrapper(handler appHandler) func(w http.ResponseWriter, r *http.Request) {
	return func(writer http.ResponseWriter, request *http.Request) {
		err := handler(writer, request)
		defer func() {
			r := recover()
			log.Warn("panic: %v", r)
			http.Error(writer,
				http.StatusText(http.StatusInternalServerError),
					http.StatusInternalServerError)
		}()
		if err != nil {
			log.Warn("Error handling request: %s", err.Error())

			if userErr, ok := err.(userError); ok {
				http.Error(writer,
					userErr.Message(),
						http.StatusBadRequest)
				return
			}

			code := http.StatusOK
			switch {
			case os.IsNotExist(err):
				code = http.StatusNotFound
			case os.IsPermission(err):
				code = http.StatusForbidden
			default:
				code = http.StatusInternalServerError
			}
			http.Error(writer, http.StatusText(code), code)
		}
	}
}

func main() {
	http.HandleFunc("/list/", errWrapper(filelisting.HandleFileList))

	err := http.ListenAndServe(":8899", nil)
	if err != nil {
		panic(err)
	}
}
