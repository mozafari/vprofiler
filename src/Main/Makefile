INSTALL_PREFIX ?= /usr/local

.PHONY: all
all:
	chmod +x vprofiler

.PHONY: install
install: all
	mkdir -p $(DESTDIR)$(INSTALL_PREFIX)/share/vprofiler/Main
	mkdir -p $(DESTDIR)$(INSTALL_PREFIX)/bin
	cp *.py $(DESTDIR)$(INSTALL_PREFIX)/share/vprofiler/Main
	cp vprofiler $(DESTDIR)$(INSTALL_PREFIX)/bin/
