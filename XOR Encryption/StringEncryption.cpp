#include <string.h>


#include "StringEncryption.h"


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
