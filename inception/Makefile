# Makefile for inception project

# Docker Compose configuration
DC = docker-compose -f srcs/docker-compose.yml

# Default target: build and start services
all: build up

# Build services
build:
	$(DC) build

# Start services in detached mode
up:
	$(DC) up -d

# Stop services
down:
	$(DC) down

# Follow service logs
logs:
	$(DC) logs -f

# Restart services
restart: down up

# Remove containers, images, and volumes
clean:
	$(DC) down --rmi all -v

# Rebuild from scratch
re: clean build up

.PHONY: all build up down logs restart clean re