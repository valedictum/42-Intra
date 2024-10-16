COL_RED		= \e[0;31m
COL_GREEN	= \e[0;32m
COL_YELLOW	= \e[0;33m
COL_BLUE	= \e[0;34m
COL_PURPLE	= \e[0;35m
COL_CYAN	= \e[0;36m
COL_RESET	= \e[0m

all: setup up 

setup:
	@echo "${COL_YELLOW}Redirecting '${COL_CYAN}jhughes.42.fr${COL_YELLOW}' to '${COL_CYAN}127.0.0.1${COL_YELLOW}'${COL_RESET}"
	@if grep -Fq "jhughes.42.fr" /etc/hosts; then echo "${COL_PURPLE}Already Done.${COL_RESET}"; else echo "127.0.0.1 jhughes.42.fr" | sudo tee -a /etc/hosts >> /dev/null && echo "${COL_GREEN}Done${COL_RESET}"; fi
	@mkdir -p /home/jhughes/data/
	@mkdir -p /home/jhughes/data/website
	@mkdir -p /home/jhughes/data/database

up:
	@sudo systemctl start docker
	@echo "${COL_YELLOW}Starting docker service... Done!${COL_RESET}"
	@cd srcs && sudo docker compose up -d --build

down:
	@cd srcs && sudo docker compose down

clean:
	@cd srcs && sudo docker compose down -v --rmi all
	@sudo rm -rf /home/jhughes/data
	@sudo sed -i '/127.0.0.1 jhughes.42.fr/d' /etc/hosts

.PHONY: all setup up down clean