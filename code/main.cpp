#include <trng.hpp>

int main(){
    // init the trng
    r2d2::trng_c::init();

    // init timers arduino
    hwlib::wait_ms(1);

    // wait until we have a new random number
    while(!r2d2::trng_c::value_available()){}

    hwlib::cout << "Random number: " << r2d2::trng_c::get() << '\n';

    // infinite loop
    while(true){}
}