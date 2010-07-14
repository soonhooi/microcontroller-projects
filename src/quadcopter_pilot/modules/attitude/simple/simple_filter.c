// TODO read timeConstant from EEPROM
// TODO try to undestand what these values are for
#define timeConstant = 0;
#define filterTerm0 = timeConstant / (timeConstant + 0.010)//10ms = ESC update rate
#define filterTerm1 1 - filterTerm0

double[] previous = {0.0, 0.0, 0.0};

double[] filter(double[] gyro, double[] accel, double dt) {
    double[] result = {0.0, 0.0, 0.0};
    for (int i = 0; i < 3; i++) {
        result[i] = (filterTerm[0] * (previous[i] + (gyro[i] * dt)) +
                    (filterTerm1 * (accel)) * 57.2957795; // what is this constant??
    }
    return result;
}
