enum measure
{
	MOTOR_TEMP = 0,
	BATTERY_PC,
	BATTERY_TEMP
};

struct input_s
{
	int vehicle_id;
	measure type;
	float measurement;
};

struct store_s
{
	int vehicle_id;
	float motor_temp;
	float battery_pc;
	float battery_temp;
};

store_s store_vehicle_measurements(input_s vehicle_data);