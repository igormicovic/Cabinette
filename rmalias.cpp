#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

void removeSpecificLines(const char* filename, const std::vector<std::string>& linesToRemove) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        perror("Error opening the file");
        exit(1);
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(inFile, line)) {
        bool found = false;
        for (size_t i = 0; i < linesToRemove.size(); ++i) {
            if (line == linesToRemove[i]) {
                found = true;
                break;
            }
        }

        if (!found) {
            lines.push_back(line);
        }
    }

    inFile.close();

    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        perror("Error opening the file");
        exit(1);
    }

    for (size_t i = 0; i < lines.size(); ++i) {
        outFile << lines[i] << "\n";
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

    std::vector<std::string> linesToRemove;
    linesToRemove.push_back("alias cabinette=~/Cabinette/test.sh");
    linesToRemove.push_back("");
    linesToRemove.push_back("alias paulo=~/Cabinette/test.sh");
    linesToRemove.push_back("");
    linesToRemove.push_back("alias C_update=~/Cabinette/update");

    removeSpecificLines(path, linesToRemove);

    return 0;
}
