
void test( int o1, int o2, int o3, int o4, int o5){
	NSString* str = [[NSString alloc] init: ""];
	str = [str append: [NSString fromInt: o1]];
	str = [str append: [NSString fromInt: o2]];
	str = [str append: [NSString fromInt: o3]];
	str = [str append: [NSString fromInt: o4]];
	str = [str append: [NSString fromInt: o5]];
	printf( str);
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

void main()
{
	//test( 1,2,3,4,5);
	int s = 10;
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	printArray( a, s);
}
