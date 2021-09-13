#include "Utils.h"

std::string Utils::debugPath = std::string("");

void Utils::setDebugPath(const char* path){
    debugPath = std::string(path);
};

std::string Utils::getDebugPath(){
    return debugPath;
};

void Utils::debugLogF(const char* output, const char* path){
    try {
        if(path != NULL)
            debugPath = getenv("APPDATA") + std::string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\" + std::string(path));

        auto debugP = std::string(debugPath + "\\DebugOutput\\" + std::string("Output.txt"));

        struct stat buffer;

        if(!(stat(debugP.c_str(), &buffer) == 0)){
            std::filesystem::create_directories(std::filesystem::path(debugP).parent_path());
        };

        CloseHandle(CreateFileA(debugP.c_str(), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));

        std::ofstream fileOutput;
        fileOutput.open(debugP.c_str(), std::ios_base::app);
        
        if(!fileOutput.is_open())
            return fileOutput.close();
        
        fileOutput << output << std::endl;
        fileOutput.close();
    } catch(...){ /* Do nothing */};
};

void Utils::initDebugFWithPath(const char* path){
    const char* _path = std::string(getenv("APPDATA") + std::string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\" + std::string(path))).c_str();
    std::filesystem::remove_all(std::filesystem::path(_path));
    Utils::debugLogF("Initialized Debug File!", _path);
};