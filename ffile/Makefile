PREFIX ?= /usr
CONFIG ?= /etc

all:
	@echo Run \'make install\' to install ffile.
	
install:
	@mkdir -p $(DESTDIR)$(PREFIX)/bin
	@mkdir -p $(DESTDIR)$(CONFIG)
	@mkdir -p $(DESTDIR)$(PREFIX)/share/applications
	@cp -p mkill $(DESTDIR)$(PREFIX)/bin/ffile
	@chmod 755 $(DESTDIR)$(PREFIX)/bin/ffile

uninstall:
	@rm -rf $(DESTDIR)$(PREFIX)/bin/ffile*
	@rm -rf $(DESTDIR)$(PREFIX)/share/applications/mkill.desktop
	@rm -rf $(DESTDIR)$(CONFIG)/mkill.conf
