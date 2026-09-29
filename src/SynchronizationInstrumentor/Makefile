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
all: EventAnnotator


EventAnnotator: ClangBase.o FileFinder.o FunctionFileReader.o WrapperGenModules.o WrapperGenerator.o Utils.o EventAnnotator.cc
	$(CXX) $(CXXFLAGS) $(LLVM_CXXFLAGS) $(CLANG_INCLUDES) $^ $(CLANG_LIBS) $(LLVM_LDFLAGS) -o EventAnnotator

ClangBase.o: ClangBase.cc
	$(CXX) $(CXXFLAGS) $(LLVM_CXXFLAGS) $(CLANG_INCLUDES) -c $^ -o $@

FileFinder.o: FileFinder.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

FunctionFileReader.o: FunctionFileReader.cc 
	$(CXX) $(CXXFLAGS) -c $^ -o $@

WrapperGenerator.o: WrapperGenerator.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

Utils.o: Utils.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

WrapperGenModules.o: WrapperGenModules.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.PHONY: install
install: all
	mkdir -p $(DESTDIR)$(INSTALL_PREFIX)/share/vprofiler
	cp EventAnnotator $(DESTDIR)$(INSTALL_PREFIX)/share/vprofiler/

.PHONY: clean
clean: 
	rm -rf *.o EventAnnotator FunctionFileReader
