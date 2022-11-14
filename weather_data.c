#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
date_finder(int where, int *month) 
{
	int day;
	where = where + 1;
	if (where >= 1 && where <= 31) {
		*month = 1;
		day = where;
	}
	else if (where >= 32 && where <= 60) {
		*month = 2;
		day = where - 31;
	}
	else if (where >= 61 && where <= 91) {
		*month = 3;
		day = where - 60;
	}
	else if (where >= 92 && where <= 121) {
		*month = 4;
		day = where - 91;
	}
	else if (where >= 122 && where <= 152) {
		*month = 5;
		day = where - 121;
	}
	else if (where >= 153 && where <= 182) {
		*month = 6;
		day = where - 152;
	}
	else if (where >= 183 && where <= 213) {
		*month = 7;
		day = where - 182;
	}
	else if (where >= 214 && where <= 244) {
		*month = 8;
		day = where - 213;
	}
	else if (where >= 245 && where <= 274) {
		*month = 9; 
		day = where - 244;
	}
	else if (where >= 275 && where <= 305) {
		*month = 10;
		day = where - 274;
	}
	else if (where >= 306 && where <= 335) {
		*month = 11;
		day = where - 305;
	}
	else if (where >= 336 && where <= 366) {
		*month = 12;
		day = where - 335;
	}
	return(day);
}

