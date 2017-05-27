cd cmake-build-debug
cmake ..
make
cd ..
./cmake-build-debug/compute_sha512_hash --path=test1.txt
