all:
	mkdir -p /home/swillis/data
	mkdir -p /home/swillis/data/sqldb
	mkdir -p /home/swillis/data/wpfiles
	chmod 777 /home/swillis/data/sqldb
	chmod 777 /home/swillis/data/wpfiles
	docker-compose -f ./srcs/docker-compose.yml up -d --build

build:
	docker-compose -f ./srcs/docker-compose.yml up -d --build

stop:
	docker-compose -f ./srcs/docker-compose.yml stop

start:
	docker-compose -f ./srcs/docker-compose.yml start

down:
	docker-compose -f ./srcs/docker-compose.yml down

clean: down
	docker system prune -af
	docker volume prune -f

fclean : clean
	rm -rf /home/swillis/data/sqldb
	rm -rf /home/swillis/data/wpfiles

re: fclean all

log :
	docker-compose -f srcs/docker-compose.yml logs
