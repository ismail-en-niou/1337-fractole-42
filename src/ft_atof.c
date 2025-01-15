#include "../includes/fract_ol.h"



float ft_atof(const char *str) {
    float res = 0.0;
    float fraction = 0.0;
    int sign = 1;
    int i = 0;
    int divisor = 10;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) {
        i++;
    }
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.') {
        i++;
        while (str[i] >= '0' && str[i] <= '9') {
            fraction += (float)(str[i] - '0') / divisor;
            divisor *= 10;
            i++;
        }
    }

    return sign * (res + fraction);
}

