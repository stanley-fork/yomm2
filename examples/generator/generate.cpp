#include "animals.hpp"

#include <iostream>

#include <yorel/yomm2/generator.hpp>

int main(int argc, char* argv[]) {
    using namespace yorel::yomm2;

    auto compiler = update();
    generator generator;

    std::ofstream slots(argv[1]);
    generator
        .write_static_offsets<method_class(void, pet, (virtual_ptr<Animal>))>(
            slots)
        .write_static_offsets<method_class(
            void, mate, (virtual_ptr<Animal>, virtual_ptr<Animal>))>(slots);

    std::ofstream tables(argv[2]);
    generator.encode_dispatch_data(compiler, tables);

    return 0;
}