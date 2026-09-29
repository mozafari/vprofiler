INSTALL_PREFIX ?= /usr/local

CXX := $(shell which g++)
CXXFLAGS := -fno-rtti -O0 -g -std=c++1y
PLUGIN_CXXFLAGS := -fpic

LLVM_CXXFLAGS := $(shell llvm-config --cxxflags)
LLVM_LDFLAGS  := $(shell llvm-config --ldflags --libs --system-libs)

LLVM_INCLUDES := $(shell llvm-config --includedir)
#CLANG_INCLUDES := -I../llvm/tools/clang/include \
				  -I../build/tools/clang/include


CLANG_LIBS := \
	-Wl,--start-group \
	-lclangAST \
	-lclangASTMatchers \
	-lclangAnalysis \
	-lclangBasic \
	-lclangDriver \
	-lclangEdit \
	-lclangFrontend \
	-lclangFrontendTool \
	-lclangLex \
	-lclangParse \
	-lclangSema \
	-lclangEdit \
	-lclangRewrite \
	-lclangRewriteFrontend \
	-lclangStaticAnalyzerFrontend \
	-lclangStaticAnalyzerCheckers \
	-lclangStaticAnalyzerCore \
	-lclangSerialization \
	-lclangToolingCore \
	-lclangTooling \
	-lclangFormat \
	-Wl,--end-group

.PHONY: all

all: TracerInstrumentor

TracerInstrumentor: NonTargetTracerInstrumentorVisitor.o CallerInstrumentorVisitor.o  TracerInstrumentorVisitor.o ReturnInstrumentorVisitor.o FileFinder.o Utils.o TracerInstrumentor.cc
	$(CXX) $(CXXFLAGS) $(LLVM_CXXFLAGS) $(CLANG_INCLUDES) $^ $(CLANG_LIBS) $(LLVM_LDFLAGS) -o TracerInstrumentor

NonTargetTracerInstrumentorVisitor.o: NonTargetTracerInstrumentorVisitor.cc
	$(CXX) $(CXXFLAGS) $(LLVM_CXXFLAGS) $(CLANG_INCLUDES) -c $^ -o $@

CallerInstrumentorVisitor.o: CallerInstrumentorVisitor.cc
	$(CXX) $(CXXFLAGS) $(LLVM_CXXFLAGS) $(CLANG_INCLUDES) -c $^ -o $@

TracerInstrumentorVisitor.o: TracerInstrumentorVisitor.cc
	$(CXX) $(CXXFLAGS) $(LLVM_CXXFLAGS) $(CLANG_INCLUDES) -c $^ -o $@

ReturnInstrumentorVisitor.o: ReturnInstrumentorVisitor.cc
	$(CXX) $(CXXFLAGS) $(LLVM_CXXFLAGS) $(CLANG_INCLUDES) -c $^ -o $@

FileFinder.o: FileFinder.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

Utils.o: Utils.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.PHONY: install
install: all
	mkdir -p $(DESTDIR)$(INSTALL_PREFIX)/share/vprofiler
	cp TracerInstrumentor $(DESTDIR)$(INSTALL_PREFIX)/share/vprofiler/

.PHONY: clean
clean: 
	rm -rf *.o TracerInstrumentor
