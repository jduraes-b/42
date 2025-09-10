# Variables
DATA_DIR := $(HOME)/data
WORDPRESS_DIR := $(DATA_DIR)/wordpress
MARIADB_DIR := $(DATA_DIR)/mariadb
ENV_SRC := $(HOME)/Desktop/.env
ENV_DEST := ./srcs/.env
SECRETS_SRC := $(HOME)/Desktop/secrets
SECRETS_DEST := ./secrets
DC := docker-compose -f ./srcs/docker-compose.yml

all: build up

build:
	mkdir -p $(DATA_DIR)/mariadb
	mkdir -p $(DATA_DIR)/wordpress
	$(DC) build

up:
	$(DC) up -d

down:
	$(DC) down -v

clean:	down
	@echo "Cleaning containers and images..."
	docker system prune -af

fclean:	clean
	docker run --rm -v $(WORDPRESS_DIR):/data alpine sh -c "rm -rf /data/*"
	docker run --rm -v $(MARIADB_DIR):/data alpine sh -c "rm -rf /data/*"

re: clean all

# First-time setup: copy secrets and env
setup:
	@if [ -f $(ENV_SRC) ]; then cp $(ENV_SRC) $(ENV_DEST); echo ".env copied to $(ENV_DEST)"; else echo "No .env found on Desktop"; fi
	@if [ -d $(SECRETS_SRC) ]; then cp -r $(SECRETS_SRC) $(SECRETS_DEST); echo "secrets copied to $(SECRETS_DEST)"; else echo "No secrets folder found on Desktop"; fi

.PHONY: all up down build clean fclean re setup
