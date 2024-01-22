#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

/**
 * @brief Represents a Visitor structure with entering and leaving time.
 */
struct Visitor {
    std::string enteringTime;    ///< The entering time of the visitor.
    std::string leavingTime;     ///< The leaving time of the visitor.
};

/**
 * @brief It compare the two visitorsList based on entering times.
 *
 * This function is used for sorting visitorsList based on entering times.
 *
 * @param v1Obj The first visitor.
 * @param v2Obj The second visitor.
 * @return True if v1Obj's entering time is less than v2Obj's entering time, otherwise false.
 */
bool comparevisitorsListEnteringTime(const Visitor& v1Obj, const Visitor& v2Obj) {
    return v1Obj.enteringTime < v2Obj.enteringTime;
}

/**
 * @brief This main function to analyze visiting times and find the time period with the most visitorsList.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return 0 if the program runs successfully, otherwise an error code.
 */
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file_path_Provided>\n";
        return 1;
    }

    const std::string inputFilePath = argv[1];

    std::ifstream inputFile(inputFilePath);
    if (!inputFile) {
        std::cerr << "Error opening input file: " << inputFilePath << "\n";
        return 1;
    }

    std::vector<Visitor> visitorsList;
    std::string line;
    while (std::getline(inputFile, line)) {
        Visitor visitorObj;
        std::istringstream iss(line);
        std::getline(iss, visitorObj.enteringTime, ',');
        std::getline(iss, visitorObj.leavingTime);
        visitorsList.push_back(visitorObj);
    }

    inputFile.close();

    // Sort visitorsList bases on entering time
    std::sort(visitorsList.begin(), visitorsList.end(), comparevisitorsListEnteringTime);

    int maxvisitors = 0;
    std::string startTime;
    std::string endTime;

    for (size_t i = 0; i < visitorsList.size(); ++i) {
        int overlapsInterval = 1;   ///< Current visitor is overlapping with itself

        for (size_t j = i + 1; j < visitorsList.size(); ++j) {
            if (visitorsList[j].enteringTime <= visitorsList[i].leavingTime) {
                overlapsInterval++;
            }
            else {
                break;
            }
        }

        if (overlapsInterval > maxvisitors) {
            maxvisitors = overlapsInterval;
            startTime = visitorsList[i].enteringTime;
            endTime = visitorsList[i].leavingTime;
        }
    }

    std::cout << startTime << "-" << endTime << ";" << maxvisitors << " visitorsList\n";

    return 0;
}
