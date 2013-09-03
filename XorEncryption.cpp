#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <string>


class StringEncryption
{
public:
    // Allow the user to specify an encryption key
    StringEncryption(const char *key) : eKey(key) {}

    std::string Encode(const char *s) { return Xor(s); }
    std::string Decode(const char *s) { return Xor(s); }

private:
    // XOR (encryp/decryp)tion routine
    std::string Xor(const char *s);
    // e(ncryption)Key
    std::string eKey;

    // Disallow copying
    StringEncryption(const StringEncryption& obj);
    StringEncryption& operator=(const StringEncryption& obj);
};


std::string StringEncryption::Xor(const char *s)
{
    std::string result = "";

    int s_size = static_cast <int> (strlen(s));
    int index  = 0;

    for (int i = 0; i < s_size; ++i)
    {
        result += (*(s + i) ^ eKey[index]);

        ++index;

        if (index == eKey.length())
            index = 0;
    }

    return result;
}


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
