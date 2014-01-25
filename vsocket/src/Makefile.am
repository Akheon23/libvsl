AM_CPPFLAGS = -Wall -std=gnu++0x -I../../udt/ -finline-functions -fstack-check -fstack-protector-all -O0 -g3 -ggdb3
AM_LDFLAGS = -L../../udt/ -lcrypto -lssl -ludt -lstdc++ -lpthread -lm
ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libvsocket.la
libvsocket_la_SOURCES = bridge.cpp buffer.cpp if.cpp db.cpp node.cpp socks.cpp mem.cpp vsl.cpp ssl.cpp tcp.cpp udt.cpp net.cpp vsocket.cpp adapter.cpp url.cpp channel.cpp
