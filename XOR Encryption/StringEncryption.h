#ifndef STRINGENCRYPTION_H_INCLUDED
#define STRINGENCRYPTION_H_INCLUDED


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


#endif // STRINGENCRYPTION_H_INCLUDED
