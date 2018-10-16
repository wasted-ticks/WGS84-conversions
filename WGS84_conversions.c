#include <math.h>

#define WGS84_RADIUS (6378137.00)
#define WGS84_INV_FLATTENING (298.257223563)
#define WGS84_FLATTENING (1 / WGS84_INV_FLATTENING)

extern struct WGS84_LLA {
	double lat;
	double lng;
	double altitude; /* meters */
};

/* measurements are in meters */
extern struct WGS84_ECEF {
	double x; 
	double y;
	double z;
};

extern struct WGS84_ECEF WGS84_LLA_to_ECEF
	( struct WGS84_LLA lla )
{
	struct WGS84_ECEF ecef = {0};
	
	double rad = (M_PI / 180.0);
	
	//double c_lat = cos(rad * lla.lat);
	//double s_lat = sin(rad * lla.lat);
	
	//double c_lng = cos(rad * lla.lng);
	//double s_lng = sin(rad * lla.lng);
	
	//TODO
	
	return ecef;
}

extern struct WGS84_LLH WGS84_ECEF_to_LLA
	( struct WGS84_ECEF ecef )
{
	struct WGS84_LLA lla = {0};
	
	//TODO
	
	return lla;
}