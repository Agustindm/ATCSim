/*
 * AirController.cpp
 *
 *  Created on: 21/07/2014
 *      Author: paco
 *
 *  Copyright 2014 Francisco Martín
 *
 *  This file is part of ATCSim.
 *
 *  ATCSim is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  ATCSim is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with ATCSim.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "AirController.h"
#include "Airport.h"
#include "Flight.h"
#include "Position.h"
#include <list>

AirController::AirController() {
	// TODO Auto-generated constructor stub

}

AirController::~AirController() {
	// TODO Auto-generated destructor stub
}

void
AirController::doWork()
{
			std::list<Flight*> flights = Airport::getInstance()->getFlights();
			std::list<Flight*>::iterator it;

			Position pos_aterrizaje_0(3500.0, 0.0, 100.0);
			Position pos_aterrizaje_1(1500.0, 0.0, 50.0);
			Position pos_aterrizaje_2(200.0, 0.0, 25.0);
			Position pos_aterrizaje_3(-750.0, 0.0, 25.0);

			//Rutas bajas dan mejores resultados que altas
			//El punto final bien fijado (altura y posicion)
			Position pos_circuito_0(15000.0, -3500.0, 1500.0);
			Position pos_circuito_1(15000.0, -10000.0, 500.0);
			Position pos_circuito_2(7000.0, -10000.0, 200.0);
			Position pos_circuito_3(7000.0, -3500.0, 100.0);

			Position pos_circuito_4(15000.0, 3500.0, 1500.0);
			Position pos_circuito_5(15000.0, 10000.0, 500.0);
			Position pos_circuito_6(7000.0, 10000.0, 200.0);
			Position pos_circuito_7(7000.0, 3500.0, 100.0);

			//Position pos_circuito_8(15000.0, -3500.0, 1500.0);
			//Position pos_circuito_9(15000.0, -10000.0, 500.0);
			//Position pos_circuito_10(7000.0, -10000.0, 200.0);
			//Position pos_circuito_11(7000.0, -3500.0, 100.0);

			//Position pos_circuito_12(15000.0, 3500.0, 1500.0);
			//Position pos_circuito_13(15000.0, 10000.0, 500.0);
			//Position pos_circuito_14(7000.0, 10000.0, 200.0);
			//Position pos_circuito_15(7000.0, 3500.0, 100.0);

			Route ra0, ra1, ra2, ra3;
			Route rc0, rc1, rc2, rc3;
			Route rc4, rc5, rc6, rc7;
			//Route rc8, rc9, rc10, rc11;
			//Route rc12, rc13, rc14, rc15;

			ra0.pos = pos_aterrizaje_0;
			ra0.speed = 400.0;
			ra1.pos = pos_aterrizaje_1;
			ra1.speed = 200.0;
			ra2.pos = pos_aterrizaje_2;
			ra2.speed = 19.0;
			ra3.pos = pos_aterrizaje_3;
			ra3.speed = 15.0;

			rc0.pos = pos_circuito_0;
			rc0.speed = 500.0;
			rc1.pos = pos_circuito_1;
			rc1.speed = 500.0;
			rc2.pos = pos_circuito_2;
			rc2.speed = 500.0;
			rc3.pos = pos_circuito_3;
			rc3.speed = 500.0;

			rc4.pos = pos_circuito_4;
			rc4.speed = 500.0;
			rc5.pos = pos_circuito_5;
			rc5.speed = 500.0;
			rc6.pos = pos_circuito_6;
			rc6.speed = 500.0;
			rc7.pos = pos_circuito_7;
			rc7.speed = 500.0;
/*
			rc8.pos = pos_circuito_8;
			rc8.speed = 500.0;
			rc9.pos = pos_circuito_9;
			rc9.speed = 500.0;
			rc10.pos = pos_circuito_10;
			rc10.speed = 500.0;
			rc11.pos = pos_circuito_11;
			rc11.speed = 500.0;

			rc12.pos = pos_circuito_12;
			rc12.speed = 500.0;
			rc13.pos = pos_circuito_13;
			rc13.speed = 500.0;
			rc14.pos = pos_circuito_14;
			rc14.speed = 500.0;
			rc15.pos = pos_circuito_15;
			rc15.speed = 500.0;
*/
			if(!Airport::getInstance()->is_booked_landing())
			{
				Flight* primero = *(flights.begin());

				primero->getRoute()->clear();
			}

			for(it = flights.begin(); it!=flights.end(); ++it)
			{
				if((*it)->getRoute()->empty())

				{
					if(Airport::getInstance()->is_booked_landing()&& (*it)->getPosition().get_y()<0){

						(*it)->getRoute()->push_back(rc0);
						(*it)->getRoute()->push_back(rc1);
						(*it)->getRoute()->push_back(rc2);
						(*it)->getRoute()->push_back(rc3);

						//(*it)->getRoute()->push_back(rc8);
						//(*it)->getRoute()->push_back(rc9);
						//(*it)->getRoute()->push_back(rc10);
						//(*it)->getRoute()->push_back(rc11);
					}else if(Airport::getInstance()->is_booked_landing()&& (*it)->getPosition().get_y()>=0){

						(*it)->getRoute()->push_back(rc4);
						(*it)->getRoute()->push_back(rc5);
						(*it)->getRoute()->push_back(rc6);
						(*it)->getRoute()->push_back(rc7);

						//(*it)->getRoute()->push_back(rc12);
						//(*it)->getRoute()->push_back(rc13);
						//(*it)->getRoute()->push_back(rc14);
						//(*it)->getRoute()->push_back(rc15);
					}else{
						Airport::getInstance()->book_landing();
						(*it)->getRoute()->push_back(ra0);
						(*it)->getRoute()->push_back(ra1);
						(*it)->getRoute()->push_back(ra2);
						(*it)->getRoute()->push_back(ra3);
					}
				}
			}

}
