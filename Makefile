INSTALL_PREFIX ?= /usr/local

.PHONY: all
all:
	make -C src all

.PHONY: install
install: all
	make -C src install INSTALL_PREFIX=$(INSTALL_PREFIX)

.PHONY: clean
clean:
	make -C src clean
