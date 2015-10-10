/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 *  Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 sign.cpp -o sign -lssl
 *
 *  Usage:
 *      $ ./sign
 */

/*
 * $ openssl genrsa -des3 -out private.key 1024
 * Generating RSA private key, 1024 bit long modulus
 * ...................++++++
 * .......................++++++
 * e is 65537 (0x10001)
 * Enter pass phrase for private.key: 1234
 * Verifying - Enter pass phrase for private.key: 1234
 * 
 * $ cat private.key 
 * -----BEGIN RSA PRIVATE KEY-----
 * Proc-Type: 4,ENCRYPTED
 * DEK-Info: DES-EDE3-CBC,F263834F4AB2BA3F
 * 
 * 1NvFchbMolZoh7jIthMyYTvpr3hwVNa1KmhGohzxY0M0AhTxBOHPEXL2ZIbKsf4v
 * ehE5ge3Ij+8mBvrxTeXydK7dkxoF/uKkTOuJeY+zOmWMSSmT9D0BN5yYvvQCFJ9+
 * ir2arbPSRhm+WDbhcV8LOSxyYxIVZdW0QN54BuJ1igWq2sgUtbWXmoucK6DdPzwT
 * iJq9rCNgeJWVPOuRVXDdYmhjWeAns9H5PIUAxrHLiN2xXAzlFOXYKWE1a/WxEpVL
 * /6okZnsWSQsg6T8DgtoUEmSaTDbpKFpkXAimdqCsr4WQrxev0PSLV+qWHclDnZrS
 * ytMp3ZiCd2Ulk13Sz4Up7pL5rJaQ3jxuDxnKpfgFGBkIddUhxHS/bQg+SQsh8c4Q
 * za9knVjJdA5dgMUOGYD1ZamUuE423ma4GU2G5rkD139q7bnQqZXhijPHZigcQlDl
 * 3g35olZQCMx/4Z/GUX5QgVlL7gm9BPo5cN6DN5LODfkNSeUprgxNYEGUQLo+LH2c
 * ifE2hshDHSHvbC5Cc98KCbgyhJeQmWLYfy21fdDJpa8g396tQSPODV5D7ctUjOyF
 * tvuxTOIyR9E4YYi45ec6NcdbqappVEa+08yFj64OkCeNqLvK4B784ca2pwkdMWM3
 * 6Iani8OaA9EzKg7l63TMU2HAA5te9fbxqL3dGenvZJ3K/byg06WiKi9PeHtaUb48
 * l7/HVBJ1ZmdH/NcVMGt+9OKNbmtmMDt9R6E6Rc5qwP/qEPG3IfaQq7QQ8IC3TOoy
 * Agd/YHI5dfQ3zy+zJtL3zRS10m2Sc2FIQfO0L1eXiwS9kW4tG/zPWQ==
 * -----END RSA PRIVATE KEY-----
 * 
 * $ openssl rsa -in private.key -pubout > key.pub
 * Enter pass phrase for private.key: 1234
 * writing RSA key
 * 
 * $ cat key.pub 
 * -----BEGIN PUBLIC KEY-----
 * MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCWCbDaq8HYPdYg16wBZj9+CyZq
 * 7cg4hHMJmKyQtJr50vTLwecaO9e16ynD1ZuZyeOm3sZqlRBlRChUTrAJ7H2haUzG
 * aHn8kL9gaIafo/Mhd0BoCOSDkcqmbLWDtj7EmZTbYC7Isg/ZBD9g4YcDaZflU68m
 * zY5m3v7qcKmusf/q3wIDAQAB
 * -----END PUBLIC KEY-----
 * 
 * $ echo "C++" | openssl dgst -sha1 -sign private.key -out signature
 * Enter pass phrase for private.key: 1234
 * 
 * $ xxd signature 
 * 0000000: 1ea7 fd7d 6246 a948 0ad4 5670 8c95 fcfb  ...}bF.H..Vp....
 * 0000010: fa40 af8e e8c0 f4a0 7d36 fd86 bb26 2471  .@......}6...&$q
 * 0000020: bc55 141a 47b6 10ec 8ed8 11ad 3ba1 f19f  .U..G.......;...
 * 0000030: fc9e 8ddf 0912 63e9 6fe2 28fa c458 3cd1  ......c.o.( ..X<.
 * 0000040: 9199 9aae 9a1d d41b c6cf e2d1 599e 6449  ............Y.dI
 * 0000050: 2af5 ec9e 90a3 bb32 2a3d e006 0dd2 551c  *......2*=....U.
 * 0000060: bb40 91cb 077b d535 3eaa 6ece 7ea7 1209  .@...{.5>.n.~...
 * 0000070: 4d42 cc03 6f2c 4459 4a55 465f 8ed0 c438  MB..o,DYJUF_...8
 * 
 * $ echo "C++" | openssl dgst -sha1 -verify key.pub -signature signature 
 * Verified OK
 * 
 * $ echo "C--" | openssl dgst -sha1 -verify key.pub -signature signature 
 * Verification Failure
 */

