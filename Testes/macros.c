#include <stdio.h>
#include <stdlib.h>

typedef int FUNC_POINT(); 

int f_1(){
    printf("%s: 1\n", __func__);
    return 1;
}

int f_0(){
    printf("%s: 0\n", __func__);
    return 0;
}

FUNC_POINT *func_pointer[2];
//func_pointer[0] = f_1;

int set_callback_function(int idx, FUNC_POINT *array_ptrF[2], FUNC_POINT *func_pointer){
    array_ptrF[idx] = func_pointer;
    return 0;
}

int main(){

    //FUNC_POINT *func_pointer[2];

    set_callback_function(0, func_pointer, f_0);
    set_callback_function(1, func_pointer, f_1);

    (*func_pointer[0])();
    (*func_pointer[1])();

    return 0;
}
