# Cryptography
Implementing cipher algorithms : md5, sha256.

### Overview
In this project I use only this functions:

* open
* close
* read
* write
* malloc
* free

### Installation
To generate an executable for this project run `make` in the root of the project directory after you've downloaded or cloned it.
The make process will generate a binary called `ft_ssl`.

### Usage
After generating a binary, you can run the program with
`./ft_ssl [command] [command args : -pqrs]`
`-p`, echo STDIN to STDOUT and append the checksum to STDOUT.
`-q`, quiet mode.
`-r`, reverse the format of the output.
`-s`, print the sum of the given string.

### Usage examples
Encrypting some plaintext/string/file to [md5]:
```
> ./ft_ssl md5 <<< "Hello World"
e59ff97941044f85df5297e1c302d260

> ./ft_ssl md5 -s "imaltsev"
MD5 ("imaltsev") = b71c4a265a03b3cabaf0941ec59eadb4

> echo "github forever" > file
> ./ft_ssl md5 file
MD5 (file) = 8dccc05f12d52c51c32a4652395287ca

```

Encrypting some plaintext/string/file to [sha256]:
```
> e1r5p13% ./ft_ssl sha256 -p <<< "Hello world"
Hello world
1894a19c85ba153acbf743ac4e43fc004c891604b26f8c69e1e83ea2afc7c48f

> ./ft_ssl sha256 -s "imaltsev"
SHA256 ("imaltsev") = 8c3cdb023e061cf430c7a4964b57ec13587248d2bb35c12175a7c9869edbe364

> echo "github forever" > file
> ./ft_ssl sha256 file
SHA256 (file) = 7133a1de8691032ecaf2b0f79d99d6d2e18e5dbedfbcef74eb9b50d3e60a7168

> ./ft_ssl sha256 -sr "imaltsev"
8c3cdb023e061cf430c7a4964b57ec13587248d2bb35c12175a7c9869edbe364 "imaltsev"

> ./ft_ssl sha256 -r file
7133a1de8691032ecaf2b0f79d99d6d2e18e5dbedfbcef74eb9b50d3e60a7168 file

```
