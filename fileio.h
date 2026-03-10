#include <fstream>
#include <cstdint>

class FileIO{

    private:
        //TODO
    public:
        std::fstream game;
        FileIO(const std::string& file);
        ~FileIO();

        bool validate();
        uint8_t* readByte(uint32_t byteToRead, int amount=1);
        
        void writeToFile(long offsetToWrite, uint16_t value);
        void writeBytesToFile(long* bytesToWriteTo, uint32_t* byteToRead, long length);
};