#include "vehicle_data_col.h"
#include <gtest/gtest.h>

input_s vehicle_1 = {231, MOTOR_TEMP, 30.87};

TEST(COLLECT, reports_are_fetched_and_stored_with_vehicle_id) {
	
	store_s sto = store_vehicle_measurements(vehicle_1);
	
	EXPECT_NEAR(sto.motor_temp, 30.86, 0.02);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
