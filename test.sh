file1="libft.h"
file2="get_next_line.c"

if [ -e "$file1" ]; then
  mv Makefile testing
  mv main.c testing.c
  cp ~/Cabinette/main.c .
  cp ~/Cabinette/Makefile .
  make test
  rm main.c
  rm Makefile
  mv testing Makefile
  mv testing.c main.c
elif [ -e "$file2" ]; then
  mv Makefile testing
  mv main.c testing.c
  cp ~/Cabinette/main1.c .
  cp ~/Cabinette/Makefile1 .
  cp ~/Cabinette/long.txt .
  cp ~/Cabinette/nline.txt .
  cp ~/Cabinette/text.txt .
  mv main1.c main.c
  mv Makefile1 Makefile
  make test
  rm main.c
  rm Makefile
  rm long.txt
  rm nline.txt
  rm text.txt
  mv testing Makefile
  mv testing.c main.c
else
  echo "File doesn't exist"
fi