int main(void)
{
	FILE *fp;
	fp = fopen("Winter 2022 term project", "r");
	if (fp == NULL) {
		printf("The file can't be opened. Please upload your data.");
		return(-1);
	}
	
	double data[366][8];
	char line[60];
	int r = 0;
	double lakeav20[6]; double av20; double sum = 0; double allsum = 0; 
	double lakeavsort[6][2];
	int hmonth[6]; int cmonth[6]; int hdate[6]; int cdate[6]; int h = 0; int l = 0; 
	double hottest[6]; double coldest[6]; int wherehot[6]; int wherecold[6]; char lakename[15]; 
	double hot; double cold; int hlake[6]; int clake[6]; 
	double saverage[6][2]; 
	double waverage[6][2]; 
	int swimcount[6]; 
	int freezecount[6];
	double ndata[365][8]; double lakeav19[6]; double av19; 
	
	while (r < 366) {
		fgets(line, 60, fp);
		sscanf(line, "%lf %lf %lf %lf %lf %lf %lf %lf", &data[r][0], &data[r][1], &data[r][2], &data[r][3], &data[r][4], &data[r][5], &data[r][6], &data[r][7]);
		memset(line, 0, 60);
		r++;
	}
	fclose(fp);
	
	printf("Welcome to our cps 188 winter 2022 term project..\n\n");
	
	//question 1
	for (r = 2; r < 8; r++) {
		l = r-2;
		for (h = 0; h < 366; h++) {
			sum = sum + data[h][r];
			allsum = allsum + data[h][r];
		}
		lakeav20[l] = sum/366;
		sum = 0;
	}
	av20 = allsum/(366*6);
	
	printf("_______________________________________________________________________________________________\n");
	printf("\nQuestion number 1:\n");
	for (h = 0; h < 6; h++) {
		switch(h) {
			case 0: 
				strncpy(lakename, "Superior", 15);
				break;
			case 1: 
				strncpy(lakename, "Michigan", 15);
				break;
			case 2: 
				strncpy(lakename, "Huron", 15);
				break;
			case 3: 
				strncpy(lakename, "Erie", 15);
				break;
			case 4: 
				strncpy(lakename, "Ontario", 15);
				break;
			case 5: 
				strncpy(lakename, "St. Clair", 15);
			}
		printf("Yearly temperature average for Lake %s is about %.2lf degrees Celsius.\n", lakename, lakeav20[h]);
		memset(lakename, 0, 15);
	}
	printf("\n Yearly average between all lakes is about %.2lf degrees Celsius.\n\n", av20);
	
	//question 2
	for (r = 0; r < 6; r++) {
		lakeavsort[r][0] = lakeav20[r];
		lakeavsort[r][1] = r;
	}
	double temp0; double temp1;
	for (r = 0; r < 6; r++) {
		for (h = 0; h < 6; h++) {
			if (lakeavsort[h][0] < lakeavsort[r][0]) {
				temp0 = lakeavsort[r][0];
				temp1 = lakeavsort[r][1];
				
				lakeavsort[r][0] = lakeavsort[h][0];
				lakeavsort[r][1] = lakeavsort[h][1];
				
				lakeavsort[h][0] = temp0;
				lakeavsort[h][1] = temp1;
			}
		}
	}
	
	printf("_______________________________________________________________________________________________\n");
	printf("\nQuestion 2:\n");
	switch((int)lakeavsort[0][1]) {
		case 0: 
			strncpy(lakename, "Superior", 15);
			break;
		case 1: 
			strncpy(lakename, "Michigan", 15);
			break;
		case 2: 
			strncpy(lakename, "Huron", 15);
			break;
		case 3: 
			strncpy(lakename, "Erie", 15);
			break;
		case 4: 
			strncpy(lakename, "Ontario", 15);
			break;
		case 5: 
			strncpy(lakename, "St. Clair", 15);
	}
	printf(" Lake with the hottest mode was Lake %s.\n", lakename);
	memset(lakename, 0, 15);
			
	switch((int)lakeavsort[5][1]) {
		case 0: 
			strncpy(lakename, "Superior", 15);
			break;
		case 1: 
			strncpy(lakename, "Michigan", 15);
			break;
		case 2: 
			strncpy(lakename, "Huron", 15);
			break;
		case 3: 
			strncpy(lakename, "Erie", 15);
			break;
		case 4: 
			strncpy(lakename, "Ontario", 15);
			break;
		case 5: 
			strncpy(lakename, "St. Clair", 15);
		}
	printf("Lake with the lowest average was Lake %s.\n\n", lakename);
	memset(lakename, 0, 15);
			
	for (h = 0; h < 6; h++){
		switch(h) {
			case 0: 
				strncpy(lakename, "Superior", 15);
				break;
			case 1: 
				strncpy(lakename, "Michigan", 15);
				break;
			case 2: 
				strncpy(lakename, "Huron", 15);
				break;
			case 3: 
				strncpy(lakename, "Erie", 15);
				break;
			case 4: 
				strncpy(lakename, "Ontario", 15);
				break;
			case 5: 
				strncpy(lakename, "St. Clair", 15);
		}
		if (lakeav20[h] < av20) {
			printf("Lake %s's average was lower than the overall average.\n", lakename);
		}
		else if (lakeav20[h] > av20) {
			printf("Lake %s's average was higher than the average.\n", lakename);
		}
		else if (lakeav20[h] == av20) {
			printf("Lake %s's average was the same to the average.\n", lakename);
		}
		memset(lakename, 0, 15);
	}
	printf("\n");
	
	//question 3 
	l = 0;
	while (l < 6) {
		for (l = 2; l < 8; l++) {
			hottest[h] = data[0][h];
			coldest[h] = data[0][h];
			
			for (r = 0; r < 366; r++) {
				if (data[r][h] > hottest[l]) {
					hottest[l] = data[r][h];
					wherehot[l] = r;
				}
			}
			for (r = 0; r < 366; r++) {
				if (data[r][h] < coldest[l]) {
					coldest[l] = data[r][h];
					wherecold[l] = r;
				}
			}
			hdate[l] = date_finder(wherehot[l], &hmonth[l]);
			cdate[l] = date_finder(wherecold[l], &cmonth[l]);
			l++;
		}
	}
	
	printf("_______________________________________________________________________________________________\n");
	printf("\nQuestion 3:\n");
	for (h = 0; h < 6; h++) {
		switch(h) {
			case 0: 
				strncpy(lakename, "Superior", 15);
				break;
			case 1: 
				strncpy(lakename, "Michigan", 15);
				break;
			case 2: 
				strncpy(lakename, "Huron", 15);
				break;
			case 3: 
				strncpy(lakename, "Erie", 15);
				break;
			case 4: 
				strncpy(lakename, "Ontario", 15);
				break;
			case 5: 
				strncpy(lakename, "St. Clair", 15);
			}
		printf("The warmest  temperature of Lake %s = %.2lf degrees Celsius. It happened on %d/%d/2020.\n", lakename, hottest[h], hdate[h], hmonth[h]);
		printf("The coldest temperature of Lake %s = %.2lf degrees Celsius. It happened on %d/%d/2020.\n\n", lakename, coldest[h], cdate[h], cmonth[h]);
		memset(lakename, 0, 15);
	}
	
	//question 4
	hot = hottest[0];
	cold = coldest[0];
	for (r = 0; r < 6; r++) {
		if (hottest[r] > hot) {
			hot = hottest[r];
		}
	}
	for (r = 0; r < 6; r++) {
		if (coldest[r] < cold) {
			cold = coldest[r];
		}
	}

	l = 0;
	int hamount = 0;
	for (r = 0; r < 6; r++) {
		if (hottest[r] == hot) {
			hlake[l] = r;
			l++;
			hamount++;
		}
	}
	l = 0;
	int camount = 0;
	for (r = 0; r < 6; r++) {
		if (coldest[r] == cold) {
			clake[r] = r;
			l++;
			camount++;
		}
	}	
	
	printf("_______________________________________________________________________________________________\n");
	printf("\nQuestion 4:\n");
	printf("The warmest  temperature was %.2lf degrees Celsius.\n", hot);
	printf("This temperature occured on the following dates and lakes:\n");
	for (h = 0; h < hamount; h++) {
		switch(hlake[h]) {
			case 0: 
				strncpy(lakename, "Superior", 15);
				break;
			case 1: 
				strncpy(lakename, "Michigan", 15);
				break;
			case 2: 
				strncpy(lakename, "Huron", 15);
				break;
			case 3: 
				strncpy(lakename, "Erie", 15);
				break;
			case 4: 
				strncpy(lakename, "Ontario", 15);
				break;
			case 5: 
				strncpy(lakename, "St. Clair", 15);
			}
		printf("Lake %s, date: %d/%d/2020\n", lakename, hdate[hlake[h]], hmonth[hlake[h]]);
		memset(lakename, 0, 15);
	}
	printf("\n");
	printf("The coldestvtemperature was %.2lf degrees Celsius.\n", cold);
	printf("This temperature occured on the following dates and lakes:\n");
	for (h = 0; h < camount; h++) {
		switch(clake[h]) {
			case 0: 
				strncpy(lakename, "Superior", 15);
				break;
			case 1: 
				strncpy(lakename, "Michigan", 15);
				break;
			case 2: 
				strncpy(lakename, "Huron", 15);
				break;
			case 3: 
				strncpy(lakename, "Erie", 15);
				break;
			case 4: 
				strncpy(lakename, "Ontario", 15);
				break;
			case 5: 
				strncpy(lakename, "St. Clair", 15);
			}
		printf("Lake %s, date: %d/%d/2020\n", lakename, cdate[clake[h]], cmonth[clake[h]]);
		memset(lakename, 0, 15);
	}
	printf("\n");	
	
	//question 5
	// average for entries 171-264 of each lake
	for (h = 2; h < 8; h++) {
		r = h-2;
		for (l = 171; l < 265; l++) {
			saverage[r][0] = saverage[r][0] + data[l][h];
		}
		saverage[r][0] = saverage[r][0]/94;
		saverage[r][1] = (double)r;
	}
	temp0 = 0; temp1 = 0;
	for (r = 0; r < 6; r++) {
		for (h = 0; h < 6; h++) {
			if (saverage[h][0] < saverage[r][0]) {
				temp0 = saverage[r][0];
				temp1 = saverage[r][1];
				
				saverage[r][0] = saverage[h][0];
				saverage[r][1] = saverage[h][1];
				
				saverage[h][0] = temp0;
				saverage[h][1] = temp1;
			}
		}
	}
	
	printf("_______________________________________________________________________________________________\n");
	printf("\nQuestion 5:\n");
	printf(" Summer averages for lakes from warmest to coldest are:\n");
	for (r = 0; r < 6; r++) {
		switch((int)saverage[r][1]) {
			case 0: 
				strncpy(lakename, "Superior", 15);
				break;
			case 1: 
				strncpy(lakename, "Michigan", 15);
				break;
			case 2: 
				strncpy(lakename, "Huron", 15);
				break;
			case 3: 
				strncpy(lakename, "Erie", 15);
				break;
			case 4: 
				strncpy(lakename, "Ontario", 15);
				break;
			case 5: 
				strncpy(lakename, "St. Clair", 15);
		}
		printf("Lake %s: temperature was %.2lf degrees Celsius.\n", lakename, saverage[r][0]);
		memset(lakename, 0, 15);
	}
	printf("\n");
	
	//question 6
	// average for entries 0-78 and 354-365 of each lake
	for (h = 2; h < 8; h++) {
		r = h-2;
		for (l = 0; l < 79; l++) {
			waverage[r][0] = waverage[r][0] + data[l][h];
		}
		for (l = 354; l < 366; l++) {
			waverage[r][0] = waverage[r][0] + data[l][h];
		}
		waverage[r][0] = waverage[r][0]/91;
		waverage[r][1] = (double)r;
	}
	temp0 = 0; temp1 = 0;
	for (r = 0; r < 6; r++) {
		for (h = 0; h < 6; h++) {
			if (waverage[h][0] < waverage[r][0]) {
				temp0 = waverage[r][0];
				temp1 = waverage[r][1];
				
				waverage[r][0] = waverage[h][0];
				waverage[r][1] = waverage[h][1];
				
				waverage[h][0] = temp0;
				waverage[h][1] = temp1;
			}
		}
	}
	
	printf("_______________________________________________________________________________________________\n");
	printf("\nQuestion 6:\n");
	printf("The winter averages of all lakes from warmest to coldest are:\n");
	for (r = 0; r < 6; r++) {
		switch((int)waverage[r][1]) {
			case 0: 
				strncpy(lakename, "Superior", 15);
				break;
			case 1: 
				strncpy(lakename, "Michigan", 15);
				break;
			case 2: 
				strncpy(lakename, "Huron", 15);
				break;
			case 3: 
				strncpy(lakename, "Erie", 15);
				break;
			case 4: 
				strncpy(lakename, "Ontario", 15);
				break;
			case 5: 
				strncpy(lakename, "St. Clair", 15);
			}
		printf("Lake %s: temperature was %.2lf degrees Celsius.\n", lakename, waverage[r][0]);
		memset(lakename, 0, 15);
	}
	printf("\n");
	
	//question 7
	for (h = 2; h < 8; h++) {
		l = h-2;
		swimcount[l] = 0;
		for (r = 0; r < 366; r++) {
			if (data[r][h] > 20) {
				swimcount[l]++;
			}
		}
	}
	
	printf("_______________________________________________________________________________________________\n");
	printf("\nQuestion 7:\n");
	printf("For each lake in 2020, here are the amount of days it was suitable for swimming in:\n");
	for (r = 0; r < 6; r++) {
		switch(r) {
			case 0: 
				strncpy(lakename, "Superior", 15);
				break;
			case 1: 
				strncpy(lakename, "Michigan", 15);
				break;
			case 2: 
				strncpy(lakename, "Huron", 15);
				break;
			case 3: 
				strncpy(lakename, "Erie", 15);
				break;
			case 4: 
				strncpy(lakename, "Ontario", 15);
				break;
			case 5: 
				strncpy(lakename, "St. Clair", 15);
		}
			printf("Lake %s: %d days.\n", lakename, swimcount[r]);
			memset(lakename, 0, 15);
	}
	printf("\n");
	
	//question 8
	for (h = 2; h < 8; h++) {
		l = h-2;
		freezecount[l] = 0;
		for (r = 0; r < 366; r++) {
			if (data[r][h] < 0) {
				freezecount[l]++;
			}
		}
	}
	
	printf("_______________________________________________________________________________________________\n");
	printf("\nQuestion 8:\n");
	printf("For each lake in 2020, here are the amount of days it was frozen:\n");
	for (r = 0; r < 6; r++) {
		switch(r) {
			case 0: 
				strncpy(lakename, "Superior", 15);
				break;
			case 1: 
				strncpy(lakename, "Michigan", 15);
				break;
			case 2: 
				strncpy(lakename, "Huron", 15);
				break;
			case 3: 
				strncpy(lakename, "Erie", 15);
				break;
			case 4: 
				strncpy(lakename, "Ontario", 15);
				break;
			case 5: 
				strncpy(lakename, "St. Clair", 15);
		}
		printf("Lake %s: %d days.\n", lakename, freezecount[r]);
		memset(lakename, 0, 15);
	}
	printf("\n");
	
//question 9
	FILE *f;
	f = fopen("2019 data", "r");
	if (fp == NULL) {
		printf("The file could not be opened.");
		return(-1);
	}
	
	while (r < 365) {
		fgets(line, 60, f);
		sscanf(line, "%lf %lf %lf %lf %lf %lf %lf %lf", &ndata[r][0], &ndata[r][1], &ndata[r][2], &ndata[r][3], &ndata[r][4], &ndata[r][5], &ndata[r][6], &ndata[r][7]);
		memset(line, 0, 60);
		r++;
	}
	fclose(f);
	
	sum = 0; allsum = 0;
	for (r = 2; r < 8; r++) {
		l = r-2;
		for (h = 0; h < 365; h++) {
			sum = sum + ndata[h][r];
			allsum = allsum + ndata[h][r];
		}
		lakeav19[l] = sum/365;
		sum = 0;
	}
	av19 = allsum/(365*6);
	
	FILE *ptr;
	ptr = fopen("difference between the two", "w");
	fprintf(ptr, "2019 YEARLY AVERAGE            2020 YEARLY AVERAGE            LAKE NAME\n");
	for (r = 0; r < 6; r++) {
		switch(r) {
			case 0: 
				strncpy(lakename, "Superior", 15);
				break;
			case 1: 
				strncpy(lakename, "Michigan", 15);
				break;
			case 2: 
				strncpy(lakename, "Huron", 15);
				break;
			case 3: 
				strncpy(lakename, "Erie", 15);
				break;
			case 4: 
				strncpy(lakename, "Ontario", 15);
				break;
			case 5: 
				strncpy(lakename, "St. Clair", 15);
			}
		if (r == 0 || r == 2) {
			fprintf(ptr, "%.2lf                           ", lakeav19[r]);
			fprintf(ptr, "%.2lf                           ", lakeav20[r]);
			fprintf(ptr, "Lake %s\n", lakename);
			memset(lakename, 0, 15);
		}
		else if (r == 1 || r == 4) {
			fprintf(ptr, "%.2lf                           ", lakeav19[r]);
			fprintf(ptr, "%.2lf                          ", lakeav20[r]);
			fprintf(ptr, "Lake %s\n", lakename);
			memset(lakename, 0, 15);
		}
		else {
			fprintf(ptr, "%.2lf                          ", lakeav19[r]);
			fprintf(ptr, "%.2lf                          ", lakeav20[r]);
			fprintf(ptr, "Lake %s\n", lakename);
			memset(lakename, 0, 15);
		}
	}
	fprintf(ptr, "\n");
	fprintf(ptr, "AVERAGE FOR 2019: %.2lf\n", av19);
	fprintf(ptr, "AVERAGE FOR 2020: %.2lf\n", av20);
	fclose(ptr);
	
	printf("_______________________________________________________________________________________________\n");
	printf("\nQuestion 9:\n");
	printf("A file comparing the two years average was open.\n\n");
	printf("_______________________________________________________________________________________________\n");
	
	return 0;
}