#include <iostream>
#include <string>

#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/sha.h>
#include <openssl/ssl.h>

RSA* getPrivateKey( std::string const & privateKeyPemString )
{
    BIO* bioBuffer = BIO_new_mem_buf( 
        ( void*) privateKeyPemString.c_str(),
        ( int) privateKeyPemString.size()
    );

    RSA* result = PEM_read_bio_RSAPrivateKey( 
        bioBuffer,
        nullptr,
        nullptr,
        ( void*) "1234" /* password */
    );

    BIO_set_close( bioBuffer, BIO_NOCLOSE );
    BIO_free( bioBuffer );

    return result;
}

RSA* getPublicKey1( std::string const & publicKeyPemString )
{
    BIO* const bioBuffer = BIO_new_mem_buf( 
        ( void*) publicKeyPemString.c_str(),
        ( int) publicKeyPemString.size()
    );

    //RSA* const rsaPublic = PEM_read_bio_RSAPublicKey( 
    RSA* const result = PEM_read_bio_RSA_PUBKEY( 
        bioBuffer,
        nullptr,
        nullptr,
        nullptr
    );

    BIO_set_close( bioBuffer, BIO_NOCLOSE );
    BIO_free( bioBuffer );

    return result;
}

RSA* getPublicKey2( RSA* const rsaPrivate )
{
    /*
     * struct
     * {
     *      BIGNUM *n;      // public modulus
     *      BIGNUM *e;      // public exponent
     *      BIGNUM *d;      // private exponent
     *      BIGNUM *p;      // secret prime factor
     *      BIGNUM *q;      // secret prime factor
     *      BIGNUM *dmp1;   // d mod (p-1)
     *      BIGNUM *dmq1;   // d mod (q-1)
     *      BIGNUM *iqmp;   // q^-1 mod p
     *     // ...
     * } RSA;
     */

    RSA* const rsaPublic = RSA_new();
    rsaPublic->n = BN_dup( rsaPrivate->n );
    rsaPublic->e = BN_dup( rsaPrivate->e );

    return rsaPublic;
}

RSA* getPublicKey3( RSA* rsaPrivate )
{
    char* buffer = nullptr;

    int const size = i2d_RSAPublicKey( 
        rsaPrivate,
        ( unsigned char**)( & buffer)
    );  

    RSA* const rsaPublic = d2i_RSAPublicKey( 
        nullptr,
        ( unsigned char const**)( & buffer),
        size
    );

    return rsaPublic;
}

