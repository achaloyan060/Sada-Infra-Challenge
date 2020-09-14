cd build
cmake ../
make
cd ..
./build/challenge2
echo "diff results:"
diff data/loomings.txt output/loomings-clean.txt
