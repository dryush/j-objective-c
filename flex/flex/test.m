
void printArray( int arr[], int size)
{
	NSString* elem;
	elem = [[NSString alloc] init:""];
	int i = 0;
	while( i < size){
		elem = [elem append: [NSString fromInt: arr[i]]];
		i = i + 1;
		printf( elem);
	}
}

void main()
{

	int s = 10;
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	printArray( a, s);
}
