
void scanArray( int arr[], int size)
{
	NSScanner* scan = [[NSScanner alloc] init];
	int i = 0;
	while( i < size){
		NSString* str = [[NSString alloc] init: "Введите элемент "];
		str = [[ str append: [NSString fromInt: i]] append: " массива"];
		printf( str);
		arr[i] = [scan scanInt];

		i = i + 1;
	}
}

void printArray( int arr[], int size)
{
	printf( [[[NSString alloc] init:"array size:"] append: [NSString fromInt: size]]);
	NSString* elem;
	elem = [[NSString alloc] init:""];
	int i = 0;
	while( i < size){
		elem = [elem append: [NSString fromInt: arr[i]]];
		elem = [elem append: " "];
		i = i + 1;
	}
	printf( elem);
}

void iLoveBubbles( int arr[], int size)
{
	int b[5] = {1000, 4, 2, 1, -50};

	int buf = 0;
	int i = 0;
	int j = 0;
	while(i < size) {
		j = 0;
		while(j < size) {
			if(arr[i] < arr[j]) {
				buf = arr[j];
				arr[j] = arr[i];
				arr[i] = buf;
			}
			j = j + 1;
		}
		i = i + 1;
	}

}

void main()
{
	int s = 10;
	int a[10];
	scanArray( a, s); 
	iLoveBubbles( a, s);
	printArray( a, s);
}
