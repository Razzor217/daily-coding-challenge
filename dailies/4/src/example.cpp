#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include <hashing/merkle_damgard.h>


int main()
{
    std::string s {"Hello, world!"};

    std::uint16_t* ptr = reinterpret_cast<uint16_t*>(s.data());
    std::size_t const length = s.size() / sizeof(std::uint16_t);

    std::vector<std::uint16_t> v;
    std::copy(ptr, ptr + length, std::back_inserter(v));

    std::uint32_t const seed = 0xffffffff;
    hashing::merkle_damgard<std::vector<std::uint16_t>::iterator, std::uint16_t> md {seed};
    std::cout << "MD hash: " << std::hex << md(v.begin(), v.end()) << std::endl;

    return 0;
}