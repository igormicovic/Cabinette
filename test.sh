mv Makefile testing
mv main.c testing.c
cp ~/Cabinette/main.c .
cp ~/Cabinette/Makefile .
make test
rm main.c
rm Makefile
mv testing Makefile
mv testing.c main.c
