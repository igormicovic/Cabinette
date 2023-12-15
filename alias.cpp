#include <iostream>
#include <fstream>
#include <cstdlib>

void ft_putstr_fd(const char* s, std::ostream& os)
{
    os << s;
}

int main() {
    const char* home = getenv("HOME");

    if (home == nullptr) {
        std::cerr << "Error getting home directory" << std::endl;
        return 1;
    }

    char path[1024];
    snprintf(path, sizeof(path), "%s/.zshrc", home);

    std::ofstream file(path, std::ios::out | std::ios::trunc);

    if (!file.is_open()) {
        perror("Error opening the file");
        return 1;
    }
    else {
        ft_putstr_fd("\n", file);
        ft_putstr_fd("alias francinette=~/francinette/tester.sh\n", file);
        ft_putstr_fd("\n", file);
        ft_putstr_fd("alias paco=~/francinette/tester.sh\n", file);
        ft_putstr_fd("\n", file);
        ft_putstr_fd("alias cabinette=~/Cabinette/test.sh\n", file);
        ft_putstr_fd("\n", file);
        ft_putstr_fd("alias paulo=~/Cabinette/test.sh\n", file);
        ft_putstr_fd("\n", file);
        ft_putstr_fd("alias C_update=~/Cabinette/update\n", file);
    }

    file.close();
    return 0;
}
