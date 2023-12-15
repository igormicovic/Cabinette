file1="libft.h"
file2="get_next_line.c"

if [ -e "$file1" ]; then
  mv Makefile testing
  mv main.c testing.c
  cp ~/Cabinette/Libft/main.c .
  cp ~/Cabinette/Libft/Makefile .
  make test
  rm main.c
  rm Makefile
  mv testing Makefile
  mv testing.c main.c
elif [ -e "$file2" ]; then
  mv Makefile testing
  mv main.c testing.c
  cp ~/Cabinette/Get_Next_Line/main.c .
  cp ~/Cabinette/Get_Next_Line/Makefile .
  cp ~/Cabinette/Get_Next_Line/long.txt .
  cp ~/Cabinette/Get_Next_Line/nline.txt .
  cp ~/Cabinette/Get_Next_Line/text.txt .
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
