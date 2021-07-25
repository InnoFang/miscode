package registry

// register log service

type ServiceName string

type Registration struct {
	ServiceName
	ServiceURL string
}

const (
	LogService = ServiceName("LogService")
)