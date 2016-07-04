void flauwe_bocht_rechts() {
	robot.rechts(255, 255);
}

void flauwe_bocht_links() {
	robot.links(255, 255);
}
void AIMODE_v5_Backup() {
	getDistance();
	bool objLeft = dist_left < 10;
	bool objRight = dist_right < 10;
	bool objCent = dist_center < 10;
	bool objLeftSide = dist_LeftSide < 10;
	bool objRightSide = dist_RightSide < 10;

	if (objLeft && objCent && objRight && objLeftSide && objRightSide) //1
	{
		robot.achteruit(255);
		delay(500);
		robot.rechts_eigenas(255);
		delay(1000);
	}
	else if (objLeftSide && objLeft && objCent && objRight && !objRightSide) //2
	{
		robot.achteruit(255);
		delay(500);
		flauwe_bocht_rechts();
	}
	else if (objLeftSide && objLeft && objCent && !objRight && objRightSide) //3
	{
		//niet mogelijk
	}
	else if (objLeftSide && objLeft && objCent && !objRight && !objRightSide) //4
	{
		flauwe_bocht_rechts();
	}
	else if (objLeftSide && objLeft && !objCent && objRight && objRightSide) //5
	{
		/*robot.achteruit(255);
		delay(1000);
		robot.rechts_eigenas(255);
		delay(1000);*/
	}
	else if (objLeftSide && objLeft && !objCent && objRight && !objRightSide) //6
	{
		/*robot.achteruit(255);
		delay(1000);
		robot.rechts_eigenas(255);
		delay(500);*/
	}
	else if (objLeftSide && objLeft && !objCent && !objRight && objRightSide) //7
	{
		robot.rechts(255, 255);
	}
	else if (objLeftSide && objLeft && !objCent && !objRight && !objRightSide) //8
	{
		robot.rechts(255, 255);
	}
	else if (objLeftSide && !objLeft && objCent && objRight && objRightSide) //9
	{
		//niet mogelijk
	}
	else if (objLeftSide && !objLeft && objCent && objRight && !objRightSide) //10
	{
		//niet mogelijk
	}
	else if (objLeftSide && !objLeft && objCent && !objRight && objRightSide) //11
	{
		//speciaal
		robot.stop();
	}
	else if (objLeftSide && !objLeft && objCent && !objRight && !objRightSide) //12
	{
		robot.achteruit(255);
		delay(300);
		flauwe_bocht_rechts();
	}
	else if (objLeftSide && !objLeft && !objCent && objRight && objRightSide) //13
	{
		flauwe_bocht_links();
	}
	else if (objLeftSide && !objLeft && !objCent && objRight && !objRightSide) //14
	{
		//Bestaat niet
	}
	else if (objLeftSide && !objLeft && !objCent && !objRight && objRightSide) //15
	{
		//afstand links en rechts meten, bepalen welke kant bijsturen
		if (dist_LeftSide > dist_RightSide)
		{
			robot.links(255, 200);
		}
		else if (dist_RightSide > dist_LeftSide)
		{
			robot.rechts(255, 200);
		}
	}
	else if (objLeftSide && !objLeft && !objCent && !objRight && !objRightSide) //16
	{
		//meting afstand links
			robot.rechts(255, 255);
		
	}
	else if (!objLeftSide && objLeft && objCent && objRight && objRightSide) //17
	{
		robot.achteruit(255);
		delay(500);
		robot.links_eigenas(255);
		delay(500);
	}
	else if (!objLeftSide && objLeft && objCent && objRight && !objRightSide) //18
	{
		if (dist_left > dist_right)
		{
			robot.achteruit(255);
			delay(750);
			flauwe_bocht_links();
		}
		else if (dist_left < dist_right)
		{
			robot.achteruit(255);
			delay(750);
			flauwe_bocht_rechts();
		}
		else if (dist_left == dist_right && dist_LeftSide > dist_RightSide)
		{
			robot.achteruit(255);
			delay(750);
			robot.links(255, 185);
		}
		else if (dist_left == dist_right && dist_LeftSide < dist_RightSide)
		{
			robot.achteruit(255);
			delay(1000);
			robot.rechts(255, 185);
		}
	}
	else if (!objLeftSide && objLeft && objCent && !objRight && objRightSide) //19
	{
		//niet mogelijk
	}
	else if (!objLeftSide && objLeft && objCent && !objRight && !objRightSide) //20
	{
		robot.achteruit(255);
		delay(500);
		flauwe_bocht_rechts();
	}
	else if (!objLeftSide && objLeft && !objCent && objRight && objRightSide) //21
	{
		if ((dist_left && dist_right) > 10)
		{
			robot.vooruit(255);
		}
		else {
			robot.achteruit(255);
			delay(500);
			robot.links_eigenas(255);
		}
	}
	else if (!objLeftSide && objLeft && !objCent && objRight && !objRightSide) //22
	{
		//
	}
	else if (!objLeftSide && objLeft && !objCent && !objRight && objRightSide) //23
	{
		// niet mogelijk
	}
	else if (!objLeftSide && objLeft && !objCent && !objRight && !objRightSide) //24
	{
		flauwe_bocht_rechts();
	}
	else if (!objLeftSide && !objLeft && objCent && objRight && objRightSide) //25
	{
		robot.links_eigenas(255);
		delay(500);
	}
	else if (!objLeftSide && !objLeft && objCent && objRight && !objRightSide) //26
	{
		robot.links_eigenas(255);
		delay(500);
	}
	else if (!objLeftSide && !objLeft && objCent && !objRight && objRightSide) //27
	{
		robot.achteruit(255);
		delay(500);
		flauwe_bocht_links();
	}
	else if (!objLeftSide && !objLeft && objCent && !objRight && !objRightSide) //28
	{
		if (dist_left > dist_right)
		{
			robot.achteruit(255);
			delay(500);
			flauwe_bocht_links();
		}
		else
		{
			robot.achteruit(255);
			delay(500);
			flauwe_bocht_rechts();
		}
	}
	else if (!objLeftSide && !objLeft && !objCent && objRight && objRightSide) //29
	{
		flauwe_bocht_links();
	}
	else if (!objLeftSide && !objLeft && !objCent && objRight && !objRightSide) //30
	{
		flauwe_bocht_links();
	}
	else if (!objLeftSide && !objLeft && !objCent && !objRight && objRightSide) //31
	{
			flauwe_bocht_links();
	}
	else if (!objLeftSide && !objLeft && !objCent && !objRight && objRightSide) //32
	{
		robot.vooruit(255);
	}
	//robot.vooruit(255); // altijd vooruit als case is doorlopen en niet stop is
}
