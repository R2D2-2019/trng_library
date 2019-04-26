#include <trng.hpp>

int main(){
    r2d2::trng_c::init();

    while(!r2d2::trng_c::value_available()){∏

    r2d2::trng_c::get();
}