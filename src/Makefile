INSTALL_PREFIX ?= /usr/local

.PHONY: all
all: Main SynchronizationInstrumentor TracerInstrumentor

.PHONY: Main
Main:
	make -C Main

.PHONY: SynchronizationInstrumentor
SynchronizationInstrumentor:
	make -C SynchronizationInstrumentor

.PHONY: TracerInstrumentor
TracerInstrumentor:
	make -C TracerInstrumentor

.PHONY: install
install: all
	make -C ExecutionTimeTracer install INSTALL_PREFIX=$(INSTALL_PREFIX)
	make -C FactorSelector install INSTALL_PREFIX=$(INSTALL_PREFIX)
	make -C Main install INSTALL_PREFIX=$(INSTALL_PREFIX)
	make -C SynchronizationInstrumentor install INSTALL_PREFIX=$(INSTALL_PREFIX)
	make -C TracerInstrumentor install INSTALL_PREFIX=$(INSTALL_PREFIX)
	make -C Restorer install INSTALL_PREFIX=$(INSTALL_PREFIX)

.PHONY: clean
clean:
	make -C SynchronizationInstrumentor clean
	make -C TracerInstrumentor clean
