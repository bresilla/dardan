#include "fmt/format.h"
// #include "spdlog/spdlog.h"
#include <tull/block.h>
#include <tull/classic.h>
#include <utils.hpp>

int main() {
    std::string s = fmt::format( "I'd rather be {1} than {0}.", "right", "happy" );
    fmt::print( s );    // Python-like format string syntax

    fmt::print( "gogo" );

    // spdlog::info("Welcome to spdlog!");
    // spdlog::error("Some error message with arg: {}", 1);
}
