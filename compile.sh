g++ -Wall -fexceptions -g -lpthread -lsqlite3  -c gather.cc -o gather.o
g++ -Wall -fexceptions -g -lpthread -lsqlite3  -c main.cc -o main.o
g++ -Wall -fexceptions -g -lpthread -lsqlite3  -c thread_pool.cc -o thread_pool.o
g++ -Wall -fexceptions -g -lpthread -lsqlite3  -c tools.cc -o tools.o
g++  -o socket_sqlite main.o gather.o thread_pool.o tools.o  -lpthread -lsqlite3 
rm -f *.o 
