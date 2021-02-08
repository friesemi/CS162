#include "house.h"
#include "apartment_complex.h"
#include "business_complex.h"

int main(){
	House house;
	Apartment apps;
	Business bus;
	house.houseListing();
	apps.apartmentListing();
	bus.businessListing();

	return 0;
}