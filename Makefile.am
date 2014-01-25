AUTOMAKE_OPTIONS = foreign
SUBDIRS = src udt vsocket
linux: 
	make -C udt
	bash -c "cd vsocket; ./configure; make"
	make -C .
