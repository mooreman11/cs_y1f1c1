#include <stdio.h>
#include <math.h>

int getBaseToDecimal(int num, char baseFrom){
	// function converts base0-9 values to base10 (decimal) values
	int sum = 0;
	char count = 0;
	while (num != 0){
		sum += ((num%10) * pow(baseFrom, count));
		num /= 10;
		count++;
	}
	return sum;
}

int getDecimalToBinary(int num){
	// function converts base10 (decimal) values to base2 (binary) values
	char count = 0;
	int sum = 0;
	while (num != 0){
		if ((num / (int) pow(2, count)) != 0){
			count++;
		}
		else{
			break;
		}
	}
	while (num != 0){
		if ((num % (int) pow(2, count-1)) > 0){
			sum += (int) pow(10, count-1);
			num -= (int) pow(2, count-1);
			count--;
		}
		else if ((num % (int) pow(2, count-1)) == 0){
			sum += (int) pow(10, count-1);
			break;
		}
	}
	return sum;
}

int getBinaryXor(){
	// function scans 2 binary values, converts them each to decimal values, performs xor operations, and then converts them back to binary
	int bin1, bin2;
	scanf("%d", &bin1);
	scanf("%d", &bin2);
	return getDecimalToBinary(getBaseToDecimal(bin1, 2) ^ getBaseToDecimal(bin2, 2));
}

int getHexSum(){
	// function scans 2 hexidecimal values, converts the sum to a binary value, and retrieves last four values
	int hex1, hex2;
	scanf("%x", &hex1);
	scanf("%x", &hex2);
	return getDecimalToBinary(hex1+hex2)%10000;
}

int getDecimalFromOtherBase(){
	int num, base;
	scanf("%d", &num);
	scanf("%d", &base);
	return getBaseToDecimal(num, base);
}

int getBinaryBitFromBase10(){
	//converts decimal number to binary, retrieves given index/bit from converted decimal
	int num, index;
	scanf("%d", &num);
	scanf("%d", &index);
	return (getDecimalToBinary(num) / (int) pow(10, index-1))%10;
}

int main(){
	printf("xor value: %d\n", getBinaryXor());
	printf("binary value: %d\n", getHexSum());
	printf("decimal from base value: %d\n", getDecimalFromOtherBase());
	printf("retrieves bit from given decimal: %d\n", getBinaryBitFromBase10());
	return 0;
}

