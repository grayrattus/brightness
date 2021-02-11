#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int argBrightness = 0;
	if (argc != 2 || sscanf(argv[1], "%i", &argBrightness) != 1) {
		perror("Accept only one argument. Number that you want to increase/decreate brightness.");
		exit(-1);
	}

	FILE *brightnessFile = fopen("/sys/class/backlight/intel_backlight/brightness", "rw+");
	int currentBrightness = 0;
	if (brightnessFile == NULL) {
		perror("Cannot open sys file");
		exit(-1);
	}
	fscanf(brightnessFile, "%d", &currentBrightness);
	int newBrightness = currentBrightness + argBrightness;

	printf("%d", newBrightness);

	fprintf(brightnessFile, "%d", newBrightness);
	if(ferror(brightnessFile)) {
		perror("Could not write to brightness file");
		exit(-1);
	}
	
	fclose(brightnessFile);
	return 0;
}
