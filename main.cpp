#include <iostream>
#include <vector>
#include "kokkos/core/src/Kokkos_Core.hpp"

int main(int argc, char* argv[])
{
    namespace kk = Kokkos;
    std::vector<double> a(128), b(128);

    kk::initialize(argc, argv);
    kk::DefaultExecutionSpace::print_configuration(std::cout);
    kk::parallel_for(128, [&] (const size_t i) {
        a[i] = 0.; b[i] = 0.;
    });

    kk::parallel_for(128, [&] (const size_t i) {
        a[i] += b[i];
    });

    std::cout << "a[0] = " << a[0] << std::endl;
    kk::finalize();
    return 0;
}