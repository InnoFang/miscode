package registry

// register log service

type ServiceName string

type Registration struct {
	ServiceName
	ServiceURL string
	RequiredServices []ServiceName
	ServiceUpdateURL string
}

const (
	LogService = ServiceName("LogService")
	GradingService = ServiceName("GradingService")
)

type patchEntry struct {
	Name ServiceName
	URL string
}

type patch struct {
	Added []patchEntry
	Removed []patchEntry
}