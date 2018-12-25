void func (float a[], int size) {
	int i = 0;
	printf("This is begin func");
	while (i < size) {
		if (a[i] < 0) {
			printf("This is func");
			a[i] = 0;
		}
		i = i + 1;
	}
}
void main()
{
	NSScanner *in = [[NSScanner alloc]init];
	float a[5];
	a[0] = [in scanFloat];
	int b = !(a[0] > 0 && a[0] < 3.333);
	printf([NSString fromInt: b]);
	
}