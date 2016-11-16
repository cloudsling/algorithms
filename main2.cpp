//#include <iostream>
//
//using std::cout;
//
//#define ARR_LEN 10
//
//void res(int *);
//
//void print_arr(int arr[], int len);
//
//int main() {
//    int arr[ARR_LEN];
//
//    for (int index = 0; index < ARR_LEN; ++index) {
//        arr[index] = index * index;
//        cout << arr[index] << std::endl;
//    }
//
//    cout << "------------------------------------------------------------------------" << std::endl;
//    res(arr);
//
//    print_arr(arr, ARR_LEN);
//}
//
//void print_arr(int arr[], int len) {
//    for (int index = 0; index < len; ++index) {
//        cout << arr[index] << std::endl;
//    }
//}
//
//void res(int *pointers) {
//    for (int i = 0; i < ARR_LEN; ++i) {
//        *pointers++ = 3;
//    }
//}