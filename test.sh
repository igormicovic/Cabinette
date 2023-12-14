mv Makefile testing
mv main.c testing.c
cp ~/beqa/main.c .
cp ~/beqa/Makefile .
make test
rm main.c
rm Makefile
mv testing Makefile
mv testing.c main.c
