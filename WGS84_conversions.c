#include <math.h>

#define WGS84_RADIUS (6378137.00)
#define WGS84_INV_FLATTENING (298.257223563)
#define WGS84_FLATTENING (1 / WGS84_INV_FLATTENING)

/**
 * CONVERSION FUNCTIONS FOR WGS84 DATUM
 */

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

/**
 * CONVERTS COORDINATES OF (LAT, LNG, ALTITUDE) TO ECEF (X, Y, Z)
 * USING WSG84 DATUM.
 */
extern struct WGS84_ECEF WGS84_LLA_to_ECEF
	( struct WGS84_LLA lla )
{
	struct WGS84_ECEF ecef = {0};
	
	double rad = (M_PI / 180.0);
	
	double c_lat = cos(rad * lla.lat);
	double s_lat = sin(rad * lla.lat);
	
	double c_lng = cos(rad * lla.lng);
	double s_lng = sin(rad * lla.lng);
	
	double pvr = prime_vertical_radius(lla.lat);
	double e_sq = WGS84_FLATTENING * (2 - WGS84_FLATTENING);
	
	ecef.x = (pvr + (lla.altitude / 1000.00)) * c_lat * c_lng;
	ecef.y = (pvr + (lla.altitude / 1000.00)) * c_lat * s_lng;
	ecef.z = ((1.00 - e_sq) * pvr + (lla.altitude / 1000.00)) * s_lat;
	
	return ecef;
}

extern struct WGS84_LLH WGS84_ECEF_to_LLA
	( struct WGS84_ECEF ecef )
{
	struct WGS84_LLA lla = {0};
	
	//TODO
	
	return lla;
}

static double prime_vertical_radius
	(double lat)
{
	double rad = (M_PI / 180.0);
	double s_lat = sin(rad * lat);
	double e_sq = WGS84_FLATTENING * (2 - WGS84_FLATTENING);
	return WGS84_RADIUS / sqrt(1.00 - e_sq * s_lat * s_lat);
}

