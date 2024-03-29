#include "FileStream.h"
#include "FilePointer.h"

std::string MODE = "-mode";
std::string FILE_POINTER_MODE = "FilePointer";
std::string FILE_STREAM_MODE = "FileStream";

std::string IN_FILE_NAME = "in.txt";
std::string OUT_FILE_NAME = "out.txt";

int main(int argc, char *argv[]) {

    std::cout << "Ctrl+B char: " << (char) 2 << '\n';

    if (argc >= 3 && argv[1] == MODE) { // Method choice
        if (argv[2] == FILE_POINTER_MODE) {
            file_pointer_main(IN_FILE_NAME.c_str(), OUT_FILE_NAME.c_str()); // file pointer method
        } else if (argv[2] == FILE_STREAM_MODE) {
            file_stream_main(IN_FILE_NAME, OUT_FILE_NAME);  // file stream method
        } else
            std::cout << "Incorrect mode!\n";
    } else {
        std::cout << "Missing arguments!\n";
    }

}