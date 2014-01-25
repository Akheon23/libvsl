AM_CCFLAGS = -Wall -I./udt/ -finline-functions -fstack-check -fstack-protector-all -O0 -g3 -ggdb3
AM_LDFLAGS = -L./udt/ -L./vsocket -lvsocket -lcrypto -lssl -ludt -lstdc++ -lpthread -lm -lssl -lcrypto -lsocket

bin_PROGRAMS = gclient
gclient_SOURCES = gclient.cpp socks.cpp console.cpp secret.cpp memory.cpp

