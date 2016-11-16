/*
#include <iostream>

#define FULL_NUM 0xFFFF
#define INT_SIZE 16

using namespace std;

int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit);

int main() {
    int original_value = 0xFFFF, value_to_store = 0x123;
    unsigned start = 15, end = 4;

    int value;
    value = store_bit_field(original_value, value_to_store, start, end);

    cout << hex << value << endl;
}

int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit) {
    unsigned mask, rmask;
    int modified_value, tmp_value;

    mask = FULL_NUM;
    mask = mask >> (INT_SIZE - (starting_bit - ending_bit) - 1) << ending_bit;

    rmask = (~mask) & original_value;

    modified_value = value_to_store << ending_bit;
    tmp_value = modified_value & mask;

    return rmask | tmp_value;
}
*/
