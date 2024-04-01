file1="ft_lstnew.c"
file2="ft_lstnew_bonus.c"
file3="libft.h"
file4="get_next_line.c"
file5="ft_printf.h"
file6="pipex.h"
file7="Makefile"

if [ -e "$file1" ]; then
  mv main.c testing.c
  cp ~/Cabinette/Libft/main.c .
  cp ~/Cabinette/Libft/alias.cpp .
  cp ~/Cabinette/Libft/rmalias.cpp .
  g++ alias.cpp && ./a.out
  make test
  g++ rmalias.cpp && ./a.out
  rm a.out
  rm rmalias.cpp
  rm alias.cpp
  rm main.c
  mv testing.c main.c 2>/dev/null
elif [ -e "$file2" ]; then
  mv main.c testing.c
  cp ~/Cabinette/Libft/main.c .
  cp ~/Cabinette/Libft/alias.cpp .
  cp ~/Cabinette/Libft/rmalias.cpp .
  g++ alias.cpp && ./a.out
  make test
  g++ rmalias.cpp && ./a.out
  rm a.out
  rm rmalias.cpp
  rm alias.cpp
  rm main.c
  mv testing.c main.c 2>/dev/null
elif [ -e "$file3" ]; then
  mv main.c testing.c
  cp ~/Cabinette/Libft/main2.c .
  cp ~/Cabinette/Libft/alias.cpp .
  cp ~/Cabinette/Libft/rmalias.cpp .
  mv main2.c main.c
  g++ alias.cpp && ./a.out
  make test
  g++ rmalias.cpp && ./a.out
  rm a.out
  rm rmalias.cpp
  rm alias.cpp
  rm main.c
  mv testing.c main.c 2>/dev/null
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
  mv testing Makefile 2>/dev/null
  mv testing.c main.c 2>/dev/null
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
  mv testing.c main.c 2>/dev/null
elif [ -e "$file6" ]; then
  mv file1 testing
  mv file2 testing2
  cp ~/Cabinette/Pipex/file1 .
  cp ~/Cabinette/Pipex/file2 .
  cp ~/Cabinette/Pipex/pipex.py .
  cp ~/Cabinette/Pipex/alias.cpp .
  cp ~/Cabinette/Pipex/rmalias.cpp .
  g++ alias.cpp && ./a.out
  make test
  g++ rmalias.cpp && ./a.out
  rm a.out
  rm rmalias.cpp
  rm alias.cpp
  rm pipex.py
  rm file1
  rm file2
  mv testing.c main.c 2>/dev/null
  mv testing file1 2>/dev/null
  mv testing2 file2 2>/dev/null
elif [ -e "$file7" ]; then
  if cat Makefile | grep -q "pipex"; then
    mv file1 testing
    mv file2 testing2
    cp ~/Cabinette/Pipex/file1 .
    cp ~/Cabinette/Pipex/file2 .
    cp ~/Cabinette/Pipex/pipex.py .
    cp ~/Cabinette/Pipex/alias.cpp .
    cp ~/Cabinette/Pipex/rmalias.cpp .
    g++ alias.cpp && ./a.out
    make test
    g++ rmalias.cpp && ./a.out
    rm a.out
    rm rmalias.cpp
    rm alias.cpp
    rm pipex.py
    rm file1
    rm file2
    mv testing.c main.c 2>/dev/null
    mv testing file1 2>/dev/null
    mv testing2 file2 2>/dev/null
  else
    echo "Cannot find any files from [libft,ft_printf,get_next_line,pipex]"
  fi
else
  echo "Cannot find any files from [libft,ft_printf,get_next_line,pipex]."
fi
