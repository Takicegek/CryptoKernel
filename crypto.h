#ifndef CRYPTO_H_INCLUDED
#define CRYPTO_H_INCLUDED

#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <string>

#define RSA_KEYLEN 2048

namespace CryptoKernel
{

class Crypto
{
public:
    Crypto(bool fGenerate = false);
    ~Crypto();
    bool getStatus();
    std::string decrypt(std::string cipherText);
    std::string encrypt(std::string plainText);
    std::string sign(std::string message);
    bool verify(std::string message, std::string signature);
    std::string getPublicKey();
    std::string getPrivateKey();
    bool setPublicKey(std::string publicKey);
    bool setPrivateKey(std::string privateKey);
    std::string sha256(std::string message);
    std::string getEk();
    bool setEk(std::string Ek);

private:
    EVP_PKEY *keypair;
    EVP_CIPHER_CTX *rsaCtx;
    bool status;
    unsigned char *ek;
    int ekl;
    unsigned char *iv;
    int ivl;
};

}

#endif // CRYPTO_H_INCLUDED