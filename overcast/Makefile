# tool macros
GO ?= go build
GOFLAGS := "" # FILL: compile flags


# compile macros
TARGET_OS := ""

ifeq ($(OS),Windows_NT)
	$(TARGET_OS) = windows
else ifeq ($(OS),Darwin)
	$(TARGET_OS) = darwin
else
	$(TARGET_OS) = linux
endif


# default rule
default: build

.PHONY: build
build: $(GO) main.go

.PHONY: build windows
build windows: GOOS=windows $(GO) main.go

.PHONY: debug
debug: $(GO) $()

.PHONY: clean
clean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -f $(CLEAN_LIST)
