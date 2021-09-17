#ifndef CLIENT_UTILS_UTILS
#define CLIENT_UTILS_UTILS

#include <Windows.h>
#include <filesystem>
#include <fstream>
#include <string>
#include <functional>
#include <bitset>
#include <optional>
#include <unordered_set>
#include <gsl/gsl>

class Utils {
private:
    static std::string debugPath;
public:
    static auto setDebugPath(const char*) -> void;
    static auto getDebugPath() -> std::string;

    static auto debugLogF(const char* output, const char* path = NULL) -> void;
    static auto initDebugFWithPath(const char* path) -> void;
};

#endif /* CLIENT_UTILS_UTILS */