int main()
{
    typedef std::basic_string< unsigned char > ustring_t;

    const std::string privateKeyPemString( 
        "-----BEGIN RSA PRIVATE KEY-----\n"
        "Proc-Type: 4,ENCRYPTED\n"
        "DEK-Info: DES-EDE3-CBC,F263834F4AB2BA3F\n"
        "\n"
        "1NvFchbMolZoh7jIthMyYTvpr3hwVNa1KmhGohzxY0M0AhTxBOHPEXL2ZIbKsf4v\n"
        "ehE5ge3Ij+8mBvrxTeXydK7dkxoF/uKkTOuJeY+zOmWMSSmT9D0BN5yYvvQCFJ9+\n"
        "ir2arbPSRhm+WDbhcV8LOSxyYxIVZdW0QN54BuJ1igWq2sgUtbWXmoucK6DdPzwT\n"
        "iJq9rCNgeJWVPOuRVXDdYmhjWeAns9H5PIUAxrHLiN2xXAzlFOXYKWE1a/WxEpVL\n"
        "/6okZnsWSQsg6T8DgtoUEmSaTDbpKFpkXAimdqCsr4WQrxev0PSLV+qWHclDnZrS\n"
        "ytMp3ZiCd2Ulk13Sz4Up7pL5rJaQ3jxuDxnKpfgFGBkIddUhxHS/bQg+SQsh8c4Q\n"
        "za9knVjJdA5dgMUOGYD1ZamUuE423ma4GU2G5rkD139q7bnQqZXhijPHZigcQlDl\n"
        "3g35olZQCMx/4Z/GUX5QgVlL7gm9BPo5cN6DN5LODfkNSeUprgxNYEGUQLo+LH2c\n"
        "ifE2hshDHSHvbC5Cc98KCbgyhJeQmWLYfy21fdDJpa8g396tQSPODV5D7ctUjOyF\n"
        "tvuxTOIyR9E4YYi45ec6NcdbqappVEa+08yFj64OkCeNqLvK4B784ca2pwkdMWM3\n"
        "6Iani8OaA9EzKg7l63TMU2HAA5te9fbxqL3dGenvZJ3K/byg06WiKi9PeHtaUb48\n"
        "l7/HVBJ1ZmdH/NcVMGt+9OKNbmtmMDt9R6E6Rc5qwP/qEPG3IfaQq7QQ8IC3TOoy\n"
        "Agd/YHI5dfQ3zy+zJtL3zRS10m2Sc2FIQfO0L1eXiwS9kW4tG/zPWQ==\n"
        "-----END RSA PRIVATE KEY-----"
    );

    const std::string publicKeyPemString( 
        "-----BEGIN PUBLIC KEY-----\n"
        "MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCWCbDaq8HYPdYg16wBZj9+CyZq\n"
        "7cg4hHMJmKyQtJr50vTLwecaO9e16ynD1ZuZyeOm3sZqlRBlRChUTrAJ7H2haUzG\n"
        "aHn8kL9gaIafo/Mhd0BoCOSDkcqmbLWDtj7EmZTbYC7Isg/ZBD9g4YcDaZflU68m\n"
        "zY5m3v7qcKmusf/q3wIDAQAB\n"
        "-----END PUBLIC KEY-----"
    );

    const std::string _messageString( "C++" );

    const ustring_t messageString( 
        _messageString.begin(),
        _messageString.end()
    );

    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    unsigned char sha1[ SHA_DIGEST_LENGTH ] = {};

    SHA1( 
        messageString.c_str(),
        messageString.size(),
        sha1
    );

    RSA* rsaPrivate = nullptr;
    unsigned signatureSize = 0;
    unsigned char signatureBuffer[ 128 /* RSA_size( rsaPrivate ) */ ] = {};

    {
        rsaPrivate = getPrivateKey( privateKeyPemString );

        int const signResult = RSA_sign( 
            NID_sha1,
            sha1,
            SHA_DIGEST_LENGTH,
            signatureBuffer,
            & signatureSize,
            rsaPrivate
        );
        
        if( signResult != 1 )
        {
            std::cout << ERR_error_string( ERR_get_error(), 0 ) << std::endl;
        }
    }

    {
        RSA* const rsaPublic = getPublicKey1( publicKeyPemString );

        int const verifyResult = RSA_verify( 
            NID_sha1,
            sha1,
            SHA_DIGEST_LENGTH,
            signatureBuffer,
            signatureSize,
            rsaPublic
        );

        if( verifyResult != 1 )
        {
            std::cout << ERR_error_string( ERR_get_error(), 0 ) << std::endl;
        }
    
        RSA_free( rsaPublic ); 
    }

    {
        RSA* const rsaPublic = getPublicKey2( rsaPrivate );

        int const verifyResult = RSA_verify( 
            NID_sha1,
            sha1,
            SHA_DIGEST_LENGTH,
            signatureBuffer,
            signatureSize,
            rsaPublic
        );

        if( verifyResult != 1 )
        {
            std::cout << ERR_error_string( ERR_get_error(), 0 ) << std::endl;
        }
    
        RSA_free( rsaPublic ); 
    }

    {
        RSA* const rsaPublic = getPublicKey3( rsaPrivate );

        int const verifyResult = RSA_verify( 
            NID_sha1,
            sha1,
            SHA_DIGEST_LENGTH,
            signatureBuffer,
            signatureSize,
            rsaPublic
        );

        if( verifyResult != 1 )
        {
            std::cout << ERR_error_string( ERR_get_error(), 0 ) << std::endl;
        }
    
        RSA_free( rsaPublic ); 
    }

    RSA_free( rsaPrivate ); 

    return 0;
}

