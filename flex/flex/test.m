void test( int o1, int o2, int o3, int o4, int o5){
	NSString* str = [[NSString alloc] init: ""];
	str = [str append: [NSString fromInt: o1]];
	str = [str append: [NSString fromInt: o2]];
	str = [str append: [NSString fromInt: o3]];
	str = [str append: [NSString fromInt: o4]];
	str = [str append: [NSString fromInt: o5]];
	printf( str);
}

void scanArray( int arr[], int size)
{
	NSScanner* scan = [[NSScanner alloc] init];
	int i = 0;
	while( i < size){
		NSString* str = [[NSString alloc] init: "¬ведите элемент "];
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
	//test( 1,2,3,4,5);
	int s = 10;
	int a[10];// = {1,2,3,4,5,6,7,8,9,10};
	scanArray( a, s); 
	iLoveBubbles( a, s);
	printArray( a, s);
}


