#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

void ft_putstr_fd(const char* s, std::ostream& os)
{
    os << s;
}

void markLines(const char* filename, const std::vector<std::string>& linesToAdd) {
    std::ofstream file(filename, std::ios::out | std::ios::app);

    if (!file.is_open()) {
        perror("Error opening the file");
        exit(1);
    }

    for (const auto& line : linesToAdd) {
        ft_putstr_fd(line.c_str(), file);
    }

    file.close();
}

void removeMarkedLines(const char* filename, const std::vector<std::string>& linesToRemove) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        perror("Error opening the file");
        exit(1);
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(inFile, line)) {
        if (std::find(linesToRemove.begin(), linesToRemove.end(), line) == linesToRemove.end()) {
            lines.push_back(line);
        }
    }

    inFile.close();

    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        perror("Error opening the file");
        exit(1);
    }

    for (const auto& l : lines) {
        outFile << l << "\n";
    }

    outFile.close();
}

int main() {
    const char* home = getenv("HOME");

    if (home == nullptr) {
        std::cerr << "Error getting home directory" << std::endl;
        return 1;
    }

    const char* filename = ".zshrc";
    char path[1024];
    snprintf(path, sizeof(path), "%s/%s", home, filename);

    std::vector<std::string> linesToRemove = 
    {
        "alias cabinette=~/Cabinette/test.sh",
        "",
        "alias paulo=~/Cabinette/test.sh",
        "",
        "alias C_update=~/Cabinette/update",
    };

    removeMarkedLines(path, linesToRemove);

    return 0;
}
