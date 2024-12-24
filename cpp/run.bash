clear

echo "(1/3) Collecting all C++ files..."

cpp_files=( $(find . -name "*.cpp") )
echo "Found ${#cpp_files[@]} C++ files"

echo "(2/3) Compiling..."
compile_time_start=$(date +%s.%N)
g++ -o main ${cpp_files[@]} -lsqlite3 -lcpprest -lboost_system -lpthread
compile_time_end=$(date +%s.%N)
compile_time=$(echo "$compile_time_end - $compile_time_start" | bc)
echo "Compilation took $compile_time seconds"

echo "(3/3) Running program..."
echo ""
runtime_start=$(date +%s.%N)
./main
runtime_end=$(date +%s.%N)
runtime=$(echo "$runtime_end - $runtime_start" | bc)
echo ""

echo "Program execution time: $runtime seconds"