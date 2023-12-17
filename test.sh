file1="ft_lstnew.c"
file2="ft_lstnew_bonus.c"
file3="libft.h"
file4="get_next_line.c"
file5="ft_printf.h"

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
  cp ~/Cabinette/Libft/main.c .
  cp ~/Cabinette/Libft/Makefile1 .
  mv Makefile1 Makefile
  make test
  rm main.c
  rm Makefile
  mv testing Makefile
  mv testing.c main.c
elif [ -e "$file3" ]; then
  mv Makefile testing
  mv main.c testing.c
  cp ~/Cabinette/Libft/main2.c .
  cp ~/Cabinette/Libft/Makefile2 .
  mv Makefile2 Makefile
  mv main2.c main.c
  make test
  rm main.c
  rm Makefile
  mv testing Makefile
  mv testing.c main.c
elif [ -e "$file4" ]; then
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
  elif [ -e "$file5" ]; then
  mv main.c testing.c
  cp ~/Cabinette/Ft_Printf/main.c .
  cp ~/Cabinette/Ft_Printf/alias.cpp .
  cp ~/Cabinette/Ft_Printf/rmalias.cpp .
  g++ alias.cpp && ./a.out
  make test
  g++ rmalias.cpp && ./a.out
  rm a.out
  rm rmalias.cpp
  rm alias.cpp
  rm main.c
  mv testing.c main.c
else
  echo "File doesn't exist"
fi
