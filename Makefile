# Compilador
CXX = g++
# Flags de compilación
CXXFLAGS = -Wall -std=c++11
# Directorios de los headers
INCDIR = -Isrc

# Directorios para los binarios y objetos
BINDIR = bin
OBJDIR = bin/obj

# Archivos fuente del directorio src y raíz
SRCS = $(shell find src -name '*.cpp')
SRCS_APP = $(SRCS)
SRCS_APP += app.cpp
SRCS_TESTS = $(shell find tests -name '*.cpp')

# Objetos
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)
OBJS_APP = $(SRCS_APP:%.cpp=$(OBJDIR)/%.o)
OBJS_TESTS = $(SRCS_TESTS:%.cpp=$(OBJDIR)/%.o)

# Nombre del ejecutable
EXEC = $(BINDIR)/app.sh
EXEC_TESTS = $(BINDIR)/tests.sh

#rule to compile .cpp into .o files
$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCDIR) -c $< -o $@


.DEFAULT_GOAL := help

## —— 📦 Makefile 📦 —————————————————————————————————————————
help: ## Outputs this help screen
	@grep -E '(^[a-zA-Z0-9_-]+:.*?##.*$$)|(^##)' Makefile | awk 'BEGIN {FS = ":.*?## "}{printf "\033[32m%-30s\033[0m %s\n", $$1, $$2}' | sed -e 's/\[32m##/[33m/'

createFolders: ## Creates compiling folders
	$(shell mkdir -p $(BINDIR) $(OBJDIR))
	$(shell mkdir -p $(addprefix $(OBJDIR)/,$(dir $(SRCS))))
	$(shell mkdir -p $(addprefix $(OBJDIR)/,$(dir $(SRCS_TESTS))))

clean:## clean bin/*
	rm -rf $(OBJDIR) $(BINDIR)
## —— Tests commands —————————————————————————————————————————
buildTests: clean createFolders $(OBJS) $(OBJS_TESTS) ## Builds the Tests
	$(CXX) $(CXXFLAGS) -o $(EXEC_TESTS) $(OBJS) $(OBJS_TESTS)

runTests: buildTests ## Builds the Tests and runs it
	./$(EXEC_TESTS)

## —— App commands ———————————————————————————————————————————

build: clean createFolders $(OBJS_APP) ## Builds the App
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS_APP)

run: build## Builds the App and runs it
	./$(EXEC)

## —— Docker commands —————————————————————————————————————————

up: ## up docker container
	docker-compose -f dev-docker-compose.yml up -d
down: ## down
	docker-compose -f dev-docker-compose.yml down
enter: ## enter to docker container with compiler
	docker exec -it compiler /bin/bash
