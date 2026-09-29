# VProfiler

VProfiler is a source-instrumenting profiler for finding functions that contribute most to latency variance in multithreaded applications. It analyzes a semantic interval of interest rather than only average time in a call graph.

This is historical research software, preserved for reproducibility. It is not maintained or qualified for current Clang/LLVM or Python environments.

## Historical build and runtime requirements

- A POSIX-like environment with `make`, a C++ compiler, and Python 2. The command-line code uses Python-2 syntax; Python 3 is not supported by this revision.
- `llvm-config` plus the Clang development headers and libraries compatible with this 2017 source tree. The code uses Clang tooling APIs directly; no current LLVM/Clang release has been qualified here.
- A target C/C++ project and its `compile_commands.json` compilation database.

Build the instrumentors with:

```bash
make
```

To install without writing to a system directory, choose a prefix:

```bash
make INSTALL_PREFIX="$HOME/.local" install
export PATH="$HOME/.local/bin:$PATH"
```

The checked-in test compilation databases are historical captures with their original build paths. Generate a new compilation database for the project being profiled instead of reusing those paths.

## Example

After building and placing `vprofiler` on `PATH`, annotate a project using its source directory, a list of parallelism functions, and a compilation database:

```bash
vprofiler --annotate \
  --source_dir /path/to/project/src \
  --parallelism_functions /path/to/parallelism-functions.txt \
  --compilation_db /path/to/compile_commands.json
```

On a compatible historical toolchain, the command reports `Instrumenting synchronization APIs...` and then asks the user to integrate the generated files in `vprof_files` into the target application. That output means the annotation stage completed; it does not yet identify variance factors. The full profiling workflow additionally requires the target project's build and run scripts and uses the generated latency data to rank factors.

## Citing VProfiler

```bibtex
@inproceedings{huang2017statistical,
  title     = {Statistical Analysis of Latency Through Semantic Profiling},
  author    = {Huang, Jiamin and Mozafari, Barzan and Wenisch, Thomas F.},
  booktitle = {Proceedings of the Twelfth European Conference on Computer Systems},
  pages     = {64--79},
  year      = {2017},
  publisher = {ACM},
  doi       = {10.1145/3064176.3064179}
}
```

## License

VProfiler is available under the [Apache License 2.0](LICENSE). Preserve the notices in generated and third-party files.
