#include <iostream>
#include <cstdlib>
#include <cstdio>


int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Invalid number of parameters passed! \n");
        exit(1);
    }

    StringEncryption key("XXX");

    for (int i = 1; i < argc; ++i)
    {
        std::cout << "Input string: " << argv[i] << std::endl;
        std::cout << "Encoded string: " << key.Encode(argv[i]) << std::endl;
        std::cout << "Decoded string: " << key.Decode(key.Encode(argv[i]).c_str()) << std::endl;
    }

    std::cout << "Encoded string: " << argc - 1;

    return 0;
}
