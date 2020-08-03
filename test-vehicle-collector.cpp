#include <math.h>
#include "vehicle_data_col.h"
#include <gtest/gtest.h>

input_s vehicle_1[3] = {
	{231, MOTOR_TEMP, 30.87},
	{231, BATTERY_PC, 70.02},
	{231, BATTERY_TEMP, 35.20}
};

input_s vehicle_2[3] = {
	{225, MOTOR_TEMP, 35.64},
	{225, BATTERY_PC, 85.01},
	{225, BATTERY_TEMP, 37.23}
};

TEST(COLLECT, reports_are_fetched_and_stored_with_vehicle_id) {
	
	// Vehicle 1 data
	store_s vehicle_data = store_vehicle_measurements(vehicle_1[0]);
	EXPECT_NEAR(vehicle_data.motor_temp, 30.86, 0.02);
	
	vehicle_data = store_vehicle_measurements(vehicle_1[1]);
	EXPECT_NEAR(vehicle_data.battery_pc, 70, 0.02);
	
	// Check for invalid data.
	ASSERT_EQ(isnan(vehicle_data.battery_temp), 1);
	
	// Vehicle 2 data
	vehicle_data = store_vehicle_measurements(vehicle_2[2]);
	EXPECT_NEAR(vehicle_data.battery_temp, 37.03, 0.2);
	
	vehicle_data = store_vehicle_measurements(vehicle_2[1]);
	EXPECT_NEAR(vehicle_data.battery_pc, 85.0, 0.1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
