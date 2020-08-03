#include <math.h>
#include "vehicle_data_col.h"

store_s store_vehicle_measurements(input_s vehicleInData)
{
	store_s vehicleInventory = {0, NAN, NAN, NAN};
	
	vehicleInventory.vehicle_id = vehicleInData.vehicle_id;
	
	switch(vehicleInData.type)
	{
		case MOTOR_TEMP:
			vehicleInventory.motor_temp = vehicleInData.measurement;
			break;
		case BATTERY_PC:
			vehicleInventory.battery_pc = vehicleInData.measurement;
			break;
		case BATTERY_TEMP:
			vehicleInventory.battery_temp = vehicleInData.measurement;
			break;
		default:
			break;
	}

	return vehicleInventory;
}