# Português
## CacheSim
Simulador de cache projetado em **C++** para a aula de **Arquitetura e Organização de Computadores II**
## Uso
Para usar o código, primeiro se compila *normalmente* usando o **g++**,
> `g++ main.cpp -o nome_do_programa`

depois, roda o arquivo em um dos formatos:
>`./nome_do_programa` , `./nome_do_programa default` - gera um arquivo e executa na configuração default:
>> **256** - *numero de conjuntos*
>**4** - *tamanho do bloco*
>**1** - *associatividade*
>**0** - *politica Random*

>`./nome_do_programa generate`  - gera um arquivo com nome *arquivo_de_entrada*
>`./nome_do_programa generate nome_do_arquivo` - gera um arquivo com nome *nome_do_arquivo*
>`./nome_do_programa 256:4:1:0 nome_do_arquivo`  - roda na configuração 256 *nsets*, 4 *bsize*, 1 *assoc* e 0 *politica de substituição*
>>**0** - Random
>**1** - FIFO
>**2** - LRU
# English

## CacheSim
**C++** cache simulator for **Architecture and Computer's Organization** class


## Usage

To use the code, firstly, *normally* compile using **g++**,
> `g++ main.cpp -o program_name`

after, run the code with the following formats:
>`./program_name` , `./program_name default` - generate a file and executs on default configuration: 
>> **256** - *Sets number*
>**4** - *Block size*
>**1** - *Associativity*
>**0** - *Random substitution policy*

>`./program_name generate`  - generate a file with *arquivo_de_entrada* name
>`./program_name generate file_name` - generate a file with *program_name* name
>`./program_name 256:4:1:0 nome_do_arquivo`  - run with the 256 *nsets*, 4 *bsize*, 1 *assoc* e 0 *sub policy*
>>**0** - Random
>**1** - FIFO
>**2** - LRU
