#include <stdio.h>
#include <time.h>

void years_and_days(long int *days_5, long int *years_6, long int a) {

	*days_5 = a / 86400;
	*years_6 = *days_5 / 365;
	*days_5 = *days_5 % 365;
	*years_6 = 1970 + *years_6;
}


void hours_and_minutes(long int *hours_1, long int *minutes_2, long int *second_3, long int *thesecondofday_4, long int a) {
	*thesecondofday_4 = a % 86400;
	*hours_1 = *thesecondofday_4 / 3600;
	*second_3 = *thesecondofday_4 % 3600;
	*minutes_2 = *second_3 / 60;
	*second_3 = a % 60;
}


void printfyears_days(long int *h, long int *m, long int *s, long int *d, long int *y) {
	if (*d <= 31) {
		if (*d == 1) {
			printf("%list Jan.", *d);
		}
		if (*d == 2) {
			printf("%lind Jan.", *d);
		}
		if (*d == 3) {
			printf("%lird Jan.", *d);
		}
		else {
			printf("%lith Jan.", *d);
		}
	}
	if ((*d >= 32) && (*d <= 59)) {
		*d = *d - 31;
		if (*d == 1) {
			printf("%list Feb.", *d);
		}
		if (*d == 2) {
			printf("%lind Feb.", *d);
		}
		if (*d == 3) {
			printf("%lird Feb.", *d);
		}
		else {
			printf("%lith Feb.", *d);
		}
	}
	if ((*d >= 60) && (*d <= 90)) {
		*d = *d - 59;
		if (*d == 1) {
			printf("%list Mar.", *d);
		}
		if (*d == 2) {
			printf("%lind Mar.", *d);
		}
		if (*d == 3) {
			printf("%lird Mar.", *d);
		}
		else {
			printf("%lith Mar.", *d);
		}
	}
	if ((*d >= 91) && (*d <= 120)) {
		*d = *d - 90;
		if (*d == 1) {
			printf("%list Apr.", *d);
		}
		if (*d == 2) {
			printf("%lind Apr.", *d);
		}
		if (*d == 3) {
			printf("%lird Apr.", *d);
		}
		else {
			printf("%lith Apr.", *d);
		}
	}
	if ((*d >= 121) && (*d <= 151)) {
		*d = *d - 120;
		if (*d == 1) {
			printf("%list May.", *d);
		}
		if (*d == 2) {
			printf("%lind May.", *d);
		}
		if (*d == 3) {
			printf("%lird May.", *d);
		}
		else {
			printf("%lith May.", *d);
		}
	}
	if ((*d >= 152) && (*d <= 181)) {
		*d = *d - 151;
		if (*d == 1) {
			printf("%list June.", *d);
		}
		if (*d == 2) {
			printf("%lind June.", *d);
		}
		if (*d == 3) {
			printf("%lird June.", *d);
		}
		else {
			printf("%lith June.", *d);
		}
	}
	if ((*d >= 182) && (*d <= 212)) {
		*d = *d - 181;
		if (*d == 1) {
			printf("%list July.", *d);
		}
		if (*d == 2) {
			printf("%lind July.", *d);
		}
		if (*d == 3) {
			printf("%lird July.", *d);
		}
		else {
			printf("%lith July.", *d);
		}
	}
	if ((*d >= 213) && (*d <= 243)) {
		*d = *d - 212;
		if (*d == 1) {
			printf("%list Aug.", *d);
		}
		if (*d == 2) {
			printf("%lind Aug.", *d);
		}
		if (*d == 3) {
			printf("%lird Aug.", *d);
		}
		else {
			printf("%lith Aug.", *d);
		}
	}
	if ((*d >= 244) && (*d <= 273)) {
		*d = *d - 243;
		if (*d == 1) {
			printf("%list Sept.", *d);
		}
		if (*d == 2) {
			printf("%lind Sept.", *d);
		}
		if (*d == 3) {
			printf("%lird Sept.", *d);
		}
		else {
			printf("%lith Sept.", *d);
		}
	}
	if ((*d >= 274) && (*d <= 304)) {
		*d = *d - 273;
		if (*d == 1) {
			printf("%list Oct.", *d);
		}
		if (*d == 2) {
			printf("%lind Oct.", *d);
		}
		if (*d == 3) {
			printf("%lird Oct.", *d);
		}
		else {
			printf("%lith Oct.", *d);
		}
	}
	if ((*d >= 305) && (*d <= 334)) {
		*d = *d - 304;
		if (*d == 1) {
			printf("%list Nov.", *d);
		}
		if (*d == 2) {
			printf("%lind Nov.", *d);
		}
		if (*d == 3) {
			printf("%lird Nov.", *d);
		}
		else {
			printf("%lith Nov.", *d);
		}
	}
	if ((*d >= 335) && (*d <= 365)) {
		*d = *d - 334;
		if (*d == 1) {
			printf("%list Dec.", *d);
		}
		if (*d == 2) {
			printf("%lind Dec.", *d);
		}
		if (*d == 3) {
			printf("%lird Dec.", *d);
		}
		else {
			printf("%lith Dec.", *d);
		}
	}
	printf("%li ", *y);
	printf("\n%02d:%02d:%02d", *h+8, *m, *s);
}
int main() {
	time_t now;
	now = time(NULL);
	long int a = now;
	long int hours;
	long int minutes;
	long int sounds;
	long int the_sounds_of_today;
	long int days;
	long int years;
	long int *pointer_1, *pointer_2, *pointer_3, *pointer_4, *pointer_5, *pointer_6;
	pointer_1 = &hours;
	pointer_2 = &minutes;
	pointer_3 = &sounds;
	pointer_4 = &the_sounds_of_today;
	pointer_5 = &days;
	pointer_6 = &years;
	printf("%lli\n", now);




	years_and_days(pointer_5, pointer_6, a);
	hours_and_minutes(pointer_1, pointer_2, pointer_3, pointer_4, a);
    printfyears_days(pointer_1, pointer_2, pointer_3, pointer_5, pointer_6);

	
	
	
	
	getchar();
	return 0;
}
