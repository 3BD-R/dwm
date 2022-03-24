PREFIX ?= /usr
CONFIG ?= /etc

#all:
#	@echo Run \'make install\' to install mkill.
	
install:
	@cp -p mkill $(DESTDIR)$(PREFIX)/bin/mkill
	@chmod 755 $(DESTDIR)$(PREFIX)/bin/mkill

uninstall:
	@rm -rf $(DESTDIR)$(PREFIX)/bin/mkill*
